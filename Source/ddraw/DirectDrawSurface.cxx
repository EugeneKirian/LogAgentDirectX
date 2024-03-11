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
#include <DirectDrawSurfaceLogger.hxx>

#define DirectDrawSurfaceLogMethod(L, M) AgentLogMethod(L, DirectDrawSurface, M)
#define DirectDrawSurfaceLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectDrawSurface, M, C, PARAMS)

#define DirectDrawSurfaceLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectDrawSurface, AddRef, R)
#define DirectDrawSurfaceLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectDrawSurface, Release, R)

#define DirectDrawSurfaceLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectDrawSurface, M, R)
#define DirectDrawSurfaceLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectDrawSurface, M, R, C, PARAMS)

#define DirectDrawSurfaceLogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, DirectDrawSurface, M, C, PARAMS)
#define DirectDrawSurfaceLogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, DirectDrawSurface, M, R, C, PARAMS)

typedef struct EnumAttachedSurfacesCallbackContext
{
    DirectDrawSurface* Self;
    LPLOGGER Logger;
    LPDDENUMSURFACESCALLBACK EnumSurfacesCallback;
    LPVOID Context;
} ENUMATTACHEDSURFACESCALLBACKCONTEXT, * LPENUMATTACHEDSURFACESCALLBACKCONTEXT;

static HRESULT CALLBACK EnumAttachedSurfacesCallback(LPDIRECTDRAWSURFACE lpDDSurface, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpContext)
{
    LPENUMATTACHEDSURFACESCALLBACKCONTEXT context = (LPENUMATTACHEDSURFACESCALLBACKCONTEXT)lpContext;

    DirectDrawSurfaceLogMethodCallbackValue(TRACEDEBUG, EnumAttachedSurfaces, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));

    CONST HRESULT result = context->EnumSurfacesCallback(lpDDSurface, lpDDSurfaceDesc, context->Context);

    DirectDrawSurfaceLogMethodCallbackResultValue(TRACEDEBUGINFO, EnumAttachedSurfaces, result, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));
}

typedef struct EnumOverlayZOrdersCallbackContext
{
    DirectDrawSurface* Self;
    LPLOGGER Logger;
    LPDDENUMSURFACESCALLBACK Callback;
    LPVOID Context;
} ENUMOVERLAYZORDERSCALLBACKCONTEXT, * LPENUMOVERLAYZORDERSCALLBACKCONTEXT;

static HRESULT CALLBACK EnumOverlayZOrdersCallback(LPDIRECTDRAWSURFACE lpDDSurface, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpContext)
{
    LPENUMOVERLAYZORDERSCALLBACKCONTEXT context = (LPENUMOVERLAYZORDERSCALLBACKCONTEXT)lpContext;

    DirectDrawSurfaceLogMethodCallbackValue(TRACEDEBUG, EnumOverlayZOrders, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));

    CONST HRESULT result = context->Callback(lpDDSurface, lpDDSurfaceDesc, context->Context);

    DirectDrawSurfaceLogMethodCallbackResultValue(TRACEDEBUGINFO, EnumOverlayZOrders, result, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));
}

DirectDrawSurface::DirectDrawSurface(AgentConstructorParameters(DirectDrawSurface))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectDrawSurface);
}

DirectDrawSurface::~DirectDrawSurface()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectDrawSurface);
}

HRESULT DirectDrawSurface::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectDrawSurfaceLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

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

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectDrawSurface::AddRef()
{
    DirectDrawSurfaceLogMethod(DEBUG, AddRef);
    DirectDrawSurfaceLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectDrawSurface::Release()
{
    DirectDrawSurfaceLogMethod(DEBUG, Release);
    DirectDrawSurfaceLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Attaches the specified z-buffer surface to this surface.
HRESULT DirectDrawSurface::AddAttachedSurface(LPDIRECTDRAWSURFACE lpDDSAttachedSurface)
{
    DirectDrawSurfaceLogMethodValue(TRACE, AddAttachedSurface, 1, (lpDDSAttachedSurface));

    AttemptAccessAgentValue(DirectDrawSurface, lpDDSAttachedSurface);

    CONST HRESULT result = this->State.Self->AddAttachedSurface(lpDDSAttachedSurface);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, AddAttachedSurface, result, 1, (ActivateAgent(DirectDrawSurface, lpDDSAttachedSurface)));
}

// This method is not currently implemented.
HRESULT DirectDrawSurface::AddOverlayDirtyRect(LPRECT lpRect)
{
    DirectDrawSurfaceLogMethodValue(TRACE, AddOverlayDirtyRect, 1, (lpRect));

    CONST HRESULT result = this->State.Self->AddOverlayDirtyRect(lpRect);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, AddOverlayDirtyRect, result, 1, (lpRect));
}

// Performs a bit block transfer (bitblt).
// This method does not support z-buffering or alpha blending during bitblt operations.
HRESULT DirectDrawSurface::Blt(LPRECT lpDestRect, LPDIRECTDRAWSURFACE lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx)
{
    DirectDrawSurfaceLogMethodValue(TRACE, Blt, 5, (lpDestRect, lpDDSrcSurface, lpSrcRect, dwFlags, lpDDBltFx));

    AttemptAccessAgentValue(DirectDrawSurface, lpDDSrcSurface);

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

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, Blt, result, 5, (lpDestRect, ActivateAgent(DirectDrawSurface, lpDDSrcSurface), lpSrcRect, dwFlags, lpDDBltFx));
}

// This method is not currently implemented.
HRESULT DirectDrawSurface::BltBatch(LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags)
{
    DirectDrawSurfaceLogMethodValue(TRACE, BltBatch, 3, (lpDDBltBatch, dwCount, dwFlags));

    if (lpDDBltBatch != NULL) { AttemptAccessAgentValue(DirectDrawSurface, lpDDBltBatch->lpDDSSrc); }

    CONST HRESULT result = this->State.Self->BltBatch(lpDDBltBatch, dwCount, dwFlags);

    if (lpDDBltBatch != NULL) { lpDDBltBatch->lpDDSSrc = ActivateAgent(DirectDrawSurface, lpDDBltBatch->lpDDSSrc); }

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, BltBatch, result, 3, (lpDDBltBatch, dwCount, dwFlags));
}

// Performs a source copy bitblt or transparent bitblt by using a source color key or destination color key.
HRESULT DirectDrawSurface::BltFast(DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans)
{
    DirectDrawSurfaceLogMethodValue(TRACE, BltFast, 5, (dwX, dwY, lpDDSrcSurface, lpSrcRect, dwTrans));

    AttemptAccessAgentValue(DirectDrawSurface, lpDDSrcSurface);

    CONST HRESULT result = this->State.Self->BltFast(dwX, dwY, lpDDSrcSurface, lpSrcRect, dwTrans);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, BltFast, result, 5, (dwX, dwY, ActivateAgent(DirectDrawSurface, lpDDSrcSurface), lpSrcRect, dwTrans));
}

// Detaches one or more attached surfaces.
HRESULT DirectDrawSurface::DeleteAttachedSurface(DWORD dwFlags, LPDIRECTDRAWSURFACE lpDDSAttachedSurface)
{
    DirectDrawSurfaceLogMethodValue(TRACE, DeleteAttachedSurface, 2, (dwFlags, lpDDSAttachedSurface));

    AttemptAccessAgentValue(DirectDrawSurface, lpDDSAttachedSurface);

    CONST HRESULT result = this->State.Self->DeleteAttachedSurface(dwFlags, lpDDSAttachedSurface);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, DeleteAttachedSurface, result, 2, (dwFlags, ActivateAgent(DirectDrawSurface, lpDDSAttachedSurface)));
}

// Enumerates all the surfaces that are attached to this surface.
HRESULT DirectDrawSurface::EnumAttachedSurfaces(LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback)
{
    DirectDrawSurfaceLogMethodValue(DEBUGINFO, EnumAttachedSurfaces, 2, (lpContext, lpEnumSurfacesCallback));

    if (lpEnumSurfacesCallback == NULL) { DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, EnumAttachedSurfaces, DDERR_INVALIDPARAMS, 2, (lpContext, lpEnumSurfacesCallback)); }

    ENUMATTACHEDSURFACESCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumSurfacesCallback = lpEnumSurfacesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumAttachedSurfaces(&context, EnumAttachedSurfacesCallback);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, EnumAttachedSurfaces, result, 2, (lpContext, lpEnumSurfacesCallback));
}

// Enumerates the overlay surfaces on the specified destination.
// You can enumerate the overlays in front-to-back or back-to-front order.
HRESULT DirectDrawSurface::EnumOverlayZOrders(DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpfnCallback)
{
    DirectDrawSurfaceLogMethodValue(DEBUGINFO, EnumOverlayZOrders, 3, (dwFlags, lpContext, lpfnCallback));

    if (lpfnCallback == NULL) { DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, EnumOverlayZOrders, DDERR_INVALIDPARAMS, 3, (dwFlags, lpContext, lpfnCallback)); }

    ENUMOVERLAYZORDERSCALLBACKCONTEXT context;

    context.Self = this;
    context.Callback = lpfnCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumOverlayZOrders(dwFlags, &context, EnumOverlayZOrdersCallback);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, EnumOverlayZOrders, result, 3, (dwFlags, lpContext, lpfnCallback));
}

// Makes the surface memory that is associated with the DDSCAPS_BACKBUFFER surface become associated with the front-buffer surface.
HRESULT DirectDrawSurface::Flip(LPDIRECTDRAWSURFACE lpDDSurfaceTargetOverride, DWORD dwFlags)
{
    DirectDrawSurfaceLogMethodValue(TRACE, Flip, 2, (lpDDSurfaceTargetOverride, dwFlags));

    AttemptAccessAgentValue(DirectDrawSurface, lpDDSurfaceTargetOverride);

    CONST HRESULT result = this->State.Self->Flip(lpDDSurfaceTargetOverride, dwFlags);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, Flip, result, 2, (ActivateAgent(DirectDrawSurface, lpDDSurfaceTargetOverride), dwFlags));
}

// Obtains the attached surface that has the specified capabilities,
// and increments the reference count of the retrieved interface.
HRESULT DirectDrawSurface::GetAttachedSurface(LPDDSCAPS lpDDSCaps, LPDIRECTDRAWSURFACE FAR* lplpDDAttachedSurface)
{
    DirectDrawSurfaceLogMethodValue(TRACE, GetAttachedSurface, 2, (lpDDSCaps, lplpDDAttachedSurface));

    CONST HRESULT result = this->State.Self->GetAttachedSurface(lpDDSCaps, lplpDDAttachedSurface);

    if (SUCCEEDED(result)) { *lplpDDAttachedSurface = ActivateAgentDelegate(DirectDrawSurface, *lplpDDAttachedSurface); }

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, GetAttachedSurface, result, 2, (lpDDSCaps, lplpDDAttachedSurface));
}

// Obtains status about a bit block transfer (bitblt) operation.
HRESULT DirectDrawSurface::GetBltStatus(DWORD dwFlags)
{
    DirectDrawSurfaceLogMethodValue(TRACE, GetBltStatus, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->GetBltStatus(dwFlags);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, GetBltStatus, result, 1, (dwFlags));
}

// Retrieves the capabilities of this surface.
// These capabilities are not necessarily related to the capabilities of the display device.
HRESULT DirectDrawSurface::GetCaps(LPDDSCAPS lpDDSCaps)
{
    DirectDrawSurfaceLogMethodValue(TRACE, GetCaps, 1, (lpDDSCaps));

    CONST HRESULT result = this->State.Self->GetCaps(lpDDSCaps);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, GetCaps, result, 1, (lpDDSCaps));
}

// Retrieves the DirectDrawClipper object that is associated with this surface,
// and increments the reference count of the returned clipper.
HRESULT DirectDrawSurface::GetClipper(LPDIRECTDRAWCLIPPER FAR* lplpDDClipper)
{
    DirectDrawSurfaceLogMethodValue(TRACE, GetClipper, 1, (lplpDDClipper));

    CONST HRESULT result = this->State.Self->GetClipper(lplpDDClipper);

    if (SUCCEEDED(result)) { *lplpDDClipper = ActivateAgentDelegate(DirectDrawClipper, *lplpDDClipper); }

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, GetClipper, result, 1, (lplpDDClipper));
}

// Retrieves the color key value for this surface.
HRESULT DirectDrawSurface::GetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey)
{
    DirectDrawSurfaceLogMethodValue(TRACE, GetColorKey, 2, (dwFlags, lpDDColorKey));

    CONST HRESULT result = this->State.Self->GetColorKey(dwFlags, lpDDColorKey);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, GetColorKey, result, 2, (dwFlags, lpDDColorKey));
}

// Creates a GDI-compatible handle of a device context for this surface.
HRESULT DirectDrawSurface::GetDC(HDC FAR* lphDC)
{
    DirectDrawSurfaceLogMethodValue(TRACE, GetDC, 1, (lphDC));

    CONST HRESULT result = this->State.Self->GetDC(lphDC);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, GetDC, result, 1, (lphDC));
}

