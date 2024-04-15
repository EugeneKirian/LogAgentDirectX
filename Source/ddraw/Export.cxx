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
#include "DirectDraw.hxx"
#include "DirectDraw7.hxx"
#include "DirectDrawClipper.hxx"
#include "DirectDrawSurface.hxx"
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

typedef struct DirectDrawEnumerateCallbackContextA
{
    LPDDENUMCALLBACKA Callback;
    LPVOID Context;
} DIRECTDRAWENUMERATECALLBACKCONTEXTA, * LPDIRECTDRAWENUMERATECALLBACKCONTEXTA;

typedef struct DirectDrawEnumerateCallbackContextW
{
    LPDDENUMCALLBACKW Callback;
    LPVOID Context;
} DIRECTDRAWENUMERATECALLBACKCONTEXTW, * LPDIRECTDRAWENUMERATECALLBACKCONTEXTW;

typedef struct DirectDrawEnumerateExCallbackContextA
{
    LPDDENUMCALLBACKEXA Callback;
    LPVOID Context;
} DIRECTDRAWENUMERATEEXCALLBACKCONTEXTA, * LPDIRECTDRAWENUMERATEEXCALLBACKCONTEXTA;

typedef struct DirectDrawEnumerateExCallbackContextW
{
    LPDDENUMCALLBACKEXW Callback;
    LPVOID Context;
} DIRECTDRAWENUMERATEEXCALLBACKCONTEXTW, * LPDIRECTDRAWENUMERATEEXCALLBACKCONTEXTW;

static BOOL CALLBACK DirectDrawEnumerateCallbackA(LPGUID lpGUID, LPSTR lpDriverDescription, LPSTR lpDriverName, LPVOID Context)
{
    ModuleLogMethodCallbackValue(TRACEDEBUG, DirectDrawEnumerateA, 3, (lpGUID, lpDriverDescription, lpDriverName));

    LPDIRECTDRAWENUMERATECALLBACKCONTEXTA context = (LPDIRECTDRAWENUMERATECALLBACKCONTEXTA)Context;

    CONST BOOL result = context->Callback(lpGUID, lpDriverDescription, lpDriverName, context->Context);

    ModuleLogMethodCallbackResultValue(TRACEDEBUGINFO, DirectDrawEnumerateA, BOOL, result, 3, (lpGUID, lpDriverDescription, lpDriverName));
}

static BOOL CALLBACK DirectDrawEnumerateExCallbackA(LPGUID lpGUID, LPSTR lpDriverDescription, LPSTR lpDriverName, LPVOID Context, HMONITOR hMonitor)
{
    ModuleLogMethodCallbackValue(TRACEDEBUG, DirectDrawEnumerateExA, 4, (lpGUID, lpDriverDescription, lpDriverName, hMonitor));

    LPDIRECTDRAWENUMERATEEXCALLBACKCONTEXTA context = (LPDIRECTDRAWENUMERATEEXCALLBACKCONTEXTA)Context;

    CONST BOOL result = context->Callback(lpGUID, lpDriverDescription, lpDriverName, context->Context, hMonitor);

    ModuleLogMethodCallbackResultValue(TRACEDEBUGINFO, DirectDrawEnumerateExA, BOOL, result, 4, (lpGUID, lpDriverDescription, lpDriverName, hMonitor));
}

static BOOL CALLBACK DirectDrawEnumerateExCallbackW(LPGUID lpGUID, LPWSTR lpDriverDescription, LPWSTR lpDriverName, LPVOID Context, HMONITOR hMonitor)
{
    ModuleLogMethodCallbackValue(TRACEDEBUG, DirectDrawEnumerateExW, 4, (lpGUID, lpDriverDescription, lpDriverName, hMonitor));

    LPDIRECTDRAWENUMERATEEXCALLBACKCONTEXTW context = (LPDIRECTDRAWENUMERATEEXCALLBACKCONTEXTW)Context;

    CONST BOOL result = context->Callback(lpGUID, lpDriverDescription, lpDriverName, context->Context, hMonitor);

    ModuleLogMethodCallbackResultValue(TRACEDEBUGINFO, DirectDrawEnumerateExW, BOOL, result, 4, (lpGUID, lpDriverDescription, lpDriverName, hMonitor));
}

