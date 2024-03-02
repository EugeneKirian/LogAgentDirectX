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

#include "ModuleLogger.hxx"
#include "ModuleTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(Module, AcquireDDThreadLock);             \
        A(Module, CompleteCreateSysmemSurface);     \
        A(Module, D3DParseUnknownCommand);          \
        A(Module, DDGetAttachedSurfaceLcl);         \
        A(Module, DDInternalLock);                  \
        A(Module, DDInternalUnlock);                \
        A(Module, DSoundHelp);                      \
        A(Module, DirectDrawCreate);                \
        A(Module, DirectDrawCreateClipper);         \
        A(Module, DirectDrawCreateEx);              \
        A(Module, DirectDrawEnumerateA);            \
        A(Module, DirectDrawEnumerateExA);          \
        A(Module, DirectDrawEnumerateExW);          \
        A(Module, DirectDrawEnumerateW);            \
        A(Module, DllCanUnloadNow);                 \
        A(Module, DllGetClassObject);               \
        A(Module, GetDDSurfaceLocal);               \
        A(Module, GetOLEThunkData);                 \
        A(Module, GetSurfaceFromDC);                \
        A(Module, RegisterSpecialCase);             \
        A(Module, ReleaseDDThreadLock);             \
        A(Module, SetAppCompatData);                \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerModuleMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerModuleAcquireDDThreadLockValue(LPSTRINGBUILDER builder, CONST LPMODULEACQUIREDDTHREADLOCKMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerModuleCompleteCreateSysmemSurfaceValue(LPSTRINGBUILDER builder, CONST LPMODULECOMPLETECREATESYSMEMSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerModuleD3DParseUnknownCommandValue(LPSTRINGBUILDER builder, CONST LPMODULED3DPARSEUNKNOWNCOMMANDMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Commands /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Result /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDDGetAttachedSurfaceLclValue(LPSTRINGBUILDER builder, CONST LPMODULEDDGETATTACHEDSURFACELCLMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Result); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDDInternalLockValue(LPSTRINGBUILDER builder, CONST LPMODULEDDINTERNALLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Bits /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDDInternalUnlockValue(LPSTRINGBUILDER builder, CONST LPMODULEDDINTERNALUNLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDSoundHelpValue(LPSTRINGBUILDER builder, CONST LPMODULEDSOUNDHELPMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatWindow, value->Window);
    FORMATVALUE(builder, TextFormatObject, value->WndProc);
    FORMATVALUE(builder, TextFormatValue, value->Process); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectDrawCreateValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTDRAWCREATEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->Device);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectDrawCreateClipperValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTDRAWCREATECLIPPERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}
static CONST BOOL AcquireLoggerModuleDirectDrawCreateExValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTDRAWCREATEEXMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->Device);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatID, value->IID);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectDrawEnumerateAValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTDRAWENUMERATEAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectDrawEnumerateExAValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTDRAWENUMERATEEXAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectDrawEnumerateExWValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTDRAWENUMERATEEXWMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectDrawEnumerateWValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTDRAWENUMERATEWMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDllCanUnloadNowValue(LPSTRINGBUILDER builder, CONST LPMODULEDLLCANUNLOADNOWMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerModuleDllGetClassObjectValue(LPSTRINGBUILDER builder, CONST LPMODULEDLLGETCLASSOBJECTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatID, value->IID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerModuleGetDDSurfaceLocalValue(LPSTRINGBUILDER builder, CONST LPMODULEGETDDSURFACELOCALMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatValue, value->Handle);
    FORMATVALUE(builder, TextFormatObject, value->IsNew); return TRUE;
}

static CONST BOOL AcquireLoggerModuleGetOLEThunkDataValue(LPSTRINGBUILDER builder, CONST LPMODULEGETOLETHUNKDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Ordinal); return TRUE;
}

static CONST BOOL AcquireLoggerModuleGetSurfaceFromDCValue(LPSTRINGBUILDER builder, CONST LPMODULEGETSURFACEFROMDCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->DC);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Driver); return TRUE;
}

static CONST BOOL AcquireLoggerModuleRegisterSpecialCaseValue(LPSTRINGBUILDER builder, CONST LPMODULEREGISTERSPECIALCASEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Param1);
    FORMATVALUE(builder, TextFormatValue, value->Param2);
    FORMATVALUE(builder, TextFormatValue, value->Param3);
    FORMATVALUE(builder, TextFormatValue, value->Param4); return TRUE;
}

static CONST BOOL AcquireLoggerModuleReleaseDDThreadLockValue(LPSTRINGBUILDER builder, CONST LPMODULERELEASEDDTHREADLOCKMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerModuleSetAppCompatDataValue(LPSTRINGBUILDER builder, CONST LPMODULESETAPPCOMPATDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Type);
    FORMATVALUE(builder, TextFormatValue, value->Value); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerModuleMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                                  \
    switch (ID)                                     \
    {                                               \
        A(Module, DirectDrawEnumerateA);            \
        A(Module, DirectDrawEnumerateExA);          \
        A(Module, DirectDrawEnumerateExW);          \
        A(Module, DirectDrawEnumerateW);            \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerModuleMethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerModuleDirectDrawEnumerateACallbackValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTDRAWENUMERATEAMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatString, value->Description);
    FORMATVALUE(builder, TextFormatString, value->Name); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectDrawEnumerateExACallbackValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTDRAWENUMERATEEXAMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatString, value->Description);
    FORMATVALUE(builder, TextFormatString, value->Name);
    FORMATVALUE(builder, TextFormatObject, value->Monitor); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectDrawEnumerateExWCallbackValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTDRAWENUMERATEEXWMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatString, value->Description);
    FORMATVALUE(builder, TextFormatString, value->Name);
    FORMATVALUE(builder, TextFormatObject, value->Monitor); return TRUE;
}

static CONST BOOL AcquireLoggerModuleDirectDrawEnumerateWCallbackValue(LPSTRINGBUILDER builder, CONST LPMODULEDIRECTDRAWENUMERATEWMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatString, value->Description);
    FORMATVALUE(builder, TextFormatString, value->Name); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerModuleMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}