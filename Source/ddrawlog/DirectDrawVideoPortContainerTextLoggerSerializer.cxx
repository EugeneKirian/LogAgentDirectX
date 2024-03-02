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
#include "DirectDrawVideoPortContainerLogger.hxx"
#include "DirectDrawVideoPortContainerTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                                   \
    switch (ID)                                                     \
    {                                                               \
        A(DirectDrawVideoPortContainer, QueryInterface);            \
        A(DirectDrawVideoPortContainer, AddRef);                    \
        A(DirectDrawVideoPortContainer, Release);                   \
        A(DirectDrawVideoPortContainer, CreateVideoPort);           \
        A(DirectDrawVideoPortContainer, EnumVideoPorts);            \
        A(DirectDrawVideoPortContainer, GetVideoPortConnectInfo);   \
        A(DirectDrawVideoPortContainer, QueryVideoPortStatus);      \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawVideoPortContainerMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortContainerQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTCONTAINERQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortContainerAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTCONTAINERADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawVideoPortContainerReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTCONTAINERRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawVideoPortContainerCreateVideoPortValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTCONTAINERCREATEVIDEOPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->VideoPort);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortContainerEnumVideoPortsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTCONTAINERENUMVIDEOPORTSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->EnumVideoCallback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortContainerGetVideoPortConnectInfoValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTCONTAINERGETVIDEOPORTCONNECTINFOMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->ID);
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->ConnectInfo /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortContainerQueryVideoPortStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTCONTAINERQUERYVIDEOPORTSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Status /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectDrawVideoPortContainerMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                                          \
    switch (ID)                                             \
    {                                                       \
        A(DirectDrawVideoPortContainer, EnumVideoPorts);    \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawVideoPortContainerMethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortContainerEnumVideoPortsCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTCONTAINERENUMVIDEOPORTSMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirectDrawVideoPortContainerMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}