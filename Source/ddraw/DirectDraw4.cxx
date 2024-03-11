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

#include "Direct3D.hxx"
#include "Direct3D2.hxx"
#include "Direct3D3.hxx"
#include "Direct3D7.hxx"
#include "DirectDraw.hxx"
#include "DirectDraw2.hxx"
#include "DirectDraw4.hxx"
#include "DirectDraw7.hxx"
#include "DirectDrawClipper.hxx"
#include "DirectDrawPalette.hxx"
#include "DirectDrawSurface4.hxx"
#include "DirectDrawVideoPortContainer.hxx"

#include <AgentLogger.hxx>
#include <DirectDraw4Logger.hxx>

#define DirectDraw4LogMethod(L, M) AgentLogMethod(L, DirectDraw4, M)
#define DirectDraw4LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectDraw4, M, C, PARAMS)

#define DirectDraw4LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectDraw4, AddRef, R)
#define DirectDraw4LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectDraw4, Release, R)

#define DirectDraw4LogMethodResult(L, M, R) AgentLogMethodResult(L, DirectDraw4, M, R)
#define DirectDraw4LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectDraw4, M, R, C, PARAMS)

#define DirectDraw4LogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, DirectDraw4, M, C, PARAMS)
#define DirectDraw4LogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, DirectDraw4, M, R, C, PARAMS)

typedef struct DirectDrawEnumModesCallbackContext
{
    DirectDraw4* Self;
    LPLOGGER Logger;
    LPDDENUMMODESCALLBACK2 EnumModesCallback;
    LPVOID Context;
} DIRECTDRAWENUMMODESCALLBACKCONTEXT, * LPDIRECTDRAWENUMMODESCALLBACKCONTEXT;

static HRESULT CALLBACK EnumModesCallback(LPDDSURFACEDESC2 lpDDSurfaceDesc, LPVOID lpContext)
{
    LPDIRECTDRAWENUMMODESCALLBACKCONTEXT context = (LPDIRECTDRAWENUMMODESCALLBACKCONTEXT)lpContext;

    DirectDraw4LogMethodCallbackValue(TRACEDEBUG, EnumDisplayModes, 2, (context->Self, lpDDSurfaceDesc));

    CONST HRESULT result = context->EnumModesCallback(lpDDSurfaceDesc, context->Context);

    DirectDraw4LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumDisplayModes, result, 2, (context->Self, lpDDSurfaceDesc));
}

typedef struct DirectDrawEnumSurfaceCallbackContext
{
    DirectDraw4* Self;
    LPLOGGER Logger;
    LPDDENUMSURFACESCALLBACK2 EnumSurfacesCallback;
    LPVOID Context;
} DIRECTDRAWENUMSURFACECALLBACKCONTEXT, * LPDIRECTDRAWENUMSURFACECALLBACKCONTEXT;

static HRESULT CALLBACK EnumSurfacesCallback(LPDIRECTDRAWSURFACE4 lpDDSurface, LPDDSURFACEDESC2 lpDDSD, LPVOID lpContext)
{
    LPDIRECTDRAWENUMSURFACECALLBACKCONTEXT context = (LPDIRECTDRAWENUMSURFACECALLBACKCONTEXT)lpContext;

    DirectDraw4LogMethodCallbackValue(TRACEDEBUG, EnumSurfaces, 3, (context->Self, lpDDSurface, lpDDSD));

    CONST HRESULT result = context->EnumSurfacesCallback(lpDDSurface, lpDDSD, context->Context);

    DirectDraw4LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumSurfaces, result, 3, (context->Self, lpDDSurface, lpDDSD));
}

DirectDraw4::DirectDraw4(AgentConstructorParameters(DirectDraw4))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectDraw4);
}

DirectDraw4::~DirectDraw4()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectDraw4);
}

HRESULT DirectDraw4::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectDraw4LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3D, riid)) { *ppvObj = ActivateAgent(Direct3D, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3D2, riid)) { *ppvObj = ActivateAgent(Direct3D2, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3D3, riid)) { *ppvObj = ActivateAgent(Direct3D3, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3D7, riid)) { *ppvObj = ActivateAgent(Direct3D7, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw, riid)) { *ppvObj = ActivateAgent(DirectDraw, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw2, riid)) { *ppvObj = ActivateAgent(DirectDraw2, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw4, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(DirectDraw4, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw7, riid)) { *ppvObj = ActivateAgent(DirectDraw7, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawVideoPortContainer, riid)) { *ppvObj = ActivateAgent(DirectDrawVideoPortContainer, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectDraw4::AddRef()
{
    DirectDraw4LogMethod(DEBUG, AddRef);
    DirectDraw4LogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectDraw4::Release()
{
    DirectDraw4LogMethod(DEBUG, Release);
    DirectDraw4LogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// This method is not currently implemented.
HRESULT DirectDraw4::Compact()
{
    DirectDraw4LogMethod(DEBUG, Compact);

    CONST HRESULT result = this->State.Self->Compact();

    DirectDraw4LogMethodResult(DEBUGINFO, Compact, result);
}

// Creates a DirectDrawClipper object.
HRESULT DirectDraw4::CreateClipper(DWORD dwFlags, LPDIRECTDRAWCLIPPER FAR* lplpDDClipper, IUnknown FAR* pUnkOuter)
{
    DirectDraw4LogMethodValue(TRACE, CreateClipper, 3, (dwFlags, lplpDDClipper, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateClipper(dwFlags, lplpDDClipper, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDDClipper = ActivateAgentDelegate(DirectDrawClipper, *lplpDDClipper); }

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, CreateClipper, result, 3, (dwFlags, lplpDDClipper, pUnkOuter));
}

// Creates a DirectDrawPalette object for this DirectDraw object.
HRESULT DirectDraw4::CreatePalette(DWORD dwFlags, LPPALETTEENTRY lpColorTable, LPDIRECTDRAWPALETTE FAR* lplpDDPalette, IUnknown FAR* pUnkOuter)
{
    DirectDraw4LogMethodValue(TRACE, CreatePalette, 4, (dwFlags, lpColorTable, lplpDDPalette, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreatePalette(dwFlags, lpColorTable, lplpDDPalette, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDDPalette = ActivateAgentDelegate(DirectDrawPalette, *lplpDDPalette); }

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, CreatePalette, result, 4, (dwFlags, lpColorTable, lplpDDPalette, pUnkOuter));
}

// Creates a DirectDrawSurface object for this DirectDraw object.
HRESULT DirectDraw4::CreateSurface(LPDDSURFACEDESC2 lpDDSurfaceDesc, LPDIRECTDRAWSURFACE4 FAR* lplpDDSurface, IUnknown FAR* pUnkOuter)
{
    DirectDraw4LogMethodValue(TRACE, CreateSurface, 3, (lpDDSurfaceDesc, lplpDDSurface, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateSurface(lpDDSurfaceDesc, lplpDDSurface, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDDSurface = ActivateAgentDelegate(DirectDrawSurface4, *lplpDDSurface); }

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, CreateSurface, result, 3, (lpDDSurfaceDesc, lplpDDSurface, pUnkOuter));
}

// Duplicates a DirectDrawSurface object.
HRESULT DirectDraw4::DuplicateSurface(LPDIRECTDRAWSURFACE4 lpDDSurface, LPDIRECTDRAWSURFACE4 FAR* lplpDupDDSurface)
{
    DirectDraw4LogMethodValue(TRACE, DuplicateSurface, 2, (lpDDSurface, lplpDupDDSurface));

    AttemptAccessAgentValue(DirectDrawSurface4, lpDDSurface);

    CONST HRESULT result = this->State.Self->DuplicateSurface(lpDDSurface, lplpDupDDSurface);

    if (SUCCEEDED(result)) { *lplpDupDDSurface = ActivateAgentDelegate(DirectDrawSurface4, *lplpDupDDSurface); }

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, DuplicateSurface, result, 2, (ActivateAgent(DirectDrawSurface4, lpDDSurface), lplpDupDDSurface));
}

// Enumerates all the display modes that the hardware exposes through the DirectDraw object
// and that are compatible with a provided surface description.
HRESULT DirectDraw4::EnumDisplayModes(DWORD dwFlags, LPDDSURFACEDESC2 lpDDSurfaceDesc, LPVOID lpContext, LPDDENUMMODESCALLBACK2 lpEnumModesCallback)
{
    DirectDraw4LogMethodValue(DEBUGINFO, EnumDisplayModes, 4, (dwFlags, lpDDSurfaceDesc, lpContext, lpEnumModesCallback));

    if (lpEnumModesCallback == NULL) { DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, EnumDisplayModes, DDERR_INVALIDPARAMS, 4, (dwFlags, lpDDSurfaceDesc, lpContext, lpEnumModesCallback)); }

    DIRECTDRAWENUMMODESCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumModesCallback = lpEnumModesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumDisplayModes(dwFlags, lpDDSurfaceDesc, &context, EnumModesCallback);

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, EnumDisplayModes, result, 4, (dwFlags, lpDDSurfaceDesc, lpContext, lpEnumModesCallback));
}

// Enumerates all the existing or possible surfaces that meet the specified surface description.
HRESULT DirectDraw4::EnumSurfaces(DWORD dwFlags, LPDDSURFACEDESC2 lpDDSD, LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpEnumSurfacesCallback)
{
    DirectDraw4LogMethodValue(DEBUGINFO, EnumSurfaces, 4, (dwFlags, lpDDSD, lpContext, lpEnumSurfacesCallback));

    if (lpEnumSurfacesCallback == NULL) { DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, EnumSurfaces, DDERR_INVALIDPARAMS, 4, (dwFlags, lpDDSD, lpContext, lpEnumSurfacesCallback)); }

    DIRECTDRAWENUMSURFACECALLBACKCONTEXT context;

    context.Self = this;
    context.EnumSurfacesCallback = lpEnumSurfacesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumSurfaces(dwFlags, lpDDSD, &context, EnumSurfacesCallback);

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, EnumSurfaces, result, 4, (dwFlags, lpDDSD, lpContext, lpEnumSurfacesCallback));
}

// Makes the surface that the GDI writes to the primary surface.
HRESULT DirectDraw4::FlipToGDISurface()
{
    DirectDraw4LogMethod(DEBUG, FlipToGDISurface);

    CONST HRESULT result = this->State.Self->FlipToGDISurface();

    DirectDraw4LogMethodResult(DEBUGINFO, FlipToGDISurface, result);
}

// Retrieves the capabilities of the device driver for the hardware and the hardware emulation layer (HEL).
HRESULT DirectDraw4::GetCaps(LPDDCAPS lpDDDriverCaps, LPDDCAPS lpDDHELCaps)
{
    DirectDraw4LogMethodValue(TRACE, GetCaps, 2, (lpDDDriverCaps, lpDDHELCaps));

    CONST HRESULT result = this->State.Self->GetCaps(lpDDDriverCaps, lpDDHELCaps);

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, GetCaps, result, 2, (lpDDDriverCaps, lpDDHELCaps));
}

// Retrieves the current display mode.
HRESULT DirectDraw4::GetDisplayMode(LPDDSURFACEDESC2 lpDDSurfaceDesc)
{
    DirectDraw4LogMethodValue(TRACE, GetDisplayMode, 1, (lpDDSurfaceDesc));

    CONST HRESULT result = this->State.Self->GetDisplayMode(lpDDSurfaceDesc);

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, GetDisplayMode, result, 1, (lpDDSurfaceDesc));
}

// Retrieves the four-character codes (FOURCC) that are supported by the DirectDraw object.
// This method can also retrieve the number of codes that are supported.
HRESULT DirectDraw4::GetFourCCCodes(LPDWORD lpdwNumCodes, LPDWORD lpdwCodes)
{
    DirectDraw4LogMethodValue(TRACE, GetFourCCCodes, 2, (lpdwNumCodes, lpdwCodes));

    CONST HRESULT result = this->State.Self->GetFourCCCodes(lpdwNumCodes, lpdwCodes);

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, GetFourCCCodes, result, 2, (lpdwNumCodes, lpdwCodes));
}

// Retrieves the DirectDrawSurface object that currently represents the surface memory that GDI is treating as the primary surface.
HRESULT DirectDraw4::GetGDISurface(LPDIRECTDRAWSURFACE4 FAR* lplpGDIDDSSurface)
{
    DirectDraw4LogMethodValue(TRACE, GetGDISurface, 1, (lplpGDIDDSSurface));

    CONST HRESULT result = this->State.Self->GetGDISurface(lplpGDIDDSSurface);

    if (SUCCEEDED(result)) { *lplpGDIDDSSurface = ActivateAgentDelegate(DirectDrawSurface4, *lplpGDIDDSSurface); }

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, GetGDISurface, result, 1, (lplpGDIDDSSurface));
}

// Retrieves the frequency of the monitor that the DirectDraw object controls.
HRESULT DirectDraw4::GetMonitorFrequency(LPDWORD lpdwFrequency)
{
    DirectDraw4LogMethodValue(TRACE, GetMonitorFrequency, 1, (lpdwFrequency));

    CONST HRESULT result = this->State.Self->GetMonitorFrequency(lpdwFrequency);

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, GetMonitorFrequency, result, 1, (lpdwFrequency));
}

// Retrieves the scan line that is currently being drawn on the monitor.
HRESULT DirectDraw4::GetScanLine(LPDWORD lpdwScanLine)
{
    DirectDraw4LogMethodValue(TRACE, GetScanLine, 1, (lpdwScanLine));

    CONST HRESULT result = this->State.Self->GetScanLine(lpdwScanLine);

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, GetScanLine, result, 1, (lpdwScanLine));
}

// Retrieves the status of the vertical blank.
HRESULT DirectDraw4::GetVerticalBlankStatus(LPBOOL lpbIsInVB)
{
    DirectDraw4LogMethodValue(TRACE, GetVerticalBlankStatus, 1, (lpbIsInVB));

    CONST HRESULT result = this->State.Self->GetVerticalBlankStatus(lpbIsInVB);

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, GetVerticalBlankStatus, result, 1, (lpbIsInVB));
}

// Initializes a DirectDraw object that was created by using the CoCreateInstance COM function.
HRESULT DirectDraw4::Initialize(GUID FAR* lpGUID)
{
    DirectDraw4LogMethodValue(TRACE, Initialize, 1, (lpGUID));

    CONST HRESULT result = this->State.Self->Initialize(lpGUID);

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 1, (lpGUID));
}

// Resets the mode of the display device hardware for the primary surface to what it was before
// the IDirectDraw::SetDisplayMode method was called. Exclusive-level access is required to use this method.
HRESULT DirectDraw4::RestoreDisplayMode()
{
    DirectDraw4LogMethod(DEBUG, RestoreDisplayMode);

    CONST HRESULT result = this->State.Self->RestoreDisplayMode();

    DirectDraw4LogMethodResult(DEBUGINFO, RestoreDisplayMode, result);
}

// Determines the top-level behavior of the application.
HRESULT DirectDraw4::SetCooperativeLevel(HWND hWnd, DWORD dwFlags)
{
    DirectDraw4LogMethodValue(TRACE, SetCooperativeLevel, 2, (hWnd, dwFlags));

    CONST HRESULT result = this->State.Self->SetCooperativeLevel(hWnd, dwFlags);

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, SetCooperativeLevel, result, 2, (hWnd, dwFlags));
}

// Sets the mode of the display-device hardware.
HRESULT DirectDraw4::SetDisplayMode(DWORD dwWidth, DWORD dwHeight, DWORD dwBPP, DWORD dwRefreshRate, DWORD dwFlags)
{
    DirectDraw4LogMethodValue(TRACE, SetDisplayMode, 5, (dwWidth, dwHeight, dwBPP, dwRefreshRate, dwFlags));

    CONST HRESULT result = this->State.Self->SetDisplayMode(dwWidth, dwHeight, dwBPP, dwRefreshRate, dwFlags);

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, SetDisplayMode, result, 5, (dwWidth, dwHeight, dwBPP, dwRefreshRate, dwFlags));
}

// Helps the application synchronize itself with the vertical-blank interval.
HRESULT DirectDraw4::WaitForVerticalBlank(DWORD dwFlags, HANDLE hEvent)
{
    DirectDraw4LogMethodValue(TRACE, WaitForVerticalBlank, 2, (dwFlags, hEvent));

    CONST HRESULT result = this->State.Self->WaitForVerticalBlank(dwFlags, hEvent);

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, WaitForVerticalBlank, result, 2, (dwFlags, hEvent));
}

// Retrieves the total amount of display memory available and the amount of display memory currently free for a given type of surface.
HRESULT DirectDraw4::GetAvailableVidMem(LPDDSCAPS2 lpDDSCaps, LPDWORD lpdwTotal, LPDWORD lpdwFree)
{
    DirectDraw4LogMethodValue(TRACE, GetAvailableVidMem, 3, (lpDDSCaps, lpdwTotal, lpdwFree));

    CONST HRESULT result = this->State.Self->GetAvailableVidMem(lpDDSCaps, lpdwTotal, lpdwFree);

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, GetAvailableVidMem, result, 3, (lpDDSCaps, lpdwTotal, lpdwFree));
}

// Retrieves the IDirectDrawSurface4 interface for a surface, based on its GDI device context handle.
HRESULT DirectDraw4::GetSurfaceFromDC(HDC hDC, LPDIRECTDRAWSURFACE4* lpDDS)
{
    DirectDraw4LogMethodValue(TRACE, GetSurfaceFromDC, 2, (hDC, lpDDS));

    CONST HRESULT result = this->State.Self->GetSurfaceFromDC(hDC, lpDDS);

    if (SUCCEEDED(result)) { *lpDDS = ActivateAgentDelegate(DirectDrawSurface4, *lpDDS); }

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, GetSurfaceFromDC, result, 2, (hDC, lpDDS));
}

// Restores all the surfaces that were created for the DirectDraw object, in the order that they were created.
HRESULT DirectDraw4::RestoreAllSurfaces()
{
    DirectDraw4LogMethod(DEBUG, RestoreAllSurfaces);

    CONST HRESULT result = this->State.Self->RestoreAllSurfaces();

    DirectDraw4LogMethodResult(DEBUGINFO, RestoreAllSurfaces, result);
}

// Reports the current cooperative-level status of the DirectDraw device for a windowed or full-screen application.
HRESULT DirectDraw4::TestCooperativeLevel()
{
    DirectDraw4LogMethod(DEBUG, TestCooperativeLevel);

    CONST HRESULT result = this->State.Self->TestCooperativeLevel();

    DirectDraw4LogMethodResult(DEBUGINFO, TestCooperativeLevel, result);
}

// Obtains information about the device driver. This method can be used, with caution,
// to recognize specific hardware installations to implement workarounds for poor driver or chipset behavior.
HRESULT DirectDraw4::GetDeviceIdentifier(LPDDDEVICEIDENTIFIER lpDDDI, DWORD dwFlags)
{
    DirectDraw4LogMethodValue(TRACE, GetDeviceIdentifier, 2, (lpDDDI, dwFlags));

    CONST HRESULT result = this->State.Self->GetDeviceIdentifier(lpDDDI, dwFlags);

    DirectDraw4LogMethodResultValue(TRACEDEBUGINFO, GetDeviceIdentifier, result, 2, (lpDDDI, dwFlags));
}