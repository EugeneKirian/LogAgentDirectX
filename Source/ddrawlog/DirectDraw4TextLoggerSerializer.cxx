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
#include "DirectDraw4Logger.hxx"
#include "DirectDraw4TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(DirectDraw4, QueryInterface);                 \
        A(DirectDraw4, AddRef);                         \
        A(DirectDraw4, Release);                        \
        A(DirectDraw4, Compact);                        \
        A(DirectDraw4, CreateClipper);                  \
        A(DirectDraw4, CreatePalette);                  \
        A(DirectDraw4, CreateSurface);                  \
        A(DirectDraw4, DuplicateSurface);               \
        A(DirectDraw4, EnumDisplayModes);               \
        A(DirectDraw4, EnumSurfaces);                   \
        A(DirectDraw4, FlipToGDISurface);               \
        A(DirectDraw4, GetCaps);                        \
        A(DirectDraw4, GetDisplayMode);                 \
        A(DirectDraw4, GetFourCCCodes);                 \
        A(DirectDraw4, GetGDISurface);                  \
        A(DirectDraw4, GetMonitorFrequency);            \
        A(DirectDraw4, GetScanLine);                    \
        A(DirectDraw4, GetVerticalBlankStatus);         \
        A(DirectDraw4, Initialize);                     \
        A(DirectDraw4, RestoreDisplayMode);             \
        A(DirectDraw4, SetCooperativeLevel);            \
        A(DirectDraw4, SetDisplayMode);                 \
        A(DirectDraw4, WaitForVerticalBlank);           \
        A(DirectDraw4, GetAvailableVidMem);             \
        A(DirectDraw4, GetSurfaceFromDC);               \
        A(DirectDraw4, RestoreAllSurfaces);             \
        A(DirectDraw4, TestCooperativeLevel);           \
        A(DirectDraw4, GetDeviceIdentifier);            \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDraw4MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDraw4QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw4ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw4CompactValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4COMPACTMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw4CreateClipperValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4CREATECLIPPERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4CreatePaletteValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4CREATEPALETTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Colors /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4CreateSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4CREATESURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4DuplicateSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4DUPLICATESURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Duplicate); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4EnumDisplayModesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4ENUMDISPLAYMODESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->EnumModesCallback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4EnumSurfacesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4ENUMSURFACESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->EnumSurfacesCallback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4FlipToGDISurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4FLIPTOGDISURFACEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw4GetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4GETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->AccelerationDriverCaps /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->EmulationDricerCaps /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4GetDisplayModeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4GETDISPLAYMODEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4GetFourCCCodesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4GETFOURCCCODESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Codes /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4GetGDISurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4GETGDISURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4GetMonitorFrequencyValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4GETMONITORFREQUENCYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Frequency); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4GetScanLineValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4GETSCANLINEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->ScanLine); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4GetVerticalBlankStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4GETVERTICALBLANKSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->IsInVerticalBlank); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4InitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4INITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4RestoreDisplayModeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4RESTOREDISPLAYMODEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw4SetCooperativeLevelValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4SETCOOPERATIVELEVELMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatWindow, value->Window);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4SetDisplayModeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4SETDISPLAYMODEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Width);
    FORMATVALUE(builder, TextFormatValue, value->Height);
    FORMATVALUE(builder, TextFormatValue, value->Bits);
    FORMATVALUE(builder, TextFormatValue, value->RefreshRate);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4WaitForVerticalBlankValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4WAITFORVERTICALBLANKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Event); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4GetAvailableVidMemValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4GETAVAILABLEVIDMEMMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Total);
    FORMATVALUE(builder, TextFormatValue, value->Free); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4GetSurfaceFromDCValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4GETSURFACEFROMDCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->DC);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4RestoreAllSurfacesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4RESTOREALLSURFACESMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw4TestCooperativeLevelValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4TESTCOOPERATIVELEVELMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw4GetDeviceIdentifierValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4GETDEVICEIDENTIFIERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Identifier /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectDraw4MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                                      \
    switch (ID)                                         \
    {                                                   \
        A(DirectDraw4, EnumDisplayModes);               \
        A(DirectDraw4, EnumSurfaces);                   \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDraw4MethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDraw4EnumDisplayModesCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4ENUMDISPLAYMODESMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw4EnumSurfacesCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW4ENUMSURFACESMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirectDraw4MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}