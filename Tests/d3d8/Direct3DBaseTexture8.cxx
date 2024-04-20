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

#include "Direct3DBaseTexture8.hxx"

#include "Window.hxx"

VOID Direct3DBaseTexture8Create(LPMODULE module)
{
    HWND hwnd = InitializeWindow();

    LPDIRECT3D8 d3d = module->Direct3DCreate8(D3D_SDK_VERSION);
    IsNotEqual(d3d, NULL);

    d3d->AddRef();
    IsEqual(d3d->Release(), 1);

    D3DPRESENT_PARAMETERS params;
    ZeroMemory(&params, sizeof(D3DPRESENT_PARAMETERS));

    params.BackBufferWidth = 640;
    params.BackBufferHeight = 480;
    params.BackBufferFormat = D3DFMT_A8R8G8B8;
    params.BackBufferCount = 1;
    params.MultiSampleType = D3DMULTISAMPLE_NONE;
    params.SwapEffect = D3DSWAPEFFECT_DISCARD;
    params.hDeviceWindow = hwnd;
    params.Windowed = TRUE;
    params.EnableAutoDepthStencil = FALSE;
    params.AutoDepthStencilFormat = D3DFMT_UNKNOWN;

    LPDIRECT3DDEVICE8 device = NULL;
    HRESULT result = d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &params, &device);
    IsEqual(result, D3D_OK);
    IsNotEqual(d3d, NULL);

    LPDIRECT3DTEXTURE8 stex = NULL;
    result = device->CreateTexture(256, 256, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &stex);
    IsEqual(result, D3D_OK);
    IsNotEqual(stex, NULL);

    result = device->SetTexture(0, stex);

    LPDIRECT3DBASETEXTURE8 gtex = NULL;
    result = device->GetTexture(0, &gtex);
    IsEqual(result, D3D_OK);
    IsNotEqual(gtex, NULL);

    IsEqual(stex, gtex);

    DIRECTRELEASE(gtex);
    DIRECTRELEASE(stex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DBaseTexture8Release(LPMODULE module)
{
    HWND hwnd = InitializeWindow();

    LPDIRECT3D8 d3d = module->Direct3DCreate8(D3D_SDK_VERSION);
    IsNotEqual(d3d, NULL);

    d3d->AddRef();
    IsEqual(d3d->Release(), 1);

    D3DPRESENT_PARAMETERS params;
    ZeroMemory(&params, sizeof(D3DPRESENT_PARAMETERS));

    params.BackBufferWidth = 640;
    params.BackBufferHeight = 480;
    params.BackBufferFormat = D3DFMT_A8R8G8B8;
    params.BackBufferCount = 1;
    params.MultiSampleType = D3DMULTISAMPLE_NONE;
    params.SwapEffect = D3DSWAPEFFECT_DISCARD;
    params.hDeviceWindow = hwnd;
    params.Windowed = TRUE;
    params.EnableAutoDepthStencil = FALSE;
    params.AutoDepthStencilFormat = D3DFMT_UNKNOWN;

    LPDIRECT3DDEVICE8 device = NULL;
    HRESULT result = d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &params, &device);
    IsEqual(result, D3D_OK);
    IsNotEqual(d3d, NULL);

    LPDIRECT3DTEXTURE8 tex = NULL;
    result = device->CreateTexture(256, 256, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &tex);
    IsEqual(result, D3D_OK);
    IsNotEqual(tex, NULL);

    //IsEqual(tex->Release(), 0);
    //IsEqual(tex->Release(), 0);
    //IsEqual(tex->Release(), 0);

    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DBaseTexture8QueryInterfaceIUnknown(LPMODULE module)
{
    HWND hwnd = InitializeWindow();

    LPDIRECT3D8 d3d = module->Direct3DCreate8(D3D_SDK_VERSION);
    IsNotEqual(d3d, NULL);

    d3d->AddRef();
    IsEqual(d3d->Release(), 1);

    D3DPRESENT_PARAMETERS params;
    ZeroMemory(&params, sizeof(D3DPRESENT_PARAMETERS));

    params.BackBufferWidth = 640;
    params.BackBufferHeight = 480;
    params.BackBufferFormat = D3DFMT_A8R8G8B8;
    params.BackBufferCount = 1;
    params.MultiSampleType = D3DMULTISAMPLE_NONE;
    params.SwapEffect = D3DSWAPEFFECT_DISCARD;
    params.hDeviceWindow = hwnd;
    params.Windowed = TRUE;
    params.EnableAutoDepthStencil = FALSE;
    params.AutoDepthStencilFormat = D3DFMT_UNKNOWN;

    LPDIRECT3DDEVICE8 device = NULL;
    HRESULT result = d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &params, &device);
    IsEqual(result, D3D_OK);
    IsNotEqual(d3d, NULL);

    LPDIRECT3DTEXTURE8 stex = NULL;
    result = device->CreateTexture(256, 256, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &stex);
    IsEqual(result, D3D_OK);
    IsNotEqual(stex, NULL);

    result = device->SetTexture(0, stex);

    LPDIRECT3DBASETEXTURE8 gtex = NULL;
    result = device->GetTexture(0, &gtex);
    IsEqual(result, D3D_OK);
    IsNotEqual(gtex, NULL);

    IsEqual(gtex, stex);

    LPUNKNOWN unk = NULL;
    result = gtex->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual(unk, NULL);
    IsEqual(gtex, unk);

    DIRECTRELEASE(unk);
    DIRECTRELEASE(stex);
    DIRECTRELEASE(gtex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DBaseTexture8Query(LPDIRECT3DBASETEXTURE8 tex)
{
    LPDIRECT3D8 d3d = NULL;
    HRESULT result = tex->QueryInterface(IID_IDirect3D8, (LPVOID*)&d3d);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3d, NULL);

    LPDIRECT3DDEVICE8 d3dd = NULL;
    result = tex->QueryInterface(IID_IDirect3DDevice8, (LPVOID*)&d3dd);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dd, NULL);

    LPDIRECT3DRESOURCE8 d3dr = NULL;
    result = tex->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&d3dr);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dr, tex);
    DIRECTRELEASE(d3dr);

    LPDIRECT3DBASETEXTURE8 d3dbt = NULL;
    result = tex->QueryInterface(IID_IDirect3DBaseTexture8, (LPVOID*)&d3dbt);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dbt, tex);
    DIRECTRELEASE(d3dbt);

    LPDIRECT3DTEXTURE8 d3dt = NULL;
    result = tex->QueryInterface(IID_IDirect3DTexture8, (LPVOID*)&d3dt);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dt, tex);
    DIRECTRELEASE(d3dt);

    LPDIRECT3DCUBETEXTURE8 d3dct = NULL;
    result = tex->QueryInterface(IID_IDirect3DCubeTexture8, (LPVOID*)&d3dct);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dct, NULL);

    LPDIRECT3DVOLUMETEXTURE8 d3dvt = NULL;
    result = tex->QueryInterface(IID_IDirect3DVolumeTexture8, (LPVOID*)&d3dvt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dvt, NULL);

    LPDIRECT3DVERTEXBUFFER8 d3dvb = NULL;
    result = tex->QueryInterface(IID_IDirect3DVertexBuffer8, (LPVOID*)&d3dvb);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dvb, NULL);

    LPDIRECT3DINDEXBUFFER8 d3dib = NULL;
    result = tex->QueryInterface(IID_IDirect3DIndexBuffer8, (LPVOID*)&d3dib);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dib, NULL);

    LPDIRECT3DSURFACE8 d3ds = NULL;
    result = tex->QueryInterface(IID_IDirect3DSurface8, (LPVOID*)&d3ds);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3ds, NULL);

    LPDIRECT3DVOLUME8 d3dv = NULL;
    result = tex->QueryInterface(IID_IDirect3DVolume8, (LPVOID*)&d3dv);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dv, NULL);

    LPDIRECT3DSWAPCHAIN8 d3dsc = NULL;
    result = tex->QueryInterface(IID_IDirect3DSwapChain8, (LPVOID*)&d3dsc);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dsc, NULL);

    LPUNKNOWN unk = NULL;
    result = tex->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual((LPVOID)unk, NULL);
    IsEqual((LPVOID)unk, tex);
    DIRECTRELEASE(unk);
}

