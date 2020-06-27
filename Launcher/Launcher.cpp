struct IUnknown;
#define NOMINMAX
#include <Windows.h>
#include <Shlwapi.h>
#include <string>
#include <vector>
#include <algorithm>
using std::wstring;
using std::pair;
using std::make_pair;
using std::max;
using std::vector;

#pragma comment(lib, "Shlwapi.lib")

#include "CommandLineArguments.h"

bool StartSuspendedProcess(wstring &commandLine, const wstring &startDirectory, int nShowCmd, PROCESS_INFORMATION &processInformation)
{
    STARTUPINFOW startupInfo = {};
    startupInfo.cb = sizeof(startupInfo);
    startupInfo.dwFlags = STARTF_USESHOWWINDOW;
    startupInfo.wShowWindow = nShowCmd;

    BOOL okay;
    DWORD lastError;
    okay = CreateProcessW(NULL, &commandLine[0], NULL, NULL, false, CREATE_SUSPENDED, NULL, startDirectory.c_str(), &startupInfo, &processInformation);
    lastError = GetLastError();
    return okay;
}

pair<DWORD_PTR, SIZE_T> FindMemoryBlock(void* ptr)
{
    MEMORY_BASIC_INFORMATION memInfo = {};
    SIZE_T result;
    result = VirtualQuery(ptr, &memInfo, sizeof(memInfo));
    return std::make_pair((DWORD_PTR)memInfo.BaseAddress, (SIZE_T)memInfo.RegionSize);
}

DWORD InjectDllIntoRemoteProcess(const PROCESS_INFORMATION& processInformation, LPCWSTR payloadDllName, LPCWSTR injectorDllName)
{
    //Load Injector DLL
    HMODULE injectorDll = NULL;
    injectorDll = LoadLibraryW(injectorDllName);
    if (injectorDll == NULL) return GetLastError();
    
    //Find the function
    LPCSTR funcName = "_CallLoadLibraryThreadEntryW@4";
    if (sizeof(void*) == 8) { funcName = "CallLoadLibraryThreadEntryW"; }
    FARPROC callLoadLibrary = (FARPROC)GetProcAddress(injectorDll, funcName);
    if (callLoadLibrary == NULL) return GetLastError();

    //Find the memory block used by the DLL
    auto block = FindMemoryBlock(callLoadLibrary);
    //block contains only the TEXT section of the DLL
    DWORD_PTR dllBaseAddress = max((DWORD_PTR)injectorDll, block.first);
    DWORD_PTR dllEndAddress = block.first + block.second;
    SIZE_T dllSize = dllEndAddress - dllBaseAddress;
    
    DWORD_PTR procAddressWithinDll = (DWORD_PTR)callLoadLibrary - dllBaseAddress;

    DWORD_PTR memWithinOtherProcess = (DWORD_PTR)VirtualAllocEx(processInformation.hProcess, 0, dllSize, MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (memWithinOtherProcess == 0) return GetLastError();
    memWithinOtherProcess = (DWORD_PTR)VirtualAllocEx(processInformation.hProcess, (LPVOID)memWithinOtherProcess, dllSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (memWithinOtherProcess == 0) return GetLastError();

    BOOL okay;
    SIZE_T numberOfBytesWritten = 0;
    okay = WriteProcessMemory(processInformation.hProcess, (LPVOID)memWithinOtherProcess, (LPCVOID)dllBaseAddress, dllSize, &numberOfBytesWritten);
    
    SIZE_T nameSize = (wcslen(payloadDllName) + 1) * sizeof(wchar_t);
    
    DWORD_PTR dllNameInOtherProcess = memWithinOtherProcess + dllSize - nameSize;
    okay = WriteProcessMemory(processInformation.hProcess, (LPVOID)dllNameInOtherProcess, payloadDllName, nameSize, &numberOfBytesWritten);

    DWORD_PTR callLoadLibraryInOtherProcess = procAddressWithinDll + memWithinOtherProcess;
    DWORD remoteThreadId = 0;

#if _DEBUG
    const bool _debug = true;
#else
    const bool _debug = false;
#endif
    bool debuggerPresent = IsDebuggerPresent();

    if (debuggerPresent || _debug)
    {
        bool DebuggerDialog(const PROCESS_INFORMATION & processInformation);
        if (DebuggerDialog(processInformation))
        {

        }
        else
        {
            return TerminateProcess(processInformation.hProcess, 1);
        }
    }

    HANDLE hThread = CreateRemoteThread(processInformation.hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)callLoadLibraryInOtherProcess, (LPVOID)dllNameInOtherProcess, 0, &remoteThreadId);
    
    DWORD result = 0;
    
    if (hThread != NULL)
    {
        WaitForSingleObject(hThread, INFINITE);
        DWORD exitCode = 0;
        okay = GetExitCodeThread(hThread, &exitCode);
        CloseHandle(hThread);
        result = exitCode;
    }
    else
    {
        result = GetLastError();
    }
    okay = VirtualFreeEx(processInformation.hProcess, (LPVOID)memWithinOtherProcess, 0, MEM_RELEASE);
    return result;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
    CommandLineData cmd = ParseCommandLine();
    if (cmd.targetFullCommandLine.empty())
    {
        bool LauncherDialog(CommandLineData &cmd);
        if (LauncherDialog(cmd))
        {
            if (cmd.targetFullCommandLine.empty()) return ERROR_FILE_NOT_FOUND;
        }
        else
        {
            return 0;
        }
        //MessageBoxW(NULL, L"Please drag and drop an EXE file onto this EXE file.", L"Instructions", 0);
        //return ERROR_FILE_NOT_FOUND;
    }
    wstring stretcherDll = LocateFile2(L"Stretcher.dll", cmd);
    if (stretcherDll.empty())
    {
        MessageBoxW(NULL, L"Cannot find Stretcher.dll.", L"Error", 0);
        return ERROR_FILE_NOT_FOUND;
    }
    wstring injectorDll = LocateFile2(L"Injector.dll", cmd);
    if (injectorDll.empty())
    {
        MessageBoxW(NULL, L"Cannot find Injector.dll.", L"Error", 0);
        return ERROR_FILE_NOT_FOUND;
    }
    
    for (int i = 0; i < cmd.switches.size(); i++)
    {
        const wstring& cmdSwitch = cmd.switches[i];
        if (cmdSwitch == L"--optimus")
        {
            SetEnvironmentVariableW(L"SHIM_MCCOMPAT", L"0x800000001");
        }
    }

    PROCESS_INFORMATION processInformation = {};
    bool okay = StartSuspendedProcess(cmd.targetFullCommandLine, cmd.targetDirectory, nShowCmd, processInformation);
    DWORD result = InjectDllIntoRemoteProcess(processInformation, stretcherDll.c_str(), injectorDll.c_str());
    AllowSetForegroundWindow(processInformation.dwProcessId);
    ResumeThread(processInformation.hThread);
    CloseHandle(processInformation.hProcess);
    CloseHandle(processInformation.hThread);
	return result;
}
