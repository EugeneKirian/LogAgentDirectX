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
#include "DirectDraw7.hxx"
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
#include <DirectDrawSurface7Logger.hxx>

#define DirectDrawSurface7LogMethod(L, M) AgentLogMethod(L, DirectDrawSurface7, M)
#define DirectDrawSurface7LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectDrawSurface7, M, C, PARAMS)

#define DirectDrawSurface7LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectDrawSurface7, AddRef, R)
#define DirectDrawSurface7LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectDrawSurface7, Release, R)

#define DirectDrawSurface7LogMethodResult(L, M, R) AgentLogMethodResult(L, DirectDrawSurface7, M, R)
#define DirectDrawSurface7LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectDrawSurface7, M, R, C, PARAMS)

#define DirectDrawSurface7LogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, DirectDrawSurface7, M, C, PARAMS)
#define DirectDrawSurface7LogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, DirectDrawSurface7, M, R, C, PARAMS)

typedef struct EnumAttachedSurfacesCallbackContext
{
    DirectDrawSurface7* Self;
    LPLOGGER Logger;
    LPDDENUMSURFACESCALLBACK7 EnumSurfacesCallback;
    LPVOID Context;
} ENUMATTACHEDSURFACESCALLBACKCONTEXT, * LPENUMATTACHEDSURFACESCALLBACKCONTEXT;

static HRESULT CALLBACK EnumAttachedSurfacesCallback(LPDIRECTDRAWSURFACE7 lpDDSurface, LPDDSURFACEDESC2 lpDDSurfaceDesc, LPVOID lpContext)
{
    LPENUMATTACHEDSURFACESCALLBACKCONTEXT context = (LPENUMATTACHEDSURFACESCALLBACKCONTEXT)lpContext;

    DirectDrawSurface7LogMethodCallbackValue(DEBUG, EnumAttachedSurfaces, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));

    CONST HRESULT result = context->EnumSurfacesCallback(lpDDSurface, lpDDSurfaceDesc, context->Context);

    DirectDrawSurface7LogMethodCallbackResultValue(DEBUGINFO, EnumAttachedSurfaces, result, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));
}

typedef struct EnumOverlayZOrdersCallbackContext
{
    DirectDrawSurface7* Self;
    LPLOGGER Logger;
    LPDDENUMSURFACESCALLBACK7 Callback;
    LPVOID Context;
} ENUMOVERLAYZORDERSCALLBACKCONTEXT, * LPENUMOVERLAYZORDERSCALLBACKCONTEXT;

static HRESULT CALLBACK EnumOverlayZOrdersCallback(LPDIRECTDRAWSURFACE7 lpDDSurface, LPDDSURFACEDESC2 lpDDSurfaceDesc, LPVOID lpContext)
{
    LPENUMOVERLAYZORDERSCALLBACKCONTEXT context = (LPENUMOVERLAYZORDERSCALLBACKCONTEXT)lpContext;

    DirectDrawSurface7LogMethodCallbackValue(DEBUG, EnumOverlayZOrders, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));

    CONST HRESULT result = context->Callback(lpDDSurface, lpDDSurfaceDesc, context->Context);

    DirectDrawSurface7LogMethodCallbackResultValue(DEBUGINFO, EnumOverlayZOrders, result, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));
}

DirectDrawSurface7::DirectDrawSurface7(AgentConstructorParameters(DirectDrawSurface7))
{
    AgentConstructor();
    AgentLogConstructor(DEBUG, DirectDrawSurface7);
}

DirectDrawSurface7::~DirectDrawSurface7()
{
    AgentDestructor();
    AgentLogDestructor(DEBUG, DirectDrawSurface7);
}

HRESULT DirectDrawSurface7::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectDrawSurface7LogMethodValue(DEBUG, QueryInterface, 2, (riid, ppvObj));

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

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectDrawSurface7::AddRef()
{
    DirectDrawSurface7LogMethod(DEBUG, AddRef);
    DirectDrawSurface7LogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectDrawSurface7::Release()
{
    DirectDrawSurface7LogMethod(DEBUG, Release);
    DirectDrawSurface7LogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Attaches the specified z-buffer surface to this surface.
HRESULT DirectDrawSurface7::AddAttachedSurface(LPDIRECTDRAWSURFACE7 lpDDSAttachedSurface)
{
    DirectDrawSurface7LogMethodValue(DEBUG, AddAttachedSurface, 1, (lpDDSAttachedSurface));

    AttemptAccessAgentValue(DirectDrawSurface7, lpDDSAttachedSurface);

    CONST HRESULT result = this->State.Self->AddAttachedSurface(lpDDSAttachedSurface);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, AddAttachedSurface, result, 1, (ActivateAgent(DirectDrawSurface7, lpDDSAttachedSurface)));
}

// This method is not currently implemented.
HRESULT DirectDrawSurface7::AddOverlayDirtyRect(LPRECT lpRect)
{
    DirectDrawSurface7LogMethodValue(DEBUG, AddOverlayDirtyRect, 1, (lpRect));

    CONST HRESULT result = this->State.Self->AddOverlayDirtyRect(lpRect);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, AddOverlayDirtyRect, result, 1, (lpRect));
}

// Performs a bit block transfer (bitblt).
// This method does not support z-buffering or alpha blending during bitblt operations.
HRESULT DirectDrawSurface7::Blt(LPRECT lpDestRect, LPDIRECTDRAWSURFACE7 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx)
{
    DirectDrawSurface7LogMethodValue(DEBUG, Blt, 5, (lpDestRect, lpDDSrcSurface, lpSrcRect, dwFlags, lpDDBltFx));

    AttemptAccessAgentValue(DirectDrawSurface7, lpDDSrcSurface);

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

        if (dwFlags & DDBLT_ALPHASRCSURFACEOVERRIDE) lpDDBltFx->lpDDSAlphaSrc = ActivateAgent(DirectDrawSurface, lpDDBltFx->lpDDSAlphaSrc);

        if (dwFlags & DDBLT_PRIVATE_ALIASPATTERN) { lpDDBltFx->lpDDSPattern = ActivateAgent(DirectDrawSurface, lpDDBltFx->lpDDSPattern); }
    }

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, Blt, result, 5, (lpDestRect, ActivateAgent(DirectDrawSurface7, lpDDSrcSurface), lpSrcRect, dwFlags, lpDDBltFx));
}

// This method is not currently implemented.
HRESULT DirectDrawSurface7::BltBatch(LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags)
{
    if (lpDDBltBatch != NULL) { AttemptAccessAgentValue(DirectDrawSurface, lpDDBltBatch->lpDDSSrc); }

    DirectDrawSurface7LogMethodValue(DEBUG, BltBatch, 3, (lpDDBltBatch, dwCount, dwFlags));

    CONST HRESULT result = this->State.Self->BltBatch(lpDDBltBatch, dwCount, dwFlags);

    if (lpDDBltBatch != NULL) { lpDDBltBatch->lpDDSSrc = ActivateAgent(DirectDrawSurface, lpDDBltBatch->lpDDSSrc); }

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, BltBatch, result, 3, (lpDDBltBatch, dwCount, dwFlags));
}

// Performs a source copy bitblt or transparent bitblt by using a source color key or destination color key.
HRESULT DirectDrawSurface7::BltFast(DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE7 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans)
{
    DirectDrawSurface7LogMethodValue(DEBUG, BltFast, 5, (dwX, dwY, lpDDSrcSurface, lpSrcRect, dwTrans));

    AttemptAccessAgentValue(DirectDrawSurface7, lpDDSrcSurface);

    CONST HRESULT result = this->State.Self->BltFast(dwX, dwY, lpDDSrcSurface, lpSrcRect, dwTrans);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, BltFast, result, 5, (dwX, dwY, ActivateAgent(DirectDrawSurface7, lpDDSrcSurface), lpSrcRect, dwTrans));
}

// Detaches one or more attached surfaces.
HRESULT DirectDrawSurface7::DeleteAttachedSurface(DWORD dwFlags, LPDIRECTDRAWSURFACE7 lpDDSAttachedSurface)
{
    DirectDrawSurface7LogMethodValue(DEBUG, DeleteAttachedSurface, 2, (dwFlags, lpDDSAttachedSurface));

    AttemptAccessAgentValue(DirectDrawSurface7, lpDDSAttachedSurface);

    CONST HRESULT result = this->State.Self->DeleteAttachedSurface(dwFlags, lpDDSAttachedSurface);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, DeleteAttachedSurface, result, 2, (dwFlags, ActivateAgent(DirectDrawSurface7, lpDDSAttachedSurface)));
}

