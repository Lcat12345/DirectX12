#pragma once

// 
// 외주를 맡김.
// 외주 맡긴 걸 받아서 화면에 출력함.
// 

class SwapChain
{
public:
	void Init(const WindowInfo& info, ComPtr<Device> _device);


private:
	ComPtr<IDXGISwapChain> _swapChain;
	ComPtr<ID3D12Resource> _buffer;



};

