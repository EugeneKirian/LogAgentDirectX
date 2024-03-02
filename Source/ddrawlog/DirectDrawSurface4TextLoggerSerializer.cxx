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
#include "DirectDrawSurface4Logger.hxx"
#include "DirectDrawSurface4TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(DirectDrawSurface4, QueryInterface);          \
        A(DirectDrawSurface4, AddRef);                  \
        A(DirectDrawSurface4, Release);                 \
        A(DirectDrawSurface4, AddAttachedSurface);      \
        A(DirectDrawSurface4, AddOverlayDirtyRect);     \
        A(DirectDrawSurface4, Blt);                     \
        A(DirectDrawSurface4, BltBatch);                \
        A(DirectDrawSurface4, BltFast);                 \
        A(DirectDrawSurface4, DeleteAttachedSurface);   \
        A(DirectDrawSurface4, EnumAttachedSurfaces);    \
        A(DirectDrawSurface4, EnumOverlayZOrders);      \
        A(DirectDrawSurface4, Flip);                    \
        A(DirectDrawSurface4, GetAttachedSurface);      \
        A(DirectDrawSurface4, GetBltStatus);            \
        A(DirectDrawSurface4, GetCaps);                 \
        A(DirectDrawSurface4, GetClipper);              \
        A(DirectDrawSurface4, GetColorKey);             \
        A(DirectDrawSurface4, GetDC);                   \
        A(DirectDrawSurface4, GetFlipStatus);           \
        A(DirectDrawSurface4, GetOverlayPosition);      \
        A(DirectDrawSurface4, GetPalette);              \
        A(DirectDrawSurface4, GetPixelFormat);          \
        A(DirectDrawSurface4, GetSurfaceDesc);          \
        A(DirectDrawSurface4, Initialize);              \
        A(DirectDrawSurface4, IsLost);                  \
        A(DirectDrawSurface4, Lock);                    \
        A(DirectDrawSurface4, ReleaseDC);               \
        A(DirectDrawSurface4, Restore);                 \
        A(DirectDrawSurface4, SetClipper);              \
        A(DirectDrawSurface4, SetColorKey);             \
        A(DirectDrawSurface4, SetOverlayPosition);      \
        A(DirectDrawSurface4, SetPalette);              \
        A(DirectDrawSurface4, Unlock);                  \
        A(DirectDrawSurface4, UpdateOverlay);           \
        A(DirectDrawSurface4, UpdateOverlayDisplay);    \
        A(DirectDrawSurface4, UpdateOverlayZOrder);     \
        A(DirectDrawSurface4, GetDDInterface);          \
        A(DirectDrawSurface4, PageLock);                \
        A(DirectDrawSurface4, PageUnlock);              \
        A(DirectDrawSurface4, SetSurfaceDesc);          \
        A(DirectDrawSurface4, SetPrivateData);          \
        A(DirectDrawSurface4, GetPrivateData);          \
        A(DirectDrawSurface4, FreePrivateData);         \
        A(DirectDrawSurface4, GetUniquenessValue);      \
        A(DirectDrawSurface4, ChangeUniquenessValue);   \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawSurface4MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawSurface4QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface4ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface4AddAttachedSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4ADDATTACHEDSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4AddOverlayDirtyRectValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4ADDOVERLAYDIRTYRECTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Rect); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4BltValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4BLTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Destination);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Source);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Effect /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4BltBatchValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4BLTBATCHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Batch /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4BltFastValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4BLTFASTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Rect);
    FORMATVALUE(builder, TextFormatValue, value->Transparent /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4DeleteAttachedSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4DELETEATTACHEDSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4EnumAttachedSurfacesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4ENUMATTACHEDSURFACESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->EnumSurfacesCallback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4EnumOverlayZOrdersValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4ENUMOVERLAYZORDERSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->Callback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4FlipValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4FLIPMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4GetAttachedSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4GETATTACHEDSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4GetBltStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4GETBLTSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4GetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4GETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4GetClipperValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4GETCLIPPERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Clipper); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4GetColorKeyValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4GETCOLORKEYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->ColorKey /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4GetDCValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4GETDCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->DC); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4GetFlipStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4GETFLIPSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODOD */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4GetOverlayPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4GETOVERLAYPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4GetPaletteValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4GETPALETTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Palette); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4GetPixelFormatValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4GETPIXELFORMATMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Format /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4GetSurfaceDescValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4GETSURFACEDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4InitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4INITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4IsLostValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4ISLOSTMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface4LockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4LOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Rect);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Event); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4ReleaseDCValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4RELEASEDCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->DC); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4RestoreValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4RESTOREMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface4SetClipperValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4SETCLIPPERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Clipper); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4SetColorKeyValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4SETCOLORKEYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->ColorKey /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4SetOverlayPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4SETOVERLAYPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4SetPaletteValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4SETPALETTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Palette); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4UnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4UNLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Value /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4UpdateOverlayValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4UPDATEOVERLAYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Source /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Destination /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Effect /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4UpdateOverlayDisplayValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4UPDATEOVERLAYDISPLAYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4UpdateOverlayZOrderValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4UPDATEOVERLAYZORDERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4GetDDInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4GETDDINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4PageLockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4PAGELOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4PageUnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4PAGEUNLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4SetSurfaceDescValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4SETSURFACEDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4SetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4SETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Value /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4GetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4GETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Value /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4FreePrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4FREEPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4GetUniquenessValueValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4GETUNIQUENESSVALUEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Value); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4ChangeUniquenessValueValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4CHANGEUNIQUENESSVALUEMETHODVALUE value) { return TRUE; }

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectDrawSurface4MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                                      \
    switch (ID)                                         \
    {                                                   \
        A(DirectDrawSurface4, EnumAttachedSurfaces);    \
        A(DirectDrawSurface4, EnumOverlayZOrders);      \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawSurface4MethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawSurface4EnumAttachedSurfacesCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4ENUMATTACHEDSURFACESMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface4EnumOverlayZOrdersCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE4ENUMOVERLAYZORDERSMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirectDrawSurface4MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}