static BOOL CALLBACK DirectDrawEnumerateCallbackW(LPGUID lpGUID, LPWSTR lpDriverDescription, LPWSTR lpDriverName, LPVOID Context)
{
    ModuleLogMethodCallbackValue(TRACEDEBUG, DirectDrawEnumerateW, 3, (lpGUID, lpDriverDescription, lpDriverName));

    LPDIRECTDRAWENUMERATECALLBACKCONTEXTW context = (LPDIRECTDRAWENUMERATECALLBACKCONTEXTW)Context;

    const BOOL result = context->Callback(lpGUID, lpDriverDescription, lpDriverName, context->Context);

    ModuleLogMethodCallbackResultValue(TRACEDEBUGINFO, DirectDrawEnumerateW, BOOL, result, 3, (lpGUID, lpDriverDescription, lpDriverName));
}

extern "C" VOID WINAPI AcquireDDThreadLock(VOID)
{
    ModuleLogMethod(TRACE, AcquireDDThreadLock);

    Module.AcquireInternalLock();

    ModuleLogMethodVoidResult(DEBUG, AcquireDDThreadLock);
}

extern "C" BOOL WINAPI CompleteCreateSysmemSurface(LPDDRAWI_DDRAWSURFACE_LCL lpSurfLcl)
{
    ModuleLogMethodValue(TRACE, CompleteCreateSysmemSurface, 1, (lpSurfLcl));

    CONST BOOL result = Module.CompleteCreateSysmemSurface(lpSurfLcl);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, CompleteCreateSysmemSurface, result != TRUE, BOOL, result, 1, (lpSurfLcl));
}

extern "C" HRESULT WINAPI D3DParseUnknownCommand(LPVOID lpvCommands, LPVOID * lplpvReturnedCommand)
{
    ModuleLogMethodValue(TRACE, D3DParseUnknownCommand, 2, (lpvCommands, lplpvReturnedCommand));
    
    CONST HRESULT result = Module.ParseUnknownCommand(lpvCommands, lplpvReturnedCommand);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, D3DParseUnknownCommand, FAILED(result), HRESULT, result, 2, (lpvCommands, lplpvReturnedCommand));
}

extern "C" HRESULT WINAPI DDGetAttachedSurfaceLcl(LPDDRAWI_DDRAWSURFACE_LCL this_lcl, LPDDSCAPS2 lpDDSCaps, LPDDRAWI_DDRAWSURFACE_LCL * lplpDDAttachedSurfaceLcl)
{
    ModuleLogMethodValue(TRACE, DDGetAttachedSurfaceLcl, 3, (this_lcl, lpDDSCaps, lplpDDAttachedSurfaceLcl));

    CONST HRESULT result = Module.GetAttachedSurfaceLocal(this_lcl, lpDDSCaps, lplpDDAttachedSurfaceLcl);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DDGetAttachedSurfaceLcl, FAILED(result), HRESULT, result, 3, (this_lcl, lpDDSCaps, lplpDDAttachedSurfaceLcl));
}

extern "C" HRESULT WINAPI DDInternalLock(LPDDRAWI_DDRAWSURFACE_LCL this_lcl, LPVOID * lpBits)
{
    ModuleLogMethodValue(TRACE, DDInternalLock, 2, (this_lcl, lpBits));

    CONST HRESULT result = Module.InternalLock(this_lcl, lpBits);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DDInternalLock, FAILED(result), HRESULT, result, 2, (this_lcl, lpBits));
}

