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

#include "Direct3DVolume8.hxx"

#include "Window.hxx"

VOID Direct3DVolume8Create(LPMODULE module)
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

    LPDIRECT3DVOLUMETEXTURE8 tex = NULL;
    result = device->CreateVolumeTexture(256, 256, 256, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &tex);
    IsEqual(result, D3D_OK);
    IsNotEqual(tex, NULL);

    LPDIRECT3DVOLUME8 vol = NULL;
    result = tex->GetVolumeLevel(0, &vol);
    IsEqual(result, D3D_OK);
    IsNotEqual(vol, NULL);

    DIRECTRELEASE(vol);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DVolume8Release(LPMODULE module)
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

    LPDIRECT3DVOLUMETEXTURE8 tex = NULL;
    result = device->CreateVolumeTexture(256, 256, 256, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &tex);
    IsEqual(result, D3D_OK);
    IsNotEqual(tex, NULL);

    LPDIRECT3DVOLUME8 vol = NULL;
    result = tex->GetVolumeLevel(0, &vol);
    IsEqual(result, D3D_OK);
    IsNotEqual(vol, NULL);

    IsEqual(vol->Release(), 1);
    IsEqual(vol->Release(), 0);
    IsEqual(vol->Release(), 0);

    DIRECTRELEASE(vol);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DVolume8QueryInterfaceIUnknown(LPMODULE module)
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

    LPDIRECT3DVOLUMETEXTURE8 tex = NULL;
    result = device->CreateVolumeTexture(256, 256, 256, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &tex);
    IsEqual(result, D3D_OK);
    IsNotEqual(tex, NULL);

    LPDIRECT3DVOLUME8 vol = NULL;
    result = tex->GetVolumeLevel(0, &vol);
    IsEqual(result, D3D_OK);
    IsNotEqual(vol, NULL);

    LPUNKNOWN unk = NULL;
    result = vol->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual(unk, NULL);
    IsEqual(vol, unk);

    DIRECTRELEASE(vol);
    DIRECTRELEASE(unk);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DVolume8Query(LPDIRECT3DVOLUME8 vol)
{
    LPDIRECT3D8 d3d = NULL;
    HRESULT result = vol->QueryInterface(IID_IDirect3D8, (LPVOID*)&d3d);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3d, NULL);

    LPDIRECT3DDEVICE8 d3dd = NULL;
    result = vol->QueryInterface(IID_IDirect3DDevice8, (LPVOID*)&d3dd);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dd, NULL);

    LPDIRECT3DRESOURCE8 d3dr = NULL;
    result = vol->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&d3dr);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dr, NULL);

    LPDIRECT3DBASETEXTURE8 d3dbt = NULL;
    result = vol->QueryInterface(IID_IDirect3DBaseTexture8, (LPVOID*)&d3dbt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dbt, NULL);

    LPDIRECT3DTEXTURE8 d3dt = NULL;
    result = vol->QueryInterface(IID_IDirect3DTexture8, (LPVOID*)&d3dt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dt, NULL);

    LPDIRECT3DCUBETEXTURE8 d3dct = NULL;
    result = vol->QueryInterface(IID_IDirect3DCubeTexture8, (LPVOID*)&d3dct);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dct, NULL);

    LPDIRECT3DVOLUMETEXTURE8 d3dvt = NULL;
    result = vol->QueryInterface(IID_IDirect3DVolumeTexture8, (LPVOID*)&d3dvt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dvt, NULL);

    LPDIRECT3DVERTEXBUFFER8 d3dvb = NULL;
    result = vol->QueryInterface(IID_IDirect3DVertexBuffer8, (LPVOID*)&d3dvb);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dvb, NULL);

    LPDIRECT3DINDEXBUFFER8 d3dib = NULL;
    result = vol->QueryInterface(IID_IDirect3DIndexBuffer8, (LPVOID*)&d3dib);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dib, NULL);

    LPDIRECT3DSURFACE8 d3ds = NULL;
    result = vol->QueryInterface(IID_IDirect3DSurface8, (LPVOID*)&d3ds);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3ds, NULL);

    LPDIRECT3DVOLUME8 d3dv = NULL;
    result = vol->QueryInterface(IID_IDirect3DVolume8, (LPVOID*)&d3dv);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dv, vol);
    DIRECTRELEASE(d3dv);

    LPDIRECT3DSWAPCHAIN8 d3dsc = NULL;
    result = vol->QueryInterface(IID_IDirect3DSwapChain8, (LPVOID*)&d3dsc);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dsc, NULL);

    LPUNKNOWN unk = NULL;
    result = vol->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual((LPVOID)unk, NULL);
    IsEqual((LPVOID)unk, vol);
    DIRECTRELEASE(unk);
}

VOID Direct3DVolume8QueryInterfaceAll(LPMODULE module)
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

    LPDIRECT3DVOLUMETEXTURE8 tex = NULL;
    result = device->CreateVolumeTexture(256, 256, 256, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &tex);
    IsEqual(result, D3D_OK);
    IsNotEqual(tex, NULL);

    LPDIRECT3DVOLUME8 vol = NULL;
    result = tex->GetVolumeLevel(0, &vol);
    IsEqual(result, D3D_OK);
    IsNotEqual(vol, NULL);

    Direct3DVolume8Query(vol);

    DIRECTRELEASE(vol);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DVolume8UnknownQuery(LPUNKNOWN unknown)
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
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dr, NULL);

    LPDIRECT3DBASETEXTURE8 d3dbt = NULL;
    result = unknown->QueryInterface(IID_IDirect3DBaseTexture8, (LPVOID*)&d3dbt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dbt, NULL);

    LPDIRECT3DTEXTURE8 d3dt = NULL;
    result = unknown->QueryInterface(IID_IDirect3DTexture8, (LPVOID*)&d3dt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dt, NULL);

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
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dv, unknown);
    DIRECTRELEASE(d3dv);

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

VOID Direct3DVolume8UnknownQueryInterfaceAll(LPMODULE module)
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

    LPDIRECT3DVOLUMETEXTURE8 tex = NULL;
    result = device->CreateVolumeTexture(256, 256, 256, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &tex);
    IsEqual(result, D3D_OK);
    IsNotEqual(tex, NULL);

    LPDIRECT3DVOLUME8 vol = NULL;
    result = tex->GetVolumeLevel(0, &vol);
    IsEqual(result, D3D_OK);
    IsNotEqual(vol, NULL);

    LPUNKNOWN unk = NULL;
    result = vol->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual(unk, NULL);
    IsEqual(vol, unk);

    Direct3DVolume8UnknownQuery(unk);

    DIRECTRELEASE(vol);
    DIRECTRELEASE(unk);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}