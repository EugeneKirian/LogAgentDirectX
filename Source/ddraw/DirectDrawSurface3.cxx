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
#include <DirectDrawSurface3Logger.hxx>

#define DirectDrawSurface3LogMethod(L, M) AgentLogMethod(L, DirectDrawSurface3, M)
#define DirectDrawSurface3LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectDrawSurface3, M, C, PARAMS)

#define DirectDrawSurface3LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectDrawSurface3, AddRef, R)
#define DirectDrawSurface3LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectDrawSurface3, Release, R)

#define DirectDrawSurface3LogMethodResult(L, M, R) AgentLogMethodResult(L, DirectDrawSurface3, M, R)
#define DirectDrawSurface3LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectDrawSurface3, M, R, C, PARAMS)

#define DirectDrawSurface3LogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, DirectDrawSurface3, M, C, PARAMS)
#define DirectDrawSurface3LogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, DirectDrawSurface3, M, R, C, PARAMS)

typedef struct EnumAttachedSurfacesCallbackContext
{
    DirectDrawSurface3* Self;
    LPLOGGER Logger;
    LPDDENUMSURFACESCALLBACK EnumSurfacesCallback;
    LPVOID Context;
} ENUMATTACHEDSURFACESCALLBACKCONTEXT, * LPENUMATTACHEDSURFACESCALLBACKCONTEXT;

static HRESULT CALLBACK EnumAttachedSurfacesCallback(LPDIRECTDRAWSURFACE lpDDSurface, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpContext)
{
    LPENUMATTACHEDSURFACESCALLBACKCONTEXT context = (LPENUMATTACHEDSURFACESCALLBACKCONTEXT)lpContext;

    DirectDrawSurface3LogMethodCallbackValue(TRACEDEBUG, EnumAttachedSurfaces, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));

    CONST HRESULT result = context->EnumSurfacesCallback(lpDDSurface, lpDDSurfaceDesc, context->Context);

    DirectDrawSurface3LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumAttachedSurfaces, result, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));
}

typedef struct EnumOverlayZOrdersCallbackContext
{
    DirectDrawSurface3* Self;
    LPLOGGER Logger;
    LPDDENUMSURFACESCALLBACK Callback;
    LPVOID Context;
} ENUMOVERLAYZORDERSCALLBACKCONTEXT, * LPENUMOVERLAYZORDERSCALLBACKCONTEXT;

static HRESULT CALLBACK EnumOverlayZOrdersCallback(LPDIRECTDRAWSURFACE lpDDSurface, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID Context)
{
    LPENUMOVERLAYZORDERSCALLBACKCONTEXT context = (LPENUMOVERLAYZORDERSCALLBACKCONTEXT)Context;

    DirectDrawSurface3LogMethodCallbackValue(TRACEDEBUG, EnumOverlayZOrders, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));

    CONST HRESULT result = context->Callback(lpDDSurface, lpDDSurfaceDesc, context->Context);

    DirectDrawSurface3LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumOverlayZOrders, result, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));
}

DirectDrawSurface3::DirectDrawSurface3(AgentConstructorParameters(DirectDrawSurface3))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectDrawSurface3);
}

DirectDrawSurface3::~DirectDrawSurface3()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectDrawSurface3);
}

HRESULT DirectDrawSurface3::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectDrawSurface3LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

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

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectDrawSurface3::AddRef()
{
    DirectDrawSurface3LogMethod(DEBUG, AddRef);
    DirectDrawSurface3LogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectDrawSurface3::Release()
{
    DirectDrawSurface3LogMethod(DEBUG, Release);
    DirectDrawSurface3LogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Attaches the specified z-buffer surface to this surface.
HRESULT DirectDrawSurface3::AddAttachedSurface(LPDIRECTDRAWSURFACE3 lpDDSAttachedSurface)
{
    DirectDrawSurface3LogMethodValue(TRACE, AddAttachedSurface, 1, (lpDDSAttachedSurface));

    AttemptAccessAgentValue(DirectDrawSurface3, lpDDSAttachedSurface);

    CONST HRESULT result = this->State.Self->AddAttachedSurface(lpDDSAttachedSurface);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, AddAttachedSurface, result, 1, (ActivateAgent(DirectDrawSurface3, lpDDSAttachedSurface)));
}

// This method is not currently implemented.
HRESULT DirectDrawSurface3::AddOverlayDirtyRect(LPRECT lpRect)
{
    DirectDrawSurface3LogMethodValue(TRACE, AddOverlayDirtyRect, 1, (lpRect));

    CONST HRESULT result = this->State.Self->AddOverlayDirtyRect(lpRect);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, AddOverlayDirtyRect, result, 1, (lpRect));
}

