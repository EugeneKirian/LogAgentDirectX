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

class Direct3DViewport3 : public IDirect3DViewport3
{
public:
    Direct3DViewport3(AgentConstructorParameters(Direct3DViewport3));
    virtual ~Direct3DViewport3();

    /*** IUnknown ***/

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj);
    STDMETHOD_(ULONG, AddRef)(THIS);
    STDMETHOD_(ULONG, Release)(THIS);

    /*** IDirect3DViewport ***/

    STDMETHOD(Initialize)(THIS_ LPDIRECT3D);
    STDMETHOD(GetViewport)(THIS_ LPD3DVIEWPORT);
    STDMETHOD(SetViewport)(THIS_ LPD3DVIEWPORT);
    STDMETHOD(TransformVertices)(THIS_ DWORD, LPD3DTRANSFORMDATA, DWORD, LPDWORD);
    STDMETHOD(LightElements)(THIS_ DWORD, LPD3DLIGHTDATA);
    STDMETHOD(SetBackground)(THIS_ D3DMATERIALHANDLE);
    STDMETHOD(GetBackground)(THIS_ LPD3DMATERIALHANDLE, LPBOOL);
    STDMETHOD(SetBackgroundDepth)(THIS_ LPDIRECTDRAWSURFACE);
    STDMETHOD(GetBackgroundDepth)(THIS_ LPDIRECTDRAWSURFACE*, LPBOOL);
    STDMETHOD(Clear)(THIS_ DWORD, LPD3DRECT, DWORD);
    STDMETHOD(AddLight)(THIS_ LPDIRECT3DLIGHT);
    STDMETHOD(DeleteLight)(THIS_ LPDIRECT3DLIGHT);
    STDMETHOD(NextLight)(THIS_ LPDIRECT3DLIGHT, LPDIRECT3DLIGHT*, DWORD);

    /*** IDirect3DViewport2 ***/

    STDMETHOD(GetViewport2)(THIS_ LPD3DVIEWPORT2);
    STDMETHOD(SetViewport2)(THIS_ LPD3DVIEWPORT2);

    /*** IDirect3DViewport3 ***/

    STDMETHOD(SetBackgroundDepth2)(THIS_ LPDIRECTDRAWSURFACE4);
    STDMETHOD(GetBackgroundDepth2)(THIS_ LPDIRECTDRAWSURFACE4*, LPBOOL);
    STDMETHOD(Clear2)(THIS_ DWORD, LPD3DRECT, DWORD, D3DCOLOR, D3DVALUE, DWORD);

protected:
    AgentStateStruct(Direct3DViewport3);
};