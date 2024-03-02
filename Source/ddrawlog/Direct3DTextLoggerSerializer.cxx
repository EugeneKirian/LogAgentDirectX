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
#include "Direct3DLogger.hxx"
#include "Direct3DTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                           \
    switch (ID)                             \
    {                                       \
        A(Direct3D, QueryInterface);        \
        A(Direct3D, AddRef);                \
        A(Direct3D, Release);               \
        A(Direct3D, Initialize);            \
        A(Direct3D, EnumDevices);           \
        A(Direct3D, CreateLight);           \
        A(Direct3D, CreateMaterial);        \
        A(Direct3D, CreateViewport);        \
        A(Direct3D, FindDevice);            \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DInitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DINITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DEnumDevicesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DENUMDEVICESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DCreateLightValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCREATELIGHTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Light);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DCreateMaterialValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCREATEMATERIALMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Material);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DCreateViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DCREATEVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DFindDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DFINDDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Search /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Result /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                          \
    switch (ID)                             \
    {                                       \
        A(Direct3D, EnumDevices);           \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DMethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DEnumDevicesCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DENUMDEVICESMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatString, value->Description);
    FORMATVALUE(builder, TextFormatString, value->Name);
    FORMATVALUE(builder, TextFormatObject, value->HardwareDescriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->EmulationDescriptor /* TODO */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirect3DMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}