// Enumerates all the surfaces that are attached to this surface.
HRESULT DirectDrawSurface7::EnumAttachedSurfaces(LPVOID lpContext, LPDDENUMSURFACESCALLBACK7 lpEnumSurfacesCallback)
{
    DirectDrawSurface7LogMethodValue(DEBUGINFO, EnumAttachedSurfaces, 2, (lpContext, lpEnumSurfacesCallback));

    if (lpEnumSurfacesCallback == NULL) { DirectDrawSurface7LogMethodResultValue(DEBUGINFO, EnumAttachedSurfaces, DDERR_INVALIDPARAMS, 2, (lpContext, lpEnumSurfacesCallback)); }

    ENUMATTACHEDSURFACESCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumSurfacesCallback = lpEnumSurfacesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumAttachedSurfaces(&context, EnumAttachedSurfacesCallback);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, EnumAttachedSurfaces, result, 2, (lpContext, lpEnumSurfacesCallback));
}

// Enumerates the overlay surfaces on the specified destination.
// You can enumerate the overlays in front-to-back or back-to-front order.
HRESULT DirectDrawSurface7::EnumOverlayZOrders(DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK7 lpfnCallback)
{
    DirectDrawSurface7LogMethodValue(DEBUGINFO, EnumOverlayZOrders, 3, (dwFlags, lpContext, lpfnCallback));

    if (lpfnCallback == NULL) { DirectDrawSurface7LogMethodResultValue(DEBUGINFO, EnumOverlayZOrders, DDERR_INVALIDPARAMS, 3, (dwFlags, lpContext, lpfnCallback)); }

    ENUMOVERLAYZORDERSCALLBACKCONTEXT context;

    context.Self = this;
    context.Callback = lpfnCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumOverlayZOrders(dwFlags, &context, EnumOverlayZOrdersCallback);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, EnumOverlayZOrders, result, 3, (dwFlags, lpContext, lpfnCallback));
}

// Makes the surface memory that is associated with the DDSCAPS_BACKBUFFER surface become associated with the front-buffer surface.
HRESULT DirectDrawSurface7::Flip(LPDIRECTDRAWSURFACE7 lpDDSurfaceTargetOverride, DWORD dwFlags)
{
    DirectDrawSurface7LogMethodValue(DEBUG, Flip, 2, (lpDDSurfaceTargetOverride, dwFlags));

    AttemptAccessAgentValue(DirectDrawSurface7, lpDDSurfaceTargetOverride);

    CONST HRESULT result = this->State.Self->Flip(lpDDSurfaceTargetOverride, dwFlags);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, Flip, result, 2, (ActivateAgent(DirectDrawSurface7, lpDDSurfaceTargetOverride), dwFlags));
}

// Obtains the attached surface that has the specified capabilities,
// and increments the reference count of the retrieved interface.
HRESULT DirectDrawSurface7::GetAttachedSurface(LPDDSCAPS2 lpDDSCaps, LPDIRECTDRAWSURFACE7 FAR* lplpDDAttachedSurface)
{
    DirectDrawSurface7LogMethodValue(DEBUG, GetAttachedSurface, 2, (lpDDSCaps, lplpDDAttachedSurface));

    CONST HRESULT result = this->State.Self->GetAttachedSurface(lpDDSCaps, lplpDDAttachedSurface);

    if (SUCCEEDED(result)) { *lplpDDAttachedSurface = ActivateAgentDelegate(DirectDrawSurface7, *lplpDDAttachedSurface); }

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, GetAttachedSurface, result, 2, (lpDDSCaps, lplpDDAttachedSurface));
}

// Obtains status about a bit block transfer (bitblt) operation.
HRESULT DirectDrawSurface7::GetBltStatus(DWORD dwFlags)
{
    DirectDrawSurface7LogMethodValue(DEBUG, GetBltStatus, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->GetBltStatus(dwFlags);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, GetBltStatus, result, 1, (dwFlags));
}

