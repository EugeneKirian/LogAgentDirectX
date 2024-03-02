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
#include "DirectDrawSurfaceLogger.hxx"
#include "DirectDrawSurfaceTextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(DirectDrawSurface, QueryInterface);           \
        A(DirectDrawSurface, AddRef);                   \
        A(DirectDrawSurface, Release);                  \
        A(DirectDrawSurface, AddAttachedSurface);       \
        A(DirectDrawSurface, AddOverlayDirtyRect);      \
        A(DirectDrawSurface, Blt);                      \
        A(DirectDrawSurface, BltBatch);                 \
        A(DirectDrawSurface, BltFast);                  \
        A(DirectDrawSurface, DeleteAttachedSurface);    \
        A(DirectDrawSurface, EnumAttachedSurfaces);     \
        A(DirectDrawSurface, EnumOverlayZOrders);       \
        A(DirectDrawSurface, Flip);                     \
        A(DirectDrawSurface, GetAttachedSurface);       \
        A(DirectDrawSurface, GetBltStatus);             \
        A(DirectDrawSurface, GetCaps);                  \
        A(DirectDrawSurface, GetClipper);               \
        A(DirectDrawSurface, GetColorKey);              \
        A(DirectDrawSurface, GetDC);                    \
        A(DirectDrawSurface, GetFlipStatus);            \
        A(DirectDrawSurface, GetOverlayPosition);       \
        A(DirectDrawSurface, GetPalette);               \
        A(DirectDrawSurface, GetPixelFormat);           \
        A(DirectDrawSurface, GetSurfaceDesc);           \
        A(DirectDrawSurface, Initialize);               \
        A(DirectDrawSurface, IsLost);                   \
        A(DirectDrawSurface, Lock);                     \
        A(DirectDrawSurface, ReleaseDC);                \
        A(DirectDrawSurface, Restore);                  \
        A(DirectDrawSurface, SetClipper);               \
        A(DirectDrawSurface, SetColorKey);              \
        A(DirectDrawSurface, SetOverlayPosition);       \
        A(DirectDrawSurface, SetPalette);               \
        A(DirectDrawSurface, Unlock);                   \
        A(DirectDrawSurface, UpdateOverlay);            \
        A(DirectDrawSurface, UpdateOverlayDisplay);     \
        A(DirectDrawSurface, UpdateOverlayZOrder);      \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawSurfaceMethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceQueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEQUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceAddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurfaceReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACERELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurfaceAddAttachedSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEADDATTACHEDSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceAddOverlayDirtyRectValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEADDOVERLAYDIRTYRECTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Rect); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceBltValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEBLTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Destination);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Source);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Effect /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceBltBatchValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEBLTBATCHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Batch /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceBltFastValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEBLTFASTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Rect);
    FORMATVALUE(builder, TextFormatValue, value->Transparent /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceDeleteAttachedSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEDELETEATTACHEDSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceEnumAttachedSurfacesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEENUMATTACHEDSURFACESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->EnumSurfacesCallback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceEnumOverlayZOrdersValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEENUMOVERLAYZORDERSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->Callback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceFlipValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEFLIPMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceGetAttachedSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEGETATTACHEDSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceGetBltStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEGETBLTSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceGetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEGETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceGetClipperValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEGETCLIPPERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Clipper); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceGetColorKeyValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEGETCOLORKEYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->ColorKey /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceGetDCValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEGETDCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->DC); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceGetFlipStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEGETFLIPSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODOD */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceGetOverlayPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEGETOVERLAYPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceGetPaletteValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEGETPALETTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Palette); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceGetPixelFormatValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEGETPIXELFORMATMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Format /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceGetSurfaceDescValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEGETSURFACEDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceInitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEINITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceIsLostValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEISLOSTMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurfaceLockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACELOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Rect);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Event); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceReleaseDCValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACERELEASEDCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->DC); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceRestoreValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACERESTOREMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurfaceSetClipperValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACESETCLIPPERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Clipper); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceSetColorKeyValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACESETCOLORKEYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->ColorKey /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceSetOverlayPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACESETOVERLAYPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceSetPaletteValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACESETPALETTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Palette); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceUnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEUNLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Value /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceUpdateOverlayValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEUPDATEOVERLAYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Source /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Destination /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Effect /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceUpdateOverlayDisplayValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEUPDATEOVERLAYDISPLAYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceUpdateOverlayZOrderValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEUPDATEOVERLAYZORDERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectDrawSurfaceMethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                                      \
    switch (ID)                                         \
    {                                                   \
        A(DirectDrawSurface, EnumAttachedSurfaces);     \
        A(DirectDrawSurface, EnumOverlayZOrders);       \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawSurfaceMethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceEnumAttachedSurfacesCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEENUMATTACHEDSURFACESMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurfaceEnumOverlayZOrdersCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACEENUMOVERLAYZORDERSMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirectDrawSurfaceMethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}