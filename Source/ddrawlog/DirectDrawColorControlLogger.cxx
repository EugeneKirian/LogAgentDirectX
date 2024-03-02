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
#include "DirectDrawColorControlLogger.hxx"
#include "DirectDrawColorControlTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                           \
    switch (ID)                                             \
    {                                                       \
        A(DirectDrawColorControl, QueryInterface);          \
        A(DirectDrawColorControl, AddRef);                  \
        A(DirectDrawColorControl, Release);                 \
        A(DirectDrawColorControl, GetColorControls);        \
        A(DirectDrawColorControl, SetColorControls);        \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawColorControlMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawColorControlQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCOLORCONTROLQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawColorControlAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCOLORCONTROLADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawColorControlReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCOLORCONTROLRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawColorControlGetColorControlsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCOLORCONTROLGETCOLORCONTROLSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ColorControl); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawColorControlSetColorControlsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCOLORCONTROLSETCOLORCONTROLSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ColorControl); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectDrawColorControlMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirectDrawColorControlMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirectDrawColorControlMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }