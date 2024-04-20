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
#include "Direct3DCubeTexture8.hxx"
#include "Direct3DDevice8.hxx"
#include "Direct3DSurface8.hxx"
#include "Direct3DSurface8.hxx"
#include "Direct3DTexture8.hxx"
#include "Direct3DVolume8.hxx"
#include "Direct3DVolumeTexture8.hxx"

#include <AgentLogger.hxx>
#include <Direct3DSurface8Logger.hxx>

#define Direct3DSurface8LogMethod(L, M) AgentLogMethod(L, Direct3DSurface8, M)
#define Direct3DSurface8LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DSurface8, M, C, PARAMS)

#define Direct3DSurface8LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DSurface8, AddRef, R)
#define Direct3DSurface8LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DSurface8, Release, R, FALSE)

#define Direct3DSurface8LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DSurface8, M, R)
#define Direct3DSurface8LogMethodCustomResult(L, M, R, F, T) AgentLogMethodCustomResult(L, Direct3DSurface8, M, R, F, T)

#define Direct3DSurface8LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DSurface8, M, R, C, PARAMS)
#define Direct3DSurface8LogMethodCustomResultValue(L, M, R, F, T, C, PARAMS) AgentLogMethodCustomResultValue(L, Direct3DSurface8, M, R, F, T, C, PARAMS)

Direct3DSurface8::Direct3DSurface8(AgentConstructorParameters(Direct3DSurface8))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DSurface8);
}

Direct3DSurface8::~Direct3DSurface8()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DSurface8);
}

HRESULT Direct3DSurface8::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DSurface8LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DSurface8, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Direct3DSurface8, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DSurface8LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DSurface8::AddRef()
{
    Direct3DSurface8LogMethod(TRACE, AddRef);
    Direct3DSurface8LogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG Direct3DSurface8::Release()
{
    Direct3DSurface8LogMethod(TRACE, Release);
    Direct3DSurface8LogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Retrieves the device associated with a surface.
HRESULT Direct3DSurface8::GetDevice(LPDIRECT3DDEVICE8* ppDevice)
{
    Direct3DSurface8LogMethodValue(TRACE, GetDevice, 1, (ppDevice));

    CONST HRESULT result = this->State.Self->GetDevice(ppDevice);

    if (SUCCEEDED(result)) { *ppDevice = ActivateAgent(Direct3DDevice8, *ppDevice); }

    Direct3DSurface8LogMethodResultValue(TRACEDEBUGINFO, GetDevice, result, 1, (ppDevice));
}

// Associates data with the surface that is intended for use by the application, not by Microsoft® Direct3D®.
HRESULT Direct3DSurface8::SetPrivateData(REFGUID refguid, LPCVOID pData, DWORD SizeOfData, DWORD Flags)
{
    Direct3DSurface8LogMethodValue(TRACE, SetPrivateData, 4, (refguid, pData, SizeOfData, Flags));

    CONST HRESULT result = this->State.Self->SetPrivateData(refguid, pData, SizeOfData, Flags);

    Direct3DSurface8LogMethodResultValue(TRACEDEBUGINFO, SetPrivateData, result, 4, (refguid, pData, SizeOfData, Flags));
}

// Copies the private data associated with the surface to a provided buffer.
HRESULT Direct3DSurface8::GetPrivateData(REFGUID refguid, LPVOID pData, DWORD* pSizeOfData)
{
    Direct3DSurface8LogMethodValue(TRACE, GetPrivateData, 3, (refguid, pData, pSizeOfData));

    CONST HRESULT result = this->State.Self->GetPrivateData(refguid, pData, pSizeOfData);

    Direct3DSurface8LogMethodResultValue(TRACEDEBUGINFO, GetPrivateData, result, 3, (refguid, pData, pSizeOfData));
}

// Frees the specified private data associated with this surface.
HRESULT Direct3DSurface8::FreePrivateData(REFGUID refguid)
{
    Direct3DSurface8LogMethodValue(TRACE, FreePrivateData, 1, (refguid));

    CONST HRESULT result = this->State.Self->FreePrivateData(refguid);

    Direct3DSurface8LogMethodResultValue(TRACEDEBUGINFO, FreePrivateData, result, 1, (refguid));
}

// Provides access to the parent cube texture or texture (mipmap) object, if this surface is a child level of a cube texture or a mipmap.
HRESULT Direct3DSurface8::GetContainer(REFIID riid, LPVOID* ppContainer)
{
    Direct3DSurface8LogMethodValue(TRACE, GetContainer, 2, (riid, ppContainer));

    CONST HRESULT result = this->State.Self->GetContainer(riid, ppContainer);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppContainer))
        {
            if (IsEqualIID(IID_IDirect3DBaseTexture8, riid)) { *ppContainer = ActivateAgentBase(Direct3DBaseTexture8, *ppContainer); }
            else if (IsEqualIID(IID_IDirect3DCubeTexture8, riid)) { *ppContainer = ActivateAgentBase(Direct3DCubeTexture8, *ppContainer); }
            else if (IsEqualIID(IID_IDirect3DDevice8, riid)) { *ppContainer = ActivateAgentBase(Direct3DDevice8, *ppContainer); }
            else if (IsEqualIID(IID_IDirect3DSurface8, riid)) { *ppContainer = ActivateAgentBase(Direct3DSurface8, *ppContainer); }
            else if (IsEqualIID(IID_IDirect3DSurface8, riid)) { *ppContainer = ActivateAgentBase(Direct3DSurface8, *ppContainer); }
            else if (IsEqualIID(IID_IDirect3DTexture8, riid)) { *ppContainer = ActivateAgentBase(Direct3DTexture8, *ppContainer); }
            else if (IsEqualIID(IID_IDirect3DVolumeTexture8, riid)) { *ppContainer = ActivateAgentBase(Direct3DVolumeTexture8, *ppContainer); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DSurface8LogMethodResultValue(TRACEDEBUGINFO, GetContainer, result, 2, (riid, ppContainer));
}

// Retrieves a description of the surface.
HRESULT Direct3DSurface8::GetDesc(D3DSURFACE_DESC* pDesc)
{
    Direct3DSurface8LogMethodValue(TRACE, GetDesc, 1, (pDesc));

    CONST HRESULT result = this->State.Self->GetDesc(pDesc);

    Direct3DSurface8LogMethodResultValue(TRACEDEBUGINFO, GetDesc, result, 1, (pDesc));
}

// Locks a rectangle on a surface.
HRESULT Direct3DSurface8::LockRect(D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags)
{
    Direct3DSurface8LogMethodValue(TRACE, LockRect, 3, (pLockedRect, pRect, Flags));

    CONST HRESULT result = this->State.Self->LockRect(pLockedRect, pRect, Flags);

    Direct3DSurface8LogMethodResultValue(TRACEDEBUGINFO, LockRect, result, 3, (pLockedRect, pRect, Flags));
}

// Unlocks a rectangle on a surface.
HRESULT Direct3DSurface8::UnlockRect()
{
    Direct3DSurface8LogMethod(TRACE, UnlockRect);

    CONST HRESULT result = this->State.Self->UnlockRect();

    Direct3DSurface8LogMethodResult(TRACEDEBUGINFO, UnlockRect, result);
}