extern "C" HRESULT WINAPI DDInternalUnlock(LPDDRAWI_DDRAWSURFACE_LCL this_lcl)
{
    ModuleLogMethodValue(TRACE, DDInternalUnlock, 1, (this_lcl));

    CONST HRESULT result = Module.InternalUnlock(this_lcl);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DDInternalUnlock, FAILED(result), HRESULT, result, 1, (this_lcl));
}

extern "C" HRESULT WINAPI DSoundHelp(HWND hWnd, WNDPROC lpWndProc, DWORD pid)
{
    ModuleLogMethodValue(TRACE, DSoundHelp, 3, (hWnd, lpWndProc, pid));

    CONST HRESULT result = Module.DirectSoundHelp(hWnd, lpWndProc, pid);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DSoundHelp, FAILED(result), HRESULT, result, 3, (hWnd, lpWndProc, pid));
}

// Creates an instance of a DirectDraw object.
extern "C" HRESULT WINAPI DirectDrawCreate(LPGUID lpGUID, LPDIRECTDRAW * lplpDD, LPUNKNOWN pUnkOuter)
{
    ModuleLogMethodValue(TRACE, DirectDrawCreate, 3, (lpGUID, lplpDD, pUnkOuter));

    CONST HRESULT result = Module.DirectDrawCreate(lpGUID, lplpDD, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDD = AssembleAgent(DirectDraw, Module.Assembler, (new AssemblerDelegate(Module.Assembler)), Module.Logger, *lplpDD); }

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectDrawCreate, FAILED(result), HRESULT, result, 3, (lpGUID, lplpDD, pUnkOuter));
}

// Creates an instance of a DirectDrawClipper object not associated with a DirectDraw object.
extern "C" HRESULT WINAPI DirectDrawCreateClipper(DWORD dwFlags, LPDIRECTDRAWCLIPPER * lplpDDClipper, LPUNKNOWN pUnkOuter)
{
    ModuleLogMethodValue(TRACE, DirectDrawCreateClipper, 3, (dwFlags, lplpDDClipper, pUnkOuter));

    CONST HRESULT result = Module.DirectDrawCreateClipper(dwFlags, lplpDDClipper, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDDClipper = AssembleAgent(DirectDrawClipper, Module.Assembler, (new AssemblerDelegate(Module.Assembler)), Module.Logger, *lplpDDClipper); }

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectDrawCreateClipper, FAILED(result), HRESULT, result, 3, (dwFlags, lplpDDClipper, pUnkOuter));
}

// Creates an instance of a DirectDraw object that supports the set of Direct3D interfaces in DirectX 7.0.
extern "C" HRESULT WINAPI DirectDrawCreateEx(LPGUID lpGuid, LPVOID * lplpDD, REFIID riid, LPUNKNOWN pUnkOuter)
{
    ModuleLogMethodValue(TRACE, DirectDrawCreateEx, 4, (lpGuid, lplpDD, riid, pUnkOuter));

    CONST HRESULT result = Module.DirectDrawCreateEx(lpGuid, lplpDD, riid, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDD = AssembleAgent(DirectDraw7, Module.Assembler, (new AssemblerDelegate(Module.Assembler)), Module.Logger, *lplpDD); }

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectDrawCreateEx, FAILED(result), HRESULT, result, 4, (lpGuid, lplpDD, riid, pUnkOuter));
}

// Enumerates the primary DirectDraw display device and a non-display device
// (such as a 3-D accelerator that has no 2-D capabilities) if one is installed.
// The NULL entry always identifies the primary display device shared with GDI.
extern "C" HRESULT WINAPI DirectDrawEnumerateA(LPDDENUMCALLBACKA lpCallback, LPVOID lpContext)
{
    ModuleLogMethodValue(TRACEDEBUG, DirectDrawEnumerateA, 2, (lpCallback, lpContext));

    if (lpCallback == NULL) { ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectDrawEnumerateA, TRUE, HRESULT, DDERR_INVALIDPARAMS, 2, (lpCallback, lpContext)); }

    DIRECTDRAWENUMERATECALLBACKCONTEXTA context;

    context.Callback = lpCallback;
    context.Context = lpContext;

    CONST HRESULT result = Module.DirectDrawEnumerateA(DirectDrawEnumerateCallbackA, &context);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectDrawEnumerateA, FAILED(result), HRESULT, result, 2, (lpCallback, lpContext));
}

