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

#include "Direct3DTexture.hxx"

#include "Window.hxx"

VOID DirectDrawCreateSurfaceTexture(LPMODULE module)
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

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsEqual(result, DD_OK);

    {
        LPDIRECT3DTEXTURE dds1t1 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds1t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t1, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);

        LPDIRECT3DTEXTURE2 dds1t2 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds1t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t2, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t2);
        IsNotEqual((LPVOID)dds1t1, (LPVOID)dds1t2);

        DIRECTRELEASE(dds1t1);
        DIRECTRELEASE(dds1t2);
    }

    {
        LPDIRECT3DTEXTURE dds2t1 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds2t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t1, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);

        LPDIRECT3DTEXTURE2 dds2t2 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds2t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t2, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t2);
        IsNotEqual((LPVOID)dds2t1, (LPVOID)dds2t2);

        DIRECTRELEASE(dds2t1);
        DIRECTRELEASE(dds2t2);
    }

    {
        LPDIRECT3DTEXTURE dds3t1 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds3t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t1, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);

        LPDIRECT3DTEXTURE2 dds3t2 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds3t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t2, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t2);
        IsNotEqual((LPVOID)dds3t1, (LPVOID)dds3t2);

        DIRECTRELEASE(dds3t1);
        DIRECTRELEASE(dds3t2);
    }

    {
        LPDIRECT3DTEXTURE dds4t1 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds4t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t1, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);

        LPDIRECT3DTEXTURE2 dds4t2 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds4t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t2, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t2);
        IsNotEqual((LPVOID)dds4t1, (LPVOID)dds4t2);

        DIRECTRELEASE(dds4t1);
        DIRECTRELEASE(dds4t2);
    }

    {
        LPDIRECT3DTEXTURE dds7t1 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds7t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t1, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);

        LPDIRECT3DTEXTURE2 dds7t2 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds7t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t2, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t2);
        IsNotEqual((LPVOID)dds7t1, (LPVOID)dds7t2);

        DIRECTRELEASE(dds7t1);
        DIRECTRELEASE(dds7t2);
    }

    DIRECTRELEASE(dds7);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dds3);
    DIRECTRELEASE(dds2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw2CreateSurfaceTexture(LPMODULE module)
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

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsEqual(result, DD_OK);

    {
        LPDIRECT3DTEXTURE dds1t1 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds1t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t1, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);

        LPDIRECT3DTEXTURE2 dds1t2 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds1t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t2, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t2);
        IsNotEqual((LPVOID)dds1t1, (LPVOID)dds1t2);

        DIRECTRELEASE(dds1t1);
        DIRECTRELEASE(dds1t2);
    }

    {
        LPDIRECT3DTEXTURE dds2t1 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds2t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t1, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);

        LPDIRECT3DTEXTURE2 dds2t2 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds2t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t2, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t2);
        IsNotEqual((LPVOID)dds2t1, (LPVOID)dds2t2);

        DIRECTRELEASE(dds2t1);
        DIRECTRELEASE(dds2t2);
    }

    {
        LPDIRECT3DTEXTURE dds3t1 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds3t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t1, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);

        LPDIRECT3DTEXTURE2 dds3t2 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds3t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t2, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t2);
        IsNotEqual((LPVOID)dds3t1, (LPVOID)dds3t2);

        DIRECTRELEASE(dds3t1);
        DIRECTRELEASE(dds3t2);
    }

    {
        LPDIRECT3DTEXTURE dds4t1 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds4t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t1, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);

        LPDIRECT3DTEXTURE2 dds4t2 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds4t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t2, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t2);
        IsNotEqual((LPVOID)dds4t1, (LPVOID)dds4t2);

        DIRECTRELEASE(dds4t1);
        DIRECTRELEASE(dds4t2);
    }

    {
        LPDIRECT3DTEXTURE dds7t1 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds7t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t1, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);

        LPDIRECT3DTEXTURE2 dds7t2 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds7t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t2, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t2);
        IsNotEqual((LPVOID)dds7t1, (LPVOID)dds7t2);

        DIRECTRELEASE(dds7t1);
        DIRECTRELEASE(dds7t2);
    }

    DIRECTRELEASE(dds7);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dds3);
    DIRECTRELEASE(dds2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw4CreateSurfaceTexture(LPMODULE module)
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

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsEqual(result, DD_OK);

    {
        LPDIRECT3DTEXTURE dds1t1 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds1t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t1, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);

        LPDIRECT3DTEXTURE2 dds1t2 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds1t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t2, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t2);
        IsNotEqual((LPVOID)dds1t1, (LPVOID)dds1t2);

        DIRECTRELEASE(dds1t1);
        DIRECTRELEASE(dds1t2);
    }

    {
        LPDIRECT3DTEXTURE dds2t1 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds2t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t1, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);

        LPDIRECT3DTEXTURE2 dds2t2 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds2t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t2, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t2);
        IsNotEqual((LPVOID)dds2t1, (LPVOID)dds2t2);

        DIRECTRELEASE(dds2t1);
        DIRECTRELEASE(dds2t2);
    }

    {
        LPDIRECT3DTEXTURE dds3t1 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds3t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t1, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);

        LPDIRECT3DTEXTURE2 dds3t2 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds3t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t2, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t2);
        IsNotEqual((LPVOID)dds3t1, (LPVOID)dds3t2);

        DIRECTRELEASE(dds3t1);
        DIRECTRELEASE(dds3t2);
    }

    {
        LPDIRECT3DTEXTURE dds4t1 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds4t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t1, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);

        LPDIRECT3DTEXTURE2 dds4t2 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds4t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t2, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t2);
        IsNotEqual((LPVOID)dds4t1, (LPVOID)dds4t2);

        DIRECTRELEASE(dds4t1);
        DIRECTRELEASE(dds4t2);
    }

    {
        LPDIRECT3DTEXTURE dds7t1 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds7t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t1, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);

        LPDIRECT3DTEXTURE2 dds7t2 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds7t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t2, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t2);
        IsNotEqual((LPVOID)dds7t1, (LPVOID)dds7t2);

        DIRECTRELEASE(dds7t1);
        DIRECTRELEASE(dds7t2);
    }

    DIRECTRELEASE(dds7);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dds3);
    DIRECTRELEASE(dds2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw7CreateSurfaceTexture(LPMODULE module)
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

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = dds7->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = dds7->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dds7->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = dds7->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsEqual(result, DD_OK);

    {
        LPDIRECT3DTEXTURE dds1t1 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds1t1);
        IsNotEqual(result, DD_OK);

        LPDIRECT3DTEXTURE2 dds1t2 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds1t2);
        IsNotEqual(result, DD_OK);
    }

    {
        LPDIRECT3DTEXTURE dds2t1 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds2t1);
        IsNotEqual(result, DD_OK);

        LPDIRECT3DTEXTURE2 dds2t2 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds2t2);
        IsNotEqual(result, DD_OK);
    }

    {
        LPDIRECT3DTEXTURE dds3t1 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds3t1);
        IsNotEqual(result, DD_OK);

        LPDIRECT3DTEXTURE2 dds3t2 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds3t2);
        IsNotEqual(result, DD_OK);
    }

    {
        LPDIRECT3DTEXTURE dds4t1 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds4t1);
        IsNotEqual(result, DD_OK);

        LPDIRECT3DTEXTURE2 dds4t2 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds4t2);
        IsNotEqual(result, DD_OK);
    }

    {
        LPDIRECT3DTEXTURE dds7t1 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds7t1);
        IsNotEqual(result, DD_OK);

        LPDIRECT3DTEXTURE2 dds7t2 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds7t2);
        IsNotEqual(result, DD_OK);
    }

    DIRECTRELEASE(dds7);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dds3);
    DIRECTRELEASE(dds2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDrawSurfaceTextureQueryInterfaceIUnknown(LPMODULE module)
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

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsEqual(result, DD_OK);

    {
        LPDIRECT3DTEXTURE dds1t1 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds1t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t1, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);

        LPDIRECT3DTEXTURE2 dds1t2 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds1t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t2, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t2);
        IsNotEqual((LPVOID)dds1t1, (LPVOID)dds1t2);

        {
            LPUNKNOWN unk1 = NULL;
            result = dds1t1->QueryInterface(IID_IUnknown, (LPVOID*)&unk1);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds1t1, (LPVOID)unk1);
            IsEqual((LPVOID)dds1, (LPVOID)unk1);

            LPUNKNOWN unk2 = NULL;
            result = dds1t2->QueryInterface(IID_IUnknown, (LPVOID*)&unk2);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds1t2, (LPVOID)unk2);
            IsEqual((LPVOID)dds1, (LPVOID)unk2);

            DIRECTRELEASE(unk1);
            DIRECTRELEASE(unk2);
        }

        DIRECTRELEASE(dds1t1);
        DIRECTRELEASE(dds1t2);
    }

    {
        LPDIRECT3DTEXTURE dds2t1 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds2t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t1, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);

        LPDIRECT3DTEXTURE2 dds2t2 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds2t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t2, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t2);
        IsNotEqual((LPVOID)dds2t1, (LPVOID)dds2t2);

        {
            LPUNKNOWN unk1 = NULL;
            result = dds2t1->QueryInterface(IID_IUnknown, (LPVOID*)&unk1);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds2t1, (LPVOID)unk1);
            IsEqual((LPVOID)dds1, (LPVOID)unk1);

            LPUNKNOWN unk2 = NULL;
            result = dds2t2->QueryInterface(IID_IUnknown, (LPVOID*)&unk2);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds2t2, (LPVOID)unk2);
            IsEqual((LPVOID)dds1, (LPVOID)unk2);

            DIRECTRELEASE(unk1);
            DIRECTRELEASE(unk2);
        }

        DIRECTRELEASE(dds2t1);
        DIRECTRELEASE(dds2t2);
    }

    {
        LPDIRECT3DTEXTURE dds3t1 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds3t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t1, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);

        LPDIRECT3DTEXTURE2 dds3t2 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds3t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t2, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t2);
        IsNotEqual((LPVOID)dds3t1, (LPVOID)dds3t2);

        {
            LPUNKNOWN unk1 = NULL;
            result = dds3t1->QueryInterface(IID_IUnknown, (LPVOID*)&unk1);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds3t1, (LPVOID)unk1);
            IsEqual((LPVOID)dds1, (LPVOID)unk1);

            LPUNKNOWN unk2 = NULL;
            result = dds3t2->QueryInterface(IID_IUnknown, (LPVOID*)&unk2);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds3t2, (LPVOID)unk2);
            IsEqual((LPVOID)dds1, (LPVOID)unk2);

            DIRECTRELEASE(unk1);
            DIRECTRELEASE(unk2);
        }

        DIRECTRELEASE(dds3t1);
        DIRECTRELEASE(dds3t2);
    }

    {
        LPDIRECT3DTEXTURE dds4t1 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds4t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t1, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);

        LPDIRECT3DTEXTURE2 dds4t2 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds4t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t2, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t2);
        IsNotEqual((LPVOID)dds4t1, (LPVOID)dds4t2);

        {
            LPUNKNOWN unk1 = NULL;
            result = dds4t1->QueryInterface(IID_IUnknown, (LPVOID*)&unk1);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds4t1, (LPVOID)unk1);
            IsEqual((LPVOID)dds1, (LPVOID)unk1);

            LPUNKNOWN unk2 = NULL;
            result = dds4t2->QueryInterface(IID_IUnknown, (LPVOID*)&unk2);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds4t2, (LPVOID)unk2);
            IsEqual((LPVOID)dds1, (LPVOID)unk2);

            DIRECTRELEASE(unk1);
            DIRECTRELEASE(unk2);
        }

        DIRECTRELEASE(dds4t1);
        DIRECTRELEASE(dds4t2);
    }

    {
        LPDIRECT3DTEXTURE dds7t1 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds7t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t1, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);

        LPDIRECT3DTEXTURE2 dds7t2 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds7t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t2, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t2);
        IsNotEqual((LPVOID)dds7t1, (LPVOID)dds7t2);

        {
            LPUNKNOWN unk1 = NULL;
            result = dds7t1->QueryInterface(IID_IUnknown, (LPVOID*)&unk1);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds7t1, (LPVOID)unk1);
            IsEqual((LPVOID)dds1, (LPVOID)unk1);

            LPUNKNOWN unk2 = NULL;
            result = dds7t2->QueryInterface(IID_IUnknown, (LPVOID*)&unk2);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds7t2, (LPVOID)unk2);
            IsEqual((LPVOID)dds1, (LPVOID)unk2);

            DIRECTRELEASE(unk1);
            DIRECTRELEASE(unk2);
        }

        DIRECTRELEASE(dds7t1);
        DIRECTRELEASE(dds7t2);
    }

    DIRECTRELEASE(dds7);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dds3);
    DIRECTRELEASE(dds2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw2SurfaceTextureQueryInterfaceIUnknown(LPMODULE module)
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

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsEqual(result, DD_OK);

    {
        LPDIRECT3DTEXTURE dds1t1 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds1t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t1, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);

        LPDIRECT3DTEXTURE2 dds1t2 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds1t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t2, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t2);
        IsNotEqual((LPVOID)dds1t1, (LPVOID)dds1t2);

        {
            LPUNKNOWN unk1 = NULL;
            result = dds1t1->QueryInterface(IID_IUnknown, (LPVOID*)&unk1);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds1t1, (LPVOID)unk1);
            IsEqual((LPVOID)dds1, (LPVOID)unk1);

            LPUNKNOWN unk2 = NULL;
            result = dds1t2->QueryInterface(IID_IUnknown, (LPVOID*)&unk2);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds1t2, (LPVOID)unk2);
            IsEqual((LPVOID)dds1, (LPVOID)unk2);

            DIRECTRELEASE(unk1);
            DIRECTRELEASE(unk2);
        }

        DIRECTRELEASE(dds1t1);
        DIRECTRELEASE(dds1t2);
    }

    {
        LPDIRECT3DTEXTURE dds2t1 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds2t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t1, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);

        LPDIRECT3DTEXTURE2 dds2t2 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds2t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t2, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t2);
        IsNotEqual((LPVOID)dds2t1, (LPVOID)dds2t2);

        {
            LPUNKNOWN unk1 = NULL;
            result = dds2t1->QueryInterface(IID_IUnknown, (LPVOID*)&unk1);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds2t1, (LPVOID)unk1);
            IsEqual((LPVOID)dds1, (LPVOID)unk1);

            LPUNKNOWN unk2 = NULL;
            result = dds2t2->QueryInterface(IID_IUnknown, (LPVOID*)&unk2);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds2t2, (LPVOID)unk2);
            IsEqual((LPVOID)dds1, (LPVOID)unk2);

            DIRECTRELEASE(unk1);
            DIRECTRELEASE(unk2);
        }

        DIRECTRELEASE(dds2t1);
        DIRECTRELEASE(dds2t2);
    }

    {
        LPDIRECT3DTEXTURE dds3t1 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds3t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t1, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);

        LPDIRECT3DTEXTURE2 dds3t2 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds3t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t2, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t2);
        IsNotEqual((LPVOID)dds3t1, (LPVOID)dds3t2);

        {
            LPUNKNOWN unk1 = NULL;
            result = dds3t1->QueryInterface(IID_IUnknown, (LPVOID*)&unk1);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds3t1, (LPVOID)unk1);
            IsEqual((LPVOID)dds1, (LPVOID)unk1);

            LPUNKNOWN unk2 = NULL;
            result = dds3t2->QueryInterface(IID_IUnknown, (LPVOID*)&unk2);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds3t2, (LPVOID)unk2);
            IsEqual((LPVOID)dds1, (LPVOID)unk2);

            DIRECTRELEASE(unk1);
            DIRECTRELEASE(unk2);
        }

        DIRECTRELEASE(dds3t1);
        DIRECTRELEASE(dds3t2);
    }

    {
        LPDIRECT3DTEXTURE dds4t1 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds4t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t1, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);

        LPDIRECT3DTEXTURE2 dds4t2 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds4t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t2, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t2);
        IsNotEqual((LPVOID)dds4t1, (LPVOID)dds4t2);

        {
            LPUNKNOWN unk1 = NULL;
            result = dds4t1->QueryInterface(IID_IUnknown, (LPVOID*)&unk1);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds4t1, (LPVOID)unk1);
            IsEqual((LPVOID)dds1, (LPVOID)unk1);

            LPUNKNOWN unk2 = NULL;
            result = dds4t2->QueryInterface(IID_IUnknown, (LPVOID*)&unk2);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds4t2, (LPVOID)unk2);
            IsEqual((LPVOID)dds1, (LPVOID)unk2);

            DIRECTRELEASE(unk1);
            DIRECTRELEASE(unk2);
        }

        DIRECTRELEASE(dds4t1);
        DIRECTRELEASE(dds4t2);
    }

    {
        LPDIRECT3DTEXTURE dds7t1 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds7t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t1, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);

        LPDIRECT3DTEXTURE2 dds7t2 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds7t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t2, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t2);
        IsNotEqual((LPVOID)dds7t1, (LPVOID)dds7t2);

        {
            LPUNKNOWN unk1 = NULL;
            result = dds7t1->QueryInterface(IID_IUnknown, (LPVOID*)&unk1);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds7t1, (LPVOID)unk1);
            IsEqual((LPVOID)dds1, (LPVOID)unk1);

            LPUNKNOWN unk2 = NULL;
            result = dds7t2->QueryInterface(IID_IUnknown, (LPVOID*)&unk2);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds7t2, (LPVOID)unk2);
            IsEqual((LPVOID)dds1, (LPVOID)unk2);

            DIRECTRELEASE(unk1);
            DIRECTRELEASE(unk2);
        }

        DIRECTRELEASE(dds7t1);
        DIRECTRELEASE(dds7t2);
    }

    DIRECTRELEASE(dds7);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dds3);
    DIRECTRELEASE(dds2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw4SurfaceTextureQueryInterfaceIUnknown(LPMODULE module)
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

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsEqual(result, DD_OK);

    {
        LPDIRECT3DTEXTURE dds1t1 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds1t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t1, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);

        LPDIRECT3DTEXTURE2 dds1t2 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds1t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t2, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t2);
        IsNotEqual((LPVOID)dds1t1, (LPVOID)dds1t2);

        {
            LPUNKNOWN unk1 = NULL;
            result = dds1t1->QueryInterface(IID_IUnknown, (LPVOID*)&unk1);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds1t1, (LPVOID)unk1);
            IsEqual((LPVOID)dds1, (LPVOID)unk1);

            LPUNKNOWN unk2 = NULL;
            result = dds1t2->QueryInterface(IID_IUnknown, (LPVOID*)&unk2);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds1t2, (LPVOID)unk2);
            IsEqual((LPVOID)dds1, (LPVOID)unk2);

            DIRECTRELEASE(unk1);
            DIRECTRELEASE(unk2);
        }

        DIRECTRELEASE(dds1t1);
        DIRECTRELEASE(dds1t2);
    }

    {
        LPDIRECT3DTEXTURE dds2t1 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds2t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t1, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);

        LPDIRECT3DTEXTURE2 dds2t2 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds2t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t2, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t2);
        IsNotEqual((LPVOID)dds2t1, (LPVOID)dds2t2);

        {
            LPUNKNOWN unk1 = NULL;
            result = dds2t1->QueryInterface(IID_IUnknown, (LPVOID*)&unk1);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds2t1, (LPVOID)unk1);
            IsEqual((LPVOID)dds1, (LPVOID)unk1);

            LPUNKNOWN unk2 = NULL;
            result = dds2t2->QueryInterface(IID_IUnknown, (LPVOID*)&unk2);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds2t2, (LPVOID)unk2);
            IsEqual((LPVOID)dds1, (LPVOID)unk2);

            DIRECTRELEASE(unk1);
            DIRECTRELEASE(unk2);
        }

        DIRECTRELEASE(dds2t1);
        DIRECTRELEASE(dds2t2);
    }

    {
        LPDIRECT3DTEXTURE dds3t1 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds3t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t1, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);

        LPDIRECT3DTEXTURE2 dds3t2 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds3t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t2, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t2);
        IsNotEqual((LPVOID)dds3t1, (LPVOID)dds3t2);

        {
            LPUNKNOWN unk1 = NULL;
            result = dds3t1->QueryInterface(IID_IUnknown, (LPVOID*)&unk1);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds3t1, (LPVOID)unk1);
            IsEqual((LPVOID)dds1, (LPVOID)unk1);

            LPUNKNOWN unk2 = NULL;
            result = dds3t2->QueryInterface(IID_IUnknown, (LPVOID*)&unk2);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds3t2, (LPVOID)unk2);
            IsEqual((LPVOID)dds1, (LPVOID)unk2);

            DIRECTRELEASE(unk1);
            DIRECTRELEASE(unk2);
        }

        DIRECTRELEASE(dds3t1);
        DIRECTRELEASE(dds3t2);
    }

    {
        LPDIRECT3DTEXTURE dds4t1 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds4t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t1, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);

        LPDIRECT3DTEXTURE2 dds4t2 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds4t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t2, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t2);
        IsNotEqual((LPVOID)dds4t1, (LPVOID)dds4t2);

        {
            LPUNKNOWN unk1 = NULL;
            result = dds4t1->QueryInterface(IID_IUnknown, (LPVOID*)&unk1);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds4t1, (LPVOID)unk1);
            IsEqual((LPVOID)dds1, (LPVOID)unk1);

            LPUNKNOWN unk2 = NULL;
            result = dds4t2->QueryInterface(IID_IUnknown, (LPVOID*)&unk2);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds4t2, (LPVOID)unk2);
            IsEqual((LPVOID)dds1, (LPVOID)unk2);

            DIRECTRELEASE(unk1);
            DIRECTRELEASE(unk2);
        }

        DIRECTRELEASE(dds4t1);
        DIRECTRELEASE(dds4t2);
    }

    {
        LPDIRECT3DTEXTURE dds7t1 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds7t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t1, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);

        LPDIRECT3DTEXTURE2 dds7t2 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds7t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t2, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t2);
        IsNotEqual((LPVOID)dds7t1, (LPVOID)dds7t2);

        {
            LPUNKNOWN unk1 = NULL;
            result = dds7t1->QueryInterface(IID_IUnknown, (LPVOID*)&unk1);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds7t1, (LPVOID)unk1);
            IsEqual((LPVOID)dds1, (LPVOID)unk1);

            LPUNKNOWN unk2 = NULL;
            result = dds7t2->QueryInterface(IID_IUnknown, (LPVOID*)&unk2);
            IsEqual(result, DD_OK);
            IsNotEqual((LPVOID)dds7t2, (LPVOID)unk2);
            IsEqual((LPVOID)dds1, (LPVOID)unk2);

            DIRECTRELEASE(unk1);
            DIRECTRELEASE(unk2);
        }

        DIRECTRELEASE(dds7t1);
        DIRECTRELEASE(dds7t2);
    }

    DIRECTRELEASE(dds7);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dds3);
    DIRECTRELEASE(dds2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDrawSurfaceTextureQuery(LPDIRECT3DTEXTURE tex)
{
    /* Direct3D */

    LPDIRECT3D dd3d1 = NULL;
    HRESULT result = tex->QueryInterface(IID_IDirect3D, (LPVOID*)&dd3d1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d1, NULL);

    LPDIRECT3D2 dd3d2 = NULL;
    result = tex->QueryInterface(IID_IDirect3D2, (LPVOID*)&dd3d2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d2, NULL);

    LPDIRECT3D3 dd3d3 = NULL;
    result = tex->QueryInterface(IID_IDirect3D3, (LPVOID*)&dd3d3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d3, NULL);

    LPDIRECT3D3 dd3d7 = NULL;
    result = tex->QueryInterface(IID_IDirect3D7, (LPVOID*)&dd3d7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d7, NULL);

    /* Direct3DDevice */

    LPDIRECT3DDEVICE dd3dd1 = NULL;
    result = tex->QueryInterface(IID_IDirect3DDevice, (LPVOID*)&dd3dd1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    LPDIRECT3DDEVICE2 dd3dd2 = NULL;
    result = tex->QueryInterface(IID_IDirect3DDevice2, (LPVOID*)&dd3dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd2, NULL);

    LPDIRECT3DDEVICE3 dd3dd3 = NULL;
    result = tex->QueryInterface(IID_IDirect3DDevice3, (LPVOID*)&dd3dd3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd3, NULL);

    LPDIRECT3DDEVICE7 dd3dd7 = NULL;
    result = tex->QueryInterface(IID_IDirect3DDevice7, (LPVOID*)&dd3dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd7, NULL);

    LPDIRECT3DDEVICE d3drd = NULL;
    result = tex->QueryInterface(IID_IDirect3DRampDevice, (LPVOID*)&d3drd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drd, NULL);

    LPDIRECT3DDEVICE d3drgbd = NULL;
    result = tex->QueryInterface(IID_IDirect3DRGBDevice, (LPVOID*)&d3drgbd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drgbd, NULL);

    LPDIRECT3DDEVICE d3dhald = NULL;
    result = tex->QueryInterface(IID_IDirect3DHALDevice, (LPVOID*)&d3dhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dhald, NULL);

    LPDIRECT3DDEVICE d3dmmxd = NULL;
    result = tex->QueryInterface(IID_IDirect3DMMXDevice, (LPVOID*)&d3dmmxd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dmmxd, NULL);

    LPDIRECT3DDEVICE d3drefd = NULL;
    result = tex->QueryInterface(IID_IDirect3DRefDevice, (LPVOID*)&d3drefd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drefd, NULL);

    LPDIRECT3DDEVICE d3dnd = NULL;
    result = tex->QueryInterface(IID_IDirect3DNullDevice, (LPVOID*)&d3dnd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dnd, NULL);

    LPDIRECT3DDEVICE d3dtnlhald = NULL;
    result = tex->QueryInterface(IID_IDirect3DTnLHalDevice, (LPVOID*)&d3dtnlhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dtnlhald, NULL);

    /* Direct3DExecuteBuffer */

    LPDIRECT3DEXECUTEBUFFER d3deb = NULL;
    result = tex->QueryInterface(IID_IDirect3DExecuteBuffer, (LPVOID*)&d3deb);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    /* Direct3DLight */
    LPDIRECT3DLIGHT d3dl = NULL;
    result = tex->QueryInterface(IID_IDirect3DLight, (LPVOID*)&d3dl);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dl, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dm1 = NULL;
    result = tex->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dm1);
    IsNotEqual(result, DD_OK);

    LPDIRECT3DMATERIAL2 d3dm2 = NULL;
    result = tex->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dm2);
    IsNotEqual(result, DD_OK);

    LPDIRECT3DMATERIAL3 d3dm3 = NULL;
    result = tex->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dm3);
    IsNotEqual(result, DD_OK);

    /* Direct3DTexture */

    LPDIRECT3DTEXTURE d3dt1 = NULL;
    result = tex->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&d3dt1);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dt1, NULL);
    IsEqual(d3dt1, tex);
    DIRECTRELEASE(d3dt1);

    LPDIRECT3DTEXTURE2 d3dt2 = NULL;
    result = tex->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&d3dt2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dt2, NULL);
    IsNotEqual((LPVOID)d3dt2, tex);
    DIRECTRELEASE(d3dt2);

    /* Direct3DVertexBuffer */

    LPDIRECT3DVERTEXBUFFER d3dvb1 = NULL;
    result = tex->QueryInterface(IID_IDirect3DVertexBuffer, (LPVOID*)&d3dvb1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb1, NULL);

    LPDIRECT3DVERTEXBUFFER7 d3dvb7 = NULL;
    result = tex->QueryInterface(IID_IDirect3DVertexBuffer7, (LPVOID*)&d3dvb7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb7, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dmat1 = NULL;
    result = tex->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dmat1);
    IsNotEqual(result, DD_OK);

    LPDIRECT3DMATERIAL2 d3dmat2 = NULL;
    result = tex->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dmat2);
    IsNotEqual(result, DD_OK);

    LPDIRECT3DMATERIAL3 d3dmat3 = NULL;
    result = tex->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dmat3);
    IsNotEqual(result, DD_OK);

    /* DirectDraw */

    LPDIRECTDRAW dd = NULL;
    result = tex->QueryInterface(IID_IDirectDraw, (LPVOID*)&dd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd, NULL);

    LPDIRECTDRAW2 dd2 = NULL;
    result = tex->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd2, NULL);

    LPDIRECTDRAW4 dd4 = NULL;
    result = tex->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd4, NULL);

    LPDIRECTDRAW7 dd7 = NULL;
    result = tex->QueryInterface(IID_IDirectDraw7, (LPVOID*)&dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd7, NULL);

    /* DirectDrawClipper */

    LPDIRECTDRAWCLIPPER ddc = NULL;
    result = tex->QueryInterface(IID_IDirectDrawClipper, (LPVOID*)&ddc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddc, NULL);

    /* DirectDrawColorControl */

    LPDIRECTDRAWCOLORCONTROL ddcc = NULL;
    result = tex->QueryInterface(IID_IDirectDrawColorControl, (LPVOID*)&ddcc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddcc, NULL);

    /* DirectDrawGammaControl */

    LPDIRECTDRAWGAMMACONTROL ddgc = NULL;
    result = tex->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&ddgc);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)ddgc, NULL);
    IsNotEqual((LPVOID)ddgc, tex);
    DIRECTRELEASE(ddgc);

    /* DirectDrawPalette */

    LPDIRECTDRAWPALETTE ddp = NULL;
    result = tex->QueryInterface(IID_IDirectDrawPalette, (LPVOID*)&ddp);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddp, NULL);

    /* DirectDrawSurface */

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = tex->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)dds1, NULL);
    IsNotEqual((LPVOID)dds1, tex);
    DIRECTRELEASE(dds1);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = tex->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)dds2, NULL);
    IsNotEqual((LPVOID)dds2, tex);
    DIRECTRELEASE(dds2);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = tex->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)dds3, NULL);
    IsNotEqual((LPVOID)dds3, tex);
    DIRECTRELEASE(dds3);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = tex->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)dds4, NULL);
    IsNotEqual((LPVOID)dds4, tex);
    DIRECTRELEASE(dds4);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = tex->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)dds7, NULL);
    IsNotEqual((LPVOID)dds7, tex);
    DIRECTRELEASE(dds7);

    /* DirectDrawVideoPort */
    LPDIRECTDRAWVIDEOPORT ddtex = NULL;
    result = tex->QueryInterface(IID_IDirectDrawVideoPort, (LPVOID*)&ddtex);
    IsNotEqual(result, DD_OK);
    IsEqual(ddtex, NULL);

    /* DirectDrawVideoPortContainer */

    LPDDVIDEOPORTCONTAINER ddtexc = NULL;
    result = tex->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&ddtexc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddtexc, NULL);

    /* DirectDrawVideoPortNotify */

    LPDDVIDEOPORTNOTIFY ddtexn = NULL;
    result = tex->QueryInterface(IID_IDirectDrawVideoPortNotify, (LPVOID*)&ddtexn);
    IsNotEqual(result, DD_OK);

    /* Unknown */

    LPUNKNOWN unk = NULL;
    result = tex->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);
    IsNotEqual(tex, unk);
    DIRECTRELEASE(unk);
}

