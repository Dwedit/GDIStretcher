#pragma once

struct IUnknown;
#define NOMINMAX
#include <Windows.h>

//Function Pointer Typedefs
typedef LSTATUS(APIENTRY* RegCloseKey_FUNC)(HKEY hKey);
//typedef LSTATUS(APIENTRY* RegOverridePredefKey_FUNC)(HKEY hKey, HKEY hNewHKey);
//typedef LSTATUS(APIENTRY* RegOpenUserClassesRoot_FUNC)(HANDLE hToken, DWORD dwOptions, REGSAM samDesired, PHKEY phkResult);
//typedef LSTATUS(APIENTRY* RegOpenCurrentUser_FUNC)(REGSAM samDesired, PHKEY phkResult);
//typedef LSTATUS(APIENTRY* RegDisablePredefinedCache_FUNC)();
//typedef LSTATUS(APIENTRY* RegDisablePredefinedCacheEx_FUNC)();
//typedef LSTATUS(APIENTRY* RegConnectRegistryA_FUNC)(LPCSTR lpMachineName, HKEY hKey, PHKEY phkResult);
//typedef LSTATUS(APIENTRY* RegConnectRegistryW_FUNC)(LPCWSTR lpMachineName, HKEY hKey, PHKEY phkResult);
//typedef LSTATUS(APIENTRY* RegConnectRegistryExA_FUNC)(LPCSTR lpMachineName, HKEY hKey, ULONG Flags, PHKEY phkResult);
//typedef LSTATUS(APIENTRY* RegConnectRegistryExW_FUNC)(LPCWSTR lpMachineName, HKEY hKey, ULONG Flags, PHKEY phkResult);
typedef LSTATUS(APIENTRY* RegCreateKeyA_FUNC)(HKEY hKey, LPCSTR lpSubKey, PHKEY phkResult);
typedef LSTATUS(APIENTRY* RegCreateKeyW_FUNC)(HKEY hKey, LPCWSTR lpSubKey, PHKEY phkResult);
typedef LSTATUS(APIENTRY* RegCreateKeyExA_FUNC)(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition);
typedef LSTATUS(APIENTRY* RegCreateKeyExW_FUNC)(HKEY hKey, LPCWSTR lpSubKey, DWORD Reserved, LPWSTR lpClass, DWORD dwOptions, REGSAM samDesired, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition);
//typedef LSTATUS(APIENTRY* RegCreateKeyTransactedA_FUNC)(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition, HANDLE hTransaction, PVOID pExtendedParemeter);
//typedef LSTATUS(APIENTRY* RegCreateKeyTransactedW_FUNC)(HKEY hKey, LPCWSTR lpSubKey, DWORD Reserved, LPWSTR lpClass, DWORD dwOptions, REGSAM samDesired, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition, HANDLE hTransaction, PVOID pExtendedParemeter);
typedef LSTATUS(APIENTRY* RegDeleteKeyA_FUNC)(HKEY hKey, LPCSTR lpSubKey);
typedef LSTATUS(APIENTRY* RegDeleteKeyW_FUNC)(HKEY hKey, LPCWSTR lpSubKey);
typedef LSTATUS(APIENTRY* RegDeleteKeyExA_FUNC)(HKEY hKey, LPCSTR lpSubKey, REGSAM samDesired, DWORD Reserved);
typedef LSTATUS(APIENTRY* RegDeleteKeyExW_FUNC)(HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired, DWORD Reserved);
//typedef LSTATUS(APIENTRY* RegDeleteKeyTransactedA_FUNC)(HKEY hKey, LPCSTR lpSubKey, REGSAM samDesired, DWORD Reserved, HANDLE hTransaction, PVOID pExtendedParameter);
//typedef LSTATUS(APIENTRY* RegDeleteKeyTransactedW_FUNC)(HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired, DWORD Reserved, HANDLE hTransaction, PVOID pExtendedParameter);
//typedef LONG(APIENTRY* RegDisableReflectionKey_FUNC)(HKEY hBase);
//typedef LONG(APIENTRY* RegEnableReflectionKey_FUNC)(HKEY hBase);
//typedef LONG(APIENTRY* RegQueryReflectionKey_FUNC)(HKEY hBase, BOOL* bIsReflectionDisabled);
typedef LSTATUS(APIENTRY* RegDeleteValueA_FUNC)(HKEY hKey, LPCSTR lpValueName);
typedef LSTATUS(APIENTRY* RegDeleteValueW_FUNC)(HKEY hKey, LPCWSTR lpValueName);
typedef LSTATUS(APIENTRY* RegEnumKeyA_FUNC)(HKEY hKey, DWORD dwIndex, LPSTR lpName, DWORD cchName);
typedef LSTATUS(APIENTRY* RegEnumKeyW_FUNC)(HKEY hKey, DWORD dwIndex, LPWSTR lpName, DWORD cchName);
typedef LSTATUS(APIENTRY* RegEnumKeyExA_FUNC)(HKEY hKey, DWORD dwIndex, LPSTR lpName, LPDWORD lpcchName, LPDWORD lpReserved, LPSTR lpClass, LPDWORD lpcchClass, PFILETIME lpftLastWriteTime);
typedef LSTATUS(APIENTRY* RegEnumKeyExW_FUNC)(HKEY hKey, DWORD dwIndex, LPWSTR lpName, LPDWORD lpcchName, LPDWORD lpReserved, LPWSTR lpClass, LPDWORD lpcchClass, PFILETIME lpftLastWriteTime);
typedef LSTATUS(APIENTRY* RegEnumValueA_FUNC)(HKEY hKey, DWORD dwIndex, LPSTR lpValueName, LPDWORD lpcchValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
typedef LSTATUS(APIENTRY* RegEnumValueW_FUNC)(HKEY hKey, DWORD dwIndex, LPWSTR lpValueName, LPDWORD lpcchValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
//typedef LSTATUS(APIENTRY* RegFlushKey_FUNC)(HKEY hKey);
typedef LSTATUS(APIENTRY* RegGetKeySecurity_FUNC)(HKEY hKey, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor, LPDWORD lpcbSecurityDescriptor);
//typedef LSTATUS(APIENTRY* RegLoadKeyA_FUNC)(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpFile);
//typedef LSTATUS(APIENTRY* RegLoadKeyW_FUNC)(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpFile);
typedef LSTATUS(APIENTRY* RegNotifyChangeKeyValue_FUNC)(HKEY hKey, BOOL bWatchSubtree, DWORD dwNotifyFilter, HANDLE hEvent, BOOL fAsynchronous);
typedef LSTATUS(APIENTRY* RegOpenKeyA_FUNC)(HKEY hKey, LPCSTR lpSubKey, PHKEY phkResult);
typedef LSTATUS(APIENTRY* RegOpenKeyW_FUNC)(HKEY hKey, LPCWSTR lpSubKey, PHKEY phkResult);
typedef LSTATUS(APIENTRY* RegOpenKeyExA_FUNC)(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
typedef LSTATUS(APIENTRY* RegOpenKeyExW_FUNC)(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
//typedef LSTATUS(APIENTRY* RegOpenKeyTransactedA_FUNC)(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult, HANDLE hTransaction, PVOID pExtendedParemeter);
//typedef LSTATUS(APIENTRY* RegOpenKeyTransactedW_FUNC)(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult, HANDLE hTransaction, PVOID pExtendedParemeter);
typedef LSTATUS(APIENTRY* RegQueryInfoKeyA_FUNC)(HKEY hKey, LPSTR lpClass, LPDWORD lpcchClass, LPDWORD lpReserved, LPDWORD lpcSubKeys, LPDWORD lpcbMaxSubKeyLen, LPDWORD lpcbMaxClassLen, LPDWORD lpcValues, LPDWORD lpcbMaxValueNameLen, LPDWORD lpcbMaxValueLen, LPDWORD lpcbSecurityDescriptor, PFILETIME lpftLastWriteTime);
typedef LSTATUS(APIENTRY* RegQueryInfoKeyW_FUNC)(HKEY hKey, LPWSTR lpClass, LPDWORD lpcchClass, LPDWORD lpReserved, LPDWORD lpcSubKeys, LPDWORD lpcbMaxSubKeyLen, LPDWORD lpcbMaxClassLen, LPDWORD lpcValues, LPDWORD lpcbMaxValueNameLen, LPDWORD lpcbMaxValueLen, LPDWORD lpcbSecurityDescriptor, PFILETIME lpftLastWriteTime);
typedef LSTATUS(APIENTRY* RegQueryValueA_FUNC)(HKEY hKey, LPCSTR lpSubKey, LPSTR lpData, PLONG lpcbData);
typedef LSTATUS(APIENTRY* RegQueryValueW_FUNC)(HKEY hKey, LPCWSTR lpSubKey, LPWSTR lpData, PLONG lpcbData);
typedef LSTATUS(APIENTRY* RegQueryMultipleValuesA_FUNC)(HKEY hKey, PVALENTA val_list, DWORD num_vals, LPSTR lpValueBuf, LPDWORD ldwTotsize);
typedef LSTATUS(APIENTRY* RegQueryMultipleValuesW_FUNC)(HKEY hKey, PVALENTW val_list, DWORD num_vals, LPWSTR lpValueBuf, LPDWORD ldwTotsize);
typedef LSTATUS(APIENTRY* RegQueryValueExA_FUNC)(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
typedef LSTATUS(APIENTRY* RegQueryValueExW_FUNC)(HKEY hKey, LPCWSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
//typedef LSTATUS(APIENTRY* RegReplaceKeyA_FUNC)(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpNewFile, LPCSTR lpOldFile);
//typedef LSTATUS(APIENTRY* RegReplaceKeyW_FUNC)(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpNewFile, LPCWSTR lpOldFile);
//typedef LSTATUS(APIENTRY* RegRestoreKeyA_FUNC)(HKEY hKey, LPCSTR lpFile, DWORD dwFlags);
//typedef LSTATUS(APIENTRY* RegRestoreKeyW_FUNC)(HKEY hKey, LPCWSTR lpFile, DWORD dwFlags);
//typedef LSTATUS(APIENTRY* RegRenameKey_FUNC)(HKEY hKey, LPCWSTR lpSubKeyName, LPCWSTR lpNewKeyName);
//typedef LSTATUS(APIENTRY* RegSaveKeyA_FUNC)(HKEY hKey, LPCSTR lpFile, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes);
//typedef LSTATUS(APIENTRY* RegSaveKeyW_FUNC)(HKEY hKey, LPCWSTR lpFile, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes);
typedef LSTATUS(APIENTRY* RegSetKeySecurity_FUNC)(HKEY hKey, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor);
typedef LSTATUS(APIENTRY* RegSetValueA_FUNC)(HKEY hKey, LPCSTR lpSubKey, DWORD dwType, LPCSTR lpData, DWORD cbData);
typedef LSTATUS(APIENTRY* RegSetValueW_FUNC)(HKEY hKey, LPCWSTR lpSubKey, DWORD dwType, LPCWSTR lpData, DWORD cbData);
typedef LSTATUS(APIENTRY* RegSetValueExA_FUNC)(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, CONST BYTE* lpData, DWORD cbData);
typedef LSTATUS(APIENTRY* RegSetValueExW_FUNC)(HKEY hKey, LPCWSTR lpValueName, DWORD Reserved, DWORD dwType, CONST BYTE* lpData, DWORD cbData);
//typedef LSTATUS(APIENTRY* RegUnLoadKeyA_FUNC)(HKEY hKey, LPCSTR lpSubKey);
//typedef LSTATUS(APIENTRY* RegUnLoadKeyW_FUNC)(HKEY hKey, LPCWSTR lpSubKey);
typedef LSTATUS(APIENTRY* RegDeleteKeyValueA_FUNC)(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValueName);
typedef LSTATUS(APIENTRY* RegDeleteKeyValueW_FUNC)(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName);
typedef LSTATUS(APIENTRY* RegSetKeyValueA_FUNC)(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValueName, DWORD dwType, LPCVOID lpData, DWORD cbData);
typedef LSTATUS(APIENTRY* RegSetKeyValueW_FUNC)(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName, DWORD dwType, LPCVOID lpData, DWORD cbData);
//typedef LSTATUS(APIENTRY* RegDeleteTreeA_FUNC)(HKEY hKey, LPCSTR lpSubKey);
//typedef LSTATUS(APIENTRY* RegDeleteTreeW_FUNC)(HKEY hKey, LPCWSTR lpSubKey);
//typedef LSTATUS(APIENTRY* RegCopyTreeA_FUNC)(HKEY hKeySrc, LPCSTR lpSubKey, HKEY hKeyDest);
//typedef LSTATUS(APIENTRY* RegCopyTreeW_FUNC)(HKEY hKeySrc, LPCWSTR lpSubKey, HKEY hKeyDest);
typedef LSTATUS(APIENTRY* RegGetValueA_FUNC)(HKEY hkey, LPCSTR lpSubKey, LPCSTR lpValue, DWORD dwFlags, LPDWORD pdwType, PVOID pvData, LPDWORD pcbData);
typedef LSTATUS(APIENTRY* RegGetValueW_FUNC)(HKEY hkey, LPCWSTR lpSubKey, LPCWSTR lpValue, DWORD dwFlags, LPDWORD pdwType, PVOID pvData, LPDWORD pcbData);
//typedef LSTATUS(APIENTRY* RegLoadMUIStringA_FUNC)(HKEY hKey, LPCSTR pszValue, LPSTR pszOutBuf, DWORD cbOutBuf, LPDWORD pcbData, DWORD Flags, LPCSTR pszDirectory);
//typedef LSTATUS(APIENTRY* RegLoadMUIStringW_FUNC)(HKEY hKey, LPCWSTR pszValue, LPWSTR pszOutBuf, DWORD cbOutBuf, LPDWORD pcbData, DWORD Flags, LPCWSTR pszDirectory);
//typedef LSTATUS(APIENTRY* RegLoadAppKeyA_FUNC)(LPCSTR lpFile, PHKEY phkResult, REGSAM samDesired, DWORD dwOptions, DWORD Reserved);
//typedef LSTATUS(APIENTRY* RegLoadAppKeyW_FUNC)(LPCWSTR lpFile, PHKEY phkResult, REGSAM samDesired, DWORD dwOptions, DWORD Reserved);
//typedef BOOL(APIENTRY* InitiateSystemShutdownA_FUNC)(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown);
//typedef BOOL(APIENTRY* InitiateSystemShutdownW_FUNC)(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown);
//typedef BOOL(APIENTRY* AbortSystemShutdownA_FUNC)(LPSTR lpMachineName);
//typedef BOOL(APIENTRY* AbortSystemShutdownW_FUNC)(LPWSTR lpMachineName);
//typedef BOOL(APIENTRY* InitiateSystemShutdownExA_FUNC)(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown, DWORD dwReason);
//typedef BOOL(APIENTRY* InitiateSystemShutdownExW_FUNC)(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown, DWORD dwReason);
//typedef DWORD(APIENTRY* InitiateShutdownA_FUNC)(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwGracePeriod, DWORD dwShutdownFlags, DWORD dwReason);
//typedef DWORD(APIENTRY* InitiateShutdownW_FUNC)(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwGracePeriod, DWORD dwShutdownFlags, DWORD dwReason);
//typedef DWORD(APIENTRY* CheckForHiberboot_FUNC)(PBOOLEAN pHiberboot, BOOLEAN bClearFlag);
//typedef LSTATUS(APIENTRY* RegSaveKeyExA_FUNC)(HKEY hKey, LPCSTR lpFile, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD Flags);
//typedef LSTATUS(APIENTRY* RegSaveKeyExW_FUNC)(HKEY hKey, LPCWSTR lpFile, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD Flags);

//Import Backups (Declarations)
extern RegCloseKey_FUNC RegCloseKey_OLD;
//extern RegOverridePredefKey_FUNC RegOverridePredefKey_OLD;
//extern RegOpenUserClassesRoot_FUNC RegOpenUserClassesRoot_OLD;
//extern RegOpenCurrentUser_FUNC RegOpenCurrentUser_OLD;
//extern RegDisablePredefinedCache_FUNC RegDisablePredefinedCache_OLD;
//extern RegDisablePredefinedCacheEx_FUNC RegDisablePredefinedCacheEx_OLD;
//extern RegConnectRegistryA_FUNC RegConnectRegistryA_OLD;
//extern RegConnectRegistryW_FUNC RegConnectRegistryW_OLD;
//extern RegConnectRegistryExA_FUNC RegConnectRegistryExA_OLD;
//extern RegConnectRegistryExW_FUNC RegConnectRegistryExW_OLD;
extern RegCreateKeyA_FUNC RegCreateKeyA_OLD;
extern RegCreateKeyW_FUNC RegCreateKeyW_OLD;
extern RegCreateKeyExA_FUNC RegCreateKeyExA_OLD;
extern RegCreateKeyExW_FUNC RegCreateKeyExW_OLD;
//extern RegCreateKeyTransactedA_FUNC RegCreateKeyTransactedA_OLD;
//extern RegCreateKeyTransactedW_FUNC RegCreateKeyTransactedW_OLD;
extern RegDeleteKeyA_FUNC RegDeleteKeyA_OLD;
extern RegDeleteKeyW_FUNC RegDeleteKeyW_OLD;
extern RegDeleteKeyExA_FUNC RegDeleteKeyExA_OLD;
extern RegDeleteKeyExW_FUNC RegDeleteKeyExW_OLD;
//extern RegDeleteKeyTransactedA_FUNC RegDeleteKeyTransactedA_OLD;
//extern RegDeleteKeyTransactedW_FUNC RegDeleteKeyTransactedW_OLD;
//extern RegDisableReflectionKey_FUNC RegDisableReflectionKey_OLD;
//extern RegEnableReflectionKey_FUNC RegEnableReflectionKey_OLD;
//extern RegQueryReflectionKey_FUNC RegQueryReflectionKey_OLD;
extern RegDeleteValueA_FUNC RegDeleteValueA_OLD;
extern RegDeleteValueW_FUNC RegDeleteValueW_OLD;
extern RegEnumKeyA_FUNC RegEnumKeyA_OLD;
extern RegEnumKeyW_FUNC RegEnumKeyW_OLD;
extern RegEnumKeyExA_FUNC RegEnumKeyExA_OLD;
extern RegEnumKeyExW_FUNC RegEnumKeyExW_OLD;
extern RegEnumValueA_FUNC RegEnumValueA_OLD;
extern RegEnumValueW_FUNC RegEnumValueW_OLD;
//extern RegFlushKey_FUNC RegFlushKey_OLD;
extern RegGetKeySecurity_FUNC RegGetKeySecurity_OLD;
//extern RegLoadKeyA_FUNC RegLoadKeyA_OLD;
//extern RegLoadKeyW_FUNC RegLoadKeyW_OLD;
extern RegNotifyChangeKeyValue_FUNC RegNotifyChangeKeyValue_OLD;
extern RegOpenKeyA_FUNC RegOpenKeyA_OLD;
extern RegOpenKeyW_FUNC RegOpenKeyW_OLD;
extern RegOpenKeyExA_FUNC RegOpenKeyExA_OLD;
extern RegOpenKeyExW_FUNC RegOpenKeyExW_OLD;
//extern RegOpenKeyTransactedA_FUNC RegOpenKeyTransactedA_OLD;
//extern RegOpenKeyTransactedW_FUNC RegOpenKeyTransactedW_OLD;
extern RegQueryInfoKeyA_FUNC RegQueryInfoKeyA_OLD;
extern RegQueryInfoKeyW_FUNC RegQueryInfoKeyW_OLD;
extern RegQueryValueA_FUNC RegQueryValueA_OLD;
extern RegQueryValueW_FUNC RegQueryValueW_OLD;
extern RegQueryMultipleValuesA_FUNC RegQueryMultipleValuesA_OLD;
extern RegQueryMultipleValuesW_FUNC RegQueryMultipleValuesW_OLD;
extern RegQueryValueExA_FUNC RegQueryValueExA_OLD;
extern RegQueryValueExW_FUNC RegQueryValueExW_OLD;
//extern RegReplaceKeyA_FUNC RegReplaceKeyA_OLD;
//extern RegReplaceKeyW_FUNC RegReplaceKeyW_OLD;
//extern RegRestoreKeyA_FUNC RegRestoreKeyA_OLD;
//extern RegRestoreKeyW_FUNC RegRestoreKeyW_OLD;
//extern RegRenameKey_FUNC RegRenameKey_OLD;
//extern RegSaveKeyA_FUNC RegSaveKeyA_OLD;
//extern RegSaveKeyW_FUNC RegSaveKeyW_OLD;
extern RegSetKeySecurity_FUNC RegSetKeySecurity_OLD;
extern RegSetValueA_FUNC RegSetValueA_OLD;
extern RegSetValueW_FUNC RegSetValueW_OLD;
extern RegSetValueExA_FUNC RegSetValueExA_OLD;
extern RegSetValueExW_FUNC RegSetValueExW_OLD;
//extern RegUnLoadKeyA_FUNC RegUnLoadKeyA_OLD;
//extern RegUnLoadKeyW_FUNC RegUnLoadKeyW_OLD;
extern RegDeleteKeyValueA_FUNC RegDeleteKeyValueA_OLD;
extern RegDeleteKeyValueW_FUNC RegDeleteKeyValueW_OLD;
extern RegSetKeyValueA_FUNC RegSetKeyValueA_OLD;
extern RegSetKeyValueW_FUNC RegSetKeyValueW_OLD;
//extern RegDeleteTreeA_FUNC RegDeleteTreeA_OLD;
//extern RegDeleteTreeW_FUNC RegDeleteTreeW_OLD;
//extern RegCopyTreeA_FUNC RegCopyTreeA_OLD;
extern RegGetValueA_FUNC RegGetValueA_OLD;
extern RegGetValueW_FUNC RegGetValueW_OLD;
//extern RegCopyTreeW_FUNC RegCopyTreeW_OLD;
//extern RegLoadMUIStringA_FUNC RegLoadMUIStringA_OLD;
//extern RegLoadMUIStringW_FUNC RegLoadMUIStringW_OLD;
//extern RegLoadAppKeyA_FUNC RegLoadAppKeyA_OLD;
//extern RegLoadAppKeyW_FUNC RegLoadAppKeyW_OLD;
//extern RegSaveKeyExA_FUNC RegSaveKeyExA_OLD;
//extern RegSaveKeyExW_FUNC RegSaveKeyExW_OLD;

//Replacement Functions (Declarations)
LSTATUS APIENTRY RegCloseKey_Replacement(HKEY hKey);
LSTATUS APIENTRY RegOverridePredefKey_Replacement(HKEY hKey, HKEY hNewHKey);
LSTATUS APIENTRY RegOpenUserClassesRoot_Replacement(HANDLE hToken, DWORD dwOptions, REGSAM samDesired, PHKEY phkResult);
LSTATUS APIENTRY RegOpenCurrentUser_Replacement(REGSAM samDesired, PHKEY phkResult);
LSTATUS APIENTRY RegDisablePredefinedCache_Replacement();
LSTATUS APIENTRY RegDisablePredefinedCacheEx_Replacement();
LSTATUS APIENTRY RegConnectRegistryA_Replacement(LPCSTR lpMachineName, HKEY hKey, PHKEY phkResult);
LSTATUS APIENTRY RegConnectRegistryW_Replacement(LPCWSTR lpMachineName, HKEY hKey, PHKEY phkResult);
LSTATUS APIENTRY RegConnectRegistryExA_Replacement(LPCSTR lpMachineName, HKEY hKey, ULONG Flags, PHKEY phkResult);
LSTATUS APIENTRY RegConnectRegistryExW_Replacement(LPCWSTR lpMachineName, HKEY hKey, ULONG Flags, PHKEY phkResult);
LSTATUS APIENTRY RegCreateKeyA_Replacement(HKEY hKey, LPCSTR lpSubKey, PHKEY phkResult);
LSTATUS APIENTRY RegCreateKeyW_Replacement(HKEY hKey, LPCWSTR lpSubKey, PHKEY phkResult);
LSTATUS APIENTRY RegCreateKeyExA_Replacement(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition);
LSTATUS APIENTRY RegCreateKeyExW_Replacement(HKEY hKey, LPCWSTR lpSubKey, DWORD Reserved, LPWSTR lpClass, DWORD dwOptions, REGSAM samDesired, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition);
LSTATUS APIENTRY RegCreateKeyTransactedA_Replacement(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition, HANDLE hTransaction, PVOID pExtendedParemeter);
LSTATUS APIENTRY RegCreateKeyTransactedW_Replacement(HKEY hKey, LPCWSTR lpSubKey, DWORD Reserved, LPWSTR lpClass, DWORD dwOptions, REGSAM samDesired, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition, HANDLE hTransaction, PVOID pExtendedParemeter);
LSTATUS APIENTRY RegDeleteKeyA_Replacement(HKEY hKey, LPCSTR lpSubKey);
LSTATUS APIENTRY RegDeleteKeyW_Replacement(HKEY hKey, LPCWSTR lpSubKey);
LSTATUS APIENTRY RegDeleteKeyExA_Replacement(HKEY hKey, LPCSTR lpSubKey, REGSAM samDesired, DWORD Reserved);
LSTATUS APIENTRY RegDeleteKeyExW_Replacement(HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired, DWORD Reserved);
LSTATUS APIENTRY RegDeleteKeyTransactedA_Replacement(HKEY hKey, LPCSTR lpSubKey, REGSAM samDesired, DWORD Reserved, HANDLE hTransaction, PVOID pExtendedParameter);
LSTATUS APIENTRY RegDeleteKeyTransactedW_Replacement(HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired, DWORD Reserved, HANDLE hTransaction, PVOID pExtendedParameter);
LONG APIENTRY RegDisableReflectionKey_Replacement(HKEY hBase);
LONG APIENTRY RegEnableReflectionKey_Replacement(HKEY hBase);
LONG APIENTRY RegQueryReflectionKey_Replacement(HKEY hBase, BOOL* bIsReflectionDisabled);
LSTATUS APIENTRY RegDeleteValueA_Replacement(HKEY hKey, LPCSTR lpValueName);
LSTATUS APIENTRY RegDeleteValueW_Replacement(HKEY hKey, LPCWSTR lpValueName);
LSTATUS APIENTRY RegEnumKeyA_Replacement(HKEY hKey, DWORD dwIndex, LPSTR lpName, DWORD cchName);
LSTATUS APIENTRY RegEnumKeyW_Replacement(HKEY hKey, DWORD dwIndex, LPWSTR lpName, DWORD cchName);
LSTATUS APIENTRY RegEnumKeyExA_Replacement(HKEY hKey, DWORD dwIndex, LPSTR lpName, LPDWORD lpcchName, LPDWORD lpReserved, LPSTR lpClass, LPDWORD lpcchClass, PFILETIME lpftLastWriteTime);
LSTATUS APIENTRY RegEnumKeyExW_Replacement(HKEY hKey, DWORD dwIndex, LPWSTR lpName, LPDWORD lpcchName, LPDWORD lpReserved, LPWSTR lpClass, LPDWORD lpcchClass, PFILETIME lpftLastWriteTime);
LSTATUS APIENTRY RegEnumValueA_Replacement(HKEY hKey, DWORD dwIndex, LPSTR lpValueName, LPDWORD lpcchValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
LSTATUS APIENTRY RegEnumValueW_Replacement(HKEY hKey, DWORD dwIndex, LPWSTR lpValueName, LPDWORD lpcchValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
LSTATUS APIENTRY RegFlushKey_Replacement(HKEY hKey);
LSTATUS APIENTRY RegGetKeySecurity_Replacement(HKEY hKey, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor, LPDWORD lpcbSecurityDescriptor);
LSTATUS APIENTRY RegLoadKeyA_Replacement(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpFile);
LSTATUS APIENTRY RegLoadKeyW_Replacement(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpFile);
LSTATUS APIENTRY RegNotifyChangeKeyValue_Replacement(HKEY hKey, BOOL bWatchSubtree, DWORD dwNotifyFilter, HANDLE hEvent, BOOL fAsynchronous);
LSTATUS APIENTRY RegOpenKeyA_Replacement(HKEY hKey, LPCSTR lpSubKey, PHKEY phkResult);
LSTATUS APIENTRY RegOpenKeyW_Replacement(HKEY hKey, LPCWSTR lpSubKey, PHKEY phkResult);
LSTATUS APIENTRY RegOpenKeyExA_Replacement(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
LSTATUS APIENTRY RegOpenKeyExW_Replacement(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult);
LSTATUS APIENTRY RegOpenKeyTransactedA_Replacement(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult, HANDLE hTransaction, PVOID pExtendedParemeter);
LSTATUS APIENTRY RegOpenKeyTransactedW_Replacement(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult, HANDLE hTransaction, PVOID pExtendedParemeter);
LSTATUS APIENTRY RegQueryInfoKeyA_Replacement(HKEY hKey, LPSTR lpClass, LPDWORD lpcchClass, LPDWORD lpReserved, LPDWORD lpcSubKeys, LPDWORD lpcbMaxSubKeyLen, LPDWORD lpcbMaxClassLen, LPDWORD lpcValues, LPDWORD lpcbMaxValueNameLen, LPDWORD lpcbMaxValueLen, LPDWORD lpcbSecurityDescriptor, PFILETIME lpftLastWriteTime);
LSTATUS APIENTRY RegQueryInfoKeyW_Replacement(HKEY hKey, LPWSTR lpClass, LPDWORD lpcchClass, LPDWORD lpReserved, LPDWORD lpcSubKeys, LPDWORD lpcbMaxSubKeyLen, LPDWORD lpcbMaxClassLen, LPDWORD lpcValues, LPDWORD lpcbMaxValueNameLen, LPDWORD lpcbMaxValueLen, LPDWORD lpcbSecurityDescriptor, PFILETIME lpftLastWriteTime);
LSTATUS APIENTRY RegQueryValueA_Replacement(HKEY hKey, LPCSTR lpSubKey, LPSTR lpData, PLONG lpcbData);
LSTATUS APIENTRY RegQueryValueW_Replacement(HKEY hKey, LPCWSTR lpSubKey, LPWSTR lpData, PLONG lpcbData);
LSTATUS APIENTRY RegQueryMultipleValuesA_Replacement(HKEY hKey, PVALENTA val_list, DWORD num_vals, LPSTR lpValueBuf, LPDWORD ldwTotsize);
LSTATUS APIENTRY RegQueryMultipleValuesW_Replacement(HKEY hKey, PVALENTW val_list, DWORD num_vals, LPWSTR lpValueBuf, LPDWORD ldwTotsize);
LSTATUS APIENTRY RegQueryValueExA_Replacement(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
LSTATUS APIENTRY RegQueryValueExW_Replacement(HKEY hKey, LPCWSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
LSTATUS APIENTRY RegReplaceKeyA_Replacement(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpNewFile, LPCSTR lpOldFile);
LSTATUS APIENTRY RegReplaceKeyW_Replacement(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpNewFile, LPCWSTR lpOldFile);
LSTATUS APIENTRY RegRestoreKeyA_Replacement(HKEY hKey, LPCSTR lpFile, DWORD dwFlags);
LSTATUS APIENTRY RegRestoreKeyW_Replacement(HKEY hKey, LPCWSTR lpFile, DWORD dwFlags);
LSTATUS APIENTRY RegRenameKey_Replacement(HKEY hKey, LPCWSTR lpSubKeyName, LPCWSTR lpNewKeyName);
LSTATUS APIENTRY RegSaveKeyA_Replacement(HKEY hKey, LPCSTR lpFile, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes);
LSTATUS APIENTRY RegSaveKeyW_Replacement(HKEY hKey, LPCWSTR lpFile, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes);
LSTATUS APIENTRY RegSetKeySecurity_Replacement(HKEY hKey, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor);
LSTATUS APIENTRY RegSetValueA_Replacement(HKEY hKey, LPCSTR lpSubKey, DWORD dwType, LPCSTR lpData, DWORD cbData);
LSTATUS APIENTRY RegSetValueW_Replacement(HKEY hKey, LPCWSTR lpSubKey, DWORD dwType, LPCWSTR lpData, DWORD cbData);
LSTATUS APIENTRY RegSetValueExA_Replacement(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, CONST BYTE* lpData, DWORD cbData);
LSTATUS APIENTRY RegSetValueExW_Replacement(HKEY hKey, LPCWSTR lpValueName, DWORD Reserved, DWORD dwType, CONST BYTE* lpData, DWORD cbData);
LSTATUS APIENTRY RegUnLoadKeyA_Replacement(HKEY hKey, LPCSTR lpSubKey);
LSTATUS APIENTRY RegUnLoadKeyW_Replacement(HKEY hKey, LPCWSTR lpSubKey);
LSTATUS APIENTRY RegDeleteKeyValueA_Replacement(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValueName);
LSTATUS APIENTRY RegDeleteKeyValueW_Replacement(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName);
LSTATUS APIENTRY RegSetKeyValueA_Replacement(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValueName, DWORD dwType, LPCVOID lpData, DWORD cbData);
LSTATUS APIENTRY RegSetKeyValueW_Replacement(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName, DWORD dwType, LPCVOID lpData, DWORD cbData);
LSTATUS APIENTRY RegDeleteTreeA_Replacement(HKEY hKey, LPCSTR lpSubKey);
LSTATUS APIENTRY RegDeleteTreeW_Replacement(HKEY hKey, LPCWSTR lpSubKey);
LSTATUS APIENTRY RegCopyTreeA_Replacement(HKEY hKeySrc, LPCSTR lpSubKey, HKEY hKeyDest);
LSTATUS APIENTRY RegGetValueA_Replacement(HKEY hkey, LPCSTR lpSubKey, LPCSTR lpValue, DWORD dwFlags, LPDWORD pdwType, PVOID pvData, LPDWORD pcbData);
LSTATUS APIENTRY RegGetValueW_Replacement(HKEY hkey, LPCWSTR lpSubKey, LPCWSTR lpValue, DWORD dwFlags, LPDWORD pdwType, PVOID pvData, LPDWORD pcbData);
LSTATUS APIENTRY RegCopyTreeW_Replacement(HKEY hKeySrc, LPCWSTR lpSubKey, HKEY hKeyDest);
LSTATUS APIENTRY RegLoadMUIStringA_Replacement(HKEY hKey, LPCSTR pszValue, LPSTR pszOutBuf, DWORD cbOutBuf, LPDWORD pcbData, DWORD Flags, LPCSTR pszDirectory);
LSTATUS APIENTRY RegLoadMUIStringW_Replacement(HKEY hKey, LPCWSTR pszValue, LPWSTR pszOutBuf, DWORD cbOutBuf, LPDWORD pcbData, DWORD Flags, LPCWSTR pszDirectory);
LSTATUS APIENTRY RegLoadAppKeyA_Replacement(LPCSTR lpFile, PHKEY phkResult, REGSAM samDesired, DWORD dwOptions, DWORD Reserved);
LSTATUS APIENTRY RegLoadAppKeyW_Replacement(LPCWSTR lpFile, PHKEY phkResult, REGSAM samDesired, DWORD dwOptions, DWORD Reserved);
LSTATUS APIENTRY RegSaveKeyExA_Replacement(HKEY hKey, LPCSTR lpFile, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD Flags);
LSTATUS APIENTRY RegSaveKeyExW_Replacement(HKEY hKey, LPCWSTR lpFile, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD Flags);
