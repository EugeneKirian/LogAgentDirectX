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
#include "Direct3DDevice7.hxx"
#include "Direct3DVertexBuffer7.hxx"
#include "DirectDraw.hxx"
#include "DirectDraw2.hxx"
#include "DirectDraw4.hxx"
#include "DirectDraw7.hxx"
#include "DirectDrawSurface7.hxx"
#include "DirectDrawVideoPortContainer.hxx"

#include <AgentLogger.hxx>
#include <Direct3D7Logger.hxx>

#define Direct3D7LogMethod(L, M) AgentLogMethod(L, Direct3D7, M)
#define Direct3D7LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3D7, M, C, PARAMS)

#define Direct3D7LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3D7, AddRef, R)
#define Direct3D7LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3D7, Release, R)

#define Direct3D7LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3D7, M, R)
#define Direct3D7LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3D7, M, R, C, PARAMS)

#define Direct3D7LogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, Direct3D7, M, C, PARAMS)
#define Direct3D7LogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, Direct3D7, M, R, C, PARAMS)

typedef struct EnumDevicesCallbackContext
{
    Direct3D7* Self;
    LPLOGGER Logger;
    LPD3DENUMDEVICESCALLBACK7 EnumDevicesCallback;
    LPVOID Context;
} ENUMDEVICESCALLBACKCONTEXT, * LPENUMDEVICESCALLBACKCONTEXT;

static HRESULT CALLBACK EnumDevicesCallback(LPSTR lpDeviceDescription, LPSTR lpDeviceName, LPD3DDEVICEDESC7 lpD3DDeviceDesc, LPVOID lpContext)
{
    LPENUMDEVICESCALLBACKCONTEXT context = (LPENUMDEVICESCALLBACKCONTEXT)lpContext;

    Direct3D7LogMethodCallbackValue(TRACEDEBUG, EnumDevices, 4, (context->Self, lpDeviceDescription, lpDeviceName, lpD3DDeviceDesc));

    CONST HRESULT result = context->EnumDevicesCallback(lpDeviceDescription, lpDeviceName, lpD3DDeviceDesc, context->Context);

    Direct3D7LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumDevices, result, 4, (context->Self, lpDeviceDescription, lpDeviceName, lpD3DDeviceDesc));
}

typedef struct EnumZBufferFormatsCallbackContext
{
    Direct3D7* Self;
    LPLOGGER Logger;
    LPD3DENUMPIXELFORMATSCALLBACK EnumCallback;
    LPVOID Context;
} ENUMZBUFFERFORMATSCALLBACKCONTEXT, * LPENUMZBUFFERFORMATSCALLBACKCONTEXT;

static HRESULT CALLBACK EnumZBufferFormatsCallback(LPDDPIXELFORMAT lpDDPixFmt, LPVOID lpContext)
{
    LPENUMZBUFFERFORMATSCALLBACKCONTEXT context = (LPENUMZBUFFERFORMATSCALLBACKCONTEXT)lpContext;

    Direct3D7LogMethodCallbackValue(TRACEDEBUG, EnumZBufferFormats, 2, (context->Self, lpDDPixFmt));

    CONST HRESULT result = context->EnumCallback(lpDDPixFmt, context->Context);

    Direct3D7LogMethodCallbackResultValue(TRACEDEBUGINFO, EnumZBufferFormats, result, 2, (context->Self, lpDDPixFmt));
}

Direct3D7::Direct3D7(AgentConstructorParameters(Direct3D7))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3D7);
}

Direct3D7::~Direct3D7()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3D7);
}

