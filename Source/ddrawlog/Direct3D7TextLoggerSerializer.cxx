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
#include "Direct3D7Logger.hxx"
#include "Direct3D7TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                           \
    switch (ID)                             \
    {                                       \
        A(Direct3D7, QueryInterface);       \
        A(Direct3D7, AddRef);               \
        A(Direct3D7, Release);              \
        A(Direct3D7, EnumDevices);          \
        A(Direct3D7, CreateDevice);         \
        A(Direct3D7, CreateVertexBuffer);   \
        A(Direct3D7, EnumZBufferFormats);   \
        A(Direct3D7, EvictManagedTextures); \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3D7MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3D7QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D7QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D7AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D7ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3D7ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D7RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3D7EnumDevicesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D7ENUMDEVICESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D7CreateDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D7CREATEDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Device); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D7CreateVertexBufferValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D7CREATEVERTEXBUFFERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Buffer);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D7EnumZBufferFormatsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D7ENUMZBUFFERFORMATSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D7EvictManagedTexturesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D7EVICTMANAGEDTEXTURESMETHODVALUE value) { return TRUE; }

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3D7MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                          \
    switch (ID)                             \
    {                                       \
        A(Direct3D7, EnumDevices);          \
        A(Direct3D7, EnumZBufferFormats);   \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3D7MethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3D7EnumDevicesCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D7ENUMDEVICESMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatString, value->Description);
    FORMATVALUE(builder, TextFormatString, value->Name);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D7EnumZBufferFormatsCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D7ENUMZBUFFERFORMATSMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Format /* TODOD */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirect3D7MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}