#pragma once

// [계약서 / 결제]
// 어떤 레지스터나 버퍼들을 활용하는지 등등.. 서명

class RootSignature
{
public:
	void Init(ComPtr<ID3D12Device> device);

	ComPtr<ID3D12RootSignature>	GetSignature() { return _signature; }

private:
	ComPtr<ID3D12RootSignature>	_signature;
};

