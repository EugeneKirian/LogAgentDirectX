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

#include "Direct3DDevice.hxx"
#include "Direct3DTexture.hxx"
#include "Direct3DTexture2.hxx"
#include "DirectDraw.hxx"
#include "DirectDraw4.hxx"
#include "DirectDrawClipper.hxx"
#include "DirectDrawColorControl.hxx"
#include "DirectDrawGammaControl.hxx"
#include "DirectDrawPalette.hxx"
#include "DirectDrawSurface.hxx"
#include "DirectDrawSurface2.hxx"
#include "DirectDrawSurface3.hxx"
#include "DirectDrawSurface4.hxx"
#include "DirectDrawSurface7.hxx"

#include <AgentLogger.hxx>
#include <DirectDrawSurface2Logger.hxx>

#define DirectDrawSurface2LogMethod(L, M) AgentLogMethod(L, DirectDrawSurface2, M)
#define DirectDrawSurface2LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectDrawSurface2, M, C, PARAMS)

#define DirectDrawSurface2LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectDrawSurface2, AddRef, R)
#define DirectDrawSurface2LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectDrawSurface2, Release, R)

#define DirectDrawSurface2LogMethodResult(L, M, R) AgentLogMethodResult(L, DirectDrawSurface2, M, R)
#define DirectDrawSurface2LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectDrawSurface2, M, R, C, PARAMS)

#define DirectDrawSurface2LogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, DirectDrawSurface2, M, C, PARAMS)
#define DirectDrawSurface2LogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, DirectDrawSurface2, M, R, C, PARAMS)

typedef struct EnumAttachedSurfacesCallbackContext
{
    DirectDrawSurface2* Self;
    LPLOGGER Logger;
    LPDDENUMSURFACESCALLBACK EnumSurfacesCallback;
    LPVOID Context;
} ENUMATTACHEDSURFACESCALLBACKCONTEXT, * LPENUMATTACHEDSURFACESCALLBACKCONTEXT;

static HRESULT CALLBACK EnumAttachedSurfacesCallback(LPDIRECTDRAWSURFACE lpDDSurface, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpContext)
{
    LPENUMATTACHEDSURFACESCALLBACKCONTEXT context = (LPENUMATTACHEDSURFACESCALLBACKCONTEXT)lpContext;

    DirectDrawSurface2LogMethodCallbackValue(TRACEDEBUG, EnumAttachedSurfaces, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));

    CONST HRESULT result = context->EnumSurfacesCallback(lpDDSurface, lpDDSurfaceDesc, context->Context);

    DirectDrawSurface2LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumAttachedSurfaces, result, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));
}

typedef struct EnumOverlayZOrdersCallbackContext
{
    DirectDrawSurface2* Self;
    LPLOGGER Logger;
    LPDDENUMSURFACESCALLBACK Callback;
    LPVOID Context;
} ENUMOVERLAYZORDERSCALLBACKCONTEXT, * LPENUMOVERLAYZORDERSCALLBACKCONTEXT;

static HRESULT CALLBACK EnumOverlayZOrdersCallback(LPDIRECTDRAWSURFACE lpDDSurface, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpContext)
{
    LPENUMOVERLAYZORDERSCALLBACKCONTEXT context = (LPENUMOVERLAYZORDERSCALLBACKCONTEXT)lpContext;

    DirectDrawSurface2LogMethodCallbackValue(TRACEDEBUG, EnumOverlayZOrders, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));

    CONST HRESULT result = context->Callback(lpDDSurface, lpDDSurfaceDesc, context->Context);

    DirectDrawSurface2LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumOverlayZOrders, result, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));
}

DirectDrawSurface2::DirectDrawSurface2(AgentConstructorParameters(DirectDrawSurface2))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectDrawSurface2);
}

DirectDrawSurface2::~DirectDrawSurface2()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectDrawSurface2);
}

