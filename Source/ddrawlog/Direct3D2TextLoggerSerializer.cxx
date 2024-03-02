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
#include "Direct3D2Logger.hxx"
#include "Direct3D2TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                           \
    switch (ID)                             \
    {                                       \
        A(Direct3D2, QueryInterface);       \
        A(Direct3D2, AddRef);               \
        A(Direct3D2, Release);              \
        A(Direct3D2, EnumDevices);          \
        A(Direct3D2, CreateLight);          \
        A(Direct3D2, CreateMaterial);       \
        A(Direct3D2, CreateViewport);       \
        A(Direct3D2, FindDevice);           \
        A(Direct3D2, CreateDevice);         \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3D2MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3D2QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D2QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D2AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D2ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3D2ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D2RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3D2EnumDevicesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D2ENUMDEVICESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D2CreateLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D2CREATELIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Light);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D2CreateMaterialValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D2CREATEMATERIALMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Material);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D2CreateViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D2CREATEVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D2FindDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D2FINDDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Search /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Result /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D2CreateDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D2CREATEDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Device); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3D2MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                          \
    switch (ID)                             \
    {                                       \
        A(Direct3D2, EnumDevices);          \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3D2MethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3D2EnumDevicesCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D2ENUMDEVICESMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatString, value->Description);
    FORMATVALUE(builder, TextFormatString, value->Name);
    FORMATVALUE(builder, TextFormatObject, value->HardwareDescriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->EmulationDescriptor /* TODO */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirect3D2MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}