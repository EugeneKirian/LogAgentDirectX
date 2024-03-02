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

class DirectDrawSurface7 : public IDirectDrawSurface7
{
public:
    DirectDrawSurface7(AgentConstructorParameters(DirectDrawSurface7));
    virtual ~DirectDrawSurface7();

    /*** IUnknown ***/

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj);
    STDMETHOD_(ULONG, AddRef)(THIS);
    STDMETHOD_(ULONG, Release)(THIS);

    /*** IDirectDrawSurface ***/

    STDMETHOD(AddAttachedSurface)(THIS_ LPDIRECTDRAWSURFACE7);
    STDMETHOD(AddOverlayDirtyRect)(THIS_ LPRECT);
    STDMETHOD(Blt)(THIS_ LPRECT, LPDIRECTDRAWSURFACE7, LPRECT, DWORD, LPDDBLTFX);
    STDMETHOD(BltBatch)(THIS_ LPDDBLTBATCH, DWORD, DWORD);
    STDMETHOD(BltFast)(THIS_ DWORD, DWORD, LPDIRECTDRAWSURFACE7, LPRECT, DWORD);
    STDMETHOD(DeleteAttachedSurface)(THIS_ DWORD, LPDIRECTDRAWSURFACE7);
    STDMETHOD(EnumAttachedSurfaces)(THIS_ LPVOID, LPDDENUMSURFACESCALLBACK7);
    STDMETHOD(EnumOverlayZOrders)(THIS_ DWORD, LPVOID, LPDDENUMSURFACESCALLBACK7);
    STDMETHOD(Flip)(THIS_ LPDIRECTDRAWSURFACE7, DWORD);
    STDMETHOD(GetAttachedSurface)(THIS_ LPDDSCAPS2, LPDIRECTDRAWSURFACE7 FAR*);
    STDMETHOD(GetBltStatus)(THIS_ DWORD);
    STDMETHOD(GetCaps)(THIS_ LPDDSCAPS2);
    STDMETHOD(GetClipper)(THIS_ LPDIRECTDRAWCLIPPER FAR*);
    STDMETHOD(GetColorKey)(THIS_ DWORD, LPDDCOLORKEY);
    STDMETHOD(GetDC)(THIS_ HDC FAR*);
    STDMETHOD(GetFlipStatus)(THIS_ DWORD);
    STDMETHOD(GetOverlayPosition)(THIS_ LPLONG, LPLONG);
    STDMETHOD(GetPalette)(THIS_ LPDIRECTDRAWPALETTE FAR*);
    STDMETHOD(GetPixelFormat)(THIS_ LPDDPIXELFORMAT);
    STDMETHOD(GetSurfaceDesc)(THIS_ LPDDSURFACEDESC2);
    STDMETHOD(Initialize)(THIS_ LPDIRECTDRAW, LPDDSURFACEDESC2);
    STDMETHOD(IsLost)(THIS);
    STDMETHOD(Lock)(THIS_ LPRECT, LPDDSURFACEDESC2, DWORD, HANDLE);
    STDMETHOD(ReleaseDC)(THIS_ HDC);
    STDMETHOD(Restore)(THIS);
    STDMETHOD(SetClipper)(THIS_ LPDIRECTDRAWCLIPPER);
    STDMETHOD(SetColorKey)(THIS_ DWORD, LPDDCOLORKEY);
    STDMETHOD(SetOverlayPosition)(THIS_ LONG, LONG);
    STDMETHOD(SetPalette)(THIS_ LPDIRECTDRAWPALETTE);
    STDMETHOD(Unlock)(THIS_ LPRECT);
    STDMETHOD(UpdateOverlay)(THIS_ LPRECT, LPDIRECTDRAWSURFACE7, LPRECT, DWORD, LPDDOVERLAYFX);
    STDMETHOD(UpdateOverlayDisplay)(THIS_ DWORD);
    STDMETHOD(UpdateOverlayZOrder)(THIS_ DWORD, LPDIRECTDRAWSURFACE7);

    /*** IDirectDrawSurface2 ***/

    STDMETHOD(GetDDInterface)(THIS_ LPVOID FAR*);
    STDMETHOD(PageLock)(THIS_ DWORD);
    STDMETHOD(PageUnlock)(THIS_ DWORD);

    /*** IDirectDrawSurface3 ***/

    STDMETHOD(SetSurfaceDesc)(THIS_ LPDDSURFACEDESC2, DWORD);

    /*** IDirectDrawSurface4 ***/

    STDMETHOD(SetPrivateData)(THIS_ REFGUID, LPVOID, DWORD, DWORD);
    STDMETHOD(GetPrivateData)(THIS_ REFGUID, LPVOID, LPDWORD);
    STDMETHOD(FreePrivateData)(THIS_ REFGUID);
    STDMETHOD(GetUniquenessValue)(THIS_ LPDWORD);
    STDMETHOD(ChangeUniquenessValue)(THIS);

    /*** IDirectDrawSurface7 ***/

    STDMETHOD(SetPriority)(THIS_ DWORD);
    STDMETHOD(GetPriority)(THIS_ LPDWORD);
    STDMETHOD(SetLOD)(THIS_ DWORD);
    STDMETHOD(GetLOD)(THIS_ LPDWORD);

protected:
    AgentStateStruct(DirectDrawSurface7);
};