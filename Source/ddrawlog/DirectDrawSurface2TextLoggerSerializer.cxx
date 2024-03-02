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
#include "DirectDrawSurface2Logger.hxx"
#include "DirectDrawSurface2TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(DirectDrawSurface2, QueryInterface);          \
        A(DirectDrawSurface2, AddRef);                  \
        A(DirectDrawSurface2, Release);                 \
        A(DirectDrawSurface2, AddAttachedSurface);      \
        A(DirectDrawSurface2, AddOverlayDirtyRect);     \
        A(DirectDrawSurface2, Blt);                     \
        A(DirectDrawSurface2, BltBatch);                \
        A(DirectDrawSurface2, BltFast);                 \
        A(DirectDrawSurface2, DeleteAttachedSurface);   \
        A(DirectDrawSurface2, EnumAttachedSurfaces);    \
        A(DirectDrawSurface2, EnumOverlayZOrders);      \
        A(DirectDrawSurface2, Flip);                    \
        A(DirectDrawSurface2, GetAttachedSurface);      \
        A(DirectDrawSurface2, GetBltStatus);            \
        A(DirectDrawSurface2, GetCaps);                 \
        A(DirectDrawSurface2, GetClipper);              \
        A(DirectDrawSurface2, GetColorKey);             \
        A(DirectDrawSurface2, GetDC);                   \
        A(DirectDrawSurface2, GetFlipStatus);           \
        A(DirectDrawSurface2, GetOverlayPosition);      \
        A(DirectDrawSurface2, GetPalette);              \
        A(DirectDrawSurface2, GetPixelFormat);          \
        A(DirectDrawSurface2, GetSurfaceDesc);          \
        A(DirectDrawSurface2, Initialize);              \
        A(DirectDrawSurface2, IsLost);                  \
        A(DirectDrawSurface2, Lock);                    \
        A(DirectDrawSurface2, ReleaseDC);               \
        A(DirectDrawSurface2, Restore);                 \
        A(DirectDrawSurface2, SetClipper);              \
        A(DirectDrawSurface2, SetColorKey);             \
        A(DirectDrawSurface2, SetOverlayPosition);      \
        A(DirectDrawSurface2, SetPalette);              \
        A(DirectDrawSurface2, Unlock);                  \
        A(DirectDrawSurface2, UpdateOverlay);           \
        A(DirectDrawSurface2, UpdateOverlayDisplay);    \
        A(DirectDrawSurface2, UpdateOverlayZOrder);     \
        A(DirectDrawSurface2, GetDDInterface);          \
        A(DirectDrawSurface2, PageLock);                \
        A(DirectDrawSurface2, PageUnlock);              \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawSurface2MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawSurface2QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface2ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface2AddAttachedSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2ADDATTACHEDSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2AddOverlayDirtyRectValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2ADDOVERLAYDIRTYRECTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Rect); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2BltValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2BLTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Destination);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Source);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Effect /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2BltBatchValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2BLTBATCHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Batch /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2BltFastValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2BLTFASTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Rect);
    FORMATVALUE(builder, TextFormatValue, value->Transparent /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2DeleteAttachedSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2DELETEATTACHEDSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2EnumAttachedSurfacesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2ENUMATTACHEDSURFACESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->EnumSurfacesCallback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2EnumOverlayZOrdersValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2ENUMOVERLAYZORDERSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->Callback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2FlipValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2FLIPMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2GetAttachedSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2GETATTACHEDSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2GetBltStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2GETBLTSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2GetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2GETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2GetClipperValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2GETCLIPPERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Clipper); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2GetColorKeyValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2GETCOLORKEYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->ColorKey /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2GetDCValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2GETDCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->DC); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2GetFlipStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2GETFLIPSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODOD */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2GetOverlayPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2GETOVERLAYPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2GetPaletteValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2GETPALETTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Palette); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2GetPixelFormatValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2GETPIXELFORMATMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Format /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2GetSurfaceDescValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2GETSURFACEDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2InitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2INITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2IsLostValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2ISLOSTMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface2LockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2LOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Rect);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Event); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2ReleaseDCValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2RELEASEDCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->DC); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2RestoreValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2RESTOREMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface2SetClipperValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2SETCLIPPERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Clipper); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2SetColorKeyValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2SETCOLORKEYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->ColorKey /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2SetOverlayPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2SETOVERLAYPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2SetPaletteValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2SETPALETTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Palette); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2UnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2UNLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Value /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2UpdateOverlayValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2UPDATEOVERLAYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Source /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Destination /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Effect /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2UpdateOverlayDisplayValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2UPDATEOVERLAYDISPLAYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2UpdateOverlayZOrderValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2UPDATEOVERLAYZORDERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2GetDDInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2GETDDINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2PageLockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2PAGELOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2PageUnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2PAGEUNLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectDrawSurface2MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                                      \
    switch (ID)                                         \
    {                                                   \
        A(DirectDrawSurface2, EnumAttachedSurfaces);    \
        A(DirectDrawSurface2, EnumOverlayZOrders);      \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawSurface2MethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawSurface2EnumAttachedSurfacesCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2ENUMATTACHEDSURFACESMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface2EnumOverlayZOrdersCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE2ENUMOVERLAYZORDERSMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirectDrawSurface2MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}