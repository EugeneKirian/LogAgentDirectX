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

#pragma once

#include "Base.hxx"

typedef struct ModuleAcquireDDThreadLockMethodValue
{

} MODULEACQUIREDDTHREADLOCKMETHODVALUE, * LPMODULEACQUIREDDTHREADLOCKMETHODVALUE;

typedef struct ModuleCompleteCreateSysmemSurfaceMethodValue
{
    LPVOID Object;
} MODULECOMPLETECREATESYSMEMSURFACEMETHODVALUE, * LPMODULECOMPLETECREATESYSMEMSURFACEMETHODVALUE;

typedef struct ModuleD3DParseUnknownCommandMethodValue
{
    LPVOID Commands;
    LPVOID* Result;
} MODULED3DPARSEUNKNOWNCOMMANDMETHODVALUE, * LPMODULED3DPARSEUNKNOWNCOMMANDMETHODVALUE;

typedef struct ModuleDDGetAttachedSurfaceLclMethodValue
{
    LPVOID Object;
    LPDDSCAPS2 Caps;
    LPVOID Result; /* TODO */
} MODULEDDGETATTACHEDSURFACELCLMETHODVALUE, * LPMODULEDDGETATTACHEDSURFACELCLMETHODVALUE;

typedef struct ModuleDDInternalLockMethodValue
{
    LPVOID Object;
    LPVOID* Bits;
} MODULEDDINTERNALLOCKMETHODVALUE, * LPMODULEDDINTERNALLOCKMETHODVALUE;

typedef struct ModuleDDInternalUnlockMethodValue
{
    LPVOID Object;
} MODULEDDINTERNALUNLOCKMETHODVALUE, * LPMODULEDDINTERNALUNLOCKMETHODVALUE;

typedef struct ModuleDSoundHelpMethodValue
{
    HWND Window;
    WNDPROC WndProc;
    DWORD Process;
} MODULEDSOUNDHELPMETHODVALUE, * LPMODULEDSOUNDHELPMETHODVALUE;

typedef struct ModuleDirectDrawCreateMethodValue
{
    LPGUID Device;
    LPDIRECTDRAW* Object;
    LPUNKNOWN Unknown;
} MODULEDIRECTDRAWCREATEMETHODVALUE, * LPMODULEDIRECTDRAWCREATEMETHODVALUE;

typedef struct ModuleDirectDrawCreateClipperMethodValue
{
    DWORD Options;
    LPDIRECTDRAWCLIPPER* Object;
    LPUNKNOWN Unknown;
} MODULEDIRECTDRAWCREATECLIPPERMETHODVALUE, * LPMODULEDIRECTDRAWCREATECLIPPERMETHODVALUE;

typedef struct ModuleDirectDrawCreateExMethodValue
{
    LPGUID Device;
    LPVOID* Object;
    GUID IID;
    LPUNKNOWN Unknown;
} MODULEDIRECTDRAWCREATEEXMETHODVALUE, * LPMODULEDIRECTDRAWCREATEEXMETHODVALUE;

typedef struct ModuleDirectDrawEnumerateAMethodValue
{
    LPDDENUMCALLBACKA Callback;
    LPVOID Context;
} MODULEDIRECTDRAWENUMERATEAMETHODVALUE, * LPMODULEDIRECTDRAWENUMERATEAMETHODVALUE;

typedef struct ModuleDirectDrawEnumerateExAMethodValue
{
    LPDDENUMCALLBACKEXA Callback;
    LPVOID Context;
    DWORD Options;
} MODULEDIRECTDRAWENUMERATEEXAMETHODVALUE, * LPMODULEDIRECTDRAWENUMERATEEXAMETHODVALUE;

typedef struct ModuleDirectDrawEnumerateExWMethodValue
{
    LPDDENUMCALLBACKEXW Callback;
    LPVOID Context;
    DWORD Options;
} MODULEDIRECTDRAWENUMERATEEXWMETHODVALUE, * LPMODULEDIRECTDRAWENUMERATEEXWMETHODVALUE;

