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
#include "Direct3DMaterial2Logger.hxx"
#include "Direct3DMaterial2TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(Direct3DMaterial2, QueryInterface);       \
        A(Direct3DMaterial2, AddRef);               \
        A(Direct3DMaterial2, Release);              \
        A(Direct3DMaterial2, SetMaterial);          \
        A(Direct3DMaterial2, GetMaterial);          \
        A(Direct3DMaterial2, GetHandle);            \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DMaterial2MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DMaterial2QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DMATERIAL2QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DMaterial2AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DMATERIAL2ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DMaterial2ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DMATERIAL2RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DMaterial2SetMaterialValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DMATERIAL2SETMATERIALMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Material /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DMaterial2GetMaterialValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DMATERIAL2GETMATERIALMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Material /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DMaterial2GetHandleValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DMATERIAL2GETHANDLEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Device);
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DMaterial2MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DMaterial2MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DMaterial2MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }