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
#include "DirectDrawSurface.hxx"
#include "DirectDrawVideoPortContainer.hxx"

#include <AgentLogger.hxx>
#include <DirectDraw2Logger.hxx>

#define DirectDraw2LogMethod(L, M) AgentLogMethod(L, DirectDraw2, M)
#define DirectDraw2LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectDraw2, M, C, PARAMS)

#define DirectDraw2LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectDraw2, AddRef, R)
#define DirectDraw2LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectDraw2, Release, R)

#define DirectDraw2LogMethodResult(L, M, R) AgentLogMethodResult(L, DirectDraw2, M, R)
#define DirectDraw2LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectDraw2, M, R, C, PARAMS)

#define DirectDraw2LogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, DirectDraw2, M, C, PARAMS)
#define DirectDraw2LogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, DirectDraw2, M, R, C, PARAMS)

typedef struct DirectDrawEnumModesCallbackContext
{
    DirectDraw2* Self;
    LPLOGGER Logger;
    LPDDENUMMODESCALLBACK EnumModesCallback;
    LPVOID Context;
} DIRECTDRAWENUMMODESCALLBACKCONTEXT, * LPDIRECTDRAWENUMMODESCALLBACKCONTEXT;

static HRESULT CALLBACK EnumModesCallback(LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpContext)
{
    LPDIRECTDRAWENUMMODESCALLBACKCONTEXT context = (LPDIRECTDRAWENUMMODESCALLBACKCONTEXT)lpContext;

    DirectDraw2LogMethodCallbackValue(TRACEDEBUG, EnumDisplayModes, 2, (context->Self, lpDDSurfaceDesc));

    CONST HRESULT result = context->EnumModesCallback(lpDDSurfaceDesc, context->Context);

    DirectDraw2LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumDisplayModes, result, 2, (context->Self, lpDDSurfaceDesc));
}

typedef struct DirectDrawEnumSurfaceCallbackContext
{
    DirectDraw2* Self;
    LPLOGGER Logger;
    LPDDENUMSURFACESCALLBACK EnumSurfacesCallback;
    LPVOID Context;
} DIRECTDRAWENUMSURFACECALLBACKCONTEXT, * LPDIRECTDRAWENUMSURFACECALLBACKCONTEXT;

static HRESULT CALLBACK EnumSurfacesCallback(LPDIRECTDRAWSURFACE lpDDSurface, LPDDSURFACEDESC lpDDSD, LPVOID lpContext)
{
    LPDIRECTDRAWENUMSURFACECALLBACKCONTEXT context = (LPDIRECTDRAWENUMSURFACECALLBACKCONTEXT)lpContext;

    DirectDraw2LogMethodCallbackValue(TRACEDEBUG, EnumSurfaces, 3, (context->Self, lpDDSurface, lpDDSD));

    CONST HRESULT result = context->EnumSurfacesCallback(lpDDSurface, lpDDSD, context->Context);

    DirectDraw2LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumSurfaces, result, 3, (context->Self, lpDDSurface, lpDDSD));
}

DirectDraw2::DirectDraw2(AgentConstructorParameters(DirectDraw2))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectDraw2);
}

DirectDraw2::~DirectDraw2()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectDraw2);
}

HRESULT DirectDraw2::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectDraw2LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3D, riid)) { *ppvObj = ActivateAgent(Direct3D, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3D2, riid)) { *ppvObj = ActivateAgent(Direct3D2, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3D3, riid)) { *ppvObj = ActivateAgent(Direct3D3, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3D7, riid)) { *ppvObj = ActivateAgent(Direct3D7, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(DirectDraw, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw2, riid)) { *ppvObj = ActivateAgent(DirectDraw2, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw4, riid)) { *ppvObj = ActivateAgent(DirectDraw4, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw7, riid)) { *ppvObj = ActivateAgent(DirectDraw7, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawVideoPortContainer, riid)) { *ppvObj = ActivateAgent(DirectDrawVideoPortContainer, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectDraw2::AddRef()
{
    DirectDraw2LogMethod(TRACE, AddRef);
    DirectDraw2LogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG DirectDraw2::Release()
{
    DirectDraw2LogMethod(TRACE, Release);
    DirectDraw2LogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// This method is not currently implemented.
HRESULT DirectDraw2::Compact()
{
    DirectDraw2LogMethod(TRACE, Compact);

    CONST HRESULT result = this->State.Self->Compact();

    DirectDraw2LogMethodResult(TRACEDEBUGINFO, Compact, result);
}

// Creates a DirectDrawClipper object.
HRESULT DirectDraw2::CreateClipper(DWORD dwFlags, LPDIRECTDRAWCLIPPER FAR* lplpDDClipper, IUnknown FAR* pUnkOuter)
{
    DirectDraw2LogMethodValue(TRACE, CreateClipper, 3, (dwFlags, lplpDDClipper, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateClipper(dwFlags, lplpDDClipper, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDDClipper = ActivateAgentDelegate(DirectDrawClipper, *lplpDDClipper); }

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, CreateClipper, result, 3, (dwFlags, lplpDDClipper, pUnkOuter));
}

// Creates a DirectDrawPalette object for this DirectDraw object.
HRESULT DirectDraw2::CreatePalette(DWORD dwFlags, LPPALETTEENTRY lpColorTable, LPDIRECTDRAWPALETTE FAR* lplpDDPalette, IUnknown FAR* pUnkOuter)
{
    DirectDraw2LogMethodValue(TRACE, CreatePalette, 4, (dwFlags, lpColorTable, lplpDDPalette, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreatePalette(dwFlags, lpColorTable, lplpDDPalette, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDDPalette = ActivateAgentDelegate(DirectDrawPalette, *lplpDDPalette); }

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, CreatePalette, result, 4, (dwFlags, lpColorTable, lplpDDPalette, pUnkOuter));
}

// Creates a DirectDrawSurface object for this DirectDraw object.
HRESULT DirectDraw2::CreateSurface(LPDDSURFACEDESC lpDDSurfaceDesc, LPDIRECTDRAWSURFACE FAR* lplpDDSurface, IUnknown FAR* pUnkOuter)
{
    DirectDraw2LogMethodValue(TRACE, CreateSurface, 3, (lpDDSurfaceDesc, lplpDDSurface, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateSurface(lpDDSurfaceDesc, lplpDDSurface, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDDSurface = ActivateAgentDelegate(DirectDrawSurface, *lplpDDSurface); }

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, CreateSurface, result, 3, (lpDDSurfaceDesc, lplpDDSurface, pUnkOuter));
}

// Duplicates a DirectDrawSurface object.
HRESULT DirectDraw2::DuplicateSurface(LPDIRECTDRAWSURFACE lpDDSurface, LPDIRECTDRAWSURFACE FAR* lplpDupDDSurface)
{
    DirectDraw2LogMethodValue(TRACE, DuplicateSurface, 2, (lpDDSurface, lplpDupDDSurface));

    AttemptAccessAgentValue(DirectDrawSurface, lpDDSurface);

    CONST HRESULT result = this->State.Self->DuplicateSurface(lpDDSurface, lplpDupDDSurface);

    if (SUCCEEDED(result)) { *lplpDupDDSurface = ActivateAgentDelegate(DirectDrawSurface, *lplpDupDDSurface); }

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, DuplicateSurface, result, 2, (ActivateAgent(DirectDrawSurface, lpDDSurface), lplpDupDDSurface));
}

// Enumerates all the display modes that the hardware exposes through the DirectDraw object
// and that are compatible with a provided surface description.
HRESULT DirectDraw2::EnumDisplayModes(DWORD dwFlags, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpContext, LPDDENUMMODESCALLBACK lpEnumModesCallback)
{
    DirectDraw2LogMethodValue(TRACEDEBUG, EnumDisplayModes, 4, (dwFlags, lpDDSurfaceDesc, lpContext, lpEnumModesCallback));

    if (lpEnumModesCallback == NULL) { DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, EnumDisplayModes, DDERR_INVALIDPARAMS, 4, (dwFlags, lpDDSurfaceDesc, lpContext, lpEnumModesCallback)); }

    DIRECTDRAWENUMMODESCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumModesCallback = lpEnumModesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumDisplayModes(dwFlags, lpDDSurfaceDesc, &context, EnumModesCallback);

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, EnumDisplayModes, result, 4, (dwFlags, lpDDSurfaceDesc, lpContext, lpEnumModesCallback));
}

// Enumerates all the existing or possible surfaces that meet the specified surface description.
HRESULT DirectDraw2::EnumSurfaces(DWORD dwFlags, LPDDSURFACEDESC lpDDSD, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback)
{
    DirectDraw2LogMethodValue(TRACEDEBUG, EnumSurfaces, 4, (dwFlags, lpDDSD, lpContext, lpEnumSurfacesCallback));

    if (lpEnumSurfacesCallback == NULL) { DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, EnumSurfaces, DDERR_INVALIDPARAMS, 4, (dwFlags, lpDDSD, lpContext, lpEnumSurfacesCallback)); }

    DIRECTDRAWENUMSURFACECALLBACKCONTEXT context;

    context.Self = this;
    context.EnumSurfacesCallback = lpEnumSurfacesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumSurfaces(dwFlags, lpDDSD, &context, EnumSurfacesCallback);

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, EnumSurfaces, result, 4, (dwFlags, lpDDSD, lpContext, lpEnumSurfacesCallback));
}

// Makes the surface that the GDI writes to the primary surface.
HRESULT DirectDraw2::FlipToGDISurface()
{
    DirectDraw2LogMethod(TRACE, FlipToGDISurface);

    CONST HRESULT result = this->State.Self->FlipToGDISurface();

    DirectDraw2LogMethodResult(TRACEDEBUGINFO, FlipToGDISurface, result);
}

// Retrieves the capabilities of the device driver for the hardware and the hardware emulation layer (HEL).
HRESULT DirectDraw2::GetCaps(LPDDCAPS lpDDDriverCaps, LPDDCAPS lpDDHELCaps)
{
    DirectDraw2LogMethodValue(TRACE, GetCaps, 2, (lpDDDriverCaps, lpDDHELCaps));

    CONST HRESULT result = this->State.Self->GetCaps(lpDDDriverCaps, lpDDHELCaps);

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, GetCaps, result, 2, (lpDDDriverCaps, lpDDHELCaps));
}

// Retrieves the current display mode.
HRESULT DirectDraw2::GetDisplayMode(LPDDSURFACEDESC lpDDSurfaceDesc)
{
    DirectDraw2LogMethodValue(TRACE, GetDisplayMode, 1, (lpDDSurfaceDesc));

    CONST HRESULT result = this->State.Self->GetDisplayMode(lpDDSurfaceDesc);

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, GetDisplayMode, result, 1, (lpDDSurfaceDesc));
}

// Retrieves the four-character codes (FOURCC) that are supported by the DirectDraw object.
// This method can also retrieve the number of codes that are supported.
HRESULT DirectDraw2::GetFourCCCodes(LPDWORD lpdwNumCodes, LPDWORD lpdwCodes)
{
    DirectDraw2LogMethodValue(TRACE, GetFourCCCodes, 2, (lpdwNumCodes, lpdwCodes));

    CONST HRESULT result = this->State.Self->GetFourCCCodes(lpdwNumCodes, lpdwCodes);

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, GetFourCCCodes, result, 2, (lpdwNumCodes, lpdwCodes));
}

