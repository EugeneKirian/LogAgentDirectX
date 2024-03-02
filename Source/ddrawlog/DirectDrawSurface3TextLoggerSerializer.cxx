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
#include "DirectDrawSurface3Logger.hxx"
#include "DirectDrawSurface3TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(DirectDrawSurface3, QueryInterface);          \
        A(DirectDrawSurface3, AddRef);                  \
        A(DirectDrawSurface3, Release);                 \
        A(DirectDrawSurface3, AddAttachedSurface);      \
        A(DirectDrawSurface3, AddOverlayDirtyRect);     \
        A(DirectDrawSurface3, Blt);                     \
        A(DirectDrawSurface3, BltBatch);                \
        A(DirectDrawSurface3, BltFast);                 \
        A(DirectDrawSurface3, DeleteAttachedSurface);   \
        A(DirectDrawSurface3, EnumAttachedSurfaces);    \
        A(DirectDrawSurface3, EnumOverlayZOrders);      \
        A(DirectDrawSurface3, Flip);                    \
        A(DirectDrawSurface3, GetAttachedSurface);      \
        A(DirectDrawSurface3, GetBltStatus);            \
        A(DirectDrawSurface3, GetCaps);                 \
        A(DirectDrawSurface3, GetClipper);              \
        A(DirectDrawSurface3, GetColorKey);             \
        A(DirectDrawSurface3, GetDC);                   \
        A(DirectDrawSurface3, GetFlipStatus);           \
        A(DirectDrawSurface3, GetOverlayPosition);      \
        A(DirectDrawSurface3, GetPalette);              \
        A(DirectDrawSurface3, GetPixelFormat);          \
        A(DirectDrawSurface3, GetSurfaceDesc);          \
        A(DirectDrawSurface3, Initialize);              \
        A(DirectDrawSurface3, IsLost);                  \
        A(DirectDrawSurface3, Lock);                    \
        A(DirectDrawSurface3, ReleaseDC);               \
        A(DirectDrawSurface3, Restore);                 \
        A(DirectDrawSurface3, SetClipper);              \
        A(DirectDrawSurface3, SetColorKey);             \
        A(DirectDrawSurface3, SetOverlayPosition);      \
        A(DirectDrawSurface3, SetPalette);              \
        A(DirectDrawSurface3, Unlock);                  \
        A(DirectDrawSurface3, UpdateOverlay);           \
        A(DirectDrawSurface3, UpdateOverlayDisplay);    \
        A(DirectDrawSurface3, UpdateOverlayZOrder);     \
        A(DirectDrawSurface3, GetDDInterface);          \
        A(DirectDrawSurface3, PageLock);                \
        A(DirectDrawSurface3, PageUnlock);              \
        A(DirectDrawSurface3, SetSurfaceDesc);          \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawSurface3MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawSurface3QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface3ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface3AddAttachedSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3ADDATTACHEDSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3AddOverlayDirtyRectValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3ADDOVERLAYDIRTYRECTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Rect); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3BltValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3BLTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Destination);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Source);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Effect /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3BltBatchValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3BLTBATCHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Batch /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3BltFastValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3BLTFASTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Rect);
    FORMATVALUE(builder, TextFormatValue, value->Transparent /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3DeleteAttachedSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3DELETEATTACHEDSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3EnumAttachedSurfacesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3ENUMATTACHEDSURFACESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->EnumSurfacesCallback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3EnumOverlayZOrdersValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3ENUMOVERLAYZORDERSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->Callback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3FlipValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3FLIPMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3GetAttachedSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3GETATTACHEDSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3GetBltStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3GETBLTSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3GetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3GETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3GetClipperValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3GETCLIPPERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Clipper); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3GetColorKeyValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3GETCOLORKEYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->ColorKey /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3GetDCValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3GETDCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->DC); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3GetFlipStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3GETFLIPSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODOD */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3GetOverlayPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3GETOVERLAYPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3GetPaletteValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3GETPALETTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Palette); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3GetPixelFormatValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3GETPIXELFORMATMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Format /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3GetSurfaceDescValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3GETSURFACEDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3InitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3INITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3IsLostValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3ISLOSTMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface3LockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3LOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Rect);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Event); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3ReleaseDCValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3RELEASEDCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->DC); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3RestoreValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3RESTOREMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface3SetClipperValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3SETCLIPPERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Clipper); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3SetColorKeyValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3SETCOLORKEYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->ColorKey /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3SetOverlayPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3SETOVERLAYPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3SetPaletteValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3SETPALETTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Palette); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3UnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3UNLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Value /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3UpdateOverlayValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3UPDATEOVERLAYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Source /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Destination /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Effect /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3UpdateOverlayDisplayValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3UPDATEOVERLAYDISPLAYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3UpdateOverlayZOrderValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3UPDATEOVERLAYZORDERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3GetDDInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3GETDDINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3PageLockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3PAGELOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3PageUnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3PAGEUNLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3SetSurfaceDescValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3SETSURFACEDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectDrawSurface3MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                                      \
    switch (ID)                                         \
    {                                                   \
        A(DirectDrawSurface3, EnumAttachedSurfaces);    \
        A(DirectDrawSurface3, EnumOverlayZOrders);      \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawSurface3MethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawSurface3EnumAttachedSurfacesCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3ENUMATTACHEDSURFACESMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface3EnumOverlayZOrdersCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE3ENUMOVERLAYZORDERSMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirectDrawSurface3MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}