VOID Direct3DBaseTexture8QueryInterfaceAll(LPMODULE module)
{
    HWND hwnd = InitializeWindow();

    LPDIRECT3D8 d3d = module->Direct3DCreate8(D3D_SDK_VERSION);
    IsNotEqual(d3d, NULL);

    d3d->AddRef();
    IsEqual(d3d->Release(), 1);

    D3DPRESENT_PARAMETERS params;
    ZeroMemory(&params, sizeof(D3DPRESENT_PARAMETERS));

    params.BackBufferWidth = 640;
    params.BackBufferHeight = 480;
    params.BackBufferFormat = D3DFMT_A8R8G8B8;
    params.BackBufferCount = 1;
    params.MultiSampleType = D3DMULTISAMPLE_NONE;
    params.SwapEffect = D3DSWAPEFFECT_DISCARD;
    params.hDeviceWindow = hwnd;
    params.Windowed = TRUE;
    params.EnableAutoDepthStencil = FALSE;
    params.AutoDepthStencilFormat = D3DFMT_UNKNOWN;

    LPDIRECT3DDEVICE8 device = NULL;
    HRESULT result = d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &params, &device);
    IsEqual(result, D3D_OK);
    IsNotEqual(d3d, NULL);

    LPDIRECT3DTEXTURE8 stex = NULL;
    result = device->CreateTexture(256, 256, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &stex);
    IsEqual(result, D3D_OK);
    IsNotEqual(stex, NULL);

    result = device->SetTexture(0, stex);

    LPDIRECT3DBASETEXTURE8 gtex = NULL;
    result = device->GetTexture(0, &gtex);
    IsEqual(result, D3D_OK);
    IsNotEqual(gtex, NULL);

    IsEqual(gtex, stex);

    Direct3DBaseTexture8Query(gtex);

    DIRECTRELEASE(stex);
    DIRECTRELEASE(gtex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DBaseTexture8UnknownQuery(LPUNKNOWN unknown)
{
    LPDIRECT3D8 d3d = NULL;
    HRESULT result = unknown->QueryInterface(IID_IDirect3D8, (LPVOID*)&d3d);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3d, NULL);

    LPDIRECT3DDEVICE8 d3dd = NULL;
    result = unknown->QueryInterface(IID_IDirect3DDevice8, (LPVOID*)&d3dd);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dd, NULL);

    LPDIRECT3DRESOURCE8 d3dr = NULL;
    result = unknown->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&d3dr);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dr, unknown);
    DIRECTRELEASE(d3dr);

    LPDIRECT3DBASETEXTURE8 d3dbt = NULL;
    result = unknown->QueryInterface(IID_IDirect3DBaseTexture8, (LPVOID*)&d3dbt);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dbt, unknown);
    DIRECTRELEASE(d3dbt);

    LPDIRECT3DTEXTURE8 d3dt = NULL;
    result = unknown->QueryInterface(IID_IDirect3DTexture8, (LPVOID*)&d3dt);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dt, unknown);
    DIRECTRELEASE(d3dt);

    LPDIRECT3DCUBETEXTURE8 d3dct = NULL;
    result = unknown->QueryInterface(IID_IDirect3DCubeTexture8, (LPVOID*)&d3dct);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dct, NULL);

    LPDIRECT3DVOLUMETEXTURE8 d3dvt = NULL;
    result = unknown->QueryInterface(IID_IDirect3DVolumeTexture8, (LPVOID*)&d3dvt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dvt, NULL);

    LPDIRECT3DVERTEXBUFFER8 d3dvb = NULL;
    result = unknown->QueryInterface(IID_IDirect3DVertexBuffer8, (LPVOID*)&d3dvb);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dvb, NULL);

    LPDIRECT3DINDEXBUFFER8 d3dib = NULL;
    result = unknown->QueryInterface(IID_IDirect3DIndexBuffer8, (LPVOID*)&d3dib);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dib, NULL);

    LPDIRECT3DSURFACE8 d3ds = NULL;
    result = unknown->QueryInterface(IID_IDirect3DSurface8, (LPVOID*)&d3ds);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3ds, NULL);

    LPDIRECT3DVOLUME8 d3dv = NULL;
    result = unknown->QueryInterface(IID_IDirect3DVolume8, (LPVOID*)&d3dv);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dv, NULL);

    LPDIRECT3DSWAPCHAIN8 d3dsc = NULL;
    result = unknown->QueryInterface(IID_IDirect3DSwapChain8, (LPVOID*)&d3dsc);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dsc, NULL);

    LPUNKNOWN unk = NULL;
    result = unknown->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual((LPVOID)unk, NULL);
    IsEqual((LPVOID)unk, unknown);
    DIRECTRELEASE(unk);
}