// Enumerates all DirectDraw devices installed on the system.
// The NULL entry always identifies the primary display device shared with GDI.
extern "C" HRESULT WINAPI DirectDrawEnumerateExA(LPDDENUMCALLBACKEXA lpCallback, LPVOID lpContext, DWORD dwFlags)
{
    ModuleLogMethodValue(TRACEDEBUG, DirectDrawEnumerateExA, 3, (lpCallback, lpContext, dwFlags));

    if (lpCallback == NULL) { ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectDrawEnumerateExA, TRUE, HRESULT, DDERR_INVALIDPARAMS, 3, (lpCallback, lpContext, dwFlags)); }

    DIRECTDRAWENUMERATEEXCALLBACKCONTEXTA context;

    context.Callback = lpCallback;
    context.Context = lpContext;

    CONST HRESULT result = Module.DirectDrawEnumerateExA(DirectDrawEnumerateExCallbackA, &context, dwFlags);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectDrawEnumerateExA, FAILED(result), HRESULT, result, 3, (lpCallback, lpContext, dwFlags));
}

// Enumerates all DirectDraw devices installed on the system.
// The NULL entry always identifies the primary display device shared with GDI.
extern "C" HRESULT WINAPI DirectDrawEnumerateExW(LPDDENUMCALLBACKEXW lpCallback, LPVOID lpContext, DWORD dwFlags)
{
    ModuleLogMethodValue(TRACEDEBUG, DirectDrawEnumerateExW, 3, (lpCallback, lpContext, dwFlags));

    if (lpCallback == NULL) { ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectDrawEnumerateExW, TRUE, HRESULT, DDERR_INVALIDPARAMS, 3, (lpCallback, lpContext, dwFlags)); }

    DIRECTDRAWENUMERATEEXCALLBACKCONTEXTW context;

    context.Callback = lpCallback;
    context.Context = lpContext;

    CONST HRESULT result = Module.DirectDrawEnumerateExW(DirectDrawEnumerateExCallbackW, &context, dwFlags);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectDrawEnumerateExW, FAILED(result), HRESULT, result, 3, (lpCallback, lpContext, dwFlags));
}

// Enumerates the primary DirectDraw display device and a non-display device
// (such as a 3-D accelerator that has no 2-D capabilities) if one is installed.
// The NULL entry always identifies the primary display device shared with GDI.
extern "C" HRESULT WINAPI DirectDrawEnumerateW(LPDDENUMCALLBACKW lpCallback, LPVOID lpContext)
{
    ModuleLogMethodValue(TRACEDEBUG, DirectDrawEnumerateW, 2, (lpCallback, lpContext));

    if (lpCallback == NULL) { ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectDrawEnumerateW, TRUE, HRESULT, DDERR_INVALIDPARAMS, 2, (lpCallback, lpContext)); }

    DIRECTDRAWENUMERATECALLBACKCONTEXTW context;

    context.Callback = lpCallback;
    context.Context = lpContext;

    CONST HRESULT result = Module.DirectDrawEnumerateW(DirectDrawEnumerateCallbackW, &context);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, DirectDrawEnumerateW, FAILED(result), HRESULT, result, 2, (lpCallback, lpContext));
}

extern "C" HRESULT WINAPI DllCanUnloadNow(VOID)
{
    ModuleLogMethod(TRACE, DllCanUnloadNow);

    CONST HRESULT result = Module.DllCanUnloadNow();

    ModuleLogMethodResult(TRACEDEBUG, DllCanUnloadNow, FAILED(result), HRESULT, result);
}

extern "C" HRESULT WINAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID * ppv)
{
    ModuleLogMethodValue(TRACE, DllGetClassObject, 3, (rclsid, riid, ppv));
    
    CONST HRESULT result = Module.DllGetClassObject(rclsid, riid, ppv);

    ModuleLogMethodResultValue(TRACEDEBUG, DllGetClassObject, FAILED(result), HRESULT, result, 3, (rclsid, riid, ppv));
}

extern "C" LPDDRAWI_DDRAWSURFACE_LCL WINAPI GetDDSurfaceLocal(LPDDRAWI_DIRECTDRAW_LCL this_lcl, DWORD handle, BOOL * isnew)
{
    ModuleLogMethodValue(TRACE, GetDDSurfaceLocal, 3, (this_lcl, handle, isnew));

    CONST LPDDRAWI_DDRAWSURFACE_LCL result = Module.GetDirectDrawSurfaceLocal(this_lcl, handle, isnew);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, GetDDSurfaceLocal, result == NULL, LPDDRAWI_DDRAWSURFACE_LCL, result, 3, (this_lcl, handle, isnew));
}

extern "C" ULONG_PTR WINAPI GetOLEThunkData(ULONG_PTR dwOrdinal)
{
    ModuleLogMethodValue(TRACE, GetOLEThunkData, 1, (dwOrdinal));
    
    CONST ULONG_PTR result = Module.GetOLEThunkData(dwOrdinal);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, GetOLEThunkData, FALSE, ULONG_PTR, result, 1, (dwOrdinal));
}

extern "C" HRESULT WINAPI GetSurfaceFromDC(HDC hDC, LPDIRECTDRAWSURFACE * ppdds, HDC * phdcDriver)
{
    ModuleLogMethodValue(TRACE, GetSurfaceFromDC, 3, (hDC, ppdds, phdcDriver));

    CONST HRESULT result = Module.GetSurfaceFromDeviceContext(hDC, ppdds, phdcDriver);

    if (SUCCEEDED(result)) { *ppdds = AssembleAgent(DirectDrawSurface, Module.Assembler, (new AssemblerDelegate(Module.Assembler)), Module.Logger, *ppdds); }

    ModuleLogMethodResultValue(TRACEDEBUGINFO, GetSurfaceFromDC, FAILED(result), HRESULT, result, 3, (hDC, ppdds, phdcDriver));
}

extern "C" HRESULT WINAPI RegisterSpecialCase(DWORD dwParam1, DWORD dwParam2, DWORD dwParam3, DWORD dwParam4)
{
    ModuleLogMethodValue(TRACE, RegisterSpecialCase, 4, (dwParam1, dwParam2, dwParam3, dwParam4));
    
    CONST HRESULT result = Module.RegisterSpecialCase(dwParam1, dwParam2, dwParam3, dwParam4);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, RegisterSpecialCase, FAILED(result), HRESULT, result, 4, (dwParam1, dwParam2, dwParam3, dwParam4));
}

extern "C" VOID WINAPI ReleaseDDThreadLock(VOID)
{
    ModuleLogMethod(TRACE, ReleaseDDThreadLock);

    Module.ReleaseThreadLock();

    ModuleLogMethodVoidResult(TRACE, ReleaseDDThreadLock);
}

extern "C" HRESULT WINAPI SetAppCompatData(DWORD dwType, DWORD dwValue)
{
    ModuleLogMethodValue(TRACE, SetAppCompatData, 2, (dwType, dwValue));

    if (Module.SetApplicationCompatibilityData == NULL) { ModuleLogMethodResultValue(TRACEDEBUGINFO, SetAppCompatData, TRUE, HRESULT, DDERR_UNSUPPORTED, 2, (dwType, dwValue)); }

    CONST HRESULT result = Module.SetApplicationCompatibilityData(dwType, dwValue);

    ModuleLogMethodResultValue(TRACEDEBUGINFO, SetAppCompatData, FAILED(result), HRESULT, result, 2, (dwType, dwValue));
}