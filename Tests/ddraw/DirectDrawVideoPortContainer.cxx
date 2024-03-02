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

#include "DirectDrawVideoPortContainer.hxx"

VOID DirectDrawCreateVideoPortContainer(LPMODULE module)
{
    LPDIRECTDRAW dd1 = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd1, NULL);
    IsEqual(result, DD_OK);

    LPDDVIDEOPORTCONTAINER vpc = NULL;
    result = dd1->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc);
    IsEqual(result, DD_OK);

    vpc->AddRef();
    IsEqual(vpc->Release(), 1);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(vpc);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);
}

VOID DirectDraw2CreateVideoPortContainer(LPMODULE module)
{
    LPDIRECTDRAW dd1 = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd1, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW2 dd2 = NULL;
    result = dd1->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsEqual(result, DD_OK);

    LPDDVIDEOPORTCONTAINER vpc = NULL;
    result = dd2->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc);
    IsEqual(result, DD_OK);

    vpc->AddRef();
    IsEqual(vpc->Release(), 1);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(vpc);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);

    dd2->AddRef();
    IsEqual(dd2->Release(), 1);

    DIRECTRELEASE(dd2);
}

VOID DirectDraw4CreateVideoPortContainer(LPMODULE module)
{
    LPDIRECTDRAW dd1 = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd1, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW4 dd4 = NULL;
    result = dd1->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsEqual(result, DD_OK);

    LPDDVIDEOPORTCONTAINER vpc = NULL;
    result = dd4->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc);
    IsEqual(result, DD_OK);

    vpc->AddRef();
    IsEqual(vpc->Release(), 1);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(vpc);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);

    dd4->AddRef();
    IsEqual(dd4->Release(), 1);

    DIRECTRELEASE(dd4);
}

VOID DirectDraw7CreateVideoPortContainer(LPMODULE module)
{
    LPDIRECTDRAW7 dd7 = NULL;
    HRESULT result = module->DirectDrawCreateEx(NULL, (LPVOID*)&dd7, IID_IDirectDraw7, NULL);
    IsEqual(result, DD_OK);

    LPDDVIDEOPORTCONTAINER vpc = NULL;
    result = dd7->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc);
    IsEqual(result, DD_OK);

    vpc->AddRef();
    IsEqual(vpc->Release(), 1);

    dd7->AddRef();
    IsEqual(dd7->Release(), 1);

    DIRECTRELEASE(vpc);

    dd7->AddRef();
    IsEqual(dd7->Release(), 1);

    DIRECTRELEASE(dd7);
}

VOID DirectDrawVideoPortContainerQueryInterfaceIUnknown(LPMODULE module)
{
    LPDIRECTDRAW dd1 = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd1, NULL);
    IsEqual(result, DD_OK);

    LPDDVIDEOPORTCONTAINER vpc = NULL;
    result = dd1->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc);
    IsEqual(result, DD_OK);

    vpc->AddRef();
    IsEqual(vpc->Release(), 1);

    LPUNKNOWN unk = NULL;
    result = vpc->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);
    
    IsNotEqual(vpc, unk);
    IsEqual(dd1, unk);

    dd1->AddRef();
    IsEqual(dd1->Release(), 2);

    DIRECTRELEASE(vpc);
    DIRECTRELEASE(unk);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);
}

VOID DirectDraw2VideoPortContainerQueryInterfaceIUnknown(LPMODULE module)
{
    LPDIRECTDRAW dd1 = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd1, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW2 dd2 = NULL;
    result = dd1->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsEqual(result, DD_OK);

    LPDDVIDEOPORTCONTAINER vpc = NULL;
    result = dd2->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc);
    IsEqual(result, DD_OK);

    vpc->AddRef();
    IsEqual(vpc->Release(), 1);

    LPUNKNOWN unk = NULL;
    result = vpc->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);

    IsNotEqual(vpc, unk);
    IsEqual(dd1, unk);

    dd1->AddRef();
    IsEqual(dd1->Release(), 2);

    DIRECTRELEASE(vpc);
    DIRECTRELEASE(unk);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);

    dd2->AddRef();
    IsEqual(dd2->Release(), 1);

    DIRECTRELEASE(dd2);
}

