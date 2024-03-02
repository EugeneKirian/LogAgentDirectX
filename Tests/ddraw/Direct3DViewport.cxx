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

#include "Direct3DViewport.hxx"

VOID DirectDrawCreateViewport(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECT3D d3d1 = NULL;
    result = dd->QueryInterface(IID_IDirect3D, (LPVOID*)&d3d1);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT vp11 = NULL;
    result = d3d1->CreateViewport(&vp11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);

    LPDIRECT3DVIEWPORT2 vp12 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPDIRECT3DVIEWPORT3 vp13 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp13, NULL);
    IsEqual((LPVOID)vp12, (LPVOID)vp13);
    IsEqual((LPVOID)vp11, (LPVOID)vp13);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT2 vp22 = NULL;
    result = d3d2->CreateViewport(&vp22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp22, NULL);
    IsNotEqual(vp11, vp22);

    LPDIRECT3DVIEWPORT vp21 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPDIRECT3DVIEWPORT3 vp23 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp23, NULL);
    IsEqual((LPVOID)vp22, (LPVOID)vp23);
    IsEqual((LPVOID)vp21, (LPVOID)vp23);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT3 vp33 = NULL;
    result = d3d3->CreateViewport(&vp33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp33, NULL);

    IsNotEqual(vp11, vp33);
    IsNotEqual(vp22, vp33);

    LPDIRECT3DVIEWPORT vp31 = NULL;
    result = vp33->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp33, (LPVOID)vp31);

    LPDIRECT3DVIEWPORT2 vp32 = NULL;
    result = vp33->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp32, NULL);
    IsEqual((LPVOID)vp32, (LPVOID)vp33);
    IsEqual((LPVOID)vp32, (LPVOID)vp31);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DIRECTRELEASE(vp31);
    DIRECTRELEASE(vp32);
    DIRECTRELEASE(vp33);
    DIRECTRELEASE(vp21);
    DIRECTRELEASE(vp22);
    DIRECTRELEASE(vp23);
    DIRECTRELEASE(vp13);
    DIRECTRELEASE(vp12);
    DIRECTRELEASE(vp11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd);
}

VOID DirectDraw2CreateViewport(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW2 dd2 = NULL;
    result = dd->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsEqual(result, DD_OK);

    LPDIRECT3D d3d1 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D, (LPVOID*)&d3d1);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT vp11 = NULL;
    result = d3d1->CreateViewport(&vp11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);

    LPDIRECT3DVIEWPORT2 vp12 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPDIRECT3DVIEWPORT3 vp13 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp13, NULL);
    IsEqual((LPVOID)vp12, (LPVOID)vp13);
    IsEqual((LPVOID)vp11, (LPVOID)vp13);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT2 vp22 = NULL;
    result = d3d2->CreateViewport(&vp22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp22, NULL);
    IsNotEqual(vp11, vp22);

    LPDIRECT3DVIEWPORT vp21 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPDIRECT3DVIEWPORT3 vp23 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp23, NULL);
    IsEqual((LPVOID)vp22, (LPVOID)vp23);
    IsEqual((LPVOID)vp21, (LPVOID)vp23);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT3 vp33 = NULL;
    result = d3d3->CreateViewport(&vp33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp33, NULL);

    IsNotEqual(vp11, vp33);
    IsNotEqual(vp22, vp33);

    LPDIRECT3DVIEWPORT vp31 = NULL;
    result = vp33->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp33, (LPVOID)vp31);

    LPDIRECT3DVIEWPORT2 vp32 = NULL;
    result = vp33->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp32, NULL);
    IsEqual((LPVOID)vp32, (LPVOID)vp33);
    IsEqual((LPVOID)vp32, (LPVOID)vp31);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DIRECTRELEASE(vp31);
    DIRECTRELEASE(vp32);
    DIRECTRELEASE(vp33);
    DIRECTRELEASE(vp21);
    DIRECTRELEASE(vp22);
    DIRECTRELEASE(vp23);
    DIRECTRELEASE(vp13);
    DIRECTRELEASE(vp12);
    DIRECTRELEASE(vp11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd2);
    DIRECTRELEASE(dd);
}

VOID DirectDraw4CreateViewport(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW4 dd4 = NULL;
    result = dd->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsEqual(result, DD_OK);

    LPDIRECT3D d3d1 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D, (LPVOID*)&d3d1);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT vp11 = NULL;
    result = d3d1->CreateViewport(&vp11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);

    LPDIRECT3DVIEWPORT2 vp12 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPDIRECT3DVIEWPORT3 vp13 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp13, NULL);
    IsEqual((LPVOID)vp12, (LPVOID)vp13);
    IsEqual((LPVOID)vp11, (LPVOID)vp13);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT2 vp22 = NULL;
    result = d3d2->CreateViewport(&vp22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp22, NULL);
    IsNotEqual(vp11, vp22);

    LPDIRECT3DVIEWPORT vp21 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPDIRECT3DVIEWPORT3 vp23 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp23, NULL);
    IsEqual((LPVOID)vp22, (LPVOID)vp23);
    IsEqual((LPVOID)vp21, (LPVOID)vp23);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT3 vp33 = NULL;
    result = d3d3->CreateViewport(&vp33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp33, NULL);

    IsNotEqual(vp11, vp33);
    IsNotEqual(vp22, vp33);

    LPDIRECT3DVIEWPORT vp31 = NULL;
    result = vp33->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp33, (LPVOID)vp31);

    LPDIRECT3DVIEWPORT2 vp32 = NULL;
    result = vp33->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp32, NULL);
    IsEqual((LPVOID)vp32, (LPVOID)vp33);
    IsEqual((LPVOID)vp32, (LPVOID)vp31);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DIRECTRELEASE(vp31);
    DIRECTRELEASE(vp32);
    DIRECTRELEASE(vp33);
    DIRECTRELEASE(vp21);
    DIRECTRELEASE(vp22);
    DIRECTRELEASE(vp23);
    DIRECTRELEASE(vp13);
    DIRECTRELEASE(vp12);
    DIRECTRELEASE(vp11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd4);
    DIRECTRELEASE(dd);
}

VOID DirectDraw7CreateViewport(LPMODULE module)
{
    LPDIRECTDRAW7 dd7 = NULL;
    HRESULT result = module->DirectDrawCreateEx(NULL, (LPVOID*)&dd7, IID_IDirectDraw7, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW dd = NULL;
    result = dd7->QueryInterface(IID_IDirectDraw, (LPVOID*)&dd);
    IsEqual(result, DD_OK);

    LPDIRECT3D d3d1 = NULL;
    result = dd->QueryInterface(IID_IDirect3D, (LPVOID*)&d3d1);
    IsNotEqual(result, DD_OK);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsNotEqual(result, DD_OK);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsNotEqual(result, DD_OK);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3d7, NULL);

    DIRECTRELEASE(d3d7);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd);
    DIRECTRELEASE(dd7);
}

VOID DirectDrawCreateViewportQueryInterfaceIUnknown(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECT3D d3d1 = NULL;
    result = dd->QueryInterface(IID_IDirect3D, (LPVOID*)&d3d1);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT vp11 = NULL;
    result = d3d1->CreateViewport(&vp11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);

    LPUNKNOWN unk11 = NULL;
    result = vp11->QueryInterface(IID_IUnknown, (LPVOID*)&unk11);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk11, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)unk11);

    LPDIRECT3DVIEWPORT2 vp12 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPUNKNOWN unk12 = NULL;
    result = vp12->QueryInterface(IID_IUnknown, (LPVOID*)&unk12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk12, NULL);
    IsEqual((LPVOID)vp12, (LPVOID)unk12);

    LPDIRECT3DVIEWPORT3 vp13 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp13, NULL);
    IsEqual((LPVOID)vp12, (LPVOID)vp13);
    IsEqual((LPVOID)vp11, (LPVOID)vp13);

    LPUNKNOWN unk13 = NULL;
    result = vp13->QueryInterface(IID_IUnknown, (LPVOID*)&unk13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk13, NULL);
    IsEqual((LPVOID)vp13, (LPVOID)unk13);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT2 vp22 = NULL;
    result = d3d2->CreateViewport(&vp22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp22, NULL);
    IsNotEqual(vp11, vp22);

    LPUNKNOWN unk22 = NULL;
    result = vp22->QueryInterface(IID_IUnknown, (LPVOID*)&unk22);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk22, NULL);
    IsEqual((LPVOID)vp22, (LPVOID)unk22);

    LPDIRECT3DVIEWPORT vp21 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPUNKNOWN unk21 = NULL;
    result = vp21->QueryInterface(IID_IUnknown, (LPVOID*)&unk21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk21, NULL);
    IsEqual((LPVOID)vp22, (LPVOID)unk21);

    LPDIRECT3DVIEWPORT3 vp23 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp23, NULL);
    IsEqual((LPVOID)vp22, (LPVOID)vp23);
    IsEqual((LPVOID)vp21, (LPVOID)vp23);

    LPUNKNOWN unk23 = NULL;
    result = vp23->QueryInterface(IID_IUnknown, (LPVOID*)&unk23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk23, NULL);
    IsEqual((LPVOID)vp23, (LPVOID)unk23);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT3 vp33 = NULL;
    result = d3d3->CreateViewport(&vp33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp33, NULL);

    IsNotEqual(vp11, vp33);
    IsNotEqual(vp22, vp33);

    LPUNKNOWN unk33 = NULL;
    result = vp33->QueryInterface(IID_IUnknown, (LPVOID*)&unk33);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk33, NULL);
    IsEqual((LPVOID)vp33, (LPVOID)unk33);

    LPDIRECT3DVIEWPORT vp31 = NULL;
    result = vp33->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp33, (LPVOID)vp31);

    LPUNKNOWN unk31 = NULL;
    result = vp31->QueryInterface(IID_IUnknown, (LPVOID*)&unk31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk31, NULL);
    IsEqual((LPVOID)vp31, (LPVOID)unk31);

    LPDIRECT3DVIEWPORT2 vp32 = NULL;
    result = vp33->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp32, NULL);
    IsEqual((LPVOID)vp32, (LPVOID)vp33);
    IsEqual((LPVOID)vp32, (LPVOID)vp31);

    LPUNKNOWN unk32 = NULL;
    result = vp32->QueryInterface(IID_IUnknown, (LPVOID*)&unk32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk32, NULL);
    IsEqual((LPVOID)vp32, (LPVOID)unk32);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DIRECTRELEASE(vp31);
    DIRECTRELEASE(vp32);
    DIRECTRELEASE(vp33);
    DIRECTRELEASE(vp21);
    DIRECTRELEASE(vp22);
    DIRECTRELEASE(vp23);
    DIRECTRELEASE(vp13);
    DIRECTRELEASE(vp12);
    DIRECTRELEASE(vp11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd);
}

VOID DirectDraw2CreateViewportQueryInterfaceIUnknown(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW2 dd2 = NULL;
    result = dd->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsEqual(result, DD_OK);

    LPDIRECT3D d3d1 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D, (LPVOID*)&d3d1);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT vp11 = NULL;
    result = d3d1->CreateViewport(&vp11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);

    LPUNKNOWN unk11 = NULL;
    result = vp11->QueryInterface(IID_IUnknown, (LPVOID*)&unk11);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk11, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)unk11);

    LPDIRECT3DVIEWPORT2 vp12 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPUNKNOWN unk12 = NULL;
    result = vp12->QueryInterface(IID_IUnknown, (LPVOID*)&unk12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk12, NULL);
    IsEqual((LPVOID)vp12, (LPVOID)unk12);

    LPDIRECT3DVIEWPORT3 vp13 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp13, NULL);
    IsEqual((LPVOID)vp12, (LPVOID)vp13);
    IsEqual((LPVOID)vp11, (LPVOID)vp13);

    LPUNKNOWN unk13 = NULL;
    result = vp13->QueryInterface(IID_IUnknown, (LPVOID*)&unk13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk13, NULL);
    IsEqual((LPVOID)vp13, (LPVOID)unk13);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT2 vp22 = NULL;
    result = d3d2->CreateViewport(&vp22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp22, NULL);
    IsNotEqual(vp11, vp22);

    LPUNKNOWN unk22 = NULL;
    result = vp22->QueryInterface(IID_IUnknown, (LPVOID*)&unk22);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk22, NULL);
    IsEqual((LPVOID)vp22, (LPVOID)unk22);

    LPDIRECT3DVIEWPORT vp21 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPUNKNOWN unk21 = NULL;
    result = vp21->QueryInterface(IID_IUnknown, (LPVOID*)&unk21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk21, NULL);
    IsEqual((LPVOID)vp22, (LPVOID)unk21);

    LPDIRECT3DVIEWPORT3 vp23 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp23, NULL);
    IsEqual((LPVOID)vp22, (LPVOID)vp23);
    IsEqual((LPVOID)vp21, (LPVOID)vp23);

    LPUNKNOWN unk23 = NULL;
    result = vp23->QueryInterface(IID_IUnknown, (LPVOID*)&unk23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk23, NULL);
    IsEqual((LPVOID)vp23, (LPVOID)unk23);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT3 vp33 = NULL;
    result = d3d3->CreateViewport(&vp33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp33, NULL);

    IsNotEqual(vp11, vp33);
    IsNotEqual(vp22, vp33);

    LPUNKNOWN unk33 = NULL;
    result = vp33->QueryInterface(IID_IUnknown, (LPVOID*)&unk33);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk33, NULL);
    IsEqual((LPVOID)vp33, (LPVOID)unk33);

    LPDIRECT3DVIEWPORT vp31 = NULL;
    result = vp33->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp33, (LPVOID)vp31);

    LPUNKNOWN unk31 = NULL;
    result = vp31->QueryInterface(IID_IUnknown, (LPVOID*)&unk31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk31, NULL);
    IsEqual((LPVOID)vp31, (LPVOID)unk31);

    LPDIRECT3DVIEWPORT2 vp32 = NULL;
    result = vp33->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp32, NULL);
    IsEqual((LPVOID)vp32, (LPVOID)vp33);
    IsEqual((LPVOID)vp32, (LPVOID)vp31);

    LPUNKNOWN unk32 = NULL;
    result = vp32->QueryInterface(IID_IUnknown, (LPVOID*)&unk32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk32, NULL);
    IsEqual((LPVOID)vp32, (LPVOID)unk32);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DIRECTRELEASE(vp31);
    DIRECTRELEASE(vp32);
    DIRECTRELEASE(vp33);
    DIRECTRELEASE(vp21);
    DIRECTRELEASE(vp22);
    DIRECTRELEASE(vp23);
    DIRECTRELEASE(vp13);
    DIRECTRELEASE(vp12);
    DIRECTRELEASE(vp11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd2);
    DIRECTRELEASE(dd);
}

VOID DirectDraw4CreateViewportQueryInterfaceIUnknown(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW4 dd4 = NULL;
    result = dd->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsEqual(result, DD_OK);

    LPDIRECT3D d3d1 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D, (LPVOID*)&d3d1);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT vp11 = NULL;
    result = d3d1->CreateViewport(&vp11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);

    LPUNKNOWN unk11 = NULL;
    result = vp11->QueryInterface(IID_IUnknown, (LPVOID*)&unk11);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk11, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)unk11);

    LPDIRECT3DVIEWPORT2 vp12 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPUNKNOWN unk12 = NULL;
    result = vp12->QueryInterface(IID_IUnknown, (LPVOID*)&unk12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk12, NULL);
    IsEqual((LPVOID)vp12, (LPVOID)unk12);

    LPDIRECT3DVIEWPORT3 vp13 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp13, NULL);
    IsEqual((LPVOID)vp12, (LPVOID)vp13);
    IsEqual((LPVOID)vp11, (LPVOID)vp13);

    LPUNKNOWN unk13 = NULL;
    result = vp13->QueryInterface(IID_IUnknown, (LPVOID*)&unk13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk13, NULL);
    IsEqual((LPVOID)vp13, (LPVOID)unk13);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT2 vp22 = NULL;
    result = d3d2->CreateViewport(&vp22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp22, NULL);
    IsNotEqual(vp11, vp22);

    LPUNKNOWN unk22 = NULL;
    result = vp22->QueryInterface(IID_IUnknown, (LPVOID*)&unk22);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk22, NULL);
    IsEqual((LPVOID)vp22, (LPVOID)unk22);

    LPDIRECT3DVIEWPORT vp21 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPUNKNOWN unk21 = NULL;
    result = vp21->QueryInterface(IID_IUnknown, (LPVOID*)&unk21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk21, NULL);
    IsEqual((LPVOID)vp22, (LPVOID)unk21);

    LPDIRECT3DVIEWPORT3 vp23 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp23, NULL);
    IsEqual((LPVOID)vp22, (LPVOID)vp23);
    IsEqual((LPVOID)vp21, (LPVOID)vp23);

    LPUNKNOWN unk23 = NULL;
    result = vp23->QueryInterface(IID_IUnknown, (LPVOID*)&unk23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk23, NULL);
    IsEqual((LPVOID)vp23, (LPVOID)unk23);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT3 vp33 = NULL;
    result = d3d3->CreateViewport(&vp33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp33, NULL);

    IsNotEqual(vp11, vp33);
    IsNotEqual(vp22, vp33);

    LPUNKNOWN unk33 = NULL;
    result = vp33->QueryInterface(IID_IUnknown, (LPVOID*)&unk33);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk33, NULL);
    IsEqual((LPVOID)vp33, (LPVOID)unk33);

    LPDIRECT3DVIEWPORT vp31 = NULL;
    result = vp33->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp33, (LPVOID)vp31);

    LPUNKNOWN unk31 = NULL;
    result = vp31->QueryInterface(IID_IUnknown, (LPVOID*)&unk31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk31, NULL);
    IsEqual((LPVOID)vp31, (LPVOID)unk31);

    LPDIRECT3DVIEWPORT2 vp32 = NULL;
    result = vp33->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp32, NULL);
    IsEqual((LPVOID)vp32, (LPVOID)vp33);
    IsEqual((LPVOID)vp32, (LPVOID)vp31);

    LPUNKNOWN unk32 = NULL;
    result = vp32->QueryInterface(IID_IUnknown, (LPVOID*)&unk32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk32, NULL);
    IsEqual((LPVOID)vp32, (LPVOID)unk32);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DIRECTRELEASE(vp31);
    DIRECTRELEASE(vp32);
    DIRECTRELEASE(vp33);
    DIRECTRELEASE(vp21);
    DIRECTRELEASE(vp22);
    DIRECTRELEASE(vp23);
    DIRECTRELEASE(vp13);
    DIRECTRELEASE(vp12);
    DIRECTRELEASE(vp11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd4);
    DIRECTRELEASE(dd);
}

