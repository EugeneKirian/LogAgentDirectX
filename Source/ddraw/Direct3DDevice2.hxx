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

class Direct3DDevice2 : public IDirect3DDevice2
{
public:
    Direct3DDevice2(AgentConstructorParameters(Direct3DDevice2));
    virtual ~Direct3DDevice2();

    /*** IUnknown ***/

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj);
    STDMETHOD_(ULONG, AddRef)(THIS);
    STDMETHOD_(ULONG, Release)(THIS);

    /*** IDirect3DDevice2 ***/

    STDMETHOD(GetCaps)(THIS_ LPD3DDEVICEDESC, LPD3DDEVICEDESC);
    STDMETHOD(SwapTextureHandles)(THIS_ LPDIRECT3DTEXTURE2, LPDIRECT3DTEXTURE2);
    STDMETHOD(GetStats)(THIS_ LPD3DSTATS);
    STDMETHOD(AddViewport)(THIS_ LPDIRECT3DVIEWPORT2);
    STDMETHOD(DeleteViewport)(THIS_ LPDIRECT3DVIEWPORT2);
    STDMETHOD(NextViewport)(THIS_ LPDIRECT3DVIEWPORT2, LPDIRECT3DVIEWPORT2*, DWORD);
    STDMETHOD(EnumTextureFormats)(THIS_ LPD3DENUMTEXTUREFORMATSCALLBACK, LPVOID);
    STDMETHOD(BeginScene)(THIS);
    STDMETHOD(EndScene)(THIS);
    STDMETHOD(GetDirect3D)(THIS_ LPDIRECT3D2*);
    STDMETHOD(SetCurrentViewport)(THIS_ LPDIRECT3DVIEWPORT2);
    STDMETHOD(GetCurrentViewport)(THIS_ LPDIRECT3DVIEWPORT2*);
    STDMETHOD(SetRenderTarget)(THIS_ LPDIRECTDRAWSURFACE, DWORD);
    STDMETHOD(GetRenderTarget)(THIS_ LPDIRECTDRAWSURFACE*);
    STDMETHOD(Begin)(THIS_ D3DPRIMITIVETYPE, D3DVERTEXTYPE, DWORD);
    STDMETHOD(BeginIndexed)(THIS_ D3DPRIMITIVETYPE, D3DVERTEXTYPE, LPVOID, DWORD, DWORD);
    STDMETHOD(Vertex)(THIS_ LPVOID);
    STDMETHOD(Index)(THIS_ WORD);
    STDMETHOD(End)(THIS_ DWORD);
    STDMETHOD(GetRenderState)(THIS_ D3DRENDERSTATETYPE, LPDWORD);
    STDMETHOD(SetRenderState)(THIS_ D3DRENDERSTATETYPE, DWORD);
    STDMETHOD(GetLightState)(THIS_ D3DLIGHTSTATETYPE, LPDWORD);
    STDMETHOD(SetLightState)(THIS_ D3DLIGHTSTATETYPE, DWORD);
    STDMETHOD(SetTransform)(THIS_ D3DTRANSFORMSTATETYPE, LPD3DMATRIX);
    STDMETHOD(GetTransform)(THIS_ D3DTRANSFORMSTATETYPE, LPD3DMATRIX);
    STDMETHOD(MultiplyTransform)(THIS_ D3DTRANSFORMSTATETYPE, LPD3DMATRIX);
    STDMETHOD(DrawPrimitive)(THIS_ D3DPRIMITIVETYPE, D3DVERTEXTYPE, LPVOID, DWORD, DWORD);
    STDMETHOD(DrawIndexedPrimitive)(THIS_ D3DPRIMITIVETYPE, D3DVERTEXTYPE, LPVOID, DWORD, LPWORD, DWORD, DWORD);
    STDMETHOD(SetClipStatus)(THIS_ LPD3DCLIPSTATUS);
    STDMETHOD(GetClipStatus)(THIS_ LPD3DCLIPSTATUS);

protected:
    AgentStateStruct(Direct3DDevice2);
};