HRESULT DirectDrawSurface2::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectDrawSurface2LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DTexture, riid)) { *ppvObj = ActivateAgent(Direct3DTexture, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DTexture2, riid)) { *ppvObj = ActivateAgent(Direct3DTexture2, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawColorControl, riid)) { *ppvObj = ActivateAgent(DirectDrawColorControl, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawGammaControl, riid)) { *ppvObj = ActivateAgent(DirectDrawGammaControl, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface2, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface2, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface3, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface3, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface4, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface4, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface7, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface7, *ppvObj); }
            else { *ppvObj = ActivateAgent(Direct3DDevice, *ppvObj); } // NOTE: Surface Caps must have DDSCAPS_3DDEVICE flag set.
        }
    }

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectDrawSurface2::AddRef()
{
    DirectDrawSurface2LogMethod(DEBUG, AddRef);
    DirectDrawSurface2LogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectDrawSurface2::Release()
{
    DirectDrawSurface2LogMethod(DEBUG, Release);
    DirectDrawSurface2LogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Attaches the specified z-buffer surface to this surface.
HRESULT DirectDrawSurface2::AddAttachedSurface(LPDIRECTDRAWSURFACE2 lpDDSAttachedSurface)
{
    DirectDrawSurface2LogMethodValue(TRACE, AddAttachedSurface, 1, (lpDDSAttachedSurface));

    AttemptAccessAgentValue(DirectDrawSurface2, lpDDSAttachedSurface);

    CONST HRESULT result = this->State.Self->AddAttachedSurface(lpDDSAttachedSurface);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, AddAttachedSurface, result, 1, (ActivateAgent(DirectDrawSurface2, lpDDSAttachedSurface)));
}

// This method is not currently implemented.
HRESULT DirectDrawSurface2::AddOverlayDirtyRect(LPRECT lpRect)
{
    DirectDrawSurface2LogMethodValue(TRACE, AddOverlayDirtyRect, 1, (lpRect));

    CONST HRESULT result = this->State.Self->AddOverlayDirtyRect(lpRect);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, AddOverlayDirtyRect, result, 1, (lpRect));
}

// Performs a bit block transfer (bitblt).
// This method does not support z-buffering or alpha blending during bitblt operations.
HRESULT DirectDrawSurface2::Blt(LPRECT lpDestRect, LPDIRECTDRAWSURFACE2 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx)
{
    DirectDrawSurface2LogMethodValue(TRACE, Blt, 5, (lpDestRect, lpDDSrcSurface, lpSrcRect, dwFlags, lpDDBltFx));

    AttemptAccessAgentValue(DirectDrawSurface2, lpDDSrcSurface);

    if (lpDDBltFx != NULL)
    {
        if (dwFlags & DDBLT_ZBUFFERDESTOVERRIDE) { AttemptAccessAgentValue(DirectDrawSurface, lpDDBltFx->lpDDSZBufferDest); }

        if (dwFlags & DDBLT_ZBUFFERSRCOVERRIDE) { AttemptAccessAgentValue(DirectDrawSurface, lpDDBltFx->lpDDSZBufferSrc); }

        if (dwFlags & DDBLT_ALPHADESTSURFACEOVERRIDE) { AttemptAccessAgentValue(DirectDrawSurface, lpDDBltFx->lpDDSAlphaDest); }

        if (dwFlags & DDBLT_ALPHASRCSURFACEOVERRIDE) { AttemptAccessAgentValue(DirectDrawSurface, lpDDBltFx->lpDDSAlphaSrc); }

        if (dwFlags & DDBLT_PRIVATE_ALIASPATTERN) { AttemptAccessAgentValue(DirectDrawSurface, lpDDBltFx->lpDDSPattern); }
    }

    CONST HRESULT result = this->State.Self->Blt(lpDestRect, lpDDSrcSurface, lpSrcRect, dwFlags, lpDDBltFx);

    if (lpDDBltFx != NULL)
    {
        if (dwFlags & DDBLT_ZBUFFERDESTOVERRIDE) { lpDDBltFx->lpDDSZBufferDest = ActivateAgent(DirectDrawSurface, lpDDBltFx->lpDDSZBufferDest); }

        if (dwFlags & DDBLT_ZBUFFERSRCOVERRIDE) { lpDDBltFx->lpDDSZBufferSrc = ActivateAgent(DirectDrawSurface, lpDDBltFx->lpDDSZBufferSrc); }

        if (dwFlags & DDBLT_ALPHADESTSURFACEOVERRIDE) { lpDDBltFx->lpDDSAlphaDest = ActivateAgent(DirectDrawSurface, lpDDBltFx->lpDDSAlphaDest); }

        if (dwFlags & DDBLT_ALPHASRCSURFACEOVERRIDE) { lpDDBltFx->lpDDSAlphaSrc = ActivateAgent(DirectDrawSurface, lpDDBltFx->lpDDSAlphaSrc); }

        if (dwFlags & DDBLT_PRIVATE_ALIASPATTERN) { lpDDBltFx->lpDDSPattern = ActivateAgent(DirectDrawSurface, lpDDBltFx->lpDDSPattern); }
    }

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, Blt, result, 5, (lpDestRect, ActivateAgent(DirectDrawSurface2, lpDDSrcSurface), lpSrcRect, dwFlags, lpDDBltFx));
}

// This method is not currently implemented.
HRESULT DirectDrawSurface2::BltBatch(LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags)
{
    DirectDrawSurface2LogMethodValue(TRACE, BltBatch, 3, (lpDDBltBatch, dwCount, dwFlags));

    if (lpDDBltBatch != NULL) { AttemptAccessAgentValue(DirectDrawSurface, lpDDBltBatch->lpDDSSrc); }

    CONST HRESULT result = this->State.Self->BltBatch(lpDDBltBatch, dwCount, dwFlags);

    if (lpDDBltBatch != NULL) { lpDDBltBatch->lpDDSSrc = ActivateAgent(DirectDrawSurface, lpDDBltBatch->lpDDSSrc); }

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, BltBatch, result, 3, (lpDDBltBatch, dwCount, dwFlags));
}

// Performs a source copy bitblt or transparent bitblt by using a source color key or destination color key.
HRESULT DirectDrawSurface2::BltFast(DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE2 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans)
{
    DirectDrawSurface2LogMethodValue(TRACE, BltFast, 5, (dwX, dwY, lpDDSrcSurface, lpSrcRect, dwTrans));

    AttemptAccessAgentValue(DirectDrawSurface2, lpDDSrcSurface);

    CONST HRESULT result = this->State.Self->BltFast(dwX, dwY, lpDDSrcSurface, lpSrcRect, dwTrans);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, BltFast, result, 5, (dwX, dwY, ActivateAgent(DirectDrawSurface2, lpDDSrcSurface), lpSrcRect, dwTrans));
}

// Detaches one or more attached surfaces.
HRESULT DirectDrawSurface2::DeleteAttachedSurface(DWORD dwFlags, LPDIRECTDRAWSURFACE2 lpDDSAttachedSurface)
{
    DirectDrawSurface2LogMethodValue(TRACE, DeleteAttachedSurface, 2, (dwFlags, lpDDSAttachedSurface));

    AttemptAccessAgentValue(DirectDrawSurface2, lpDDSAttachedSurface);

    CONST HRESULT result = this->State.Self->DeleteAttachedSurface(dwFlags, lpDDSAttachedSurface);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, DeleteAttachedSurface, result, 2, (dwFlags, ActivateAgent(DirectDrawSurface2, lpDDSAttachedSurface)));
}

// Enumerates all the surfaces that are attached to this surface.
HRESULT DirectDrawSurface2::EnumAttachedSurfaces(LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback)
{
    DirectDrawSurface2LogMethodValue(DEBUGINFO, EnumAttachedSurfaces, 2, (lpContext, lpEnumSurfacesCallback));

    if (lpEnumSurfacesCallback == NULL) { DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, EnumAttachedSurfaces, DDERR_INVALIDPARAMS, 2, (lpContext, lpEnumSurfacesCallback)); }

    ENUMATTACHEDSURFACESCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumSurfacesCallback = lpEnumSurfacesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumAttachedSurfaces(&context, EnumAttachedSurfacesCallback);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, EnumAttachedSurfaces, result, 2, (lpContext, lpEnumSurfacesCallback));
}

// Enumerates the overlay surfaces on the specified destination.
// You can enumerate the overlays in front-to-back or back-to-front order.
HRESULT DirectDrawSurface2::EnumOverlayZOrders(DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpfnCallback)
{
    DirectDrawSurface2LogMethodValue(DEBUGINFO, EnumOverlayZOrders, 3, (dwFlags, lpContext, lpfnCallback));

    if (lpfnCallback == NULL) { DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, EnumOverlayZOrders, DDERR_INVALIDPARAMS, 3, (dwFlags, lpContext, lpfnCallback)); }

    ENUMOVERLAYZORDERSCALLBACKCONTEXT context;

    context.Self = this;
    context.Callback = lpfnCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumOverlayZOrders(dwFlags, &context, EnumOverlayZOrdersCallback);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, EnumOverlayZOrders, result, 3, (dwFlags, lpContext, lpfnCallback));
}

// Makes the surface memory that is associated with the DDSCAPS_BACKBUFFER surface become associated with the front-buffer surface.
HRESULT DirectDrawSurface2::Flip(LPDIRECTDRAWSURFACE2 lpDDSurfaceTargetOverride, DWORD dwFlags)
{
    DirectDrawSurface2LogMethodValue(TRACE, Flip, 2, (lpDDSurfaceTargetOverride, dwFlags));

    AttemptAccessAgentValue(DirectDrawSurface2, lpDDSurfaceTargetOverride);

    CONST HRESULT result = this->State.Self->Flip(lpDDSurfaceTargetOverride, dwFlags);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, Flip, result, 2, (ActivateAgent(DirectDrawSurface2, lpDDSurfaceTargetOverride), dwFlags));
}

// Obtains the attached surface that has the specified capabilities,
// and increments the reference count of the retrieved interface.
HRESULT DirectDrawSurface2::GetAttachedSurface(LPDDSCAPS lpDDSCaps, LPDIRECTDRAWSURFACE2 FAR* lplpDDAttachedSurface)
{
    DirectDrawSurface2LogMethodValue(TRACE, GetAttachedSurface, 2, (lpDDSCaps, lplpDDAttachedSurface));

    CONST HRESULT result = this->State.Self->GetAttachedSurface(lpDDSCaps, lplpDDAttachedSurface);

    if (SUCCEEDED(result)) { *lplpDDAttachedSurface = ActivateAgentDelegate(DirectDrawSurface2, *lplpDDAttachedSurface); }

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, GetAttachedSurface, result, 2, (lpDDSCaps, lplpDDAttachedSurface));
}

// Obtains status about a bit block transfer (bitblt) operation.
HRESULT DirectDrawSurface2::GetBltStatus(DWORD dwFlags)
{
    DirectDrawSurface2LogMethodValue(TRACE, GetBltStatus, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->GetBltStatus(dwFlags);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, GetBltStatus, result, 1, (dwFlags));
}

// Retrieves the capabilities of this surface.
// These capabilities are not necessarily related to the capabilities of the display device.
HRESULT DirectDrawSurface2::GetCaps(LPDDSCAPS lpDDSCaps)
{
    DirectDrawSurface2LogMethodValue(TRACE, GetCaps, 1, (lpDDSCaps));

    CONST HRESULT result = this->State.Self->GetCaps(lpDDSCaps);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, GetCaps, result, 1, (lpDDSCaps));
}

// Retrieves the DirectDrawClipper object that is associated with this surface,
// and increments the reference count of the returned clipper.
HRESULT DirectDrawSurface2::GetClipper(LPDIRECTDRAWCLIPPER FAR* lplpDDClipper)
{
    DirectDrawSurface2LogMethodValue(TRACE, GetClipper, 1, (lplpDDClipper));

    CONST HRESULT result = this->State.Self->GetClipper(lplpDDClipper);

    if (SUCCEEDED(result)) { *lplpDDClipper = ActivateAgentDelegate(DirectDrawClipper, *lplpDDClipper); }

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, GetClipper, result, 1, (lplpDDClipper));
}