// Performs a bit block transfer (bitblt).
// This method does not support z-buffering or alpha blending during bitblt operations.
HRESULT DirectDrawSurface3::Blt(LPRECT lpDestRect, LPDIRECTDRAWSURFACE3 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx)
{
    DirectDrawSurface3LogMethodValue(TRACE, Blt, 5, (lpDestRect, lpDDSrcSurface, lpSrcRect, dwFlags, lpDDBltFx));

    AttemptAccessAgentValue(DirectDrawSurface3, lpDDSrcSurface);

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

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, Blt, result, 5, (lpDestRect, ActivateAgent(DirectDrawSurface3, lpDDSrcSurface), lpSrcRect, dwFlags, lpDDBltFx));
}

// This method is not currently implemented.
HRESULT DirectDrawSurface3::BltBatch(LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags)
{
    DirectDrawSurface3LogMethodValue(TRACE, BltBatch, 3, (lpDDBltBatch, dwCount, dwFlags));

    if (lpDDBltBatch != NULL) { AttemptAccessAgentValue(DirectDrawSurface, lpDDBltBatch->lpDDSSrc); }

    CONST HRESULT result = this->State.Self->BltBatch(lpDDBltBatch, dwCount, dwFlags);

    if (lpDDBltBatch != NULL) { lpDDBltBatch->lpDDSSrc = ActivateAgent(DirectDrawSurface, lpDDBltBatch->lpDDSSrc); }

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, BltBatch, result, 3, (lpDDBltBatch, dwCount, dwFlags));
}

// Performs a source copy bitblt or transparent bitblt by using a source color key or destination color key.
HRESULT DirectDrawSurface3::BltFast(DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE3 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans)
{
    DirectDrawSurface3LogMethodValue(TRACE, BltFast, 5, (dwX, dwY, lpDDSrcSurface, lpSrcRect, dwTrans));

    AttemptAccessAgentValue(DirectDrawSurface3, lpDDSrcSurface);

    CONST HRESULT result = this->State.Self->BltFast(dwX, dwY, lpDDSrcSurface, lpSrcRect, dwTrans);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, BltFast, result, 5, (dwX, dwY, ActivateAgent(DirectDrawSurface3, lpDDSrcSurface), lpSrcRect, dwTrans));
}

// Detaches one or more attached surfaces.
HRESULT DirectDrawSurface3::DeleteAttachedSurface(DWORD dwFlags, LPDIRECTDRAWSURFACE3 lpDDSAttachedSurface)
{
    DirectDrawSurface3LogMethodValue(TRACE, DeleteAttachedSurface, 2, (dwFlags, lpDDSAttachedSurface));

    AttemptAccessAgentValue(DirectDrawSurface3, lpDDSAttachedSurface);

    CONST HRESULT result = this->State.Self->DeleteAttachedSurface(dwFlags, lpDDSAttachedSurface);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, DeleteAttachedSurface, result, 2, (dwFlags, ActivateAgent(DirectDrawSurface3, lpDDSAttachedSurface)));
}

// Enumerates all the surfaces that are attached to this surface.
HRESULT DirectDrawSurface3::EnumAttachedSurfaces(LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback)
{
    DirectDrawSurface3LogMethodValue(DEBUGINFO, EnumAttachedSurfaces, 2, (lpContext, lpEnumSurfacesCallback));

    if (lpEnumSurfacesCallback == NULL) { DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, EnumAttachedSurfaces, DDERR_INVALIDPARAMS, 2, (lpContext, lpEnumSurfacesCallback)); }

    ENUMATTACHEDSURFACESCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumSurfacesCallback = lpEnumSurfacesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumAttachedSurfaces(&context, EnumAttachedSurfacesCallback);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, EnumAttachedSurfaces, result, 2, (lpContext, lpEnumSurfacesCallback));
}