// Retrieves the capabilities of this surface.
// These capabilities are not necessarily related to the capabilities of the display device.
HRESULT DirectDrawSurface7::GetCaps(LPDDSCAPS2 lpDDSCaps)
{
    DirectDrawSurface7LogMethodValue(DEBUG, GetCaps, 1, (lpDDSCaps));

    CONST HRESULT result = this->State.Self->GetCaps(lpDDSCaps);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, GetCaps, result, 1, (lpDDSCaps));
}

// Retrieves the DirectDrawClipper object that is associated with this surface,
// and increments the reference count of the returned clipper.
HRESULT DirectDrawSurface7::GetClipper(LPDIRECTDRAWCLIPPER FAR* lplpDDClipper)
{
    DirectDrawSurface7LogMethodValue(DEBUG, GetClipper, 1, (lplpDDClipper));

    CONST HRESULT result = this->State.Self->GetClipper(lplpDDClipper);

    if (SUCCEEDED(result)) { *lplpDDClipper = ActivateAgentDelegate(DirectDrawClipper, *lplpDDClipper); }

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, GetClipper, result, 1, (lplpDDClipper));
}

// Retrieves the color key value for this surface.
HRESULT DirectDrawSurface7::GetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey)
{
    DirectDrawSurface7LogMethodValue(DEBUG, GetColorKey, 2, (dwFlags, lpDDColorKey));

    CONST HRESULT result = this->State.Self->GetColorKey(dwFlags, lpDDColorKey);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, GetColorKey, result, 2, (dwFlags, lpDDColorKey));
}

// Creates a GDI-compatible handle of a device context for this surface.
HRESULT DirectDrawSurface7::GetDC(HDC FAR* lphDC)
{
    DirectDrawSurface7LogMethodValue(DEBUG, GetDC, 1, (lphDC));

    CONST HRESULT result = this->State.Self->GetDC(lphDC);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, GetDC, result, 1, (lphDC));
}

// Retrieves status about whether this surface has finished its flipping process.
HRESULT DirectDrawSurface7::GetFlipStatus(DWORD dwFlags)
{
    DirectDrawSurface7LogMethodValue(DEBUG, GetFlipStatus, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->GetFlipStatus(dwFlags);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, GetFlipStatus, result, 1, (dwFlags));
}

// Retrieves the display coordinates of this surface.
// This method is used on a visible, active overlay surface
// (that is, a surface that has the DDSCAPS_OVERLAY flag set).
HRESULT DirectDrawSurface7::GetOverlayPosition(LPLONG lplX, LPLONG lplY)
{
    DirectDrawSurface7LogMethodValue(DEBUG, GetOverlayPosition, 2, (lplX, lplY));

    CONST HRESULT result = this->State.Self->GetOverlayPosition(lplX, lplY);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, GetOverlayPosition, result, 2, (lplX, lplY));
}

// Retrieves the DirectDrawPalette object that is associated with this surface,
// and increments the reference count of the returned palette.
HRESULT DirectDrawSurface7::GetPalette(LPDIRECTDRAWPALETTE FAR* lplpDDPalette)
{
    DirectDrawSurface7LogMethodValue(DEBUG, GetPalette, 1, (lplpDDPalette));

    CONST HRESULT result = this->State.Self->GetPalette(lplpDDPalette);

    if (SUCCEEDED(result)) { *lplpDDPalette = ActivateAgentDelegate(DirectDrawPalette, *lplpDDPalette); }

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, GetPalette, result, 1, (lplpDDPalette));
}

// Retrieves the color and pixel format of this surface.
HRESULT DirectDrawSurface7::GetPixelFormat(LPDDPIXELFORMAT lpDDPixelFormat)
{
    DirectDrawSurface7LogMethodValue(DEBUG, GetPixelFormat, 1, (lpDDPixelFormat));

    CONST HRESULT result = this->State.Self->GetPixelFormat(lpDDPixelFormat);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, GetPixelFormat, result, 1, (lpDDPixelFormat));
}

// Retrieves a description of this surface in its current condition.
HRESULT DirectDrawSurface7::GetSurfaceDesc(LPDDSURFACEDESC2 lpDDSurfaceDesc)
{
    DirectDrawSurface7LogMethodValue(DEBUG, GetSurfaceDesc, 1, (lpDDSurfaceDesc));

    CONST HRESULT result = this->State.Self->GetSurfaceDesc(lpDDSurfaceDesc);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, GetSurfaceDesc, result, 1, (lpDDSurfaceDesc));
}

