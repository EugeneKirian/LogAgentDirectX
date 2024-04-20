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
#include "Direct3DResource8.hxx"
#include "Direct3DSurface8.hxx"
#include "Direct3DTexture8.hxx"
#include "Direct3DVolume8.hxx"
#include "Direct3DVolumeTexture8.hxx"

#include <AgentLogger.hxx>
#include <Direct3DVolume8Logger.hxx>

#define Direct3DVolume8LogMethod(L, M) AgentLogMethod(L, Direct3DVolume8, M)
#define Direct3DVolume8LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DVolume8, M, C, PARAMS)

#define Direct3DVolume8LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DVolume8, AddRef, R)
#define Direct3DVolume8LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DVolume8, Release, R, FALSE)

#define Direct3DVolume8LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DVolume8, M, R)
#define Direct3DVolume8LogMethodCustomResult(L, M, R, F, T) AgentLogMethodCustomResult(L, Direct3DVolume8, M, R, F, T)

#define Direct3DVolume8LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DVolume8, M, R, C, PARAMS)
#define Direct3DVolume8LogMethodCustomResultValue(L, M, R, F, T, C, PARAMS) AgentLogMethodCustomResultValue(L, Direct3DVolume8, M, R, F, T, C, PARAMS)

Direct3DVolume8::Direct3DVolume8(AgentConstructorParameters(Direct3DVolume8))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DVolume8);
}

Direct3DVolume8::~Direct3DVolume8()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DVolume8);
}

HRESULT Direct3DVolume8::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DVolume8LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DVolume8, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Direct3DVolume8, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DVolume8LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DVolume8::AddRef()
{
    Direct3DVolume8LogMethod(TRACE, AddRef);
    Direct3DVolume8LogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG Direct3DVolume8::Release()
{
    Direct3DVolume8LogMethod(TRACE, Release);
    Direct3DVolume8LogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Retrieves the device associated with a resource.
HRESULT Direct3DVolume8::GetDevice(LPDIRECT3DDEVICE8* ppDevice)
{
    Direct3DVolume8LogMethodValue(TRACE, GetDevice, 1, (ppDevice));

    CONST HRESULT result = this->State.Self->GetDevice(ppDevice);

    if (SUCCEEDED(result)) { *ppDevice = ActivateAgent(Direct3DDevice8, *ppDevice); }

    Direct3DVolume8LogMethodResultValue(TRACEDEBUGINFO, GetDevice, result, 1, (ppDevice));
}

// Associates data with the resource that is intended for use by the application, not by Microsoft® Direct3D®.
// Data is passed by value, and multiple sets of data can be associated with a single resource.
HRESULT Direct3DVolume8::SetPrivateData(REFGUID refguid, LPCVOID pData, DWORD SizeOfData, DWORD Flags)
{
    Direct3DVolume8LogMethodValue(TRACE, SetPrivateData, 4, (refguid, pData, SizeOfData, Flags));

    CONST HRESULT result = this->State.Self->SetPrivateData(refguid, pData, SizeOfData, Flags);

    Direct3DVolume8LogMethodResultValue(TRACEDEBUGINFO, SetPrivateData, result, 4, (refguid, pData, SizeOfData, Flags));
}

// Copies the private data associated with the resource to a provided buffer.
HRESULT Direct3DVolume8::GetPrivateData(REFGUID refguid, LPVOID pData, DWORD* pSizeOfData)
{
    Direct3DVolume8LogMethodValue(TRACE, GetPrivateData, 3, (refguid, pData, pSizeOfData));

    CONST HRESULT result = this->State.Self->GetPrivateData(refguid, pData, pSizeOfData);

    Direct3DVolume8LogMethodResultValue(TRACEDEBUGINFO, GetPrivateData, result, 3, (refguid, pData, pSizeOfData));
}

// Frees the specified private data associated with this resource.
HRESULT Direct3DVolume8::FreePrivateData(REFGUID refguid)
{
    Direct3DVolume8LogMethodValue(TRACE, FreePrivateData, 1, (refguid));

    CONST HRESULT result = this->State.Self->FreePrivateData(refguid);

    Direct3DVolume8LogMethodResultValue(TRACEDEBUGINFO, FreePrivateData, result, 1, (refguid));
}

// Provides access to the parent volume texture object, if this surface is a child level of a volume texture.
HRESULT Direct3DVolume8::GetContainer(REFIID riid, LPVOID* ppContainer)
{
    Direct3DVolume8LogMethodValue(TRACE, GetContainer, 2, (riid, ppContainer));

    CONST HRESULT result = this->State.Self->GetContainer(riid, ppContainer);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppContainer))
        {
            if (IsEqualIID(IID_IDirect3DBaseTexture8, riid)) { *ppContainer = ActivateAgentBase(Direct3DBaseTexture8, *ppContainer); }
            else if (IsEqualIID(IID_IDirect3DCubeTexture8, riid)) { *ppContainer = ActivateAgentBase(Direct3DCubeTexture8, *ppContainer); }
            else if (IsEqualIID(IID_IDirect3DDevice8, riid)) { *ppContainer = ActivateAgentBase(Direct3DDevice8, *ppContainer); }
            else if (IsEqualIID(IID_IDirect3DResource8, riid)) { *ppContainer = ActivateAgentBase(Direct3DResource8, *ppContainer); }
            else if (IsEqualIID(IID_IDirect3DSurface8, riid)) { *ppContainer = ActivateAgentBase(Direct3DSurface8, *ppContainer); }
            else if (IsEqualIID(IID_IDirect3DTexture8, riid)) { *ppContainer = ActivateAgentBase(Direct3DTexture8, *ppContainer); }
            else if (IsEqualIID(IID_IDirect3DVolumeTexture8, riid)) { *ppContainer = ActivateAgentBase(Direct3DVolumeTexture8, *ppContainer); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DVolume8LogMethodResultValue(TRACEDEBUGINFO, GetContainer, result, 2, (riid, ppContainer));
}

// Retrieves a description of the volume.
HRESULT Direct3DVolume8::GetDesc(D3DVOLUME_DESC* pDesc)
{
    Direct3DVolume8LogMethodValue(TRACE, GetDesc, 1, (pDesc));

    CONST HRESULT result = this->State.Self->GetDesc(pDesc);

    Direct3DVolume8LogMethodResultValue(TRACEDEBUGINFO, GetDesc, result, 1, (pDesc));
}

// Locks a box on a volume resource.
HRESULT Direct3DVolume8::LockBox(D3DLOCKED_BOX* pLockedVolume, CONST D3DBOX* pBox, DWORD Flags)
{
    Direct3DVolume8LogMethodValue(TRACE, LockBox, 3, (pLockedVolume, pBox, Flags));

    CONST HRESULT result = this->State.Self->LockBox(pLockedVolume, pBox, Flags);

    Direct3DVolume8LogMethodResultValue(TRACEDEBUGINFO, LockBox, result, 3, (pLockedVolume, pBox, Flags));
}

// Unlocks a box on a volume resource.
HRESULT Direct3DVolume8::UnlockBox()
{
    Direct3DVolume8LogMethod(TRACE, UnlockBox);

    CONST HRESULT result = this->State.Self->UnlockBox();

    Direct3DVolume8LogMethodResult(TRACEDEBUGINFO, UnlockBox, result);
}