VOID Direct3DBaseTexture8UnknownQueryInterfaceAll(LPMODULE module)
{
    HWND hwnd = InitializeWindow();

    LPDIRECT3D8 d3d = module->Direct3DCreate8(D3D_SDK_VERSION);
    IsNotEqual(d3d, NULL);

    d3d->AddRef();
    IsEqual(d3d->Release(), 1);

    D3DPRESENT_PARAMETERS params;
    ZeroMemory(&params, sizeof(D3DPRESENT_PARAMETERS));

    params.BackBufferWidth = 640;
    params.BackBufferHeight = 480;
    params.BackBufferFormat = D3DFMT_A8R8G8B8;
    params.BackBufferCount = 1;
    params.MultiSampleType = D3DMULTISAMPLE_NONE;
    params.SwapEffect = D3DSWAPEFFECT_DISCARD;
    params.hDeviceWindow = hwnd;
    params.Windowed = TRUE;
    params.EnableAutoDepthStencil = FALSE;
    params.AutoDepthStencilFormat = D3DFMT_UNKNOWN;

    LPDIRECT3DDEVICE8 device = NULL;
    HRESULT result = d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &params, &device);
    IsEqual(result, D3D_OK);
    IsNotEqual(d3d, NULL);

    LPDIRECT3DTEXTURE8 stex = NULL;
    result = device->CreateTexture(256, 256, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &stex);
    IsEqual(result, D3D_OK);
    IsNotEqual(stex, NULL);

    result = device->SetTexture(0, stex);

    LPDIRECT3DBASETEXTURE8 gtex = NULL;
    result = device->GetTexture(0, &gtex);
    IsEqual(result, D3D_OK);
    IsNotEqual(gtex, NULL);

    IsEqual(stex, gtex);

    LPUNKNOWN unk = NULL;
    result = gtex->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual(unk, NULL);
    IsEqual(gtex, unk);

    Direct3DBaseTexture8UnknownQuery(unk);

    DIRECTRELEASE(unk);
    DIRECTRELEASE(stex);
    DIRECTRELEASE(gtex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}