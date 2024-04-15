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

#include "Direct3D7.hxx"
#include "DirectDraw.hxx"
#include "DirectDraw2.hxx"
#include "DirectDraw4.hxx"
#include "DirectDraw7.hxx"
#include "DirectDrawClipper.hxx"
#include "DirectDrawPalette.hxx"
#include "DirectDrawSurface7.hxx"
#include "DirectDrawVideoPortContainer.hxx"

#include <AgentLogger.hxx>
#include <DirectDraw7Logger.hxx>

#define DirectDraw7LogMethod(L, M) AgentLogMethod(L, DirectDraw7, M)
#define DirectDraw7LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectDraw7, M, C, PARAMS)

#define DirectDraw7LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectDraw7, AddRef, R)
#define DirectDraw7LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectDraw7, Release, R)

#define DirectDraw7LogMethodResult(L, M, R) AgentLogMethodResult(L, DirectDraw7, M, R)
#define DirectDraw7LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectDraw7, M, R, C, PARAMS)

#define DirectDraw7LogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, DirectDraw7, M, C, PARAMS)
#define DirectDraw7LogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, DirectDraw7, M, R, C, PARAMS)

typedef struct DirectDrawEnumModesCallbackContext
{
    DirectDraw7* Self;
    LPLOGGER Logger;
    LPDDENUMMODESCALLBACK2 EnumModesCallback;
    LPVOID Context;
} DIRECTDRAWENUMMODESCALLBACKCONTEXT, * LPDIRECTDRAWENUMMODESCALLBACKCONTEXT;

static HRESULT CALLBACK EnumModesCallback(LPDDSURFACEDESC2 lpDDSurfaceDesc, LPVOID lpContext)
{
    LPDIRECTDRAWENUMMODESCALLBACKCONTEXT context = (LPDIRECTDRAWENUMMODESCALLBACKCONTEXT)lpContext;

    DirectDraw7LogMethodCallbackValue(TRACEDEBUG, EnumDisplayModes, 2, (context->Self, lpDDSurfaceDesc));

    CONST HRESULT result = context->EnumModesCallback(lpDDSurfaceDesc, context->Context);

    DirectDraw7LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumDisplayModes, result, 2, (context->Self, lpDDSurfaceDesc));
}

typedef struct DirectDrawEnumSurfaceCallbackContext
{
    DirectDraw7* Self;
    LPLOGGER Logger;
    LPDDENUMSURFACESCALLBACK7 EnumSurfacesCallback;
    LPVOID Context;
} DIRECTDRAWENUMSURFACECALLBACKCONTEXT, * LPDIRECTDRAWENUMSURFACECALLBACKCONTEXT;

static HRESULT CALLBACK EnumSurfacesCallback(LPDIRECTDRAWSURFACE7 lpDDSurface, LPDDSURFACEDESC2 lpDDSD, LPVOID lpContext)
{
    LPDIRECTDRAWENUMSURFACECALLBACKCONTEXT context = (LPDIRECTDRAWENUMSURFACECALLBACKCONTEXT)lpContext;

    DirectDraw7LogMethodCallbackValue(TRACEDEBUG, EnumSurfaces, 3, (context->Self, lpDDSurface, lpDDSD));

    CONST HRESULT result = context->EnumSurfacesCallback(lpDDSurface, lpDDSD, context->Context);

    DirectDraw7LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumSurfaces, result, 3, (context->Self, lpDDSurface, lpDDSD));
}

DirectDraw7::DirectDraw7(AgentConstructorParameters(DirectDraw7))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectDraw7);
}

DirectDraw7::~DirectDraw7()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectDraw7);
}

