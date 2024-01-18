#include "pch.h"
#include "SwapChain.h"
#include "Device.h"

void SwapChain::Init(const WindowInfo& info, ComPtr<Device> _device)
{
	// 혹시 모르니 리셋
	_swapChain.Reset();

	// 스왑 체인의 설명자 채우기
	DXGI_SWAP_CHAIN_DESC _scd;
	_scd.BufferCount = SWAP_CHAIN_BUFFER_COUNT;	// 버퍼의 개수는 두개
	_scd.BufferDesc.Width = info.width;
	_scd.BufferDesc.Height = info.height;
	_scd.BufferDesc.RefreshRate; // 기억 안남
	_scd.BufferDesc.Format = DXGI_FORMAT_R8G8_UINT; // 기억 안남
	_scd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED; // 기억 안남
	_scd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED; // 기억 안남
	_scd.SampleDesc.Count = 60;
	_scd.SampleDesc.Quality = 1;
	
	// 스왑 체인 만들기
	_device->GetDXGI()->CreateSwapChain(_device.Get(), &_scd, IID_PPV_ARGS(&_swapChain));

	// 반복문으로 버퍼 채우기
	for (int i = 0; i < SWAP_CHAIN_BUFFER_COUNT; ++i)
	{

	}

}
