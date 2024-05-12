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

#include "Direct3DDevice2.hxx"

#include "Window.hxx"

VOID DirectDrawCreateDirect3DDevice2(LPMODULE module)
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
    desc.dwFlags = DDSD_CAPS;

    desc.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_PRIMARYSURFACE;

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dd->CreateSurface(&desc, &dds1, NULL);
    IsEqual(result, DD_OK);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3d2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3d2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3d2);

    LPDIRECT3DDEVICE2 d3dd2 = NULL;
    result = d3d2->CreateDevice(IID_IDirect3DHALDevice, dds1, &d3dd2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3dd2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)d3d2, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3dd2);

    {
        LPDIRECT3DDEVICE d3dd1 = NULL;
        result = d3dd2->QueryInterface(IID_IDirect3DDevice, (LPVOID*)&d3dd1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)d3dd1, NULL);

        IsNotEqual((LPVOID)d3dd2, (LPVOID)d3dd1);

        DIRECTRELEASE(d3dd1);
    }

    {
        LPDIRECT3DDEVICE3 d3dd3 = NULL;
        result = d3dd2->QueryInterface(IID_IDirect3DDevice3, (LPVOID*)&d3dd3);
        IsNotEqual(result, DD_OK);
        IsEqual((LPVOID)d3dd3, NULL);
    }

    {
        LPDIRECT3DDEVICE7 d3dd7 = NULL;
        result = d3dd2->QueryInterface(IID_IDirect3DDevice7, (LPVOID*)&d3dd7);
        IsNotEqual(result, DD_OK);
        IsEqual((LPVOID)d3dd7, NULL);
    }

    DIRECTRELEASE(d3dd2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw2CreateDirect3DDevice2(LPMODULE module)
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
    desc.dwFlags = DDSD_CAPS;

    desc.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_PRIMARYSURFACE;

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dd2->CreateSurface(&desc, &dds1, NULL);
    IsEqual(result, DD_OK);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3d2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3d2);
    IsNotEqual((LPVOID)dd2, (LPVOID)d3d2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3d2);

    LPDIRECT3DDEVICE2 d3dd2 = NULL;
    result = d3d2->CreateDevice(IID_IDirect3DHALDevice, dds1, &d3dd2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3dd2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)dd2, (LPVOID)d3d2);
    IsNotEqual((LPVOID)d3d2, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3dd2);

    {
        LPDIRECT3DDEVICE d3dd1 = NULL;
        result = d3dd2->QueryInterface(IID_IDirect3DDevice, (LPVOID*)&d3dd1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)d3dd1, NULL);

        IsNotEqual((LPVOID)d3dd2, (LPVOID)d3dd1);

        DIRECTRELEASE(d3dd1);
    }

    {
        LPDIRECT3DDEVICE3 d3dd3 = NULL;
        result = d3dd2->QueryInterface(IID_IDirect3DDevice3, (LPVOID*)&d3dd3);
        IsNotEqual(result, DD_OK);
        IsEqual((LPVOID)d3dd3, NULL);
    }

    {
        LPDIRECT3DDEVICE7 d3dd7 = NULL;
        result = d3dd2->QueryInterface(IID_IDirect3DDevice7, (LPVOID*)&d3dd7);
        IsNotEqual(result, DD_OK);
        IsEqual((LPVOID)d3dd7, NULL);
    }

    DIRECTRELEASE(d3dd2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dd2);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw4CreateDirect3DDevice2(LPMODULE module)
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
    desc.dwFlags = DDSD_CAPS;

    desc.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_PRIMARYSURFACE;

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = dd4->CreateSurface(&desc, &dds4, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsEqual(result, DD_OK);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3d2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3d2);
    IsNotEqual((LPVOID)dds4, (LPVOID)d3d2);

    LPDIRECT3DDEVICE2 d3dd2 = NULL;
    result = d3d2->CreateDevice(IID_IDirect3DHALDevice, dds1, &d3dd2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3dd2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3d2);
    IsNotEqual((LPVOID)d3d2, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)dds4, (LPVOID)d3dd2);

    {
        LPDIRECT3DDEVICE d3dd1 = NULL;
        result = d3dd2->QueryInterface(IID_IDirect3DDevice, (LPVOID*)&d3dd1);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)d3dd1, NULL);

        IsNotEqual((LPVOID)d3dd2, (LPVOID)d3dd1);

        DIRECTRELEASE(d3dd1);
    }

    {
        LPDIRECT3DDEVICE3 d3dd3 = NULL;
        result = d3dd2->QueryInterface(IID_IDirect3DDevice3, (LPVOID*)&d3dd3);
        IsNotEqual(result, DD_OK);
        IsEqual((LPVOID)d3dd3, NULL);
    }

    {
        LPDIRECT3DDEVICE7 d3dd7 = NULL;
        result = d3dd2->QueryInterface(IID_IDirect3DDevice7, (LPVOID*)&d3dd7);
        IsNotEqual(result, DD_OK);
        IsEqual((LPVOID)d3dd7, NULL);
    }

    DIRECTRELEASE(dds1);
    DIRECTRELEASE(d3dd2);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dd4);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw7CreateDirect3DDevice2(LPMODULE module)
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
    desc.dwFlags = DDSD_CAPS;

    desc.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_PRIMARYSURFACE;

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = dd7->CreateSurface(&desc, &dds7, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dds7->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsEqual(result, DD_OK);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd7->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3d2, NULL);

    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dds7);
    DIRECTRELEASE(dd7);

    ReleaseWindow(hwnd);
}

