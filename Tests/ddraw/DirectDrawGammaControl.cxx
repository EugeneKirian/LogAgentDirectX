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

#include "DirectDrawGammaControl.hxx"

#include "Window.hxx"

VOID DirectDrawCreateGammaControl(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    HWND hwnd = InitializeWindow();

    result = dd->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
    IsEqual(result, DD_OK);

    dd->AddRef();
    IsEqual(dd->Release(), 1);

    DDSURFACEDESC desc;
    ZeroMemory(&desc, sizeof(DDSURFACEDESC));

    desc.dwSize = sizeof(DDSURFACEDESC);
    desc.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;

    desc.dwWidth = 640;
    desc.dwHeight = 480;
    desc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dd->CreateSurface(&desc, &dds1, NULL);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds1);

    dds1->AddRef();
    IsEqual(dds1->Release(), 1);

    LPDIRECTDRAWGAMMACONTROL gamma1 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma1);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dds1, (LPVOID)gamma1);
    IsNotEqual((LPVOID)dd, (LPVOID)gamma1);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds1, (LPVOID)dds2);

    LPDIRECTDRAWGAMMACONTROL gamma2 = NULL;
    result = dds2->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma2);
    IsEqual(result, DD_OK);

    IsEqual(gamma1, gamma2);
    IsNotEqual((LPVOID)dd, (LPVOID)gamma2);
    IsNotEqual((LPVOID)dds1, (LPVOID)gamma2);
    IsNotEqual((LPVOID)dds2, (LPVOID)gamma2);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = dds2->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds1, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds2, (LPVOID)dds3);

    LPDIRECTDRAWGAMMACONTROL gamma3 = NULL;
    result = dds3->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma3);
    IsEqual(result, DD_OK);

    IsEqual(gamma1, gamma2);
    IsEqual(gamma2, gamma3);
    IsNotEqual((LPVOID)dd, (LPVOID)gamma3);
    IsNotEqual((LPVOID)dds1, (LPVOID)gamma3);
    IsNotEqual((LPVOID)dds2, (LPVOID)gamma3);
    IsNotEqual((LPVOID)dds3, (LPVOID)gamma3);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = dds3->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds1, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds2, (LPVOID)dds3);

    LPDIRECTDRAWGAMMACONTROL gamma4 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma4);
    IsEqual(result, DD_OK);

    IsEqual(gamma1, gamma2);
    IsEqual(gamma2, gamma3);
    IsEqual(gamma3, gamma4);
    IsNotEqual((LPVOID)dd, (LPVOID)gamma4);
    IsNotEqual((LPVOID)dds1, (LPVOID)gamma4);
    IsNotEqual((LPVOID)dds2, (LPVOID)gamma4);
    IsNotEqual((LPVOID)dds3, (LPVOID)gamma4);
    IsNotEqual((LPVOID)dds4, (LPVOID)gamma4);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = dds3->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds1, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds2, (LPVOID)dds3);

    LPDIRECTDRAWGAMMACONTROL gamma7 = NULL;
    result = dds7->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma7);
    IsEqual(result, DD_OK);

    IsEqual(gamma1, gamma2);
    IsEqual(gamma2, gamma3);
    IsEqual(gamma3, gamma4);
    IsEqual(gamma4, gamma7);
    IsNotEqual((LPVOID)dd, (LPVOID)gamma7);
    IsNotEqual((LPVOID)dds1, (LPVOID)gamma7);
    IsNotEqual((LPVOID)dds2, (LPVOID)gamma7);
    IsNotEqual((LPVOID)dds3, (LPVOID)gamma7);
    IsNotEqual((LPVOID)dds4, (LPVOID)gamma7);
    IsNotEqual((LPVOID)dds7, (LPVOID)gamma7);

    DIRECTRELEASE(gamma1);
    DIRECTRELEASE(gamma2);
    DIRECTRELEASE(gamma3);
    DIRECTRELEASE(gamma4);
    DIRECTRELEASE(gamma7);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dds2);
    DIRECTRELEASE(dds3);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dds7);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw2CreateGammaControl(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW2 dd2 = NULL;
    result = dd->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsEqual(result, DD_OK);

    HWND hwnd = InitializeWindow();

    result = dd2->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
    IsEqual(result, DD_OK);

    dd2->AddRef();
    IsEqual(dd2->Release(), 1);

    DDSURFACEDESC desc;
    ZeroMemory(&desc, sizeof(DDSURFACEDESC));

    desc.dwSize = sizeof(DDSURFACEDESC);
    desc.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;

    desc.dwWidth = 640;
    desc.dwHeight = 480;
    desc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dd2->CreateSurface(&desc, &dds1, NULL);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd2, (LPVOID)dds1);

    dds1->AddRef();
    IsEqual(dds1->Release(), 1);

    LPDIRECTDRAWGAMMACONTROL gamma1 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma1);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dds1, (LPVOID)gamma1);
    IsNotEqual((LPVOID)dd2, (LPVOID)gamma1);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds1, (LPVOID)dds2);

    LPDIRECTDRAWGAMMACONTROL gamma2 = NULL;
    result = dds2->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma2);
    IsEqual(result, DD_OK);

    IsEqual(gamma1, gamma2);
    IsNotEqual((LPVOID)dd, (LPVOID)gamma2);
    IsNotEqual((LPVOID)dds1, (LPVOID)gamma2);
    IsNotEqual((LPVOID)dds2, (LPVOID)gamma2);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = dds2->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds1, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds2, (LPVOID)dds3);

    LPDIRECTDRAWGAMMACONTROL gamma3 = NULL;
    result = dds3->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma3);
    IsEqual(result, DD_OK);

    IsEqual(gamma1, gamma2);
    IsEqual(gamma2, gamma3);
    IsNotEqual((LPVOID)dd, (LPVOID)gamma3);
    IsNotEqual((LPVOID)dds1, (LPVOID)gamma3);
    IsNotEqual((LPVOID)dds2, (LPVOID)gamma3);
    IsNotEqual((LPVOID)dds3, (LPVOID)gamma3);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = dds3->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds1, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds2, (LPVOID)dds3);

    LPDIRECTDRAWGAMMACONTROL gamma4 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma4);
    IsEqual(result, DD_OK);

    IsEqual(gamma1, gamma2);
    IsEqual(gamma2, gamma3);
    IsEqual(gamma3, gamma4);
    IsNotEqual((LPVOID)dd, (LPVOID)gamma4);
    IsNotEqual((LPVOID)dds1, (LPVOID)gamma4);
    IsNotEqual((LPVOID)dds2, (LPVOID)gamma4);
    IsNotEqual((LPVOID)dds3, (LPVOID)gamma4);
    IsNotEqual((LPVOID)dds4, (LPVOID)gamma4);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = dds3->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds1, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds2, (LPVOID)dds3);

    LPDIRECTDRAWGAMMACONTROL gamma7 = NULL;
    result = dds7->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma7);
    IsEqual(result, DD_OK);

    IsEqual(gamma1, gamma2);
    IsEqual(gamma2, gamma3);
    IsEqual(gamma3, gamma4);
    IsEqual(gamma4, gamma7);
    IsNotEqual((LPVOID)dd, (LPVOID)gamma7);
    IsNotEqual((LPVOID)dds1, (LPVOID)gamma7);
    IsNotEqual((LPVOID)dds2, (LPVOID)gamma7);
    IsNotEqual((LPVOID)dds3, (LPVOID)gamma7);
    IsNotEqual((LPVOID)dds4, (LPVOID)gamma7);
    IsNotEqual((LPVOID)dds7, (LPVOID)gamma7);

    DIRECTRELEASE(gamma1);
    DIRECTRELEASE(gamma2);
    DIRECTRELEASE(gamma3);
    DIRECTRELEASE(gamma4);
    DIRECTRELEASE(gamma7);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dds2);
    DIRECTRELEASE(dds3);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dds7);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw4CreateGammaControl(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW4 dd4 = NULL;
    result = dd->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsEqual(result, DD_OK);

    HWND hwnd = InitializeWindow();

    result = dd4->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
    IsEqual(result, DD_OK);

    dd4->AddRef();
    IsEqual(dd4->Release(), 1);

    DDSURFACEDESC2 desc;
    ZeroMemory(&desc, sizeof(DDSURFACEDESC2));

    desc.dwSize = sizeof(DDSURFACEDESC2);
    desc.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;

    desc.dwWidth = 640;
    desc.dwHeight = 480;
    desc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = dd4->CreateSurface(&desc, &dds4, NULL);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd4, (LPVOID)dds4);

    dds4->AddRef();
    IsEqual(dds4->Release(), 1);

    LPDIRECTDRAWGAMMACONTROL gamma1 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma1);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dds4, (LPVOID)gamma1);
    IsNotEqual((LPVOID)dd4, (LPVOID)gamma1);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds4, (LPVOID)dds2);

    LPDIRECTDRAWGAMMACONTROL gamma2 = NULL;
    result = dds2->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma2);
    IsEqual(result, DD_OK);

    IsEqual(gamma1, gamma2);
    IsNotEqual((LPVOID)dd, (LPVOID)gamma2);
    IsNotEqual((LPVOID)dds4, (LPVOID)gamma2);
    IsNotEqual((LPVOID)dds2, (LPVOID)gamma2);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = dds2->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds4, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds2, (LPVOID)dds3);

    LPDIRECTDRAWGAMMACONTROL gamma3 = NULL;
    result = dds3->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma3);
    IsEqual(result, DD_OK);

    IsEqual(gamma1, gamma2);
    IsEqual(gamma2, gamma3);
    IsNotEqual((LPVOID)dd, (LPVOID)gamma3);
    IsNotEqual((LPVOID)dds4, (LPVOID)gamma3);
    IsNotEqual((LPVOID)dds2, (LPVOID)gamma3);
    IsNotEqual((LPVOID)dds3, (LPVOID)gamma3);

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dds3->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds4, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds2, (LPVOID)dds3);

    LPDIRECTDRAWGAMMACONTROL gamma4 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma4);
    IsEqual(result, DD_OK);

    IsEqual(gamma1, gamma2);
    IsEqual(gamma2, gamma3);
    IsEqual(gamma3, gamma4);
    IsNotEqual((LPVOID)dd, (LPVOID)gamma4);
    IsNotEqual((LPVOID)dds4, (LPVOID)gamma4);
    IsNotEqual((LPVOID)dds2, (LPVOID)gamma4);
    IsNotEqual((LPVOID)dds3, (LPVOID)gamma4);
    IsNotEqual((LPVOID)dds1, (LPVOID)gamma4);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = dds3->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds4, (LPVOID)dds2);
    IsNotEqual((LPVOID)dds2, (LPVOID)dds3);

    LPDIRECTDRAWGAMMACONTROL gamma7 = NULL;
    result = dds7->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma7);
    IsEqual(result, DD_OK);

    IsEqual(gamma1, gamma2);
    IsEqual(gamma2, gamma3);
    IsEqual(gamma3, gamma4);
    IsEqual(gamma4, gamma7);
    IsNotEqual((LPVOID)dd, (LPVOID)gamma7);
    IsNotEqual((LPVOID)dds4, (LPVOID)gamma7);
    IsNotEqual((LPVOID)dds2, (LPVOID)gamma7);
    IsNotEqual((LPVOID)dds3, (LPVOID)gamma7);
    IsNotEqual((LPVOID)dds1, (LPVOID)gamma7);
    IsNotEqual((LPVOID)dds7, (LPVOID)gamma7);

    DIRECTRELEASE(gamma1);
    DIRECTRELEASE(gamma2);
    DIRECTRELEASE(gamma3);
    DIRECTRELEASE(gamma4);
    DIRECTRELEASE(gamma7);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dds2);
    DIRECTRELEASE(dds3);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dds7);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw7CreateGammaControl(LPMODULE module)
{
    LPDIRECTDRAW7 dd7 = NULL;
    HRESULT result = module->DirectDrawCreateEx(NULL, (LPVOID*)&dd7, IID_IDirectDraw7, NULL);
    IsEqual(result, DD_OK);

    HWND hwnd = InitializeWindow();

    result = dd7->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
    IsEqual(result, DD_OK);

    dd7->AddRef();
    IsEqual(dd7->Release(), 1);

    DDSURFACEDESC2 desc;
    ZeroMemory(&desc, sizeof(DDSURFACEDESC2));

    desc.dwSize = sizeof(DDSURFACEDESC2);
    desc.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;

    desc.dwWidth = 640;
    desc.dwHeight = 480;
    desc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = dd7->CreateSurface(&desc, &dds7, NULL);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd7, (LPVOID)dds7);

    dds7->AddRef();
    IsEqual(dds7->Release(), 1);

    LPDIRECTDRAWGAMMACONTROL gamma7 = NULL;
    result = dds7->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma7);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd7, (LPVOID)gamma7);
    IsNotEqual((LPVOID)dds7, (LPVOID)gamma7);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = dds7->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dds7, (LPVOID)dds4);

    dds4->AddRef();
    IsEqual(dds4->Release(), 1);

    LPDIRECTDRAWGAMMACONTROL gamma4 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma4);
    IsEqual(result, DD_OK);

    IsEqual(gamma4, gamma7);
    IsNotEqual((LPVOID)dd7, (LPVOID)gamma4);
    IsNotEqual((LPVOID)dds7, (LPVOID)gamma4);
    IsNotEqual((LPVOID)dds4, (LPVOID)gamma4);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = dds7->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dds7, (LPVOID)dds3);

    dds3->AddRef();
    IsEqual(dds3->Release(), 1);

    LPDIRECTDRAWGAMMACONTROL gamma3 = NULL;
    result = dds3->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma3);
    IsEqual(result, DD_OK);

    IsEqual(gamma4, gamma3);
    IsEqual(gamma4, gamma7);
    IsNotEqual((LPVOID)dd7, (LPVOID)gamma3);
    IsNotEqual((LPVOID)dds7, (LPVOID)gamma3);
    IsNotEqual((LPVOID)dds4, (LPVOID)gamma3);
    IsNotEqual((LPVOID)dds3, (LPVOID)gamma3);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = dds7->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dds7, (LPVOID)dds3);

    dds2->AddRef();
    IsEqual(dds2->Release(), 1);

    LPDIRECTDRAWGAMMACONTROL gamma2 = NULL;
    result = dds2->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma2);
    IsEqual(result, DD_OK);

    IsEqual(gamma3, gamma2);
    IsEqual(gamma4, gamma3);
    IsEqual(gamma4, gamma7);
    IsNotEqual((LPVOID)dd7, (LPVOID)gamma2);
    IsNotEqual((LPVOID)dds7, (LPVOID)gamma2);
    IsNotEqual((LPVOID)dds4, (LPVOID)gamma2);
    IsNotEqual((LPVOID)dds3, (LPVOID)gamma2);
    IsNotEqual((LPVOID)dds2, (LPVOID)gamma2);

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dds7->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dds7, (LPVOID)dds3);

    dds1->AddRef();
    IsEqual(dds1->Release(), 1);

    LPDIRECTDRAWGAMMACONTROL gamma1 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma1);
    IsEqual(result, DD_OK);

    IsEqual(gamma2, gamma1);
    IsEqual(gamma3, gamma2);
    IsEqual(gamma4, gamma3);
    IsEqual(gamma4, gamma7);
    IsNotEqual((LPVOID)dd7, (LPVOID)gamma1);
    IsNotEqual((LPVOID)dds7, (LPVOID)gamma1);
    IsNotEqual((LPVOID)dds4, (LPVOID)gamma1);
    IsNotEqual((LPVOID)dds3, (LPVOID)gamma1);
    IsNotEqual((LPVOID)dds2, (LPVOID)gamma1);
    IsNotEqual((LPVOID)dds1, (LPVOID)gamma1);

    DIRECTRELEASE(gamma1);
    DIRECTRELEASE(gamma2);
    DIRECTRELEASE(gamma3);
    DIRECTRELEASE(gamma4);
    DIRECTRELEASE(gamma7);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dds2);
    DIRECTRELEASE(dds3);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dds7);
    DIRECTRELEASE(dd7);

    ReleaseWindow(hwnd);
}