HRESULT DirectDraw7::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectDraw7LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3D7, riid)) { *ppvObj = ActivateAgent(Direct3D7, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(DirectDraw, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw2, riid)) { *ppvObj = ActivateAgent(DirectDraw2, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw4, riid)) { *ppvObj = ActivateAgent(DirectDraw4, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw7, riid)) { *ppvObj = ActivateAgent(DirectDraw7, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawVideoPortContainer, riid)) { *ppvObj = ActivateAgent(DirectDrawVideoPortContainer, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectDraw7::AddRef()
{
    DirectDraw7LogMethod(TRACE, AddRef);
    DirectDraw7LogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG DirectDraw7::Release()
{
    DirectDraw7LogMethod(TRACE, Release);
    DirectDraw7LogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// This method is not currently implemented.
HRESULT DirectDraw7::Compact()
{
    DirectDraw7LogMethod(TRACE, Compact);

    CONST HRESULT result = this->State.Self->Compact();

    DirectDraw7LogMethodResult(TRACEDEBUGINFO, Compact, result);
}

// Creates a DirectDrawClipper object.
HRESULT DirectDraw7::CreateClipper(DWORD dwFlags, LPDIRECTDRAWCLIPPER FAR* lplpDDClipper, IUnknown FAR* pUnkOuter)
{
    DirectDraw7LogMethodValue(TRACE, CreateClipper, 3, (dwFlags, lplpDDClipper, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateClipper(dwFlags, lplpDDClipper, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDDClipper = ActivateAgentDelegate(DirectDrawClipper, *lplpDDClipper); }

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, CreateClipper, result, 3, (dwFlags, lplpDDClipper, pUnkOuter));
}

// Creates a DirectDrawPalette object for this DirectDraw object.
HRESULT DirectDraw7::CreatePalette(DWORD dwFlags, LPPALETTEENTRY lpColorTable, LPDIRECTDRAWPALETTE FAR* lplpDDPalette, IUnknown FAR* pUnkOuter)
{
    DirectDraw7LogMethodValue(TRACE, CreatePalette, 4, (dwFlags, lpColorTable, lplpDDPalette, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreatePalette(dwFlags, lpColorTable, lplpDDPalette, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDDPalette = ActivateAgentDelegate(DirectDrawPalette, *lplpDDPalette); }

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, CreatePalette, result, 4, (dwFlags, lpColorTable, lplpDDPalette, pUnkOuter));
}

// Creates a DirectDrawSurface object for this DirectDraw object.
HRESULT DirectDraw7::CreateSurface(LPDDSURFACEDESC2 lpDDSurfaceDesc, LPDIRECTDRAWSURFACE7 FAR* lplpDDSurface, IUnknown FAR* pUnkOuter)
{
    DirectDraw7LogMethodValue(TRACE, CreateSurface, 3, (lpDDSurfaceDesc, lplpDDSurface, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateSurface(lpDDSurfaceDesc, lplpDDSurface, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDDSurface = ActivateAgentDelegate(DirectDrawSurface7, *lplpDDSurface); }

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, CreateSurface, result, 3, (lpDDSurfaceDesc, lplpDDSurface, pUnkOuter));
}

// Duplicates a DirectDrawSurface object.
HRESULT DirectDraw7::DuplicateSurface(LPDIRECTDRAWSURFACE7 lpDDSurface, LPDIRECTDRAWSURFACE7 FAR* lplpDupDDSurface)
{
    DirectDraw7LogMethodValue(TRACE, DuplicateSurface, 2, (lpDDSurface, lplpDupDDSurface));

    AttemptAccessAgentValue(DirectDrawSurface7, lpDDSurface);

    CONST HRESULT result = this->State.Self->DuplicateSurface(lpDDSurface, lplpDupDDSurface);

    if (SUCCEEDED(result)) { *lplpDupDDSurface = ActivateAgentDelegate(DirectDrawSurface7, *lplpDupDDSurface); }

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, DuplicateSurface, result, 2, (ActivateAgent(DirectDrawSurface7, lpDDSurface), lplpDupDDSurface));
}

// Enumerates all the display modes that the hardware exposes through the DirectDraw object
// and that are compatible with a provided surface description.
HRESULT DirectDraw7::EnumDisplayModes(DWORD dwFlags, LPDDSURFACEDESC2 lpDDSurfaceDesc, LPVOID lpContext, LPDDENUMMODESCALLBACK2 lpEnumModesCallback)
{
    DirectDraw7LogMethodValue(TRACEDEBUG, EnumDisplayModes, 4, (dwFlags, lpDDSurfaceDesc, lpContext, lpEnumModesCallback));

    if (lpEnumModesCallback == NULL) { DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, EnumDisplayModes, DDERR_INVALIDPARAMS, 4, (dwFlags, lpDDSurfaceDesc, lpContext, lpEnumModesCallback)); }

    DIRECTDRAWENUMMODESCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumModesCallback = lpEnumModesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumDisplayModes(dwFlags, lpDDSurfaceDesc, &context, EnumModesCallback);

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, EnumDisplayModes, result, 4, (dwFlags, lpDDSurfaceDesc, lpContext, lpEnumModesCallback));
}

// Enumerates all the existing or possible surfaces that meet the specified surface description.
HRESULT DirectDraw7::EnumSurfaces(DWORD dwFlags, LPDDSURFACEDESC2 lpDDSD, LPVOID lpContext, LPDDENUMSURFACESCALLBACK7 lpEnumSurfacesCallback)
{
    DirectDraw7LogMethodValue(TRACEDEBUG, EnumSurfaces, 4, (dwFlags, lpDDSD, lpContext, lpEnumSurfacesCallback));

    if (lpEnumSurfacesCallback == NULL) { DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, EnumSurfaces, DDERR_INVALIDPARAMS, 4, (dwFlags, lpDDSD, lpContext, lpEnumSurfacesCallback)); }

    DIRECTDRAWENUMSURFACECALLBACKCONTEXT context;

    context.Self = this;
    context.EnumSurfacesCallback = lpEnumSurfacesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumSurfaces(dwFlags, lpDDSD, &context, EnumSurfacesCallback);

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, EnumSurfaces, result, 4, (dwFlags, lpDDSD, lpContext, lpEnumSurfacesCallback));
}

// Makes the surface that the GDI writes to the primary surface.
HRESULT DirectDraw7::FlipToGDISurface()
{
    DirectDraw7LogMethod(TRACE, FlipToGDISurface);

    CONST HRESULT result = this->State.Self->FlipToGDISurface();

    DirectDraw7LogMethodResult(TRACEDEBUGINFO, FlipToGDISurface, result);
}

// Retrieves the capabilities of the device driver for the hardware and the hardware emulation layer (HEL).
HRESULT DirectDraw7::GetCaps(LPDDCAPS lpDDDriverCaps, LPDDCAPS lpDDHELCaps)
{
    DirectDraw7LogMethodValue(TRACE, GetCaps, 2, (lpDDDriverCaps, lpDDHELCaps));

    CONST HRESULT result = this->State.Self->GetCaps(lpDDDriverCaps, lpDDHELCaps);

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, GetCaps, result, 2, (lpDDDriverCaps, lpDDHELCaps));
}

// Retrieves the current display mode.
HRESULT DirectDraw7::GetDisplayMode(LPDDSURFACEDESC2 lpDDSurfaceDesc)
{
    DirectDraw7LogMethodValue(TRACE, GetDisplayMode, 1, (lpDDSurfaceDesc));

    CONST HRESULT result = this->State.Self->GetDisplayMode(lpDDSurfaceDesc);

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, GetDisplayMode, result, 1, (lpDDSurfaceDesc));
}

// Retrieves the four-character codes (FOURCC) that are supported by the DirectDraw object.
// This method can also retrieve the number of codes that are supported.
HRESULT DirectDraw7::GetFourCCCodes(LPDWORD lpdwNumCodes, LPDWORD lpdwCodes)
{
    DirectDraw7LogMethodValue(TRACE, GetFourCCCodes, 2, (lpdwNumCodes, lpdwCodes));

    CONST HRESULT result = this->State.Self->GetFourCCCodes(lpdwNumCodes, lpdwCodes);

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, GetFourCCCodes, result, 2, (lpdwNumCodes, lpdwCodes));
}

// Retrieves the DirectDrawSurface object that currently represents the surface memory that GDI is treating as the primary surface.
HRESULT DirectDraw7::GetGDISurface(LPDIRECTDRAWSURFACE7 FAR* lplpGDIDDSSurface)
{
    DirectDraw7LogMethodValue(TRACE, GetGDISurface, 1, (lplpGDIDDSSurface));

    CONST HRESULT result = this->State.Self->GetGDISurface(lplpGDIDDSSurface);

    if (SUCCEEDED(result)) { *lplpGDIDDSSurface = ActivateAgent(DirectDrawSurface7, *lplpGDIDDSSurface); }

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, GetGDISurface, result, 1, (lplpGDIDDSSurface));
}

// Retrieves the frequency of the monitor that the DirectDraw object controls.
HRESULT DirectDraw7::GetMonitorFrequency(LPDWORD lpdwFrequency)
{
    DirectDraw7LogMethodValue(TRACE, GetMonitorFrequency, 1, (lpdwFrequency));

    CONST HRESULT result = this->State.Self->GetMonitorFrequency(lpdwFrequency);

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, GetMonitorFrequency, result, 1, (lpdwFrequency));
}

// Retrieves the scan line that is currently being drawn on the monitor.
HRESULT DirectDraw7::GetScanLine(LPDWORD lpdwScanLine)
{
    DirectDraw7LogMethodValue(TRACE, GetScanLine, 1, (lpdwScanLine));

    CONST HRESULT result = this->State.Self->GetScanLine(lpdwScanLine);

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, GetScanLine, result, 1, (lpdwScanLine));
}

// Retrieves the status of the vertical blank.
HRESULT DirectDraw7::GetVerticalBlankStatus(LPBOOL lpbIsInVB)
{
    DirectDraw7LogMethodValue(TRACE, GetVerticalBlankStatus, 1, (lpbIsInVB));

    CONST HRESULT result = this->State.Self->GetVerticalBlankStatus(lpbIsInVB);

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, GetVerticalBlankStatus, result, 1, (lpbIsInVB));
}

// Initializes a DirectDraw object that was created by using the CoCreateInstance COM function.
HRESULT DirectDraw7::Initialize(GUID FAR* lpGUID)
{
    DirectDraw7LogMethodValue(TRACE, Initialize, 1, (lpGUID));

    CONST HRESULT result = this->State.Self->Initialize(lpGUID);

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 1, (lpGUID));
}

// Resets the mode of the display device hardware for the primary surface to what it was before
// the IDirectDraw::SetDisplayMode method was called. Exclusive-level access is required to use this method.
HRESULT DirectDraw7::RestoreDisplayMode()
{
    DirectDraw7LogMethod(TRACE, RestoreDisplayMode);

    CONST HRESULT result = this->State.Self->RestoreDisplayMode();

    DirectDraw7LogMethodResult(TRACEDEBUGINFO, RestoreDisplayMode, result);
}

// Determines the top-level behavior of the application.
HRESULT DirectDraw7::SetCooperativeLevel(HWND hWnd, DWORD dwFlags)
{
    DirectDraw7LogMethodValue(TRACE, SetCooperativeLevel, 2, (hWnd, dwFlags));

    CONST HRESULT result = this->State.Self->SetCooperativeLevel(hWnd, dwFlags);

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, SetCooperativeLevel, result, 2, (hWnd, dwFlags));
}

// Sets the mode of the display-device hardware.
HRESULT DirectDraw7::SetDisplayMode(DWORD dwWidth, DWORD dwHeight, DWORD dwBPP, DWORD dwRefreshRate, DWORD dwFlags)
{
    DirectDraw7LogMethodValue(TRACE, SetDisplayMode, 5, (dwWidth, dwHeight, dwBPP, dwRefreshRate, dwFlags));

    CONST HRESULT result = this->State.Self->SetDisplayMode(dwWidth, dwHeight, dwBPP, dwRefreshRate, dwFlags);

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, SetDisplayMode, result, 5, (dwWidth, dwHeight, dwBPP, dwRefreshRate, dwFlags));
}

// Helps the application synchronize itself with the vertical-blank interval.
HRESULT DirectDraw7::WaitForVerticalBlank(DWORD dwFlags, HANDLE hEvent)
{
    DirectDraw7LogMethodValue(TRACE, WaitForVerticalBlank, 2, (dwFlags, hEvent));

    CONST HRESULT result = this->State.Self->WaitForVerticalBlank(dwFlags, hEvent);

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, WaitForVerticalBlank, result, 2, (dwFlags, hEvent));
}

// Retrieves the total amount of display memory available and the amount of display memory currently free for a given type of surface.
HRESULT DirectDraw7::GetAvailableVidMem(LPDDSCAPS2 lpDDSCaps, LPDWORD lpdwTotal, LPDWORD lpdwFree)
{
    DirectDraw7LogMethodValue(TRACE, GetAvailableVidMem, 3, (lpDDSCaps, lpdwTotal, lpdwFree));

    CONST HRESULT result = this->State.Self->GetAvailableVidMem(lpDDSCaps, lpdwTotal, lpdwFree);

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, GetAvailableVidMem, result, 3, (lpDDSCaps, lpdwTotal, lpdwFree));
}

// Retrieves the IDirectDrawSurface7 interface for a surface, based on its GDI device context handle.
HRESULT DirectDraw7::GetSurfaceFromDC(HDC hDC, LPDIRECTDRAWSURFACE7* lpDDS)
{
    DirectDraw7LogMethodValue(TRACE, GetSurfaceFromDC, 2, (hDC, lpDDS));

    CONST HRESULT result = this->State.Self->GetSurfaceFromDC(hDC, lpDDS);

    if (SUCCEEDED(result)) { *lpDDS = ActivateAgent(DirectDrawSurface7, *lpDDS); }

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, GetSurfaceFromDC, result, 2, (hDC, lpDDS));
}

// Restores all the surfaces that were created for the DirectDraw object, in the order that they were created.
HRESULT DirectDraw7::RestoreAllSurfaces()
{
    DirectDraw7LogMethod(TRACE, RestoreAllSurfaces);

    CONST HRESULT result = this->State.Self->RestoreAllSurfaces();

    DirectDraw7LogMethodResult(TRACEDEBUGINFO, RestoreAllSurfaces, result);
}

// Reports the current cooperative-level status of the DirectDraw device for a windowed or full-screen application.
HRESULT DirectDraw7::TestCooperativeLevel()
{
    DirectDraw7LogMethod(TRACE, TestCooperativeLevel);

    CONST HRESULT result = this->State.Self->TestCooperativeLevel();

    DirectDraw7LogMethodResult(TRACEDEBUGINFO, TestCooperativeLevel, result);
}

// Obtains information about the device driver. This method can be used, with caution,
// to recognize specific hardware installations to implement workarounds for poor driver or chipset behavior.
HRESULT DirectDraw7::GetDeviceIdentifier(LPDDDEVICEIDENTIFIER2 lpDDDI, DWORD dwFlags)
{
    DirectDraw7LogMethodValue(TRACE, GetDeviceIdentifier, 2, (lpDDDI, dwFlags));

    CONST HRESULT result = this->State.Self->GetDeviceIdentifier(lpDDDI, dwFlags);

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, GetDeviceIdentifier, result, 2, (lpDDDI, dwFlags));
}

// Initiates a test to update the system registry with refresh rate information for the current display adapter and monitor combination.
// A call to this method is typically followed by calls to IDirectDraw7::EvaluateMode to pass or fail modes displayed by the test.
HRESULT DirectDraw7::StartModeTest(LPSIZE lpModesToTest, DWORD dwNumEntries, DWORD dwFlags)
{
    DirectDraw7LogMethodValue(TRACE, StartModeTest, 3, (lpModesToTest, dwNumEntries, dwFlags));

    CONST HRESULT result = this->State.Self->StartModeTest(lpModesToTest, dwNumEntries, dwFlags);

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, StartModeTest, result, 3, (lpModesToTest, dwNumEntries, dwFlags));
}

// Used after a call to IDirectDraw7::StartModeTest to pass or fail each mode that the test presents and to step through the modes until the test is complete.
HRESULT DirectDraw7::EvaluateMode(DWORD dwFlags, LPDWORD pSecondsUntilTimeout)
{
    DirectDraw7LogMethodValue(TRACE, EvaluateMode, 2, (dwFlags, pSecondsUntilTimeout));

    CONST HRESULT result = this->State.Self->EvaluateMode(dwFlags, pSecondsUntilTimeout);

    DirectDraw7LogMethodResultValue(TRACEDEBUGINFO, EvaluateMode, result, 2, (dwFlags, pSecondsUntilTimeout));
}