// Retrieves the color key value for this surface.
HRESULT DirectDrawSurface2::GetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey)
{
    DirectDrawSurface2LogMethodValue(TRACE, GetColorKey, 2, (dwFlags, lpDDColorKey));

    CONST HRESULT result = this->State.Self->GetColorKey(dwFlags, lpDDColorKey);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, GetColorKey, result, 2, (dwFlags, lpDDColorKey));
}

// Creates a GDI-compatible handle of a device context for this surface.
HRESULT DirectDrawSurface2::GetDC(HDC FAR* lphDC)
{
    DirectDrawSurface2LogMethodValue(TRACE, GetDC, 1, (lphDC));

    CONST HRESULT result = this->State.Self->GetDC(lphDC);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, GetDC, result, 1, (lphDC));
}

// Retrieves status about whether this surface has finished its flipping process.
HRESULT DirectDrawSurface2::GetFlipStatus(DWORD dwFlags)
{
    DirectDrawSurface2LogMethodValue(TRACE, GetFlipStatus, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->GetFlipStatus(dwFlags);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, GetFlipStatus, result, 1, (dwFlags));
}

// Retrieves the display coordinates of this surface.
// This method is used on a visible, active overlay surface
// (that is, a surface that has the DDSCAPS_OVERLAY flag set).
HRESULT DirectDrawSurface2::GetOverlayPosition(LPLONG lplX, LPLONG lplY)
{
    DirectDrawSurface2LogMethodValue(TRACE, GetOverlayPosition, 2, (lplX, lplY));

    CONST HRESULT result = this->State.Self->GetOverlayPosition(lplX, lplY);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, GetOverlayPosition, result, 2, (lplX, lplY));
}

// Retrieves the DirectDrawPalette object that is associated with this surface,
// and increments the reference count of the returned palette.
HRESULT DirectDrawSurface2::GetPalette(LPDIRECTDRAWPALETTE FAR* lplpDDPalette)
{
    DirectDrawSurface2LogMethodValue(TRACE, GetPalette, 1, (lplpDDPalette));

    CONST HRESULT result = this->State.Self->GetPalette(lplpDDPalette);

    if (SUCCEEDED(result)) { *lplpDDPalette = ActivateAgentDelegate(DirectDrawPalette, *lplpDDPalette); }

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, GetPalette, result, 1, (lplpDDPalette));
}

// Retrieves the color and pixel format of this surface.
HRESULT DirectDrawSurface2::GetPixelFormat(LPDDPIXELFORMAT lpDDPixelFormat)
{
    DirectDrawSurface2LogMethodValue(TRACE, GetPixelFormat, 1, (lpDDPixelFormat));

    CONST HRESULT result = this->State.Self->GetPixelFormat(lpDDPixelFormat);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, GetPixelFormat, result, 1, (lpDDPixelFormat));
}

// Retrieves a description of this surface in its current condition.
HRESULT DirectDrawSurface2::GetSurfaceDesc(LPDDSURFACEDESC lpDDSurfaceDesc)
{
    DirectDrawSurface2LogMethodValue(TRACE, GetSurfaceDesc, 1, (lpDDSurfaceDesc));

    CONST HRESULT result = this->State.Self->GetSurfaceDesc(lpDDSurfaceDesc);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, GetSurfaceDesc, result, 1, (lpDDSurfaceDesc));
}

// Initializes a DirectDrawSurface2 object.
HRESULT DirectDrawSurface2::Initialize(LPDIRECTDRAW lpDD, LPDDSURFACEDESC lpDDSurfaceDesc)
{
    DirectDrawSurface2LogMethodValue(TRACE, Initialize, 2, (lpDD, lpDDSurfaceDesc));

    AttemptAccessAgentValue(DirectDraw, lpDD);

    CONST HRESULT result = this->State.Self->Initialize(lpDD, lpDDSurfaceDesc);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 2, (ActivateAgent(DirectDraw, lpDD), lpDDSurfaceDesc));
}

// Determines whether the surface memory that is associated with a DirectDrawSurface2 object has been freed.
HRESULT DirectDrawSurface2::IsLost()
{
    DirectDrawSurface2LogMethod(DEBUG, IsLost);

    CONST HRESULT result = this->State.Self->IsLost();

    DirectDrawSurface2LogMethodResult(DEBUGINFO, IsLost, result);
}

// Obtains a pointer to the surface memory.
HRESULT DirectDrawSurface2::Lock(LPRECT lpDestRect, LPDDSURFACEDESC lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent)
{
    DirectDrawSurface2LogMethodValue(TRACE, Lock, 4, (lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent));

    CONST HRESULT result = this->State.Self->Lock(lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, Lock, result, 4, (lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent));
}

// Releases the handle of a device context that was previously obtained by using the IDirectDrawSurface2::GetDC method.
HRESULT DirectDrawSurface2::ReleaseDC(HDC hDC)
{
    DirectDrawSurface2LogMethodValue(TRACE, ReleaseDC, 1, (hDC));

    CONST HRESULT result = this->State.Self->ReleaseDC(hDC);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, ReleaseDC, result, 1, (hDC));
}

// Restores a surface that has been lost.
// This occurs when the surface memory that is associated with the DirectDrawSurface2 object has been freed.
HRESULT DirectDrawSurface2::Restore()
{
    DirectDrawSurface2LogMethod(DEBUG, Restore);

    CONST HRESULT result = this->State.Self->Restore();

    DirectDrawSurface2LogMethodResult(DEBUGINFO, Restore, result);
}

// Attaches a clipper object to, or deletes one from, this surface.
HRESULT DirectDrawSurface2::SetClipper(LPDIRECTDRAWCLIPPER lpDDClipper)
{
    DirectDrawSurface2LogMethodValue(TRACE, SetClipper, 1, (lpDDClipper));

    AttemptAccessAgentValue(DirectDrawClipper, lpDDClipper);

    CONST HRESULT result = this->State.Self->SetClipper(lpDDClipper);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, SetClipper, result, 1, (ActivateAgent(DirectDrawClipper, lpDDClipper)));
}

// Sets the color key value for the DirectDrawSurface2 object if the hardware supports color keys on a per-surface basis.
HRESULT DirectDrawSurface2::SetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey)
{
    DirectDrawSurface2LogMethodValue(TRACE, SetColorKey, 2, (dwFlags, lpDDColorKey));

    CONST HRESULT result = this->State.Self->SetColorKey(dwFlags, lpDDColorKey);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, SetColorKey, result, 2, (dwFlags, lpDDColorKey));
}

// Changes the display coordinates of an overlay surface.
HRESULT DirectDrawSurface2::SetOverlayPosition(LONG lX, LONG lY)
{
    DirectDrawSurface2LogMethodValue(TRACE, SetOverlayPosition, 2, (lX, lY));

    CONST HRESULT result = this->State.Self->SetOverlayPosition(lX, lY);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, SetOverlayPosition, result, 2, (lX, lY));
}

// Attaches a palette object to (or detaches one from) a surface.
// The surface uses this palette for all subsequent operations.
// The palette change takes place immediately, without regard to refresh timing.
HRESULT DirectDrawSurface2::SetPalette(LPDIRECTDRAWPALETTE lpDDPalette)
{
    DirectDrawSurface2LogMethodValue(TRACE, SetPalette, 1, (lpDDPalette));

    AttemptAccessAgentValue(DirectDrawPalette, lpDDPalette);

    CONST HRESULT result = this->State.Self->SetPalette(lpDDPalette);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, SetPalette, result, 1, (ActivateAgent(DirectDrawPalette, lpDDPalette)));
}

// Notifies DirectDraw that the direct surface manipulations are complete.
HRESULT DirectDrawSurface2::Unlock(LPVOID lpSurfaceData)
{
    DirectDrawSurface2LogMethodValue(TRACE, Unlock, 1, (lpSurfaceData));

    CONST HRESULT result = this->State.Self->Unlock(lpSurfaceData);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, Unlock, result, 1, (lpSurfaceData));
}