// Initializes a DirectDrawSurface7 object.
HRESULT DirectDrawSurface7::Initialize(LPDIRECTDRAW lpDD, LPDDSURFACEDESC2 lpDDSurfaceDesc)
{
    DirectDrawSurface7LogMethodValue(DEBUG, Initialize, 2, (lpDD, lpDDSurfaceDesc));

    AttemptAccessAgentValue(DirectDraw, lpDD);

    CONST HRESULT result = this->State.Self->Initialize(lpDD, lpDDSurfaceDesc);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, Initialize, result, 2, (ActivateAgent(DirectDraw, lpDD), lpDDSurfaceDesc));
}

// Determines whether the surface memory that is associated with a DirectDrawSurface7 object has been freed.
HRESULT DirectDrawSurface7::IsLost()
{
    DirectDrawSurface7LogMethod(DEBUG, IsLost);

    CONST HRESULT result = this->State.Self->IsLost();

    DirectDrawSurface7LogMethodResult(DEBUGINFO, IsLost, result);
}

// Obtains a pointer to the surface memory.
HRESULT DirectDrawSurface7::Lock(LPRECT lpDestRect, LPDDSURFACEDESC2 lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent)
{
    DirectDrawSurface7LogMethodValue(DEBUG, Lock, 4, (lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent));

    CONST HRESULT result = this->State.Self->Lock(lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, Lock, result, 4, (lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent));
}

// Releases the handle of a device context that was previously obtained by using the IDirectDrawSurface7::GetDC method.
HRESULT DirectDrawSurface7::ReleaseDC(HDC hDC)
{
    DirectDrawSurface7LogMethodValue(DEBUG, ReleaseDC, 1, (hDC));

    CONST HRESULT result = this->State.Self->ReleaseDC(hDC);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, ReleaseDC, result, 1, (hDC));
}

// Restores a surface that has been lost.
// This occurs when the surface memory that is associated with the DirectDrawSurface7 object has been freed.
HRESULT DirectDrawSurface7::Restore()
{
    DirectDrawSurface7LogMethod(DEBUG, Restore);

    CONST HRESULT result = this->State.Self->Restore();

    DirectDrawSurface7LogMethodResult(DEBUGINFO, Restore, result);
}

// Attaches a clipper object to, or deletes one from, this surface.
HRESULT DirectDrawSurface7::SetClipper(LPDIRECTDRAWCLIPPER lpDDClipper)
{
    DirectDrawSurface7LogMethodValue(DEBUG, SetClipper, 1, (lpDDClipper));

    AttemptAccessAgentValue(DirectDrawClipper, lpDDClipper);

    CONST HRESULT result = this->State.Self->SetClipper(lpDDClipper);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, SetClipper, result, 1, (ActivateAgent(DirectDrawClipper, lpDDClipper)));
}

// Sets the color key value for the DirectDrawSurface7 object if the hardware supports color keys on a per-surface basis.
HRESULT DirectDrawSurface7::SetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey)
{
    DirectDrawSurface7LogMethodValue(DEBUG, SetColorKey, 2, (dwFlags, lpDDColorKey));

    CONST HRESULT result = this->State.Self->SetColorKey(dwFlags, lpDDColorKey);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, SetColorKey, result, 2, (dwFlags, lpDDColorKey));
}

// Changes the display coordinates of an overlay surface.
HRESULT DirectDrawSurface7::SetOverlayPosition(LONG lX, LONG lY)
{
    DirectDrawSurface7LogMethodValue(DEBUG, SetOverlayPosition, 2, (lX, lY));

    CONST HRESULT result = this->State.Self->SetOverlayPosition(lX, lY);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, SetOverlayPosition, result, 2, (lX, lY));
}

// Attaches a palette object to (or detaches one from) a surface.
// The surface uses this palette for all subsequent operations.
// The palette change takes place immediately, without regard to refresh timing.
HRESULT DirectDrawSurface7::SetPalette(LPDIRECTDRAWPALETTE lpDDPalette)
{
    DirectDrawSurface7LogMethodValue(DEBUG, SetPalette, 1, (lpDDPalette));

    AttemptAccessAgentValue(DirectDrawPalette, lpDDPalette);

    CONST HRESULT result = this->State.Self->SetPalette(lpDDPalette);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, SetPalette, result, 1, (ActivateAgent(DirectDrawPalette, lpDDPalette)));
}

// Notifies DirectDraw that the direct surface manipulations are complete.
HRESULT DirectDrawSurface7::Unlock(LPRECT lpRect)
{
    DirectDrawSurface7LogMethodValue(DEBUG, Unlock, 1, (lpRect));

    CONST HRESULT result = this->State.Self->Unlock(lpRect);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, Unlock, result, 1, (lpRect));
}

// Repositions or modifies the visual attributes of an overlay surface.
// These surfaces must have the DDSCAPS_OVERLAY flag set.
HRESULT DirectDrawSurface7::UpdateOverlay(LPRECT lpSrcRect, LPDIRECTDRAWSURFACE7 lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx)
{
    DirectDrawSurface7LogMethodValue(DEBUG, UpdateOverlay, 5, (lpSrcRect, lpDDDestSurface, lpDestRect, dwFlags, lpDDOverlayFx));

    AttemptAccessAgentValue(DirectDrawSurface7, lpDDDestSurface);

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

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, UpdateOverlay, result, 5, (lpSrcRect, ActivateAgent(DirectDrawSurface7, lpDDDestSurface), lpDestRect, dwFlags, lpDDOverlayFx));
}

// This method is not currently implemented.
HRESULT DirectDrawSurface7::UpdateOverlayDisplay(DWORD dwFlags)
{
    DirectDrawSurface7LogMethodValue(DEBUG, UpdateOverlayDisplay, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->UpdateOverlayDisplay(dwFlags);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, UpdateOverlayDisplay, result, 1, (dwFlags));
}

// Sets the z-order of an overlay.
HRESULT DirectDrawSurface7::UpdateOverlayZOrder(DWORD dwFlags, LPDIRECTDRAWSURFACE7 lpDDSReference)
{
    DirectDrawSurface7LogMethodValue(DEBUG, UpdateOverlayZOrder, 2, (dwFlags, lpDDSReference));

    AttemptAccessAgentValue(DirectDrawSurface7, lpDDSReference);

    CONST HRESULT result = this->State.Self->UpdateOverlayZOrder(dwFlags, lpDDSReference);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, UpdateOverlayZOrder, result, 2, (dwFlags, ActivateAgent(DirectDrawSurface7, lpDDSReference)));
}

// Retrieves an interface to the DirectDraw object that was used to create this surface.
HRESULT DirectDrawSurface7::GetDDInterface(LPVOID FAR* lplpDD)
{
    DirectDrawSurface7LogMethodValue(DEBUG, GetDDInterface, 1, (lplpDD));

    CONST HRESULT result = this->State.Self->GetDDInterface(lplpDD);

    if (SUCCEEDED(result)) { *lplpDD = ActivateAgentDelegate(DirectDraw7, *lplpDD); }

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, GetDDInterface, result, 1, (lplpDD));
}

// Prevents a system-memory surface from being paged out while a bit block transfer (bitblt) operation
// that uses direct memory access (DMA) transfers to or from system memory is in progress.
HRESULT DirectDrawSurface7::PageLock(DWORD dwFlags)
{
    DirectDrawSurface7LogMethodValue(DEBUG, PageLock, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->PageLock(dwFlags);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, PageLock, result, 1, (dwFlags));
}

// Unlocks a system-memory surface, which then allows it to be paged out.
HRESULT DirectDrawSurface7::PageUnlock(DWORD dwFlags)
{
    DirectDrawSurface7LogMethodValue(DEBUG, PageUnlock, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->PageUnlock(dwFlags);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, PageUnlock, result, 1, (dwFlags));
}

// Sets the characteristics of an existing surface.
HRESULT DirectDrawSurface7::SetSurfaceDesc(LPDDSURFACEDESC2 lpDDSurfaceDesc, DWORD dwFlags)
{
    DirectDrawSurface7LogMethodValue(DEBUG, SetSurfaceDesc, 2, (lpDDSurfaceDesc, dwFlags));

    CONST HRESULT result = this->State.Self->SetSurfaceDesc(lpDDSurfaceDesc, dwFlags);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, SetSurfaceDesc, result, 2, (lpDDSurfaceDesc, dwFlags));
}

