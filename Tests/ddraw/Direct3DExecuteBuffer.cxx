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

#include "Direct3DExecuteBuffer.hxx"

#include "Window.hxx"

static HRESULT CALLBACK EnumDirect3DDevices(GUID FAR* lpGuid, LPSTR lpDeviceDescription, LPSTR lpDeviceName, LPD3DDEVICEDESC lpD3DHWDeviceDesc, LPD3DDEVICEDESC lpD3DHELDeviceDesc, LPVOID lpContext)
{
    CopyMemory(lpContext, lpGuid, sizeof(GUID));

    return DDENUMRET_CANCEL;
}

VOID DirectDrawCreateDirect3DExecuteBuffer(LPMODULE module)
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

    LPDIRECTDRAWSURFACE dds = NULL;
    result = dd->CreateSurface(&desc, &dds, NULL);
    IsEqual(result, DD_OK);

    LPDIRECT3D d3d = NULL;
    result = dd->QueryInterface(IID_IDirect3D, (LPVOID*)&d3d);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3d, NULL);

    IsNotEqual((LPVOID)d3d, (LPVOID)dd);
    IsNotEqual((LPVOID)d3d, (LPVOID)dds);

    GUID id;
    ZeroMemory(&id, sizeof(GUID));
    result = d3d->EnumDevices(EnumDirect3DDevices, &id);
    IsEqual(result, DD_OK);

    LPDIRECT3DDEVICE d3dd = NULL;
    result = dds->QueryInterface(id, (LPVOID*)&d3dd);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dd, NULL);

    IsNotEqual((LPVOID)d3dd, (LPVOID)dd);
    IsNotEqual((LPVOID)d3dd, (LPVOID)dds);
    IsNotEqual((LPVOID)d3dd, (LPVOID)d3d);

    D3DEXECUTEBUFFERDESC bd;
    ZeroMemory(&bd, sizeof(D3DEXECUTEBUFFERDESC));

    bd.dwSize = sizeof(D3DEXECUTEBUFFERDESC);
    bd.dwFlags = D3DDEB_BUFSIZE;
    bd.dwBufferSize = 128;

    LPDIRECT3DEXECUTEBUFFER d3deb = NULL;
    result = d3dd->CreateExecuteBuffer(&bd, &d3deb, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3deb, NULL);

    DIRECTRELEASE(d3deb);
    DIRECTRELEASE(d3dd);
    DIRECTRELEASE(d3d);
    DIRECTRELEASE(dds);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDrawDirect3DExecuteBufferQueryInterfaceIUnknown(LPMODULE module)
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

    LPDIRECTDRAWSURFACE dds = NULL;
    result = dd->CreateSurface(&desc, &dds, NULL);
    IsEqual(result, DD_OK);

    LPDIRECT3D d3d = NULL;
    result = dd->QueryInterface(IID_IDirect3D, (LPVOID*)&d3d);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3d, NULL);

    IsNotEqual((LPVOID)d3d, (LPVOID)dd);
    IsNotEqual((LPVOID)d3d, (LPVOID)dds);

    GUID id;
    ZeroMemory(&id, sizeof(GUID));
    result = d3d->EnumDevices(EnumDirect3DDevices, &id);
    IsEqual(result, DD_OK);

    LPDIRECT3DDEVICE d3dd = NULL;
    result = dds->QueryInterface(id, (LPVOID*)&d3dd);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dd, NULL);

    IsNotEqual((LPVOID)d3dd, (LPVOID)dd);
    IsNotEqual((LPVOID)d3dd, (LPVOID)dds);
    IsNotEqual((LPVOID)d3dd, (LPVOID)d3d);

    D3DEXECUTEBUFFERDESC bd;
    ZeroMemory(&bd, sizeof(D3DEXECUTEBUFFERDESC));

    bd.dwSize = sizeof(D3DEXECUTEBUFFERDESC);
    bd.dwFlags = D3DDEB_BUFSIZE;
    bd.dwBufferSize = 128;

    LPDIRECT3DEXECUTEBUFFER d3deb = NULL;
    result = d3dd->CreateExecuteBuffer(&bd, &d3deb, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3deb, NULL);

    {
        LPUNKNOWN unk = NULL;
        result = d3deb->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
        IsEqual(result, DD_OK);
        IsEqual((LPVOID)d3deb, unk);
        DIRECTRELEASE(unk);
    }

    DIRECTRELEASE(d3deb);
    DIRECTRELEASE(d3dd);
    DIRECTRELEASE(d3d);
    DIRECTRELEASE(dds);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}

