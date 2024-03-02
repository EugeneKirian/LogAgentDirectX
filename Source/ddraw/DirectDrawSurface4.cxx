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
#include <DirectDrawSurface4Logger.hxx>

#define DirectDrawSurface4LogMethod(L, M) AgentLogMethod(L, DirectDrawSurface4, M)
#define DirectDrawSurface4LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectDrawSurface4, M, C, PARAMS)

#define DirectDrawSurface4LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectDrawSurface4, AddRef, R)
#define DirectDrawSurface4LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectDrawSurface4, Release, R)

#define DirectDrawSurface4LogMethodResult(L, M, R) AgentLogMethodResult(L, DirectDrawSurface4, M, R)
#define DirectDrawSurface4LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectDrawSurface4, M, R, C, PARAMS)

#define DirectDrawSurface4LogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, DirectDrawSurface4, M, C, PARAMS)
#define DirectDrawSurface4LogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, DirectDrawSurface4, M, R, C, PARAMS)

typedef struct EnumAttachedSurfacesCallbackContext
{
    DirectDrawSurface4* Self;
    LPLOGGER Logger;
    LPDDENUMSURFACESCALLBACK2 EnumSurfacesCallback;
    LPVOID Context;
} ENUMATTACHEDSURFACESCALLBACKCONTEXT, * LPENUMATTACHEDSURFACESCALLBACKCONTEXT;

static HRESULT CALLBACK EnumAttachedSurfacesCallback(LPDIRECTDRAWSURFACE4 lpDDSurface, LPDDSURFACEDESC2 lpDDSurfaceDesc, LPVOID lpContext)
{
    LPENUMATTACHEDSURFACESCALLBACKCONTEXT context = (LPENUMATTACHEDSURFACESCALLBACKCONTEXT)lpContext;

    DirectDrawSurface4LogMethodCallbackValue(DEBUG, EnumAttachedSurfaces, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));

    CONST HRESULT result = context->EnumSurfacesCallback(lpDDSurface, lpDDSurfaceDesc, context->Context);

    DirectDrawSurface4LogMethodCallbackResultValue(DEBUGINFO, EnumAttachedSurfaces, result, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));
}

typedef struct EnumOverlayZOrdersCallbackContext
{
    DirectDrawSurface4* Self;
    LPLOGGER Logger;
    LPDDENUMSURFACESCALLBACK2 Callback;
    LPVOID Context;
} ENUMOVERLAYZORDERSCALLBACKCONTEXT, * LPENUMOVERLAYZORDERSCALLBACKCONTEXT;

static HRESULT CALLBACK EnumOverlayZOrdersCallback(LPDIRECTDRAWSURFACE4 lpDDSurface, LPDDSURFACEDESC2 lpDDSurfaceDesc, LPVOID lpContext)
{
    LPENUMOVERLAYZORDERSCALLBACKCONTEXT context = (LPENUMOVERLAYZORDERSCALLBACKCONTEXT)lpContext;

    DirectDrawSurface4LogMethodCallbackValue(DEBUG, EnumOverlayZOrders, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));

    CONST HRESULT result = context->Callback(lpDDSurface, lpDDSurfaceDesc, context->Context);

    DirectDrawSurface4LogMethodCallbackResultValue(DEBUGINFO, EnumOverlayZOrders, result, 3, (context->Self, lpDDSurface, lpDDSurfaceDesc));
}

DirectDrawSurface4::DirectDrawSurface4(AgentConstructorParameters(DirectDrawSurface4))
{
    AgentConstructor();
    AgentLogConstructor(DEBUG, DirectDrawSurface4);
}

DirectDrawSurface4::~DirectDrawSurface4()
{
    AgentDestructor();
    AgentLogDestructor(DEBUG, DirectDrawSurface4);
}

