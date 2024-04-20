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
#include "Direct3DTexture8.hxx"
#include "Direct3DVolumeTexture8.hxx"

#include <AgentLogger.hxx>
#include <Direct3DBaseTexture8Logger.hxx>

#define Direct3DBaseTexture8LogMethod(L, M) AgentLogMethod(L, Direct3DBaseTexture8, M)
#define Direct3DBaseTexture8LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DBaseTexture8, M, C, PARAMS)

#define Direct3DBaseTexture8LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DBaseTexture8, AddRef, R)
#define Direct3DBaseTexture8LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DBaseTexture8, Release, R, FALSE)

#define Direct3DBaseTexture8LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DBaseTexture8, M, R)
#define Direct3DBaseTexture8LogMethodCustomResult(L, M, R, F, T) AgentLogMethodCustomResult(L, Direct3DBaseTexture8, M, R, F, T)
#define Direct3DBaseTexture8LogMethodNoResult(L, M) AgentLogMethodNoResult(L, Direct3DBaseTexture8, M)

#define Direct3DBaseTexture8LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DBaseTexture8, M, R, C, PARAMS)
#define Direct3DBaseTexture8LogMethodCustomResultValue(L, M, R, F, T, C, PARAMS) AgentLogMethodCustomResultValue(L, Direct3DBaseTexture8, M, R, F, T, C, PARAMS)
#define Direct3DBaseTexture8LogMethodNoResultValue(L, M, R, C, PARAMS) AgentLogMethodNoResultValue(L, Direct3DBaseTexture8, M, C, PARAMS)

Direct3DBaseTexture8::Direct3DBaseTexture8(AgentConstructorParameters(Direct3DBaseTexture8))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DBaseTexture8);
}

Direct3DBaseTexture8::~Direct3DBaseTexture8()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DBaseTexture8);
}

HRESULT Direct3DBaseTexture8::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DBaseTexture8LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DBaseTexture8, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Direct3DBaseTexture8, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DCubeTexture8, riid)) { *ppvObj = ActivateAgent(Direct3DCubeTexture8, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DTexture8, riid)) { *ppvObj = ActivateAgent(Direct3DTexture8, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DVolumeTexture8, riid)) { *ppvObj = ActivateAgent(Direct3DVolumeTexture8, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DBaseTexture8LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DBaseTexture8::AddRef()
{
    Direct3DBaseTexture8LogMethod(TRACE, AddRef);
    Direct3DBaseTexture8LogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG Direct3DBaseTexture8::Release()
{
    Direct3DBaseTexture8LogMethod(TRACE, Release);
    Direct3DBaseTexture8LogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Retrieves the device associated with a resource.
HRESULT Direct3DBaseTexture8::GetDevice(LPDIRECT3DDEVICE8* ppDevice)
{
    Direct3DBaseTexture8LogMethodValue(TRACE, GetDevice, 1, (ppDevice));

    CONST HRESULT result = this->State.Self->GetDevice(ppDevice);

    if (SUCCEEDED(result)) { *ppDevice = ActivateAgent(Direct3DDevice8, *ppDevice); }

    Direct3DBaseTexture8LogMethodResultValue(TRACEDEBUGINFO, GetDevice, result, 1, (ppDevice));
}

// Associates data with the resource that is intended for use by the application, not by Microsoft® Direct3D®.
// Data is passed by value, and multiple sets of data can be associated with a single resource.
HRESULT Direct3DBaseTexture8::SetPrivateData(REFGUID refguid, LPCVOID pData, DWORD SizeOfData, DWORD Flags)
{
    Direct3DBaseTexture8LogMethodValue(TRACE, SetPrivateData, 4, (refguid, pData, SizeOfData, Flags));

    CONST HRESULT result = this->State.Self->SetPrivateData(refguid, pData, SizeOfData, Flags);

    Direct3DBaseTexture8LogMethodResultValue(TRACEDEBUGINFO, SetPrivateData, result, 4, (refguid, pData, SizeOfData, Flags));
}

// Copies the private data associated with the resource to a provided buffer.
HRESULT Direct3DBaseTexture8::GetPrivateData(REFGUID refguid, LPVOID pData, DWORD* pSizeOfData)
{
    Direct3DBaseTexture8LogMethodValue(TRACE, GetPrivateData, 3, (refguid, pData, pSizeOfData));

    CONST HRESULT result = this->State.Self->GetPrivateData(refguid, pData, pSizeOfData);

    Direct3DBaseTexture8LogMethodResultValue(TRACEDEBUGINFO, GetPrivateData, result, 3, (refguid, pData, pSizeOfData));
}

// Frees the specified private data associated with this resource.
HRESULT Direct3DBaseTexture8::FreePrivateData(REFGUID refguid)
{
    Direct3DBaseTexture8LogMethodValue(TRACE, FreePrivateData, 1, (refguid));

    CONST HRESULT result = this->State.Self->FreePrivateData(refguid);

    Direct3DBaseTexture8LogMethodResultValue(TRACEDEBUGINFO, FreePrivateData, result, 1, (refguid));
}

// Assigns the resource-management priority for this resource.
DWORD Direct3DBaseTexture8::SetPriority(DWORD PriorityNew)
{
    Direct3DBaseTexture8LogMethodValue(TRACE, SetPriority, 1, (PriorityNew));

    CONST HRESULT result = this->State.Self->SetPriority(PriorityNew);

    Direct3DBaseTexture8LogMethodCustomResultValue(TRACEDEBUGINFO, SetPriority, result, FALSE, DWORD, 1, (PriorityNew));
}

// Retrieves the priority for this resource. 
DWORD Direct3DBaseTexture8::GetPriority()
{
    Direct3DBaseTexture8LogMethod(TRACE, GetPriority);

    CONST HRESULT result = this->State.Self->GetPriority();

    Direct3DBaseTexture8LogMethodCustomResult(TRACEDEBUGINFO, GetPriority, result, FALSE, DWORD);
}

// Preloads a managed resource.
VOID Direct3DBaseTexture8::PreLoad()
{
    Direct3DBaseTexture8LogMethod(TRACE, PreLoad);

    this->State.Self->PreLoad();

    Direct3DBaseTexture8LogMethodNoResult(TRACEDEBUGINFO, PreLoad);
}

// Returns the type of the resource.
D3DRESOURCETYPE Direct3DBaseTexture8::GetType()
{
    Direct3DBaseTexture8LogMethod(TRACE, GetType);

    CONST D3DRESOURCETYPE result = this->State.Self->GetType();

    Direct3DBaseTexture8LogMethodCustomResult(TRACEDEBUGINFO, GetType, result, FALSE, D3DRESOURCETYPE);
}

// Sets the most detailed level of detail (LOD) for a managed texture.
DWORD Direct3DBaseTexture8::SetLOD(DWORD LODNew)
{
    Direct3DBaseTexture8LogMethodValue(TRACE, SetLOD, 1, (LODNew));

    CONST DWORD result = this->State.Self->SetLOD(LODNew);

    Direct3DBaseTexture8LogMethodCustomResultValue(TRACEDEBUGINFO, SetLOD, result, FALSE, DWORD, 1, (LODNew));
}

// Returns a value clamped to the maximum level of detail (LOD) set for a managed texture.
DWORD Direct3DBaseTexture8::GetLOD()
{
    Direct3DBaseTexture8LogMethod(TRACE, GetLOD);

    CONST DWORD result = this->State.Self->GetLOD();

    Direct3DBaseTexture8LogMethodCustomResult(TRACEDEBUGINFO, GetLOD, result, FALSE, DWORD);
}

// Returns the number of texture levels in a multilevel texture.
DWORD Direct3DBaseTexture8::GetLevelCount()
{
    Direct3DBaseTexture8LogMethod(TRACE, GetLevelCount);

    CONST DWORD result = this->State.Self->GetLevelCount();

    Direct3DBaseTexture8LogMethodCustomResult(TRACEDEBUGINFO, GetLevelCount, result, FALSE, DWORD);
}