VOID DirectDrawGammaControlQueryInterfaceIUnknown(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    HWND hwnd = InitializeWindow();

    result = dd->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
    IsEqual(result, DD_OK);

    dd->AddRef();
    IsEqual(dd->Release(), 1);

    DDSURFACEDESC desc;
    ZeroMemory(&desc, sizeof(DDSURFACEDESC));

    desc.dwSize = sizeof(DDSURFACEDESC);
    desc.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;

    desc.dwWidth = 640;
    desc.dwHeight = 480;
    desc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

    LPDIRECTDRAWSURFACE dds = NULL;
    result = dd->CreateSurface(&desc, &dds, NULL);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds);

    dds->AddRef();
    IsEqual(dds->Release(), 1);

    LPDIRECTDRAWGAMMACONTROL gamma = NULL;
    result = dds->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dds, (LPVOID)gamma);

    LPUNKNOWN unk = NULL;
    result = gamma->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)unk, (LPVOID)gamma);
    IsEqual((LPVOID)unk, (LPVOID)dds);

    DIRECTRELEASE(unk);
    DIRECTRELEASE(gamma);
    DIRECTRELEASE(dds);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw2GammaControlQueryInterfaceIUnknown(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW2 dd2 = NULL;
    result = dd->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsEqual(result, DD_OK);

    HWND hwnd = InitializeWindow();

    result = dd2->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
    IsEqual(result, DD_OK);

    dd->AddRef();
    IsEqual(dd->Release(), 1);

    DDSURFACEDESC desc;
    ZeroMemory(&desc, sizeof(DDSURFACEDESC));

    desc.dwSize = sizeof(DDSURFACEDESC);
    desc.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;

    desc.dwWidth = 640;
    desc.dwHeight = 480;
    desc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

    LPDIRECTDRAWSURFACE dds = NULL;
    result = dd2->CreateSurface(&desc, &dds, NULL);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds);

    dds->AddRef();
    IsEqual(dds->Release(), 1);

    LPDIRECTDRAWGAMMACONTROL gamma = NULL;
    result = dds->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dds, (LPVOID)gamma);

    LPUNKNOWN unk = NULL;
    result = gamma->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)unk, (LPVOID)gamma);
    IsEqual((LPVOID)unk, (LPVOID)dds);

    DIRECTRELEASE(unk);
    DIRECTRELEASE(gamma);
    DIRECTRELEASE(dds);
    DIRECTRELEASE(dd2);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw4GammaControlQueryInterfaceIUnknown(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW4 dd4 = NULL;
    result = dd->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsEqual(result, DD_OK);

    HWND hwnd = InitializeWindow();

    result = dd4->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
    IsEqual(result, DD_OK);

    dd->AddRef();
    IsEqual(dd->Release(), 1);

    DDSURFACEDESC2 desc;
    ZeroMemory(&desc, sizeof(DDSURFACEDESC2));

    desc.dwSize = sizeof(DDSURFACEDESC2);
    desc.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;

    desc.dwWidth = 640;
    desc.dwHeight = 480;
    desc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = dd4->CreateSurface(&desc, &dds4, NULL);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds4);

    dds4->AddRef();
    IsEqual(dds4->Release(), 1);

    LPDIRECTDRAWGAMMACONTROL gamma = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dds4, (LPVOID)gamma);

    LPUNKNOWN unk = NULL;
    result = gamma->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)unk, (LPVOID)gamma);
    IsNotEqual((LPVOID)unk, (LPVOID)dds4);

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsEqual(result, DD_OK);

    IsEqual((LPVOID)unk, (LPVOID)dds1);

    DIRECTRELEASE(dds1);
    DIRECTRELEASE(unk);
    DIRECTRELEASE(gamma);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dd4);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw7GammaControlQueryInterfaceIUnknown(LPMODULE module)
{
    LPDIRECTDRAW7 dd = NULL;
    HRESULT result = module->DirectDrawCreateEx(NULL, (LPVOID*)&dd, IID_IDirectDraw7, NULL);
    IsEqual(result, DD_OK);

    HWND hwnd = InitializeWindow();

    result = dd->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
    IsEqual(result, DD_OK);

    dd->AddRef();
    IsEqual(dd->Release(), 1);

    DDSURFACEDESC2 desc;
    ZeroMemory(&desc, sizeof(DDSURFACEDESC2));

    desc.dwSize = sizeof(DDSURFACEDESC2);
    desc.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;

    desc.dwWidth = 640;
    desc.dwHeight = 480;
    desc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = dd->CreateSurface(&desc, &dds7, NULL);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds7);

    dds7->AddRef();
    IsEqual(dds7->Release(), 1);

    LPDIRECTDRAWGAMMACONTROL gamma = NULL;
    result = dds7->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)gamma);
    IsNotEqual((LPVOID)dds7, (LPVOID)gamma);

    LPUNKNOWN unk = NULL;
    result = gamma->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)unk, (LPVOID)gamma);
    IsNotEqual((LPVOID)unk, (LPVOID)dds7);

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dds7->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsEqual(result, DD_OK);

    IsEqual((LPVOID)unk, (LPVOID)dds1);

    DIRECTRELEASE(dds1);
    DIRECTRELEASE(unk);
    DIRECTRELEASE(gamma);
    DIRECTRELEASE(dds7);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDrawGammaControlQuery(LPDIRECTDRAWGAMMACONTROL gamma, const BOOL seven)
{
    /* Direct3D */

    LPDIRECT3D dd3d1 = NULL;
    HRESULT result = gamma->QueryInterface(IID_IDirect3D, (LPVOID*)&dd3d1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d1, NULL);

    LPDIRECT3D2 dd3d2 = NULL;
    result = gamma->QueryInterface(IID_IDirect3D2, (LPVOID*)&dd3d2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d2, NULL);

    LPDIRECT3D3 dd3d3 = NULL;
    result = gamma->QueryInterface(IID_IDirect3D3, (LPVOID*)&dd3d3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d3, NULL);

    LPDIRECT3D3 dd3d7 = NULL;
    result = gamma->QueryInterface(IID_IDirect3D7, (LPVOID*)&dd3d7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d7, NULL);

    /* Direct3DDevice */

    LPDIRECT3DDEVICE dd3dd1 = NULL;
    result = gamma->QueryInterface(IID_IDirect3DDevice, (LPVOID*)&dd3dd1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    LPDIRECT3DDEVICE2 dd3dd2 = NULL;
    result = gamma->QueryInterface(IID_IDirect3DDevice2, (LPVOID*)&dd3dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd2, NULL);

    LPDIRECT3DDEVICE3 dd3dd3 = NULL;
    result = gamma->QueryInterface(IID_IDirect3DDevice3, (LPVOID*)&dd3dd3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd3, NULL);

    LPDIRECT3DDEVICE7 dd3dd7 = NULL;
    result = gamma->QueryInterface(IID_IDirect3DDevice7, (LPVOID*)&dd3dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd7, NULL);

    // NOTE: DirectDraw fails here...

    //LPDIRECT3DDEVICE d3drd = NULL;
    //result = gamma->QueryInterface(IID_IDirect3DRampDevice, (LPVOID*)&d3drd);
    //IsNotEqual(result, DD_OK);
    //IsEqual((LPVOID)d3drd, NULL);

    //LPDIRECT3DDEVICE d3drgbd = NULL;
    //result = gamma->QueryInterface(IID_IDirect3DRGBDevice, (LPVOID*)&d3drgbd);
    //IsNotEqual(result, DD_OK);
    //IsEqual((LPVOID)d3drgbd, NULL);

    //LPDIRECT3DDEVICE d3dhald = NULL;
    //result = gamma->QueryInterface(IID_IDirect3DHALDevice, (LPVOID*)&d3dhald);
    //IsNotEqual(result, DD_OK);
    //IsEqual((LPVOID)d3dhald, NULL);

    //LPDIRECT3DDEVICE d3dmmxd = NULL;
    //result = gamma->QueryInterface(IID_IDirect3DMMXDevice, (LPVOID*)&d3dmmxd);
    //IsNotEqual(result, DD_OK);
    //IsEqual((LPVOID)d3dmmxd, NULL);

    //LPDIRECT3DDEVICE d3drefd = NULL;
    //result = gamma->QueryInterface(IID_IDirect3DRefDevice, (LPVOID*)&d3drefd);
    //IsNotEqual(result, DD_OK);
    //IsEqual((LPVOID)d3drefd, NULL);

    //LPDIRECT3DDEVICE d3dnd = NULL;
    //result = gamma->QueryInterface(IID_IDirect3DNullDevice, (LPVOID*)&d3dnd);
    //IsNotEqual(result, DD_OK);
    //IsEqual((LPVOID)d3dnd, NULL);

    LPDIRECT3DDEVICE d3dtnlhald = NULL;
    result = gamma->QueryInterface(IID_IDirect3DTnLHalDevice, (LPVOID*)&d3dtnlhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dtnlhald, NULL);

    /* Direct3DExecuteBuffer */

    LPDIRECT3DEXECUTEBUFFER d3deb = NULL;
    result = gamma->QueryInterface(IID_IDirect3DExecuteBuffer, (LPVOID*)&d3deb);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    /* Direct3DLight */
    LPDIRECT3DLIGHT d3dl = NULL;
    result = gamma->QueryInterface(IID_IDirect3DLight, (LPVOID*)&d3dl);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dl, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dm1 = NULL;
    result = gamma->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dm1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm1, NULL);

    LPDIRECT3DMATERIAL2 d3dm2 = NULL;
    result = gamma->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dm2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm2, NULL);

    LPDIRECT3DMATERIAL3 d3dm3 = NULL;
    result = gamma->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dm3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm3, NULL);

    /* Direct3DTexture */

    LPDIRECT3DTEXTURE d3dt1 = NULL;
    result = gamma->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&d3dt1);

    if (seven)
    {
        IsNotEqual(result, DD_OK);
        IsEqual((LPVOID)d3dt1, NULL);
    }
    else
    {
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)gamma, (LPVOID)d3dt1);
        DIRECTRELEASE(d3dt1);
    }

    LPDIRECT3DTEXTURE2 d3dt2 = NULL;
    result = gamma->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&d3dt2);

    if (seven)
    {
        IsNotEqual(result, DD_OK);
        IsEqual((LPVOID)d3dt2, NULL);
    }
    else
    {
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)gamma, (LPVOID)d3dt2);
        DIRECTRELEASE(d3dt2);
    }

    /* Direct3DVertexBuffer */

    LPDIRECT3DVERTEXBUFFER d3dvb1 = NULL;
    result = gamma->QueryInterface(IID_IDirect3DVertexBuffer, (LPVOID*)&d3dvb1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb1, NULL);

    LPDIRECT3DVERTEXBUFFER7 d3dvb7 = NULL;
    result = gamma->QueryInterface(IID_IDirect3DVertexBuffer7, (LPVOID*)&d3dvb7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb7, NULL);

    /* Direct3DViewport */

    LPDIRECT3DVIEWPORT d3dvp1 = NULL;
    result = gamma->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&d3dvp1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvp1, NULL);

    LPDIRECT3DVIEWPORT2 d3dvp2 = NULL;
    result = gamma->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&d3dvp2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvp2, NULL);

    LPDIRECT3DVIEWPORT3 d3dvp3 = NULL;
    result = gamma->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&d3dvp3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvp3, NULL);

    /* DirectDraw */

    LPDIRECTDRAW dd = NULL;
    result = gamma->QueryInterface(IID_IDirectDraw, (LPVOID*)&dd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd, NULL);

    LPDIRECTDRAW2 dd2 = NULL;
    result = gamma->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd2, NULL);

    LPDIRECTDRAW4 dd4 = NULL;
    result = gamma->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd4, NULL);

    LPDIRECTDRAW7 dd7 = NULL;
    result = gamma->QueryInterface(IID_IDirectDraw7, (LPVOID*)&dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd7, NULL);

    /* DirectDrawClipper */

    LPDIRECTDRAWCLIPPER ddc = NULL;
    result = gamma->QueryInterface(IID_IDirectDrawClipper, (LPVOID*)&ddc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddc, NULL);

    /* DirectDrawColorControl */

    LPDIRECTDRAWCOLORCONTROL ddcc = NULL;
    result = gamma->QueryInterface(IID_IDirectDrawColorControl, (LPVOID*)&ddcc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddcc, NULL);

    /* DirectDrawGammaControl */

    LPDIRECTDRAWGAMMACONTROL ddgc = NULL;
    result = gamma->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&ddgc);
    IsEqual(result, DD_OK);
    IsEqual(gamma, ddgc);
    DIRECTRELEASE(ddgc);

    /* DirectDrawPalette */

    LPDIRECTDRAWPALETTE ddp = NULL;
    result = gamma->QueryInterface(IID_IDirectDrawPalette, (LPVOID*)&ddp);
    IsNotEqual(result, DD_OK);
    DIRECTRELEASE(ddp);

    /* DirectDrawSurface */

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = gamma->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)gamma, (LPVOID)dds1);
    DIRECTRELEASE(dds1);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = gamma->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)gamma, (LPVOID)dds2);
    DIRECTRELEASE(dds2);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = gamma->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)gamma, (LPVOID)dds3);
    DIRECTRELEASE(dds3);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = gamma->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)gamma, (LPVOID)dds4);
    DIRECTRELEASE(dds4);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = gamma->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)gamma, (LPVOID)dds7);
    DIRECTRELEASE(dds7);

    /* DirectDrawVideoPort */
    LPDIRECTDRAWVIDEOPORT ddvp = NULL;
    result = gamma->QueryInterface(IID_IDirectDrawVideoPort, (LPVOID*)&ddvp);
    IsNotEqual(result, DD_OK);
    IsEqual(ddvp, NULL);

    /* DirectDrawVideoPortContainer */

    LPDDVIDEOPORTCONTAINER ddvpc = NULL;
    result = gamma->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&ddvpc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddvpc, NULL);

    /* DirectDrawVideoPortNotify */

    LPDDVIDEOPORTNOTIFY ddvpn = NULL;
    result = gamma->QueryInterface(IID_IDirectDrawVideoPortNotify, (LPVOID*)&ddvpn);
    IsNotEqual(result, DD_OK);

    /* Unknown */

    LPUNKNOWN unk = NULL;
    result = gamma->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);
    IsNotEqual(gamma, unk);
    DIRECTRELEASE(unk);
}