HRESULT DirectDrawSurface4::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectDrawSurface4LogMethodValue(DEBUG, QueryInterface, 2, (riid, ppvObj));

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

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectDrawSurface4::AddRef()
{
    DirectDrawSurface4LogMethod(DEBUG, AddRef);
    DirectDrawSurface4LogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectDrawSurface4::Release()
{
    DirectDrawSurface4LogMethod(DEBUG, Release);
    DirectDrawSurface4LogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Attaches the specified z-buffer surface to this surface.
HRESULT DirectDrawSurface4::AddAttachedSurface(LPDIRECTDRAWSURFACE4 lpDDSAttachedSurface)
{
    DirectDrawSurface4LogMethodValue(DEBUG, AddAttachedSurface, 1, (lpDDSAttachedSurface));

    AttemptAccessAgentValue(DirectDrawSurface4, lpDDSAttachedSurface);

    CONST HRESULT result = this->State.Self->AddAttachedSurface(lpDDSAttachedSurface);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, AddAttachedSurface, result, 1, (ActivateAgent(DirectDrawSurface4, lpDDSAttachedSurface)));
}

// This method is not currently implemented.
HRESULT DirectDrawSurface4::AddOverlayDirtyRect(LPRECT lpRect)
{
    DirectDrawSurface4LogMethodValue(DEBUG, AddOverlayDirtyRect, 1, (lpRect));

    CONST HRESULT result = this->State.Self->AddOverlayDirtyRect(lpRect);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, AddOverlayDirtyRect, result, 1, (lpRect));
}

// Performs a bit block transfer (bitblt).
// This method does not support z-buffering or alpha blending during bitblt operations.
HRESULT DirectDrawSurface4::Blt(LPRECT lpDestRect, LPDIRECTDRAWSURFACE4 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwFlags, LPDDBLTFX lpDDBltFx)
{
    DirectDrawSurface4LogMethodValue(DEBUG, Blt, 5, (lpDestRect, lpDDSrcSurface, lpSrcRect, dwFlags, lpDDBltFx));

    AttemptAccessAgentValue(DirectDrawSurface4, lpDDSrcSurface);

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

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, Blt, result, 5, (lpDestRect, ActivateAgent(DirectDrawSurface4, lpDDSrcSurface), lpSrcRect, dwFlags, lpDDBltFx));
}

// This method is not currently implemented.
HRESULT DirectDrawSurface4::BltBatch(LPDDBLTBATCH lpDDBltBatch, DWORD dwCount, DWORD dwFlags)
{
    DirectDrawSurface4LogMethodValue(DEBUG, BltBatch, 3, (lpDDBltBatch, dwCount, dwFlags));

    if (lpDDBltBatch != NULL) { AttemptAccessAgentValue(DirectDrawSurface, lpDDBltBatch->lpDDSSrc); }

    CONST HRESULT result = this->State.Self->BltBatch(lpDDBltBatch, dwCount, dwFlags);

    if (lpDDBltBatch != NULL) { lpDDBltBatch->lpDDSSrc = ActivateAgent(DirectDrawSurface, lpDDBltBatch->lpDDSSrc); }

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, BltBatch, result, 3, (lpDDBltBatch, dwCount, dwFlags));
}

// Performs a source copy bitblt or transparent bitblt by using a source color key or destination color key.
HRESULT DirectDrawSurface4::BltFast(DWORD dwX, DWORD dwY, LPDIRECTDRAWSURFACE4 lpDDSrcSurface, LPRECT lpSrcRect, DWORD dwTrans)
{
    DirectDrawSurface4LogMethodValue(DEBUG, BltFast, 5, (dwX, dwY, lpDDSrcSurface, lpSrcRect, dwTrans));

    AttemptAccessAgentValue(DirectDrawSurface4, lpDDSrcSurface);

    CONST HRESULT result = this->State.Self->BltFast(dwX, dwY, lpDDSrcSurface, lpSrcRect, dwTrans);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, BltFast, result, 5, (dwX, dwY, ActivateAgent(DirectDrawSurface4, lpDDSrcSurface), lpSrcRect, dwTrans));
}

