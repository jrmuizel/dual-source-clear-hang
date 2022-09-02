/* Reproduces a GPU hang caused by drawing with dual source blending
   followed by a draw to a depth buffer

   Can be built with cl reduc.cpp
 */


#include <d3d11.h>
#include <d3d11_3.h>
#include <dxgi1_2.h>
#include <stdio.h>
#include <d3dcompiler.h>
#pragma comment(lib, "d3dcompiler")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxguid.lib")
void main() {
printf("start replay\n");
IDXGIFactory1 * factory;
/*0*/ CreateDXGIFactory1(__uuidof(IDXGIFactory1), (void**) &factory);// = 0
IDXGIAdapter1 * adapter;
/*1*/ factory->EnumAdapters1(/*Adapter: UINT = */ 0, /*ppAdapter: IDXGIAdapter1 * * = */ &adapter);// = 0

static const D3D_FEATURE_LEVEL atmp1[] = {D3D_FEATURE_LEVEL(45312), D3D_FEATURE_LEVEL(45056), D3D_FEATURE_LEVEL(41216), D3D_FEATURE_LEVEL(40960)};
ID3D11Device * device;
D3D_FEATURE_LEVEL ltmp2;
ID3D11DeviceContext * ltmp3;
/*7*/ D3D11CreateDevice(/*pAdapter: IDXGIAdapter * = */ adapter, /*DriverType = */ D3D_DRIVER_TYPE(0), /*Software: HMODULE = */ 0, /*Flags: UINT = */ D3D11_CREATE_DEVICE_VIDEO_SUPPORT | D3D11_CREATE_DEVICE_BGRA_SUPPORT | D3D11_CREATE_DEVICE_PREVENT_INTERNAL_THREADING_OPTIMIZATIONS | D3D11_CREATE_DEVICE_DEBUG, /*pFeatureLevels = */ atmp1, /*FeatureLevels: UINT = */ 4, /*SDKVersion: UINT = */ 7, /*ppDevice: ID3D11Device * * = */ &device, /*pFeatureLevel: D3D_FEATURE_LEVEL * = */ &ltmp2, /*ppImmediateContext: ID3D11DeviceContext * * = */ &ltmp3);// = 0

// Initial draw

ID3D11Device1* device_2;
/*263*/ /*IDXGIDevice4*/device->QueryInterface(/* ID3D11Device1 */ &device_2);// = 0
ID3D11DeviceContext1* ctx;
/*272*/ device_2->GetImmediateContext1(/*ppImmediateContext: ID3D11DeviceContext1 * * = */ &ctx);

const D3D11_BUFFER_DESC tmp552 = {/*ByteWidth = */ 1048576, /*Usage = */ D3D11_USAGE(2), /*BindFlags = */ 1, /*CPUAccessFlags = */ 65536, /*MiscFlags = */ 0, /*StructureByteStride = */ 0 };

ID3D11Buffer* p0x28052d187b8;
/*734*/ device->CreateBuffer(/*pDesc = */ &tmp552, /*pInitialData: const D3D11_SUBRESOURCE_DATA * = */ 0, /*ppBuffer: ID3D11Buffer * * = */ &p0x28052d187b8);// = 0
/*736*/ /*ID3D11Buffer*/p0x28052d187b8->SetPrivateData(/*guid = */ WKPDID_D3DDebugObjectName, /*DataSize: UINT = */ 30, /*pData: const void * = */ "ANGLE_VertexBuffer11 (dynamic)");// = 0
/*737*/ device->Release();// = 12

const D3D11_TEXTURE2D_DESC tmp617 = {/*Width = */ 1024, /*Height = */ 512, /*MipLevels = */ 1, /*ArraySize = */ 1, /*Format = */ DXGI_FORMAT(44), /*SampleDesc = */ {/*Count = */ 1, /*Quality = */ UINT(0)}, /*Usage = */ D3D11_USAGE(0), /*BindFlags = */ 72, /*CPUAccessFlags = */ 0, /*MiscFlags = */ 0 };
ID3D11Texture2D* p0x28052d184b8;
/*880*/ device->CreateTexture2D(/*pDesc = */ &tmp617, /*pInitialData: const D3D11_SUBRESOURCE_DATA * = */ 0, /*ppTexture2D: ID3D11Texture2D * * = */ &p0x28052d184b8);// = 0
/*882*/ /*ID3D11Texture2D1*/p0x28052d184b8->SetPrivateData(/*guid = */ WKPDID_D3DDebugObjectName, /*DataSize: UINT = */ 32, /*pData: const void * = */ "ANGLE_createRenderTarget.Texture");// = 0
const D3D11_DEPTH_STENCIL_VIEW_DESC tmp621 = {/*Format = */ DXGI_FORMAT(45), /*ViewDimension = */ D3D11_DSV_DIMENSION(3), /*Flags = */ 0, /*None = */ {/*Texture2D = */ {/*MipSlice = */ 0}} };
ID3D11DepthStencilView* p0x28052d45cf8;
/*886*/ device->CreateDepthStencilView(/*pResource: ID3D11Resource * = */ p0x28052d184b8, /*pDesc = */ &tmp621, /*ppDepthStencilView: ID3D11DepthStencilView * * = */ &p0x28052d45cf8);// = 0
/*888*/ /*ID3D11DepthStencilView*/p0x28052d45cf8->SetPrivateData(/*guid = */ WKPDID_D3DDebugObjectName, /*DataSize: UINT = */ 28, /*pData: const void * = */ "ANGLE_createRenderTarget.DSV");// = 0
D3D11_DEPTH_STENCIL_VIEW_DESC ltmp623;
/*889*/ /*ID3D11DepthStencilView*/p0x28052d45cf8->GetDesc(/*pDesc: D3D11_DEPTH_STENCIL_VIEW_DESC * = */ &ltmp623);



const D3D11_BUFFER_DESC tmp605 = {/*ByteWidth = */ 8, /*Usage = */ D3D11_USAGE(3), /*BindFlags = */ 0, /*CPUAccessFlags = */ 196608, /*MiscFlags = */ 0, /*StructureByteStride = */ 0 };
ID3D11Buffer* p0x28052d181f8;
/*834*/ device->CreateBuffer(/*pDesc = */ &tmp605, /*pInitialData: const D3D11_SUBRESOURCE_DATA * = */ 0, /*ppBuffer: ID3D11Buffer * * = */ &p0x28052d181f8);// = 0
/*836*/ /*ID3D11Buffer*/p0x28052d181f8->SetPrivateData(/*guid = */ WKPDID_D3DDebugObjectName, /*DataSize: UINT = */ 29, /*pData: const void * = */ "ANGLE_Buffer11::NativeStorage");// = 0
D3D11_MAPPED_SUBRESOURCE ltmp607;
/*837*/ ctx->Map(/*pResource: ID3D11Resource * = */ p0x28052d181f8, /*Subresource: UINT = */ 0, /*MapType = */ D3D11_MAP(2), /*MapFlags: UINT = */ 0, /*pMappedResource: D3D11_MAPPED_SUBRESOURCE * = */ &ltmp607);// = 0
void* p0x280509cd000 = ltmp607.pData; // size: 8
static const unsigned char btmp608[] = { 0x0, 0x0, 0xff, 0x0, 0x0, 0xff, 0xff, 0xff };
/*838*/ memcpy(/*dest: void * = */ p0x280509cd000, /*src = */ btmp608, /*n: size_t = */ 8);
/*839*/ ctx->Unmap(/*pResource: ID3D11Resource * = */ p0x28052d181f8, /*Subresource: UINT = */ 0);

const D3D11_BUFFER_DESC tmp677 = {/*ByteWidth = */ 8, /*Usage = */ D3D11_USAGE(0), /*BindFlags = */ 17, /*CPUAccessFlags = */ 0, /*MiscFlags = */ 0, /*StructureByteStride = */ 0 };
ID3D11Buffer* p0x28052d6a2f8;
/*969*/ device->CreateBuffer(/*pDesc = */ &tmp677, /*pInitialData: const D3D11_SUBRESOURCE_DATA * = */ 0, /*ppBuffer: ID3D11Buffer * * = */ &p0x28052d6a2f8);// = 0
/*971*/ /*ID3D11Buffer*/p0x28052d6a2f8->SetPrivateData(/*guid = */ WKPDID_D3DDebugObjectName, /*DataSize: UINT = */ 29, /*pData: const void * = */ "ANGLE_Buffer11::NativeStorage");// = 0
const D3D11_BOX tmp679 = {/*left = */ 0, /*top = */ 0, /*front = */ 0, /*right = */ 8, /*bottom = */ 1, /*back = */ 1 };
/*972*/ ctx->CopySubresourceRegion(/*pDstResource: ID3D11Resource * = */ p0x28052d6a2f8, /*DstSubresource: UINT = */ 0, /*DstX: UINT = */ 0, /*DstY: UINT = */ 0, /*DstZ: UINT = */ 0, /*pSrcResource: ID3D11Resource * = */ p0x28052d181f8, /*SrcSubresource: UINT = */ 0, /*pSrcBox = */ &tmp679);

/*5645*/ ctx->GSSetShader(/*pShader: ID3D11GeometryShader * = */ 0, /*ppClassInstances: ID3D11ClassInstance * const * = */ 0, /*NumClassInstances: UINT = */ 0);
const D3D11_SAMPLER_DESC tmp798x = {/*Filter = */ D3D11_FILTER(20), /*AddressU = */ D3D11_TEXTURE_ADDRESS_MODE(3), /*AddressV = */ D3D11_TEXTURE_ADDRESS_MODE(3), /*AddressW = */ D3D11_TEXTURE_ADDRESS_MODE(1), /*MipLODBias = */ 0.0, /*MaxAnisotropy = */ 1, /*ComparisonFunc = */ D3D11_COMPARISON_FUNC(4), /*BorderColor = */ {0.0, 0.0, 0.0, 0.0}, /*MinLOD = */ -1000.0, /*MaxLOD = */ 1000.0 };
ID3D11SamplerState* p0x28052d76320x;
/*1152*/ device->CreateSamplerState(/*pSamplerDesc = */ &tmp798x, /*ppSamplerState: ID3D11SamplerState * * = */ &p0x28052d76320x);// = 0
ID3D11SamplerState* const ptmp3031 = p0x28052d76320x;
/*5647*/ ctx->VSSetSamplers(/*StartSlot: UINT = */ 0, /*NumSamplers: UINT = */ 1, /*ppSamplers = */ &ptmp3031);
const D3D11_SHADER_RESOURCE_VIEW_DESC tmp3032 = {/*Format = */ DXGI_FORMAT(28), /*ViewDimension = */ D3D11_SRV_DIMENSION(4), /*None = */ {/*Texture2D = */ {/*MostDetailedMip = */ 0, /*MipLevels = */ 1}} };

ID3D11SamplerState* const ptmp3038 = p0x28052d76320x;
/*5663*/ ctx->PSSetSamplers(/*StartSlot: UINT = */ 0, /*NumSamplers: UINT = */ 1, /*ppSamplers = */ &ptmp3038);


/*5681*/ ctx->IASetPrimitiveTopology(/*Topology = */ D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

const D3D11_TEXTURE2D_DESC tmp2986 = {/*Width = */ 1024, /*Height = */ 512, /*MipLevels = */ 1, /*ArraySize = */ 1, /*Format = */ DXGI_FORMAT(28), /*SampleDesc = */ {/*Count = */ 1, /*Quality = */ UINT(0)}, /*Usage = */ D3D11_USAGE(0), /*BindFlags = */ 168, /*CPUAccessFlags = */ 0, /*MiscFlags = */ 0 };
ID3D11Texture2D* rt_dual_source_dest;
/*5583*/ device->CreateTexture2D(/*pDesc = */ &tmp2986, /*pInitialData: const D3D11_SUBRESOURCE_DATA * = */ 0, /*ppTexture2D: ID3D11Texture2D * * = */ &rt_dual_source_dest);// = 0
/*5585*/ /*ID3D11Texture2D1*/rt_dual_source_dest->SetPrivateData(/*guid = */ WKPDID_D3DDebugObjectName, /*DataSize: UINT = */ 26, /*pData: const void * = */ "ANGLE_TexStorage2D.Texture");// = 0

ID3D11RenderTargetView* p0x28052d6e438;
const D3D11_RENDER_TARGET_VIEW_DESC tmp2990x = {/*Format = */ DXGI_FORMAT(28), /*ViewDimension = */ D3D11_RTV_DIMENSION(4), /*None = */ {/*Texture2D = */ {/*MipSlice = */ 0}} };

/*5589*/ device->CreateRenderTargetView(/*pResource: ID3D11Resource * = */ rt_dual_source_dest, /*pDesc = */ &tmp2990x, /*ppRTView: ID3D11RenderTargetView * * = */ &p0x28052d6e438);// = 0
/*5591*/ /*ID3D11RenderTargetView1*/p0x28052d6e438->SetPrivateData(/*guid = */ WKPDID_D3DDebugObjectName, /*DataSize: UINT = */ 22, /*pData: const void * = */ "ANGLE_TexStorage2D.RTV");// = 0
D3D11_RENDER_TARGET_VIEW_DESC ltmp2992;
static const FLOAT atmp2996[] = { 1.0, 1.0, 1.0, 1.0 };
/*5597*/ ctx->ClearRenderTargetView(/*pRenderTargetView: ID3D11RenderTargetView * = */ p0x28052d6e438, /*ColorRGBA = */ atmp2996);
ID3D11RenderTargetView * const ptmp3318 = p0x28052d6e438;
/*6224*/ ctx->OMSetRenderTargets(/*NumViews: UINT = */ 1, /*ppRenderTargetViews = */ &ptmp3318, /*pDepthStencilView: ID3D11DepthStencilView * = */ p0x28052d45cf8);
const D3D11_BLEND_DESC tmp1118x = {/*AlphaToCoverageEnable = */ TRUE, /*IndependentBlendEnable = */ FALSE, /*RenderTarget = */ {
	{/*BlendEnable = */ TRUE, /*SrcBlend = */ D3D11_BLEND_ONE, /*DestBlend = */ D3D11_BLEND_INV_SRC1_COLOR, /*BlendOp = */ D3D11_BLEND_OP_ADD, /*SrcBlendAlpha = */ D3D11_BLEND_ONE, /*DestBlendAlpha = */ D3D11_BLEND_INV_SRC1_ALPHA, /*BlendOpAlpha = */D3D11_BLEND_OP_ADD, /*RenderTargetWriteMask = */ 15},
	{/*BlendEnable = */ BOOL(0), /*SrcBlend = */ D3D11_BLEND(0), /*DestBlend = */ D3D11_BLEND(0), /*BlendOp = */ D3D11_BLEND_OP(0), /*SrcBlendAlpha = */ D3D11_BLEND(0), /*DestBlendAlpha = */ D3D11_BLEND(0), /*BlendOpAlpha = */ D3D11_BLEND_OP(0), /*RenderTargetWriteMask = */ 15},
	{/*BlendEnable = */ BOOL(0), /*SrcBlend = */ D3D11_BLEND(0), /*DestBlend = */ D3D11_BLEND(0), /*BlendOp = */ D3D11_BLEND_OP(0), /*SrcBlendAlpha = */ D3D11_BLEND(0), /*DestBlendAlpha = */ D3D11_BLEND(0), /*BlendOpAlpha = */ D3D11_BLEND_OP(0), /*RenderTargetWriteMask = */ 15},
	{/*BlendEnable = */ BOOL(0), /*SrcBlend = */ D3D11_BLEND(0), /*DestBlend = */ D3D11_BLEND(0), /*BlendOp = */ D3D11_BLEND_OP(0), /*SrcBlendAlpha = */ D3D11_BLEND(0), /*DestBlendAlpha = */ D3D11_BLEND(0), /*BlendOpAlpha = */ D3D11_BLEND_OP(0), /*RenderTargetWriteMask = */ 15},
	{/*BlendEnable = */ BOOL(0), /*SrcBlend = */ D3D11_BLEND(0), /*DestBlend = */ D3D11_BLEND(0), /*BlendOp = */ D3D11_BLEND_OP(0), /*SrcBlendAlpha = */ D3D11_BLEND(0), /*DestBlendAlpha = */ D3D11_BLEND(0), /*BlendOpAlpha = */ D3D11_BLEND_OP(0), /*RenderTargetWriteMask = */ 15},
	{/*BlendEnable = */ BOOL(0), /*SrcBlend = */ D3D11_BLEND(0), /*DestBlend = */ D3D11_BLEND(0), /*BlendOp = */ D3D11_BLEND_OP(0), /*SrcBlendAlpha = */ D3D11_BLEND(0), /*DestBlendAlpha = */ D3D11_BLEND(0), /*BlendOpAlpha = */ D3D11_BLEND_OP(0), /*RenderTargetWriteMask = */ 15},
	{/*BlendEnable = */ BOOL(0), /*SrcBlend = */ D3D11_BLEND(0), /*DestBlend = */ D3D11_BLEND(0), /*BlendOp = */ D3D11_BLEND_OP(0), /*SrcBlendAlpha = */ D3D11_BLEND(0), /*DestBlendAlpha = */ D3D11_BLEND(0), /*BlendOpAlpha = */ D3D11_BLEND_OP(0), /*RenderTargetWriteMask = */ 15},
	{/*BlendEnable = */ BOOL(0), /*SrcBlend = */ D3D11_BLEND(0), /*DestBlend = */ D3D11_BLEND(0), /*BlendOp = */ D3D11_BLEND_OP(0), /*SrcBlendAlpha = */ D3D11_BLEND(0), /*DestBlendAlpha = */ D3D11_BLEND(0), /*BlendOpAlpha = */ D3D11_BLEND_OP(0), /*RenderTargetWriteMask = */ 15}} };
ID3D11BlendState* p0x28052d760e0x;
/*1717*/ device->CreateBlendState(/*pBlendStateDesc = */ &tmp1118x, /*ppBlendState: ID3D11BlendState * * = */ &p0x28052d760e0x);// = 0
static const FLOAT atmp3320[] = {0.0, 0.0, 0.0, 0.0};
/*6228*/ ctx->OMSetBlendState(/*pBlendState: ID3D11BlendState * = */ p0x28052d760e0x, /*BlendFactor = */ atmp3320, /*SampleMask = */ UINT(4294967295));

ID3D11VertexShader* p0x28052d452d0;
ID3DBlob* ds_vsBlob;
{
	ID3DBlob* errors;
	static const unsigned char dualsource_vs[] = R"(

void main(
  float4 v0 : TEXCOORD0,
  out float4 o0 : SV_Position0)
{
  o0 = 0;
  return;
}
)";
	//HRESULT hr = D3DCompileFromFile(L"dualsource_vs.hlsl", nullptr, nullptr, "main", "vs_4_1",/*D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION*/ D3DCOMPILE_OPTIMIZATION_LEVEL2, 0, &ds_vsBlob, &errors);
	HRESULT hr = D3DCompile(dualsource_vs, sizeof(dualsource_vs), "dualsource_vs.hlsl", nullptr, nullptr, "main", "vs_4_1",/*D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION*/ D3DCOMPILE_OPTIMIZATION_LEVEL2, 0, &ds_vsBlob, &errors);
	if (errors) {
		printf("Failed to compile\n");
		printf("errors: %s\n", (char*)errors->GetBufferPointer());
		if (hr != S_OK)
			exit(1);
	}
}
/*752*/ device->CreateVertexShader(ds_vsBlob->GetBufferPointer(), ds_vsBlob->GetBufferSize(), /*pClassLinkage: ID3D11ClassLinkage * = */ 0, /*ppVertexShader: ID3D11VertexShader * * = */ &p0x28052d452d0);// = 0
/*6229*/ ctx->VSSetShader(/*pVertexShader: ID3D11VertexShader * = */ p0x28052d452d0, /*ppClassInstances: ID3D11ClassInstance * const * = */ 0, /*NumClassInstances: UINT = */ 0);


static const D3D11_INPUT_ELEMENT_DESC atmp819[] = { 
	{/*SemanticName = */ "TEXCOORD", /*SemanticIndex = */ 0, /*Format = */ DXGI_FORMAT_R8G8_UNORM, /*InputSlot = */ 0, /*AlignedByteOffset = */ UINT(0), /*InputSlotClass = */ D3D11_INPUT_PER_VERTEX_DATA, /*InstanceDataStepRate = */ 0},
	{/*SemanticName = */ "TEXCOORD", /*SemanticIndex = */ 1, /*Format = */ DXGI_FORMAT_R16_UINT, /*InputSlot = */ 1, /*AlignedByteOffset = */ UINT(0), /*InputSlotClass = */ D3D11_INPUT_PER_INSTANCE_DATA, /*InstanceDataStepRate = */ 1},
	{/*SemanticName = */ "TEXCOORD", /*SemanticIndex = */ 2, /*Format = */ DXGI_FORMAT_R16_UINT, /*InputSlot = */ 2, /*AlignedByteOffset = */ UINT(0), /*InputSlotClass = */ D3D11_INPUT_PER_INSTANCE_DATA, /*InstanceDataStepRate = */ 1},
	{/*SemanticName = */ "TEXCOORD", /*SemanticIndex = */ 3, /*Format = */ DXGI_FORMAT_R32_SINT, /*InputSlot = */ 3, /*AlignedByteOffset = */ UINT(0), /*InputSlotClass = */ D3D11_INPUT_PER_INSTANCE_DATA, /*InstanceDataStepRate = */ 1} };
ID3D11InputLayout* p0x28052d755a0;
/*1189*/ device->CreateInputLayout(/*pInputElementDescs = */ atmp819, /*NumElements: UINT = */ 2, /*pShaderBytecodeWithInputSignature = */ ds_vsBlob->GetBufferPointer(), /*BytecodeLength: SIZE_T = */ ds_vsBlob->GetBufferSize(), /*ppInputLayout: ID3D11InputLayout * * = */ &p0x28052d755a0);// = 0
/*5679*/ ctx->IASetInputLayout(/*pInputLayout: ID3D11InputLayout * = */ p0x28052d755a0);
static const unsigned char dualsource_ps[] = R"(

void main( 
  float4 v0 : SV_Position0,
  out float4 o0 : SV_TARGET0,
  out float4 o1 : SV_TARGET1)
{
  o0.xyzw = 0;
  o1.xyzw = 0;
  return;
}
)";
ID3DBlob* ds_psBlob;
{
	ID3DBlob* errors;

	//D3DCompileFromFile(L"dualsource_ps.hlsl", nullptr, nullptr, "main", "ps_4_1",/*D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION*/ D3DCOMPILE_OPTIMIZATION_LEVEL2, 0, &ds_psBlob, &errors);
	HRESULT hr = D3DCompile(dualsource_ps, sizeof(dualsource_ps), "dualsource_ps.hlsl", nullptr, nullptr, "main", "ps_4_1",/*D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION*/ D3DCOMPILE_OPTIMIZATION_LEVEL2, 0, &ds_psBlob, &errors);

	if (errors) {
		printf("Failed to compile\n");
		printf("errors: %s\n", (char*)errors->GetBufferPointer());
		if (hr != S_OK)
			exit(1);
	}
}

ID3D11PixelShader* p0x28052d44450;
/*764*/ device->CreatePixelShader(ds_psBlob->GetBufferPointer(), ds_psBlob->GetBufferSize(), /*pClassLinkage: ID3D11ClassLinkage * = */ 0, /*ppPixelShader: ID3D11PixelShader * * = */ &p0x28052d44450);// = 0
/*6230*/ ctx->PSSetShader(/*pPixelShader: ID3D11PixelShader * = */ p0x28052d44450, /*ppClassInstances: ID3D11ClassInstance * const * = */ 0, /*NumClassInstances: UINT = */ 0);

ID3D11Buffer* p0x28052d7ae78;
const D3D11_BUFFER_DESC tmp1140 = {/*ByteWidth = */ 80, /*Usage = */ D3D11_USAGE(0), /*BindFlags = */ 4, /*CPUAccessFlags = */ 0, /*MiscFlags = */ 0, /*StructureByteStride = */ 0 };
/*1774*/ device->CreateBuffer(/*pDesc = */ &tmp1140, /*pInitialData: const D3D11_SUBRESOURCE_DATA * = */ 0, /*ppBuffer: ID3D11Buffer * * = */ &p0x28052d7ae78);// = 0
static const unsigned char btmp1141[] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x3b, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xbf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x0, 0x80, 0xb4, 0x1, 0x0, 0x0, 0x34, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x3f };
/*1775*/ ctx->UpdateSubresource(/*pDstResource: ID3D11Resource * = */ p0x28052d7ae78, /*DstSubresource: UINT = */ 0, /*pDstBox: const D3D11_BOX * = */ 0, /*pSrcData = */ btmp1141, /*SrcRowPitch: UINT = */ 0, /*SrcDepthPitch: UINT = */ 0);
ID3D11Buffer * const ptmp3337 = p0x28052d7ae78;
/*6279*/ ctx->VSSetConstantBuffers(/*StartSlot: UINT = */ 0, /*NumBuffers: UINT = */ 1, /*ppConstantBuffers = */ &ptmp3337);
const D3D11_VIEWPORT viewport = {/*TopLeftX = */ 0.0, /*TopLeftY = */ 0.0, /*Width = */ 512.0, /*Height = */ 512.0, /*MinDepth = */ 0.0, /*MaxDepth = */ 1.0 };
/*6304*/ ctx->RSSetViewports(/*NumViewports: UINT = */ 1, /*pViewports = */ &viewport);
static ID3D11Buffer * const vertex_buffers[] = {p0x28052d6a2f8, p0x28052d187b8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const UINT strides[] = {2, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const UINT offsets[] = {0, 24400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
/*6280*/ ctx->IASetVertexBuffers(/*StartSlot: UINT = */ 0, /*NumBuffers: UINT = */ 16, /*ppVertexBuffers = */ vertex_buffers, /*pStrides = */ strides, /*pOffsets = */ offsets);
///*6281*/ ctx->DrawIndexedInstanced(/*IndexCountPerInstance: UINT = */ 6, /*InstanceCount: UINT = */ 1, /*StartIndexLocation: UINT = */ 0, /*BaseVertexLocation: INT = */ 0, /*StartInstanceLocation: UINT = */ 0);
/*6324*/ ctx->Draw(/*VertexCount: UINT = */3, /*StartVertexLocation: UINT = */ 0);

ctx->Flush();

// Stencil clear draw

const D3D11_TEXTURE2D_DESC tmp3341 = {/*Width = */ 512, /*Height = */ 512, /*MipLevels = */ 1, /*ArraySize = */ 1, /*Format = */ DXGI_FORMAT_R24G8_TYPELESS, /*SampleDesc = */ {/*Count = */ 1, /*Quality = */ UINT(0)}, /*Usage = */ D3D11_USAGE(0), /*BindFlags = */ 72, /*CPUAccessFlags = */ 0, /*MiscFlags = */ 0};
ID3D11Texture2D * p0x28052d931f8_2;
/*6282*/ device->CreateTexture2D(/*pDesc = */ &tmp3341, /*pInitialData: const D3D11_SUBRESOURCE_DATA * = */ 0, /*ppTexture2D: ID3D11Texture2D * * = */ &p0x28052d931f8_2);// = 0
/*6284*/ /*ID3D11Texture2D1*/p0x28052d931f8_2->SetPrivateData(/*guid = */ WKPDID_D3DDebugObjectName, /*DataSize: UINT = */ 32, /*pData: const void * = */ "ANGLE_createRenderTarget.Texture");// = 0
const D3D11_DEPTH_STENCIL_VIEW_DESC tmp3345 = {/*Format = */ DXGI_FORMAT_D24_UNORM_S8_UINT, /*ViewDimension = */ D3D11_DSV_DIMENSION(3), /*Flags = */ 0, /*None = */ {/*Texture2D = */ {/*MipSlice = */ 0}}};
ID3D11DepthStencilView * p0x28052d9b438;
/*6288*/ device->CreateDepthStencilView(/*pResource: ID3D11Resource * = */ p0x28052d931f8_2, /*pDesc = */ &tmp3345, /*ppDepthStencilView: ID3D11DepthStencilView * * = */ &p0x28052d9b438);// = 0
/*6321*/ /*ID3D11Texture2D1*/p0x28052d931f8_2->Release();// = 1
/*6290*/ /*ID3D11DepthStencilView*/p0x28052d9b438->SetPrivateData(/*guid = */ WKPDID_D3DDebugObjectName, /*DataSize: UINT = */ 28, /*pData: const void * = */ "ANGLE_createRenderTarget.DSV");// = 0

const D3D11_BLEND_DESC no_blend_desc = {/*AlphaToCoverageEnable = */ FALSE, /*IndependentBlendEnable = */ FALSE, /*RenderTarget = */ {
	{/*BlendEnable = */ FALSE, /*SrcBlend = */ D3D11_BLEND(0), /*DestBlend = */ D3D11_BLEND(0), /*BlendOp = */ D3D11_BLEND_OP(0), /*SrcBlendAlpha = */ D3D11_BLEND(0), /*DestBlendAlpha = */ D3D11_BLEND(0), /*BlendOpAlpha = */ D3D11_BLEND_OP(0), /*RenderTargetWriteMask = */ 0}} };
ID3D11BlendState * p0x28052d769e0;
/*6296*/ device->CreateBlendState(/*pBlendStateDesc = */ &no_blend_desc, /*ppBlendState: ID3D11BlendState * * = */ &p0x28052d769e0);// = 0

const D3D11_DEPTH_STENCIL_DESC tmp3352 = {/*DepthEnable = */ TRUE, /*DepthWriteMask = */ D3D11_DEPTH_WRITE_MASK_ALL, /*DepthFunc = */ D3D11_COMPARISON_ALWAYS, /*StencilEnable = */ FALSE, /*StencilReadMask = */ 0, /*StencilWriteMask = */ 255, /*FrontFace = */ {/*StencilFailOp = */ D3D11_STENCIL_OP(3), /*StencilDepthFailOp = */ D3D11_STENCIL_OP(3), /*StencilPassOp = */ D3D11_STENCIL_OP(3), /*StencilFunc = */ D3D11_COMPARISON_FUNC(8)}, /*BackFace = */ {/*StencilFailOp = */ D3D11_STENCIL_OP(3), /*StencilDepthFailOp = */ D3D11_STENCIL_OP(3), /*StencilPassOp = */ D3D11_STENCIL_OP(3), /*StencilFunc = */ D3D11_COMPARISON_FUNC(8)}};
ID3D11DepthStencilState* p0x28052d75c60;
/*6297*/ device->CreateDepthStencilState(/*pDepthStencilDesc = */ &tmp3352, /*ppDepthStencilState: ID3D11DepthStencilState * * = */ &p0x28052d75c60);// = 0

const D3D11_BUFFER_DESC clear_constant_buffer_desc = {/*ByteWidth = */ 32, /*Usage = */D3D11_USAGE_DYNAMIC, /*BindFlags = */ D3D11_BIND_CONSTANT_BUFFER, /*CPUAccessFlags = */ 65536, /*MiscFlags = */ 0, /*StructureByteStride = */ 0};
// float r, g, b, a, z, c1padding[3]
static const unsigned char ibtmp3355[] = {0x0, 0x0, 0x0, 0x0,   0x0, 0x0, 0x0, 0x0,   0x0, 0x0, 0x0, 0x0,   0x0, 0x0, 0x0, 0x0,  0x0, 0x0, 0x80, 0x3f,   0x0, 0x0, 0x0, 0x0,   0x0, 0x0, 0x0, 0x0,   0x0, 0x0, 0x0, 0x0};
const D3D11_SUBRESOURCE_DATA tmp3354 = {/*pSysMem = */ ibtmp3355, /*SysMemPitch = */ 32, /*SysMemSlicePitch = */ 32};
ID3D11Buffer * clear_constant_buffer;
/*6298*/ device->CreateBuffer(/*pDesc = */ &clear_constant_buffer_desc, /*pInitialData = */ &tmp3354, /*ppBuffer: ID3D11Buffer * * = */ &clear_constant_buffer);// = 0
/*6300*/ /*ID3D11Buffer*/clear_constant_buffer->SetPrivateData(/*guid = */ WKPDID_D3DDebugObjectName, /*DataSize: UINT = */ 29, /*pData: const void * = */ "ANGLE_Clear11 Constant Buffer");// = 0

const D3D11_VIEWPORT tmp3359 = {/*TopLeftX = */ 0.0, /*TopLeftY = */ 0.0, /*Width = */ 512.0, /*Height = */ 512.0, /*MinDepth = */ 0.0, /*MaxDepth = */ 1.0};
/*6304*/ ctx->RSSetViewports(/*NumViewports: UINT = */ 1, /*pViewports = */ &tmp3359);
/*6305*/ ctx->OMSetBlendState(/*pBlendState: ID3D11BlendState * = */ p0x28052d769e0, /*BlendFactor: const FLOAT * = */ 0, /*SampleMask = */ UINT(4294967295));
/*6306*/ ctx->OMSetDepthStencilState(/*pDepthStencilState: ID3D11DepthStencilState * = */ p0x28052d75c60, /*StencilRef: UINT = */ 0);
ID3D11RasterizerState* p0x280501f4c20;
const D3D11_RASTERIZER_DESC clear_rasterizer_desc = {/*FillMode = */ D3D11_FILL_SOLID, /*CullMode = */ D3D11_CULL_NONE, /*FrontCounterClockwise = */ FALSE, /*DepthBias = */ 0, /*DepthBiasClamp = */ 0.0, /*SlopeScaledDepthBias = */ 0.0, /*DepthClipEnable = */ TRUE, /*ScissorEnable = */ BOOL(1), /*MultisampleEnable = */ FALSE, /*AntialiasedLineEnable = */ FALSE };
/*1136*/ device->CreateRasterizerState(/*pRasterizerDesc = */ &clear_rasterizer_desc, /*ppRasterizerState: ID3D11RasterizerState * * = */ &p0x280501f4c20);// = 0
/*1138*/ /*ID3D11RasterizerState2*/p0x280501f4c20->SetPrivateData(/*guid = */ WKPDID_D3DDebugObjectName, /*DataSize: UINT = */ 51, /*pData: const void * = */ "ANGLE_Clear11 Rasterizer State with scissor enabled");// = 0
/*6307*/ ctx->RSSetState(/*pRasterizerState: ID3D11RasterizerState * = */ p0x280501f4c20);

ID3D11VertexShader * clear_vs;
ID3DBlob* vsBlob;
ID3DBlob* errors;
static const unsigned char clearvs_source[] = R"(

void main( 
  uint v0 : SV_VertexID0,
  out float4 o0 : SV_POSITION0)
{
  const float4 icb[] = { { -1.000000, 1.000000, 0, 0},
                              { 1.000000, -1.000000, 0, 0},
                              { -1.000000, -1.000000, 0, 0},
                              { -1.000000, 1.000000, 0, 0},
                              { 1.000000, 1.000000, 0, 0},
                              { 1.000000, -1.000000, 0, 0} };
// Needs manual fix for instruction: 
// unknown dcl_: dcl_input_sgv v0.x, vertex_id
  float4 r0;
  uint4 bitmask, uiDest;
  float4 fDest;

  r0.x = v0.x;
  o0.xy = icb[r0.x+0].xy;
  o0.zw = float2(0,1);
  return;
}
)";
//D3DCompileFromFile(L"clear11vs.hlsl", nullptr, nullptr, "main", "vs_4_1",/*D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION*/ D3DCOMPILE_OPTIMIZATION_LEVEL2, 0, &vsBlob, &errors);
D3DCompile(clearvs_source, sizeof(clearvs_source), "clear11vs.hlsl", nullptr, nullptr, "main", "vs_4_1",/*D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION*/ D3DCOMPILE_OPTIMIZATION_LEVEL2, 0, &vsBlob, &errors);

if (errors) {
	printf("Failed to compile\n");
	OutputDebugStringA((char*)errors->GetBufferPointer());
	exit(1);
}
/*6308*/ device->CreateVertexShader(vsBlob->GetBufferPointer(), vsBlob->GetBufferSize(), /*pClassLinkage: ID3D11ClassLinkage * = */ 0, /*ppVertexShader: ID3D11VertexShader * * = */ &clear_vs);// = 0
/*6310*/ /*ID3D11VertexShader*/clear_vs->SetPrivateData(/*guid = */ WKPDID_D3DDebugObjectName, /*DataSize: UINT = */ 16, /*pData: const void * = */ "ANGLE_Clear11 VS");// = 0
/*6314*/ ctx->VSSetShader(/*pVertexShader: ID3D11VertexShader * = */ clear_vs, /*ppClassInstances: ID3D11ClassInstance * const * = */ 0, /*NumClassInstances: UINT = */ 0);


static const unsigned char clear_ps_source[] = R"(
cbuffer DepthOnlyData : register(b0)
{
  float zValue_Depth : packoffset(c1);
}

void main( 
  float4 v0 : SV_POSITION0,
  out float oDepth : SV_DEPTH)
{
  oDepth = 0;
  return;
}
)";

ID3D11PixelShader* clear_ps;
ID3DBlob* psBlob;
//ID3DBlob* errors;

//D3DCompileFromFile(L"clear11ps.hlsl", nullptr, nullptr, "main", "ps_4_1",/*D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION*/ D3DCOMPILE_OPTIMIZATION_LEVEL2, 0, &vsBlob, &errors);
D3DCompile(clear_ps_source, sizeof(clear_ps_source), "clear11ps.hlsl", nullptr, nullptr, "main", "ps_4_1",/*D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION*/ D3DCOMPILE_OPTIMIZATION_LEVEL2, 0, &psBlob, &errors);

if (errors) {
	OutputDebugStringA("Failed to compile");
	OutputDebugStringA((char*)errors->GetBufferPointer());

	exit(1);
}


/*6311*/ device->CreatePixelShader(/*pShaderBytecode = */  psBlob->GetBufferPointer(), psBlob->GetBufferSize(), /*pClassLinkage: ID3D11ClassLinkage * = */ 0, /*ppPixelShader: ID3D11PixelShader * * = */ &clear_ps);// = 0
/*6313*/ /*ID3D11PixelShader*/clear_ps->SetPrivateData(WKPDID_D3DDebugObjectName, /*DataSize: UINT = */ 22, /*pData: const void * = */ "ANGLE_Clear11 PS Depth");// = 0
/*6315*/ ctx->PSSetShader(/*pPixelShader: ID3D11PixelShader * = */ clear_ps, /*ppClassInstances: ID3D11ClassInstance * const * = */ 0, /*NumClassInstances: UINT = */ 0);
/*6316*/ ctx->PSSetConstantBuffers(/*StartSlot: UINT = */ 0, /*NumBuffers: UINT = */ 1, /*ppConstantBuffers = */ &clear_constant_buffer);
/*6317*/ ctx->IASetIndexBuffer(/*pIndexBuffer: ID3D11Buffer * = */ 0, /*Format = */ DXGI_FORMAT(0), /*Offset: UINT = */ 0);
/*6318*/ ctx->IASetInputLayout(/*pInputLayout: ID3D11InputLayout * = */ 0);

// We don't need any vertex buffers because we don't use any input geometry
ID3D11Buffer * const tmp3365 = 0;
const UINT tmp3366 = 0;
const UINT tmp3367 = 0;
/*6319*/ ctx->IASetVertexBuffers(/*StartSlot: UINT = */ 0, /*NumBuffers: UINT = */ 1, /*ppVertexBuffers = */ &tmp3365, /*pStrides = */ &tmp3366, /*pOffsets = */ &tmp3367);

/*6322*/ ctx->OMSetRenderTargets(/*NumViews: UINT = */ 0, /*ppRenderTargetViews: ID3D11RenderTargetView * const * = */ 0, /*pDepthStencilView: ID3D11DepthStencilView * = */ p0x28052d9b438);

const D3D11_RECT scissor_rect = {/*left = */ 0, /*top = */ 0, /*right = */ 256, /*bottom = */ 512};
///*6323*/ ctx->RSSetScissorRects(/*NumRects: UINT = */ 1, /*pRects = */ &scissor_rect);

/*6324*/ ctx->Draw(/*VertexCount: UINT = */ 6, /*StartVertexLocation: UINT = */ 0);
/*6454*/ ctx->Flush();
printf("done replay\n");
}
