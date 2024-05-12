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

#include "Direct3DMaterial.hxx"

VOID DirectDrawCreateMaterial(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECT3D d3d1 = NULL;
    result = dd->QueryInterface(IID_IDirect3D, (LPVOID*)&d3d1);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL mat11 = NULL;
    result = d3d1->CreateMaterial(&mat11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);

    LPDIRECT3DMATERIAL2 mat12 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPDIRECT3DMATERIAL3 mat13 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat13, NULL);
    IsNotEqual((LPVOID)mat12, (LPVOID)mat13);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat13);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL2 mat22 = NULL;
    result = d3d2->CreateMaterial(&mat22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat22, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat22);

    LPDIRECT3DMATERIAL mat21 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPDIRECT3DMATERIAL3 mat23 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat23, NULL);
    IsNotEqual((LPVOID)mat22, (LPVOID)mat23);
    IsNotEqual((LPVOID)mat21, (LPVOID)mat23);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL3 mat33 = NULL;
    result = d3d3->CreateMaterial(&mat33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat33, NULL);

    IsNotEqual((LPVOID)mat11, mat33);
    IsNotEqual((LPVOID)mat22, mat33);

    LPDIRECT3DMATERIAL mat31 = NULL;
    result = mat33->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat33, (LPVOID)mat31);

    LPDIRECT3DMATERIAL2 mat32 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat32, NULL);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat33);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat31);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DIRECTRELEASE(mat31);
    DIRECTRELEASE(mat32);
    DIRECTRELEASE(mat33);
    DIRECTRELEASE(mat21);
    DIRECTRELEASE(mat22);
    DIRECTRELEASE(mat23);
    DIRECTRELEASE(mat13);
    DIRECTRELEASE(mat12);
    DIRECTRELEASE(mat11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd);
}

VOID DirectDraw2CreateMaterial(LPMODULE module)
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

    LPDIRECT3DMATERIAL mat11 = NULL;
    result = d3d1->CreateMaterial(&mat11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);

    LPDIRECT3DMATERIAL2 mat12 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPDIRECT3DMATERIAL3 mat13 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat13, NULL);
    IsNotEqual((LPVOID)mat12, (LPVOID)mat13);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat13);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL2 mat22 = NULL;
    result = d3d2->CreateMaterial(&mat22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat22, NULL);
    IsNotEqual((LPVOID)mat11, mat22);

    LPDIRECT3DMATERIAL mat21 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPDIRECT3DMATERIAL3 mat23 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat23, NULL);
    IsNotEqual((LPVOID)mat22, (LPVOID)mat23);
    IsNotEqual((LPVOID)mat21, (LPVOID)mat23);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL3 mat33 = NULL;
    result = d3d3->CreateMaterial(&mat33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat33, NULL);

    IsNotEqual((LPVOID)mat11, mat33);
    IsNotEqual((LPVOID)mat22, mat33);

    LPDIRECT3DMATERIAL mat31 = NULL;
    result = mat33->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat33, (LPVOID)mat31);

    LPDIRECT3DMATERIAL2 mat32 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat32, NULL);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat33);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat31);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DIRECTRELEASE(mat31);
    DIRECTRELEASE(mat32);
    DIRECTRELEASE(mat33);
    DIRECTRELEASE(mat21);
    DIRECTRELEASE(mat22);
    DIRECTRELEASE(mat23);
    DIRECTRELEASE(mat13);
    DIRECTRELEASE(mat12);
    DIRECTRELEASE(mat11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd2);
    DIRECTRELEASE(dd);
}

VOID DirectDraw4CreateMaterial(LPMODULE module)
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

    LPDIRECT3DMATERIAL mat11 = NULL;
    result = d3d1->CreateMaterial(&mat11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);

    LPDIRECT3DMATERIAL2 mat12 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPDIRECT3DMATERIAL3 mat13 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat13, NULL);
    IsNotEqual((LPVOID)mat12, (LPVOID)mat13);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat13);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL2 mat22 = NULL;
    result = d3d2->CreateMaterial(&mat22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat22, NULL);
    IsNotEqual((LPVOID)mat11, mat22);

    LPDIRECT3DMATERIAL mat21 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPDIRECT3DMATERIAL3 mat23 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat23, NULL);
    IsNotEqual((LPVOID)mat22, (LPVOID)mat23);
    IsNotEqual((LPVOID)mat21, (LPVOID)mat23);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL3 mat33 = NULL;
    result = d3d3->CreateMaterial(&mat33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat33, NULL);

    IsNotEqual((LPVOID)mat11, mat33);
    IsNotEqual((LPVOID)mat22, mat33);

    LPDIRECT3DMATERIAL mat31 = NULL;
    result = mat33->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat33, (LPVOID)mat31);

    LPDIRECT3DMATERIAL2 mat32 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat32, NULL);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat33);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat31);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DIRECTRELEASE(mat31);
    DIRECTRELEASE(mat32);
    DIRECTRELEASE(mat33);
    DIRECTRELEASE(mat21);
    DIRECTRELEASE(mat22);
    DIRECTRELEASE(mat23);
    DIRECTRELEASE(mat13);
    DIRECTRELEASE(mat12);
    DIRECTRELEASE(mat11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd4);
    DIRECTRELEASE(dd);
}

VOID DirectDraw7CreateMaterial(LPMODULE module)
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

VOID DirectDrawCreateMaterialQueryInterfaceIUnknown(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECT3D d3d1 = NULL;
    result = dd->QueryInterface(IID_IDirect3D, (LPVOID*)&d3d1);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL mat11 = NULL;
    result = d3d1->CreateMaterial(&mat11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);

    LPUNKNOWN unk11 = NULL;
    result = mat11->QueryInterface(IID_IUnknown, (LPVOID*)&unk11);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk11, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)unk11);

    LPDIRECT3DMATERIAL2 mat12 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPUNKNOWN unk12 = NULL;
    result = mat12->QueryInterface(IID_IUnknown, (LPVOID*)&unk12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk12, NULL);
    IsNotEqual((LPVOID)mat12, (LPVOID)unk12);

    LPDIRECT3DMATERIAL3 mat13 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat13, NULL);
    IsNotEqual((LPVOID)mat12, (LPVOID)mat13);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat13);

    LPUNKNOWN unk13 = NULL;
    result = mat13->QueryInterface(IID_IUnknown, (LPVOID*)&unk13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk13, NULL);
    IsEqual((LPVOID)mat13, (LPVOID)unk13);
    IsEqual((LPVOID)mat13, (LPVOID)unk12);
    IsEqual((LPVOID)mat13, (LPVOID)unk11);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL2 mat22 = NULL;
    result = d3d2->CreateMaterial(&mat22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat22, NULL);
    IsNotEqual((LPVOID)mat11, mat22);

    LPUNKNOWN unk22 = NULL;
    result = mat22->QueryInterface(IID_IUnknown, (LPVOID*)&unk22);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk22, NULL);
    IsNotEqual((LPVOID)mat22, (LPVOID)unk22);

    LPDIRECT3DMATERIAL mat21 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPUNKNOWN unk21 = NULL;
    result = mat21->QueryInterface(IID_IUnknown, (LPVOID*)&unk21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk21, NULL);
    IsNotEqual((LPVOID)mat22, (LPVOID)unk21);

    LPDIRECT3DMATERIAL3 mat23 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat23, NULL);
    IsNotEqual((LPVOID)mat22, (LPVOID)mat23);
    IsNotEqual((LPVOID)mat21, (LPVOID)mat23);

    LPUNKNOWN unk23 = NULL;
    result = mat23->QueryInterface(IID_IUnknown, (LPVOID*)&unk23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk23, NULL);
    IsEqual((LPVOID)mat23, (LPVOID)unk23);
    IsEqual((LPVOID)mat23, (LPVOID)unk22);
    IsEqual((LPVOID)mat23, (LPVOID)unk21);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL3 mat33 = NULL;
    result = d3d3->CreateMaterial(&mat33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat33, NULL);

    IsNotEqual((LPVOID)mat11, mat33);
    IsNotEqual((LPVOID)mat22, mat33);

    LPUNKNOWN unk33 = NULL;
    result = mat33->QueryInterface(IID_IUnknown, (LPVOID*)&unk33);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk33, NULL);
    IsEqual((LPVOID)mat33, (LPVOID)unk33);

    LPDIRECT3DMATERIAL mat31 = NULL;
    result = mat33->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat33, (LPVOID)mat31);

    LPUNKNOWN unk31 = NULL;
    result = mat31->QueryInterface(IID_IUnknown, (LPVOID*)&unk31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk31, NULL);
    IsNotEqual((LPVOID)mat31, (LPVOID)unk31);

    LPDIRECT3DMATERIAL2 mat32 = NULL;
    result = mat31->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat32, NULL);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat33);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat31);

    LPUNKNOWN unk32 = NULL;
    result = mat32->QueryInterface(IID_IUnknown, (LPVOID*)&unk32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk32, NULL);
    IsEqual((LPVOID)mat33, (LPVOID)unk33);
    IsEqual((LPVOID)mat33, (LPVOID)unk32);
    IsEqual((LPVOID)mat33, (LPVOID)unk31);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DIRECTRELEASE(mat31);
    DIRECTRELEASE(mat32);
    DIRECTRELEASE(mat33);
    DIRECTRELEASE(mat21);
    DIRECTRELEASE(mat22);
    DIRECTRELEASE(mat23);
    DIRECTRELEASE(mat13);
    DIRECTRELEASE(mat12);
    DIRECTRELEASE(mat11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd);
}

VOID DirectDraw2CreateMaterialQueryInterfaceIUnknown(LPMODULE module)
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

    LPDIRECT3DMATERIAL mat11 = NULL;
    result = d3d1->CreateMaterial(&mat11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);

    LPUNKNOWN unk11 = NULL;
    result = mat11->QueryInterface(IID_IUnknown, (LPVOID*)&unk11);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk11, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)unk11);

    LPDIRECT3DMATERIAL2 mat12 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPUNKNOWN unk12 = NULL;
    result = mat12->QueryInterface(IID_IUnknown, (LPVOID*)&unk12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk12, NULL);
    IsNotEqual((LPVOID)mat12, (LPVOID)unk12);

    LPDIRECT3DMATERIAL3 mat13 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat13, NULL);
    IsNotEqual((LPVOID)mat12, (LPVOID)mat13);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat13);

    LPUNKNOWN unk13 = NULL;
    result = mat13->QueryInterface(IID_IUnknown, (LPVOID*)&unk13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk13, NULL);
    IsEqual((LPVOID)mat13, (LPVOID)unk13);
    IsEqual((LPVOID)mat13, (LPVOID)unk12);
    IsEqual((LPVOID)mat13, (LPVOID)unk11);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL2 mat22 = NULL;
    result = d3d2->CreateMaterial(&mat22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat22, NULL);
    IsNotEqual((LPVOID)mat11, mat22);

    LPUNKNOWN unk22 = NULL;
    result = mat22->QueryInterface(IID_IUnknown, (LPVOID*)&unk22);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk22, NULL);
    IsNotEqual((LPVOID)mat22, (LPVOID)unk22);

    LPDIRECT3DMATERIAL mat21 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPUNKNOWN unk21 = NULL;
    result = mat21->QueryInterface(IID_IUnknown, (LPVOID*)&unk21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk21, NULL);
    IsNotEqual((LPVOID)mat22, (LPVOID)unk21);

    LPDIRECT3DMATERIAL3 mat23 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat23, NULL);
    IsNotEqual((LPVOID)mat22, (LPVOID)mat23);
    IsNotEqual((LPVOID)mat21, (LPVOID)mat23);

    LPUNKNOWN unk23 = NULL;
    result = mat23->QueryInterface(IID_IUnknown, (LPVOID*)&unk23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk23, NULL);
    IsEqual((LPVOID)mat23, (LPVOID)unk23);
    IsEqual((LPVOID)mat23, (LPVOID)unk22);
    IsEqual((LPVOID)mat23, (LPVOID)unk21);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL3 mat33 = NULL;
    result = d3d3->CreateMaterial(&mat33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat33, NULL);

    IsNotEqual((LPVOID)mat11, mat33);
    IsNotEqual((LPVOID)mat22, mat33);

    LPUNKNOWN unk33 = NULL;
    result = mat33->QueryInterface(IID_IUnknown, (LPVOID*)&unk33);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk33, NULL);
    IsEqual((LPVOID)mat33, (LPVOID)unk33);

    LPDIRECT3DMATERIAL mat31 = NULL;
    result = mat33->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat33, (LPVOID)mat31);

    LPUNKNOWN unk31 = NULL;
    result = mat31->QueryInterface(IID_IUnknown, (LPVOID*)&unk31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk31, NULL);
    IsNotEqual((LPVOID)mat31, (LPVOID)unk31);

    LPDIRECT3DMATERIAL2 mat32 = NULL;
    result = mat31->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat32, NULL);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat33);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat31);

    LPUNKNOWN unk32 = NULL;
    result = mat32->QueryInterface(IID_IUnknown, (LPVOID*)&unk32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk32, NULL);
    IsEqual((LPVOID)mat33, (LPVOID)unk32);
    IsEqual((LPVOID)mat33, (LPVOID)unk33);
    IsEqual((LPVOID)mat33, (LPVOID)unk31);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DIRECTRELEASE(mat31);
    DIRECTRELEASE(mat32);
    DIRECTRELEASE(mat33);
    DIRECTRELEASE(mat21);
    DIRECTRELEASE(mat22);
    DIRECTRELEASE(mat23);
    DIRECTRELEASE(mat13);
    DIRECTRELEASE(mat12);
    DIRECTRELEASE(mat11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd2);
    DIRECTRELEASE(dd);
}

VOID DirectDraw4CreateMaterialQueryInterfaceIUnknown(LPMODULE module)
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

    LPDIRECT3DMATERIAL mat11 = NULL;
    result = d3d1->CreateMaterial(&mat11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);

    LPUNKNOWN unk11 = NULL;
    result = mat11->QueryInterface(IID_IUnknown, (LPVOID*)&unk11);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk11, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)unk11);

    LPDIRECT3DMATERIAL2 mat12 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPUNKNOWN unk12 = NULL;
    result = mat12->QueryInterface(IID_IUnknown, (LPVOID*)&unk12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk12, NULL);
    IsNotEqual((LPVOID)mat12, (LPVOID)unk12);

    LPDIRECT3DMATERIAL3 mat13 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat13, NULL);
    IsNotEqual((LPVOID)mat12, (LPVOID)mat13);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat13);

    LPUNKNOWN unk13 = NULL;
    result = mat13->QueryInterface(IID_IUnknown, (LPVOID*)&unk13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk13, NULL);
    IsEqual((LPVOID)mat13, (LPVOID)unk13);
    IsEqual((LPVOID)mat13, (LPVOID)unk12);
    IsEqual((LPVOID)mat13, (LPVOID)unk11);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL2 mat22 = NULL;
    result = d3d2->CreateMaterial(&mat22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat22, NULL);
    IsNotEqual((LPVOID)mat11, mat22);

    LPUNKNOWN unk22 = NULL;
    result = mat22->QueryInterface(IID_IUnknown, (LPVOID*)&unk22);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk22, NULL);
    IsNotEqual((LPVOID)mat22, (LPVOID)unk22);

    LPDIRECT3DMATERIAL mat21 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPUNKNOWN unk21 = NULL;
    result = mat21->QueryInterface(IID_IUnknown, (LPVOID*)&unk21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk21, NULL);
    IsNotEqual((LPVOID)mat22, (LPVOID)unk21);

    LPDIRECT3DMATERIAL3 mat23 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat23, NULL);
    IsNotEqual((LPVOID)mat22, (LPVOID)mat23);
    IsNotEqual((LPVOID)mat21, (LPVOID)mat23);

    LPUNKNOWN unk23 = NULL;
    result = mat23->QueryInterface(IID_IUnknown, (LPVOID*)&unk23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk23, NULL);
    IsEqual((LPVOID)mat23, (LPVOID)unk23);
    IsEqual((LPVOID)mat23, (LPVOID)unk22);
    IsEqual((LPVOID)mat23, (LPVOID)unk21);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL3 mat33 = NULL;
    result = d3d3->CreateMaterial(&mat33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat33, NULL);

    IsNotEqual((LPVOID)mat11, mat33);
    IsNotEqual((LPVOID)mat22, mat33);

    LPUNKNOWN unk33 = NULL;
    result = mat33->QueryInterface(IID_IUnknown, (LPVOID*)&unk33);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk33, NULL);
    IsEqual((LPVOID)mat33, (LPVOID)unk33);

    LPDIRECT3DMATERIAL mat31 = NULL;
    result = mat33->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat33, (LPVOID)mat31);

    LPUNKNOWN unk31 = NULL;
    result = mat31->QueryInterface(IID_IUnknown, (LPVOID*)&unk31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk31, NULL);
    IsNotEqual((LPVOID)mat31, (LPVOID)unk31);

    LPDIRECT3DMATERIAL2 mat32 = NULL;
    result = mat31->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat32, NULL);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat33);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat31);

    LPUNKNOWN unk32 = NULL;
    result = mat32->QueryInterface(IID_IUnknown, (LPVOID*)&unk32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)unk32, NULL);
    IsNotEqual((LPVOID)mat33, (LPVOID)mat32);

    IsEqual((LPVOID)mat33, (LPVOID)unk32);
    IsEqual((LPVOID)mat33, (LPVOID)unk33);
    IsEqual((LPVOID)mat33, (LPVOID)unk31);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DIRECTRELEASE(mat31);
    DIRECTRELEASE(mat32);
    DIRECTRELEASE(mat33);
    DIRECTRELEASE(mat21);
    DIRECTRELEASE(mat22);
    DIRECTRELEASE(mat23);
    DIRECTRELEASE(mat13);
    DIRECTRELEASE(mat12);
    DIRECTRELEASE(mat11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd4);
    DIRECTRELEASE(dd);
}

VOID DirectDrawCreateMaterialQuery(LPDIRECT3DMATERIAL mat)
{
    /* Direct3D */

    LPDIRECT3D dd3d1 = NULL;
    HRESULT result = mat->QueryInterface(IID_IDirect3D, (LPVOID*)&dd3d1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d1, NULL);

    LPDIRECT3D2 dd3d2 = NULL;
    result = mat->QueryInterface(IID_IDirect3D2, (LPVOID*)&dd3d2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d2, NULL);

    LPDIRECT3D3 dd3d3 = NULL;
    result = mat->QueryInterface(IID_IDirect3D3, (LPVOID*)&dd3d3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d3, NULL);

    LPDIRECT3D3 dd3d7 = NULL;
    result = mat->QueryInterface(IID_IDirect3D7, (LPVOID*)&dd3d7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d7, NULL);

    /* Direct3DDevice */

    LPDIRECT3DDEVICE dd3dd1 = NULL;
    result = mat->QueryInterface(IID_IDirect3DDevice, (LPVOID*)&dd3dd1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    LPDIRECT3DDEVICE2 dd3dd2 = NULL;
    result = mat->QueryInterface(IID_IDirect3DDevice2, (LPVOID*)&dd3dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd2, NULL);

    LPDIRECT3DDEVICE3 dd3dd3 = NULL;
    result = mat->QueryInterface(IID_IDirect3DDevice3, (LPVOID*)&dd3dd3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd3, NULL);

    LPDIRECT3DDEVICE7 dd3dd7 = NULL;
    result = mat->QueryInterface(IID_IDirect3DDevice7, (LPVOID*)&dd3dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd7, NULL);

    LPDIRECT3DDEVICE d3drd = NULL;
    result = mat->QueryInterface(IID_IDirect3DRampDevice, (LPVOID*)&d3drd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drd, NULL);

    LPDIRECT3DDEVICE d3drgbd = NULL;
    result = mat->QueryInterface(IID_IDirect3DRGBDevice, (LPVOID*)&d3drgbd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drgbd, NULL);

    LPDIRECT3DDEVICE d3dhald = NULL;
    result = mat->QueryInterface(IID_IDirect3DHALDevice, (LPVOID*)&d3dhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dhald, NULL);

    LPDIRECT3DDEVICE d3dmmxd = NULL;
    result = mat->QueryInterface(IID_IDirect3DMMXDevice, (LPVOID*)&d3dmmxd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dmmxd, NULL);

    LPDIRECT3DDEVICE d3drefd = NULL;
    result = mat->QueryInterface(IID_IDirect3DRefDevice, (LPVOID*)&d3drefd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drefd, NULL);

    LPDIRECT3DDEVICE d3dnd = NULL;
    result = mat->QueryInterface(IID_IDirect3DNullDevice, (LPVOID*)&d3dnd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dnd, NULL);

    LPDIRECT3DDEVICE d3dtnlhald = NULL;
    result = mat->QueryInterface(IID_IDirect3DTnLHalDevice, (LPVOID*)&d3dtnlhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dtnlhald, NULL);

    /* Direct3DExecuteBuffer */

    LPDIRECT3DEXECUTEBUFFER d3deb = NULL;
    result = mat->QueryInterface(IID_IDirect3DExecuteBuffer, (LPVOID*)&d3deb);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    /* Direct3DLight */

    LPDIRECT3DLIGHT d3dl = NULL;
    result = mat->QueryInterface(IID_IDirect3DLight, (LPVOID*)&d3dl);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dl, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dm1 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dm1);
    IsEqual(result, DD_OK);
    IsEqual((LPVOID)mat, d3dm1);
    DIRECTRELEASE(d3dm1);

    LPDIRECT3DMATERIAL2 d3dm2 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dm2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat, d3dm2);
    DIRECTRELEASE(d3dm2);

    LPDIRECT3DMATERIAL3 d3dm3 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dm3);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat, d3dm3);
    DIRECTRELEASE(d3dm3);

    /* Direct3DTexture */

    LPDIRECT3DTEXTURE d3dt1 = NULL;
    result = mat->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&d3dt1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt1, NULL);

    LPDIRECT3DTEXTURE2 d3dt2 = NULL;
    result = mat->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&d3dt2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt2, NULL);

    /* Direct3DVertexBuffer */

    LPDIRECT3DVERTEXBUFFER d3dvb1 = NULL;
    result = mat->QueryInterface(IID_IDirect3DVertexBuffer, (LPVOID*)&d3dvb1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb1, NULL);

    LPDIRECT3DVERTEXBUFFER7 d3dvb7 = NULL;
    result = mat->QueryInterface(IID_IDirect3DVertexBuffer7, (LPVOID*)&d3dvb7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb7, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dmat1 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dmat1);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dmat1, NULL);
    IsEqual(d3dmat1, mat);
    DIRECTRELEASE(d3dmat1);

    LPDIRECT3DMATERIAL2 d3dmat2 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dmat2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dmat2, NULL);
    IsNotEqual((LPVOID)d3dmat2, mat);
    DIRECTRELEASE(d3dmat2);

    LPDIRECT3DMATERIAL3 d3dmat3 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dmat3);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dmat3, NULL);
    IsNotEqual((LPVOID)d3dmat3, mat);
    DIRECTRELEASE(d3dmat3);

    /* DirectDraw */

    LPDIRECTDRAW dd = NULL;
    result = mat->QueryInterface(IID_IDirectDraw, (LPVOID*)&dd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd, NULL);

    LPDIRECTDRAW2 dd2 = NULL;
    result = mat->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd2, NULL);

    LPDIRECTDRAW4 dd4 = NULL;
    result = mat->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd4, NULL);

    LPDIRECTDRAW7 dd7 = NULL;
    result = mat->QueryInterface(IID_IDirectDraw7, (LPVOID*)&dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd7, NULL);

    /* DirectDrawClipper */

    LPDIRECTDRAWCLIPPER ddc = NULL;
    result = mat->QueryInterface(IID_IDirectDrawClipper, (LPVOID*)&ddc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddc, NULL);

    /* DirectDrawColorControl */

    LPDIRECTDRAWCOLORCONTROL ddcc = NULL;
    result = mat->QueryInterface(IID_IDirectDrawColorControl, (LPVOID*)&ddcc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddcc, NULL);

    /* DirectDrawGammaControl */

    LPDIRECTDRAWGAMMACONTROL ddgc = NULL;
    result = mat->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&ddgc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddgc, NULL);

    /* DirectDrawPalette */

    LPDIRECTDRAWPALETTE ddp = NULL;
    result = mat->QueryInterface(IID_IDirectDrawPalette, (LPVOID*)&ddp);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddp, NULL);

    /* DirectDrawSurface */

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds1, NULL);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds2, NULL);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds3, NULL);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds4, NULL);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds7, NULL);

    /* DirectDrawVideoPort */

    LPDIRECTDRAWVIDEOPORT ddmat = NULL;
    result = mat->QueryInterface(IID_IDirectDrawVideoPort, (LPVOID*)&ddmat);
    IsNotEqual(result, DD_OK);
    IsEqual(ddmat, NULL);

    /* DirectDrawVideoPortContainer */

    LPDDVIDEOPORTCONTAINER ddmatc = NULL;
    result = mat->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&ddmatc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddmatc, NULL);

    /* DirectDrawVideoPortNotify */

    LPDDVIDEOPORTNOTIFY ddmatn = NULL;
    result = mat->QueryInterface(IID_IDirectDrawVideoPortNotify, (LPVOID*)&ddmatn);
    IsNotEqual(result, DD_OK);

    /* DirectDrawFactory2 */

    LPUNKNOWN ddf2 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawFactory2, (LPVOID*)&ddf2);
    IsNotEqual(result, DD_OK);

    /* IDirectDrawPalette2 */

    LPUNKNOWN ddp2 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawPalette2, (LPVOID*)&ddp2);
    IsNotEqual(result, DD_OK);

    /* DirectDrawKernel */

    LPUNKNOWN ddk = NULL;
    result = mat->QueryInterface(IID_IDirectDrawKernel, (LPVOID*)&ddk);
    IsNotEqual(result, DD_OK);

    /* DirectDrawOptSurface */

    LPUNKNOWN ddos = NULL;
    result = mat->QueryInterface(IID_IDirectDrawOptSurface, (LPVOID*)&ddos);
    IsNotEqual(result, DD_OK);

    /* DirectDrawSurfaceKernel */

    LPUNKNOWN ddsk = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurfaceKernel, (LPVOID*)&ddsk);
    IsNotEqual(result, DD_OK);

    /* DirectDrawSurfaceNew */

    LPUNKNOWN ddsn = NULL;
    result = mat->QueryInterface(IID_IDirectDrawOptSurface, (LPVOID*)&ddsn);
    IsNotEqual(result, DD_OK);

    /* Unknown */

    LPUNKNOWN unk = NULL;
    result = mat->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);
    IsNotEqual(mat, unk);
    DIRECTRELEASE(unk);
}

VOID DirectDrawCreateMaterial2Query(LPDIRECT3DMATERIAL2 mat)
{
    /* Direct3D */

    LPDIRECT3D dd3d1 = NULL;
    HRESULT result = mat->QueryInterface(IID_IDirect3D, (LPVOID*)&dd3d1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d1, NULL);

    LPDIRECT3D2 dd3d2 = NULL;
    result = mat->QueryInterface(IID_IDirect3D2, (LPVOID*)&dd3d2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d2, NULL);

    LPDIRECT3D3 dd3d3 = NULL;
    result = mat->QueryInterface(IID_IDirect3D3, (LPVOID*)&dd3d3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d3, NULL);

    LPDIRECT3D3 dd3d7 = NULL;
    result = mat->QueryInterface(IID_IDirect3D7, (LPVOID*)&dd3d7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d7, NULL);

    /* Direct3DDevice */

    LPDIRECT3DDEVICE dd3dd1 = NULL;
    result = mat->QueryInterface(IID_IDirect3DDevice, (LPVOID*)&dd3dd1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    LPDIRECT3DDEVICE2 dd3dd2 = NULL;
    result = mat->QueryInterface(IID_IDirect3DDevice2, (LPVOID*)&dd3dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd2, NULL);

    LPDIRECT3DDEVICE3 dd3dd3 = NULL;
    result = mat->QueryInterface(IID_IDirect3DDevice3, (LPVOID*)&dd3dd3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd3, NULL);

    LPDIRECT3DDEVICE7 dd3dd7 = NULL;
    result = mat->QueryInterface(IID_IDirect3DDevice7, (LPVOID*)&dd3dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd7, NULL);

    LPDIRECT3DDEVICE d3drd = NULL;
    result = mat->QueryInterface(IID_IDirect3DRampDevice, (LPVOID*)&d3drd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drd, NULL);

    LPDIRECT3DDEVICE d3drgbd = NULL;
    result = mat->QueryInterface(IID_IDirect3DRGBDevice, (LPVOID*)&d3drgbd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drgbd, NULL);

    LPDIRECT3DDEVICE d3dhald = NULL;
    result = mat->QueryInterface(IID_IDirect3DHALDevice, (LPVOID*)&d3dhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dhald, NULL);

    LPDIRECT3DDEVICE d3dmmxd = NULL;
    result = mat->QueryInterface(IID_IDirect3DMMXDevice, (LPVOID*)&d3dmmxd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dmmxd, NULL);

    LPDIRECT3DDEVICE d3drefd = NULL;
    result = mat->QueryInterface(IID_IDirect3DRefDevice, (LPVOID*)&d3drefd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drefd, NULL);

    LPDIRECT3DDEVICE d3dnd = NULL;
    result = mat->QueryInterface(IID_IDirect3DNullDevice, (LPVOID*)&d3dnd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dnd, NULL);

    LPDIRECT3DDEVICE d3dtnlhald = NULL;
    result = mat->QueryInterface(IID_IDirect3DTnLHalDevice, (LPVOID*)&d3dtnlhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dtnlhald, NULL);

    /* Direct3DExecuteBuffer */

    LPDIRECT3DEXECUTEBUFFER d3deb = NULL;
    result = mat->QueryInterface(IID_IDirect3DExecuteBuffer, (LPVOID*)&d3deb);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    /* Direct3DLight */

    LPDIRECT3DLIGHT d3dl = NULL;
    result = mat->QueryInterface(IID_IDirect3DLight, (LPVOID*)&d3dl);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dl, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dm1 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dm1);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dm1, NULL);
    IsNotEqual((LPVOID)mat, d3dm1);
    DIRECTRELEASE(d3dm1);

    LPDIRECT3DMATERIAL2 d3dm2 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dm2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dm2, NULL);
    IsEqual(mat, d3dm2);
    DIRECTRELEASE(d3dm2);

    LPDIRECT3DMATERIAL3 d3dm3 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dm3);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dm3, NULL);
    IsNotEqual((LPVOID)mat, d3dm3);
    DIRECTRELEASE(d3dm3);

    /* Direct3DTexture */

    LPDIRECT3DTEXTURE d3dt1 = NULL;
    result = mat->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&d3dt1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt1, NULL);

    LPDIRECT3DTEXTURE2 d3dt2 = NULL;
    result = mat->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&d3dt2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt2, NULL);

    /* Direct3DVertexBuffer */

    LPDIRECT3DVERTEXBUFFER d3dvb1 = NULL;
    result = mat->QueryInterface(IID_IDirect3DVertexBuffer, (LPVOID*)&d3dvb1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb1, NULL);

    LPDIRECT3DVERTEXBUFFER7 d3dvb7 = NULL;
    result = mat->QueryInterface(IID_IDirect3DVertexBuffer7, (LPVOID*)&d3dvb7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb7, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dmat1 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dmat1);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dmat1, NULL);
    IsNotEqual((LPVOID)d3dmat1, mat);
    DIRECTRELEASE(d3dmat1);

    LPDIRECT3DMATERIAL2 d3dmat2 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dmat2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dmat2, NULL);
    IsEqual(d3dmat2, mat);
    DIRECTRELEASE(d3dmat2);

    LPDIRECT3DMATERIAL3 d3dmat3 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dmat3);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dmat3, NULL);
    IsNotEqual((LPVOID)d3dmat3, mat);
    DIRECTRELEASE(d3dmat3);

    /* DirectDraw */

    LPDIRECTDRAW dd = NULL;
    result = mat->QueryInterface(IID_IDirectDraw, (LPVOID*)&dd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd, NULL);

    LPDIRECTDRAW2 dd2 = NULL;
    result = mat->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd2, NULL);

    LPDIRECTDRAW4 dd4 = NULL;
    result = mat->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd4, NULL);

    LPDIRECTDRAW7 dd7 = NULL;
    result = mat->QueryInterface(IID_IDirectDraw7, (LPVOID*)&dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd7, NULL);

    /* DirectDrawClipper */

    LPDIRECTDRAWCLIPPER ddc = NULL;
    result = mat->QueryInterface(IID_IDirectDrawClipper, (LPVOID*)&ddc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddc, NULL);

    /* DirectDrawColorControl */

    LPDIRECTDRAWCOLORCONTROL ddcc = NULL;
    result = mat->QueryInterface(IID_IDirectDrawColorControl, (LPVOID*)&ddcc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddcc, NULL);

    /* DirectDrawGammaControl */

    LPDIRECTDRAWGAMMACONTROL ddgc = NULL;
    result = mat->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&ddgc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddgc, NULL);

    /* DirectDrawPalette */

    LPDIRECTDRAWPALETTE ddp = NULL;
    result = mat->QueryInterface(IID_IDirectDrawPalette, (LPVOID*)&ddp);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddp, NULL);

    /* DirectDrawSurface */

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds1, NULL);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds2, NULL);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds3, NULL);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds4, NULL);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds7, NULL);

    /* DirectDrawVideoPort */

    LPDIRECTDRAWVIDEOPORT ddmat = NULL;
    result = mat->QueryInterface(IID_IDirectDrawVideoPort, (LPVOID*)&ddmat);
    IsNotEqual(result, DD_OK);
    IsEqual(ddmat, NULL);

    /* DirectDrawVideoPortContainer */

    LPDDVIDEOPORTCONTAINER ddmatc = NULL;
    result = mat->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&ddmatc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddmatc, NULL);

    /* DirectDrawVideoPortNotify */

    LPDDVIDEOPORTNOTIFY ddmatn = NULL;
    result = mat->QueryInterface(IID_IDirectDrawVideoPortNotify, (LPVOID*)&ddmatn);
    IsNotEqual(result, DD_OK);

    /* DirectDrawFactory2 */

    LPUNKNOWN ddf2 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawFactory2, (LPVOID*)&ddf2);
    IsNotEqual(result, DD_OK);

    /* IDirectDrawPalette2 */

    LPUNKNOWN ddp2 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawPalette2, (LPVOID*)&ddp2);
    IsNotEqual(result, DD_OK);

    /* DirectDrawKernel */

    LPUNKNOWN ddk = NULL;
    result = mat->QueryInterface(IID_IDirectDrawKernel, (LPVOID*)&ddk);
    IsNotEqual(result, DD_OK);

    /* DirectDrawOptSurface */

    LPUNKNOWN ddos = NULL;
    result = mat->QueryInterface(IID_IDirectDrawOptSurface, (LPVOID*)&ddos);
    IsNotEqual(result, DD_OK);

    /* DirectDrawSurfaceKernel */

    LPUNKNOWN ddsk = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurfaceKernel, (LPVOID*)&ddsk);
    IsNotEqual(result, DD_OK);

    /* DirectDrawSurfaceNew */

    LPUNKNOWN ddsn = NULL;
    result = mat->QueryInterface(IID_IDirectDrawOptSurface, (LPVOID*)&ddsn);
    IsNotEqual(result, DD_OK);

    /* Unknown */

    LPUNKNOWN unk = NULL;
    result = mat->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);
    IsNotEqual(mat, unk);
    DIRECTRELEASE(unk);
}

