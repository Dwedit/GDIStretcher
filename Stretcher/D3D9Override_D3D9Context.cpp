#include "D3D9Override.h"
#include "MemoryUnlocker.h"
#include "Win32Ex.h"

D3D9Context2::D3D9Context2(IDirect3D9* d3d9)
{
	Init(d3d9);
}
D3D9Context2::D3D9Context2()
{

}

void D3D9Context2::Init(IDirect3D9* d3d9)
{
	Destroy();
	this->d3d9 = d3d9;
	this->d3d9->AddRef();
	this->originalVTable = GetOriginalVTable(d3d9, true);
	this->IsEx = GetIsEx(d3d9);
	this->myVTable = ((IDirect3D9Ex_*)d3d9)->lpVtbl;
	{
		MemoryUnlocker unlocker(this->myVTable);
		this->myVTable->CreateDevice = CreateDevice;
		this->myVTable->CreateDeviceEx = CreateDeviceEx;
	}
}
D3D9Context2::~D3D9Context2()
{
	Destroy();
}
void D3D9Context2::Destroy()
{
	SafeRelease(this->d3d9);
}
HRESULT D3D9Context2::CreateDeviceReal(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
{
	return this->originalVTable->CreateDevice(static_cast<IDirect3D9Ex*>(d3d9), Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
}
HRESULT D3D9Context2::CreateDeviceExReal(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, D3DDISPLAYMODEEX* pFullscreenDisplayMode, IDirect3DDevice9Ex** ppReturnedDeviceInterface)
{
	return this->originalVTable->CreateDeviceEx(static_cast<IDirect3D9Ex*>(d3d9), Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, pFullscreenDisplayMode, ppReturnedDeviceInterface);
}
HRESULT D3D9Context2::CreateDevice_(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
{
	HWND hwnd = hFocusWindow;
	if (hwnd == NULL && pPresentationParameters) { hwnd = pPresentationParameters->hDeviceWindow; }
	bool vsync = true;
	if (pPresentationParameters) { vsync = pPresentationParameters->PresentationInterval != D3DPRESENT_INTERVAL_IMMEDIATE; }
	UINT Adapter2 = 0;
	D3DDEVTYPE DeviceType2 = D3DDEVTYPE_HAL;
	DWORD BehaviorFlags2 = D3DCREATE_MIXED_VERTEXPROCESSING;
	if (BehaviorFlags & D3DCREATE_MULTITHREADED)
	{
		BehaviorFlags2 |= D3DCREATE_MULTITHREADED;
	}
	D3DPRESENT_PARAMETERS presentParameters = {};
	RECT monitorRect = GetMonitorRect(hwnd);
	
	int screenWidth = monitorRect.right - monitorRect.left;
	int screenHeight = monitorRect.bottom - monitorRect.top;
	presentParameters.BackBufferWidth = screenWidth;
	presentParameters.BackBufferHeight = screenHeight;
	presentParameters.BackBufferFormat = D3DFMT_A8R8G8B8;
	presentParameters.BackBufferCount = 1;
	presentParameters.MultiSampleType = D3DMULTISAMPLE_NONE;
	presentParameters.MultiSampleQuality = 0;
	presentParameters.SwapEffect = D3DSWAPEFFECT_COPY;
	presentParameters.hDeviceWindow = hwnd;
	presentParameters.Windowed = true;
	presentParameters.EnableAutoDepthStencil = true;
	presentParameters.AutoDepthStencilFormat = D3DFMT_D16;
	presentParameters.Flags = 0;
	presentParameters.FullScreen_RefreshRateInHz = 0;
	presentParameters.PresentationInterval = vsync ? D3DPRESENT_INTERVAL_ONE : D3DPRESENT_INTERVAL_IMMEDIATE;

	HRESULT hr = CreateDeviceReal(Adapter2, DeviceType2, hwnd, BehaviorFlags2, &presentParameters, ppReturnedDeviceInterface);
	IDirect3DDevice9* device = *ppReturnedDeviceInterface;
	D3D9DeviceContext* deviceContext = GetD3D9DeviceContext(device, true);
	deviceContext->parent = this;
	deviceContext->Init(device);
	deviceContext->CreateVirtualDevice(hwnd, BehaviorFlags, pPresentationParameters);
	return hr;
}
HRESULT D3D9Context2::CreateDeviceEx_(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, D3DDISPLAYMODEEX* pFullscreenDisplayMode, IDirect3DDevice9Ex** ppReturnedDeviceInterface)
{
	HWND hwnd = hFocusWindow;
	if (hwnd == NULL && pPresentationParameters) { hwnd = pPresentationParameters->hDeviceWindow; }
	bool vsync = true;
	if (pPresentationParameters) { vsync = pPresentationParameters->PresentationInterval != D3DPRESENT_INTERVAL_IMMEDIATE; }
	UINT Adapter2 = 0;
	D3DDEVTYPE DeviceType2 = D3DDEVTYPE_HAL;
	DWORD BehaviorFlags2 = D3DCREATE_MIXED_VERTEXPROCESSING;
	if (BehaviorFlags & D3DCREATE_MULTITHREADED)
	{
		BehaviorFlags2 |= D3DCREATE_MULTITHREADED;
	}
	D3DPRESENT_PARAMETERS presentParameters = {};
	RECT monitorRect = GetMonitorRect(hwnd);

	int screenWidth = monitorRect.right - monitorRect.left;
	int screenHeight = monitorRect.bottom - monitorRect.top;
	presentParameters.BackBufferWidth = screenWidth;
	presentParameters.BackBufferHeight = screenHeight;
	presentParameters.BackBufferFormat = D3DFMT_A8R8G8B8;
	presentParameters.BackBufferCount = 1;
	presentParameters.MultiSampleType = D3DMULTISAMPLE_NONE;
	presentParameters.MultiSampleQuality = 0;
	presentParameters.SwapEffect = D3DSWAPEFFECT_COPY;
	presentParameters.hDeviceWindow = hwnd;
	presentParameters.Windowed = true;
	presentParameters.EnableAutoDepthStencil = true;
	presentParameters.AutoDepthStencilFormat = D3DFMT_D16;
	presentParameters.Flags = 0;
	presentParameters.FullScreen_RefreshRateInHz = 0;
	presentParameters.PresentationInterval = vsync ? D3DPRESENT_INTERVAL_ONE : D3DPRESENT_INTERVAL_IMMEDIATE;

	HRESULT hr = CreateDeviceExReal(Adapter2, DeviceType2, hwnd, BehaviorFlags2, &presentParameters, pFullscreenDisplayMode, ppReturnedDeviceInterface);
	IDirect3DDevice9Ex* device = *ppReturnedDeviceInterface;
	D3D9DeviceContext* deviceContext = GetD3D9DeviceContext(device, true);
	deviceContext->parent = this;
	deviceContext->Init(device);
	deviceContext->CreateVirtualDevice(hwnd, BehaviorFlags, pPresentationParameters);
	return hr;
}
HRESULT __stdcall D3D9Context2::CreateDevice(IDirect3D9Ex* This, UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)	//static
{
	auto context = GetD3D9Context(This);
	if (context == NULL || context->d3d9 == NULL)
	{
		auto vtable = context != NULL ? context->originalVTable : GetOriginalVTable(This);
		return vtable->CreateDevice(This, Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
	}
	else
	{
		return context->CreateDevice_(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
	}
}
HRESULT __stdcall D3D9Context2::CreateDeviceEx(IDirect3D9Ex* This, UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, D3DDISPLAYMODEEX* pFullscreenDisplayMode, IDirect3DDevice9Ex** ppReturnedDeviceInterface)	//static
{
	auto context = GetD3D9Context(This);
	if (context == NULL || context->d3d9 == NULL)
	{
		auto vtable = context != NULL ? context->originalVTable : GetOriginalVTable(This);
		return vtable->CreateDeviceEx(This, Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, pFullscreenDisplayMode, ppReturnedDeviceInterface);
	}
	else
	{
		return context->CreateDeviceEx_(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, pFullscreenDisplayMode, ppReturnedDeviceInterface);
	}
}

bool GetIsEx(IDirect3D9* d3d9)
{
	HRESULT hr = 0;
	IDirect3D9Ex* d3d9Ex = NULL;
	hr = d3d9->QueryInterface(IID_IDirect3D9Ex, (void**)&d3d9Ex);
	if (SUCCEEDED(hr) && d3d9Ex != NULL)
	{
		SafeRelease(d3d9Ex);
		return true;
	}
	return false;
}

IDirect3D9* CreateAndOverrideDirect3D9()
{
	HRESULT hr = 0;
	HMODULE d3d9Module = LoadLibraryA("d3d9.dll");
	FARPROC _create = GetProcAddress(d3d9Module, "Direct3DCreate9");
	typedef IDirect3D9* (__stdcall* Direct3DCreate9_Func)(UINT);
	Direct3DCreate9_Func _Direct3DCreate9 = (Direct3DCreate9_Func)_create;
	IDirect3D9* d3d9 = NULL;
	if (_Direct3DCreate9)
	{
		d3d9 = _Direct3DCreate9(D3D_SDK_VERSION);
	}
	if (d3d9 != NULL)
	{
		auto context = GetD3D9Context(d3d9, true);
		context->Init(d3d9);
	}
	return d3d9;
}

IDirect3D9Ex* CreateAndOverrideDirect3D9Ex()
{
	HRESULT hr = 0;
	HMODULE d3d9Module = LoadLibraryA("d3d9.dll");
	typedef HRESULT(__stdcall* Direct3DCreate9Ex_Func)(UINT, IDirect3D9Ex**);
	FARPROC _createEx = GetProcAddress(d3d9Module, "Direct3DCreate9Ex");
	Direct3DCreate9Ex_Func _Direct3DCreate9Ex = (Direct3DCreate9Ex_Func)_createEx;
	IDirect3D9Ex* d3d9 = NULL;
	if (_Direct3DCreate9Ex)
	{
		hr = _Direct3DCreate9Ex(D3D_SDK_VERSION, &d3d9);
	}
	if (d3d9 != NULL)
	{
		auto context = GetD3D9Context(d3d9, true);
		context->Init(d3d9);
	}
	return d3d9;
}