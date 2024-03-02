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
#include "DirectDrawLogger.hxx"
#include "DirectDrawTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                   \
    switch (ID)                                     \
    {                                               \
        A(DirectDraw, QueryInterface);              \
        A(DirectDraw, AddRef);                      \
        A(DirectDraw, Release);                     \
        A(DirectDraw, Compact);                     \
        A(DirectDraw, CreateClipper);               \
        A(DirectDraw, CreatePalette);               \
        A(DirectDraw, CreateSurface);               \
        A(DirectDraw, DuplicateSurface);            \
        A(DirectDraw, EnumDisplayModes);            \
        A(DirectDraw, EnumSurfaces);                \
        A(DirectDraw, FlipToGDISurface);            \
        A(DirectDraw, GetCaps);                     \
        A(DirectDraw, GetDisplayMode);              \
        A(DirectDraw, GetFourCCCodes);              \
        A(DirectDraw, GetGDISurface);               \
        A(DirectDraw, GetMonitorFrequency);         \
        A(DirectDraw, GetScanLine);                 \
        A(DirectDraw, GetVerticalBlankStatus);      \
        A(DirectDraw, Initialize);                  \
        A(DirectDraw, RestoreDisplayMode);          \
        A(DirectDraw, SetCooperativeLevel);         \
        A(DirectDraw, SetDisplayMode);              \
        A(DirectDraw, WaitForVerticalBlank);        \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWRELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawCompactValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCOMPACTMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawCreateClipperValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCREATECLIPPERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawCreatePaletteValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCREATEPALETTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Colors /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawCreateSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWCREATESURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawDuplicateSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWDUPLICATESURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Duplicate); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawEnumDisplayModesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWENUMDISPLAYMODESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->EnumModesCallback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawEnumSurfacesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWENUMSURFACESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->EnumSurfacesCallback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawFlipToGDISurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWFLIPTOGDISURFACEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawGetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWGETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->AccelerationDriverCaps /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->EmulationDricerCaps /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawGetDisplayModeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWGETDISPLAYMODEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawGetFourCCCodesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWGETFOURCCCODESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Codes /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawGetGDISurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWGETGDISURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawGetMonitorFrequencyValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWGETMONITORFREQUENCYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Frequency); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawGetScanLineValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWGETSCANLINEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->ScanLine); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawGetVerticalBlankStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWGETVERTICALBLANKSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->IsInVerticalBlank); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawInitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWINITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawRestoreDisplayModeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWRESTOREDISPLAYMODEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSetCooperativeLevelValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSETCOOPERATIVELEVELMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatWindow, value->Window);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSetDisplayModeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSETDISPLAYMODEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Width);
    FORMATVALUE(builder, TextFormatValue, value->Height);
    FORMATVALUE(builder, TextFormatValue, value->Bits); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawWaitForVerticalBlankValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWWAITFORVERTICALBLANKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Event); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectDrawMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                                      \
    switch (ID)                                         \
    {                                                   \
        A(DirectDraw, EnumDisplayModes);                \
        A(DirectDraw, EnumSurfaces);                    \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawMethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawEnumDisplayModesCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWENUMDISPLAYMODESMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawEnumSurfacesCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWENUMSURFACESMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirectDrawMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}