// Enumerates the overlay surfaces on the specified destination.
// You can enumerate the overlays in front-to-back or back-to-front order.
HRESULT DirectDrawSurface3::EnumOverlayZOrders(DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpfnCallback)
{
    DirectDrawSurface3LogMethodValue(DEBUGINFO, EnumOverlayZOrders, 3, (dwFlags, lpContext, lpfnCallback));

    if (lpfnCallback == NULL) { DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, EnumOverlayZOrders, DDERR_INVALIDPARAMS, 3, (dwFlags, lpContext, lpfnCallback)); }

    ENUMOVERLAYZORDERSCALLBACKCONTEXT context;

    context.Self = this;
    context.Callback = lpfnCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumOverlayZOrders(dwFlags, &context, EnumOverlayZOrdersCallback);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, EnumOverlayZOrders, result, 3, (dwFlags, lpContext, lpfnCallback));
}

// Makes the surface memory that is associated with the DDSCAPS_BACKBUFFER surface become associated with the front-buffer surface.
HRESULT DirectDrawSurface3::Flip(LPDIRECTDRAWSURFACE3 lpDDSurfaceTargetOverride, DWORD dwFlags)
{
    DirectDrawSurface3LogMethodValue(TRACE, Flip, 2, (lpDDSurfaceTargetOverride, dwFlags));

    AttemptAccessAgentValue(DirectDrawSurface3, lpDDSurfaceTargetOverride);

    CONST HRESULT result = this->State.Self->Flip(lpDDSurfaceTargetOverride, dwFlags);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, Flip, result, 2, (ActivateAgent(DirectDrawSurface3, lpDDSurfaceTargetOverride), dwFlags));
}

// Obtains the attached surface that has the specified capabilities,
// and increments the reference count of the retrieved interface.
HRESULT DirectDrawSurface3::GetAttachedSurface(LPDDSCAPS lpDDSCaps, LPDIRECTDRAWSURFACE3 FAR* lplpDDAttachedSurface)
{
    DirectDrawSurface3LogMethodValue(TRACE, GetAttachedSurface, 2, (lpDDSCaps, lplpDDAttachedSurface));

    CONST HRESULT result = this->State.Self->GetAttachedSurface(lpDDSCaps, lplpDDAttachedSurface);

    if (SUCCEEDED(result)) { *lplpDDAttachedSurface = ActivateAgentDelegate(DirectDrawSurface3, *lplpDDAttachedSurface); }

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, GetAttachedSurface, result, 2, (lpDDSCaps, lplpDDAttachedSurface));
}

// Obtains status about a bit block transfer (bitblt) operation.
HRESULT DirectDrawSurface3::GetBltStatus(DWORD dwFlags)
{
    DirectDrawSurface3LogMethodValue(TRACE, GetBltStatus, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->GetBltStatus(dwFlags);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, GetBltStatus, result, 1, (dwFlags));
}

// Retrieves the capabilities of this surface.
// These capabilities are not necessarily related to the capabilities of the display device.
HRESULT DirectDrawSurface3::GetCaps(LPDDSCAPS lpDDSCaps)
{
    DirectDrawSurface3LogMethodValue(TRACE, GetCaps, 1, (lpDDSCaps));

    CONST HRESULT result = this->State.Self->GetCaps(lpDDSCaps);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, GetCaps, result, 1, (lpDDSCaps));
}

// Retrieves the DirectDrawClipper object that is associated with this surface,
// and increments the reference count of the returned clipper.
HRESULT DirectDrawSurface3::GetClipper(LPDIRECTDRAWCLIPPER FAR* lplpDDClipper)
{
    DirectDrawSurface3LogMethodValue(TRACE, GetClipper, 1, (lplpDDClipper));

    CONST HRESULT result = this->State.Self->GetClipper(lplpDDClipper);

    if (SUCCEEDED(result)) { *lplpDDClipper = ActivateAgentDelegate(DirectDrawClipper, *lplpDDClipper); }

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, GetClipper, result, 1, (lplpDDClipper));
}

