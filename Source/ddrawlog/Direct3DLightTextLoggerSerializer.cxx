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

#include "AgentLogger.hxx"
#include "Direct3DLightLogger.hxx"
#include "Direct3DLightTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                               \
    switch (ID)                                 \
    {                                           \
        A(Direct3DLight, QueryInterface);       \
        A(Direct3DLight, AddRef);               \
        A(Direct3DLight, Release);              \
        A(Direct3DLight, Initialize);           \
        A(Direct3DLight, SetLight);             \
        A(Direct3DLight, GetLight);             \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DLightMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DLightQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DLIGHTQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DLightAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DLIGHTADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DLightReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DLIGHTRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DLightInitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DLIGHTINITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DLightSetLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DLIGHTSETLIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Light /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DLightGetLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DLIGHTGETLIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Light /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DLightMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DLightMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DLightMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }