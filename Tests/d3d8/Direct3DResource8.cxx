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

#include "Direct3DResource8.hxx"

#include "Window.hxx"

VOID Direct3DIndexBufferResource8Create(LPMODULE module)
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

    LPDIRECT3DINDEXBUFFER8 ib = NULL;
    result = device->CreateIndexBuffer(1024, D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &ib);
    IsEqual(result, D3D_OK);
    IsNotEqual(ib, NULL);

    LPDIRECT3DRESOURCE8 res = NULL;
    result = ib->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, ib);

    DIRECTRELEASE(res);
    DIRECTRELEASE(ib);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DVertexBufferResource8Create(LPMODULE module)
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

    LPDIRECT3DVERTEXBUFFER8 vb = NULL;
    result = device->CreateVertexBuffer(1024, D3DUSAGE_WRITEONLY, D3DFVF_XYZRHW, D3DPOOL_DEFAULT, &vb);
    IsEqual(result, D3D_OK);
    IsNotEqual(vb, NULL);

    LPDIRECT3DRESOURCE8 res = NULL;
    result = vb->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, vb);

    DIRECTRELEASE(res);
    DIRECTRELEASE(vb);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DCubeTextureResource8Create(LPMODULE module)
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

    LPDIRECT3DCUBETEXTURE8 tex = NULL;
    result = device->CreateCubeTexture(256, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &tex);
    IsEqual(result, D3D_OK);
    IsNotEqual(tex, NULL);

    LPDIRECT3DRESOURCE8 res = NULL;
    result = tex->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, tex);

    DIRECTRELEASE(res);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DTextureResource8Create(LPMODULE module)
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

    LPDIRECT3DRESOURCE8 res = NULL;
    result = tex->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, tex);

    DIRECTRELEASE(res);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DVolumeTextureResource8Create(LPMODULE module)
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

    LPDIRECT3DRESOURCE8 res = NULL;
    result = tex->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, tex);

    DIRECTRELEASE(res);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DResource8Create(LPMODULE module)
{
    Direct3DIndexBufferResource8Create(module);
    Direct3DVertexBufferResource8Create(module);
    Direct3DCubeTextureResource8Create(module);
    Direct3DTextureResource8Create(module);
    Direct3DVolumeTextureResource8Create(module);
}

VOID Direct3DIndexBufferResource8Release(LPMODULE module)
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

    LPDIRECT3DINDEXBUFFER8 ib = NULL;
    result = device->CreateIndexBuffer(1024, D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &ib);
    IsEqual(result, D3D_OK);
    IsNotEqual(ib, NULL);

    LPDIRECT3DRESOURCE8 res = NULL;
    result = ib->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, ib);

    IsEqual(res->Release(), 1);
    IsEqual(res->Release(), 0);
    IsEqual(res->Release(), 0);

    DIRECTRELEASE(res);
    DIRECTRELEASE(ib);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DVertexBufferResource8Release(LPMODULE module)
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

    LPDIRECT3DVERTEXBUFFER8 vb = NULL;
    result = device->CreateVertexBuffer(1024, D3DUSAGE_WRITEONLY, D3DFVF_XYZRHW, D3DPOOL_DEFAULT, &vb);
    IsEqual(result, D3D_OK);
    IsNotEqual(vb, NULL);

    LPDIRECT3DRESOURCE8 res = NULL;
    result = vb->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, vb);

    IsEqual(res->Release(), 1);
    IsEqual(res->Release(), 0);
    IsEqual(res->Release(), 0);

    DIRECTRELEASE(res);
    DIRECTRELEASE(vb);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DCubeTextureResource8Release(LPMODULE module)
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

    LPDIRECT3DCUBETEXTURE8 tex = NULL;
    result = device->CreateCubeTexture(256, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &tex);
    IsEqual(result, D3D_OK);
    IsNotEqual(tex, NULL);

    LPDIRECT3DRESOURCE8 res = NULL;
    result = tex->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, tex);

    IsEqual(res->Release(), 1);
    IsEqual(res->Release(), 0);
    IsEqual(res->Release(), 0);

    DIRECTRELEASE(res);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DTextureResource8Release(LPMODULE module)
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

    LPDIRECT3DRESOURCE8 res = NULL;
    result = tex->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, tex);

    IsEqual(res->Release(), 1);
    IsEqual(res->Release(), 0);
    IsEqual(res->Release(), 0);

    DIRECTRELEASE(res);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DVolumeTextureResource8Release(LPMODULE module)
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

    LPDIRECT3DRESOURCE8 res = NULL;
    result = tex->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, tex);

    IsEqual(res->Release(), 1);
    IsEqual(res->Release(), 0);
    IsEqual(res->Release(), 0);

    DIRECTRELEASE(res);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DResource8Release(LPMODULE module)
{
    Direct3DIndexBufferResource8Release(module);
    Direct3DVertexBufferResource8Release(module);
    Direct3DCubeTextureResource8Release(module);
    Direct3DTextureResource8Release(module);
    Direct3DVolumeTextureResource8Release(module);
}

VOID Direct3DIndexBufferResource8QueryInterfaceIUnknown(LPMODULE module)
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

    LPDIRECT3DINDEXBUFFER8 ib = NULL;
    result = device->CreateIndexBuffer(1024, D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &ib);
    IsEqual(result, D3D_OK);
    IsNotEqual(ib, NULL);

    LPDIRECT3DRESOURCE8 res = NULL;
    result = ib->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, ib);

    LPUNKNOWN unk = NULL;
    result = res->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual(unk, NULL);
    IsEqual(res, unk);

    DIRECTRELEASE(unk);
    DIRECTRELEASE(res);
    DIRECTRELEASE(ib);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DVertexBufferResource8QueryInterfaceIUnknown(LPMODULE module)
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

    LPDIRECT3DVERTEXBUFFER8 vb = NULL;
    result = device->CreateVertexBuffer(1024, D3DUSAGE_WRITEONLY, D3DFVF_XYZRHW, D3DPOOL_DEFAULT, &vb);
    IsEqual(result, D3D_OK);
    IsNotEqual(vb, NULL);

    LPDIRECT3DRESOURCE8 res = NULL;
    result = vb->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, vb);

    LPUNKNOWN unk = NULL;
    result = res->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual(unk, NULL);
    IsEqual(res, unk);

    DIRECTRELEASE(unk);
    DIRECTRELEASE(res);
    DIRECTRELEASE(vb);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DCubeTextureResource8QueryInterfaceIUnknown(LPMODULE module)
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

    LPDIRECT3DCUBETEXTURE8 tex = NULL;
    result = device->CreateCubeTexture(256, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &tex);
    IsEqual(result, D3D_OK);
    IsNotEqual(tex, NULL);

    LPDIRECT3DRESOURCE8 res = NULL;
    result = tex->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, tex);

    LPUNKNOWN unk = NULL;
    result = res->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual(unk, NULL);
    IsEqual(res, unk);

    DIRECTRELEASE(unk);
    DIRECTRELEASE(res);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DTextureResource8QueryInterfaceIUnknown(LPMODULE module)
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

    LPDIRECT3DRESOURCE8 res = NULL;
    result = tex->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, tex);

    LPUNKNOWN unk = NULL;
    result = res->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual(unk, NULL);
    IsEqual(res, unk);

    DIRECTRELEASE(unk);
    DIRECTRELEASE(res);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DVolumeTextureResource8QueryInterfaceIUnknown(LPMODULE module)
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

    LPDIRECT3DRESOURCE8 res = NULL;
    result = tex->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, tex);

    LPUNKNOWN unk = NULL;
    result = res->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual(unk, NULL);
    IsEqual(res, unk);

    DIRECTRELEASE(unk); 
    DIRECTRELEASE(res);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DResource8QueryInterfaceIUnknown(LPMODULE module)
{
    Direct3DIndexBufferResource8QueryInterfaceIUnknown(module);
    Direct3DVertexBufferResource8QueryInterfaceIUnknown(module);
    Direct3DCubeTextureResource8QueryInterfaceIUnknown(module);
    Direct3DTextureResource8QueryInterfaceIUnknown(module);
    Direct3DVolumeTextureResource8QueryInterfaceIUnknown(module);
}

VOID Direct3DIndexBufferResource8Query(LPDIRECT3DRESOURCE8 res)
{
    LPDIRECT3D8 d3d = NULL;
    HRESULT result = res->QueryInterface(IID_IDirect3D8, (LPVOID*)&d3d);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3d, NULL);

    LPDIRECT3DDEVICE8 d3dd = NULL;
    result = res->QueryInterface(IID_IDirect3DDevice8, (LPVOID*)&d3dd);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dd, NULL);

    LPDIRECT3DRESOURCE8 d3dr = NULL;
    result = res->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&d3dr);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dr, res);
    DIRECTRELEASE(d3dr);

    LPDIRECT3DBASETEXTURE8 d3dbt = NULL;
    result = res->QueryInterface(IID_IDirect3DBaseTexture8, (LPVOID*)&d3dbt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dbt, NULL);

    LPDIRECT3DTEXTURE8 d3dt = NULL;
    result = res->QueryInterface(IID_IDirect3DTexture8, (LPVOID*)&d3dt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dt, NULL);

    LPDIRECT3DCUBETEXTURE8 d3dct = NULL;
    result = res->QueryInterface(IID_IDirect3DCubeTexture8, (LPVOID*)&d3dct);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dct, NULL);

    LPDIRECT3DVOLUMETEXTURE8 d3dvt = NULL;
    result = res->QueryInterface(IID_IDirect3DVolumeTexture8, (LPVOID*)&d3dvt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dvt, NULL);

    LPDIRECT3DVERTEXBUFFER8 d3dvb = NULL;
    result = res->QueryInterface(IID_IDirect3DVertexBuffer8, (LPVOID*)&d3dvb);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dvb, NULL);

    LPDIRECT3DINDEXBUFFER8 d3dib = NULL;
    result = res->QueryInterface(IID_IDirect3DIndexBuffer8, (LPVOID*)&d3dib);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dib, res);
    DIRECTRELEASE(d3dib);

    LPDIRECT3DSURFACE8 d3ds = NULL;
    result = res->QueryInterface(IID_IDirect3DSurface8, (LPVOID*)&d3ds);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3ds, NULL);

    LPDIRECT3DVOLUME8 d3dv = NULL;
    result = res->QueryInterface(IID_IDirect3DVolume8, (LPVOID*)&d3dv);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dv, NULL);

    LPDIRECT3DSWAPCHAIN8 d3dsc = NULL;
    result = res->QueryInterface(IID_IDirect3DSwapChain8, (LPVOID*)&d3dsc);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dsc, NULL);

    LPUNKNOWN unk = NULL;
    result = res->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual((LPVOID)unk, NULL);
    IsEqual((LPVOID)unk, res);
    DIRECTRELEASE(unk);
}

VOID Direct3DIndexBufferResource8QueryInterfaceAll(LPMODULE module)
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

    LPDIRECT3DINDEXBUFFER8 ib = NULL;
    result = device->CreateIndexBuffer(1024, D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &ib);
    IsEqual(result, D3D_OK);
    IsNotEqual(ib, NULL);

    LPDIRECT3DRESOURCE8 res = NULL;
    result = ib->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, ib);

    Direct3DIndexBufferResource8Query(res);

    DIRECTRELEASE(res);
    DIRECTRELEASE(ib);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DVertexBufferResource8Query(LPDIRECT3DRESOURCE8 res)
{
    LPDIRECT3D8 d3d = NULL;
    HRESULT result = res->QueryInterface(IID_IDirect3D8, (LPVOID*)&d3d);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3d, NULL);

    LPDIRECT3DDEVICE8 d3dd = NULL;
    result = res->QueryInterface(IID_IDirect3DDevice8, (LPVOID*)&d3dd);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dd, NULL);

    LPDIRECT3DRESOURCE8 d3dr = NULL;
    result = res->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&d3dr);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dr, res);
    DIRECTRELEASE(d3dr);

    LPDIRECT3DBASETEXTURE8 d3dbt = NULL;
    result = res->QueryInterface(IID_IDirect3DBaseTexture8, (LPVOID*)&d3dbt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dbt, NULL);

    LPDIRECT3DTEXTURE8 d3dt = NULL;
    result = res->QueryInterface(IID_IDirect3DTexture8, (LPVOID*)&d3dt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dt, NULL);

    LPDIRECT3DCUBETEXTURE8 d3dct = NULL;
    result = res->QueryInterface(IID_IDirect3DCubeTexture8, (LPVOID*)&d3dct);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dct, NULL);

    LPDIRECT3DVOLUMETEXTURE8 d3dvt = NULL;
    result = res->QueryInterface(IID_IDirect3DVolumeTexture8, (LPVOID*)&d3dvt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dvt, NULL);

    LPDIRECT3DVERTEXBUFFER8 d3dvb = NULL;
    result = res->QueryInterface(IID_IDirect3DVertexBuffer8, (LPVOID*)&d3dvb);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dvb, res);
    DIRECTRELEASE(d3dvb);

    LPDIRECT3DINDEXBUFFER8 d3dib = NULL;
    result = res->QueryInterface(IID_IDirect3DIndexBuffer8, (LPVOID*)&d3dib);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dib, NULL);

    LPDIRECT3DSURFACE8 d3ds = NULL;
    result = res->QueryInterface(IID_IDirect3DSurface8, (LPVOID*)&d3ds);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3ds, NULL);

    LPDIRECT3DVOLUME8 d3dv = NULL;
    result = res->QueryInterface(IID_IDirect3DVolume8, (LPVOID*)&d3dv);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dv, NULL);

    LPDIRECT3DSWAPCHAIN8 d3dsc = NULL;
    result = res->QueryInterface(IID_IDirect3DSwapChain8, (LPVOID*)&d3dsc);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dsc, NULL);

    LPUNKNOWN unk = NULL;
    result = res->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual((LPVOID)unk, NULL);
    IsEqual((LPVOID)unk, res);
    DIRECTRELEASE(unk);
}

VOID Direct3DVertexBufferResource8QueryInterfaceAll(LPMODULE module)
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

    LPDIRECT3DVERTEXBUFFER8 vb = NULL;
    result = device->CreateVertexBuffer(1024, D3DUSAGE_WRITEONLY, D3DFVF_XYZRHW, D3DPOOL_DEFAULT, &vb);
    IsEqual(result, D3D_OK);
    IsNotEqual(vb, NULL);

    LPDIRECT3DRESOURCE8 res = NULL;
    result = vb->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, vb);

    Direct3DVertexBufferResource8Query(res);

    DIRECTRELEASE(res);
    DIRECTRELEASE(vb);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DCubeTextureResource8Query(LPDIRECT3DRESOURCE8 res)
{
    LPDIRECT3D8 d3d = NULL;
    HRESULT result = res->QueryInterface(IID_IDirect3D8, (LPVOID*)&d3d);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3d, NULL);

    LPDIRECT3DDEVICE8 d3dd = NULL;
    result = res->QueryInterface(IID_IDirect3DDevice8, (LPVOID*)&d3dd);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dd, NULL);

    LPDIRECT3DRESOURCE8 d3dr = NULL;
    result = res->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&d3dr);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dr, res);
    DIRECTRELEASE(d3dr);

    LPDIRECT3DBASETEXTURE8 d3dbt = NULL;
    result = res->QueryInterface(IID_IDirect3DBaseTexture8, (LPVOID*)&d3dbt);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dbt, res);
    DIRECTRELEASE(d3dbt);

    LPDIRECT3DTEXTURE8 d3dt = NULL;
    result = res->QueryInterface(IID_IDirect3DTexture8, (LPVOID*)&d3dt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dt, NULL);

    LPDIRECT3DCUBETEXTURE8 d3dct = NULL;
    result = res->QueryInterface(IID_IDirect3DCubeTexture8, (LPVOID*)&d3dct);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dct, res);
    DIRECTRELEASE(d3dct);

    LPDIRECT3DVOLUMETEXTURE8 d3dvt = NULL;
    result = res->QueryInterface(IID_IDirect3DVolumeTexture8, (LPVOID*)&d3dvt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dvt, NULL);

    LPDIRECT3DVERTEXBUFFER8 d3dvb = NULL;
    result = res->QueryInterface(IID_IDirect3DVertexBuffer8, (LPVOID*)&d3dvb);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dvb, NULL);

    LPDIRECT3DINDEXBUFFER8 d3dib = NULL;
    result = res->QueryInterface(IID_IDirect3DIndexBuffer8, (LPVOID*)&d3dib);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dib, NULL);

    LPDIRECT3DSURFACE8 d3ds = NULL;
    result = res->QueryInterface(IID_IDirect3DSurface8, (LPVOID*)&d3ds);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3ds, NULL);

    LPDIRECT3DVOLUME8 d3dv = NULL;
    result = res->QueryInterface(IID_IDirect3DVolume8, (LPVOID*)&d3dv);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dv, NULL);

    LPDIRECT3DSWAPCHAIN8 d3dsc = NULL;
    result = res->QueryInterface(IID_IDirect3DSwapChain8, (LPVOID*)&d3dsc);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dsc, NULL);

    LPUNKNOWN unk = NULL;
    result = res->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual((LPVOID)unk, NULL);
    IsEqual((LPVOID)unk, res);
    DIRECTRELEASE(unk);
}

