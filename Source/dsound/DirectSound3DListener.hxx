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

class DirectSound3DListener : public IDirectSound3DListener
{
public:
    DirectSound3DListener(AgentConstructorParameters(DirectSound3DListener));
    virtual ~DirectSound3DListener();

    /*** IUnknown ***/

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj);
    STDMETHOD_(ULONG, AddRef)(THIS);
    STDMETHOD_(ULONG, Release)(THIS);

    /*** IDirectSound3DListener ***/

    STDMETHOD(GetAllParameters)(THIS_ LPDS3DLISTENER pListener);
    STDMETHOD(GetDistanceFactor)(THIS_ LPD3DVALUE pflDistanceFactor);
    STDMETHOD(GetDopplerFactor)(THIS_ LPD3DVALUE pflDopplerFactor);
    STDMETHOD(GetOrientation)(THIS_ LPD3DVECTOR pvOrientFront, LPD3DVECTOR pvOrientTop);
    STDMETHOD(GetPosition)(THIS_ LPD3DVECTOR pvPosition);
    STDMETHOD(GetRolloffFactor)(THIS_ LPD3DVALUE pflRolloffFactor);
    STDMETHOD(GetVelocity)(THIS_ LPD3DVECTOR pvVelocity);
    STDMETHOD(SetAllParameters)(THIS_ LPCDS3DLISTENER pcListener, DWORD dwApply);
    STDMETHOD(SetDistanceFactor)(THIS_ D3DVALUE flDistanceFactor, DWORD dwApply);
    STDMETHOD(SetDopplerFactor)(THIS_ D3DVALUE flDopplerFactor, DWORD dwApply);
    STDMETHOD(SetOrientation)(THIS_ D3DVALUE xFront, D3DVALUE yFront, D3DVALUE zFront, D3DVALUE xTop, D3DVALUE yTop, D3DVALUE zTop, DWORD dwApply);
    STDMETHOD(SetPosition)(THIS_ D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply);
    STDMETHOD(SetRolloffFactor)(THIS_ D3DVALUE flRolloffFactor, DWORD dwApply);
    STDMETHOD(SetVelocity)(THIS_ D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply);
    STDMETHOD(CommitDeferredSettings)(THIS);

protected:
    AgentStateStruct(DirectSound3DListener);
};