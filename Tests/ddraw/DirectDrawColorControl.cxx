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

#include "DirectDrawColorControl.hxx"

#include "Window.hxx"

// NOTE: Color controls only work for an overlay/primary surface.
// SURFACE: ddsCaps.dwCaps & (DDSCAPS_PRIMARYSURFACE | DDSCAPS_OVERLAY)
//          AND
// DIRECTDRAW: GetCaps(...): (ddCaps.dwCaps2 & DDCAPS2_COLORCONTROLOVERLAY)

VOID DirectDrawColorControl(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    HWND hwnd = InitializeWindow();

    result = dd->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
    IsEqual(result, DD_OK);

    DDCAPS hal;
    ZeroMemory(&hal, sizeof(DDCAPS));

    hal.dwSize = sizeof(DDCAPS);

    DDCAPS hel;
    ZeroMemory(&hel, sizeof(DDCAPS));

    hel.dwSize = sizeof(DDCAPS);

    result = dd->GetCaps(&hal, &hel);
    IsEqual(result, DD_OK);

    if (((hal.dwCaps2 & DDCAPS2_COLORCONTROLOVERLAY) != 0 && hal.dwMaxVisibleOverlays != 0)
        || ((hel.dwCaps2 & DDCAPS2_COLORCONTROLOVERLAY) != 0 && hel.dwMaxVisibleOverlays != 0))
    {
        DDSURFACEDESC desc;
        ZeroMemory(&desc, sizeof(DDSURFACEDESC));

        desc.dwSize = sizeof(DDSURFACEDESC);
        desc.dwFlags = DDSD_CAPS;

        desc.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE | DDSCAPS_SYSTEMMEMORY;

        LPDIRECTDRAWSURFACE dds = NULL;
        result = dd->CreateSurface(&desc, &dds, NULL);
        IsEqual(result, DD_OK);

        IsNotEqual((LPVOID)dd, (LPVOID)dds);

        LPDIRECTDRAWCOLORCONTROL control = NULL;
        result = dds->QueryInterface(IID_IDirectDrawColorControl, (LPVOID*)&control);
        IsEqual(result, DD_OK);

        DIRECTRELEASE(dds);
    }

    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}