// Repositions or modifies the visual attributes of an overlay surface.
// These surfaces must have the DDSCAPS_OVERLAY flag set.
HRESULT DirectDrawSurface2::UpdateOverlay(LPRECT lpSrcRect, LPDIRECTDRAWSURFACE2 lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx)
{
    DirectDrawSurface2LogMethodValue(TRACE, UpdateOverlay, 5, (lpSrcRect, lpDDDestSurface, lpDestRect, dwFlags, lpDDOverlayFx));

    AttemptAccessAgentValue(DirectDrawSurface2, lpDDDestSurface);

    if (lpDDOverlayFx != NULL)
    {
        if (dwFlags & DDOVER_ALPHADESTSURFACEOVERRIDE) { AttemptAccessAgentValue(DirectDrawSurface, lpDDOverlayFx->lpDDSAlphaDest); }

        if (dwFlags & DDOVER_ALPHASRCSURFACEOVERRIDE) { AttemptAccessAgentValue(DirectDrawSurface, lpDDOverlayFx->lpDDSAlphaSrc); }
    }

    CONST HRESULT result = this->State.Self->UpdateOverlay(lpSrcRect, lpDDDestSurface, lpDestRect, dwFlags, lpDDOverlayFx);

    if (lpDDOverlayFx != NULL)
    {
        if (dwFlags & DDOVER_ALPHADESTSURFACEOVERRIDE) { lpDDOverlayFx->lpDDSAlphaDest = ActivateAgent(DirectDrawSurface, lpDDOverlayFx->lpDDSAlphaDest); }

        if (dwFlags & DDOVER_ALPHASRCSURFACEOVERRIDE) { lpDDOverlayFx->lpDDSAlphaSrc = ActivateAgent(DirectDrawSurface, lpDDOverlayFx->lpDDSAlphaSrc); }
    }

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, UpdateOverlay, result, 5, (lpSrcRect, ActivateAgent(DirectDrawSurface2, lpDDDestSurface), lpDestRect, dwFlags, lpDDOverlayFx));
}

// This method is not currently implemented.
HRESULT DirectDrawSurface2::UpdateOverlayDisplay(DWORD dwFlags)
{
    DirectDrawSurface2LogMethodValue(TRACE, UpdateOverlayDisplay, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->UpdateOverlayDisplay(dwFlags);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, UpdateOverlayDisplay, result, 1, (dwFlags));
}

// Sets the z-order of an overlay.
HRESULT DirectDrawSurface2::UpdateOverlayZOrder(DWORD dwFlags, LPDIRECTDRAWSURFACE2 lpDDSReference)
{
    DirectDrawSurface2LogMethodValue(TRACE, UpdateOverlayZOrder, 2, (dwFlags, lpDDSReference));

    AttemptAccessAgentValue(DirectDrawSurface2, lpDDSReference);

    CONST HRESULT result = this->State.Self->UpdateOverlayZOrder(dwFlags, lpDDSReference);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, UpdateOverlayZOrder, result, 2, (dwFlags, ActivateAgent(DirectDrawSurface2, lpDDSReference)));
}

// Retrieves an interface to the DirectDraw object that was used to create this surface.
HRESULT DirectDrawSurface2::GetDDInterface(LPVOID FAR* lplpDD)
{
    DirectDrawSurface2LogMethodValue(TRACE, GetDDInterface, 1, (lplpDD));

    CONST HRESULT result = this->State.Self->GetDDInterface(lplpDD);

    if (SUCCEEDED(result)) { *lplpDD = ActivateAgentDelegate(DirectDraw4, *lplpDD); }

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, GetDDInterface, result, 1, (lplpDD));
}

// Prevents a system-memory surface from being paged out while a bit block transfer (bitblt) operation
// that uses direct memory access (DMA) transfers to or from system memory is in progress.
HRESULT DirectDrawSurface2::PageLock(DWORD dwFlags)
{
    DirectDrawSurface2LogMethodValue(TRACE, PageLock, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->PageLock(dwFlags);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, PageLock, result, 1, (dwFlags));
}

// Unlocks a system-memory surface, which then allows it to be paged out.
HRESULT DirectDrawSurface2::PageUnlock(DWORD dwFlags)
{
    DirectDrawSurface2LogMethodValue(TRACE, PageUnlock, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->PageUnlock(dwFlags);

    DirectDrawSurface2LogMethodResultValue(TRACEDEBUGINFO, PageUnlock, result, 1, (dwFlags));
}