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

#include "Agent.hxx"
#include "Base.hxx"
#include "DirectSound.hxx"
#include "DirectSound8.hxx"
#include "DirectSoundBuffer8.hxx"
#include "DirectSoundCapture.hxx"
#include "DirectSoundCaptureBuffer8.hxx"
#include "DirectSoundFullDuplex.hxx"
#include "Export.hxx"
#include "Module.hxx"

#include <ModuleLogger.hxx>

#define ModuleLogMethod(LEVEL, M) LogMethodMacro(Module.Logger, LEVEL, Module, M, NULL)

#define ModuleLogMethodValue(LEVEL, M, C, PARAMS) LogMethodValueMacro(Module.Logger, LEVEL, Module, M, NULL, C, PARAMS)

#define ModuleLogMethodVoidResult(LEVEL, M)                                                                                             \
    if (Module.Logger->IsAcceptable(LOGGER_LEVEL_##LEVEL))                                                                              \
    {                                                                                                                                   \
        LogMethodResult(Module.Logger, LOGGER_LEVEL_##LEVEL, OBJECT_ID_Module, NULL, METHOD_ID_Module_##M, (DWORD)NULL, NULL);          \
    }

#define ModuleLogMethodResult(LEVEL, M, ERR, RT, R) LogMethodResultMacro(Module.Logger, LEVEL, Module, M, NULL, ERR, RT, R)

#define ModuleLogMethodResultValue(LEVEL, M, ERR, RT, R, C, PARAMS) LogMethodResultValueMacro(Module.Logger, LEVEL, Module, M, NULL, ERR, RT, R, C, PARAMS)

#define ModuleLogMethodCallbackValue(LEVEL, M, C, PARAMS) LogMethodCallbackValueMacro(Module.Logger, LEVEL, Module, M, M, NULL, C, PARAMS)

#define ModuleLogMethodCallbackResultValue(LEVEL, M, RT, R, C, PARAMS) LogMethodCallbackResultValueMacro(Module.Logger, LEVEL, Module, M, M, NULL, RT, R, C, PARAMS)

typedef struct DirectSoundCaptureEnumerateCallbackContextA
{
    LPDSENUMCALLBACKA Callback;
    LPVOID Context;
} DIRECTSOUNDCAPTUREENUMERATECALLBACKCONTEXTA, * LPDIRECTSOUNDCAPTUREENUMERATECALLBACKCONTEXTA;

static BOOL CALLBACK DirectSoundCaptureEnumerateCallbackA(LPGUID lpGuid, LPCSTR lpcstrDescription, LPCSTR lpcstrModule, LPVOID lpContext)
{
    ModuleLogMethodCallbackValue(TRACEDEBUG, DirectSoundCaptureEnumerateA, 3, (lpGuid, lpcstrDescription, lpcstrModule));

    LPDIRECTSOUNDCAPTUREENUMERATECALLBACKCONTEXTA context = (LPDIRECTSOUNDCAPTUREENUMERATECALLBACKCONTEXTA)lpContext;

    CONST BOOL result = context->Callback(lpGuid, lpcstrDescription, lpcstrModule, context->Context);

    ModuleLogMethodCallbackResultValue(TRACEDEBUGINFO, DirectSoundCaptureEnumerateA, BOOL, result, 3, (lpGuid, lpcstrDescription, lpcstrModule));
}

typedef struct DirectSoundCaptureEnumerateCallbackContextW
{
    LPDSENUMCALLBACKW Callback;
    LPVOID Context;
} DIRECTSOUNDCAPTUREENUMERATECALLBACKCONTEXTW, * LPDIRECTSOUNDCAPTUREENUMERATECALLBACKCONTEXTW;

static BOOL CALLBACK DirectSoundCaptureEnumerateCallbackW(LPGUID lpGuid, LPCWSTR lpcstrDescription, LPCWSTR lpcstrModule, LPVOID lpContext)
{
    ModuleLogMethodCallbackValue(TRACEDEBUG, DirectSoundCaptureEnumerateW, 3, (lpGuid, lpcstrDescription, lpcstrModule));

    LPDIRECTSOUNDCAPTUREENUMERATECALLBACKCONTEXTW context = (LPDIRECTSOUNDCAPTUREENUMERATECALLBACKCONTEXTW)lpContext;

    CONST BOOL result = context->Callback(lpGuid, lpcstrDescription, lpcstrModule, context->Context);

    ModuleLogMethodCallbackResultValue(TRACEDEBUGINFO, DirectSoundCaptureEnumerateW, BOOL, result, 3, (lpGuid, lpcstrDescription, lpcstrModule));
}

typedef struct DirectSoundEnumerateCallbackContextA
{
    LPDSENUMCALLBACKA Callback;
    LPVOID Context;
} DIRECTSOUNDENUMERATECALLBACKCONTEXTA, * LPDIRECTSOUNDENUMERATECALLBACKCONTEXTA;

static BOOL CALLBACK DirectSoundEnumerateCallbackA(LPGUID lpGuid, LPCSTR lpcstrDescription, LPCSTR lpcstrModule, LPVOID lpContext)
{
    ModuleLogMethodCallbackValue(TRACEDEBUG, DirectSoundEnumerateA, 3, (lpGuid, lpcstrDescription, lpcstrModule));

    LPDIRECTSOUNDENUMERATECALLBACKCONTEXTA context = (LPDIRECTSOUNDENUMERATECALLBACKCONTEXTA)lpContext;

    CONST BOOL result = context->Callback(lpGuid, lpcstrDescription, lpcstrModule, context->Context);

    ModuleLogMethodCallbackResultValue(TRACEDEBUGINFO, DirectSoundEnumerateA, BOOL, result, 3, (lpGuid, lpcstrDescription, lpcstrModule));
}

typedef struct DirectSoundEnumerateCallbackContextW
{
    LPDSENUMCALLBACKW Callback;
    LPVOID Context;
} DIRECTSOUNDENUMERATECALLBACKCONTEXTW, * LPDIRECTSOUNDENUMERATECALLBACKCONTEXTW;

static BOOL CALLBACK DirectSoundEnumerateCallbackW(LPGUID lpGuid, LPCWSTR lpcstrDescription, LPCWSTR lpcstrModule, LPVOID lpContext)
{
    ModuleLogMethodCallbackValue(TRACEDEBUG, DirectSoundEnumerateW, 3, (lpGuid, lpcstrDescription, lpcstrModule));

    LPDIRECTSOUNDENUMERATECALLBACKCONTEXTW context = (LPDIRECTSOUNDENUMERATECALLBACKCONTEXTW)lpContext;

    CONST BOOL result = context->Callback(lpGuid, lpcstrDescription, lpcstrModule, context->Context);

    ModuleLogMethodCallbackResultValue(TRACEDEBUGINFO, DirectSoundEnumerateW, BOOL, result, 3, (lpGuid, lpcstrDescription, lpcstrModule));
}

// The DirectSoundCaptureCreate function creates and initializes an object that supports the IDirectSoundCapture interface.
extern "C" HRESULT WINAPI DirectSoundCaptureCreate(LPCGUID lpcGUID, LPDIRECTSOUNDCAPTURE * lplpDSC, LPUNKNOWN pUnkOuter)
{
    ModuleLogMethodValue(TRACE, DirectSoundCaptureCreate, 3, (lpcGUID, lplpDSC, pUnkOuter));

    CONST HRESULT result = Module.DirectSoundCaptureCreate(lpcGUID, lplpDSC, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDSC = AssembleAgent(DirectSoundCapture, Module.Assembler, (new AssemblerDelegate(Module.Assembler)), Module.Logger, *lplpDSC); }

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectSoundCaptureCreate, FAILED(result), HRESULT, result, 3, (lpcGUID, lplpDSC, pUnkOuter));
}

// The DirectSoundCaptureCreate8 function creates and initializes an object that supports the IDirectSoundCapture8 interface.
// Although the older DirectSoundCaptureCreate function can also be used to obtain the IDirectSoundCapture8 interface,
// the object created by that function cannot be used to create capture buffers that support the IDirectSoundCaptureBuffer8 interface.
extern "C" HRESULT WINAPI DirectSoundCaptureCreate8(LPCGUID lpcGUID, LPDIRECTSOUNDCAPTURE8 * lplpDSC, LPUNKNOWN pUnkOuter)
{
    ModuleLogMethodValue(TRACE, DirectSoundCaptureCreate8, 3, (lpcGUID, lplpDSC, pUnkOuter));

    if (Module.DirectSoundCaptureCreate8 == NULL) { ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectSoundCaptureCreate8, TRUE, HRESULT, DSERR_UNSUPPORTED, 3, (lpcGUID, lplpDSC, pUnkOuter)); }

    CONST HRESULT result = Module.DirectSoundCaptureCreate8(lpcGUID, lplpDSC, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDSC = AssembleAgent(DirectSoundCapture, Module.Assembler, (new AssemblerDelegate(Module.Assembler)), Module.Logger, *lplpDSC); }

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectSoundCaptureCreate8, FAILED(result), HRESULT, result, 3, (lpcGUID, lplpDSC, pUnkOuter));
}

// The DirectSoundCaptureEnumerate function enumerates the DirectSoundCapture objects installed in the system.
extern "C" HRESULT WINAPI DirectSoundCaptureEnumerateA(LPDSENUMCALLBACKA lpDSEnumCallback, LPVOID lpContext)
{
    ModuleLogMethodValue(DEBUGINFO, DirectSoundCaptureEnumerateA, 2, (lpDSEnumCallback, lpContext));

    if (lpDSEnumCallback == NULL) { ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectSoundCaptureEnumerateA, TRUE, HRESULT, DSERR_INVALIDPARAM, 2, (lpDSEnumCallback, lpContext)); }

    DIRECTSOUNDCAPTUREENUMERATECALLBACKCONTEXTA context;

    context.Callback = lpDSEnumCallback;
    context.Context = lpContext;

    CONST HRESULT result = Module.DirectSoundCaptureEnumerateA(DirectSoundCaptureEnumerateCallbackA, &context);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectSoundCaptureEnumerateA, FAILED(result), HRESULT, result, 2, (lpDSEnumCallback, lpContext));
}

// The DirectSoundCaptureEnumerate function enumerates the DirectSoundCapture objects installed in the system.
extern "C" HRESULT WINAPI DirectSoundCaptureEnumerateW(LPDSENUMCALLBACKW lpDSEnumCallback, LPVOID lpContext)
{
    ModuleLogMethodValue(DEBUGINFO, DirectSoundCaptureEnumerateW, 2, (lpDSEnumCallback, lpContext));

    if (lpDSEnumCallback == NULL) { ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectSoundCaptureEnumerateW, TRUE, HRESULT, DSERR_INVALIDPARAM, 2, (lpDSEnumCallback, lpContext)); }

    DIRECTSOUNDCAPTUREENUMERATECALLBACKCONTEXTW context;

    context.Callback = lpDSEnumCallback;
    context.Context = lpContext;

    CONST HRESULT result = Module.DirectSoundCaptureEnumerateW(DirectSoundCaptureEnumerateCallbackW, &context);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectSoundCaptureEnumerateW, FAILED(result), HRESULT, result, 2, (lpDSEnumCallback, lpContext));
}

// This function creates and initializes an IDirectSound interface.
extern "C" HRESULT WINAPI DirectSoundCreate(LPCGUID lpcGuid, LPDIRECTSOUND * ppDS, LPUNKNOWN pUnkOuter)
{
    ModuleLogMethodValue(TRACE, DirectSoundCreate, 3, (lpcGuid, ppDS, pUnkOuter));

    CONST HRESULT result = Module.DirectSoundCreate(lpcGuid, ppDS, pUnkOuter);

    if (SUCCEEDED(result)) { *ppDS = AssembleAgent(DirectSound, Module.Assembler, (new AssemblerDelegate(Module.Assembler)), Module.Logger, *ppDS); }

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectSoundCreate, FAILED(result), HRESULT, result, 3, (lpcGuid, ppDS, pUnkOuter));
}

// The DirectSoundCreate8 function creates and initializes an object that supports the IDirectSound8 interface.
extern "C" HRESULT WINAPI DirectSoundCreate8(LPCGUID lpcGuidDevice, LPDIRECTSOUND8 * ppDS8, LPUNKNOWN pUnkOuter)
{
    ModuleLogMethodValue(TRACE, DirectSoundCreate8, 3, (lpcGuidDevice, ppDS8, pUnkOuter));

    if (Module.DirectSoundCreate8 == NULL) { ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectSoundCreate8, TRUE, HRESULT, DSERR_UNSUPPORTED, 3, (lpcGuidDevice, ppDS8, pUnkOuter)); }

    CONST HRESULT result = Module.DirectSoundCreate8(lpcGuidDevice, ppDS8, pUnkOuter);

    if (SUCCEEDED(result)) { *ppDS8 = AssembleAgent(DirectSound8, Module.Assembler, (new AssemblerDelegate(Module.Assembler)), Module.Logger, *ppDS8); }

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectSoundCreate8, FAILED(result), HRESULT, result, 3, (lpcGuidDevice, ppDS8, pUnkOuter));
}

// The DirectSoundEnumerate function enumerates the DirectSound drivers installed in the system.
extern "C" HRESULT WINAPI DirectSoundEnumerateA(LPDSENUMCALLBACKA lpDSEnumCallback, LPVOID lpContext)
{
    ModuleLogMethodValue(DEBUGINFO, DirectSoundEnumerateA, 2, (lpDSEnumCallback, lpContext));

    if (lpDSEnumCallback == NULL) { ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectSoundEnumerateA, TRUE, HRESULT, DSERR_INVALIDPARAM, 2, (lpDSEnumCallback, lpContext)); }

    DIRECTSOUNDENUMERATECALLBACKCONTEXTA context;

    context.Callback = lpDSEnumCallback;
    context.Context = lpContext;

    CONST HRESULT result = Module.DirectSoundEnumerateA(DirectSoundEnumerateCallbackA, &context);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectSoundEnumerateA, FAILED(result), HRESULT, result, 2, (lpDSEnumCallback, lpContext));
}

// The DirectSoundEnumerate function enumerates the DirectSound drivers installed in the system.
extern "C" HRESULT WINAPI DirectSoundEnumerateW(LPDSENUMCALLBACKW lpDSEnumCallback, LPVOID lpContext)
{
    ModuleLogMethodValue(DEBUGINFO, DirectSoundEnumerateW, 2, (lpDSEnumCallback, lpContext));

    if (lpDSEnumCallback == NULL) { ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectSoundEnumerateW, TRUE, HRESULT, DSERR_INVALIDPARAM, 2, (lpDSEnumCallback, lpContext)); }

    DIRECTSOUNDENUMERATECALLBACKCONTEXTW context;

    context.Callback = lpDSEnumCallback;
    context.Context = lpContext;

    CONST HRESULT result = Module.DirectSoundEnumerateW(DirectSoundEnumerateCallbackW, &context);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectSoundEnumerateW, FAILED(result), HRESULT, result, 2, (lpDSEnumCallback, lpContext));
}

// he DirectSoundFullDuplexCreate8 function creates the DirectSound and DirectSoundCapture objects and returns the IDirectSoundFullDuplex8 interface.
// This function requires Microsoft Windows XP. Full duplex can be implemented on other operating systems, but the capture and rendering devices must be created separately.
extern "C" HRESULT WINAPI DirectSoundFullDuplexCreate(LPCGUID pcGuidCaptureDevice, LPCGUID pcGuidRenderDevice, LPCDSCBUFFERDESC pcDSCBufferDesc, LPCDSBUFFERDESC pcDSBufferDesc, HWND hWnd, DWORD dwLevel, LPDIRECTSOUNDFULLDUPLEX * ppDSFD, LPDIRECTSOUNDCAPTUREBUFFER8 * ppDSCBuffer8, LPDIRECTSOUNDBUFFER8 * ppDSBuffer8, LPUNKNOWN pUnkOuter)
{
    ModuleLogMethodValue(TRACE, DirectSoundFullDuplexCreate, 10, (pcGuidCaptureDevice, pcGuidRenderDevice, pcDSCBufferDesc, pcDSBufferDesc, hWnd, dwLevel, ppDSFD, ppDSCBuffer8, ppDSBuffer8, pUnkOuter));

    if (Module.DirectSoundFullDuplexCreate == NULL) { ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectSoundFullDuplexCreate, TRUE, HRESULT, DSERR_UNSUPPORTED, 10, (pcGuidCaptureDevice, pcGuidRenderDevice, pcDSCBufferDesc, pcDSBufferDesc, hWnd, dwLevel, ppDSFD, ppDSCBuffer8, ppDSBuffer8, pUnkOuter)); }

    CONST HRESULT result = Module.DirectSoundFullDuplexCreate(pcGuidCaptureDevice, pcGuidRenderDevice, pcDSCBufferDesc, pcDSBufferDesc, hWnd, dwLevel, ppDSFD, ppDSCBuffer8, ppDSBuffer8, pUnkOuter);

    if (SUCCEEDED(result))
    {
        LPASSEMBLERDELEGATE delegate = new AssemblerDelegate(Module.Assembler);

        *ppDSFD = AssembleAgent(DirectSoundFullDuplex, Module.Assembler, delegate, Module.Logger, *ppDSFD);
        *ppDSCBuffer8 = AssembleAgent(DirectSoundCaptureBuffer8, Module.Assembler, delegate, Module.Logger, *ppDSCBuffer8);
        *ppDSBuffer8 = AssembleAgent(DirectSoundBuffer8, Module.Assembler, delegate, Module.Logger, *ppDSBuffer8);
    }

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectSoundFullDuplexCreate, FAILED(result), HRESULT, result, 10, (pcGuidCaptureDevice, pcGuidRenderDevice, pcDSCBufferDesc, pcDSBufferDesc, hWnd, dwLevel, ppDSFD, ppDSCBuffer8, ppDSBuffer8, pUnkOuter));
}

extern "C" HRESULT WINAPI DllCanUnloadNow(VOID)
{
    ModuleLogMethod(DEBUG, DllCanUnloadNow);

    CONST HRESULT result = Module.DllCanUnloadNow();

    ModuleLogMethodResult(DEBUG, DllCanUnloadNow, FAILED(result), HRESULT, result);
}

extern "C" HRESULT WINAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID * ppv)
{
    ModuleLogMethodValue(TRACE, DllGetClassObject, 3, (rclsid, riid, ppv));

    CONST HRESULT result = Module.DllGetClassObject(rclsid, riid, ppv);

    ModuleLogMethodResultValue(DEBUG, DllGetClassObject, FAILED(result), HRESULT, result, 3, (rclsid, riid, ppv));
}

// The GetDeviceID function retrieves the unique device identifier of the default playback and capture devices selected by the user in Control Panel.
extern "C" HRESULT WINAPI GetDeviceID(LPCGUID pGuidSrc, LPGUID pGuidDest)
{
    ModuleLogMethodValue(TRACE, GetDeviceID, 2, (pGuidSrc, pGuidDest));

    CONST HRESULT result = Module.GetDeviceID(pGuidSrc, pGuidDest);

    ModuleLogMethodResultValue(DEBUG, GetDeviceID, FAILED(result), HRESULT, result, 2, (pGuidSrc, pGuidDest));
}