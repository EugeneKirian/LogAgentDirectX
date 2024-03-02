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
#include "Direct3DDeviceLogger.hxx"
#include "Direct3DDeviceTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                               \
    switch (ID)                                 \
    {                                           \
        A(Direct3DDevice, QueryInterface);      \
        A(Direct3DDevice, AddRef);              \
        A(Direct3DDevice, Release);             \
        A(Direct3DDevice, Initialize);          \
        A(Direct3DDevice, GetCaps);             \
        A(Direct3DDevice, SwapTextureHandles);  \
        A(Direct3DDevice, CreateExecuteBuffer); \
        A(Direct3DDevice, GetStats);            \
        A(Direct3DDevice, Execute);             \
        A(Direct3DDevice, AddViewport);         \
        A(Direct3DDevice, DeleteViewport);      \
        A(Direct3DDevice, NextViewport);        \
        A(Direct3DDevice, Pick);                \
        A(Direct3DDevice, GetPickRecords);      \
        A(Direct3DDevice, EnumTextureFormats);  \
        A(Direct3DDevice, CreateMatrix);        \
        A(Direct3DDevice, SetMatrix);           \
        A(Direct3DDevice, GetMatrix);           \
        A(Direct3DDevice, DeleteMatrix);        \
        A(Direct3DDevice, BeginScene);          \
        A(Direct3DDevice, EndScene);            \
        A(Direct3DDevice, GetDirect3D);         \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DDeviceMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DDeviceQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDeviceAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDeviceReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICERELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDeviceInitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEINITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatID, value->GUID);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDeviceGetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEGETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->HardwareDescriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->EmulationDescriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDeviceSwapTextureHandlesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICESWAPTEXTUREHANDLESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Texture1);
    FORMATVALUE(builder, TextFormatObject, value->Texture2); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDeviceCreateExecuteBufferValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICECREATEEXECUTEBUFFERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Buffer);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDeviceGetStatsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEGETSTATSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Statistics /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDeviceExecuteValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEEXECUTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Buffer);
    FORMATVALUE(builder, TextFormatObject, value->ViewPort);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDeviceAddViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEADDVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDeviceDeleteViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEDELETEVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDeviceNextViewportValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICENEXTVIEWPORTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ViewPort);
    FORMATVALUE(builder, TextFormatObject, value->NextViewPort);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDevicePickValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEPICKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Buffer);
    FORMATVALUE(builder, TextFormatObject, value->ViewPort);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Rect /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDeviceGetPickRecordsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEGETPICKRECORDSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Records /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDeviceEnumTextureFormatsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEENUMTEXTUREFORMATSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Callback);
    FORMATVALUE(builder, TextFormatObject, value->Context); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDeviceCreateMatrixValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICECREATEMATRIXMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDeviceSetMatrixValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICESETMATRIXMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle);
    FORMATVALUE(builder, TextFormatObject, value->Matrix /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDeviceGetMatrixValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEGETMATRIXMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle);
    FORMATVALUE(builder, TextFormatObject, value->Matrix /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDeviceDeleteMatrixValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEDELETEMATRIXMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Handle); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3DDeviceBeginSceneValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEBEGINSCENEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDeviceEndSceneValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEENDSCENEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3DDeviceGetDirect3DValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEGETDIRECT3DMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3DDeviceMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                              \
    switch (ID)                                 \
    {                                           \
        A(Direct3DDevice, EnumTextureFormats);  \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3DDeviceMethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3DDeviceEnumTextureFormatsCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECT3DDEVICEENUMTEXTUREFORMATSMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirect3DDeviceMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}