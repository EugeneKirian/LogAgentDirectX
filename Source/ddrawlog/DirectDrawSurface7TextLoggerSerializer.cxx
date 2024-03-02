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
#include "DirectDrawSurface7Logger.hxx"
#include "DirectDrawSurface7TextLoggerSerializer.hxx"
#include "TextLoggerSerializer.hxx"

#define MX(ID, A)                                       \
    switch (ID)                                         \
    {                                                   \
        A(DirectDrawSurface7, QueryInterface);          \
        A(DirectDrawSurface7, AddRef);                  \
        A(DirectDrawSurface7, Release);                 \
        A(DirectDrawSurface7, AddAttachedSurface);      \
        A(DirectDrawSurface7, AddOverlayDirtyRect);     \
        A(DirectDrawSurface7, Blt);                     \
        A(DirectDrawSurface7, BltBatch);                \
        A(DirectDrawSurface7, BltFast);                 \
        A(DirectDrawSurface7, DeleteAttachedSurface);   \
        A(DirectDrawSurface7, EnumAttachedSurfaces);    \
        A(DirectDrawSurface7, EnumOverlayZOrders);      \
        A(DirectDrawSurface7, Flip);                    \
        A(DirectDrawSurface7, GetAttachedSurface);      \
        A(DirectDrawSurface7, GetBltStatus);            \
        A(DirectDrawSurface7, GetCaps);                 \
        A(DirectDrawSurface7, GetClipper);              \
        A(DirectDrawSurface7, GetColorKey);             \
        A(DirectDrawSurface7, GetDC);                   \
        A(DirectDrawSurface7, GetFlipStatus);           \
        A(DirectDrawSurface7, GetOverlayPosition);      \
        A(DirectDrawSurface7, GetPalette);              \
        A(DirectDrawSurface7, GetPixelFormat);          \
        A(DirectDrawSurface7, GetSurfaceDesc);          \
        A(DirectDrawSurface7, Initialize);              \
        A(DirectDrawSurface7, IsLost);                  \
        A(DirectDrawSurface7, Lock);                    \
        A(DirectDrawSurface7, ReleaseDC);               \
        A(DirectDrawSurface7, Restore);                 \
        A(DirectDrawSurface7, SetClipper);              \
        A(DirectDrawSurface7, SetColorKey);             \
        A(DirectDrawSurface7, SetOverlayPosition);      \
        A(DirectDrawSurface7, SetPalette);              \
        A(DirectDrawSurface7, Unlock);                  \
        A(DirectDrawSurface7, UpdateOverlay);           \
        A(DirectDrawSurface7, UpdateOverlayDisplay);    \
        A(DirectDrawSurface7, UpdateOverlayZOrder);     \
        A(DirectDrawSurface7, GetDDInterface);          \
        A(DirectDrawSurface7, PageLock);                \
        A(DirectDrawSurface7, PageUnlock);              \
        A(DirectDrawSurface7, SetSurfaceDesc);          \
        A(DirectDrawSurface7, SetPrivateData);          \
        A(DirectDrawSurface7, GetPrivateData);          \
        A(DirectDrawSurface7, FreePrivateData);         \
        A(DirectDrawSurface7, GetUniquenessValue);      \
        A(DirectDrawSurface7, ChangeUniquenessValue);   \
        A(DirectDrawSurface7, SetPriority);             \
        A(DirectDrawSurface7, GetPriority);             \
        A(DirectDrawSurface7, SetLOD);                  \
        A(DirectDrawSurface7, GetLOD);                  \
    }

