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
#include "Direct3D8Logger.hxx"
#include "Direct3D8TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(Direct3D8, QueryInterface);                   \
        A(Direct3D8, AddRef);                           \
        A(Direct3D8, Release);                          \
        A(Direct3D8, RegisterSoftwareDevice);           \
        A(Direct3D8, GetAdapterCount);                  \
        A(Direct3D8, GetAdapterIdentifier);             \
        A(Direct3D8, GetAdapterModeCount);              \
        A(Direct3D8, EnumAdapterModes);                 \
        A(Direct3D8, GetAdapterDisplayMode);            \
        A(Direct3D8, CheckDeviceType);                  \
        A(Direct3D8, CheckDeviceFormat);                \
        A(Direct3D8, CheckDeviceMultiSampleType);       \
        A(Direct3D8, CheckDepthStencilMatch);           \
        A(Direct3D8, GetDeviceCaps);                    \
        A(Direct3D8, GetAdapterMonitor);                \
        A(Direct3D8, CreateDevice);                     \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirect3D8MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirect3D8QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D8QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D8AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D8ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3D8ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D8RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3D8RegisterSoftwareDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D8REGISTERSOFTWAREDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->InitializeFunction); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D8GetAdapterCountValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D8GETADAPTERCOUNTMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirect3D8GetAdapterIdentifierValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D8GETADAPTERIDENTIFIERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Adapter);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TOOD */);
    FORMATVALUE(builder, TextFormatObject, value->Identifier /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D8GetAdapterModeCountValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D8GETADAPTERMODECOUNTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Adapter); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D8EnumAdapterModesValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D8ENUMADAPTERMODESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Adapter);
    FORMATVALUE(builder, TextFormatValue, value->ModeIndex);
    FORMATVALUE(builder, TextFormatObject, value->Mode /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D8GetAdapterDisplayModeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D8GETADAPTERDISPLAYMODEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Adapter);
    FORMATVALUE(builder, TextFormatObject, value->Mode /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D8CheckDeviceTypeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D8CHECKDEVICETYPEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Adapter);
    FORMATVALUE(builder, TextFormatValue, value->CheckType /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->DisplayFormat /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->BackBufferFormat /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Windowed); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D8CheckDeviceFormatValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D8CHECKDEVICEFORMATMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Adapter);
    FORMATVALUE(builder, TextFormatValue, value->DeviceType /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->AdapterFormat /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Usage /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->ResourceType /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->CheckFormat /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D8CheckDeviceMultiSampleTypeValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D8CHECKDEVICEMULTISAMPLETYPEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Adapter);
    FORMATVALUE(builder, TextFormatValue, value->DeviceType /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->SurfaceFormat /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Windowed);
    FORMATVALUE(builder, TextFormatValue, value->MultiSampleType); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D8CheckDepthStencilMatchValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D8CHECKDEPTHSTENCILMATCHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Adapter);
    FORMATVALUE(builder, TextFormatValue, value->DeviceType /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->AdapterFormat /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->RenderTargetFormat /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->DepthStencilFormat /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D8GetDeviceCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D8GETDEVICECAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Adapter);
    FORMATVALUE(builder, TextFormatValue, value->DeviceType /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D8GetAdapterMonitorValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D8GETADAPTERMONITORMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Adapter); return TRUE;
}

static CONST BOOL AcquireLoggerDirect3D8CreateDeviceValue(LPSTRINGBUILDER builder, CONST LPDIRECT3D8CREATEDEVICEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Adapter);
    FORMATVALUE(builder, TextFormatValue, value->DeviceType /* TODO */);
    FORMATVALUE(builder, TextFormatWindow, value->Window);
    FORMATVALUE(builder, TextFormatValue, value->BehaviorFlags /* TODO*/);
    FORMATVALUE(builder, TextFormatObject, value->PresentationParameters /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->ReturnedDeviceInterface); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirect3D8MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirect3D8MethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirect3D8MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }