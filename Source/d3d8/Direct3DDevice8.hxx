/*
Copyright (c) 2024 Eugene Kirian

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include "Base.hxx"

class Direct3DDevice8 : public IDirect3DDevice8
{
public:
    Direct3DDevice8(AgentConstructorParameters(Direct3DDevice8));
    virtual ~Direct3DDevice8();

    /*** IUnknown ***/

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj);
    STDMETHOD_(ULONG, AddRef)(THIS);
    STDMETHOD_(ULONG, Release)(THIS);

    /*** IDirect3DDevice8 ***/

    STDMETHOD(TestCooperativeLevel)(THIS);
    STDMETHOD_(UINT, GetAvailableTextureMem)(THIS);
    STDMETHOD(ResourceManagerDiscardBytes)(THIS_ DWORD Bytes);
    STDMETHOD(GetDirect3D)(THIS_ LPDIRECT3D8* ppD3D8);
    STDMETHOD(GetDeviceCaps)(THIS_ D3DCAPS8* pCaps);
    STDMETHOD(GetDisplayMode)(THIS_ D3DDISPLAYMODE* pMode);
    STDMETHOD(GetCreationParameters)(THIS_ D3DDEVICE_CREATION_PARAMETERS* pParameters);
    STDMETHOD(SetCursorProperties)(THIS_ UINT XHotSpot, UINT YHotSpot, LPDIRECT3DSURFACE8 pCursorBitmap);
    STDMETHOD_(VOID, SetCursorPosition)(THIS_ UINT XScreenSpace, UINT YScreenSpace, DWORD Flags);
    STDMETHOD_(BOOL, ShowCursor)(THIS_ BOOL bShow);
    STDMETHOD(CreateAdditionalSwapChain)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters, LPDIRECT3DSWAPCHAIN8* pSwapChain);
    STDMETHOD(Reset)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters);
    STDMETHOD(Present)(THIS_ CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion);
    STDMETHOD(GetBackBuffer)(THIS_ UINT BackBuffer, D3DBACKBUFFER_TYPE Type, LPDIRECT3DSURFACE8* ppBackBuffer);
    STDMETHOD(GetRasterStatus)(THIS_ D3DRASTER_STATUS* pRasterStatus);
    STDMETHOD_(VOID, SetGammaRamp)(THIS_ DWORD Flags, CONST D3DGAMMARAMP* pRamp);
    STDMETHOD_(VOID, GetGammaRamp)(THIS_ D3DGAMMARAMP* pRamp);
    STDMETHOD(CreateTexture)(THIS_ UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, LPDIRECT3DTEXTURE8* ppTexture);
    STDMETHOD(CreateVolumeTexture)(THIS_ UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, LPDIRECT3DVOLUMETEXTURE8* ppVolumeTexture);
    STDMETHOD(CreateCubeTexture)(THIS_ UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, LPDIRECT3DCUBETEXTURE8* ppCubeTexture);
    STDMETHOD(CreateVertexBuffer)(THIS_ UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, LPDIRECT3DVERTEXBUFFER8* ppVertexBuffer);
    STDMETHOD(CreateIndexBuffer)(THIS_ UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, LPDIRECT3DINDEXBUFFER8* ppIndexBuffer);
    STDMETHOD(CreateRenderTarget)(THIS_ UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, BOOL Lockable, LPDIRECT3DSURFACE8* ppSurface);
    STDMETHOD(CreateDepthStencilSurface)(THIS_ UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, LPDIRECT3DSURFACE8* ppSurface);
    STDMETHOD(CreateImageSurface)(THIS_ UINT Width, UINT Height, D3DFORMAT Format, LPDIRECT3DSURFACE8* ppSurface);
    STDMETHOD(CopyRects)(THIS_ LPDIRECT3DSURFACE8 pSourceSurface, CONST RECT* pSourceRectsArray, UINT cRects, LPDIRECT3DSURFACE8 pDestinationSurface, CONST POINT* pDestPointsArray);
    STDMETHOD(UpdateTexture)(THIS_ LPDIRECT3DBASETEXTURE8 pSourceTexture, LPDIRECT3DBASETEXTURE8 pDestinationTexture);
    STDMETHOD(GetFrontBuffer)(THIS_ LPDIRECT3DSURFACE8 pDestSurface);
    STDMETHOD(SetRenderTarget)(THIS_ LPDIRECT3DSURFACE8 pRenderTarget, LPDIRECT3DSURFACE8 pNewZStencil);
    STDMETHOD(GetRenderTarget)(THIS_ LPDIRECT3DSURFACE8* ppRenderTarget);
    STDMETHOD(GetDepthStencilSurface)(THIS_ LPDIRECT3DSURFACE8* ppZStencilSurface);
    STDMETHOD(BeginScene)(THIS);
    STDMETHOD(EndScene)(THIS);
    STDMETHOD(Clear)(THIS_ DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, FLOAT Z, DWORD Stencil);
    STDMETHOD(SetTransform)(THIS_ D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix);
    STDMETHOD(GetTransform)(THIS_ D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix);
    STDMETHOD(MultiplyTransform)(THIS_ D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix);
    STDMETHOD(SetViewport)(THIS_ CONST D3DVIEWPORT8* pViewport);
    STDMETHOD(GetViewport)(THIS_ D3DVIEWPORT8* pViewport);
    STDMETHOD(SetMaterial)(THIS_ CONST D3DMATERIAL8* pMaterial);
    STDMETHOD(GetMaterial)(THIS_ D3DMATERIAL8* pMaterial);
    STDMETHOD(SetLight)(THIS_ DWORD Index, CONST D3DLIGHT8* pLight);
    STDMETHOD(GetLight)(THIS_ DWORD Index, D3DLIGHT8* pLight);
    STDMETHOD(LightEnable)(THIS_ DWORD Index, BOOL bEnable);
    STDMETHOD(GetLightEnable)(THIS_ DWORD Index, BOOL* pEnable);
    STDMETHOD(SetClipPlane)(THIS_ DWORD Index, CONST FLOAT* pPlane);
    STDMETHOD(GetClipPlane)(THIS_ DWORD Index, FLOAT* pPlane);
    STDMETHOD(SetRenderState)(THIS_ D3DRENDERSTATETYPE State, DWORD Value);
    STDMETHOD(GetRenderState)(THIS_ D3DRENDERSTATETYPE State, DWORD* pValue);
    STDMETHOD(BeginStateBlock)(THIS);
    STDMETHOD(EndStateBlock)(THIS_ DWORD* pToken);
    STDMETHOD(ApplyStateBlock)(THIS_ DWORD Token);
    STDMETHOD(CaptureStateBlock)(THIS_ DWORD Token);
    STDMETHOD(DeleteStateBlock)(THIS_ DWORD Token);
    STDMETHOD(CreateStateBlock)(THIS_ D3DSTATEBLOCKTYPE Type, DWORD* pToken);
    STDMETHOD(SetClipStatus)(THIS_ CONST D3DCLIPSTATUS8* pClipStatus);
    STDMETHOD(GetClipStatus)(THIS_ D3DCLIPSTATUS8* pClipStatus);
    STDMETHOD(GetTexture)(THIS_ DWORD Stage, LPDIRECT3DBASETEXTURE8* ppTexture);
    STDMETHOD(SetTexture)(THIS_ DWORD Stage, LPDIRECT3DBASETEXTURE8 pTexture);
    STDMETHOD(GetTextureStageState)(THIS_ DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue);
    STDMETHOD(SetTextureStageState)(THIS_ DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value);
    STDMETHOD(ValidateDevice)(THIS_ DWORD* pNumPasses);
    STDMETHOD(GetInfo)(THIS_ DWORD DevInfoID, LPVOID pDevInfoStruct, DWORD DevInfoStructSize);
    STDMETHOD(SetPaletteEntries)(THIS_ UINT PaletteNumber, CONST PALETTEENTRY* pEntries);
    STDMETHOD(GetPaletteEntries)(THIS_ UINT PaletteNumber, PALETTEENTRY* pEntries);
    STDMETHOD(SetCurrentTexturePalette)(THIS_ UINT PaletteNumber);
    STDMETHOD(GetCurrentTexturePalette)(THIS_ UINT* PaletteNumber);
    STDMETHOD(DrawPrimitive)(THIS_ D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount);
    STDMETHOD(DrawIndexedPrimitive)(THIS_ D3DPRIMITIVETYPE PrimitiveType, UINT MinIndex, UINT NumVertices, UINT StartIndex, UINT PrimitiveCount);
    STDMETHOD(DrawPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, LPCVOID pVertexStreamZeroData, UINT VertexStreamZeroStride);
    STDMETHOD(DrawIndexedPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertexIndices, UINT PrimitiveCount, LPCVOID pIndexData, D3DFORMAT IndexDataFormat, LPCVOID pVertexStreamZeroData, UINT VertexStreamZeroStride);
    STDMETHOD(ProcessVertices)(THIS_ UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, LPDIRECT3DVERTEXBUFFER8 pDestBuffer, DWORD Flags);
    STDMETHOD(CreateVertexShader)(THIS_ CONST DWORD* pDeclaration, CONST DWORD* pFunction, DWORD* pHandle, DWORD Usage);
    STDMETHOD(SetVertexShader)(THIS_ DWORD Handle);
    STDMETHOD(GetVertexShader)(THIS_ DWORD* pHandle);
    STDMETHOD(DeleteVertexShader)(THIS_ DWORD Handle);
    STDMETHOD(SetVertexShaderConstant)(THIS_ DWORD Register, LPCVOID pConstantData, DWORD ConstantCount);
    STDMETHOD(GetVertexShaderConstant)(THIS_ DWORD Register, LPVOID pConstantData, DWORD ConstantCount);
    STDMETHOD(GetVertexShaderDeclaration)(THIS_ DWORD Handle, LPVOID pData, DWORD* pSizeOfData);
    STDMETHOD(GetVertexShaderFunction)(THIS_ DWORD Handle, LPVOID pData, DWORD* pSizeOfData);
    STDMETHOD(SetStreamSource)(THIS_ UINT StreamNumber, LPDIRECT3DVERTEXBUFFER8 pStreamData, UINT Stride);
    STDMETHOD(GetStreamSource)(THIS_ UINT StreamNumber, LPDIRECT3DVERTEXBUFFER8* ppStreamData, UINT* pStride);
    STDMETHOD(SetIndices)(THIS_ LPDIRECT3DINDEXBUFFER8 pIndexData, UINT BaseVertexIndex);
    STDMETHOD(GetIndices)(THIS_ LPDIRECT3DINDEXBUFFER8* ppIndexData, UINT* pBaseVertexIndex);
    STDMETHOD(CreatePixelShader)(THIS_ CONST DWORD* pFunction, DWORD* pHandle);
    STDMETHOD(SetPixelShader)(THIS_ DWORD Handle);
    STDMETHOD(GetPixelShader)(THIS_ DWORD* pHandle);
    STDMETHOD(DeletePixelShader)(THIS_ DWORD Handle);
    STDMETHOD(SetPixelShaderConstant)(THIS_ DWORD Register, LPCVOID pConstantData, DWORD ConstantCount);
    STDMETHOD(GetPixelShaderConstant)(THIS_ DWORD Register, LPVOID pConstantData, DWORD ConstantCount);
    STDMETHOD(GetPixelShaderFunction)(THIS_ DWORD Handle, LPVOID pData, DWORD* pSizeOfData);
    STDMETHOD(DrawRectPatch)(THIS_ UINT Handle, CONST FLOAT* pNumSegs, CONST D3DRECTPATCH_INFO* pRectPatchInfo);
    STDMETHOD(DrawTriPatch)(THIS_ UINT Handle, CONST FLOAT* pNumSegs, CONST D3DTRIPATCH_INFO* pTriPatchInfo);
    STDMETHOD(DeletePatch)(THIS_ UINT Handle);

protected:
    AgentStateStruct(Direct3DDevice8);
};