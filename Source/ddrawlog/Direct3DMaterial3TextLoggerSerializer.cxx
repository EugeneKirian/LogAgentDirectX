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
#include "Direct3DMaterial3Logger.hxx"
#include "Direct3DMaterial3TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(Direct3DMaterial3, QueryInterface);       \
        A(Direct3DMaterial3, AddRef);               \
        A(Direct3DMaterial3, Release);              \
        A(Direct3DMaterial3, SetMaterial);          \
        A(Direct3DMaterial3, GetMaterial);          \
        A(Direct3DMaterial3, GetHandle);            \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DMaterial3MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DMaterial3QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DMATERIAL3QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DMaterial3AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DMATERIAL3ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DMaterial3ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DMATERIAL3RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DMaterial3SetMaterialValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DMATERIAL3SETMATERIALMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Material /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DMaterial3GetMaterialValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DMATERIAL3GETMATERIALMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Material /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DMaterial3GetHandleValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DMATERIAL3GETHANDLEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Device);
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DMaterial3MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3DMaterial3MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3DMaterial3MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }