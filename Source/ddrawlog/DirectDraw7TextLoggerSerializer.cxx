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
#include "DirectDraw7Logger.hxx"
#include "DirectDraw7TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(DirectDraw7, QueryInterface);                 \
        A(DirectDraw7, AddRef);                         \
        A(DirectDraw7, Release);                        \
        A(DirectDraw7, Compact);                        \
        A(DirectDraw7, CreateClipper);                  \
        A(DirectDraw7, CreatePalette);                  \
        A(DirectDraw7, CreateSurface);                  \
        A(DirectDraw7, DuplicateSurface);               \
        A(DirectDraw7, EnumDisplayModes);               \
        A(DirectDraw7, EnumSurfaces);                   \
        A(DirectDraw7, FlipToGDISurface);               \
        A(DirectDraw7, GetCaps);                        \
        A(DirectDraw7, GetDisplayMode);                 \
        A(DirectDraw7, GetFourCCCodes);                 \
        A(DirectDraw7, GetGDISurface);                  \
        A(DirectDraw7, GetMonitorFrequency);            \
        A(DirectDraw7, GetScanLine);                    \
        A(DirectDraw7, GetVerticalBlankStatus);         \
        A(DirectDraw7, Initialize);                     \
        A(DirectDraw7, RestoreDisplayMode);             \
        A(DirectDraw7, SetCooperativeLevel);            \
        A(DirectDraw7, SetDisplayMode);                 \
        A(DirectDraw7, WaitForVerticalBlank);           \
        A(DirectDraw7, GetAvailableVidMem);             \
        A(DirectDraw7, GetSurfaceFromDC);               \
        A(DirectDraw7, RestoreAllSurfaces);             \
        A(DirectDraw7, TestCooperativeLevel);           \
        A(DirectDraw7, GetDeviceIdentifier);            \
        A(DirectDraw7, StartModeTest);                  \
        A(DirectDraw7, EvaluateMode);                   \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDraw7MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDraw7QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw7ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw7CompactValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7COMPACTMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw7CreateClipperValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7CREATECLIPPERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7CreatePaletteValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7CREATEPALETTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Colors /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7CreateSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7CREATESURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Unknown); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7DuplicateSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7DUPLICATESURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Duplicate); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7EnumDisplayModesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7ENUMDISPLAYMODESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->EnumModesCallback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7EnumSurfacesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7ENUMSURFACESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->EnumSurfacesCallback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7FlipToGDISurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7FLIPTOGDISURFACEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw7GetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7GETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->AccelerationDriverCaps /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->EmulationDricerCaps /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7GetDisplayModeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7GETDISPLAYMODEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7GetFourCCCodesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7GETFOURCCCODESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatObject, value->Codes /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7GetGDISurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7GETGDISURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7GetMonitorFrequencyValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7GETMONITORFREQUENCYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Frequency); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7GetScanLineValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7GETSCANLINEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->ScanLine); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7GetVerticalBlankStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7GETVERTICALBLANKSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->IsInVerticalBlank); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7InitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7INITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7RestoreDisplayModeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7RESTOREDISPLAYMODEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw7SetCooperativeLevelValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7SETCOOPERATIVELEVELMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatWindow, value->Window);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7SetDisplayModeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7SETDISPLAYMODEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Width);
    FORMATVALUE(builder, TextFormatValue, value->Height);
    FORMATVALUE(builder, TextFormatValue, value->Bits);
    FORMATVALUE(builder, TextFormatValue, value->RefreshRate);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7WaitForVerticalBlankValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7WAITFORVERTICALBLANKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Event); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7GetAvailableVidMemValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7GETAVAILABLEVIDMEMMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Total);
    FORMATVALUE(builder, TextFormatValue, value->Free); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7GetSurfaceFromDCValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7GETSURFACEFROMDCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->DC);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7RestoreAllSurfacesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7RESTOREALLSURFACESMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw7TestCooperativeLevelValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7TESTCOOPERATIVELEVELMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDraw7GetDeviceIdentifierValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7GETDEVICEIDENTIFIERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Identifier /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7StartModeTestValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7STARTMODETESTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Modes /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7EvaluateModeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7EVALUATEMODEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->SecondsUntilTimeout); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectDraw7MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                                      \
    switch (ID)                                         \
    {                                                   \
        A(DirectDraw7, EnumDisplayModes);               \
        A(DirectDraw7, EnumSurfaces);                   \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDraw7MethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDraw7EnumDisplayModesCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7ENUMDISPLAYMODESMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDraw7EnumSurfacesCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAW7ENUMSURFACESMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirectDraw7MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}