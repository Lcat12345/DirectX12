#pragma once

// 
// ���ָ� �ñ�.
// ���� �ñ� �� �޾Ƽ� ȭ�鿡 �����.
// 

class SwapChain
{
public:
	void Init(const WindowInfo& info, ComPtr<Device> _device);


private:
	ComPtr<IDXGISwapChain> _swapChain;
	ComPtr<ID3D12Resource> _buffer;



};