// Detaches one or more attached surfaces.
HRESULT DirectDrawSurface4::DeleteAttachedSurface(DWORD dwFlags, LPDIRECTDRAWSURFACE4 lpDDSAttachedSurface)
{
    DirectDrawSurface4LogMethodValue(DEBUG, DeleteAttachedSurface, 2, (dwFlags, lpDDSAttachedSurface));

    AttemptAccessAgentValue(DirectDrawSurface4, lpDDSAttachedSurface);

    CONST HRESULT result = this->State.Self->DeleteAttachedSurface(dwFlags, lpDDSAttachedSurface);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, DeleteAttachedSurface, result, 2, (dwFlags, ActivateAgent(DirectDrawSurface4, lpDDSAttachedSurface)));
}

// Enumerates all the surfaces that are attached to this surface.
HRESULT DirectDrawSurface4::EnumAttachedSurfaces(LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpEnumSurfacesCallback)
{
    DirectDrawSurface4LogMethodValue(DEBUGINFO, EnumAttachedSurfaces, 2, (lpContext, lpEnumSurfacesCallback));

    if (lpEnumSurfacesCallback == NULL) { DirectDrawSurface4LogMethodResultValue(DEBUGINFO, EnumAttachedSurfaces, DDERR_INVALIDPARAMS, 2, (lpContext, lpEnumSurfacesCallback)); }

    ENUMATTACHEDSURFACESCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumSurfacesCallback = lpEnumSurfacesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumAttachedSurfaces(&context, EnumAttachedSurfacesCallback);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, EnumAttachedSurfaces, result, 2, (lpContext, lpEnumSurfacesCallback));
}

// Enumerates the overlay surfaces on the specified destination.
// You can enumerate the overlays in front-to-back or back-to-front order.
HRESULT DirectDrawSurface4::EnumOverlayZOrders(DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpfnCallback)
{
    DirectDrawSurface4LogMethodValue(DEBUGINFO, EnumOverlayZOrders, 3, (dwFlags, lpContext, lpfnCallback));

    if (lpfnCallback == NULL) { DirectDrawSurface4LogMethodResultValue(DEBUGINFO, EnumOverlayZOrders, DDERR_INVALIDPARAMS, 3, (dwFlags, lpContext, lpfnCallback)); }

    ENUMOVERLAYZORDERSCALLBACKCONTEXT context;

    context.Self = this;
    context.Callback = lpfnCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumOverlayZOrders(dwFlags, &context, EnumOverlayZOrdersCallback);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, EnumOverlayZOrders, result, 3, (dwFlags, lpContext, lpfnCallback));
}

// Makes the surface memory that is associated with the DDSCAPS_BACKBUFFER surface become associated with the front-buffer surface.
HRESULT DirectDrawSurface4::Flip(LPDIRECTDRAWSURFACE4 lpDDSurfaceTargetOverride, DWORD dwFlags)
{
    DirectDrawSurface4LogMethodValue(DEBUG, Flip, 2, (lpDDSurfaceTargetOverride, dwFlags));

    AttemptAccessAgentValue(DirectDrawSurface4, lpDDSurfaceTargetOverride);

    CONST HRESULT result = this->State.Self->Flip(lpDDSurfaceTargetOverride, dwFlags);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, Flip, result, 2, (ActivateAgent(DirectDrawSurface4, lpDDSurfaceTargetOverride), dwFlags));
}

// Obtains the attached surface that has the specified capabilities,
// and increments the reference count of the retrieved interface.
HRESULT DirectDrawSurface4::GetAttachedSurface(LPDDSCAPS2 lpDDSCaps, LPDIRECTDRAWSURFACE4 FAR* lplpDDAttachedSurface)
{
    DirectDrawSurface4LogMethodValue(DEBUG, GetAttachedSurface, 2, (lpDDSCaps, lplpDDAttachedSurface));

    CONST HRESULT result = this->State.Self->GetAttachedSurface(lpDDSCaps, lplpDDAttachedSurface);

    if (SUCCEEDED(result)) { *lplpDDAttachedSurface = ActivateAgentDelegate(DirectDrawSurface4, *lplpDDAttachedSurface); }

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, GetAttachedSurface, result, 2, (lpDDSCaps, lplpDDAttachedSurface));
}

