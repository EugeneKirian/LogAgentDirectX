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

class DirectDraw : public IDirectDraw
{
public:
    DirectDraw(AgentConstructorParameters(DirectDraw));
    virtual ~DirectDraw();

    /*** IUnknown ***/

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj);
    STDMETHOD_(ULONG, AddRef)(THIS);
    STDMETHOD_(ULONG, Release)(THIS);

    /*** IDirectDraw ***/

    STDMETHOD(Compact)(THIS);
    STDMETHOD(CreateClipper)(THIS_ DWORD, LPDIRECTDRAWCLIPPER FAR*, IUnknown FAR*);
    STDMETHOD(CreatePalette)(THIS_ DWORD, LPPALETTEENTRY, LPDIRECTDRAWPALETTE FAR*, IUnknown FAR*);
    STDMETHOD(CreateSurface)(THIS_ LPDDSURFACEDESC, LPDIRECTDRAWSURFACE FAR*, IUnknown FAR*);
    STDMETHOD(DuplicateSurface)(THIS_ LPDIRECTDRAWSURFACE, LPDIRECTDRAWSURFACE FAR*);
    STDMETHOD(EnumDisplayModes)(THIS_ DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMMODESCALLBACK);
    STDMETHOD(EnumSurfaces)(THIS_ DWORD, LPDDSURFACEDESC, LPVOID, LPDDENUMSURFACESCALLBACK);
    STDMETHOD(FlipToGDISurface)(THIS);
    STDMETHOD(GetCaps)(THIS_ LPDDCAPS, LPDDCAPS);
    STDMETHOD(GetDisplayMode)(THIS_ LPDDSURFACEDESC);
    STDMETHOD(GetFourCCCodes)(THIS_ LPDWORD, LPDWORD);
    STDMETHOD(GetGDISurface)(THIS_ LPDIRECTDRAWSURFACE FAR*);
    STDMETHOD(GetMonitorFrequency)(THIS_ LPDWORD);
    STDMETHOD(GetScanLine)(THIS_ LPDWORD);
    STDMETHOD(GetVerticalBlankStatus)(THIS_ LPBOOL);
    STDMETHOD(Initialize)(THIS_ GUID FAR*);
    STDMETHOD(RestoreDisplayMode)(THIS);
    STDMETHOD(SetCooperativeLevel)(THIS_ HWND, DWORD);
    STDMETHOD(SetDisplayMode)(THIS_ DWORD, DWORD, DWORD);
    STDMETHOD(WaitForVerticalBlank)(THIS_ DWORD, HANDLE);

protected:
    AgentStateStruct(DirectDraw);
};