VOID DirectDrawCreateDirect3DDevice2QueryInterfaceIUnknown(LPMODULE module)
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
    desc.dwFlags = DDSD_CAPS;

    desc.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_PRIMARYSURFACE;

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dd->CreateSurface(&desc, &dds1, NULL);
    IsEqual(result, DD_OK);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3d2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3d2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3d2);

    LPDIRECT3DDEVICE2 d3dd2 = NULL;
    result = d3d2->CreateDevice(IID_IDirect3DHALDevice, dds1, &d3dd2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3dd2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)d3d2, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3dd2);

    {
        LPUNKNOWN unk = NULL;
        d3dd2->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)unk, NULL);

        DIRECTRELEASE(unk);
    }

    DIRECTRELEASE(d3dd2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw2CreateDirect3DDevice2QueryInterfaceIUnknown(LPMODULE module)
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
    desc.dwFlags = DDSD_CAPS;

    desc.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_PRIMARYSURFACE;

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dd2->CreateSurface(&desc, &dds1, NULL);
    IsEqual(result, DD_OK);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3d2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3d2);
    IsNotEqual((LPVOID)dd2, (LPVOID)d3d2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3d2);

    LPDIRECT3DDEVICE2 d3dd2 = NULL;
    result = d3d2->CreateDevice(IID_IDirect3DHALDevice, dds1, &d3dd2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3dd2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)dd2, (LPVOID)d3d2);
    IsNotEqual((LPVOID)d3d2, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3dd2);

    {
        LPUNKNOWN unk = NULL;
        d3dd2->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)unk, NULL);

        DIRECTRELEASE(unk);
    }

    DIRECTRELEASE(d3dd2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dd2);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw4CreateDirect3DDevice2QueryInterfaceIUnknown(LPMODULE module)
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
    desc.dwFlags = DDSD_CAPS;

    desc.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_PRIMARYSURFACE;

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = dd4->CreateSurface(&desc, &dds4, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsEqual(result, DD_OK);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3d2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3d2);
    IsNotEqual((LPVOID)dds4, (LPVOID)d3d2);

    LPDIRECT3DDEVICE2 d3dd2 = NULL;
    result = d3d2->CreateDevice(IID_IDirect3DHALDevice, dds1, &d3dd2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3dd2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3d2);
    IsNotEqual((LPVOID)d3d2, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)dds4, (LPVOID)d3dd2);

    {
        LPUNKNOWN unk = NULL;
        d3dd2->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)unk, NULL);

        DIRECTRELEASE(unk);
    }

    DIRECTRELEASE(dds1);
    DIRECTRELEASE(d3dd2);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dd4);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDrawCreateDirect3DDevice2Query(LPDIRECT3DDEVICE2 device)
{
    /* Direct3D */

    LPDIRECT3D dd3d1 = NULL;
    HRESULT result = device->QueryInterface(IID_IDirect3D, (LPVOID*)&dd3d1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d1, NULL);

    LPDIRECT3D2 dd3d2 = NULL;
    result = device->QueryInterface(IID_IDirect3D2, (LPVOID*)&dd3d2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d2, NULL);

    LPDIRECT3D3 dd3d3 = NULL;
    result = device->QueryInterface(IID_IDirect3D3, (LPVOID*)&dd3d3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d3, NULL);

    LPDIRECT3D3 dd3d7 = NULL;
    result = device->QueryInterface(IID_IDirect3D7, (LPVOID*)&dd3d7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d7, NULL);

    /* Direct3DDevice */

    LPDIRECT3DDEVICE dd3dd1 = NULL;
    result = device->QueryInterface(IID_IDirect3DDevice, (LPVOID*)&dd3dd1);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)dd3dd1, NULL);
    DIRECTRELEASE(dd3dd1);

    LPDIRECT3DDEVICE2 dd3dd2 = NULL;
    result = device->QueryInterface(IID_IDirect3DDevice2, (LPVOID*)&dd3dd2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)dd3dd2, NULL);
    DIRECTRELEASE(dd3dd2);

    LPDIRECT3DDEVICE3 dd3dd3 = NULL;
    result = device->QueryInterface(IID_IDirect3DDevice3, (LPVOID*)&dd3dd3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd3, NULL);

    LPDIRECT3DDEVICE7 dd3dd7 = NULL;
    result = device->QueryInterface(IID_IDirect3DDevice7, (LPVOID*)&dd3dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd7, NULL);

    LPDIRECT3DDEVICE d3drd = NULL;
    result = device->QueryInterface(IID_IDirect3DRampDevice, (LPVOID*)&d3drd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drd, NULL);

    LPDIRECT3DDEVICE d3drgbd = NULL;
    result = device->QueryInterface(IID_IDirect3DRGBDevice, (LPVOID*)&d3drgbd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drgbd, NULL);

    LPDIRECT3DDEVICE d3dhald = NULL;
    result = device->QueryInterface(IID_IDirect3DHALDevice, (LPVOID*)&d3dhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dhald, NULL);

    LPDIRECT3DDEVICE d3dmmxd = NULL;
    result = device->QueryInterface(IID_IDirect3DMMXDevice, (LPVOID*)&d3dmmxd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dmmxd, NULL);

    LPDIRECT3DDEVICE d3drefd = NULL;
    result = device->QueryInterface(IID_IDirect3DRefDevice, (LPVOID*)&d3drefd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drefd, NULL);

    LPDIRECT3DDEVICE d3dnd = NULL;
    result = device->QueryInterface(IID_IDirect3DNullDevice, (LPVOID*)&d3dnd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dnd, NULL);

    LPDIRECT3DDEVICE d3dtnlhald = NULL;
    result = device->QueryInterface(IID_IDirect3DTnLHalDevice, (LPVOID*)&d3dtnlhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dtnlhald, NULL);

    /* Direct3DExecuteBuffer */

    LPDIRECT3DEXECUTEBUFFER d3deb = NULL;
    result = device->QueryInterface(IID_IDirect3DExecuteBuffer, (LPVOID*)&d3deb);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3deb, NULL);

    /* Direct3DLight */

    LPDIRECT3DLIGHT d3dl = NULL;
    result = device->QueryInterface(IID_IDirect3DLight, (LPVOID*)&d3dl);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dl, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dm1 = NULL;
    result = device->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dm1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm1, NULL);

    LPDIRECT3DMATERIAL2 d3dm2 = NULL;
    result = device->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dm2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm2, NULL);

    LPDIRECT3DMATERIAL3 d3dm3 = NULL;
    result = device->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dm3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm3, NULL);

    /* Direct3DTexture */

    LPDIRECT3DTEXTURE d3dt1 = NULL;
    result = device->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&d3dt1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt1, NULL);

    LPDIRECT3DTEXTURE2 d3dt2 = NULL;
    result = device->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&d3dt2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt2, NULL);

    /* Direct3DVertexBuffer */

    LPDIRECT3DVERTEXBUFFER d3dvb1 = NULL;
    result = device->QueryInterface(IID_IDirect3DVertexBuffer, (LPVOID*)&d3dvb1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb1, NULL);

    LPDIRECT3DVERTEXBUFFER7 d3dvb7 = NULL;
    result = device->QueryInterface(IID_IDirect3DVertexBuffer7, (LPVOID*)&d3dvb7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb7, NULL);

    /* Direct3DViewport */

    LPDIRECT3DVIEWPORT d3dvp1 = NULL;
    result = device->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&d3dvp1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvp1, NULL);

    LPDIRECT3DVIEWPORT2 d3dvp2 = NULL;
    result = device->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&d3dvp2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvp2, NULL);

    LPDIRECT3DVIEWPORT3 d3dvp3 = NULL;
    result = device->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&d3dvp3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvp3, NULL);

    /* DirectDraw */

    LPDIRECTDRAW dd = NULL;
    result = device->QueryInterface(IID_IDirectDraw, (LPVOID*)&dd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd, NULL);

    LPDIRECTDRAW2 dd2 = NULL;
    result = device->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd2, NULL);

    LPDIRECTDRAW4 dd4 = NULL;
    result = device->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd4, NULL);

    LPDIRECTDRAW7 dd7 = NULL;
    result = device->QueryInterface(IID_IDirectDraw7, (LPVOID*)&dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd7, NULL);

    /* DirectDrawClipper */

    LPDIRECTDRAWCLIPPER ddc = NULL;
    result = device->QueryInterface(IID_IDirectDrawClipper, (LPVOID*)&ddc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddc, NULL);

    /* DirectDrawColorControl */

    LPDIRECTDRAWCOLORCONTROL ddcc = NULL;
    result = device->QueryInterface(IID_IDirectDrawColorControl, (LPVOID*)&ddcc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddcc, NULL);

    /* DirectDrawGammaControl */

    LPDIRECTDRAWGAMMACONTROL ddgc = NULL;
    result = device->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&ddgc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddgc, NULL);

    /* DirectDrawPalette */

    LPDIRECTDRAWPALETTE ddp = NULL;
    result = device->QueryInterface(IID_IDirectDrawPalette, (LPVOID*)&ddp);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddp, NULL);

    /* DirectDrawSurface */

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = device->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds1, NULL);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = device->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds2, NULL);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = device->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds3, NULL);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = device->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds4, NULL);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = device->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds7, NULL);

    /* DirectDrawVideoPort */

    LPDIRECTDRAWVIDEOPORT ddvp = NULL;
    result = device->QueryInterface(IID_IDirectDrawVideoPort, (LPVOID*)&ddvp);
    IsNotEqual(result, DD_OK);
    IsEqual(ddvp, NULL);

    /* DirectDrawVideoPortContainer */

    LPDDVIDEOPORTCONTAINER ddvpc = NULL;
    result = device->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&ddvpc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddvpc, NULL);

    /* DirectDrawVideoPortNotify */

    LPDDVIDEOPORTNOTIFY ddvpn = NULL;
    result = device->QueryInterface(IID_IDirectDrawVideoPortNotify, (LPVOID*)&ddvpn);
    IsNotEqual(result, DD_OK);

    /* DirectDrawFactory2 */

    LPUNKNOWN ddf2 = NULL;
    result = device->QueryInterface(IID_IDirectDrawFactory2, (LPVOID*)&ddf2);
    IsNotEqual(result, DD_OK);

    /* IDirectDrawPalette2 */

    LPUNKNOWN ddp2 = NULL;
    result = device->QueryInterface(IID_IDirectDrawPalette2, (LPVOID*)&ddp2);
    IsNotEqual(result, DD_OK);

    /* DirectDrawKernel */

    LPUNKNOWN ddk = NULL;
    result = device->QueryInterface(IID_IDirectDrawKernel, (LPVOID*)&ddk);
    IsNotEqual(result, DD_OK);

    /* DirectDrawOptSurface */

    LPUNKNOWN ddos = NULL;
    result = device->QueryInterface(IID_IDirectDrawOptSurface, (LPVOID*)&ddos);
    IsNotEqual(result, DD_OK);

    /* DirectDrawSurfaceKernel */

    LPUNKNOWN ddsk = NULL;
    result = device->QueryInterface(IID_IDirectDrawSurfaceKernel, (LPVOID*)&ddsk);
    IsNotEqual(result, DD_OK);

    /* DirectDrawSurfaceNew */

    LPUNKNOWN ddsn = NULL;
    result = device->QueryInterface(IID_IDirectDrawOptSurface, (LPVOID*)&ddsn);
    IsNotEqual(result, DD_OK);

    /* Unknown */

    LPUNKNOWN unk = NULL;
    result = device->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);
    IsNotEqual(device, unk);
    DIRECTRELEASE(unk);
}