typedef struct ModuleDirectDrawEnumerateWMethodValue
{
    LPDDENUMCALLBACKW Callback;
    LPVOID Context;
} MODULEDIRECTDRAWENUMERATEWMETHODVALUE, * LPMODULEDIRECTDRAWENUMERATEWMETHODVALUE;

typedef struct ModuleDllCanUnloadNowMethodValue
{

} MODULEDLLCANUNLOADNOWMETHODVALUE, * LPMODULEDLLCANUNLOADNOWMETHODVALUE;

typedef struct ModuleDllGetClassObjectMethodValue
{
    GUID ID;
    GUID IID;
    LPVOID* Object;
} MODULEDLLGETCLASSOBJECTMETHODVALUE, * LPMODULEDLLGETCLASSOBJECTMETHODVALUE;

typedef struct ModuleGetDDSurfaceLocalMethodValue
{
    LPVOID Object;
    DWORD Handle;
    BOOL* IsNew;
} MODULEGETDDSURFACELOCALMETHODVALUE, * LPMODULEGETDDSURFACELOCALMETHODVALUE;

typedef struct ModuleGetOLEThunkDataMethodValue
{
    ULONG_PTR Ordinal;
} MODULEGETOLETHUNKDATAMETHODVALUE, * LPMODULEGETOLETHUNKDATAMETHODVALUE;

typedef struct ModuleGetSurfaceFromDCMethodValue
{
    HDC DC;
    LPDIRECTDRAWSURFACE* Surface;
    HDC* Driver;
} MODULEGETSURFACEFROMDCMETHODVALUE, * LPMODULEGETSURFACEFROMDCMETHODVALUE;

typedef struct ModuleRegisterSpecialCaseMethodValue
{
    DWORD Param1;
    DWORD Param2;
    DWORD Param3;
    DWORD Param4;
} MODULEREGISTERSPECIALCASEMETHODVALUE, * LPMODULEREGISTERSPECIALCASEMETHODVALUE;

typedef struct ModuleReleaseDDThreadLockMethodValue
{

} MODULERELEASEDDTHREADLOCKMETHODVALUE, * LPMODULERELEASEDDTHREADLOCKMETHODVALUE;

typedef struct ModuleSetAppCompatDataMethodValue
{
    DWORD Type;
    DWORD Value;
} MODULESETAPPCOMPATDATAMETHODVALUE, * LPMODULESETAPPCOMPATDATAMETHODVALUE;

typedef struct ModuleDirectDrawEnumerateAMethodCallbackValue
{
    LPGUID ID;
    LPSTR Description;
    LPSTR Name;
} MODULEDIRECTDRAWENUMERATEAMETHODCALLBACKVALUE, * LPMODULEDIRECTDRAWENUMERATEAMETHODCALLBACKVALUE;

typedef struct ModuleDirectDrawEnumerateExAMethodCallbackValue
{
    LPGUID ID;
    LPSTR Description;
    LPSTR Name;
    HMONITOR Monitor;
} MODULEDIRECTDRAWENUMERATEEXAMETHODCALLBACKVALUE, * LPMODULEDIRECTDRAWENUMERATEEXAMETHODCALLBACKVALUE;

typedef struct ModuleDirectDrawEnumerateExWMethodCallbackValue
{
    LPGUID ID;
    LPWSTR Description;
    LPWSTR Name;
    HMONITOR Monitor;
} MODULEDIRECTDRAWENUMERATEEXWMETHODCALLBACKVALUE, * LPMODULEDIRECTDRAWENUMERATEEXWMETHODCALLBACKVALUE;

typedef struct ModuleDirectDrawEnumerateWMethodCallbackValue
{
    LPGUID ID;
    LPWSTR Description;
    LPWSTR Name;
} MODULEDIRECTDRAWENUMERATEWMETHODCALLBACKVALUE, * LPMODULEDIRECTDRAWENUMERATEWMETHODCALLBACKVALUE;