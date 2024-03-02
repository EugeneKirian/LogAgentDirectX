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

class Direct3DDevice : public IDirect3DDevice
{
public:
    Direct3DDevice(AgentConstructorParameters(Direct3DDevice));
    virtual ~Direct3DDevice();

    /*** IUnknown ***/

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj);
    STDMETHOD_(ULONG, AddRef)(THIS);
    STDMETHOD_(ULONG, Release)(THIS);

    /*** IDirect3DDevice ***/

    STDMETHOD(Initialize)(THIS_ LPDIRECT3D, LPGUID, LPD3DDEVICEDESC);
    STDMETHOD(GetCaps)(THIS_ LPD3DDEVICEDESC, LPD3DDEVICEDESC);
    STDMETHOD(SwapTextureHandles)(THIS_ LPDIRECT3DTEXTURE, LPDIRECT3DTEXTURE);
    STDMETHOD(CreateExecuteBuffer)(THIS_ LPD3DEXECUTEBUFFERDESC, LPDIRECT3DEXECUTEBUFFER*, LPUNKNOWN);
    STDMETHOD(GetStats)(THIS_ LPD3DSTATS);
    STDMETHOD(Execute)(THIS_ LPDIRECT3DEXECUTEBUFFER, LPDIRECT3DVIEWPORT, DWORD);
    STDMETHOD(AddViewport)(THIS_ LPDIRECT3DVIEWPORT);
    STDMETHOD(DeleteViewport)(THIS_ LPDIRECT3DVIEWPORT);
    STDMETHOD(NextViewport)(THIS_ LPDIRECT3DVIEWPORT, LPDIRECT3DVIEWPORT*, DWORD);
    STDMETHOD(Pick)(THIS_ LPDIRECT3DEXECUTEBUFFER, LPDIRECT3DVIEWPORT, DWORD, LPD3DRECT);
    STDMETHOD(GetPickRecords)(THIS_ LPDWORD, LPD3DPICKRECORD);
    STDMETHOD(EnumTextureFormats)(THIS_ LPD3DENUMTEXTUREFORMATSCALLBACK, LPVOID);
    STDMETHOD(CreateMatrix)(THIS_ LPD3DMATRIXHANDLE);
    STDMETHOD(SetMatrix)(THIS_ D3DMATRIXHANDLE, CONST LPD3DMATRIX);
    STDMETHOD(GetMatrix)(THIS_ D3DMATRIXHANDLE, LPD3DMATRIX);
    STDMETHOD(DeleteMatrix)(THIS_ D3DMATRIXHANDLE);
    STDMETHOD(BeginScene)(THIS);
    STDMETHOD(EndScene)(THIS);
    STDMETHOD(GetDirect3D)(THIS_ LPDIRECT3D*);

protected:
    AgentStateStruct(Direct3DDevice);
};