// Retrieves the DirectDrawSurface object that currently represents the surface memory that GDI is treating as the primary surface.
HRESULT DirectDraw2::GetGDISurface(LPDIRECTDRAWSURFACE FAR* lplpGDIDDSSurface)
{
    DirectDraw2LogMethodValue(TRACE, GetGDISurface, 1, (lplpGDIDDSSurface));

    CONST HRESULT result = this->State.Self->GetGDISurface(lplpGDIDDSSurface);

    if (SUCCEEDED(result)) { *lplpGDIDDSSurface = ActivateAgent(DirectDrawSurface, *lplpGDIDDSSurface); }

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, GetGDISurface, result, 1, (lplpGDIDDSSurface));
}

// Retrieves the frequency of the monitor that the DirectDraw object controls.
HRESULT DirectDraw2::GetMonitorFrequency(LPDWORD lpdwFrequency)
{
    DirectDraw2LogMethodValue(TRACE, GetMonitorFrequency, 1, (lpdwFrequency));

    CONST HRESULT result = this->State.Self->GetMonitorFrequency(lpdwFrequency);

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, GetMonitorFrequency, result, 1, (lpdwFrequency));
}

// Retrieves the scan line that is currently being drawn on the monitor.
HRESULT DirectDraw2::GetScanLine(LPDWORD lpdwScanLine)
{
    DirectDraw2LogMethodValue(TRACE, GetScanLine, 1, (lpdwScanLine));

    CONST HRESULT result = this->State.Self->GetScanLine(lpdwScanLine);

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, GetScanLine, result, 1, (lpdwScanLine));
}

// Retrieves the status of the vertical blank.
HRESULT DirectDraw2::GetVerticalBlankStatus(LPBOOL lpbIsInVB)
{
    DirectDraw2LogMethodValue(TRACE, GetVerticalBlankStatus, 1, (lpbIsInVB));

    CONST HRESULT result = this->State.Self->GetVerticalBlankStatus(lpbIsInVB);

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, GetVerticalBlankStatus, result, 1, (lpbIsInVB));
}

// Initializes a DirectDraw object that was created by using the CoCreateInstance COM function.
HRESULT DirectDraw2::Initialize(GUID FAR* lpGUID)
{
    DirectDraw2LogMethodValue(TRACE, Initialize, 1, (lpGUID));

    CONST HRESULT result = this->State.Self->Initialize(lpGUID);

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 1, (lpGUID));
}

// Resets the mode of the display device hardware for the primary surface to what it was before
// the IDirectDraw::SetDisplayMode method was called. Exclusive-level access is required to use this method.
HRESULT DirectDraw2::RestoreDisplayMode()
{
    DirectDraw2LogMethod(TRACE, RestoreDisplayMode);

    CONST HRESULT result = this->State.Self->RestoreDisplayMode();

    DirectDraw2LogMethodResult(TRACEDEBUGINFO, RestoreDisplayMode, result);
}

// Determines the top-level behavior of the application.
HRESULT DirectDraw2::SetCooperativeLevel(HWND hWnd, DWORD dwFlags)
{
    DirectDraw2LogMethodValue(TRACE, SetCooperativeLevel, 2, (hWnd, dwFlags));

    CONST HRESULT result = this->State.Self->SetCooperativeLevel(hWnd, dwFlags);

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, SetCooperativeLevel, result, 2, (hWnd, dwFlags));
}

// Sets the mode of the display-device hardware.
HRESULT DirectDraw2::SetDisplayMode(DWORD dwWidth, DWORD dwHeight, DWORD dwBPP, DWORD dwRefreshRate, DWORD dwFlags)
{
    DirectDraw2LogMethodValue(TRACE, SetDisplayMode, 5, (dwWidth, dwHeight, dwBPP, dwRefreshRate, dwFlags));

    CONST HRESULT result = this->State.Self->SetDisplayMode(dwWidth, dwHeight, dwBPP, dwRefreshRate, dwFlags);

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, SetDisplayMode, result, 5, (dwWidth, dwHeight, dwBPP, dwRefreshRate, dwFlags));
}

// Helps the application synchronize itself with the vertical-blank interval.
HRESULT DirectDraw2::WaitForVerticalBlank(DWORD dwFlags, HANDLE hEvent)
{
    DirectDraw2LogMethodValue(TRACE, WaitForVerticalBlank, 2, (dwFlags, hEvent));

    CONST HRESULT result = this->State.Self->WaitForVerticalBlank(dwFlags, hEvent);

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, WaitForVerticalBlank, result, 2, (dwFlags, hEvent));
}

// Retrieves the total amount of display memory available and the amount of display memory currently free for a given type of surface.
HRESULT DirectDraw2::GetAvailableVidMem(LPDDSCAPS lpDDSCaps, LPDWORD lpdwTotal, LPDWORD lpdwFree)
{
    DirectDraw2LogMethodValue(TRACE, GetAvailableVidMem, 3, (lpDDSCaps, lpdwTotal, lpdwFree));

    CONST HRESULT result = this->State.Self->GetAvailableVidMem(lpDDSCaps, lpdwTotal, lpdwFree);

    DirectDraw2LogMethodResultValue(TRACEDEBUGINFO, GetAvailableVidMem, result, 3, (lpDDSCaps, lpdwTotal, lpdwFree));
}