#define ACQUIREMETHODNAME(ID, M) case METHOD_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawSurface7MethodName(CONST AGENTMETHODID method)
{
    MX(method, ACQUIREMETHODNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawSurface7QueryInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7QUERYINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7AddRefValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7ADDREFMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface7ReleaseValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7RELEASEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface7AddAttachedSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7ADDATTACHEDSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7AddOverlayDirtyRectValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7ADDOVERLAYDIRTYRECTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Rect); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7BltValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7BLTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Destination);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Source);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Effect /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7BltBatchValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7BLTBATCHMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Batch /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Count);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7BltFastValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7BLTFASTMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Rect);
    FORMATVALUE(builder, TextFormatValue, value->Transparent /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7DeleteAttachedSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7DELETEATTACHEDSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7EnumAttachedSurfacesValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7ENUMATTACHEDSURFACESMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->EnumSurfacesCallback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7EnumOverlayZOrdersValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7ENUMOVERLAYZORDERSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Context);
    FORMATVALUE(builder, TextFormatObject, value->Callback); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7FlipValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7FLIPMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7GetAttachedSurfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7GETATTACHEDSURFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7GetBltStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7GETBLTSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7GetCapsValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7GETCAPSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Caps /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7GetClipperValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7GETCLIPPERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Clipper); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7GetColorKeyValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7GETCOLORKEYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->ColorKey /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7GetDCValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7GETDCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->DC); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7GetFlipStatusValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7GETFLIPSTATUSMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODOD */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7GetOverlayPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7GETOVERLAYPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7GetPaletteValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7GETPALETTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Palette); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7GetPixelFormatValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7GETPIXELFORMATMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Format /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7GetSurfaceDescValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7GETSURFACEDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7InitializeValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7INITIALIZEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7IsLostValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7ISLOSTMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface7LockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7LOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Rect);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Event); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7ReleaseDCValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7RELEASEDCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->DC); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7RestoreValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7RESTOREMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface7SetClipperValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7SETCLIPPERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Clipper); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7SetColorKeyValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7SETCOLORKEYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->ColorKey /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7SetOverlayPositionValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7SETOVERLAYPOSITIONMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->X);
    FORMATVALUE(builder, TextFormatValue, value->Y); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7SetPaletteValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7SETPALETTEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Palette); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7UnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7UNLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Value /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7UpdateOverlayValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7UPDATEOVERLAYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Source /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Destination /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Effect /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7UpdateOverlayDisplayValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7UPDATEOVERLAYDISPLAYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7UpdateOverlayZOrderValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7UPDATEOVERLAYZORDERMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */);
    FORMATVALUE(builder, TextFormatObject, value->Surface); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7GetDDInterfaceValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7GETDDINTERFACEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7PageLockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7PAGELOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7PageUnlockValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7PAGEUNLOCKMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7SetSurfaceDescValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7SETSURFACEDESCMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7SetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7SETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Value /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size);
    FORMATVALUE(builder, TextFormatValue, value->Options /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7GetPrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7GETPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID);
    FORMATVALUE(builder, TextFormatObject, value->Value /* TODO */);
    FORMATVALUE(builder, TextFormatValue, value->Size); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7FreePrivateDataValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7FREEPRIVATEDATAMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatID, value->ID); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7GetUniquenessValueValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7GETUNIQUENESSVALUEMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Value); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7ChangeUniquenessValueValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7CHANGEUNIQUENESSVALUEMETHODVALUE value) { return TRUE; }

static CONST BOOL AcquireLoggerDirectDrawSurface7SetPriorityValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7SETPRIORITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Priority); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7GetPriorityValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7GETPRIORITYMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Priority); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7SetLODValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7SETLODMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Value); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7GetLODValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7GETLODMETHODVALUE value)
{
    FORMATVALUE(builder, TextFormatValue, value->Value); return TRUE;
}

#define ACQUIREMETHODVALUE(ID, M) case METHOD_ID_##ID##_##M: { return AcquireLogger##ID##M##Value(builder, (ID##M##MethodValue*)value); }

CONST BOOL AcquireLoggerDirectDrawSurface7MethodValue(LPSTRINGBUILDER builder, CONST AGENTMETHODID method, CONST LPVOID value)
{
    MX(method, ACQUIREMETHODVALUE); return FALSE;
}

#define MCX(ID, A)                                      \
    switch (ID)                                         \
    {                                                   \
        A(DirectDrawSurface7, EnumAttachedSurfaces);    \
        A(DirectDrawSurface7, EnumOverlayZOrders);      \
    }

#define ACQUIREMETHODCALLBACKNAME(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return #M; }

LPCSTR AcquireLoggerDirectDrawSurface7MethodCallbackName(CONST AGENTMETHODCALLBACKID callback)
{
    MCX(callback, ACQUIREMETHODCALLBACKNAME); return "<UNKNOWN>";
}

static CONST BOOL AcquireLoggerDirectDrawSurface7EnumAttachedSurfacesCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7ENUMATTACHEDSURFACESMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

static CONST BOOL AcquireLoggerDirectDrawSurface7EnumOverlayZOrdersCallbackValue(LPSTRINGBUILDER builder, CONST LPDIRECTDRAWSURFACE7ENUMOVERLAYZORDERSMETHODCALLBACKVALUE value)
{
    FORMATVALUE(builder, TextFormatObject, value->Object);
    FORMATVALUE(builder, TextFormatObject, value->Surface);
    FORMATVALUE(builder, TextFormatObject, value->Descriptor /* TODO */); return TRUE;
}

#define ACQUIREMETHODCALLBACKVALUE(ID, M) case METHODCALLBACK_ID_##ID##_##M: { return AcquireLogger##ID##M##CallbackValue(builder, (ID##M##MethodCallbackValue*)value); }

CONST BOOL AcquireLoggerDirectDrawSurface7MethodCallbackValue(LPSTRINGBUILDER builder, CONST AGENTMETHODCALLBACKID callback, CONST LPVOID value)
{
    MCX(callback, ACQUIREMETHODCALLBACKVALUE); return FALSE;
}