// Retrieves the color key value for this surface.
HRESULT DirectDrawSurface3::GetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey)
{
    DirectDrawSurface3LogMethodValue(TRACE, GetColorKey, 2, (dwFlags, lpDDColorKey));

    CONST HRESULT result = this->State.Self->GetColorKey(dwFlags, lpDDColorKey);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, GetColorKey, result, 2, (dwFlags, lpDDColorKey));
}

// Creates a GDI-compatible handle of a device context for this surface.
HRESULT DirectDrawSurface3::GetDC(HDC FAR* lphDC)
{
    DirectDrawSurface3LogMethodValue(TRACE, GetDC, 1, (lphDC));

    CONST HRESULT result = this->State.Self->GetDC(lphDC);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, GetDC, result, 1, (lphDC));
}

// Retrieves status about whether this surface has finished its flipping process.
HRESULT DirectDrawSurface3::GetFlipStatus(DWORD dwFlags)
{
    DirectDrawSurface3LogMethodValue(TRACE, GetFlipStatus, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->GetFlipStatus(dwFlags);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, GetFlipStatus, result, 1, (dwFlags));
}

// Retrieves the display coordinates of this surface.
// This method is used on a visible, active overlay surface
// (that is, a surface that has the DDSCAPS_OVERLAY flag set).
HRESULT DirectDrawSurface3::GetOverlayPosition(LPLONG lplX, LPLONG lplY)
{
    DirectDrawSurface3LogMethodValue(TRACE, GetOverlayPosition, 2, (lplX, lplY));

    CONST HRESULT result = this->State.Self->GetOverlayPosition(lplX, lplY);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, GetOverlayPosition, result, 2, (lplX, lplY));
}

// Retrieves the DirectDrawPalette object that is associated with this surface,
// and increments the reference count of the returned palette.
HRESULT DirectDrawSurface3::GetPalette(LPDIRECTDRAWPALETTE FAR* lplpDDPalette)
{
    DirectDrawSurface3LogMethodValue(TRACE, GetPalette, 1, (lplpDDPalette));

    CONST HRESULT result = this->State.Self->GetPalette(lplpDDPalette);

    if (SUCCEEDED(result)) { *lplpDDPalette = ActivateAgentDelegate(DirectDrawPalette, *lplpDDPalette); }

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, GetPalette, result, 1, (lplpDDPalette));
}

// Retrieves the color and pixel format of this surface.
HRESULT DirectDrawSurface3::GetPixelFormat(LPDDPIXELFORMAT lpDDPixelFormat)
{
    DirectDrawSurface3LogMethodValue(TRACE, GetPixelFormat, 1, (lpDDPixelFormat));

    CONST HRESULT result = this->State.Self->GetPixelFormat(lpDDPixelFormat);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, GetPixelFormat, result, 1, (lpDDPixelFormat));
}

// Retrieves a description of this surface in its current condition.
HRESULT DirectDrawSurface3::GetSurfaceDesc(LPDDSURFACEDESC lpDDSurfaceDesc)
{
    DirectDrawSurface3LogMethodValue(TRACE, GetSurfaceDesc, 1, (lpDDSurfaceDesc));

    CONST HRESULT result = this->State.Self->GetSurfaceDesc(lpDDSurfaceDesc);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, GetSurfaceDesc, result, 1, (lpDDSurfaceDesc));
}

// Initializes a DirectDrawSurface3 object.
HRESULT DirectDrawSurface3::Initialize(LPDIRECTDRAW lpDD, LPDDSURFACEDESC lpDDSurfaceDesc)
{
    DirectDrawSurface3LogMethodValue(TRACE, Initialize, 2, (lpDD, lpDDSurfaceDesc));

    AttemptAccessAgentValue(DirectDraw, lpDD);

    CONST HRESULT result = this->State.Self->Initialize(lpDD, lpDDSurfaceDesc);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 2, (ActivateAgent(DirectDraw, lpDD), lpDDSurfaceDesc));
}