VOID DirectDrawGammaControlQueryInterfaceAll(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    HWND hwnd = InitializeWindow();

    result = dd->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
    IsEqual(result, DD_OK);

    dd->AddRef();
    IsEqual(dd->Release(), 1);

    DDSURFACEDESC desc;
    ZeroMemory(&desc, sizeof(DDSURFACEDESC));

    desc.dwSize = sizeof(DDSURFACEDESC);
    desc.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;

    desc.dwWidth = 640;
    desc.dwHeight = 480;
    desc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

    LPDIRECTDRAWSURFACE dds = NULL;
    result = dd->CreateSurface(&desc, &dds, NULL);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds);

    dds->AddRef();
    IsEqual(dds->Release(), 1);

    LPDIRECTDRAWGAMMACONTROL gamma = NULL;
    result = dds->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dds, (LPVOID)gamma);

    DirectDrawGammaControlQuery(gamma, FALSE);

    gamma->AddRef();
    IsEqual(gamma->Release(), 1);

    DIRECTRELEASE(gamma);
    DIRECTRELEASE(dds);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw2GammaControlQueryInterfaceAll(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW2 dd2 = NULL;
    result = dd->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsEqual(result, DD_OK);

    HWND hwnd = InitializeWindow();

    result = dd2->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
    IsEqual(result, DD_OK);

    dd->AddRef();
    IsEqual(dd->Release(), 1);

    DDSURFACEDESC desc;
    ZeroMemory(&desc, sizeof(DDSURFACEDESC));

    desc.dwSize = sizeof(DDSURFACEDESC);
    desc.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;

    desc.dwWidth = 640;
    desc.dwHeight = 480;
    desc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

    LPDIRECTDRAWSURFACE dds = NULL;
    result = dd2->CreateSurface(&desc, &dds, NULL);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds);

    dds->AddRef();
    IsEqual(dds->Release(), 1);

    LPDIRECTDRAWGAMMACONTROL gamma = NULL;
    result = dds->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dds, (LPVOID)gamma);

    DirectDrawGammaControlQuery(gamma, FALSE);

    gamma->AddRef();
    IsEqual(gamma->Release(), 1);

    DIRECTRELEASE(gamma);
    DIRECTRELEASE(dds);
    DIRECTRELEASE(dd2);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw4GammaControlQueryInterfaceAll(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW4 dd4 = NULL;
    result = dd->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsEqual(result, DD_OK);

    HWND hwnd = InitializeWindow();

    result = dd4->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
    IsEqual(result, DD_OK);

    dd->AddRef();
    IsEqual(dd->Release(), 1);

    DDSURFACEDESC2 desc;
    ZeroMemory(&desc, sizeof(DDSURFACEDESC2));

    desc.dwSize = sizeof(DDSURFACEDESC2);
    desc.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;

    desc.dwWidth = 640;
    desc.dwHeight = 480;
    desc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

    LPDIRECTDRAWSURFACE4 dds = NULL;
    result = dd4->CreateSurface(&desc, &dds, NULL);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds);

    dds->AddRef();
    IsEqual(dds->Release(), 1);

    LPDIRECTDRAWGAMMACONTROL gamma = NULL;
    result = dds->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dds, (LPVOID)gamma);

    DirectDrawGammaControlQuery(gamma, FALSE);

    gamma->AddRef();
    IsEqual(gamma->Release(), 1);

    DIRECTRELEASE(gamma);
    DIRECTRELEASE(dds);
    DIRECTRELEASE(dd4);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw7GammaControlQueryInterfaceAll(LPMODULE module)
{
    LPDIRECTDRAW7 dd = NULL;
    HRESULT result = module->DirectDrawCreateEx(NULL, (LPVOID*)&dd, IID_IDirectDraw7, NULL);
    IsEqual(result, DD_OK);

    HWND hwnd = InitializeWindow();

    result = dd->SetCooperativeLevel(hwnd, DDSCL_NORMAL);
    IsEqual(result, DD_OK);

    dd->AddRef();
    IsEqual(dd->Release(), 1);

    DDSURFACEDESC2 desc;
    ZeroMemory(&desc, sizeof(DDSURFACEDESC2));

    desc.dwSize = sizeof(DDSURFACEDESC2);
    desc.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;

    desc.dwWidth = 640;
    desc.dwHeight = 480;
    desc.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;

    LPDIRECTDRAWSURFACE7 dds = NULL;
    result = dd->CreateSurface(&desc, &dds, NULL);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)dds);

    dds->AddRef();
    IsEqual(dds->Release(), 1);

    LPDIRECTDRAWGAMMACONTROL gamma = NULL;
    result = dds->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&gamma);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)dd, (LPVOID)gamma);
    IsNotEqual((LPVOID)dds, (LPVOID)gamma);

    DirectDrawGammaControlQuery(gamma, TRUE);

    gamma->AddRef();
    IsEqual(gamma->Release(), 1);
    

    DIRECTRELEASE(gamma);
    DIRECTRELEASE(dds);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}