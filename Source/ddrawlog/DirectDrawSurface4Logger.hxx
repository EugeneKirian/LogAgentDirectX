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

#pragma once

#include "Base.hxx"

typedef struct DirectDrawSurface4QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECTDRAWSURFACE4QUERYINTERFACEMETHODVALUE, * LPDIRECTDRAWSURFACE4QUERYINTERFACEMETHODVALUE;

typedef struct DirectDrawSurface4AddRefMethodValue
{

} DIRECTDRAWSURFACE4ADDREFMETHODVALUE, * LPDIRECTDRAWSURFACE4ADDREFMETHODVALUE;

typedef struct DirectDrawSurface4ReleaseMethodValue
{

} DIRECTDRAWSURFACE4RELEASEMETHODVALUE, * LPDIRECTDRAWSURFACE4RELEASEMETHODVALUE;

typedef struct DirectDrawSurface4AddAttachedSurfaceMethodValue
{
    LPDIRECTDRAWSURFACE4 Surface;
} DIRECTDRAWSURFACE4ADDATTACHEDSURFACEMETHODVALUE, * LPDIRECTDRAWSURFACE4ADDATTACHEDSURFACEMETHODVALUE;

typedef struct DirectDrawSurface4AddOverlayDirtyRectMethodValue
{
    LPRECT Rect;
} DIRECTDRAWSURFACE4ADDOVERLAYDIRTYRECTMETHODVALUE, * LPDIRECTDRAWSURFACE4ADDOVERLAYDIRTYRECTMETHODVALUE;

typedef struct DirectDrawSurface4BltMethodValue
{
    LPRECT Destination;
    LPDIRECTDRAWSURFACE4 Surface;
    LPRECT Source;
    DWORD Options;
    LPDDBLTFX Effect;
} DIRECTDRAWSURFACE4BLTMETHODVALUE, * LPDIRECTDRAWSURFACE4BLTMETHODVALUE;

typedef struct DirectDrawSurface4BltBatchMethodValue
{
    LPDDBLTBATCH Batch;
    DWORD Count;
    DWORD Options;
} DIRECTDRAWSURFACE4BLTBATCHMETHODVALUE, * LPDIRECTDRAWSURFACE4BLTBATCHMETHODVALUE;

typedef struct DirectDrawSurface4BltFastMethodValue
{
    DWORD X;
    DWORD Y;
    LPDIRECTDRAWSURFACE4 Surface;
    LPRECT Rect;
    DWORD Transparent;
} DIRECTDRAWSURFACE4BLTFASTMETHODVALUE, * LPDIRECTDRAWSURFACE4BLTFASTMETHODVALUE;

typedef struct DirectDrawSurface4DeleteAttachedSurfaceMethodValue
{
    DWORD Options;
    LPDIRECTDRAWSURFACE4 Surface;
} DIRECTDRAWSURFACE4DELETEATTACHEDSURFACEMETHODVALUE, * LPDIRECTDRAWSURFACE4DELETEATTACHEDSURFACEMETHODVALUE;

typedef struct DirectDrawSurface4EnumAttachedSurfacesMethodValue
{
    LPVOID Context;
    LPDDENUMSURFACESCALLBACK2 EnumSurfacesCallback;
} DIRECTDRAWSURFACE4ENUMATTACHEDSURFACESMETHODVALUE, * LPDIRECTDRAWSURFACE4ENUMATTACHEDSURFACESMETHODVALUE;

typedef struct DirectDrawSurface4EnumOverlayZOrdersMethodValue
{
    DWORD Options;
    LPVOID Context;
    LPDDENUMSURFACESCALLBACK2 Callback;
} DIRECTDRAWSURFACE4ENUMOVERLAYZORDERSMETHODVALUE, * LPDIRECTDRAWSURFACE4ENUMOVERLAYZORDERSMETHODVALUE;

typedef struct DirectDrawSurface4FlipMethodValue
{
    LPDIRECTDRAWSURFACE4 Surface;
    DWORD Options;
} DIRECTDRAWSURFACE4FLIPMETHODVALUE, * LPDIRECTDRAWSURFACE4FLIPMETHODVALUE;

typedef struct DirectDrawSurface4GetAttachedSurfaceMethodValue
{
    LPDDSCAPS2 Caps;
    LPDIRECTDRAWSURFACE4* Surface;
} DIRECTDRAWSURFACE4GETATTACHEDSURFACEMETHODVALUE, * LPDIRECTDRAWSURFACE4GETATTACHEDSURFACEMETHODVALUE;

typedef struct DirectDrawSurface4GetBltStatusMethodValue
{
    DWORD Options;
} DIRECTDRAWSURFACE4GETBLTSTATUSMETHODVALUE, * LPDIRECTDRAWSURFACE4GETBLTSTATUSMETHODVALUE;

typedef struct DirectDrawSurface4GetCapsMethodValue
{
    LPDDSCAPS2 Caps;
} DIRECTDRAWSURFACE4GETCAPSMETHODVALUE, * LPDIRECTDRAWSURFACE4GETCAPSMETHODVALUE;

typedef struct DirectDrawSurface4GetClipperMethodValue
{
    LPDIRECTDRAWCLIPPER* Clipper;
} DIRECTDRAWSURFACE4GETCLIPPERMETHODVALUE, * LPDIRECTDRAWSURFACE4GETCLIPPERMETHODVALUE;

typedef struct DirectDrawSurface4GetColorKeyMethodValue
{
    DWORD Options;
    LPDDCOLORKEY ColorKey;
} DIRECTDRAWSURFACE4GETCOLORKEYMETHODVALUE, * LPDIRECTDRAWSURFACE4GETCOLORKEYMETHODVALUE;

typedef struct DirectDrawSurface4GetDCMethodValue
{
    HDC* DC;
} DIRECTDRAWSURFACE4GETDCMETHODVALUE, * LPDIRECTDRAWSURFACE4GETDCMETHODVALUE;

typedef struct DirectDrawSurface4GetFlipStatusMethodValue
{
    DWORD Options;
} DIRECTDRAWSURFACE4GETFLIPSTATUSMETHODVALUE, * LPDIRECTDRAWSURFACE4GETFLIPSTATUSMETHODVALUE;

typedef struct DirectDrawSurface4GetOverlayPositionMethodValue
{
    LPLONG X;
    LPLONG Y;
} DIRECTDRAWSURFACE4GETOVERLAYPOSITIONMETHODVALUE, * LPDIRECTDRAWSURFACE4GETOVERLAYPOSITIONMETHODVALUE;

typedef struct DirectDrawSurface4GetPaletteMethodValue
{
    LPDIRECTDRAWPALETTE* Palette;
} DIRECTDRAWSURFACE4GETPALETTEMETHODVALUE, * LPDIRECTDRAWSURFACE4GETPALETTEMETHODVALUE;

typedef struct DirectDrawSurface4GetPixelFormatMethodValue
{
    LPDDPIXELFORMAT Format;
} DIRECTDRAWSURFACE4GETPIXELFORMATMETHODVALUE, * LPDIRECTDRAWSURFACE4GETPIXELFORMATMETHODVALUE;

typedef struct DirectDrawSurface4GetSurfaceDescMethodValue
{
    LPDDSURFACEDESC2 Descriptor;
} DIRECTDRAWSURFACE4GETSURFACEDESCMETHODVALUE, * LPDIRECTDRAWSURFACE4GETSURFACEDESCMETHODVALUE;

typedef struct DirectDrawSurface4InitializeMethodValue
{
    LPDIRECTDRAW Object;
    LPDDSURFACEDESC2 Descriptor;
} DIRECTDRAWSURFACE4INITIALIZEMETHODVALUE, * LPDIRECTDRAWSURFACE4INITIALIZEMETHODVALUE;

typedef struct DirectDrawSurface4IsLostMethodValue
{

} DIRECTDRAWSURFACE4ISLOSTMETHODVALUE, * LPDIRECTDRAWSURFACE4ISLOSTMETHODVALUE;

typedef struct DirectDrawSurface4LockMethodValue
{
    LPRECT Rect;
    LPDDSURFACEDESC2 Descriptor;
    DWORD Options;
    HANDLE Event;
} DIRECTDRAWSURFACE4LOCKMETHODVALUE, * LPDIRECTDRAWSURFACE4LOCKMETHODVALUE;

typedef struct DirectDrawSurface4ReleaseDCMethodValue
{
    HDC DC;
} DIRECTDRAWSURFACE4RELEASEDCMETHODVALUE, * LPDIRECTDRAWSURFACE4RELEASEDCMETHODVALUE;

typedef struct DirectDrawSurface4RestoreMethodValue
{

} DIRECTDRAWSURFACE4RESTOREMETHODVALUE, * LPDIRECTDRAWSURFACE4RESTOREMETHODVALUE;

typedef struct DirectDrawSurface4SetClipperMethodValue
{
    LPDIRECTDRAWCLIPPER Clipper;
} DIRECTDRAWSURFACE4SETCLIPPERMETHODVALUE, * LPDIRECTDRAWSURFACE4SETCLIPPERMETHODVALUE;

typedef struct DirectDrawSurface4SetColorKeyMethodValue
{
    DWORD Options;
    LPDDCOLORKEY ColorKey;
} DIRECTDRAWSURFACE4SETCOLORKEYMETHODVALUE, * LPDIRECTDRAWSURFACE4SETCOLORKEYMETHODVALUE;

typedef struct DirectDrawSurface4SetOverlayPositionMethodValue
{
    LONG X;
    LONG Y;
} DIRECTDRAWSURFACE4SETOVERLAYPOSITIONMETHODVALUE, * LPDIRECTDRAWSURFACE4SETOVERLAYPOSITIONMETHODVALUE;

typedef struct DirectDrawSurface4SetPaletteMethodValue
{
    LPDIRECTDRAWPALETTE Palette;
} DIRECTDRAWSURFACE4SETPALETTEMETHODVALUE, * LPDIRECTDRAWSURFACE4SETPALETTEMETHODVALUE;

