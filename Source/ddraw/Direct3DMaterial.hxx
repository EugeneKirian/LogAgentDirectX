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

class Direct3DMaterial : public IDirect3DMaterial
{
public:
    Direct3DMaterial(AgentConstructorParameters(Direct3DMaterial));
    virtual ~Direct3DMaterial();

    /*** IUnknown ***/

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj);
    STDMETHOD_(ULONG, AddRef)(THIS);
    STDMETHOD_(ULONG, Release)(THIS);

    /*** IDirect3DMaterial ***/

    STDMETHOD(Initialize)(THIS_ LPDIRECT3D);
    STDMETHOD(SetMaterial)(THIS_ LPD3DMATERIAL);
    STDMETHOD(GetMaterial)(THIS_ LPD3DMATERIAL);
    STDMETHOD(GetHandle)(THIS_ LPDIRECT3DDEVICE, LPD3DMATERIALHANDLE);
    STDMETHOD(Reserve)(THIS);
    STDMETHOD(Unreserve)(THIS);

protected:
    AgentStateStruct(Direct3DMaterial);
};