VOID DirectDraw4VideoPortContainerQueryInterfaceIUnknown(LPMODULE module)
{
    LPDIRECTDRAW dd1 = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd1, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW4 dd4 = NULL;
    result = dd1->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsEqual(result, DD_OK);

    LPDDVIDEOPORTCONTAINER vpc = NULL;
    result = dd4->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc);
    IsEqual(result, DD_OK);

    vpc->AddRef();
    IsEqual(vpc->Release(), 1);

    LPUNKNOWN unk = NULL;
    result = vpc->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);

    IsNotEqual(vpc, unk);
    IsEqual(dd1, unk);

    dd1->AddRef();
    IsEqual(dd1->Release(), 2);

    DIRECTRELEASE(vpc);
    DIRECTRELEASE(unk);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);

    dd4->AddRef();
    IsEqual(dd4->Release(), 1);

    DIRECTRELEASE(dd4);
}

VOID DirectDraw7VideoPortContainerQueryInterfaceIUnknown(LPMODULE module)
{
    LPDIRECTDRAW7 dd7 = NULL;
    HRESULT result = module->DirectDrawCreateEx(NULL, (LPVOID*)&dd7, IID_IDirectDraw7, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW dd1 = NULL;
    result = dd7->QueryInterface(IID_IDirectDraw, (LPVOID*)&dd1);
    IsEqual(result, DD_OK);

    LPDDVIDEOPORTCONTAINER vpc = NULL;
    result = dd7->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc);
    IsEqual(result, DD_OK);

    vpc->AddRef();
    IsEqual(vpc->Release(), 1);

    LPUNKNOWN unk = NULL;
    result = vpc->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);

    IsNotEqual(vpc, unk);
    IsNotEqual(dd7, unk);
    IsEqual(dd1, unk);

    dd7->AddRef();
    IsEqual(dd7->Release(), 1);

    DIRECTRELEASE(vpc);
    DIRECTRELEASE(unk);

    dd7->AddRef();
    IsEqual(dd7->Release(), 1);

    DIRECTRELEASE(dd7);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);
}

VOID DirectDrawVideoPortContainerQueryInterfaceVideoPortContainer(LPMODULE module)
{
    LPDIRECTDRAW dd1 = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd1, NULL);
    IsEqual(result, DD_OK);

    LPDDVIDEOPORTCONTAINER vpc1 = NULL;
    result = dd1->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc1);
    IsEqual(result, DD_OK);

    vpc1->AddRef();
    IsEqual(vpc1->Release(), 1);

    LPUNKNOWN unk = NULL;
    result = vpc1->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);

    IsNotEqual(vpc1, unk);
    IsEqual(dd1, unk);

    LPDDVIDEOPORTCONTAINER vpc2 = NULL;
    result = unk->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc2);
    IsEqual(result, DD_OK);

    IsEqual(vpc1, vpc2);

    vpc2->AddRef();
    IsEqual(vpc2->Release(), 2);

    dd1->AddRef();
    IsEqual(dd1->Release(), 2);

    DIRECTRELEASE(vpc2);
    DIRECTRELEASE(vpc1);
    DIRECTRELEASE(unk);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);
}

VOID DirectDraw2VideoPortContainerQueryInterfaceVideoPortContainer(LPMODULE module)
{
    LPDIRECTDRAW dd1 = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd1, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW2 dd2 = NULL;
    result = dd1->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsEqual(result, DD_OK);

    LPDDVIDEOPORTCONTAINER vpc1 = NULL;
    result = dd2->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc1);
    IsEqual(result, DD_OK);

    vpc1->AddRef();
    IsEqual(vpc1->Release(), 1);

    LPUNKNOWN unk = NULL;
    result = vpc1->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);

    IsNotEqual(vpc1, unk);
    IsEqual(dd1, unk);

    LPDDVIDEOPORTCONTAINER vpc2 = NULL;
    result = unk->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc2);
    IsEqual(result, DD_OK);

    IsEqual(vpc1, vpc2);

    vpc2->AddRef();
    IsEqual(vpc2->Release(), 2);

    dd1->AddRef();
    IsEqual(dd1->Release(), 2);

    DIRECTRELEASE(vpc2);
    DIRECTRELEASE(vpc1);
    DIRECTRELEASE(unk);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);

    dd2->AddRef();
    IsEqual(dd2->Release(), 1);

    DIRECTRELEASE(dd2);
}

VOID DirectDraw4VideoPortContainerQueryInterfaceVideoPortContainer(LPMODULE module)
{
    LPDIRECTDRAW dd1 = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd1, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW4 dd4 = NULL;
    result = dd1->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsEqual(result, DD_OK);

    LPDDVIDEOPORTCONTAINER vpc1 = NULL;
    result = dd4->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc1);
    IsEqual(result, DD_OK);

    vpc1->AddRef();
    IsEqual(vpc1->Release(), 1);

    LPUNKNOWN unk = NULL;
    result = vpc1->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);

    IsNotEqual(vpc1, unk);
    IsEqual(dd1, unk);

    LPDDVIDEOPORTCONTAINER vpc2 = NULL;
    result = unk->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc2);
    IsEqual(result, DD_OK);

    IsEqual(vpc1, vpc2);

    vpc2->AddRef();
    IsEqual(vpc2->Release(), 2);

    dd1->AddRef();
    IsEqual(dd1->Release(), 2);

    DIRECTRELEASE(vpc2);
    DIRECTRELEASE(vpc1);
    DIRECTRELEASE(unk);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);

    dd4->AddRef();
    IsEqual(dd4->Release(), 1);

    DIRECTRELEASE(dd4);
}

VOID DirectDraw7VideoPortContainerQueryInterfaceVideoPortContainer(LPMODULE module)
{
    LPDIRECTDRAW7 dd7 = NULL;
    HRESULT result = module->DirectDrawCreateEx(NULL, (LPVOID*)&dd7, IID_IDirectDraw7, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW dd1 = NULL;
    result = dd7->QueryInterface(IID_IDirectDraw, (LPVOID*)&dd1);
    IsEqual(result, DD_OK);

    LPDDVIDEOPORTCONTAINER vpc1 = NULL;
    result = dd7->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc1);
    IsEqual(result, DD_OK);

    vpc1->AddRef();
    IsEqual(vpc1->Release(), 1);

    LPUNKNOWN unk = NULL;
    result = vpc1->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);

    IsNotEqual(vpc1, unk);
    IsNotEqual(dd7, unk);
    IsEqual(dd1, unk);

    LPDDVIDEOPORTCONTAINER vpc2 = NULL;
    result = unk->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc2);
    IsEqual(result, DD_OK);

    IsEqual(vpc1, vpc2);

    vpc2->AddRef();
    IsEqual(vpc2->Release(), 2);

    dd7->AddRef();
    IsEqual(dd7->Release(), 1);

    DIRECTRELEASE(vpc2);
    DIRECTRELEASE(vpc1);
    DIRECTRELEASE(unk);

    dd7->AddRef();
    IsEqual(dd7->Release(), 1);

    DIRECTRELEASE(dd7);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);
}

VOID DirectDrawVideoPortContainerQuery(LPDDVIDEOPORTCONTAINER container, const BOOL seven)
{
    /* Direct3D */

    LPDIRECT3D dd3d1 = NULL;
    HRESULT result = container->QueryInterface(IID_IDirect3D, (LPVOID*)&dd3d1);

    if (seven)
    {
        IsNotEqual(result, DD_OK);
        IsEqual((LPVOID)dd3d1, NULL);
    }
    else
    {
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)container, (LPVOID)dd3d1);
        DIRECTRELEASE(dd3d1);
    }

    LPDIRECT3D2 dd3d2 = NULL;
    result = container->QueryInterface(IID_IDirect3D2, (LPVOID*)&dd3d2);

    if (seven)
    {
        IsNotEqual(result, DD_OK);
        IsEqual((LPVOID)dd3d2, NULL);
    }
    else
    {
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)container, (LPVOID)dd3d2);
        DIRECTRELEASE(dd3d2);
    }

    LPDIRECT3D3 dd3d3 = NULL;
    result = container->QueryInterface(IID_IDirect3D3, (LPVOID*)&dd3d3);

    if (seven)
    {
        IsNotEqual(result, DD_OK);
        IsEqual((LPVOID)dd3d3, NULL);
    }
    else
    {
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)container, (LPVOID)dd3d3);
        DIRECTRELEASE(dd3d3);
    }

    LPDIRECT3D3 dd3d7 = NULL;
    result = container->QueryInterface(IID_IDirect3D7, (LPVOID*)&dd3d7);

    if (seven)
    {
        IsEqual(result, DD_OK);
        IsNotEqual((LPVOID)container, (LPVOID)dd3d7);
        DIRECTRELEASE(dd3d7);
    }
    else
    {
        IsNotEqual(result, DD_OK);
        IsEqual((LPVOID)dd3d7, NULL);
    }

    /* Direct3DDevice */

    LPDIRECT3DDEVICE dd3dd1 = NULL;
    result = container->QueryInterface(IID_IDirect3DDevice, (LPVOID*)&dd3dd1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    LPDIRECT3DDEVICE2 dd3dd2 = NULL;
    result = container->QueryInterface(IID_IDirect3DDevice2, (LPVOID*)&dd3dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd2, NULL);

    LPDIRECT3DDEVICE3 dd3dd3 = NULL;
    result = container->QueryInterface(IID_IDirect3DDevice3, (LPVOID*)&dd3dd3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd3, NULL);

    LPDIRECT3DDEVICE7 dd3dd7 = NULL;
    result = container->QueryInterface(IID_IDirect3DDevice7, (LPVOID*)&dd3dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd7, NULL);

    LPDIRECT3DDEVICE d3drd = NULL;
    result = container->QueryInterface(IID_IDirect3DRampDevice, (LPVOID*)&d3drd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drd, NULL);

    LPDIRECT3DDEVICE d3drgbd = NULL;
    result = container->QueryInterface(IID_IDirect3DRGBDevice, (LPVOID*)&d3drgbd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drgbd, NULL);

    LPDIRECT3DDEVICE d3dhald = NULL;
    result = container->QueryInterface(IID_IDirect3DHALDevice, (LPVOID*)&d3dhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dhald, NULL);

    LPDIRECT3DDEVICE d3dmmxd = NULL;
    result = container->QueryInterface(IID_IDirect3DMMXDevice, (LPVOID*)&d3dmmxd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dmmxd, NULL);

    LPDIRECT3DDEVICE d3drefd = NULL;
    result = container->QueryInterface(IID_IDirect3DRefDevice, (LPVOID*)&d3drefd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drefd, NULL);

    LPDIRECT3DDEVICE d3dnd = NULL;
    result = container->QueryInterface(IID_IDirect3DNullDevice, (LPVOID*)&d3dnd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dnd, NULL);

    LPDIRECT3DDEVICE d3dtnlhald = NULL;
    result = container->QueryInterface(IID_IDirect3DTnLHalDevice, (LPVOID*)&d3dtnlhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dtnlhald, NULL);

    /* Direct3DExecuteBuffer */

    LPDIRECT3DEXECUTEBUFFER d3deb = NULL;
    result = container->QueryInterface(IID_IDirect3DExecuteBuffer, (LPVOID*)&d3deb);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    /* Direct3DLight */
    LPDIRECT3DLIGHT d3dl = NULL;
    result = container->QueryInterface(IID_IDirect3DLight, (LPVOID*)&d3dl);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dl, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dm1 = NULL;
    result = container->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dm1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm1, NULL);

    LPDIRECT3DMATERIAL2 d3dm2 = NULL;
    result = container->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dm2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm2, NULL);

    LPDIRECT3DMATERIAL3 d3dm3 = NULL;
    result = container->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dm3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm3, NULL);

    /* Direct3DTexture */

    LPDIRECT3DTEXTURE d3dt1 = NULL;
    result = container->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&d3dt1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt1, NULL);

    LPDIRECT3DTEXTURE2 d3dt2 = NULL;
    result = container->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&d3dt2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt2, NULL);

    /* Direct3DVertexBuffer */

    LPDIRECT3DVERTEXBUFFER d3dvb1 = NULL;
    result = container->QueryInterface(IID_IDirect3DVertexBuffer, (LPVOID*)&d3dvb1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb1, NULL);

    LPDIRECT3DVERTEXBUFFER7 d3dvb7 = NULL;
    result = container->QueryInterface(IID_IDirect3DVertexBuffer7, (LPVOID*)&d3dvb7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb7, NULL);

    /* Direct3DViewport */

    LPDIRECT3DVIEWPORT d3dvp1 = NULL;
    result = container->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&d3dvp1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvp1, NULL);

    LPDIRECT3DVIEWPORT2 d3dvp2 = NULL;
    result = container->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&d3dvp2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvp2, NULL);

    LPDIRECT3DVIEWPORT3 d3dvp3 = NULL;
    result = container->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&d3dvp3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvp3, NULL);

    /* DirectDraw */

    LPDIRECTDRAW dd = NULL;
    result = container->QueryInterface(IID_IDirectDraw, (LPVOID*)&dd);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)container, (LPVOID)dd);
    DIRECTRELEASE(dd);

    LPDIRECTDRAW2 dd2 = NULL;
    result = container->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)container, (LPVOID)dd2);
    DIRECTRELEASE(dd2);

    LPDIRECTDRAW4 dd4 = NULL;
    result = container->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)container, (LPVOID)dd4);
    DIRECTRELEASE(dd4);

    LPDIRECTDRAW7 dd7 = NULL;
    result = container->QueryInterface(IID_IDirectDraw7, (LPVOID*)&dd7);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)container, (LPVOID)dd7);
    DIRECTRELEASE(dd7);

    /* DirectDrawClipper */

    LPDIRECTDRAWCLIPPER ddc = NULL;
    result = container->QueryInterface(IID_IDirectDrawClipper, (LPVOID*)&ddc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddc, NULL);

    /* DirectDrawColorControl */

    LPDIRECTDRAWCOLORCONTROL ddcc = NULL;
    result = container->QueryInterface(IID_IDirectDrawColorControl, (LPVOID*)&ddcc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddcc, NULL);

    /* DirectDrawGammaControl */

    LPDIRECTDRAWGAMMACONTROL ddgc = NULL;
    result = container->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&ddgc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddgc, NULL);

    /* DirectDrawPalette */

    LPDIRECTDRAWPALETTE ddp = NULL;
    result = container->QueryInterface(IID_IDirectDrawPalette, (LPVOID*)&ddp);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddp, NULL);

    /* DirectDrawSurface */

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = container->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds1, NULL);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = container->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds2, NULL);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = container->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds3, NULL);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = container->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds4, NULL);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = container->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds7, NULL);

    /* DirectDrawVideoPort */
    LPDIRECTDRAWVIDEOPORT ddvp = NULL;
    result = container->QueryInterface(IID_IDirectDrawVideoPort, (LPVOID*)&ddvp);
    IsNotEqual(result, DD_OK);
    IsEqual(ddvp, NULL);

    /* DirectDrawVideoPortContainer */

    LPDDVIDEOPORTCONTAINER ddvpc = NULL;
    result = container->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&ddvpc);
    IsEqual(result, DD_OK);
    IsEqual(container, ddvpc);
    DIRECTRELEASE(ddvpc);

    /* DirectDrawVideoPortNotify */

    LPDDVIDEOPORTNOTIFY ddvpn = NULL;
    result = container->QueryInterface(IID_IDirectDrawVideoPortNotify, (LPVOID*)&ddvpn);
    IsNotEqual(result, DD_OK);

    /* Unknown */

    LPUNKNOWN unk = NULL;
    result = container->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);
    IsNotEqual(container, unk);
    DIRECTRELEASE(unk);
}