VOID Direct3DCubeTextureResource8QueryInterfaceAll(LPMODULE module)
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

    LPDIRECT3DCUBETEXTURE8 tex = NULL;
    result = device->CreateCubeTexture(256, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &tex);
    IsEqual(result, D3D_OK);
    IsNotEqual(tex, NULL);

    LPDIRECT3DRESOURCE8 res = NULL;
    result = tex->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, tex);

    Direct3DCubeTextureResource8Query(res);

    DIRECTRELEASE(res);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DTextureResource8Query(LPDIRECT3DRESOURCE8 res)
{
    LPDIRECT3D8 d3d = NULL;
    HRESULT result = res->QueryInterface(IID_IDirect3D8, (LPVOID*)&d3d);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3d, NULL);

    LPDIRECT3DDEVICE8 d3dd = NULL;
    result = res->QueryInterface(IID_IDirect3DDevice8, (LPVOID*)&d3dd);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dd, NULL);

    LPDIRECT3DRESOURCE8 d3dr = NULL;
    result = res->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&d3dr);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dr, res);
    DIRECTRELEASE(d3dr);

    LPDIRECT3DBASETEXTURE8 d3dbt = NULL;
    result = res->QueryInterface(IID_IDirect3DBaseTexture8, (LPVOID*)&d3dbt);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dbt, res);
    DIRECTRELEASE(d3dbt);

    LPDIRECT3DTEXTURE8 d3dt = NULL;
    result = res->QueryInterface(IID_IDirect3DTexture8, (LPVOID*)&d3dt);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dt, res);
    DIRECTRELEASE(d3dt);

    LPDIRECT3DCUBETEXTURE8 d3dct = NULL;
    result = res->QueryInterface(IID_IDirect3DCubeTexture8, (LPVOID*)&d3dct);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dct, NULL);

    LPDIRECT3DVOLUMETEXTURE8 d3dvt = NULL;
    result = res->QueryInterface(IID_IDirect3DVolumeTexture8, (LPVOID*)&d3dvt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dvt, NULL);

    LPDIRECT3DVERTEXBUFFER8 d3dvb = NULL;
    result = res->QueryInterface(IID_IDirect3DVertexBuffer8, (LPVOID*)&d3dvb);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dvb, NULL);

    LPDIRECT3DINDEXBUFFER8 d3dib = NULL;
    result = res->QueryInterface(IID_IDirect3DIndexBuffer8, (LPVOID*)&d3dib);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dib, NULL);

    LPDIRECT3DSURFACE8 d3ds = NULL;
    result = res->QueryInterface(IID_IDirect3DSurface8, (LPVOID*)&d3ds);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3ds, NULL);

    LPDIRECT3DVOLUME8 d3dv = NULL;
    result = res->QueryInterface(IID_IDirect3DVolume8, (LPVOID*)&d3dv);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dv, NULL);

    LPDIRECT3DSWAPCHAIN8 d3dsc = NULL;
    result = res->QueryInterface(IID_IDirect3DSwapChain8, (LPVOID*)&d3dsc);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dsc, NULL);

    LPUNKNOWN unk = NULL;
    result = res->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual((LPVOID)unk, NULL);
    IsEqual((LPVOID)unk, res);
    DIRECTRELEASE(unk);
}