typedef struct DirectDrawSurface4UnlockMethodValue
{
    LPVOID Value;
} DIRECTDRAWSURFACE4UNLOCKMETHODVALUE, * LPDIRECTDRAWSURFACE4UNLOCKMETHODVALUE;

typedef struct DirectDrawSurface4UpdateOverlayMethodValue
{
    LPRECT Source;
    LPDIRECTDRAWSURFACE4 Surface;
    LPRECT Destination;
    DWORD Options;
    LPDDOVERLAYFX Effect;
} DIRECTDRAWSURFACE4UPDATEOVERLAYMETHODVALUE, * LPDIRECTDRAWSURFACE4UPDATEOVERLAYMETHODVALUE;

typedef struct DirectDrawSurface4UpdateOverlayDisplayMethodValue
{
    DWORD Options;
} DIRECTDRAWSURFACE4UPDATEOVERLAYDISPLAYMETHODVALUE, * LPDIRECTDRAWSURFACE4UPDATEOVERLAYDISPLAYMETHODVALUE;

typedef struct DirectDrawSurface4UpdateOverlayZOrderMethodValue
{
    DWORD Options;
    LPDIRECTDRAWSURFACE4 Surface;
} DIRECTDRAWSURFACE4UPDATEOVERLAYZORDERMETHODVALUE, * LPDIRECTDRAWSURFACE4UPDATEOVERLAYZORDERMETHODVALUE;

typedef struct DirectDrawSurface4GetDDInterfaceMethodValue
{
    LPVOID* Object;
} DIRECTDRAWSURFACE4GETDDINTERFACEMETHODVALUE, * LPDIRECTDRAWSURFACE4GETDDINTERFACEMETHODVALUE;

typedef struct DirectDrawSurface4PageLockMethodValue
{
    DWORD Options;
} DIRECTDRAWSURFACE4PAGELOCKMETHODVALUE, * LPDIRECTDRAWSURFACE4PAGELOCKMETHODVALUE;

typedef struct DirectDrawSurface4PageUnlockMethodValue
{
    DWORD Options;
} DIRECTDRAWSURFACE4PAGEUNLOCKMETHODVALUE, * LPDIRECTDRAWSURFACE4PAGEUNLOCKMETHODVALUE;

typedef struct DirectDrawSurface4SetSurfaceDescMethodValue
{
    LPDDSURFACEDESC2 Descriptor;
    DWORD Options;
} DIRECTDRAWSURFACE4SETSURFACEDESCMETHODVALUE, * LPDIRECTDRAWSURFACE4SETSURFACEDESCMETHODVALUE;

typedef struct DirectDrawSurface4SetPrivateDataMethodValue
{
    GUID ID;
    LPVOID Value;
    DWORD Size;
    DWORD Options;
} DIRECTDRAWSURFACE4SETPRIVATEDATAMETHODVALUE, * LPDIRECTDRAWSURFACE4SETPRIVATEDATAMETHODVALUE;

typedef struct DirectDrawSurface4GetPrivateDataMethodValue
{
    GUID ID;
    LPVOID Value;
    LPDWORD Size;
} DIRECTDRAWSURFACE4GETPRIVATEDATAMETHODVALUE, * LPDIRECTDRAWSURFACE4GETPRIVATEDATAMETHODVALUE;

typedef struct DirectDrawSurface4FreePrivateDataMethodValue
{
    GUID ID;
} DIRECTDRAWSURFACE4FREEPRIVATEDATAMETHODVALUE, * LPDIRECTDRAWSURFACE4FREEPRIVATEDATAMETHODVALUE;

typedef struct DirectDrawSurface4GetUniquenessValueMethodValue
{
    LPDWORD Value;
} DIRECTDRAWSURFACE4GETUNIQUENESSVALUEMETHODVALUE, * LPDIRECTDRAWSURFACE4GETUNIQUENESSVALUEMETHODVALUE;

typedef struct DirectDrawSurface4ChangeUniquenessValueMethodValue
{

} DIRECTDRAWSURFACE4CHANGEUNIQUENESSVALUEMETHODVALUE, * LPDIRECTDRAWSURFACE4CHANGEUNIQUENESSVALUEMETHODVALUE;

typedef struct DirectDrawSurface4EnumAttachedSurfacesMethodCallbackValue
{
    LPVOID Object;
    LPDIRECTDRAWSURFACE4 Surface;
    LPDDSURFACEDESC2 Descriptor;
} DIRECTDRAWSURFACE4ENUMATTACHEDSURFACESMETHODCALLBACKVALUE, * LPDIRECTDRAWSURFACE4ENUMATTACHEDSURFACESMETHODCALLBACKVALUE;

typedef struct DirectDrawSurface4EnumOverlayZOrdersMethodCallbackValue
{
    LPVOID Object;
    LPDIRECTDRAWSURFACE4 Surface;
    LPDDSURFACEDESC2 Descriptor;
} DIRECTDRAWSURFACE4ENUMOVERLAYZORDERSMETHODCALLBACKVALUE, * LPDIRECTDRAWSURFACE4ENUMOVERLAYZORDERSMETHODCALLBACKVALUE;