VOID DirectDrawCreateViewportQuery(LPDIRECT3DVIEWPORT vp)
{
    /* Direct3D */

    LPDIRECT3D dd3d1 = NULL;
    HRESULT result = vp->QueryInterface(IID_IDirect3D, (LPVOID*)&dd3d1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d1, NULL);

    LPDIRECT3D2 dd3d2 = NULL;
    result = vp->QueryInterface(IID_IDirect3D2, (LPVOID*)&dd3d2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d2, NULL);

    LPDIRECT3D3 dd3d3 = NULL;
    result = vp->QueryInterface(IID_IDirect3D3, (LPVOID*)&dd3d3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d3, NULL);

    LPDIRECT3D3 dd3d7 = NULL;
    result = vp->QueryInterface(IID_IDirect3D7, (LPVOID*)&dd3d7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d7, NULL);

    /* Direct3DDevice */

    LPDIRECT3DDEVICE dd3dd1 = NULL;
    result = vp->QueryInterface(IID_IDirect3DDevice, (LPVOID*)&dd3dd1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    LPDIRECT3DDEVICE2 dd3dd2 = NULL;
    result = vp->QueryInterface(IID_IDirect3DDevice2, (LPVOID*)&dd3dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd2, NULL);

    LPDIRECT3DDEVICE3 dd3dd3 = NULL;
    result = vp->QueryInterface(IID_IDirect3DDevice3, (LPVOID*)&dd3dd3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd3, NULL);

    LPDIRECT3DDEVICE7 dd3dd7 = NULL;
    result = vp->QueryInterface(IID_IDirect3DDevice7, (LPVOID*)&dd3dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd7, NULL);

    LPDIRECT3DDEVICE d3drd = NULL;
    result = vp->QueryInterface(IID_IDirect3DRampDevice, (LPVOID*)&d3drd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drd, NULL);

    LPDIRECT3DDEVICE d3drgbd = NULL;
    result = vp->QueryInterface(IID_IDirect3DRGBDevice, (LPVOID*)&d3drgbd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drgbd, NULL);

    LPDIRECT3DDEVICE d3dhald = NULL;
    result = vp->QueryInterface(IID_IDirect3DHALDevice, (LPVOID*)&d3dhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dhald, NULL);

    LPDIRECT3DDEVICE d3dmmxd = NULL;
    result = vp->QueryInterface(IID_IDirect3DMMXDevice, (LPVOID*)&d3dmmxd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dmmxd, NULL);

    LPDIRECT3DDEVICE d3drefd = NULL;
    result = vp->QueryInterface(IID_IDirect3DRefDevice, (LPVOID*)&d3drefd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drefd, NULL);

    LPDIRECT3DDEVICE d3dnd = NULL;
    result = vp->QueryInterface(IID_IDirect3DNullDevice, (LPVOID*)&d3dnd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dnd, NULL);

    LPDIRECT3DDEVICE d3dtnlhald = NULL;
    result = vp->QueryInterface(IID_IDirect3DTnLHalDevice, (LPVOID*)&d3dtnlhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dtnlhald, NULL);

    /* Direct3DExecuteBuffer */

    LPDIRECT3DEXECUTEBUFFER d3deb = NULL;
    result = vp->QueryInterface(IID_IDirect3DExecuteBuffer, (LPVOID*)&d3deb);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    /* Direct3DLight */
    LPDIRECT3DLIGHT d3dl = NULL;
    result = vp->QueryInterface(IID_IDirect3DLight, (LPVOID*)&d3dl);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dl, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dm1 = NULL;
    result = vp->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dm1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm1, NULL);

    LPDIRECT3DMATERIAL2 d3dm2 = NULL;
    result = vp->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dm2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm2, NULL);

    LPDIRECT3DMATERIAL3 d3dm3 = NULL;
    result = vp->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dm3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm3, NULL);

    /* Direct3DTexture */

    LPDIRECT3DTEXTURE d3dt1 = NULL;
    result = vp->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&d3dt1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt1, NULL);

    LPDIRECT3DTEXTURE2 d3dt2 = NULL;
    result = vp->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&d3dt2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt2, NULL);

    /* Direct3DVertexBuffer */

    LPDIRECT3DVERTEXBUFFER d3dvb1 = NULL;
    result = vp->QueryInterface(IID_IDirect3DVertexBuffer, (LPVOID*)&d3dvb1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb1, NULL);

    LPDIRECT3DVERTEXBUFFER7 d3dvb7 = NULL;
    result = vp->QueryInterface(IID_IDirect3DVertexBuffer7, (LPVOID*)&d3dvb7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb7, NULL);

    /* Direct3DViewport */

    LPDIRECT3DVIEWPORT d3dvp1 = NULL;
    result = vp->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&d3dvp1);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dvp1, NULL);
    IsEqual(d3dvp1, vp);
    DIRECTRELEASE(d3dvp1);

    LPDIRECT3DVIEWPORT2 d3dvp2 = NULL;
    result = vp->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&d3dvp2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dvp2, NULL);
    IsEqual(d3dvp2, vp);
    DIRECTRELEASE(d3dvp2);

    LPDIRECT3DVIEWPORT3 d3dvp3 = NULL;
    result = vp->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&d3dvp3);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dvp3, NULL);
    IsEqual(d3dvp3, vp);
    DIRECTRELEASE(d3dvp3);

    /* DirectDraw */

    LPDIRECTDRAW dd = NULL;
    result = vp->QueryInterface(IID_IDirectDraw, (LPVOID*)&dd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd, NULL);

    LPDIRECTDRAW2 dd2 = NULL;
    result = vp->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd2, NULL);

    LPDIRECTDRAW4 dd4 = NULL;
    result = vp->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd4, NULL);

    LPDIRECTDRAW7 dd7 = NULL;
    result = vp->QueryInterface(IID_IDirectDraw7, (LPVOID*)&dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd7, NULL);

    /* DirectDrawClipper */

    LPDIRECTDRAWCLIPPER ddc = NULL;
    result = vp->QueryInterface(IID_IDirectDrawClipper, (LPVOID*)&ddc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddc, NULL);

    /* DirectDrawColorControl */

    LPDIRECTDRAWCOLORCONTROL ddcc = NULL;
    result = vp->QueryInterface(IID_IDirectDrawColorControl, (LPVOID*)&ddcc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddcc, NULL);

    /* DirectDrawGammaControl */

    LPDIRECTDRAWGAMMACONTROL ddgc = NULL;
    result = vp->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&ddgc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddgc, NULL);

    /* DirectDrawPalette */

    LPDIRECTDRAWPALETTE ddp = NULL;
    result = vp->QueryInterface(IID_IDirectDrawPalette, (LPVOID*)&ddp);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddp, NULL);

    /* DirectDrawSurface */

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = vp->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds1, NULL);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = vp->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds2, NULL);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = vp->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds3, NULL);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = vp->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds4, NULL);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = vp->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds7, NULL);

    /* DirectDrawVideoPort */
    LPDIRECTDRAWVIDEOPORT ddvp = NULL;
    result = vp->QueryInterface(IID_IDirectDrawVideoPort, (LPVOID*)&ddvp);
    IsNotEqual(result, DD_OK);
    IsEqual(ddvp, NULL);

    /* DirectDrawVideoPortContainer */

    LPDDVIDEOPORTCONTAINER ddvpc = NULL;
    result = vp->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&ddvpc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddvpc, NULL);

    /* DirectDrawVideoPortNotify */

    LPDDVIDEOPORTNOTIFY ddvpn = NULL;
    result = vp->QueryInterface(IID_IDirectDrawVideoPortNotify, (LPVOID*)&ddvpn);
    IsNotEqual(result, DD_OK);

    /* Unknown */

    LPUNKNOWN unk = NULL;
    result = vp->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);
    IsEqual(vp, unk);
    DIRECTRELEASE(unk);
}

VOID DirectDrawCreateViewport2Query(LPDIRECT3DVIEWPORT2 vp)
{
    /* Direct3D */

    LPDIRECT3D dd3d1 = NULL;
    HRESULT result = vp->QueryInterface(IID_IDirect3D, (LPVOID*)&dd3d1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d1, NULL);

    LPDIRECT3D2 dd3d2 = NULL;
    result = vp->QueryInterface(IID_IDirect3D2, (LPVOID*)&dd3d2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d2, NULL);

    LPDIRECT3D3 dd3d3 = NULL;
    result = vp->QueryInterface(IID_IDirect3D3, (LPVOID*)&dd3d3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d3, NULL);

    LPDIRECT3D3 dd3d7 = NULL;
    result = vp->QueryInterface(IID_IDirect3D7, (LPVOID*)&dd3d7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d7, NULL);

    /* Direct3DDevice */

    LPDIRECT3DDEVICE dd3dd1 = NULL;
    result = vp->QueryInterface(IID_IDirect3DDevice, (LPVOID*)&dd3dd1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    LPDIRECT3DDEVICE2 dd3dd2 = NULL;
    result = vp->QueryInterface(IID_IDirect3DDevice2, (LPVOID*)&dd3dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd2, NULL);

    LPDIRECT3DDEVICE3 dd3dd3 = NULL;
    result = vp->QueryInterface(IID_IDirect3DDevice3, (LPVOID*)&dd3dd3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd3, NULL);

    LPDIRECT3DDEVICE7 dd3dd7 = NULL;
    result = vp->QueryInterface(IID_IDirect3DDevice7, (LPVOID*)&dd3dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd7, NULL);

    LPDIRECT3DDEVICE d3drd = NULL;
    result = vp->QueryInterface(IID_IDirect3DRampDevice, (LPVOID*)&d3drd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drd, NULL);

    LPDIRECT3DDEVICE d3drgbd = NULL;
    result = vp->QueryInterface(IID_IDirect3DRGBDevice, (LPVOID*)&d3drgbd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drgbd, NULL);

    LPDIRECT3DDEVICE d3dhald = NULL;
    result = vp->QueryInterface(IID_IDirect3DHALDevice, (LPVOID*)&d3dhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dhald, NULL);

    LPDIRECT3DDEVICE d3dmmxd = NULL;
    result = vp->QueryInterface(IID_IDirect3DMMXDevice, (LPVOID*)&d3dmmxd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dmmxd, NULL);

    LPDIRECT3DDEVICE d3drefd = NULL;
    result = vp->QueryInterface(IID_IDirect3DRefDevice, (LPVOID*)&d3drefd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drefd, NULL);

    LPDIRECT3DDEVICE d3dnd = NULL;
    result = vp->QueryInterface(IID_IDirect3DNullDevice, (LPVOID*)&d3dnd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dnd, NULL);

    LPDIRECT3DDEVICE d3dtnlhald = NULL;
    result = vp->QueryInterface(IID_IDirect3DTnLHalDevice, (LPVOID*)&d3dtnlhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dtnlhald, NULL);

    /* Direct3DExecuteBuffer */

    LPDIRECT3DEXECUTEBUFFER d3deb = NULL;
    result = vp->QueryInterface(IID_IDirect3DExecuteBuffer, (LPVOID*)&d3deb);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    /* Direct3DLight */
    LPDIRECT3DLIGHT d3dl = NULL;
    result = vp->QueryInterface(IID_IDirect3DLight, (LPVOID*)&d3dl);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dl, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dm1 = NULL;
    result = vp->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dm1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm1, NULL);

    LPDIRECT3DMATERIAL2 d3dm2 = NULL;
    result = vp->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dm2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm2, NULL);

    LPDIRECT3DMATERIAL3 d3dm3 = NULL;
    result = vp->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dm3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm3, NULL);

    /* Direct3DTexture */

    LPDIRECT3DTEXTURE d3dt1 = NULL;
    result = vp->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&d3dt1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt1, NULL);

    LPDIRECT3DTEXTURE2 d3dt2 = NULL;
    result = vp->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&d3dt2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt2, NULL);

    /* Direct3DVertexBuffer */

    LPDIRECT3DVERTEXBUFFER d3dvb1 = NULL;
    result = vp->QueryInterface(IID_IDirect3DVertexBuffer, (LPVOID*)&d3dvb1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb1, NULL);

    LPDIRECT3DVERTEXBUFFER7 d3dvb7 = NULL;
    result = vp->QueryInterface(IID_IDirect3DVertexBuffer7, (LPVOID*)&d3dvb7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb7, NULL);

    /* Direct3DViewport */

    LPDIRECT3DVIEWPORT d3dvp1 = NULL;
    result = vp->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&d3dvp1);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dvp1, NULL);
    IsEqual(d3dvp1, vp);
    DIRECTRELEASE(d3dvp1);

    LPDIRECT3DVIEWPORT2 d3dvp2 = NULL;
    result = vp->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&d3dvp2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dvp2, NULL);
    IsEqual(d3dvp2, vp);
    DIRECTRELEASE(d3dvp2);

    LPDIRECT3DVIEWPORT3 d3dvp3 = NULL;
    result = vp->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&d3dvp3);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dvp3, NULL);
    IsEqual(d3dvp3, vp);
    DIRECTRELEASE(d3dvp3);

    /* DirectDraw */

    LPDIRECTDRAW dd = NULL;
    result = vp->QueryInterface(IID_IDirectDraw, (LPVOID*)&dd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd, NULL);

    LPDIRECTDRAW2 dd2 = NULL;
    result = vp->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd2, NULL);

    LPDIRECTDRAW4 dd4 = NULL;
    result = vp->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd4, NULL);

    LPDIRECTDRAW7 dd7 = NULL;
    result = vp->QueryInterface(IID_IDirectDraw7, (LPVOID*)&dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd7, NULL);

    /* DirectDrawClipper */

    LPDIRECTDRAWCLIPPER ddc = NULL;
    result = vp->QueryInterface(IID_IDirectDrawClipper, (LPVOID*)&ddc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddc, NULL);

    /* DirectDrawColorControl */

    LPDIRECTDRAWCOLORCONTROL ddcc = NULL;
    result = vp->QueryInterface(IID_IDirectDrawColorControl, (LPVOID*)&ddcc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddcc, NULL);

    /* DirectDrawGammaControl */

    LPDIRECTDRAWGAMMACONTROL ddgc = NULL;
    result = vp->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&ddgc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddgc, NULL);

    /* DirectDrawPalette */

    LPDIRECTDRAWPALETTE ddp = NULL;
    result = vp->QueryInterface(IID_IDirectDrawPalette, (LPVOID*)&ddp);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddp, NULL);

    /* DirectDrawSurface */

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = vp->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds1, NULL);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = vp->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds2, NULL);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = vp->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds3, NULL);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = vp->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds4, NULL);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = vp->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds7, NULL);

    /* DirectDrawVideoPort */
    LPDIRECTDRAWVIDEOPORT ddvp = NULL;
    result = vp->QueryInterface(IID_IDirectDrawVideoPort, (LPVOID*)&ddvp);
    IsNotEqual(result, DD_OK);
    IsEqual(ddvp, NULL);

    /* DirectDrawVideoPortContainer */

    LPDDVIDEOPORTCONTAINER ddvpc = NULL;
    result = vp->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&ddvpc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddvpc, NULL);

    /* DirectDrawVideoPortNotify */

    LPDDVIDEOPORTNOTIFY ddvpn = NULL;
    result = vp->QueryInterface(IID_IDirectDrawVideoPortNotify, (LPVOID*)&ddvpn);
    IsNotEqual(result, DD_OK);

    /* Unknown */

    LPUNKNOWN unk = NULL;
    result = vp->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);
    IsEqual(vp, unk);
    DIRECTRELEASE(unk);
}

