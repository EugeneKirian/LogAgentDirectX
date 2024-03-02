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

#include "DirectDrawVideoPort.hxx"

HRESULT WINAPI EnumVideoCallback(LPDDVIDEOPORTCAPS lpDDVideoPortCaps, LPVOID lpContext)
{
    CopyMemory(lpContext, lpDDVideoPortCaps, sizeof(DDVIDEOPORTCAPS));

    return DDENUMRET_CANCEL;
}

VOID DirectDrawCreateVideoPort(LPMODULE module)
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

    DDVIDEOPORTCAPS caps;
    ZeroMemory(&caps, sizeof(DDVIDEOPORTCAPS));

    result = vpc->EnumVideoPorts(0, NULL, &caps, EnumVideoCallback);
    IsNotEqual(result, DD_OK);

    LPDIRECTDRAWVIDEOPORT vp = NULL;

    DDVIDEOPORTDESC desc;
    ZeroMemory(&desc, sizeof(DDVIDEOPORTDESC));

    desc.dwSize = sizeof(DDVIDEOPORTDESC);

    result = vpc->CreateVideoPort(0, &desc, &vp, NULL);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)vp, NULL);

    DIRECTRELEASE(vpc);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);
}

VOID DirectDraw2CreateVideoPort(LPMODULE module)
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

    dd2->AddRef();
    IsEqual(dd2->Release(), 1);

    DDVIDEOPORTCAPS caps;
    ZeroMemory(&caps, sizeof(DDVIDEOPORTCAPS));

    result = vpc->EnumVideoPorts(0, NULL, &caps, EnumVideoCallback);
    IsNotEqual(result, DD_OK);

    LPDIRECTDRAWVIDEOPORT vp = NULL;

    DDVIDEOPORTDESC desc;
    ZeroMemory(&desc, sizeof(DDVIDEOPORTDESC));

    desc.dwSize = sizeof(DDVIDEOPORTDESC);

    result = vpc->CreateVideoPort(0, &desc, &vp, NULL);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)vp, NULL);

    DIRECTRELEASE(vpc);

    dd2->AddRef();
    IsEqual(dd2->Release(), 1);

    DIRECTRELEASE(dd2);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);
}

VOID DirectDraw4CreateVideoPort(LPMODULE module)
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

    dd4->AddRef();
    IsEqual(dd4->Release(), 1);

    DDVIDEOPORTCAPS caps;
    ZeroMemory(&caps, sizeof(DDVIDEOPORTCAPS));

    result = vpc->EnumVideoPorts(0, NULL, &caps, EnumVideoCallback);
    IsNotEqual(result, DD_OK);

    LPDIRECTDRAWVIDEOPORT vp = NULL;

    DDVIDEOPORTDESC desc;
    ZeroMemory(&desc, sizeof(DDVIDEOPORTDESC));

    desc.dwSize = sizeof(DDVIDEOPORTDESC);

    result = vpc->CreateVideoPort(0, &desc, &vp, NULL);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)vp, NULL);

    DIRECTRELEASE(vpc);

    dd4->AddRef();
    IsEqual(dd4->Release(), 1);

    DIRECTRELEASE(dd4);

    dd1->AddRef();
    IsEqual(dd1->Release(), 1);

    DIRECTRELEASE(dd1);
}

VOID DirectDraw7CreateVideoPort(LPMODULE module)
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

    DDVIDEOPORTCAPS caps;
    ZeroMemory(&caps, sizeof(DDVIDEOPORTCAPS));

    result = vpc->EnumVideoPorts(0, NULL, &caps, EnumVideoCallback);
    IsNotEqual(result, DD_OK);

    LPDIRECTDRAWVIDEOPORT vp = NULL;

    DDVIDEOPORTDESC desc;
    ZeroMemory(&desc, sizeof(DDVIDEOPORTDESC));

    desc.dwSize = sizeof(DDVIDEOPORTDESC);

    result = vpc->CreateVideoPort(0, &desc, &vp, NULL);
    IsNotEqual(result, DD_OK);
    IsEqual((LPVOID)vp, NULL);

    DIRECTRELEASE(vpc);

    dd7->AddRef();
    IsEqual(dd7->Release(), 1);

    DIRECTRELEASE(dd7);
}