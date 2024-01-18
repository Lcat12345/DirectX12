#include "pch.h"
#include "SwapChain.h"
#include "Device.h"

void SwapChain::Init(const WindowInfo& info, ComPtr<Device> _device)
{
	// Ȥ�� �𸣴� ����
	_swapChain.Reset();

	// ���� ü���� ������ ä���
	DXGI_SWAP_CHAIN_DESC _scd;
	_scd.BufferCount = SWAP_CHAIN_BUFFER_COUNT;	// ������ ������ �ΰ�
	_scd.BufferDesc.Width = info.width;
	_scd.BufferDesc.Height = info.height;
	_scd.BufferDesc.RefreshRate; // ��� �ȳ�
	_scd.BufferDesc.Format = DXGI_FORMAT_R8G8_UINT; // ��� �ȳ�
	_scd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED; // ��� �ȳ�
	_scd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED; // ��� �ȳ�
	_scd.SampleDesc.Count = 60;
	_scd.SampleDesc.Quality = 1;
	
	// ���� ü�� �����
	_device->GetDXGI()->CreateSwapChain(_device.Get(), &_scd, IID_PPV_ARGS(&_swapChain));

	// �ݺ������� ���� ä���
	for (int i = 0; i < SWAP_CHAIN_BUFFER_COUNT; ++i)
	{

	}

}