VOID DirectDrawCreateMaterial3Query(LPDIRECT3DMATERIAL3 mat)
{
    /* Direct3D */

    LPDIRECT3D dd3d1 = NULL;
    HRESULT result = mat->QueryInterface(IID_IDirect3D, (LPVOID*)&dd3d1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d1, NULL);

    LPDIRECT3D2 dd3d2 = NULL;
    result = mat->QueryInterface(IID_IDirect3D2, (LPVOID*)&dd3d2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d2, NULL);

    LPDIRECT3D3 dd3d3 = NULL;
    result = mat->QueryInterface(IID_IDirect3D3, (LPVOID*)&dd3d3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d3, NULL);

    LPDIRECT3D3 dd3d7 = NULL;
    result = mat->QueryInterface(IID_IDirect3D7, (LPVOID*)&dd3d7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3d7, NULL);

    /* Direct3DDevice */

    LPDIRECT3DDEVICE dd3dd1 = NULL;
    result = mat->QueryInterface(IID_IDirect3DDevice, (LPVOID*)&dd3dd1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    LPDIRECT3DDEVICE2 dd3dd2 = NULL;
    result = mat->QueryInterface(IID_IDirect3DDevice2, (LPVOID*)&dd3dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd2, NULL);

    LPDIRECT3DDEVICE3 dd3dd3 = NULL;
    result = mat->QueryInterface(IID_IDirect3DDevice3, (LPVOID*)&dd3dd3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd3, NULL);

    LPDIRECT3DDEVICE7 dd3dd7 = NULL;
    result = mat->QueryInterface(IID_IDirect3DDevice7, (LPVOID*)&dd3dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd7, NULL);

    LPDIRECT3DDEVICE d3drd = NULL;
    result = mat->QueryInterface(IID_IDirect3DRampDevice, (LPVOID*)&d3drd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drd, NULL);

    LPDIRECT3DDEVICE d3drgbd = NULL;
    result = mat->QueryInterface(IID_IDirect3DRGBDevice, (LPVOID*)&d3drgbd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drgbd, NULL);

    LPDIRECT3DDEVICE d3dhald = NULL;
    result = mat->QueryInterface(IID_IDirect3DHALDevice, (LPVOID*)&d3dhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dhald, NULL);

    LPDIRECT3DDEVICE d3dmmxd = NULL;
    result = mat->QueryInterface(IID_IDirect3DMMXDevice, (LPVOID*)&d3dmmxd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dmmxd, NULL);

    LPDIRECT3DDEVICE d3drefd = NULL;
    result = mat->QueryInterface(IID_IDirect3DRefDevice, (LPVOID*)&d3drefd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3drefd, NULL);

    LPDIRECT3DDEVICE d3dnd = NULL;
    result = mat->QueryInterface(IID_IDirect3DNullDevice, (LPVOID*)&d3dnd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dnd, NULL);

    LPDIRECT3DDEVICE d3dtnlhald = NULL;
    result = mat->QueryInterface(IID_IDirect3DTnLHalDevice, (LPVOID*)&d3dtnlhald);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dtnlhald, NULL);

    /* Direct3DExecuteBuffer */

    LPDIRECT3DEXECUTEBUFFER d3deb = NULL;
    result = mat->QueryInterface(IID_IDirect3DExecuteBuffer, (LPVOID*)&d3deb);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd3dd1, NULL);

    /* Direct3DLight */

    LPDIRECT3DLIGHT d3dl = NULL;
    result = mat->QueryInterface(IID_IDirect3DLight, (LPVOID*)&d3dl);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dl, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dm1 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dm1);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dm1, NULL);
    IsNotEqual((LPVOID)mat, d3dm1);
    DIRECTRELEASE(d3dm1);

    LPDIRECT3DMATERIAL2 d3dm2 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dm2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dm2, NULL);
    IsNotEqual((LPVOID)mat, d3dm2);
    DIRECTRELEASE(d3dm2);

    LPDIRECT3DMATERIAL3 d3dm3 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dm3);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dm3, NULL);
    IsEqual(mat, d3dm3);
    DIRECTRELEASE(d3dm3);

    /* Direct3DTexture */

    LPDIRECT3DTEXTURE d3dt1 = NULL;
    result = mat->QueryInterface(IID_IDirect3DTexture, (LPVOID*)&d3dt1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt1, NULL);

    LPDIRECT3DTEXTURE2 d3dt2 = NULL;
    result = mat->QueryInterface(IID_IDirect3DTexture2, (LPVOID*)&d3dt2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dt2, NULL);

    /* Direct3DVertexBuffer */

    LPDIRECT3DVERTEXBUFFER d3dvb1 = NULL;
    result = mat->QueryInterface(IID_IDirect3DVertexBuffer, (LPVOID*)&d3dvb1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb1, NULL);

    LPDIRECT3DVERTEXBUFFER7 d3dvb7 = NULL;
    result = mat->QueryInterface(IID_IDirect3DVertexBuffer7, (LPVOID*)&d3dvb7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)d3dvb7, NULL);

    /* Direct3DMaterial */

    LPDIRECT3DMATERIAL d3dmat1 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&d3dmat1);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dmat1, NULL);
    IsNotEqual((LPVOID)d3dmat1, mat);
    DIRECTRELEASE(d3dmat1);

    LPDIRECT3DMATERIAL2 d3dmat2 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&d3dmat2);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dmat2, NULL);
    IsNotEqual((LPVOID)d3dmat2, mat);
    DIRECTRELEASE(d3dmat2);

    LPDIRECT3DMATERIAL3 d3dmat3 = NULL;
    result = mat->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&d3dmat3);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)d3dmat3, NULL);
    IsEqual(d3dmat3, mat);
    DIRECTRELEASE(d3dmat3);

    /* DirectDraw */

    LPDIRECTDRAW dd = NULL;
    result = mat->QueryInterface(IID_IDirectDraw, (LPVOID*)&dd);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd, NULL);

    LPDIRECTDRAW2 dd2 = NULL;
    result = mat->QueryInterface(IID_IDirectDraw2, (LPVOID*)&dd2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd2, NULL);

    LPDIRECTDRAW4 dd4 = NULL;
    result = mat->QueryInterface(IID_IDirectDraw4, (LPVOID*)&dd4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd4, NULL);

    LPDIRECTDRAW7 dd7 = NULL;
    result = mat->QueryInterface(IID_IDirectDraw7, (LPVOID*)&dd7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dd7, NULL);

    /* DirectDrawClipper */

    LPDIRECTDRAWCLIPPER ddc = NULL;
    result = mat->QueryInterface(IID_IDirectDrawClipper, (LPVOID*)&ddc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddc, NULL);

    /* DirectDrawColorControl */

    LPDIRECTDRAWCOLORCONTROL ddcc = NULL;
    result = mat->QueryInterface(IID_IDirectDrawColorControl, (LPVOID*)&ddcc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddcc, NULL);

    /* DirectDrawGammaControl */

    LPDIRECTDRAWGAMMACONTROL ddgc = NULL;
    result = mat->QueryInterface(IID_IDirectDrawGammaControl, (LPVOID*)&ddgc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddgc, NULL);

    /* DirectDrawPalette */

    LPDIRECTDRAWPALETTE ddp = NULL;
    result = mat->QueryInterface(IID_IDirectDrawPalette, (LPVOID*)&ddp);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddp, NULL);

    /* DirectDrawSurface */

    LPDIRECTDRAWSURFACE dds1 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&dds1);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds1, NULL);

    LPDIRECTDRAWSURFACE2 dds2 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurface2, (LPVOID*)&dds2);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds2, NULL);

    LPDIRECTDRAWSURFACE3 dds3 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurface3, (LPVOID*)&dds3);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds3, NULL);

    LPDIRECTDRAWSURFACE4 dds4 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurface4, (LPVOID*)&dds4);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds4, NULL);

    LPDIRECTDRAWSURFACE7 dds7 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurface7, (LPVOID*)&dds7);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)dds7, NULL);

    /* DirectDrawVideoPort */

    LPDIRECTDRAWVIDEOPORT ddmat = NULL;
    result = mat->QueryInterface(IID_IDirectDrawVideoPort, (LPVOID*)&ddmat);
    IsNotEqual(result, DD_OK);
    IsEqual(ddmat, NULL);

    /* DirectDrawVideoPortContainer */

    LPDDVIDEOPORTCONTAINER ddmatc = NULL;
    result = mat->QueryInterface(IID_IDDVideoPortContainer, (LPVOID*)&ddmatc);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)ddmatc, NULL);

    /* DirectDrawVideoPortNotify */

    LPDDVIDEOPORTNOTIFY ddmatn = NULL;
    result = mat->QueryInterface(IID_IDirectDrawVideoPortNotify, (LPVOID*)&ddmatn);
    IsNotEqual(result, DD_OK);

    /* DirectDrawFactory2 */

    LPUNKNOWN ddf2 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawFactory2, (LPVOID*)&ddf2);
    IsNotEqual(result, DD_OK);

    /* IDirectDrawPalette2 */

    LPUNKNOWN ddp2 = NULL;
    result = mat->QueryInterface(IID_IDirectDrawPalette2, (LPVOID*)&ddp2);
    IsNotEqual(result, DD_OK);

    /* DirectDrawKernel */

    LPUNKNOWN ddk = NULL;
    result = mat->QueryInterface(IID_IDirectDrawKernel, (LPVOID*)&ddk);
    IsNotEqual(result, DD_OK);

    /* DirectDrawOptSurface */

    LPUNKNOWN ddos = NULL;
    result = mat->QueryInterface(IID_IDirectDrawOptSurface, (LPVOID*)&ddos);
    IsNotEqual(result, DD_OK);

    /* DirectDrawSurfaceKernel */

    LPUNKNOWN ddsk = NULL;
    result = mat->QueryInterface(IID_IDirectDrawSurfaceKernel, (LPVOID*)&ddsk);
    IsNotEqual(result, DD_OK);

    /* DirectDrawSurfaceNew */

    LPUNKNOWN ddsn = NULL;
    result = mat->QueryInterface(IID_IDirectDrawOptSurface, (LPVOID*)&ddsn);
    IsNotEqual(result, DD_OK);

    /* Unknown */

    LPUNKNOWN unk = NULL;
    result = mat->QueryInterface(IID_IUnknown, (LPVOID*)&unk);
    IsEqual(result, DD_OK);
    IsEqual(mat, unk);
    DIRECTRELEASE(unk);
}

VOID DirectDrawCreateMaterialQueryInterfaceAll(LPMODULE module)
{
    LPDIRECTDRAW dd = NULL;
    HRESULT result = module->DirectDrawCreate(NULL, &dd, NULL);
    IsEqual(result, DD_OK);

    LPDIRECT3D d3d1 = NULL;
    result = dd->QueryInterface(IID_IDirect3D, (LPVOID*)&d3d1);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL mat11 = NULL;
    result = d3d1->CreateMaterial(&mat11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);

    LPDIRECT3DMATERIAL2 mat12 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPDIRECT3DMATERIAL3 mat13 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat13, NULL);
    IsNotEqual((LPVOID)mat12, (LPVOID)mat13);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat13);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL2 mat22 = NULL;
    result = d3d2->CreateMaterial(&mat22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat22, NULL);
    IsNotEqual((LPVOID)mat11, mat22);

    LPDIRECT3DMATERIAL mat21 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPDIRECT3DMATERIAL3 mat23 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat23, NULL);
    IsNotEqual((LPVOID)mat22, (LPVOID)mat23);
    IsNotEqual((LPVOID)mat21, (LPVOID)mat23);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL3 mat33 = NULL;
    result = d3d3->CreateMaterial(&mat33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat33, NULL);

    IsNotEqual((LPVOID)mat11, mat33);
    IsNotEqual((LPVOID)mat22, mat33);

    LPDIRECT3DMATERIAL mat31 = NULL;
    result = mat33->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat33, (LPVOID)mat31);

    LPDIRECT3DMATERIAL2 mat32 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat32, NULL);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat33);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat31);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DirectDrawCreateMaterialQuery(mat11);
    DirectDrawCreateMaterialQuery(mat21);
    DirectDrawCreateMaterialQuery(mat31);

    DirectDrawCreateMaterial2Query(mat12);
    DirectDrawCreateMaterial2Query(mat22);
    DirectDrawCreateMaterial2Query(mat32);

    DirectDrawCreateMaterial3Query(mat13);
    DirectDrawCreateMaterial3Query(mat23);
    DirectDrawCreateMaterial3Query(mat33);

    DIRECTRELEASE(mat31);
    DIRECTRELEASE(mat32);
    DIRECTRELEASE(mat33);
    DIRECTRELEASE(mat21);
    DIRECTRELEASE(mat22);
    DIRECTRELEASE(mat23);
    DIRECTRELEASE(mat13);
    DIRECTRELEASE(mat12);
    DIRECTRELEASE(mat11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd);
}