VOID DirectDrawDirect3DExecuteBufferQuery(LPDIRECT3DEXECUTEBUFFER buffer)
{
    /* Direct3D */

    LPDIRECT3D dd3d1 = NULL;
    HRESULT result = buffer->QueryInterface(IID_IDirect3D, (LPVOID*)&dd3d1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d1, NULL);

    LPDIRECT3D2 dd3d2 = NULL;
    result = buffer->QueryInterface(IID_IDirect3D2, (LPVOID*)&dd3d2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d2, NULL);

    LPDIRECT3D3 dd3d3 = NULL;
    result = buffer->QueryInterface(IID_IDirect3D3, (LPVOID*)&dd3d3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d3, NULL);

    LPDIRECT3D3 dd3d7 = NULL;
    result = buffer->QueryInterface(IID_IDirect3D7, (LPVOID*)&dd3d7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d7, NULL);

    /* Direct3DDevice */

    LPDIRECT3DDEVICE dd3dd1 = NULL;
    result = buffer->QueryInterface(IID_IDirect3DDevice, (LPVOID*)&dd3dd1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    LPDIRECT3DDEVICE2 dd3dd2 = NULL;
    result = buffer->QueryInterface(IID_IDirect3DDevice2, (LPVOID*)&dd3dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd2, NULL);

    LPDIRECT3DDEVICE3 dd3dd3 = NULL;
    result = buffer->QueryInterface(IID_IDirect3DDevice3, (LPVOID*)&dd3dd3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd3, NULL);

    LPDIRECT3DDEVICE7 dd3dd7 = NULL;
    result = buffer->QueryInterface(IID_IDirect3DDevice7, (LPVOID*)&dd3dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd7, NULL);

    LPDIRECT3DDEVICE d3drd = NULL;
    result = buffer->QueryInterface(IID_IDirect3DRampDevice, (LPVOID*)&d3drd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drd, NULL);

    LPDIRECT3DDEVICE d3drgbd = NULL;
    result = buffer->QueryInterface(IID_IDirect3DRGBDevice, (LPVOID*)&d3drgbd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drd, NULL);

    LPDIRECT3DDEVICE d3dhald = NULL;
    result = buffer->QueryInterface(IID_IDirect3DHALDevice, (LPVOID*)&d3dhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drd, NULL);

    LPDIRECT3DDEVICE d3dmmxd = NULL;
    result = buffer->QueryInterface(IID_IDirect3DMMXDevice, (LPVOID*)&d3dmmxd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drd, NULL);

    LPDIRECT3DDEVICE d3drefd = NULL;
    result = buffer->QueryInterface(IID_IDirect3DRefDevice, (LPVOID*)&d3drefd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drefd, NULL);

    LPDIRECT3DDEVICE d3dnd = NULL;
    result = buffer->QueryInterface(IID_IDirect3DNullDevice, (LPVOID*)&d3dnd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dnd, NULL);

    LPDIRECT3DDEVICE d3dtnlhald = NULL;
    result = buffer->QueryInterface(IID_IDirect3DTnLHalDevice, (LPVOID*)&d3dtnlhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dtnlhald, NULL);

    /* Direct3DExecuteBuffer */

    LPDIRECT3DEXECUTEBUFFER d3deb = NULL;
    result = buffer->QueryInterface(IID_IDirect3DExecuteBuffer, (LPVOID*)&d3deb);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3deb, NULL);

    IsEqual((LPVOID)d3deb, (LPVOID)buffer);

    /* Direct3DLight */

    LPDIRECT3DLIGHT d3dl = NULL;
    result = buffer->QueryInterface(IID_IDirect3DLight, (LPVOID*)&d3dl);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dl, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dm1 = NULL;
    result = buffer->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dm1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm1, NULL);

    LPDIRECT3DMATERIAL2 d3dm2 = NULL;
    result = buffer->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dm2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm2, NULL);

    LPDIRECT3DMATERIAL3 d3dm3 = NULL;
    result = buffer->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dm3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm3, NULL);

    /* Direct3DTexture */

    LPDIRECT3DTEXTURE d3dt1 = NULL;
    result = buffer->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&d3dt1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt1, NULL);

    LPDIRECT3DTEXTURE2 d3dt2 = NULL;
    result = buffer->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&d3dt2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt1, NULL);

    /* Direct3DVertexBuffer */

    LPDIRECT3DVERTEXBUFFER d3dvb1 = NULL;
    result = buffer->QueryInterface(IID_IDirect3DVertexBuffer, (LPVOID*)&d3dvb1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb1, NULL);

    LPDIRECT3DVERTEXBUFFER7 d3dvb7 = NULL;
    result = buffer->QueryInterface(IID_IDirect3DVertexBuffer7, (LPVOID*)&d3dvb7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb7, NULL);

    /* Direct3DViewport */

    LPDIRECT3DVIEWPORT d3dvp1 = NULL;
    result = buffer->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&d3dvp1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvp1, NULL);

    LPDIRECT3DVIEWPORT2 d3dvp2 = NULL;
    result = buffer->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&d3dvp2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvp2, NULL);

    LPDIRECT3DVIEWPORT3 d3dvp3 = NULL;
    result = buffer->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&d3dvp3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvp3, NULL);

    /* DirectDraw */

    LPDIRECTDRAW dd = NULL;
    result = buffer->QueryInterface(IID_IDirectDraw, (LPVOID*)&dd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd, NULL);

    LPDIRECTDRAW2 dd2 = NULL;
    result = buffer->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd2, NULL);

    LPDIRECTDRAW4 dd4 = NULL;
    result = buffer->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd4, NULL);

    LPDIRECTDRAW7 dd7 = NULL;
    result = buffer->QueryInterface(IID_IDirectDraw7, (LPVOID*)&dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd7, NULL);

    /* DirectDrawClipper */

    LPDIRECTDRAWCLIPPER ddc = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawClipper, (LPVOID*)&ddc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddc, NULL);

    /* DirectDrawColorControl */

    LPDIRECTDRAWCOLORCONTROL ddcc = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawColorControl, (LPVOID*)&ddcc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddcc, NULL);

    /* DirectDrawGammaControl */

    LPDIRECTDRAWGAMMACONTROL ddgc = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&ddgc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddgc, NULL);

    /* DirectDrawPalette */

    LPDIRECTDRAWPALETTE ddp = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawPalette, (LPVOID*)&ddp);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddp, NULL);

    /* DirectDrawSurface */

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds1, NULL);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds1, NULL);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds1, NULL);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds1, NULL);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds1, NULL);

    /* DirectDrawVideoPort */

    LPDIRECTDRAWVIDEOPORT ddvp = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawVideoPort, (LPVOID*)&ddvp);
    IsNotEqual(result, DD_OK);
    IsEqual(ddvp, NULL);

    /* DirectDrawVideoPortContainer */

    LPDDVIDEOPORTCONTAINER ddvpc = NULL;
    result = buffer->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&ddvpc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddvpc, NULL);

    /* DirectDrawVideoPortNotify */

    LPDDVIDEOPORTNOTIFY ddvpn = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawVideoPortNotify, (LPVOID*)&ddvpn);
    IsNotEqual(result, DD_OK);

    /* DirectDrawFactory2 */

    LPUNKNOWN ddf2 = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawFactory2, (LPVOID*)&ddf2);
    IsNotEqual(result, DD_OK);

    /* IDirectDrawPalette2 */

    LPUNKNOWN ddp2 = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawPalette2, (LPVOID*)&ddp2);
    IsNotEqual(result, DD_OK);

    /* DirectDrawKernel */

    LPUNKNOWN ddk = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawKernel, (LPVOID*)&ddk);
    IsNotEqual(result, DD_OK);

    /* DirectDrawOptSurface */

    LPUNKNOWN ddos = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawOptSurface, (LPVOID*)&ddos);
    IsNotEqual(result, DD_OK);

    /* DirectDrawSurfaceKernel */

    LPUNKNOWN ddsk = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawSurfaceKernel, (LPVOID*)&ddsk);
    IsNotEqual(result, DD_OK);

    /* DirectDrawSurfaceNew */

    LPUNKNOWN ddsn = NULL;
    result = buffer->QueryInterface(IID_IDirectDrawOptSurface, (LPVOID*)&ddsn);
    IsNotEqual(result, DD_OK);

    /* Unknown */

    LPUNKNOWN unk = NULL;
    result = buffer->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);
    IsEqual(buffer, unk);
    DIRECTRELEASE(unk);
}

