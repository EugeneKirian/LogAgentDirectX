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
#include <DirectDrawLogger.hxx>

#define DirectDrawLogMethod(L, M) AgentLogMethod(L, DirectDraw, M)
#define DirectDrawLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectDraw, M, C, PARAMS)

#define DirectDrawLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectDraw, AddRef, R)
#define DirectDrawLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectDraw, Release, R)

#define DirectDrawLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectDraw, M, R)
#define DirectDrawLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectDraw, M, R, C, PARAMS)

#define DirectDrawLogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, DirectDraw, M, C, PARAMS)
#define DirectDrawLogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, DirectDraw, M, R, C, PARAMS)

typedef struct DirectDrawEnumDisplayModesCallbackContext
{
    DirectDraw* Self;
    LPLOGGER Logger;
    LPDDENUMMODESCALLBACK EnumDisplayModesCallback;
    LPVOID Context;
} DIRECTDRAWENUMDISPLAYMODESCALLBACKCONTEXT, * LPDIRECTDRAWENUMDISPLAYMODESCALLBACKCONTEXT;

static HRESULT CALLBACK EnumDisplayModesCallback(LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpContext)
{
    LPDIRECTDRAWENUMDISPLAYMODESCALLBACKCONTEXT context = (LPDIRECTDRAWENUMDISPLAYMODESCALLBACKCONTEXT)lpContext;

    DirectDrawLogMethodCallbackValue(TRACEDEBUG, EnumDisplayModes, 2, (context->Self, lpDDSurfaceDesc));

    CONST HRESULT result = context->EnumDisplayModesCallback(lpDDSurfaceDesc, context->Context);

    DirectDrawLogMethodCallbackResultValue(TRACEDEBUGINFO, EnumDisplayModes, result, 2, (context->Self, lpDDSurfaceDesc));
}

typedef struct DirectDrawEnumSurfaceCallbackContext
{
    DirectDraw* Self;
    LPLOGGER Logger;
    LPDDENUMSURFACESCALLBACK EnumSurfacesCallback;
    LPVOID Context;
} DIRECTDRAWENUMSURFACECALLBACKCONTEXT, * LPDIRECTDRAWENUMSURFACECALLBACKCONTEXT;

static HRESULT CALLBACK EnumSurfacesCallback(LPDIRECTDRAWSURFACE lpDDSurface, LPDDSURFACEDESC lpDDSD, LPVOID lpContext)
{
    LPDIRECTDRAWENUMSURFACECALLBACKCONTEXT context = (LPDIRECTDRAWENUMSURFACECALLBACKCONTEXT)lpContext;

    DirectDrawLogMethodCallbackValue(TRACEDEBUG, EnumSurfaces, 3, (context->Self, lpDDSurface, lpDDSD));

    CONST HRESULT result = context->EnumSurfacesCallback(lpDDSurface, lpDDSD, context->Context);

    DirectDrawLogMethodCallbackResultValue(TRACEDEBUGINFO, EnumSurfaces, result, 3, (context->Self, lpDDSurface, lpDDSD));
}

DirectDraw::DirectDraw(AgentConstructorParameters(DirectDraw))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectDraw);
}

DirectDraw::~DirectDraw()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectDraw);
}

HRESULT DirectDraw::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectDrawLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj) );

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

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectDraw::AddRef()
{
    DirectDrawLogMethod(TRACE, AddRef);
    DirectDrawLogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG DirectDraw::Release()
{
    DirectDrawLogMethod(TRACE, Release);
    DirectDrawLogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// This method is not currently implemented.
HRESULT DirectDraw::Compact()
{
    DirectDrawLogMethod(TRACE, Compact);
    
    CONST HRESULT result = this->State.Self->Compact();

    DirectDrawLogMethodResult(TRACEDEBUGINFO, Compact, result);
}

// Creates a DirectDrawClipper object.
HRESULT DirectDraw::CreateClipper(DWORD dwFlags, LPDIRECTDRAWCLIPPER FAR* lplpDDClipper, IUnknown FAR* pUnkOuter)
{
    DirectDrawLogMethodValue(TRACE, CreateClipper, 3, (dwFlags, lplpDDClipper, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateClipper(dwFlags, lplpDDClipper, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDDClipper = ActivateAgentDelegate(DirectDrawClipper, *lplpDDClipper); }

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, CreateClipper, result, 3, (dwFlags, lplpDDClipper, pUnkOuter));
}

// Creates a DirectDrawPalette object for this DirectDraw object.
HRESULT DirectDraw::CreatePalette(DWORD dwFlags, LPPALETTEENTRY lpColorTable, LPDIRECTDRAWPALETTE FAR* lplpDDPalette, IUnknown FAR* pUnkOuter)
{
    DirectDrawLogMethodValue(TRACE, CreatePalette, 4, (dwFlags, lpColorTable, lplpDDPalette, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreatePalette(dwFlags, lpColorTable, lplpDDPalette, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDDPalette = ActivateAgentDelegate(DirectDrawPalette, *lplpDDPalette); }

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, CreatePalette, result, 4, (dwFlags, lpColorTable, lplpDDPalette, pUnkOuter));
}

// Creates a DirectDrawSurface object for this DirectDraw object.
HRESULT DirectDraw::CreateSurface(LPDDSURFACEDESC lpDDSurfaceDesc, LPDIRECTDRAWSURFACE FAR* lplpDDSurface, IUnknown FAR* pUnkOuter)
{
    DirectDrawLogMethodValue(TRACE, CreateSurface, 3, (lpDDSurfaceDesc, lplpDDSurface, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateSurface(lpDDSurfaceDesc, lplpDDSurface, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDDSurface = ActivateAgentDelegate(DirectDrawSurface, *lplpDDSurface); }

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, CreateSurface, result, 3, (lpDDSurfaceDesc, lplpDDSurface, pUnkOuter));
}

// Duplicates a DirectDrawSurface object.
HRESULT DirectDraw::DuplicateSurface(LPDIRECTDRAWSURFACE lpDDSurface, LPDIRECTDRAWSURFACE FAR* lplpDupDDSurface)
{
    DirectDrawLogMethodValue(TRACE, DuplicateSurface, 2, (lpDDSurface, lplpDupDDSurface));

    AttemptAccessAgentValue(DirectDrawSurface, lpDDSurface);

    CONST HRESULT result = this->State.Self->DuplicateSurface(lpDDSurface, lplpDupDDSurface);

    if (SUCCEEDED(result)) { *lplpDupDDSurface = ActivateAgentDelegate(DirectDrawSurface, *lplpDupDDSurface); }

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, DuplicateSurface, result, 2, (ActivateAgent(DirectDrawSurface, lpDDSurface), lplpDupDDSurface));
}

// Enumerates all the display modes that the hardware exposes through the DirectDraw object
// and that are compatible with a provided surface description.
HRESULT DirectDraw::EnumDisplayModes(DWORD dwFlags, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpContext, LPDDENUMMODESCALLBACK lpEnumModesCallback)
{
    DirectDrawLogMethodValue(TRACEDEBUG, EnumDisplayModes, 4, (dwFlags, lpDDSurfaceDesc, lpContext, lpEnumModesCallback));

    if (lpEnumModesCallback == NULL) { DirectDrawLogMethodResultValue(TRACEDEBUGINFO, EnumDisplayModes, DDERR_INVALIDPARAMS, 4, (dwFlags, lpDDSurfaceDesc, lpContext, lpEnumModesCallback)); }

    DIRECTDRAWENUMDISPLAYMODESCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumDisplayModesCallback = lpEnumModesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumDisplayModes(dwFlags, lpDDSurfaceDesc, &context, EnumDisplayModesCallback);

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, EnumDisplayModes, result, 4, (dwFlags, lpDDSurfaceDesc, lpContext, lpEnumModesCallback));
}

// Enumerates all the existing or possible surfaces that meet the specified surface description.
HRESULT DirectDraw::EnumSurfaces(DWORD dwFlags, LPDDSURFACEDESC lpDDSD, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback)
{
    DirectDrawLogMethodValue(TRACEDEBUG, EnumSurfaces, 4, (dwFlags, lpDDSD, lpContext, lpEnumSurfacesCallback));

    if (lpEnumSurfacesCallback == NULL) { DirectDrawLogMethodResultValue(TRACEDEBUGINFO, EnumSurfaces, DDERR_INVALIDPARAMS, 4, (dwFlags, lpDDSD, lpContext, lpEnumSurfacesCallback)); }

    DIRECTDRAWENUMSURFACECALLBACKCONTEXT context;
    
    context.Self = this;
    context.EnumSurfacesCallback = lpEnumSurfacesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumSurfaces(dwFlags, lpDDSD, &context, EnumSurfacesCallback);

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, EnumSurfaces, result, 4, (dwFlags, lpDDSD, lpContext, lpEnumSurfacesCallback));
}

// Makes the surface that the GDI writes to the primary surface.
HRESULT DirectDraw::FlipToGDISurface()
{
    DirectDrawLogMethod(TRACE, FlipToGDISurface);

    CONST HRESULT result = this->State.Self->FlipToGDISurface();

    DirectDrawLogMethodResult(TRACEDEBUGINFO, FlipToGDISurface, result);
}

// Retrieves the capabilities of the device driver for the hardware and the hardware emulation layer (HEL).
HRESULT DirectDraw::GetCaps(LPDDCAPS lpDDDriverCaps, LPDDCAPS lpDDHELCaps)
{
    DirectDrawLogMethodValue(TRACE, GetCaps, 2, (lpDDDriverCaps, lpDDHELCaps));

    CONST HRESULT result = this->State.Self->GetCaps(lpDDDriverCaps, lpDDHELCaps);

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, GetCaps, result, 2, (lpDDDriverCaps, lpDDHELCaps));
}

// Retrieves the current display mode.
HRESULT DirectDraw::GetDisplayMode(LPDDSURFACEDESC lpDDSurfaceDesc)
{
    DirectDrawLogMethodValue(TRACE, GetDisplayMode, 1, (lpDDSurfaceDesc));

    CONST HRESULT result = this->State.Self->GetDisplayMode(lpDDSurfaceDesc);

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, GetDisplayMode, result, 1, (lpDDSurfaceDesc));
}

// Retrieves the four-character codes (FOURCC) that are supported by the DirectDraw object.
// This method can also retrieve the number of codes that are supported.
HRESULT DirectDraw::GetFourCCCodes(LPDWORD lpdwNumCodes, LPDWORD lpdwCodes)
{
    DirectDrawLogMethodValue(TRACE, GetFourCCCodes, 2, (lpdwNumCodes, lpdwCodes));

    CONST HRESULT result = this->State.Self->GetFourCCCodes(lpdwNumCodes, lpdwCodes);

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, GetFourCCCodes, result, 2, (lpdwNumCodes, lpdwCodes));
}

// Retrieves the DirectDrawSurface object that currently represents the surface memory that GDI is treating as the primary surface.
HRESULT DirectDraw::GetGDISurface(LPDIRECTDRAWSURFACE FAR* lplpGDIDDSSurface)
{
    DirectDrawLogMethodValue(TRACE, GetGDISurface, 1, (lplpGDIDDSSurface));

    CONST HRESULT result = this->State.Self->GetGDISurface(lplpGDIDDSSurface);

    if (SUCCEEDED(result)) { *lplpGDIDDSSurface = ActivateAgent(DirectDrawSurface, *lplpGDIDDSSurface); }

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, GetGDISurface, result, 1, (lplpGDIDDSSurface));
}

// Retrieves the frequency of the monitor that the DirectDraw object controls.
HRESULT DirectDraw::GetMonitorFrequency(LPDWORD lpdwFrequency)
{
    DirectDrawLogMethodValue(TRACE, GetMonitorFrequency, 1, (lpdwFrequency));

    CONST HRESULT result = this->State.Self->GetMonitorFrequency(lpdwFrequency);

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, GetMonitorFrequency, result, 1, (lpdwFrequency));
}

// Retrieves the scan line that is currently being drawn on the monitor.
HRESULT DirectDraw::GetScanLine(LPDWORD lpdwScanLine)
{
    DirectDrawLogMethodValue(TRACE, GetScanLine, 1, (lpdwScanLine));

    CONST HRESULT result = this->State.Self->GetScanLine(lpdwScanLine);

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, GetScanLine, result, 1, (lpdwScanLine));
}

// Retrieves the status of the vertical blank.
HRESULT DirectDraw::GetVerticalBlankStatus(LPBOOL lpbIsInVB)
{
    DirectDrawLogMethodValue(TRACE, GetVerticalBlankStatus, 1, (lpbIsInVB));

    CONST HRESULT result = this->State.Self->GetVerticalBlankStatus(lpbIsInVB);

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, GetVerticalBlankStatus, result, 1, (lpbIsInVB));
}

// Initializes a DirectDraw object that was created by using the CoCreateInstance COM function.
HRESULT DirectDraw::Initialize(GUID FAR* lpGUID)
{
    DirectDrawLogMethodValue(TRACE, Initialize, 1, (lpGUID));

    CONST HRESULT result = this->State.Self->Initialize(lpGUID);

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 1, (lpGUID));
}

// Resets the mode of the display device hardware for the primary surface to what it was before
// the IDirectDraw::SetDisplayMode method was called. Exclusive-level access is required to use this method.
HRESULT DirectDraw::RestoreDisplayMode()
{
    DirectDrawLogMethod(TRACE, RestoreDisplayMode);

    CONST HRESULT result = this->State.Self->RestoreDisplayMode();

    DirectDrawLogMethodResult(TRACEDEBUGINFO, RestoreDisplayMode, result);
}

// Determines the top-level behavior of the application.
HRESULT DirectDraw::SetCooperativeLevel(HWND hWnd, DWORD dwFlags)
{
    DirectDrawLogMethodValue(TRACE, SetCooperativeLevel, 2, (hWnd, dwFlags));

    CONST HRESULT result = this->State.Self->SetCooperativeLevel(hWnd, dwFlags);

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, SetCooperativeLevel, result, 2, (hWnd, dwFlags));
}

// Sets the mode of the display-device hardware.
HRESULT DirectDraw::SetDisplayMode(DWORD dwWidth, DWORD dwHeight, DWORD dwBPP)
{
    DirectDrawLogMethodValue(TRACE, SetDisplayMode, 3, (dwWidth, dwHeight, dwBPP));

    CONST HRESULT result = this->State.Self->SetDisplayMode(dwWidth, dwHeight, dwBPP);

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, SetDisplayMode, result, 3, (dwWidth, dwHeight, dwBPP));
}

// Helps the application synchronize itself with the vertical-blank interval.
HRESULT DirectDraw::WaitForVerticalBlank(DWORD dwFlags, HANDLE hEvent)
{
    DirectDrawLogMethodValue(TRACE, WaitForVerticalBlank, 2, (dwFlags, hEvent));

    CONST HRESULT result = this->State.Self->WaitForVerticalBlank(dwFlags, hEvent);

    DirectDrawLogMethodResultValue(TRACEDEBUGINFO, WaitForVerticalBlank, result, 2, (dwFlags, hEvent));
}