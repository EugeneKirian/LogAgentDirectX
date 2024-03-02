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
#include "DirectDraw2Logger.hxx"
#include "DirectDraw2TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(DirectDraw2, QueryInterface);                 \
        A(DirectDraw2, AddRef);                         \
        A(DirectDraw2, Release);                        \
        A(DirectDraw2, Compact);                        \
        A(DirectDraw2, CreateClipper);                  \
        A(DirectDraw2, CreatePalette);                  \
        A(DirectDraw2, CreateSurface);                  \
        A(DirectDraw2, DuplicateSurface);               \
        A(DirectDraw2, EnumDisplayModes);               \
        A(DirectDraw2, EnumSurfaces);                   \
        A(DirectDraw2, FlipToGDISurface);               \
        A(DirectDraw2, GetCaps);                        \
        A(DirectDraw2, GetDisplayMode);                 \
        A(DirectDraw2, GetFourCCCodes);                 \
        A(DirectDraw2, GetGDISurface);                  \
        A(DirectDraw2, GetMonitorFrequency);            \
        A(DirectDraw2, GetScanLine);                    \
        A(DirectDraw2, GetVerticalBlankStatus);         \
        A(DirectDraw2, Initialize);                     \
        A(DirectDraw2, RestoreDisplayMode);             \
        A(DirectDraw2, SetCooperativeLevel);            \
        A(DirectDraw2, SetDisplayMode);                 \
        A(DirectDraw2, WaitForVerticalBlank);           \
        A(DirectDraw2, GetAvailableVidMem);             \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDraw2MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDraw2QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw2ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw2CompactValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2COMPACTMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw2CreateClipperValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2CREATECLIPPERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2CreatePaletteValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2CREATEPALETTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Colors /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2CreateSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2CREATESURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2DuplicateSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2DUPLICATESURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Duplicate); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2EnumDisplayModesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2ENUMDISPLAYMODESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->EnumModesCallback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2EnumSurfacesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2ENUMSURFACESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->EnumSurfacesCallback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2FlipToGDISurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2FLIPTOGDISURFACEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw2GetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2GETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->AccelerationDriverCaps /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->EmulationDricerCaps /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2GetDisplayModeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2GETDISPLAYMODEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2GetFourCCCodesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2GETFOURCCCODESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Codes /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2GetGDISurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2GETGDISURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2GetMonitorFrequencyValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2GETMONITORFREQUENCYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Frequency); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2GetScanLineValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2GETSCANLINEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->ScanLine); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2GetVerticalBlankStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2GETVERTICALBLANKSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->IsInVerticalBlank); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2InitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2INITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2RestoreDisplayModeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2RESTOREDISPLAYMODEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw2SetCooperativeLevelValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2SETCOOPERATIVELEVELMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatWindow, value->Window);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2SetDisplayModeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2SETDISPLAYMODEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Width);
    FORMATVALUE(builder, TextFormatValue, value->Height);
    FORMATVALUE(builder, TextFormatValue, value->Bits);
    FORMATVALUE(builder, TextFormatValue, value->RefreshRate);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2WaitForVerticalBlankValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2WAITFORVERTICALBLANKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Event); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2GetAvailableVidMemValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2GETAVAILABLEVIDMEMMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Total);
    FORMATVALUE(builder, TextFormatValue, value->Free); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectDraw2MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                                      \
    switch (ID)                                         \
    {                                                   \
        A(DirectDraw2, EnumDisplayModes);               \
        A(DirectDraw2, EnumSurfaces);                   \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDraw2MethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDraw2EnumDisplayModesCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2ENUMDISPLAYMODESMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw2EnumSurfacesCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW2ENUMSURFACESMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirectDraw2MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}