VOID DirectDrawCreateViewport3Query(LPDIRECT3DVIEWPORT3 vp)
{
    /* Direct3D */

    LPDIRECT3D dd3d1 = NULL;
    HRESULT result = vp->QueryInterface(IID_IDirect3D, (LPVOID*)&dd3d1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d1, NULL);

    LPDIRECT3D2 dd3d2 = NULL;
    result = vp->QueryInterface(IID_IDirect3D2, (LPVOID*)&dd3d2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d2, NULL);

    LPDIRECT3D3 dd3d3 = NULL;
    result = vp->QueryInterface(IID_IDirect3D3, (LPVOID*)&dd3d3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d3, NULL);

    LPDIRECT3D3 dd3d7 = NULL;
    result = vp->QueryInterface(IID_IDirect3D7, (LPVOID*)&dd3d7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d7, NULL);

    /* Direct3DDevice */

    LPDIRECT3DDEVICE dd3dd1 = NULL;
    result = vp->QueryInterface(IID_IDirect3DDevice, (LPVOID*)&dd3dd1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    LPDIRECT3DDEVICE2 dd3dd2 = NULL;
    result = vp->QueryInterface(IID_IDirect3DDevice2, (LPVOID*)&dd3dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd2, NULL);

    LPDIRECT3DDEVICE3 dd3dd3 = NULL;
    result = vp->QueryInterface(IID_IDirect3DDevice3, (LPVOID*)&dd3dd3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd3, NULL);

    LPDIRECT3DDEVICE7 dd3dd7 = NULL;
    result = vp->QueryInterface(IID_IDirect3DDevice7, (LPVOID*)&dd3dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd7, NULL);

    LPDIRECT3DDEVICE d3drd = NULL;
    result = vp->QueryInterface(IID_IDirect3DRampDevice, (LPVOID*)&d3drd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drd, NULL);

    LPDIRECT3DDEVICE d3drgbd = NULL;
    result = vp->QueryInterface(IID_IDirect3DRGBDevice, (LPVOID*)&d3drgbd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drgbd, NULL);

    LPDIRECT3DDEVICE d3dhald = NULL;
    result = vp->QueryInterface(IID_IDirect3DHALDevice, (LPVOID*)&d3dhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dhald, NULL);

    LPDIRECT3DDEVICE d3dmmxd = NULL;
    result = vp->QueryInterface(IID_IDirect3DMMXDevice, (LPVOID*)&d3dmmxd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dmmxd, NULL);

    LPDIRECT3DDEVICE d3drefd = NULL;
    result = vp->QueryInterface(IID_IDirect3DRefDevice, (LPVOID*)&d3drefd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drefd, NULL);

    LPDIRECT3DDEVICE d3dnd = NULL;
    result = vp->QueryInterface(IID_IDirect3DNullDevice, (LPVOID*)&d3dnd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dnd, NULL);

    LPDIRECT3DDEVICE d3dtnlhald = NULL;
    result = vp->QueryInterface(IID_IDirect3DTnLHalDevice, (LPVOID*)&d3dtnlhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dtnlhald, NULL);

    /* Direct3DExecuteBuffer */

    LPDIRECT3DEXECUTEBUFFER d3deb = NULL;
    result = vp->QueryInterface(IID_IDirect3DExecuteBuffer, (LPVOID*)&d3deb);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    /* Direct3DLight */
    LPDIRECT3DLIGHT d3dl = NULL;
    result = vp->QueryInterface(IID_IDirect3DLight, (LPVOID*)&d3dl);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dl, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dm1 = NULL;
    result = vp->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dm1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm1, NULL);

    LPDIRECT3DMATERIAL2 d3dm2 = NULL;
    result = vp->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dm2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm2, NULL);

    LPDIRECT3DMATERIAL3 d3dm3 = NULL;
    result = vp->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dm3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dm3, NULL);

    /* Direct3DTexture */

    LPDIRECT3DTEXTURE d3dt1 = NULL;
    result = vp->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&d3dt1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt1, NULL);

    LPDIRECT3DTEXTURE2 d3dt2 = NULL;
    result = vp->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&d3dt2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt2, NULL);

    /* Direct3DVertexBuffer */

    LPDIRECT3DVERTEXBUFFER d3dvb1 = NULL;
    result = vp->QueryInterface(IID_IDirect3DVertexBuffer, (LPVOID*)&d3dvb1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb1, NULL);

    LPDIRECT3DVERTEXBUFFER7 d3dvb7 = NULL;
    result = vp->QueryInterface(IID_IDirect3DVertexBuffer7, (LPVOID*)&d3dvb7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb7, NULL);

    /* Direct3DViewport */

    LPDIRECT3DVIEWPORT d3dvp1 = NULL;
    result = vp->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&d3dvp1);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dvp1, NULL);
    IsEqual(d3dvp1, vp);
    DIRECTRELEASE(d3dvp1);

    LPDIRECT3DVIEWPORT2 d3dvp2 = NULL;
    result = vp->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&d3dvp2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dvp2, NULL);
    IsEqual(d3dvp2, vp);
    DIRECTRELEASE(d3dvp2);

    LPDIRECT3DVIEWPORT3 d3dvp3 = NULL;
    result = vp->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&d3dvp3);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dvp3, NULL);
    IsEqual(d3dvp3, vp);
    DIRECTRELEASE(d3dvp3);

    /* DirectDraw */

    LPDIRECTDRAW dd = NULL;
    result = vp->QueryInterface(IID_IDirectDraw, (LPVOID*)&dd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd, NULL);

    LPDIRECTDRAW2 dd2 = NULL;
    result = vp->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd2, NULL);

    LPDIRECTDRAW4 dd4 = NULL;
    result = vp->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd4, NULL);

    LPDIRECTDRAW7 dd7 = NULL;
    result = vp->QueryInterface(IID_IDirectDraw7, (LPVOID*)&dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd7, NULL);

    /* DirectDrawClipper */

    LPDIRECTDRAWCLIPPER ddc = NULL;
    result = vp->QueryInterface(IID_IDirectDrawClipper, (LPVOID*)&ddc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddc, NULL);

    /* DirectDrawColorControl */

    LPDIRECTDRAWCOLORCONTROL ddcc = NULL;
    result = vp->QueryInterface(IID_IDirectDrawColorControl, (LPVOID*)&ddcc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddcc, NULL);

    /* DirectDrawGammaControl */

    LPDIRECTDRAWGAMMACONTROL ddgc = NULL;
    result = vp->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&ddgc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddgc, NULL);

    /* DirectDrawPalette */

    LPDIRECTDRAWPALETTE ddp = NULL;
    result = vp->QueryInterface(IID_IDirectDrawPalette, (LPVOID*)&ddp);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddp, NULL);

    /* DirectDrawSurface */

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = vp->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds1, NULL);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = vp->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds2, NULL);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = vp->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds3, NULL);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = vp->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds4, NULL);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = vp->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds7, NULL);

    /* DirectDrawVideoPort */
    LPDIRECTDRAWVIDEOPORT ddvp = NULL;
    result = vp->QueryInterface(IID_IDirectDrawVideoPort, (LPVOID*)&ddvp);
    IsNotEqual(result, DD_OK);
    IsEqual(ddvp, NULL);

    /* DirectDrawVideoPortContainer */

    LPDDVIDEOPORTCONTAINER ddvpc = NULL;
    result = vp->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&ddvpc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddvpc, NULL);

    /* DirectDrawVideoPortNotify */

    LPDDVIDEOPORTNOTIFY ddvpn = NULL;
    result = vp->QueryInterface(IID_IDirectDrawVideoPortNotify, (LPVOID*)&ddvpn);
    IsNotEqual(result, DD_OK);

    /* Unknown */

    LPUNKNOWN unk = NULL;
    result = vp->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);
    IsEqual(vp, unk);
    DIRECTRELEASE(unk);
}

VOID DirectDrawCreateViewportQueryInterfaceAll(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECT3D d3d1 = NULL;
    result = dd->QueryInterface(IID_IDirect3D, (LPVOID*)&d3d1);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT vp11 = NULL;
    result = d3d1->CreateViewport(&vp11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);

    LPDIRECT3DVIEWPORT2 vp12 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPDIRECT3DVIEWPORT3 vp13 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp13, NULL);
    IsEqual((LPVOID)vp12, (LPVOID)vp13);
    IsEqual((LPVOID)vp11, (LPVOID)vp13);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT2 vp22 = NULL;
    result = d3d2->CreateViewport(&vp22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp22, NULL);
    IsNotEqual(vp11, vp22);

    LPDIRECT3DVIEWPORT vp21 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPDIRECT3DVIEWPORT3 vp23 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp23, NULL);
    IsEqual((LPVOID)vp22, (LPVOID)vp23);
    IsEqual((LPVOID)vp21, (LPVOID)vp23);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT3 vp33 = NULL;
    result = d3d3->CreateViewport(&vp33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp33, NULL);

    IsNotEqual(vp11, vp33);
    IsNotEqual(vp22, vp33);

    LPDIRECT3DVIEWPORT vp31 = NULL;
    result = vp33->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp33, (LPVOID)vp31);

    LPDIRECT3DVIEWPORT2 vp32 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp32, NULL);
    IsNotEqual((LPVOID)vp32, (LPVOID)vp33);
    IsNotEqual((LPVOID)vp32, (LPVOID)vp31);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DirectDrawCreateViewportQuery(vp11);
    DirectDrawCreateViewportQuery(vp21);
    DirectDrawCreateViewportQuery(vp31);

    DirectDrawCreateViewport2Query(vp12);
    DirectDrawCreateViewport2Query(vp22);
    DirectDrawCreateViewport2Query(vp32);

    DirectDrawCreateViewport3Query(vp13);
    DirectDrawCreateViewport3Query(vp23);
    DirectDrawCreateViewport3Query(vp33);

    DIRECTRELEASE(vp31);
    DIRECTRELEASE(vp32);
    DIRECTRELEASE(vp33);
    DIRECTRELEASE(vp21);
    DIRECTRELEASE(vp22);
    DIRECTRELEASE(vp23);
    DIRECTRELEASE(vp13);
    DIRECTRELEASE(vp12);
    DIRECTRELEASE(vp11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd);
}

