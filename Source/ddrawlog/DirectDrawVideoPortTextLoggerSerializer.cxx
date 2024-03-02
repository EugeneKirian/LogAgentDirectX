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
#include "DirectDrawVideoPortLogger.hxx"
#include "DirectDrawVideoPortTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(DirectDrawVideoPort, QueryInterface);         \
        A(DirectDrawVideoPort, AddRef);                 \
        A(DirectDrawVideoPort, Release);                \
        A(DirectDrawVideoPort, Flip);                   \
        A(DirectDrawVideoPort, GetBandwidthInfo);       \
        A(DirectDrawVideoPort, GetColorControls);       \
        A(DirectDrawVideoPort, GetInputFormats);        \
        A(DirectDrawVideoPort, GetOutputFormats);       \
        A(DirectDrawVideoPort, GetFieldPolarity);       \
        A(DirectDrawVideoPort, GetVideoLine);           \
        A(DirectDrawVideoPort, GetVideoSignalStatus);   \
        A(DirectDrawVideoPort, SetColorControls);       \
        A(DirectDrawVideoPort, SetTargetSurface);       \
        A(DirectDrawVideoPort, StartVideo);             \
        A(DirectDrawVideoPort, StopVideo);              \
        A(DirectDrawVideoPort, UpdateVideo);            \
        A(DirectDrawVideoPort, WaitForSync);            \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawVideoPortMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawVideoPortReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawVideoPortFlipValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTFLIPMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortGetBandwidthInfoValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTGETBANDWIDTHINFOMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Format /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Width);
    FORMATVALUE(builder, TextFormatValue, value->Height);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Bandwidth /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortGetColorControlsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTGETCOLORCONTROLSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ColorControl /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortGetInputFormatsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTGETINPUTFORMATSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Formats);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortGetOutputFormatsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTGETOUTPUTFORMATSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Input);
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Formats);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortGetFieldPolarityValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTGETFIELDPOLARITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->FieldPolarity); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortGetVideoLineValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTGETVIDEOLINEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Line); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortGetVideoSignalStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTGETVIDEOSIGNALSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Status); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortSetColorControlsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTSETCOLORCONTROLSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->ColorControl /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortSetTargetSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTSETTARGETSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortStartVideoValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTSTARTVIDEOMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->VideoInfo /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortStopVideoValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTSTOPVIDEOMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawVideoPortUpdateVideoValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTUPDATEVIDEOMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->VideoInfo /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawVideoPortWaitForSyncValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWVIDEOPORTWAITFORSYNCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Line);
    FORMATVALUE(builder, TextFormatValue, value->Timeout); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectDrawVideoPortMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

LPCSTR AcquireLoggerDirectDrawVideoPortMethodCallbackName(CONST AGENTMETHODCALLBACKID callback) { return "<UNKNOWN>"; }

CONST BOOL AcquireLoggerDirectDrawVideoPortMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value) { return FALSE; }