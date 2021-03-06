#pragma once

//#define NOMINMAX
//struct IUnknown;
//#include <Windows.h>
//#include <d3d9.h>

#include <memory>
#include <vector>

#include "Region.h"

class CUpscalerImpl;
class CUpscaler
{
private:
	std::unique_ptr<CUpscalerImpl> impl;
public:
	CUpscaler();
	~CUpscaler();
	void Dispose();
	bool SetSourceTexture(void *texture); //IDirect3DTexture9
	bool SetSwapChain(void* swapChain); //IDirect3DSwapChain9
	void SetDoBeginScene(bool doBeginScene);
	void SetViewRectangle(int x, int y, int width, int height);
	void SetInputRectangle(int x, int y, int width, int height);
	HRESULT Update(const Region &region); //region in unscaled coordinates
	HRESULT Update();
	void SetBorderDirty();
	bool UpdateToTexture(int x, int y, int width, int height);
	bool UpdateToBackBuffer(int x, int y, int width, int height);
	bool UpdateToScreen(int x, int y, int width, int height);
	void SetUpscaleFilter(int upscaleFilter);
	//void SetUpdateRegion(const Region& region); //region in unscaled coordinates, call before each frame 
};