VOID DirectDraw2CreateViewportQueryInterfaceAll(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW2 dd2 = NULL;
    result = dd->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsEqual(result, DD_OK);

    LPDIRECT3D d3d1 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D, (LPVOID*)&d3d1);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT vp11 = NULL;
    result = d3d1->CreateViewport(&vp11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);

    LPDIRECT3DVIEWPORT2 vp12 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPDIRECT3DVIEWPORT3 vp13 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp13, NULL);
    IsEqual((LPVOID)vp12, (LPVOID)vp13);
    IsEqual((LPVOID)vp11, (LPVOID)vp13);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT2 vp22 = NULL;
    result = d3d2->CreateViewport(&vp22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp22, NULL);
    IsNotEqual(vp11, vp22);

    LPDIRECT3DVIEWPORT vp21 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPDIRECT3DVIEWPORT3 vp23 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp23, NULL);
    IsEqual((LPVOID)vp22, (LPVOID)vp23);
    IsEqual((LPVOID)vp21, (LPVOID)vp23);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT3 vp33 = NULL;
    result = d3d3->CreateViewport(&vp33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp33, NULL);

    IsNotEqual(vp11, vp33);
    IsNotEqual(vp22, vp33);

    LPDIRECT3DVIEWPORT vp31 = NULL;
    result = vp33->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp33, (LPVOID)vp31);

    LPDIRECT3DVIEWPORT2 vp32 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp32, NULL);
    IsNotEqual((LPVOID)vp32, (LPVOID)vp33);
    IsNotEqual((LPVOID)vp32, (LPVOID)vp31);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DirectDrawCreateViewportQuery(vp11);
    DirectDrawCreateViewportQuery(vp21);
    DirectDrawCreateViewportQuery(vp31);

    DirectDrawCreateViewport2Query(vp12);
    DirectDrawCreateViewport2Query(vp22);
    DirectDrawCreateViewport2Query(vp32);

    DirectDrawCreateViewport3Query(vp13);
    DirectDrawCreateViewport3Query(vp23);
    DirectDrawCreateViewport3Query(vp33);

    DIRECTRELEASE(vp31);
    DIRECTRELEASE(vp32);
    DIRECTRELEASE(vp33);
    DIRECTRELEASE(vp21);
    DIRECTRELEASE(vp22);
    DIRECTRELEASE(vp23);
    DIRECTRELEASE(vp13);
    DIRECTRELEASE(vp12);
    DIRECTRELEASE(vp11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd2);
    DIRECTRELEASE(dd);
}

VOID DirectDraw4CreateViewportQueryInterfaceAll(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECTDRAW4 dd4 = NULL;
    result = dd->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsEqual(result, DD_OK);

    LPDIRECT3D d3d1 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D, (LPVOID*)&d3d1);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT vp11 = NULL;
    result = d3d1->CreateViewport(&vp11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);

    LPDIRECT3DVIEWPORT2 vp12 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp11, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPDIRECT3DVIEWPORT3 vp13 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp13, NULL);
    IsEqual((LPVOID)vp12, (LPVOID)vp13);
    IsEqual((LPVOID)vp11, (LPVOID)vp13);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT2 vp22 = NULL;
    result = d3d2->CreateViewport(&vp22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp22, NULL);
    IsNotEqual(vp11, vp22);

    LPDIRECT3DVIEWPORT vp21 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp11, (LPVOID)vp12);

    LPDIRECT3DVIEWPORT3 vp23 = NULL;
    result = vp22->QueryInterface(IID_IDirect3DViewport3, (LPVOID*)&vp23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp23, NULL);
    IsEqual((LPVOID)vp22, (LPVOID)vp23);
    IsEqual((LPVOID)vp21, (LPVOID)vp23);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DVIEWPORT3 vp33 = NULL;
    result = d3d3->CreateViewport(&vp33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp33, NULL);

    IsNotEqual(vp11, vp33);
    IsNotEqual(vp22, vp33);

    LPDIRECT3DVIEWPORT vp31 = NULL;
    result = vp33->QueryInterface(IID_IDirect3DViewport, (LPVOID*)&vp31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp21, NULL);
    IsEqual((LPVOID)vp33, (LPVOID)vp31);

    LPDIRECT3DVIEWPORT2 vp32 = NULL;
    result = vp11->QueryInterface(IID_IDirect3DViewport2, (LPVOID*)&vp32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)vp32, NULL);
    IsNotEqual((LPVOID)vp32, (LPVOID)vp33);
    IsNotEqual((LPVOID)vp32, (LPVOID)vp31);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DirectDrawCreateViewportQuery(vp11);
    DirectDrawCreateViewportQuery(vp21);
    DirectDrawCreateViewportQuery(vp31);

    DirectDrawCreateViewport2Query(vp12);
    DirectDrawCreateViewport2Query(vp22);
    DirectDrawCreateViewport2Query(vp32);

    DirectDrawCreateViewport3Query(vp13);
    DirectDrawCreateViewport3Query(vp23);
    DirectDrawCreateViewport3Query(vp33);

    DIRECTRELEASE(vp31);
    DIRECTRELEASE(vp32);
    DIRECTRELEASE(vp33);
    DIRECTRELEASE(vp21);
    DIRECTRELEASE(vp22);
    DIRECTRELEASE(vp23);
    DIRECTRELEASE(vp13);
    DIRECTRELEASE(vp12);
    DIRECTRELEASE(vp11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd4);
    DIRECTRELEASE(dd);
}