VOID DirectDrawCreateDirect3DDevice2QueryInterfaceAll(LPMODULE module)
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
    desc.dwFlags = DDSD_CAPS;

    desc.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_PRIMARYSURFACE;

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dd->CreateSurface(&desc, &dds1, NULL);
    IsEqual(result, DD_OK);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3d2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3d2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3d2);

    LPDIRECT3DDEVICE2 d3dd2 = NULL;
    result = d3d2->CreateDevice(IID_IDirect3DHALDevice, dds1, &d3dd2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3dd2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)d3d2, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3dd2);

    DirectDrawCreateDirect3DDevice2Query(d3dd2);

    DIRECTRELEASE(d3dd2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw2CreateDirect3DDevice2QueryInterfaceAll(LPMODULE module)
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
    desc.dwFlags = DDSD_CAPS;

    desc.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_PRIMARYSURFACE;

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dd2->CreateSurface(&desc, &dds1, NULL);
    IsEqual(result, DD_OK);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3d2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3d2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3d2);

    LPDIRECT3DDEVICE2 d3dd2 = NULL;
    result = d3d2->CreateDevice(IID_IDirect3DHALDevice, dds1, &d3dd2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3dd2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)dd2, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)d3d2, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3dd2);

    DirectDrawCreateDirect3DDevice2Query(d3dd2);

    DIRECTRELEASE(d3dd2);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(dd2);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDraw4CreateDirect3DDevice2QueryInterfaceAll(LPMODULE module)
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
    desc.dwFlags = DDSD_CAPS;

    desc.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_PRIMARYSURFACE;

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = dd4->CreateSurface(&desc, &dds4, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dds4->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsEqual(result, DD_OK);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3d2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3d2);
    IsNotEqual((LPVOID)dds4, (LPVOID)d3d2);

    LPDIRECT3DDEVICE2 d3dd2 = NULL;
    result = d3d2->CreateDevice(IID_IDirect3DHALDevice, dds1, &d3dd2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3dd2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3d2);
    IsNotEqual((LPVOID)d3d2, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)dds4, (LPVOID)d3dd2);

    DirectDrawCreateDirect3DDevice2Query(d3dd2);

    DIRECTRELEASE(dds1);
    DIRECTRELEASE(d3dd2);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(dds4);
    DIRECTRELEASE(dd4);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDrawCreateDirect3DDevice2UnknownQuery(LPUNKNOWN device)
{
    /* Direct3D */

    LPDIRECT3D dd3d1 = NULL;
    HRESULT result = device->QueryInterface(IID_IDirect3D, (LPVOID*)&dd3d1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d1, NULL);

    LPDIRECT3D2 dd3d2 = NULL;
    result = device->QueryInterface(IID_IDirect3D2, (LPVOID*)&dd3d2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d2, NULL);

    LPDIRECT3D3 dd3d3 = NULL;
    result = device->QueryInterface(IID_IDirect3D3, (LPVOID*)&dd3d3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d3, NULL);

    LPDIRECT3D3 dd3d7 = NULL;
    result = device->QueryInterface(IID_IDirect3D7, (LPVOID*)&dd3d7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d7, NULL);

    /* Direct3DDevice */

    LPDIRECT3DDEVICE dd3dd1 = NULL;
    result = device->QueryInterface(IID_IDirect3DDevice, (LPVOID*)&dd3dd1);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)dd3dd1, NULL);
    DIRECTRELEASE(dd3dd1);

    LPDIRECT3DDEVICE2 dd3dd2 = NULL;
    result = device->QueryInterface(IID_IDirect3DDevice2, (LPVOID*)&dd3dd2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)dd3dd2, NULL);
    DIRECTRELEASE(dd3dd2);

    LPDIRECT3DDEVICE3 dd3dd3 = NULL;
    result = device->QueryInterface(IID_IDirect3DDevice3, (LPVOID*)&dd3dd3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd3, NULL);

    LPDIRECT3DDEVICE7 dd3dd7 = NULL;
    result = device->QueryInterface(IID_IDirect3DDevice7, (LPVOID*)&dd3dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd7, NULL);

    LPDIRECT3DDEVICE d3drd = NULL;
    result = device->QueryInterface(IID_IDirect3DRampDevice, (LPVOID*)&d3drd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drd, NULL);

    LPDIRECT3DDEVICE d3drgbd = NULL;
    result = device->QueryInterface(IID_IDirect3DRGBDevice, (LPVOID*)&d3drgbd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drgbd, NULL);

    LPDIRECT3DDEVICE d3dhald = NULL;
    result = device->QueryInterface(IID_IDirect3DHALDevice, (LPVOID*)&d3dhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dhald, NULL);

    LPDIRECT3DDEVICE d3dmmxd = NULL;
    result = device->QueryInterface(IID_IDirect3DMMXDevice, (LPVOID*)&d3dmmxd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dmmxd, NULL);

    LPDIRECT3DDEVICE d3drefd = NULL;
    result = device->QueryInterface(IID_IDirect3DRefDevice, (LPVOID*)&d3drefd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drefd, NULL);

    LPDIRECT3DDEVICE d3dnd = NULL;
    result = device->QueryInterface(IID_IDirect3DNullDevice, (LPVOID*)&d3dnd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dnd, NULL);

    LPDIRECT3DDEVICE d3dtnlhald = NULL;
    result = device->QueryInterface(IID_IDirect3DTnLHalDevice, (LPVOID*)&d3dtnlhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dtnlhald, NULL);

    /* Direct3DExecuteBuffer */

    LPDIRECT3DEXECUTEBUFFER d3deb = NULL;
    result = device->QueryInterface(IID_IDirect3DExecuteBuffer, (LPVOID*)&d3deb);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3deb, NULL);

    /* Direct3DLight */

    LPDIRECT3DLIGHT d3dl = NULL;
    result = device->QueryInterface(IID_IDirect3DLight, (LPVOID*)&d3dl);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dl, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dm1 = NULL;
    result = device->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dm1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm1, NULL);

    LPDIRECT3DMATERIAL2 d3dm2 = NULL;
    result = device->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dm2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm2, NULL);

    LPDIRECT3DMATERIAL3 d3dm3 = NULL;
    result = device->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dm3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm3, NULL);

    /* Direct3DTexture */

    LPDIRECT3DTEXTURE d3dt1 = NULL;
    result = device->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&d3dt1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt1, NULL);

    LPDIRECT3DTEXTURE2 d3dt2 = NULL;
    result = device->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&d3dt2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt2, NULL);

    /* Direct3DVertexBuffer */

    LPDIRECT3DVERTEXBUFFER d3dvb1 = NULL;
    result = device->QueryInterface(IID_IDirect3DVertexBuffer, (LPVOID*)&d3dvb1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb1, NULL);

    LPDIRECT3DVERTEXBUFFER7 d3dvb7 = NULL;
    result = device->QueryInterface(IID_IDirect3DVertexBuffer7, (LPVOID*)&d3dvb7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb7, NULL);

    /* Direct3DViewport */

    LPDIRECT3DVIEWPORT d3dvp1 = NULL;
    result = device->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&d3dvp1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvp1, NULL);

    LPDIRECT3DVIEWPORT2 d3dvp2 = NULL;
    result = device->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&d3dvp2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvp2, NULL);

    LPDIRECT3DVIEWPORT3 d3dvp3 = NULL;
    result = device->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&d3dvp3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvp3, NULL);

    /* DirectDraw */

    LPDIRECTDRAW dd = NULL;
    result = device->QueryInterface(IID_IDirectDraw, (LPVOID*)&dd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd, NULL);

    LPDIRECTDRAW2 dd2 = NULL;
    result = device->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd2, NULL);

    LPDIRECTDRAW4 dd4 = NULL;
    result = device->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd4, NULL);

    LPDIRECTDRAW7 dd7 = NULL;
    result = device->QueryInterface(IID_IDirectDraw7, (LPVOID*)&dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd7, NULL);

    /* DirectDrawClipper */

    LPDIRECTDRAWCLIPPER ddc = NULL;
    result = device->QueryInterface(IID_IDirectDrawClipper, (LPVOID*)&ddc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddc, NULL);

    /* DirectDrawColorControl */

    LPDIRECTDRAWCOLORCONTROL ddcc = NULL;
    result = device->QueryInterface(IID_IDirectDrawColorControl, (LPVOID*)&ddcc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddcc, NULL);

    /* DirectDrawGammaControl */

    LPDIRECTDRAWGAMMACONTROL ddgc = NULL;
    result = device->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&ddgc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddgc, NULL);

    /* DirectDrawPalette */

    LPDIRECTDRAWPALETTE ddp = NULL;
    result = device->QueryInterface(IID_IDirectDrawPalette, (LPVOID*)&ddp);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddp, NULL);

    /* DirectDrawSurface */

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = device->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds1, NULL);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = device->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds2, NULL);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = device->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds3, NULL);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = device->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds4, NULL);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = device->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds7, NULL);

    /* DirectDrawVideoPort */

    LPDIRECTDRAWVIDEOPORT ddvp = NULL;
    result = device->QueryInterface(IID_IDirectDrawVideoPort, (LPVOID*)&ddvp);
    IsNotEqual(result, DD_OK);
    IsEqual(ddvp, NULL);

    /* DirectDrawVideoPortContainer */

    LPDDVIDEOPORTCONTAINER ddvpc = NULL;
    result = device->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&ddvpc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddvpc, NULL);

    /* DirectDrawVideoPortNotify */

    LPDDVIDEOPORTNOTIFY ddvpn = NULL;
    result = device->QueryInterface(IID_IDirectDrawVideoPortNotify, (LPVOID*)&ddvpn);
    IsNotEqual(result, DD_OK);

    /* DirectDrawFactory2 */

    LPUNKNOWN ddf2 = NULL;
    result = device->QueryInterface(IID_IDirectDrawFactory2, (LPVOID*)&ddf2);
    IsNotEqual(result, DD_OK);

    /* IDirectDrawPalette2 */

    LPUNKNOWN ddp2 = NULL;
    result = device->QueryInterface(IID_IDirectDrawPalette2, (LPVOID*)&ddp2);
    IsNotEqual(result, DD_OK);

    /* DirectDrawKernel */

    LPUNKNOWN ddk = NULL;
    result = device->QueryInterface(IID_IDirectDrawKernel, (LPVOID*)&ddk);
    IsNotEqual(result, DD_OK);

    /* DirectDrawOptSurface */

    LPUNKNOWN ddos = NULL;
    result = device->QueryInterface(IID_IDirectDrawOptSurface, (LPVOID*)&ddos);
    IsNotEqual(result, DD_OK);

    /* DirectDrawSurfaceKernel */

    LPUNKNOWN ddsk = NULL;
    result = device->QueryInterface(IID_IDirectDrawSurfaceKernel, (LPVOID*)&ddsk);
    IsNotEqual(result, DD_OK);

    /* DirectDrawSurfaceNew */

    LPUNKNOWN ddsn = NULL;
    result = device->QueryInterface(IID_IDirectDrawOptSurface, (LPVOID*)&ddsn);
    IsNotEqual(result, DD_OK);

    /* Unknown */

    LPUNKNOWN unk = NULL;
    result = device->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);
    IsEqual(device, unk);
    DIRECTRELEASE(unk);
}

VOID DirectDrawDirect3DDevice2UnknownQueryAll(LPMODULE module)
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
    desc.dwFlags = DDSD_CAPS;

    desc.ddsCaps.dwCaps = DDSCAPS_3DDEVICE | DDSCAPS_PRIMARYSURFACE;

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = dd->CreateSurface(&desc, &dds1, NULL);
    IsEqual(result, DD_OK);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3d2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3d2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3d2);

    LPDIRECT3DDEVICE2 d3dd2 = NULL;
    result = d3d2->CreateDevice(IID_IDirect3DHALDevice, dds1, &d3dd2);
    IsEqual(result, DD_OK);

    IsNotEqual((LPVOID)d3dd2, NULL);
    IsNotEqual((LPVOID)dd, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)d3d2, (LPVOID)d3dd2);
    IsNotEqual((LPVOID)dds1, (LPVOID)d3dd2);

    {
        LPUNKNOWN unk = NULL;
        d3dd2->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)unk, NULL);

        DirectDrawCreateDirect3DDevice2UnknownQuery(unk);

        DIRECTRELEASE(unk);
    }

    DIRECTRELEASE(d3dd2);
    DIRECTRELEASE(dds1);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}