VOID DirectDraw2CreateMaterialQueryInterfaceAll(LPMODULE module)
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

    LPDIRECT3DMATERIAL mat11 = NULL;
    result = d3d1->CreateMaterial(&mat11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);

    LPDIRECT3DMATERIAL2 mat12 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPDIRECT3DMATERIAL3 mat13 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat13, NULL);
    IsNotEqual((LPVOID)mat12, (LPVOID)mat13);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat13);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL2 mat22 = NULL;
    result = d3d2->CreateMaterial(&mat22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat22, NULL);
    IsNotEqual((LPVOID)mat11, mat22);

    LPDIRECT3DMATERIAL mat21 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPDIRECT3DMATERIAL3 mat23 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat23, NULL);
    IsNotEqual((LPVOID)mat22, (LPVOID)mat23);
    IsNotEqual((LPVOID)mat21, (LPVOID)mat23);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL3 mat33 = NULL;
    result = d3d3->CreateMaterial(&mat33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat33, NULL);

    IsNotEqual((LPVOID)mat11, mat33);
    IsNotEqual((LPVOID)mat22, mat33);

    LPDIRECT3DMATERIAL mat31 = NULL;
    result = mat33->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat33, (LPVOID)mat31);

    LPDIRECT3DMATERIAL2 mat32 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat32, NULL);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat33);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat31);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd2->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DirectDrawCreateMaterialQuery(mat11);
    DirectDrawCreateMaterialQuery(mat21);
    DirectDrawCreateMaterialQuery(mat31);

    DirectDrawCreateMaterial2Query(mat12);
    DirectDrawCreateMaterial2Query(mat22);
    DirectDrawCreateMaterial2Query(mat32);

    DirectDrawCreateMaterial3Query(mat13);
    DirectDrawCreateMaterial3Query(mat23);
    DirectDrawCreateMaterial3Query(mat33);

    DIRECTRELEASE(mat31);
    DIRECTRELEASE(mat32);
    DIRECTRELEASE(mat33);
    DIRECTRELEASE(mat21);
    DIRECTRELEASE(mat22);
    DIRECTRELEASE(mat23);
    DIRECTRELEASE(mat13);
    DIRECTRELEASE(mat12);
    DIRECTRELEASE(mat11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd2);
    DIRECTRELEASE(dd);
}

VOID DirectDraw4CreateMaterialQueryInterfaceAll(LPMODULE module)
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

    LPDIRECT3DMATERIAL mat11 = NULL;
    result = d3d1->CreateMaterial(&mat11, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);

    LPDIRECT3DMATERIAL2 mat12 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat12);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat11, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPDIRECT3DMATERIAL3 mat13 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat13);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat13, NULL);
    IsNotEqual((LPVOID)mat12, (LPVOID)mat13);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat13);

    LPDIRECT3D2 d3d2 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D2, (LPVOID*)&d3d2);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL2 mat22 = NULL;
    result = d3d2->CreateMaterial(&mat22, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat22, NULL);
    IsNotEqual((LPVOID)mat11, mat22);

    LPDIRECT3DMATERIAL mat21 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat21);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat11, (LPVOID)mat12);

    LPDIRECT3DMATERIAL3 mat23 = NULL;
    result = mat22->QueryInterface(IID_IDirect3DMaterial3, (LPVOID*)&mat23);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat23, NULL);
    IsNotEqual((LPVOID)mat22, (LPVOID)mat23);
    IsNotEqual((LPVOID)mat21, (LPVOID)mat23);

    LPDIRECT3D3 d3d3 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D3, (LPVOID*)&d3d3);
    IsEqual(result, DD_OK);

    LPDIRECT3DMATERIAL3 mat33 = NULL;
    result = d3d3->CreateMaterial(&mat33, NULL);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat33, NULL);

    IsNotEqual((LPVOID)mat11, mat33);
    IsNotEqual((LPVOID)mat22, mat33);

    LPDIRECT3DMATERIAL mat31 = NULL;
    result = mat33->QueryInterface(IID_IDirect3DMaterial, (LPVOID*)&mat31);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat21, NULL);
    IsNotEqual((LPVOID)mat33, (LPVOID)mat31);

    LPDIRECT3DMATERIAL2 mat32 = NULL;
    result = mat11->QueryInterface(IID_IDirect3DMaterial2, (LPVOID*)&mat32);
    IsEqual(result, DD_OK);
    IsNotEqual((LPVOID)mat32, NULL);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat33);
    IsNotEqual((LPVOID)mat32, (LPVOID)mat31);

    LPDIRECT3D7 d3d7 = NULL;
    result = dd4->QueryInterface(IID_IDirect3D7, (LPVOID*)&d3d7);
    IsNotEqual(result, DD_OK);

    DirectDrawCreateMaterialQuery(mat11);
    DirectDrawCreateMaterialQuery(mat21);
    DirectDrawCreateMaterialQuery(mat31);

    DirectDrawCreateMaterial2Query(mat12);
    DirectDrawCreateMaterial2Query(mat22);
    DirectDrawCreateMaterial2Query(mat32);

    DirectDrawCreateMaterial3Query(mat13);
    DirectDrawCreateMaterial3Query(mat23);
    DirectDrawCreateMaterial3Query(mat33);

    DIRECTRELEASE(mat31);
    DIRECTRELEASE(mat32);
    DIRECTRELEASE(mat33);
    DIRECTRELEASE(mat21);
    DIRECTRELEASE(mat22);
    DIRECTRELEASE(mat23);
    DIRECTRELEASE(mat13);
    DIRECTRELEASE(mat12);
    DIRECTRELEASE(mat11);
    DIRECTRELEASE(d3d3);
    DIRECTRELEASE(d3d2);
    DIRECTRELEASE(d3d1);
    DIRECTRELEASE(dd4);
    DIRECTRELEASE(dd);
}