#pragma once

enum class CONSTANT_BUFFER_TYPE : uint8
{
	GLOBAL,
	TRANSFORM,
	MATERIAL,
	END
};

enum
{
	CONSTANT_BUFFER_COUNT = static_cast<uint8>(CONSTANT_BUFFER_TYPE::END)
};

class ConstantBuffer
{
public:
	ConstantBuffer();
	~ConstantBuffer();

	// reg : � �������Ϳ� ������ ������ ���ڷ� �޾ƿ�
	void Init(CBV_REGISTER reg, uint32 size, uint32 count);

	void Clear();
	void PushData(void* buffer, uint32 size);

	void SetGlobalData(void* buffer, uint32 size);

	D3D12_GPU_VIRTUAL_ADDRESS GetGpuVirtualAddress(uint32 index);
	D3D12_CPU_DESCRIPTOR_HANDLE GetCpuHandle(uint32 index);

private:
	void CreateBuffer();
	void CreateView();

private:
	// gpu�� �Ҵ�� ����
	ComPtr<ID3D12Resource>	_cbvBuffer;
	// memcpy�뵵�� ����
	BYTE* _mappedBuffer = nullptr;
	// ���۸� ��� ������ΰ�
	uint32					_elementSize = 0;
	uint32					_elementCount = 0;

	ComPtr<ID3D12DescriptorHeap>		_cbvHeap;
	D3D12_CPU_DESCRIPTOR_HANDLE			_cpuHandleBegin = {};
	uint32								_handleIncrementSize = 0;

	// ���� � ���۱��� ����� �ߴ��� �����ϴ� �ε���
	uint32					_currentIndex = 0;

	CBV_REGISTER			_reg = {};
};

