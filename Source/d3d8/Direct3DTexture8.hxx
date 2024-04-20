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

#include "Base.hxx"

class Direct3DTexture8 : public IDirect3DTexture8
{
public:
    Direct3DTexture8(AgentConstructorParameters(Direct3DTexture8));
    virtual ~Direct3DTexture8();

    /*** IUnknown ***/

    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID* ppvObj);
    STDMETHOD_(ULONG, AddRef)(THIS);
    STDMETHOD_(ULONG, Release)(THIS);

    /*** IDirect3DResource8 ***/

    STDMETHOD(GetDevice)(THIS_ LPDIRECT3DDEVICE8* ppDevice);
    STDMETHOD(SetPrivateData)(THIS_ REFGUID refguid, LPCVOID pData, DWORD SizeOfData, DWORD Flags);
    STDMETHOD(GetPrivateData)(THIS_ REFGUID refguid, LPVOID pData, DWORD* pSizeOfData);
    STDMETHOD(FreePrivateData)(THIS_ REFGUID refguid);
    STDMETHOD_(DWORD, SetPriority)(THIS_ DWORD PriorityNew);
    STDMETHOD_(DWORD, GetPriority)(THIS);
    STDMETHOD_(VOID, PreLoad)(THIS);
    STDMETHOD_(D3DRESOURCETYPE, GetType)(THIS);

    /*** IDirect3DBaseTexture8 ***/

    STDMETHOD_(DWORD, SetLOD)(THIS_ DWORD LODNew);
    STDMETHOD_(DWORD, GetLOD)(THIS);
    STDMETHOD_(DWORD, GetLevelCount)(THIS);

    /***  IDirect3DTexture8 ***/

    STDMETHOD(GetLevelDesc)(THIS_ UINT Level, D3DSURFACE_DESC* pDesc);
    STDMETHOD(GetSurfaceLevel)(THIS_ UINT Level, LPDIRECT3DSURFACE8* ppSurfaceLevel);
    STDMETHOD(LockRect)(THIS_ UINT Level, D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags);
    STDMETHOD(UnlockRect)(THIS_ UINT Level);
    STDMETHOD(AddDirtyRect)(THIS_ CONST RECT* pDirtyRect);

protected:
    AgentStateStruct(Direct3DTexture8);
};