// Obtains status about a bit block transfer (bitblt) operation.
HRESULT DirectDrawSurface4::GetBltStatus(DWORD dwFlags)
{
    DirectDrawSurface4LogMethodValue(DEBUG, GetBltStatus, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->GetBltStatus(dwFlags);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, GetBltStatus, result, 1, (dwFlags));
}

// Retrieves the capabilities of this surface.
// These capabilities are not necessarily related to the capabilities of the display device.
HRESULT DirectDrawSurface4::GetCaps(LPDDSCAPS2 lpDDSCaps)
{
    DirectDrawSurface4LogMethodValue(DEBUG, GetCaps, 1, (lpDDSCaps));

    CONST HRESULT result = this->State.Self->GetCaps(lpDDSCaps);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, GetCaps, result, 1, (lpDDSCaps));
}

// Retrieves the DirectDrawClipper object that is associated with this surface,
// and increments the reference count of the returned clipper.
HRESULT DirectDrawSurface4::GetClipper(LPDIRECTDRAWCLIPPER FAR* lplpDDClipper)
{
    DirectDrawSurface4LogMethodValue(DEBUG, GetClipper, 1, (lplpDDClipper));

    CONST HRESULT result = this->State.Self->GetClipper(lplpDDClipper);

    if (SUCCEEDED(result)) { *lplpDDClipper = ActivateAgentDelegate(DirectDrawClipper, *lplpDDClipper); }

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, GetClipper, result, 1, (lplpDDClipper));
}

// Retrieves the color key value for this surface.
HRESULT DirectDrawSurface4::GetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey)
{
    DirectDrawSurface4LogMethodValue(DEBUG, GetColorKey, 2, (dwFlags, lpDDColorKey));

    CONST HRESULT result = this->State.Self->GetColorKey(dwFlags, lpDDColorKey);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, GetColorKey, result, 2, (dwFlags, lpDDColorKey));
}

// Creates a GDI-compatible handle of a device context for this surface.
HRESULT DirectDrawSurface4::GetDC(HDC FAR* lphDC)
{
    DirectDrawSurface4LogMethodValue(DEBUG, GetDC, 1, (lphDC));

    CONST HRESULT result = this->State.Self->GetDC(lphDC);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, GetDC, result, 1, (lphDC));
}

// Retrieves status about whether this surface has finished its flipping process.
HRESULT DirectDrawSurface4::GetFlipStatus(DWORD dwFlags)
{
    DirectDrawSurface4LogMethodValue(DEBUG, GetFlipStatus, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->GetFlipStatus(dwFlags);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, GetFlipStatus, result, 1, (dwFlags));
}

// Retrieves the display coordinates of this surface.
// This method is used on a visible, active overlay surface
// (that is, a surface that has the DDSCAPS_OVERLAY flag set).
HRESULT DirectDrawSurface4::GetOverlayPosition(LPLONG lplX, LPLONG lplY)
{
    DirectDrawSurface4LogMethodValue(DEBUG, GetOverlayPosition, 2, (lplX, lplY));

    CONST HRESULT result = this->State.Self->GetOverlayPosition(lplX, lplY);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, GetOverlayPosition, result, 2, (lplX, lplY));
}

// Retrieves the DirectDrawPalette object that is associated with this surface,
// and increments the reference count of the returned palette.
HRESULT DirectDrawSurface4::GetPalette(LPDIRECTDRAWPALETTE FAR* lplpDDPalette)
{
    DirectDrawSurface4LogMethodValue(DEBUG, GetPalette, 1, (lplpDDPalette));

    CONST HRESULT result = this->State.Self->GetPalette(lplpDDPalette);

    if (SUCCEEDED(result)) { *lplpDDPalette = ActivateAgentDelegate(DirectDrawPalette, *lplpDDPalette); }

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, GetPalette, result, 1, (lplpDDPalette));
}