VOID DirectDrawVideoPortContainerQueryInterfaceAll(LPMODULE module)
{
    LPDIRECTDRAW dd1 = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd1, NULL);
    IsEqual(result, DD_OK);

    LPDDVIDEOPORTCONTAINER vpc = NULL;
    result = dd1->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc);
    IsEqual(result, DD_OK);

    DirectDrawVideoPortContainerQuery(vpc, FALSE);

    vpc->AddRef();
    IsEqual(vpc->Release(), 1);

    DIRECTRELEASE(vpc);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);
}

VOID DirectDraw2VideoPortContainerQueryInterfaceAll(LPMODULE module)
{
    LPDIRECTDRAW dd1 = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd1, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW2 dd2 = NULL;
    result = dd1->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsEqual(result, DD_OK);

    LPDDVIDEOPORTCONTAINER vpc = NULL;
    result = dd2->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc);
    IsEqual(result, DD_OK);

    DirectDrawVideoPortContainerQuery(vpc, FALSE);

    vpc->AddRef();
    IsEqual(vpc->Release(), 1);

    DIRECTRELEASE(vpc);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);

    dd2->AddRef();
    IsEqual(dd2->Release(), 1);

    DIRECTRELEASE(dd2);
}

VOID DirectDraw4VideoPortContainerQueryInterfaceAll(LPMODULE module)
{
    LPDIRECTDRAW dd1 = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd1, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW4 dd4 = NULL;
    result = dd1->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsEqual(result, DD_OK);

    LPDDVIDEOPORTCONTAINER vpc = NULL;
    result = dd4->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc);
    IsEqual(result, DD_OK);

    DirectDrawVideoPortContainerQuery(vpc, FALSE);

    vpc->AddRef();
    IsEqual(vpc->Release(), 1);

    DIRECTRELEASE(vpc);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);

    dd4->AddRef();
    IsEqual(dd4->Release(), 1);

    DIRECTRELEASE(dd4);
}

VOID DirectDraw7VideoPortContainerQueryInterfaceAll(LPMODULE module)
{
    LPDIRECTDRAW7 dd7 = NULL;
    HRESULT result = module->DirectDrawCreateEx(NULL, (LPVOID*)&dd7, IID_IDirectDraw7, NULL);
    IsEqual(result, DD_OK);

    LPDDVIDEOPORTCONTAINER vpc = NULL;
    result = dd7->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&vpc);
    IsEqual(result, DD_OK);

    DirectDrawVideoPortContainerQuery(vpc, TRUE);

    vpc->AddRef();
    IsEqual(vpc->Release(), 1);

    DIRECTRELEASE(vpc);

    dd7->AddRef();
    IsEqual(dd7->Release(), 1);

    DIRECTRELEASE(dd7);
}