// Associates data with the surface that is intended for use by the application, not by DirectDraw.
// Data is passed by value, and multiple sets of data can be associated with a single surface.
HRESULT DirectDrawSurface7::SetPrivateData(REFGUID riid, LPVOID lpData, DWORD dwDataSize, DWORD dwFlags)
{
    DirectDrawSurface7LogMethodValue(DEBUG, SetPrivateData, 4, (riid, lpData, dwDataSize, dwFlags));

    CONST HRESULT result = this->State.Self->SetPrivateData(riid, lpData, dwDataSize, dwFlags);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, SetPrivateData, result, 4, (riid, lpData, dwDataSize, dwFlags));
}

// Copies the private data that is associated with this surface to a provided buffer.
HRESULT DirectDrawSurface7::GetPrivateData(REFGUID riid, LPVOID lpBuffer, LPDWORD lpdwBufferSize)
{
    DirectDrawSurface7LogMethodValue(DEBUG, GetPrivateData, 3, (riid, lpBuffer, lpdwBufferSize));

    CONST HRESULT result = this->State.Self->GetPrivateData(riid, lpBuffer, lpdwBufferSize);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, GetPrivateData, result, 3, (riid, lpBuffer, lpdwBufferSize));
}

// Frees the specified private data that is associated with this surface.
HRESULT DirectDrawSurface7::FreePrivateData(REFGUID riid)
{
    DirectDrawSurface7LogMethodValue(DEBUG, FreePrivateData, 1, (riid));

    CONST HRESULT result = this->State.Self->FreePrivateData(riid);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, FreePrivateData, result, 1, (riid));
}

// Retrieves the current uniqueness value for this surface.
HRESULT DirectDrawSurface7::GetUniquenessValue(LPDWORD lpdwValue)
{
    DirectDrawSurface7LogMethodValue(DEBUG, GetUniquenessValue, 1, (lpdwValue));

    CONST HRESULT result = this->State.Self->GetUniquenessValue(lpdwValue);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, GetUniquenessValue, result, 1, (lpdwValue));
}

// Manually updates the uniqueness value for this surface.
HRESULT DirectDrawSurface7::ChangeUniquenessValue()
{
    DirectDrawSurface7LogMethod(DEBUG, ChangeUniquenessValue);

    CONST HRESULT result = this->State.Self->ChangeUniquenessValue();

    DirectDrawSurface7LogMethodResult(DEBUGINFO, ChangeUniquenessValue, result);
}

// Assigns the texture-management priority for this texture. This method succeeds only on managed textures.
HRESULT DirectDrawSurface7::SetPriority(DWORD dwPriority)
{
    DirectDrawSurface7LogMethodValue(DEBUG, SetPriority, 1, (dwPriority));

    CONST HRESULT result = this->State.Self->SetPriority(dwPriority);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, SetPriority, result, 1, (dwPriority));
}

// Retrieves the texture-management priority for this texture. This method succeeds only on managed textures.
HRESULT DirectDrawSurface7::GetPriority(LPDWORD lpdwPriority)
{
    DirectDrawSurface7LogMethodValue(DEBUG, GetPriority, 1, (lpdwPriority));

    CONST HRESULT result = this->State.Self->GetPriority(lpdwPriority);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, GetPriority, result, 1, (lpdwPriority));
}

// Sets the maximum level of detail (LOD) for a managed mipmap surface. This method succeeds only on managed textures.
HRESULT DirectDrawSurface7::SetLOD(DWORD dwMaxLOD)
{
    DirectDrawSurface7LogMethodValue(DEBUG, SetLOD, 1, (dwMaxLOD));

    CONST HRESULT result = this->State.Self->SetLOD(dwMaxLOD);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, SetLOD, result, 1, (dwMaxLOD));
}

// Retrieves the maximum level of detail (LOD) currently set for a managed mipmap surface. This method succeeds only on managed textures.
HRESULT DirectDrawSurface7::GetLOD(LPDWORD lpdwMaxLOD)
{
    DirectDrawSurface7LogMethodValue(DEBUG, GetLOD, 1, (lpdwMaxLOD));

    CONST HRESULT result = this->State.Self->GetLOD(lpdwMaxLOD);

    DirectDrawSurface7LogMethodResultValue(DEBUGINFO, GetLOD, result, 1, (lpdwMaxLOD));
}