VOID DirectDrawSurfaceTextureQuery(LPDIRECT3DTEXTURE2 tex)
{
    /* Direct3D */

    LPDIRECT3D dd3d1 = NULL;
    HRESULT result = tex->QueryInterface(IID_IDirect3D, (LPVOID*)&dd3d1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d1, NULL);

    LPDIRECT3D2 dd3d2 = NULL;
    result = tex->QueryInterface(IID_IDirect3D2, (LPVOID*)&dd3d2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d2, NULL);

    LPDIRECT3D3 dd3d3 = NULL;
    result = tex->QueryInterface(IID_IDirect3D3, (LPVOID*)&dd3d3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d3, NULL);

    LPDIRECT3D3 dd3d7 = NULL;
    result = tex->QueryInterface(IID_IDirect3D7, (LPVOID*)&dd3d7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d7, NULL);

    /* Direct3DDevice */

    LPDIRECT3DDEVICE dd3dd1 = NULL;
    result = tex->QueryInterface(IID_IDirect3DDevice, (LPVOID*)&dd3dd1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    LPDIRECT3DDEVICE2 dd3dd2 = NULL;
    result = tex->QueryInterface(IID_IDirect3DDevice2, (LPVOID*)&dd3dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd2, NULL);

    LPDIRECT3DDEVICE3 dd3dd3 = NULL;
    result = tex->QueryInterface(IID_IDirect3DDevice3, (LPVOID*)&dd3dd3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd3, NULL);

    LPDIRECT3DDEVICE7 dd3dd7 = NULL;
    result = tex->QueryInterface(IID_IDirect3DDevice7, (LPVOID*)&dd3dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd7, NULL);

    LPDIRECT3DDEVICE d3drd = NULL;
    result = tex->QueryInterface(IID_IDirect3DRampDevice, (LPVOID*)&d3drd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drd, NULL);

    LPDIRECT3DDEVICE d3drgbd = NULL;
    result = tex->QueryInterface(IID_IDirect3DRGBDevice, (LPVOID*)&d3drgbd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drgbd, NULL);

    LPDIRECT3DDEVICE d3dhald = NULL;
    result = tex->QueryInterface(IID_IDirect3DHALDevice, (LPVOID*)&d3dhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dhald, NULL);

    LPDIRECT3DDEVICE d3dmmxd = NULL;
    result = tex->QueryInterface(IID_IDirect3DMMXDevice, (LPVOID*)&d3dmmxd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dmmxd, NULL);

    LPDIRECT3DDEVICE d3drefd = NULL;
    result = tex->QueryInterface(IID_IDirect3DRefDevice, (LPVOID*)&d3drefd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drefd, NULL);

    LPDIRECT3DDEVICE d3dnd = NULL;
    result = tex->QueryInterface(IID_IDirect3DNullDevice, (LPVOID*)&d3dnd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dnd, NULL);

    LPDIRECT3DDEVICE d3dtnlhald = NULL;
    result = tex->QueryInterface(IID_IDirect3DTnLHalDevice, (LPVOID*)&d3dtnlhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dtnlhald, NULL);

    /* Direct3DExecuteBuffer */

    LPDIRECT3DEXECUTEBUFFER d3deb = NULL;
    result = tex->QueryInterface(IID_IDirect3DExecuteBuffer, (LPVOID*)&d3deb);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    /* Direct3DLight */
    LPDIRECT3DLIGHT d3dl = NULL;
    result = tex->QueryInterface(IID_IDirect3DLight, (LPVOID*)&d3dl);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dl, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dm1 = NULL;
    result = tex->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dm1);
    IsNotEqual(result, DD_OK);

    LPDIRECT3DMATERIAL2 d3dm2 = NULL;
    result = tex->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dm2);
    IsNotEqual(result, DD_OK);

    LPDIRECT3DMATERIAL3 d3dm3 = NULL;
    result = tex->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dm3);
    IsNotEqual(result, DD_OK);

    /* Direct3DTexture */

    LPDIRECT3DTEXTURE d3dt1 = NULL;
    result = tex->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&d3dt1);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dt1, NULL);
    IsNotEqual((LPVOID)d3dt1, tex);
    DIRECTRELEASE(d3dt1);

    LPDIRECT3DTEXTURE2 d3dt2 = NULL;
    result = tex->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&d3dt2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dt2, NULL);
    IsEqual((LPVOID)d3dt2, tex);
    DIRECTRELEASE(d3dt2);

    /* Direct3DVertexBuffer */

    LPDIRECT3DVERTEXBUFFER d3dvb1 = NULL;
    result = tex->QueryInterface(IID_IDirect3DVertexBuffer, (LPVOID*)&d3dvb1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb1, NULL);

    LPDIRECT3DVERTEXBUFFER7 d3dvb7 = NULL;
    result = tex->QueryInterface(IID_IDirect3DVertexBuffer7, (LPVOID*)&d3dvb7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb7, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dmat1 = NULL;
    result = tex->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dmat1);
    IsNotEqual(result, DD_OK);

    LPDIRECT3DMATERIAL2 d3dmat2 = NULL;
    result = tex->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dmat2);
    IsNotEqual(result, DD_OK);

    LPDIRECT3DMATERIAL3 d3dmat3 = NULL;
    result = tex->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dmat3);
    IsNotEqual(result, DD_OK);

    /* DirectDraw */

    LPDIRECTDRAW dd = NULL;
    result = tex->QueryInterface(IID_IDirectDraw, (LPVOID*)&dd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd, NULL);

    LPDIRECTDRAW2 dd2 = NULL;
    result = tex->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd, NULL);

    LPDIRECTDRAW4 dd4 = NULL;
    result = tex->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd, NULL);

    LPDIRECTDRAW7 dd7 = NULL;
    result = tex->QueryInterface(IID_IDirectDraw7, (LPVOID*)&dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd, NULL);

    /* DirectDrawClipper */

    LPDIRECTDRAWCLIPPER ddc = NULL;
    result = tex->QueryInterface(IID_IDirectDrawClipper, (LPVOID*)&ddc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddc, NULL);

    /* DirectDrawColorControl */

    LPDIRECTDRAWCOLORCONTROL ddcc = NULL;
    result = tex->QueryInterface(IID_IDirectDrawColorControl, (LPVOID*)&ddcc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddcc, NULL);

    /* DirectDrawGammaControl */

    LPDIRECTDRAWGAMMACONTROL ddgc = NULL;
    result = tex->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&ddgc);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)ddgc, NULL);
    IsNotEqual((LPVOID)ddgc, tex);
    DIRECTRELEASE(ddgc);

    /* DirectDrawPalette */

    LPDIRECTDRAWPALETTE ddp = NULL;
    result = tex->QueryInterface(IID_IDirectDrawPalette, (LPVOID*)&ddp);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddp, NULL);

    /* DirectDrawSurface */

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = tex->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)dds1, NULL);
    IsNotEqual((LPVOID)dds1, tex);
    DIRECTRELEASE(dds1);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = tex->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)dds2, NULL);
    IsNotEqual((LPVOID)dds2, tex);
    DIRECTRELEASE(dds2);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = tex->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)dds3, NULL);
    IsNotEqual((LPVOID)dds3, tex);
    DIRECTRELEASE(dds3);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = tex->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)dds4, NULL);
    IsNotEqual((LPVOID)dds4, tex);
    DIRECTRELEASE(dds4);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = tex->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)dds7, NULL);
    IsNotEqual((LPVOID)dds7, tex);
    DIRECTRELEASE(dds7);

    /* DirectDrawVideoPort */
    LPDIRECTDRAWVIDEOPORT ddtex = NULL;
    result = tex->QueryInterface(IID_IDirectDrawVideoPort, (LPVOID*)&ddtex);
    IsNotEqual(result, DD_OK);
    IsEqual(ddtex, NULL);

    /* DirectDrawVideoPortContainer */

    LPDDVIDEOPORTCONTAINER ddtexc = NULL;
    result = tex->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&ddtexc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddtexc, NULL);

    /* DirectDrawVideoPortNotify */

    LPDDVIDEOPORTNOTIFY ddtexn = NULL;
    result = tex->QueryInterface(IID_IDirectDrawVideoPortNotify, (LPVOID*)&ddtexn);
    IsNotEqual(result, DD_OK);

    /* Unknown */

    LPUNKNOWN unk = NULL;
    result = tex->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);
    IsNotEqual(tex, unk);
    DIRECTRELEASE(unk);
}

