#pragma once

class ConstantBuffer
{
public:
	ConstantBuffer();
	~ConstantBuffer();

	void Init(uint32 size, uint32 count);

	void Clear();
	void PushData(int32 rootParamIndex, void* buffer, uint32 size);

	D3D12_GPU_VIRTUAL_ADDRESS GetGpuVirtualAddress(uint32 index);

private:
	void CreateBuffer();

private:
	// gpu에 할당될 공간
	ComPtr<ID3D12Resource>	_cbvBuffer;
	// memcpy용도의 버퍼
	BYTE* _mappedBuffer = nullptr;
	// 버퍼를 몇개를 만들것인가
	uint32					_elementSize = 0;
	uint32					_elementCount = 0;

	// 현재 어떤 버퍼까지 사용을 했는지 추적하는 인덱스
	uint32					_currentIndex = 0;
};

