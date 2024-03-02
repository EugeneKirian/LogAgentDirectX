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

class DirectDraw4 : public IDirectDraw4
{
public:
    DirectDraw4(AgentConstructorParameters(DirectDraw4));
    virtual ~DirectDraw4();

    /*** IUnknown ***/

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj);
    STDMETHOD_(ULONG, AddRef)(THIS);
    STDMETHOD_(ULONG, Release)(THIS);

    /*** IDirectDraw ***/

    STDMETHOD(Compact)(THIS);
    STDMETHOD(CreateClipper)(THIS_ DWORD, LPDIRECTDRAWCLIPPER FAR*, IUnknown FAR*);
    STDMETHOD(CreatePalette)(THIS_ DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE FAR*, IUnknown FAR*);
    STDMETHOD(CreateSurface)(THIS_ LPDDSURFACEDESC2, LPDIRECTDRAWSURFACE4 FAR*, IUnknown FAR*);
    STDMETHOD(DuplicateSurface)(THIS_ LPDIRECTDRAWSURFACE4, LPDIRECTDRAWSURFACE4 FAR*);
    STDMETHOD(EnumDisplayModes)(THIS_ DWORD, LPDDSURFACEDESC2, LPVOID, LPDDENUMMODESCALLBACK2);
    STDMETHOD(EnumSurfaces)(THIS_ DWORD, LPDDSURFACEDESC2, LPVOID, LPDDENUMSURFACESCALLBACK2);
    STDMETHOD(FlipToGDISurface)(THIS);
    STDMETHOD(GetCaps)(THIS_ LPDDCAPS, LPDDCAPS);
    STDMETHOD(GetDisplayMode)(THIS_ LPDDSURFACEDESC2);
    STDMETHOD(GetFourCCCodes)(THIS_ LPDWORD, LPDWORD);
    STDMETHOD(GetGDISurface)(THIS_ LPDIRECTDRAWSURFACE4 FAR*);
    STDMETHOD(GetMonitorFrequency)(THIS_ LPDWORD);
    STDMETHOD(GetScanLine)(THIS_ LPDWORD);
    STDMETHOD(GetVerticalBlankStatus)(THIS_ LPBOOL);
    STDMETHOD(Initialize)(THIS_ GUID FAR*);
    STDMETHOD(RestoreDisplayMode)(THIS);
    STDMETHOD(SetCooperativeLevel)(THIS_ HWND, DWORD);
    STDMETHOD(SetDisplayMode)(THIS_ DWORD, DWORD, DWORD, DWORD, DWORD);
    STDMETHOD(WaitForVerticalBlank)(THIS_ DWORD, HANDLE);

    /*** IDirectDraw2 ***/

    STDMETHOD(GetAvailableVidMem)(THIS_ LPDDSCAPS2, LPDWORD, LPDWORD);

    /*** IDirectDraw4 ***/

    STDMETHOD(GetSurfaceFromDC)(THIS_ HDC, LPDIRECTDRAWSURFACE4*);
    STDMETHOD(RestoreAllSurfaces)(THIS);
    STDMETHOD(TestCooperativeLevel)(THIS);
    STDMETHOD(GetDeviceIdentifier)(THIS_ LPDDDEVICEIDENTIFIER, DWORD);

protected:
    AgentStateStruct(DirectDraw4);
};