VOID DirectDrawSurfaceTextureQueryInterfaceAll(LPMODULE module)
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

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsEqual(result, DD_OK);

    {
        LPDIRECT3DTEXTURE dds1t1 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds1t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t1, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);

        LPDIRECT3DTEXTURE2 dds1t2 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds1t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t2, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t2);
        IsNotEqual((LPVOID)dds1t1, (LPVOID)dds1t2);

        DirectDrawSurfaceTextureQuery(dds1t1);
        DirectDrawSurfaceTextureQuery(dds1t2);

        DIRECTRELEASE(dds1t1);
        DIRECTRELEASE(dds1t2);
    }

    {
        LPDIRECT3DTEXTURE dds2t1 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds2t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t1, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);

        LPDIRECT3DTEXTURE2 dds2t2 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds2t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t2, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t2);
        IsNotEqual((LPVOID)dds2t1, (LPVOID)dds2t2);

        DirectDrawSurfaceTextureQuery(dds2t1);
        DirectDrawSurfaceTextureQuery(dds2t2);

        DIRECTRELEASE(dds2t1);
        DIRECTRELEASE(dds2t2);
    }

    {
        LPDIRECT3DTEXTURE dds3t1 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds3t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t1, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);

        LPDIRECT3DTEXTURE2 dds3t2 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds3t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t2, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t2);
        IsNotEqual((LPVOID)dds3t1, (LPVOID)dds3t2);

        DirectDrawSurfaceTextureQuery(dds3t1);
        DirectDrawSurfaceTextureQuery(dds3t2);

        DIRECTRELEASE(dds3t1);
        DIRECTRELEASE(dds3t2);
    }

    {
        LPDIRECT3DTEXTURE dds4t1 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds4t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t1, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);

        LPDIRECT3DTEXTURE2 dds4t2 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds4t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t2, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t2);
        IsNotEqual((LPVOID)dds4t1, (LPVOID)dds4t2);

        DirectDrawSurfaceTextureQuery(dds4t1);
        DirectDrawSurfaceTextureQuery(dds4t2);

        DIRECTRELEASE(dds4t1);
        DIRECTRELEASE(dds4t2);
    }

    {
        LPDIRECT3DTEXTURE dds7t1 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds7t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t1, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);

        LPDIRECT3DTEXTURE2 dds7t2 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds7t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t2, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t2);
        IsNotEqual((LPVOID)dds7t1, (LPVOID)dds7t2);

        DirectDrawSurfaceTextureQuery(dds7t1);
        DirectDrawSurfaceTextureQuery(dds7t2);

        DIRECTRELEASE(dds7t1);
        DIRECTRELEASE(dds7t2);
    }

    DIRECTRELEASE(dds7);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dds3);
    DIRECTRELEASE(dds2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw2SurfaceTextureQueryInterfaceAll(LPMODULE module)
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

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = dds1->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsEqual(result, DD_OK);

    {
        LPDIRECT3DTEXTURE dds1t1 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds1t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t1, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);

        LPDIRECT3DTEXTURE2 dds1t2 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds1t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t2, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t2);
        IsNotEqual((LPVOID)dds1t1, (LPVOID)dds1t2);

        DirectDrawSurfaceTextureQuery(dds1t1);
        DirectDrawSurfaceTextureQuery(dds1t2);

        DIRECTRELEASE(dds1t1);
        DIRECTRELEASE(dds1t2);
    }

    {
        LPDIRECT3DTEXTURE dds2t1 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds2t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t1, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);

        LPDIRECT3DTEXTURE2 dds2t2 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds2t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t2, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t2);
        IsNotEqual((LPVOID)dds2t1, (LPVOID)dds2t2);

        DirectDrawSurfaceTextureQuery(dds2t1);
        DirectDrawSurfaceTextureQuery(dds2t2);

        DIRECTRELEASE(dds2t1);
        DIRECTRELEASE(dds2t2);
    }

    {
        LPDIRECT3DTEXTURE dds3t1 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds3t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t1, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);

        LPDIRECT3DTEXTURE2 dds3t2 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds3t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t2, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t2);
        IsNotEqual((LPVOID)dds3t1, (LPVOID)dds3t2);

        DirectDrawSurfaceTextureQuery(dds3t1);
        DirectDrawSurfaceTextureQuery(dds3t2);

        DIRECTRELEASE(dds3t1);
        DIRECTRELEASE(dds3t2);
    }

    {
        LPDIRECT3DTEXTURE dds4t1 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds4t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t1, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);

        LPDIRECT3DTEXTURE2 dds4t2 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds4t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t2, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t2);
        IsNotEqual((LPVOID)dds4t1, (LPVOID)dds4t2);

        DirectDrawSurfaceTextureQuery(dds4t1);
        DirectDrawSurfaceTextureQuery(dds4t2);

        DIRECTRELEASE(dds4t1);
        DIRECTRELEASE(dds4t2);
    }

    {
        LPDIRECT3DTEXTURE dds7t1 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds7t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t1, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);

        LPDIRECT3DTEXTURE2 dds7t2 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds7t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t2, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t2);
        IsNotEqual((LPVOID)dds7t1, (LPVOID)dds7t2);

        DirectDrawSurfaceTextureQuery(dds7t1);
        DirectDrawSurfaceTextureQuery(dds7t2);

        DIRECTRELEASE(dds7t1);
        DIRECTRELEASE(dds7t2);
    }

    DIRECTRELEASE(dds7);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dds3);
    DIRECTRELEASE(dds2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw4SurfaceTextureQueryInterfaceAll(LPMODULE module)
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

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsEqual(result, DD_OK);

    {
        LPDIRECT3DTEXTURE dds1t1 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds1t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t1, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);

        LPDIRECT3DTEXTURE2 dds1t2 = NULL;
        result = dds1->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds1t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds1t2, NULL);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t1);
        IsNotEqual((LPVOID)dds1, (LPVOID)dds1t2);
        IsNotEqual((LPVOID)dds1t1, (LPVOID)dds1t2);

        DirectDrawSurfaceTextureQuery(dds1t1);
        DirectDrawSurfaceTextureQuery(dds1t2);

        DIRECTRELEASE(dds1t1);
        DIRECTRELEASE(dds1t2);
    }

    {
        LPDIRECT3DTEXTURE dds2t1 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds2t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t1, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);

        LPDIRECT3DTEXTURE2 dds2t2 = NULL;
        result = dds2->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds2t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds2t2, NULL);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t1);
        IsNotEqual((LPVOID)dds2, (LPVOID)dds2t2);
        IsNotEqual((LPVOID)dds2t1, (LPVOID)dds2t2);

        DirectDrawSurfaceTextureQuery(dds2t1);
        DirectDrawSurfaceTextureQuery(dds2t2);

        DIRECTRELEASE(dds2t1);
        DIRECTRELEASE(dds2t2);
    }

    {
        LPDIRECT3DTEXTURE dds3t1 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds3t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t1, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);

        LPDIRECT3DTEXTURE2 dds3t2 = NULL;
        result = dds3->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds3t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds3t2, NULL);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t1);
        IsNotEqual((LPVOID)dds3, (LPVOID)dds3t2);
        IsNotEqual((LPVOID)dds3t1, (LPVOID)dds3t2);

        DirectDrawSurfaceTextureQuery(dds3t1);
        DirectDrawSurfaceTextureQuery(dds3t2);

        DIRECTRELEASE(dds3t1);
        DIRECTRELEASE(dds3t2);
    }

    {
        LPDIRECT3DTEXTURE dds4t1 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds4t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t1, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);

        LPDIRECT3DTEXTURE2 dds4t2 = NULL;
        result = dds4->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds4t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds4t2, NULL);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t1);
        IsNotEqual((LPVOID)dds4, (LPVOID)dds4t2);
        IsNotEqual((LPVOID)dds4t1, (LPVOID)dds4t2);

        DirectDrawSurfaceTextureQuery(dds4t1);
        DirectDrawSurfaceTextureQuery(dds4t2);

        DIRECTRELEASE(dds4t1);
        DIRECTRELEASE(dds4t2);
    }

    {
        LPDIRECT3DTEXTURE dds7t1 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&dds7t1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t1, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);

        LPDIRECT3DTEXTURE2 dds7t2 = NULL;
        result = dds7->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&dds7t2);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)dds7t2, NULL);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t1);
        IsNotEqual((LPVOID)dds7, (LPVOID)dds7t2);
        IsNotEqual((LPVOID)dds7t1, (LPVOID)dds7t2);

        DirectDrawSurfaceTextureQuery(dds7t1);
        DirectDrawSurfaceTextureQuery(dds7t2);

        DIRECTRELEASE(dds7t1);
        DIRECTRELEASE(dds7t2);
    }

    DIRECTRELEASE(dds7);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dds3);
    DIRECTRELEASE(dds2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}