// Retrieves status about whether this surface has finished its flipping process.
HRESULT DirectDrawSurface::GetFlipStatus(DWORD dwFlags)
{
    DirectDrawSurfaceLogMethodValue(TRACE, GetFlipStatus, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->GetFlipStatus(dwFlags);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, GetFlipStatus, result, 1, (dwFlags));
}

// Retrieves the display coordinates of this surface.
// This method is used on a visible, active overlay surface
// (that is, a surface that has the DDSCAPS_OVERLAY flag set).
HRESULT DirectDrawSurface::GetOverlayPosition(LPLONG lplX, LPLONG lplY)
{
    DirectDrawSurfaceLogMethodValue(TRACE, GetOverlayPosition, 2, (lplX, lplY));

    CONST HRESULT result = this->State.Self->GetOverlayPosition(lplX, lplY);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, GetOverlayPosition, result, 2, (lplX, lplY));
}

// Retrieves the DirectDrawPalette object that is associated with this surface,
// and increments the reference count of the returned palette.
HRESULT DirectDrawSurface::GetPalette(LPDIRECTDRAWPALETTE FAR* lplpDDPalette)
{
    DirectDrawSurfaceLogMethodValue(TRACE, GetPalette, 1, (lplpDDPalette));

    CONST HRESULT result = this->State.Self->GetPalette(lplpDDPalette);

    if (SUCCEEDED(result)) { *lplpDDPalette = ActivateAgentDelegate(DirectDrawPalette, *lplpDDPalette); }

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, GetPalette, result, 1, (lplpDDPalette));
}

// Retrieves the color and pixel format of this surface.
HRESULT DirectDrawSurface::GetPixelFormat(LPDDPIXELFORMAT lpDDPixelFormat)
{
    DirectDrawSurfaceLogMethodValue(TRACE, GetPixelFormat, 1, (lpDDPixelFormat));

    CONST HRESULT result = this->State.Self->GetPixelFormat(lpDDPixelFormat);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, GetPixelFormat, result, 1, (lpDDPixelFormat));
}

// Retrieves a description of this surface in its current condition.
HRESULT DirectDrawSurface::GetSurfaceDesc(LPDDSURFACEDESC lpDDSurfaceDesc)
{
    DirectDrawSurfaceLogMethodValue(TRACE, GetSurfaceDesc, 1, (lpDDSurfaceDesc));

    CONST HRESULT result = this->State.Self->GetSurfaceDesc(lpDDSurfaceDesc);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, GetSurfaceDesc, result, 1, (lpDDSurfaceDesc));
}

// Initializes a DirectDrawSurface object.
HRESULT DirectDrawSurface::Initialize(LPDIRECTDRAW lpDD, LPDDSURFACEDESC lpDDSurfaceDesc)
{
    DirectDrawSurfaceLogMethodValue(TRACE, Initialize, 2, (lpDD, lpDDSurfaceDesc));

    AttemptAccessAgentValue(DirectDraw, lpDD);

    CONST HRESULT result = this->State.Self->Initialize(lpDD, lpDDSurfaceDesc);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 2, (ActivateAgent(DirectDraw, lpDD), lpDDSurfaceDesc));
}

// Determines whether the surface memory that is associated with a DirectDrawSurface object has been freed.
HRESULT DirectDrawSurface::IsLost()
{
    DirectDrawSurfaceLogMethod(DEBUG, IsLost);

    CONST HRESULT result = this->State.Self->IsLost();

    DirectDrawSurfaceLogMethodResult(DEBUGINFO, IsLost, result);
}

// Obtains a pointer to the surface memory.
HRESULT DirectDrawSurface::Lock(LPRECT lpDestRect, LPDDSURFACEDESC lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent)
{
    DirectDrawSurfaceLogMethodValue(TRACE, Lock, 4, (lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent));

    CONST HRESULT result = this->State.Self->Lock(lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, Lock, result, 4, (lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent));
}

// Releases the handle of a device context that was previously obtained by using the IDirectDrawSurface::GetDC method.
HRESULT DirectDrawSurface::ReleaseDC(HDC hDC)
{
    DirectDrawSurfaceLogMethodValue(TRACE, ReleaseDC, 1, (hDC));

    CONST HRESULT result = this->State.Self->ReleaseDC(hDC);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, ReleaseDC, result, 1, (hDC));
}

// Restores a surface that has been lost.
// This occurs when the surface memory that is associated with the DirectDrawSurface object has been freed.
HRESULT DirectDrawSurface::Restore()
{
    DirectDrawSurfaceLogMethod(DEBUG, Restore);

    CONST HRESULT result = this->State.Self->Restore();

    DirectDrawSurfaceLogMethodResult(DEBUGINFO, Restore, result);
}