// Determines whether the surface memory that is associated with a DirectDrawSurface3 object has been freed.
HRESULT DirectDrawSurface3::IsLost()
{
    DirectDrawSurface3LogMethod(DEBUG, IsLost);

    CONST HRESULT result = this->State.Self->IsLost();

    DirectDrawSurface3LogMethodResult(DEBUGINFO, IsLost, result);
}

// Obtains a pointer to the surface memory.
HRESULT DirectDrawSurface3::Lock(LPRECT lpDestRect, LPDDSURFACEDESC lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent)
{
    DirectDrawSurface3LogMethodValue(TRACE, Lock, 4, (lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent));

    CONST HRESULT result = this->State.Self->Lock(lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, Lock, result, 4, (lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent));
}

// Releases the handle of a device context that was previously obtained by using the IDirectDrawSurface3::GetDC method.
HRESULT DirectDrawSurface3::ReleaseDC(HDC hDC)
{
    DirectDrawSurface3LogMethodValue(TRACE, ReleaseDC, 1, (hDC));

    CONST HRESULT result = this->State.Self->ReleaseDC(hDC);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, ReleaseDC, result, 1, (hDC));
}

// Restores a surface that has been lost.
// This occurs when the surface memory that is associated with the DirectDrawSurface3 object has been freed.
HRESULT DirectDrawSurface3::Restore()
{
    DirectDrawSurface3LogMethod(DEBUG, Restore);

    CONST HRESULT result = this->State.Self->Restore();

    DirectDrawSurface3LogMethodResult(DEBUGINFO, Restore, result);
}

// Attaches a clipper object to, or deletes one from, this surface.
HRESULT DirectDrawSurface3::SetClipper(LPDIRECTDRAWCLIPPER lpDDClipper)
{
    DirectDrawSurface3LogMethodValue(TRACE, SetClipper, 1, (lpDDClipper));

    AttemptAccessAgentValue(DirectDrawClipper, lpDDClipper);

    CONST HRESULT result = this->State.Self->SetClipper(lpDDClipper);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, SetClipper, result, 1, (ActivateAgent(DirectDrawClipper, lpDDClipper)));
}

// Sets the color key value for the DirectDrawSurface3 object if the hardware supports color keys on a per-surface basis.
HRESULT DirectDrawSurface3::SetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey)
{
    DirectDrawSurface3LogMethodValue(TRACE, SetColorKey, 2, (dwFlags, lpDDColorKey));

    CONST HRESULT result = this->State.Self->SetColorKey(dwFlags, lpDDColorKey);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, SetColorKey, result, 2, (dwFlags, lpDDColorKey));
}

// Changes the display coordinates of an overlay surface.
HRESULT DirectDrawSurface3::SetOverlayPosition(LONG lX, LONG lY)
{
    DirectDrawSurface3LogMethodValue(TRACE, SetOverlayPosition, 2, (lX, lY));

    CONST HRESULT result = this->State.Self->SetOverlayPosition(lX, lY);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, SetOverlayPosition, result, 2, (lX, lY));
}

// Attaches a palette object to (or detaches one from) a surface.
// The surface uses this palette for all subsequent operations.
// The palette change takes place immediately, without regard to refresh timing.
HRESULT DirectDrawSurface3::SetPalette(LPDIRECTDRAWPALETTE lpDDPalette)
{
    DirectDrawSurface3LogMethodValue(TRACE, SetPalette, 1, (lpDDPalette));

    AttemptAccessAgentValue(DirectDrawPalette, lpDDPalette);

    CONST HRESULT result = this->State.Self->SetPalette(lpDDPalette);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, SetPalette, result, 1, (ActivateAgent(DirectDrawPalette, lpDDPalette)));
}

