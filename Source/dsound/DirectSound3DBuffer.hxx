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

class DirectSound3DBuffer : public IDirectSound3DBuffer
{
public:
    DirectSound3DBuffer(AgentConstructorParameters(DirectSound3DBuffer));
    virtual ~DirectSound3DBuffer();

    /*** IUnknown ***/

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj);
    STDMETHOD_(ULONG, AddRef)(THIS);
    STDMETHOD_(ULONG, Release)(THIS);

    /*** IDirectSound3DBuffer ***/

    STDMETHOD(GetAllParameters)(THIS_ LPDS3DBUFFER pDs3dBuffer);
    STDMETHOD(GetConeAngles)(THIS_ LPDWORD pdwInsideConeAngle, LPDWORD pdwOutsideConeAngle);
    STDMETHOD(GetConeOrientation)(THIS_ LPD3DVECTOR pvOrientation);
    STDMETHOD(GetConeOutsideVolume)(THIS_ LPLONG plConeOutsideVolume);
    STDMETHOD(GetMaxDistance)(THIS_ LPD3DVALUE pflMaxDistance);
    STDMETHOD(GetMinDistance)(THIS_ LPD3DVALUE pflMinDistance);
    STDMETHOD(GetMode)(THIS_ LPDWORD pdwMode);
    STDMETHOD(GetPosition)(THIS_ LPD3DVECTOR pvPosition);
    STDMETHOD(GetVelocity)(THIS_ LPD3DVECTOR pvVelocity);
    STDMETHOD(SetAllParameters)(THIS_ LPCDS3DBUFFER pcDs3dBuffer, DWORD dwApply);
    STDMETHOD(SetConeAngles)(THIS_ DWORD dwInsideConeAngle, DWORD dwOutsideConeAngle, DWORD dwApply);
    STDMETHOD(SetConeOrientation)(THIS_ D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply);
    STDMETHOD(SetConeOutsideVolume)(THIS_ LONG lConeOutsideVolume, DWORD dwApply);
    STDMETHOD(SetMaxDistance)(THIS_ D3DVALUE flMaxDistance, DWORD dwApply);
    STDMETHOD(SetMinDistance)(THIS_ D3DVALUE flMinDistance, DWORD dwApply);
    STDMETHOD(SetMode)(THIS_ DWORD dwMode, DWORD dwApply);
    STDMETHOD(SetPosition)(THIS_ D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply);
    STDMETHOD(SetVelocity)(THIS_ D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply);

protected:
    AgentStateStruct(DirectSound3DBuffer);
};