// Attaches a clipper object to, or deletes one from, this surface.
HRESULT DirectDrawSurface::SetClipper(LPDIRECTDRAWCLIPPER lpDDClipper)
{
    DirectDrawSurfaceLogMethodValue(TRACE, SetClipper, 1, (lpDDClipper));

    AttemptAccessAgentValue(DirectDrawClipper, lpDDClipper);

    CONST HRESULT result = this->State.Self->SetClipper(lpDDClipper);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, SetClipper, result, 1, (ActivateAgent(DirectDrawClipper, lpDDClipper)));
}

// Sets the color key value for the DirectDrawSurface object if the hardware supports color keys on a per-surface basis.
HRESULT DirectDrawSurface::SetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey)
{
    DirectDrawSurfaceLogMethodValue(TRACE, SetColorKey, 2, (dwFlags, lpDDColorKey));

    CONST HRESULT result = this->State.Self->SetColorKey(dwFlags, lpDDColorKey);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, SetColorKey, result, 2, (dwFlags, lpDDColorKey));
}

// Changes the display coordinates of an overlay surface.
HRESULT DirectDrawSurface::SetOverlayPosition(LONG lX, LONG lY)
{
    DirectDrawSurfaceLogMethodValue(TRACE, SetOverlayPosition, 2, (lX, lY));

    CONST HRESULT result = this->State.Self->SetOverlayPosition(lX, lY);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, SetOverlayPosition, result, 2, (lX, lY));
}

// Attaches a palette object to (or detaches one from) a surface.
// The surface uses this palette for all subsequent operations.
// The palette change takes place immediately, without regard to refresh timing.
HRESULT DirectDrawSurface::SetPalette(LPDIRECTDRAWPALETTE lpDDPalette)
{
    DirectDrawSurfaceLogMethodValue(TRACE, SetPalette, 1, (lpDDPalette));

    AttemptAccessAgentValue(DirectDrawPalette, lpDDPalette);

    CONST HRESULT result = this->State.Self->SetPalette(lpDDPalette);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, SetPalette, result, 1, (ActivateAgent(DirectDrawPalette, lpDDPalette)));
}

// Notifies DirectDraw that the direct surface manipulations are complete.
HRESULT DirectDrawSurface::Unlock(LPVOID lpSurfaceData)
{
    DirectDrawSurfaceLogMethodValue(TRACE, Unlock, 1, (lpSurfaceData));

    CONST HRESULT result = this->State.Self->Unlock(lpSurfaceData);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, Unlock, result, 1, (lpSurfaceData));
}

// Repositions or modifies the visual attributes of an overlay surface.
// These surfaces must have the DDSCAPS_OVERLAY flag set.
HRESULT DirectDrawSurface::UpdateOverlay(LPRECT lpSrcRect, LPDIRECTDRAWSURFACE lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx)
{
    DirectDrawSurfaceLogMethodValue(TRACE, UpdateOverlay, 5, (lpSrcRect, lpDDDestSurface, lpDestRect, dwFlags, lpDDOverlayFx));

    AttemptAccessAgentValue(DirectDrawSurface, lpDDDestSurface);

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

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, UpdateOverlay, result, 5, (lpSrcRect, ActivateAgent(DirectDrawSurface, lpDDDestSurface), lpDestRect, dwFlags, lpDDOverlayFx));
}

// This method is not currently implemented.
HRESULT DirectDrawSurface::UpdateOverlayDisplay(DWORD dwFlags)
{
    DirectDrawSurfaceLogMethodValue(TRACE, UpdateOverlayDisplay, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->UpdateOverlayDisplay(dwFlags);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, UpdateOverlayDisplay, result, 1, (dwFlags));
}

// Sets the z-order of an overlay.
HRESULT DirectDrawSurface::UpdateOverlayZOrder(DWORD dwFlags, LPDIRECTDRAWSURFACE lpDDSReference)
{
    DirectDrawSurfaceLogMethodValue(TRACE, UpdateOverlayZOrder, 2, (dwFlags, lpDDSReference));

    AttemptAccessAgentValue(DirectDrawSurface, lpDDSReference);

    CONST HRESULT result = this->State.Self->UpdateOverlayZOrder(dwFlags, lpDDSReference);

    DirectDrawSurfaceLogMethodResultValue(TRACEDEBUGINFO, UpdateOverlayZOrder, result, 2, (dwFlags, ActivateAgent(DirectDrawSurface, lpDDSReference)));
}