// Notifies DirectDraw that the direct surface manipulations are complete.
HRESULT DirectDrawSurface3::Unlock(LPVOID lpSurfaceData)
{
    DirectDrawSurface3LogMethodValue(TRACE, Unlock, 1, (lpSurfaceData));

    CONST HRESULT result = this->State.Self->Unlock(lpSurfaceData);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, Unlock, result, 1, (lpSurfaceData));
}

// Repositions or modifies the visual attributes of an overlay surface.
// These surfaces must have the DDSCAPS_OVERLAY flag set.
HRESULT DirectDrawSurface3::UpdateOverlay(LPRECT lpSrcRect, LPDIRECTDRAWSURFACE3 lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx)
{
    DirectDrawSurface3LogMethodValue(TRACE, UpdateOverlay, 5, (lpSrcRect, lpDDDestSurface, lpDestRect, dwFlags, lpDDOverlayFx));

    AttemptAccessAgentValue(DirectDrawSurface3, lpDDDestSurface);

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

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, UpdateOverlay, result, 5, (lpSrcRect, ActivateAgent(DirectDrawSurface3, lpDDDestSurface), lpDestRect, dwFlags, lpDDOverlayFx));
}

// This method is not currently implemented.
HRESULT DirectDrawSurface3::UpdateOverlayDisplay(DWORD dwFlags)
{
    DirectDrawSurface3LogMethodValue(TRACE, UpdateOverlayDisplay, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->UpdateOverlayDisplay(dwFlags);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, UpdateOverlayDisplay, result, 1, (dwFlags));
}

// Sets the z-order of an overlay.
HRESULT DirectDrawSurface3::UpdateOverlayZOrder(DWORD dwFlags, LPDIRECTDRAWSURFACE3 lpDDSReference)
{
    DirectDrawSurface3LogMethodValue(TRACE, UpdateOverlayZOrder, 2, (dwFlags, lpDDSReference));

    AttemptAccessAgentValue(DirectDrawSurface3, lpDDSReference);

    CONST HRESULT result = this->State.Self->UpdateOverlayZOrder(dwFlags, lpDDSReference);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, UpdateOverlayZOrder, result, 2, (dwFlags, ActivateAgent(DirectDrawSurface3, lpDDSReference)));
}

// Retrieves an interface to the DirectDraw object that was used to create this surface.
HRESULT DirectDrawSurface3::GetDDInterface(LPVOID FAR* lplpDD)
{
    DirectDrawSurface3LogMethodValue(TRACE, GetDDInterface, 1, (lplpDD));

    CONST HRESULT result = this->State.Self->GetDDInterface(lplpDD);

    if (SUCCEEDED(result)) { *lplpDD = ActivateAgentDelegate(DirectDraw4, *lplpDD); }

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, GetDDInterface, result, 1, (lplpDD));
}

// Prevents a system-memory surface from being paged out while a bit block transfer (bitblt) operation
// that uses direct memory access (DMA) transfers to or from system memory is in progress.
HRESULT DirectDrawSurface3::PageLock(DWORD dwFlags)
{
    DirectDrawSurface3LogMethodValue(TRACE, PageLock, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->PageLock(dwFlags);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, PageLock, result, 1, (dwFlags));
}

// Unlocks a system-memory surface, which then allows it to be paged out.
HRESULT DirectDrawSurface3::PageUnlock(DWORD dwFlags)
{
    DirectDrawSurface3LogMethodValue(TRACE, PageUnlock, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->PageUnlock(dwFlags);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, PageUnlock, result, 1, (dwFlags));
}

// Sets the characteristics of an existing surface.
HRESULT DirectDrawSurface3::SetSurfaceDesc(LPDDSURFACEDESC lpDDSurfaceDesc, DWORD dwFlags)
{
    DirectDrawSurface3LogMethodValue(TRACE, SetSurfaceDesc, 2, (lpDDSurfaceDesc, dwFlags));

    CONST HRESULT result = this->State.Self->SetSurfaceDesc(lpDDSurfaceDesc, dwFlags);

    DirectDrawSurface3LogMethodResultValue(TRACEDEBUGINFO, SetSurfaceDesc, result, 2, (lpDDSurfaceDesc, dwFlags));
}