// Retrieves the color and pixel format of this surface.
HRESULT DirectDrawSurface4::GetPixelFormat(LPDDPIXELFORMAT lpDDPixelFormat)
{
    DirectDrawSurface4LogMethodValue(DEBUG, GetPixelFormat, 1, (lpDDPixelFormat));

    CONST HRESULT result = this->State.Self->GetPixelFormat(lpDDPixelFormat);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, GetPixelFormat, result, 1, (lpDDPixelFormat));
}

// Retrieves a description of this surface in its current condition.
HRESULT DirectDrawSurface4::GetSurfaceDesc(LPDDSURFACEDESC2 lpDDSurfaceDesc)
{
    DirectDrawSurface4LogMethodValue(DEBUG, GetSurfaceDesc, 1, (lpDDSurfaceDesc));

    CONST HRESULT result = this->State.Self->GetSurfaceDesc(lpDDSurfaceDesc);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, GetSurfaceDesc, result, 1, (lpDDSurfaceDesc));
}

// Initializes a DirectDrawSurface4 object.
HRESULT DirectDrawSurface4::Initialize(LPDIRECTDRAW lpDD, LPDDSURFACEDESC2 lpDDSurfaceDesc)
{
    DirectDrawSurface4LogMethodValue(DEBUG, Initialize, 2, (lpDD, lpDDSurfaceDesc));

    AttemptAccessAgentValue(DirectDraw, lpDD);

    CONST HRESULT result = this->State.Self->Initialize(lpDD, lpDDSurfaceDesc);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, Initialize, result, 2, (ActivateAgent(DirectDraw, lpDD), lpDDSurfaceDesc));
}

// Determines whether the surface memory that is associated with a DirectDrawSurface4 object has been freed.
HRESULT DirectDrawSurface4::IsLost()
{
    DirectDrawSurface4LogMethod(DEBUG, IsLost);

    CONST HRESULT result = this->State.Self->IsLost();

    DirectDrawSurface4LogMethodResult(DEBUGINFO, IsLost, result);
}

// Obtains a pointer to the surface memory.
HRESULT DirectDrawSurface4::Lock(LPRECT lpDestRect, LPDDSURFACEDESC2 lpDDSurfaceDesc, DWORD dwFlags, HANDLE hEvent)
{
    DirectDrawSurface4LogMethodValue(DEBUG, Lock, 4, (lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent));

    CONST HRESULT result = this->State.Self->Lock(lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, Lock, result, 4, (lpDestRect, lpDDSurfaceDesc, dwFlags, hEvent));
}

// Releases the handle of a device context that was previously obtained by using the IDirectDrawSurface4::GetDC method.
HRESULT DirectDrawSurface4::ReleaseDC(HDC hDC)
{
    DirectDrawSurface4LogMethodValue(DEBUG, ReleaseDC, 1, (hDC));

    CONST HRESULT result = this->State.Self->ReleaseDC(hDC);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, ReleaseDC, result, 1, (hDC));
}

// Restores a surface that has been lost.
// This occurs when the surface memory that is associated with the DirectDrawSurface4 object has been freed.
HRESULT DirectDrawSurface4::Restore()
{
    DirectDrawSurface4LogMethod(DEBUG, Restore);

    CONST HRESULT result = this->State.Self->Restore();

    DirectDrawSurface4LogMethodResult(DEBUGINFO, Restore, result);
}

// Attaches a clipper object to, or deletes one from, this surface.
HRESULT DirectDrawSurface4::SetClipper(LPDIRECTDRAWCLIPPER lpDDClipper)
{
    DirectDrawSurface4LogMethodValue(DEBUG, SetClipper, 1, (lpDDClipper));

    AttemptAccessAgentValue(DirectDrawClipper, lpDDClipper);

    CONST HRESULT result = this->State.Self->SetClipper(lpDDClipper);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, SetClipper, result, 1, (ActivateAgent(DirectDrawClipper, lpDDClipper)));
}

// Sets the color key value for the DirectDrawSurface4 object if the hardware supports color keys on a per-surface basis.
HRESULT DirectDrawSurface4::SetColorKey(DWORD dwFlags, LPDDCOLORKEY lpDDColorKey)
{
    DirectDrawSurface4LogMethodValue(DEBUG, SetColorKey, 2, (dwFlags, lpDDColorKey));

    CONST HRESULT result = this->State.Self->SetColorKey(dwFlags, lpDDColorKey);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, SetColorKey, result, 2, (dwFlags, lpDDColorKey));
}