HRESULT Direct3D7::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3D7LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectDraw, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(DirectDraw, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw2, riid)) { *ppvObj = ActivateAgent(DirectDraw2, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw4, riid)) { *ppvObj = ActivateAgent(DirectDraw4, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw7, riid)) { *ppvObj = ActivateAgent(DirectDraw7, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawVideoPortContainer, riid)) { *ppvObj = ActivateAgent(DirectDrawVideoPortContainer, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3D7LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3D7::AddRef()
{
    Direct3D7LogMethod(DEBUG, AddRef);
    Direct3D7LogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG Direct3D7::Release()
{
    Direct3D7LogMethod(DEBUG, Release);
    Direct3D7LogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Enumerates all Direct3D device drivers installed on the system.
HRESULT Direct3D7::EnumDevices(LPD3DENUMDEVICESCALLBACK7 lpEnumDevicesCallback, LPVOID lpContext)
{
    Direct3D7LogMethodValue(DEBUGINFO, EnumDevices, 2, (lpEnumDevicesCallback, lpContext));

    if (lpEnumDevicesCallback == NULL) { Direct3D7LogMethodResultValue(TRACEDEBUGINFO, EnumDevices, DDERR_INVALIDPARAMS, 2, (lpEnumDevicesCallback, lpContext)); }

    ENUMDEVICESCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumDevicesCallback = lpEnumDevicesCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumDevices(EnumDevicesCallback, &context);

    Direct3D7LogMethodResultValue(TRACEDEBUGINFO, EnumDevices, result, 2, (lpEnumDevicesCallback, lpContext));
}

// Creates a Direct3D device to be used with the DrawPrimitive methods.
HRESULT Direct3D7::CreateDevice(REFCLSID rclsid, LPDIRECTDRAWSURFACE7 lpDDS, LPDIRECT3DDEVICE7* lplpD3DDevice)
{
    Direct3D7LogMethodValue(TRACE, CreateDevice, 3, (rclsid, lpDDS, lplpD3DDevice));

    AttemptAccessAgentValue(DirectDrawSurface7, lpDDS);

    CONST HRESULT result = this->State.Self->CreateDevice(rclsid, lpDDS, lplpD3DDevice);

    if (SUCCEEDED(result)) { *lplpD3DDevice = ActivateAgentDelegate(Direct3DDevice7, *lplpD3DDevice); }

    Direct3D7LogMethodResultValue(TRACEDEBUGINFO, CreateDevice, result, 3, (rclsid, lpDDS, lplpD3DDevice));
}

// Creates a vertex buffer object.
HRESULT Direct3D7::CreateVertexBuffer(LPD3DVERTEXBUFFERDESC lpVBDesc, LPDIRECT3DVERTEXBUFFER7* lplpD3DVertexBuffer, DWORD dwFlags)
{
    Direct3D7LogMethodValue(TRACE, CreateVertexBuffer, 3, (lpVBDesc, lplpD3DVertexBuffer, dwFlags));

    CONST HRESULT result = this->State.Self->CreateVertexBuffer(lpVBDesc, lplpD3DVertexBuffer, dwFlags);

    if (SUCCEEDED(result)) { *lplpD3DVertexBuffer = ActivateAgentDelegate(Direct3DVertexBuffer7, *lplpD3DVertexBuffer); }

    Direct3D7LogMethodResultValue(TRACEDEBUGINFO, CreateVertexBuffer, result, 3, (lpVBDesc, lplpD3DVertexBuffer, dwFlags));
}

// Enumerates the supported depth-buffer formats for a specified device.
HRESULT Direct3D7::EnumZBufferFormats(REFCLSID riidDevice, LPD3DENUMPIXELFORMATSCALLBACK lpEnumCallback, LPVOID lpContext)
{
    Direct3D7LogMethodValue(DEBUGINFO, EnumZBufferFormats, 3, (riidDevice, lpEnumCallback, lpContext));

    if (lpEnumCallback == NULL) { Direct3D7LogMethodResultValue(TRACEDEBUGINFO, EnumZBufferFormats, DDERR_INVALIDPARAMS, 3, (riidDevice, lpEnumCallback, lpContext)); }

    ENUMZBUFFERFORMATSCALLBACKCONTEXT context;

    context.Self = this;
    context.EnumCallback = lpEnumCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumZBufferFormats(riidDevice, EnumZBufferFormatsCallback, &context);

    Direct3D7LogMethodResultValue(TRACEDEBUGINFO, EnumZBufferFormats, result, 3, (riidDevice, lpEnumCallback, lpContext));
}

// Evicts all managed textures from local or nonlocal video memory.
HRESULT Direct3D7::EvictManagedTextures()
{
    Direct3D7LogMethod(DEBUG, EvictManagedTextures);

    CONST HRESULT result = this->State.Self->EvictManagedTextures();

    Direct3D7LogMethodResult(DEBUGINFO, EvictManagedTextures, result);
}