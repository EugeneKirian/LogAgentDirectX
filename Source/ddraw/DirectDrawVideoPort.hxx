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

class DirectDrawVideoPort : public IDirectDrawVideoPort
{
public:
    DirectDrawVideoPort(AgentConstructorParameters(DirectDrawVideoPort));
    virtual ~DirectDrawVideoPort();

    /*** IUnknown ***/

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj);
    STDMETHOD_(ULONG, AddRef)(THIS);
    STDMETHOD_(ULONG, Release)(THIS);

    /*** IDirectDrawVideoPort ***/

    STDMETHOD(Flip)(THIS_ LPDIRECTDRAWSURFACE, DWORD);
    STDMETHOD(GetBandwidthInfo)(THIS_ LPDDPIXELFORMAT, DWORD, DWORD, DWORD, LPDDVIDEOPORTBANDWIDTH);
    STDMETHOD(GetColorControls)(THIS_ LPDDCOLORCONTROL);
    STDMETHOD(GetInputFormats)(THIS_ LPDWORD, LPDDPIXELFORMAT, DWORD);
    STDMETHOD(GetOutputFormats)(THIS_ LPDDPIXELFORMAT, LPDWORD, LPDDPIXELFORMAT, DWORD);
    STDMETHOD(GetFieldPolarity)(THIS_ LPBOOL);
    STDMETHOD(GetVideoLine)(THIS_ LPDWORD);
    STDMETHOD(GetVideoSignalStatus)(THIS_ LPDWORD);
    STDMETHOD(SetColorControls)(THIS_ LPDDCOLORCONTROL);
    STDMETHOD(SetTargetSurface)(THIS_ LPDIRECTDRAWSURFACE, DWORD);
    STDMETHOD(StartVideo)(THIS_ LPDDVIDEOPORTINFO);
    STDMETHOD(StopVideo)(THIS);
    STDMETHOD(UpdateVideo)(THIS_ LPDDVIDEOPORTINFO);
    STDMETHOD(WaitForSync)(THIS_ DWORD, DWORD, DWORD);

protected:
    AgentStateStruct(DirectDrawVideoPort);
};