VOID Direct3DTextureResource8QueryInterfaceAll(LPMODULE module)
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

    LPDIRECT3DRESOURCE8 res = NULL;
    result = tex->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, tex);

    Direct3DTextureResource8Query(res);

    DIRECTRELEASE(res);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DVolumeTextureResource8Query(LPDIRECT3DRESOURCE8 res)
{
    LPDIRECT3D8 d3d = NULL;
    HRESULT result = res->QueryInterface(IID_IDirect3D8, (LPVOID*)&d3d);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3d, NULL);

    LPDIRECT3DDEVICE8 d3dd = NULL;
    result = res->QueryInterface(IID_IDirect3DDevice8, (LPVOID*)&d3dd);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dd, NULL);

    LPDIRECT3DRESOURCE8 d3dr = NULL;
    result = res->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&d3dr);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dr, res);
    DIRECTRELEASE(d3dr);

    LPDIRECT3DBASETEXTURE8 d3dbt = NULL;
    result = res->QueryInterface(IID_IDirect3DBaseTexture8, (LPVOID*)&d3dbt);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dbt, res);
    DIRECTRELEASE(d3dbt);

    LPDIRECT3DTEXTURE8 d3dt = NULL;
    result = res->QueryInterface(IID_IDirect3DTexture8, (LPVOID*)&d3dt);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dt, NULL);

    LPDIRECT3DCUBETEXTURE8 d3dct = NULL;
    result = res->QueryInterface(IID_IDirect3DCubeTexture8, (LPVOID*)&d3dct);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dct, NULL);

    LPDIRECT3DVOLUMETEXTURE8 d3dvt = NULL;
    result = res->QueryInterface(IID_IDirect3DVolumeTexture8, (LPVOID*)&d3dvt);
    IsEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dvt, res);
    DIRECTRELEASE(d3dvt);

    LPDIRECT3DVERTEXBUFFER8 d3dvb = NULL;
    result = res->QueryInterface(IID_IDirect3DVertexBuffer8, (LPVOID*)&d3dvb);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dvb, NULL);

    LPDIRECT3DINDEXBUFFER8 d3dib = NULL;
    result = res->QueryInterface(IID_IDirect3DIndexBuffer8, (LPVOID*)&d3dib);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dib, NULL);

    LPDIRECT3DSURFACE8 d3ds = NULL;
    result = res->QueryInterface(IID_IDirect3DSurface8, (LPVOID*)&d3ds);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3ds, NULL);

    LPDIRECT3DVOLUME8 d3dv = NULL;
    result = res->QueryInterface(IID_IDirect3DVolume8, (LPVOID*)&d3dv);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dv, NULL);

    LPDIRECT3DSWAPCHAIN8 d3dsc = NULL;
    result = res->QueryInterface(IID_IDirect3DSwapChain8, (LPVOID*)&d3dsc);
    IsNotEqual(result, D3D_OK);
    IsEqual((LPVOID)d3dsc, NULL);

    LPUNKNOWN unk = NULL;
    result = res->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, D3D_OK);
    IsNotEqual((LPVOID)unk, NULL);
    IsEqual((LPVOID)unk, res);
    DIRECTRELEASE(unk);
}

VOID Direct3DVolumeTextureResource8QueryInterfaceAll(LPMODULE module)
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

    LPDIRECT3DRESOURCE8 res = NULL;
    result = tex->QueryInterface(IID_IDirect3DResource8, (LPVOID*)&res);
    IsEqual(result, D3D_OK);
    IsNotEqual(res, NULL);
    IsEqual(res, tex);

    Direct3DVolumeTextureResource8Query(res);

    DIRECTRELEASE(res);
    DIRECTRELEASE(tex);
    DIRECTRELEASE(device);
    DIRECTRELEASE(d3d);

    ReleaseWindow(hwnd);
}

VOID Direct3DResource8QueryInterfaceAll(LPMODULE module)
{
    Direct3DIndexBufferResource8QueryInterfaceAll(module);
    Direct3DVertexBufferResource8QueryInterfaceAll(module);
    Direct3DCubeTextureResource8QueryInterfaceAll(module);
    Direct3DTextureResource8QueryInterfaceAll(module);
    Direct3DVolumeTextureResource8QueryInterfaceAll(module);
}