VOID DirectDrawDirect3DExecuteBufferQueryInterfaceAll(LPMODULE module)
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

    LPDIRECTDRAWSURFACE dds = NULL;
    result = dd->CreateSurface(&desc, &dds, NULL);
    IsEqual(result, DD_OK);

    LPDIRECT3D d3d = NULL;
    result = dd->QueryInterface(IID_IDirect3D, (LPVOID*)&d3d);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3d, NULL);

    IsNotEqual((LPVOID)d3d, (LPVOID)dd);
    IsNotEqual((LPVOID)d3d, (LPVOID)dds);

    GUID id;
    ZeroMemory(&id, sizeof(GUID));
    result = d3d->EnumDevices(EnumDirect3DDevices, &id);
    IsEqual(result, DD_OK);

    LPDIRECT3DDEVICE d3dd = NULL;
    result = dds->QueryInterface(id, (LPVOID*)&d3dd);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dd, NULL);

    IsNotEqual((LPVOID)d3dd, (LPVOID)dd);
    IsNotEqual((LPVOID)d3dd, (LPVOID)dds);
    IsNotEqual((LPVOID)d3dd, (LPVOID)d3d);

    D3DEXECUTEBUFFERDESC bd;
    ZeroMemory(&bd, sizeof(D3DEXECUTEBUFFERDESC));

    bd.dwSize = sizeof(D3DEXECUTEBUFFERDESC);
    bd.dwFlags = D3DDEB_BUFSIZE;
    bd.dwBufferSize = 128;

    LPDIRECT3DEXECUTEBUFFER d3deb = NULL;
    result = d3dd->CreateExecuteBuffer(&bd, &d3deb, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3deb, NULL);

    DirectDrawDirect3DExecuteBufferQuery(d3deb);

    DIRECTRELEASE(d3deb);
    DIRECTRELEASE(d3dd);
    DIRECTRELEASE(d3d);
    DIRECTRELEASE(dds);
    DIRECTRELEASE(dd);

    ReleaseWindow(hwnd);
}