// Changes the display coordinates of an overlay surface.
HRESULT DirectDrawSurface4::SetOverlayPosition(LONG lX, LONG lY)
{
    DirectDrawSurface4LogMethodValue(DEBUG, SetOverlayPosition, 2, (lX, lY));

    CONST HRESULT result = this->State.Self->SetOverlayPosition(lX, lY);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, SetOverlayPosition, result, 2, (lX, lY));
}

// Attaches a palette object to (or detaches one from) a surface.
// The surface uses this palette for all subsequent operations.
// The palette change takes place immediately, without regard to refresh timing.
HRESULT DirectDrawSurface4::SetPalette(LPDIRECTDRAWPALETTE lpDDPalette)
{
    DirectDrawSurface4LogMethodValue(DEBUG, SetPalette, 1, (lpDDPalette));

    AttemptAccessAgentValue(DirectDrawPalette, lpDDPalette);

    CONST HRESULT result = this->State.Self->SetPalette(lpDDPalette);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, SetPalette, result, 1, (ActivateAgent(DirectDrawPalette, lpDDPalette)));
}

// Notifies DirectDraw that the direct surface manipulations are complete.
HRESULT DirectDrawSurface4::Unlock(LPRECT lpRect)
{
    DirectDrawSurface4LogMethodValue(DEBUG, Unlock, 1, (lpRect));

    CONST HRESULT result = this->State.Self->Unlock(lpRect);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, Unlock, result, 1, (lpRect));
}

// Repositions or modifies the visual attributes of an overlay surface.
// These surfaces must have the DDSCAPS_OVERLAY flag set.
HRESULT DirectDrawSurface4::UpdateOverlay(LPRECT lpSrcRect, LPDIRECTDRAWSURFACE4 lpDDDestSurface, LPRECT lpDestRect, DWORD dwFlags, LPDDOVERLAYFX lpDDOverlayFx)
{
    DirectDrawSurface4LogMethodValue(DEBUG, UpdateOverlay, 5, (lpSrcRect, lpDDDestSurface, lpDestRect, dwFlags, lpDDOverlayFx));

    AttemptAccessAgentValue(DirectDrawSurface4, lpDDDestSurface);

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

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, UpdateOverlay, result, 5, (lpSrcRect, ActivateAgent(DirectDrawSurface4, lpDDDestSurface), lpDestRect, dwFlags, lpDDOverlayFx));
}

// This method is not currently implemented.
HRESULT DirectDrawSurface4::UpdateOverlayDisplay(DWORD dwFlags)
{
    DirectDrawSurface4LogMethodValue(DEBUG, UpdateOverlayDisplay, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->UpdateOverlayDisplay(dwFlags);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, UpdateOverlayDisplay, result, 1, (dwFlags));
}

// Sets the z-order of an overlay.
HRESULT DirectDrawSurface4::UpdateOverlayZOrder(DWORD dwFlags, LPDIRECTDRAWSURFACE4 lpDDSReference)
{
    DirectDrawSurface4LogMethodValue(DEBUG, UpdateOverlayZOrder, 2, (dwFlags, lpDDSReference));

    AttemptAccessAgentValue(DirectDrawSurface4, lpDDSReference);

    CONST HRESULT result = this->State.Self->UpdateOverlayZOrder(dwFlags, lpDDSReference);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, UpdateOverlayZOrder, result, 2, (dwFlags, ActivateAgent(DirectDrawSurface4, lpDDSReference)));
}

// Retrieves an interface to the DirectDraw object that was used to create this surface.
HRESULT DirectDrawSurface4::GetDDInterface(LPVOID FAR* lplpDD)
{
    DirectDrawSurface4LogMethodValue(DEBUG, GetDDInterface, 1, (lplpDD));

    CONST HRESULT result = this->State.Self->GetDDInterface(lplpDD);

    if (SUCCEEDED(result)) { *lplpDD = ActivateAgentDelegate(DirectDraw4, *lplpDD); }

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, GetDDInterface, result, 1, (lplpDD));
}

// Prevents a system-memory surface from being paged out while a bit block transfer (bitblt) operation
// that uses direct memory access (DMA) transfers to or from system memory is in progress.
HRESULT DirectDrawSurface4::PageLock(DWORD dwFlags)
{
    DirectDrawSurface4LogMethodValue(DEBUG, PageLock, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->PageLock(dwFlags);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, PageLock, result, 1, (dwFlags));
}

// Unlocks a system-memory surface, which then allows it to be paged out.
HRESULT DirectDrawSurface4::PageUnlock(DWORD dwFlags)
{
    DirectDrawSurface4LogMethodValue(DEBUG, PageUnlock, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->PageUnlock(dwFlags);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, PageUnlock, result, 1, (dwFlags));
}

// Sets the characteristics of an existing surface.
HRESULT DirectDrawSurface4::SetSurfaceDesc(LPDDSURFACEDESC2 lpDDSurfaceDesc, DWORD dwFlags)
{
    DirectDrawSurface4LogMethodValue(DEBUG, SetSurfaceDesc, 2, (lpDDSurfaceDesc, dwFlags));

    CONST HRESULT result = this->State.Self->SetSurfaceDesc(lpDDSurfaceDesc, dwFlags);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, SetSurfaceDesc, result, 2, (lpDDSurfaceDesc, dwFlags));
}

// Associates data with the surface that is intended for use by the application, not by DirectDraw.
// Data is passed by value, and multiple sets of data can be associated with a single surface.
HRESULT DirectDrawSurface4::SetPrivateData(REFGUID riid, LPVOID lpData, DWORD dwDataSize, DWORD dwFlags)
{
    DirectDrawSurface4LogMethodValue(DEBUG, SetPrivateData, 4, (riid, lpData, dwDataSize, dwFlags));

    CONST HRESULT result = this->State.Self->SetPrivateData(riid, lpData, dwDataSize, dwFlags);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, SetPrivateData, result, 4, (riid, lpData, dwDataSize, dwFlags));
}

// Copies the private data that is associated with this surface to a provided buffer.
HRESULT DirectDrawSurface4::GetPrivateData(REFGUID riid, LPVOID lpBuffer, LPDWORD lpdwBufferSize)
{
    DirectDrawSurface4LogMethodValue(DEBUG, GetPrivateData, 3, (riid, lpBuffer, lpdwBufferSize));

    CONST HRESULT result = this->State.Self->GetPrivateData(riid, lpBuffer, lpdwBufferSize);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, GetPrivateData, result, 3, (riid, lpBuffer, lpdwBufferSize));
}

// Frees the specified private data that is associated with this surface.
HRESULT DirectDrawSurface4::FreePrivateData(REFGUID riid)
{
    DirectDrawSurface4LogMethodValue(DEBUG, FreePrivateData, 1, (riid));

    CONST HRESULT result = this->State.Self->FreePrivateData(riid);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, FreePrivateData, result, 1, (riid));
}

// Retrieves the current uniqueness value for this surface.
HRESULT DirectDrawSurface4::GetUniquenessValue(LPDWORD lpdwValue)
{
    DirectDrawSurface4LogMethodValue(DEBUG, GetUniquenessValue, 1, (lpdwValue));

    CONST HRESULT result = this->State.Self->GetUniquenessValue(lpdwValue);

    DirectDrawSurface4LogMethodResultValue(DEBUGINFO, GetUniquenessValue, result, 1, (lpdwValue));
}

// Manually updates the uniqueness value for this surface.
HRESULT DirectDrawSurface4::ChangeUniquenessValue()
{
    DirectDrawSurface4LogMethod(DEBUG, ChangeUniquenessValue);

    CONST HRESULT result = this->State.Self->ChangeUniquenessValue();

    DirectDrawSurface4LogMethodResult(DEBUGINFO, ChangeUniquenessValue, result);
}