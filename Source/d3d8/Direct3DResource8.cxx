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
#include "Direct3DIndexBuffer8.hxx"
#include "Direct3DResource8.hxx"
#include "Direct3DTexture8.hxx"
#include "Direct3DVertexBuffer8.hxx"
#include "Direct3DVolumeTexture8.hxx"

#include <AgentLogger.hxx>
#include <Direct3DResource8Logger.hxx>

#define Direct3DResource8LogMethod(L, M) AgentLogMethod(L, Direct3DResource8, M)
#define Direct3DResource8LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DResource8, M, C, PARAMS)

#define Direct3DResource8LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DResource8, AddRef, R)
#define Direct3DResource8LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DResource8, Release, R, FALSE)

#define Direct3DResource8LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DResource8, M, R)
#define Direct3DResource8LogMethodCustomResult(L, M, R, F, T) AgentLogMethodCustomResult(L, Direct3DResource8, M, R, F, T)
#define Direct3DResource8LogMethodNoResult(L, M) AgentLogMethodNoResult(L, Direct3DResource8, M)

#define Direct3DResource8LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DResource8, M, R, C, PARAMS)
#define Direct3DResource8LogMethodCustomResultValue(L, M, R, F, T, C, PARAMS) AgentLogMethodCustomResultValue(L, Direct3DResource8, M, R, F, T, C, PARAMS)

Direct3DResource8::Direct3DResource8(AgentConstructorParameters(Direct3DResource8))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DResource8);
}

Direct3DResource8::~Direct3DResource8()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DResource8);
}

HRESULT Direct3DResource8::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DResource8LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DResource8, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Direct3DResource8, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DBaseTexture8, riid)) { *ppvObj = ActivateAgent(Direct3DBaseTexture8, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DCubeTexture8, riid)) { *ppvObj = ActivateAgent(Direct3DCubeTexture8, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DIndexBuffer8, riid)) { *ppvObj = ActivateAgent(Direct3DIndexBuffer8, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DTexture8, riid)) { *ppvObj = ActivateAgent(Direct3DTexture8, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DVertexBuffer8, riid)) { *ppvObj = ActivateAgent(Direct3DVertexBuffer8, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DVolumeTexture8, riid)) { *ppvObj = ActivateAgent(Direct3DVolumeTexture8, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DResource8LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DResource8::AddRef()
{
    Direct3DResource8LogMethod(TRACE, AddRef);
    Direct3DResource8LogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG Direct3DResource8::Release()
{
    Direct3DResource8LogMethod(TRACE, Release);
    Direct3DResource8LogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Retrieves the device associated with a resource.
HRESULT Direct3DResource8::GetDevice(LPDIRECT3DDEVICE8* ppDevice)
{
    Direct3DResource8LogMethodValue(TRACE, GetDevice, 1, (ppDevice));

    CONST HRESULT result = this->State.Self->GetDevice(ppDevice);

    if (SUCCEEDED(result)) { *ppDevice = ActivateAgent(Direct3DDevice8, *ppDevice); }

    Direct3DResource8LogMethodResultValue(TRACEDEBUGINFO, GetDevice, result, 1, (ppDevice));
}

// Associates data with the resource that is intended for use by the application, not by Microsoft® Direct3D®.
// Data is passed by value, and multiple sets of data can be associated with a single resource.
HRESULT Direct3DResource8::SetPrivateData(REFGUID refguid, LPCVOID pData, DWORD SizeOfData, DWORD Flags)
{
    Direct3DResource8LogMethodValue(TRACE, SetPrivateData, 4, (refguid, pData, SizeOfData, Flags));

    CONST HRESULT result = this->State.Self->SetPrivateData(refguid, pData, SizeOfData, Flags);

    Direct3DResource8LogMethodResultValue(TRACEDEBUGINFO, SetPrivateData, result, 4, (refguid, pData, SizeOfData, Flags));
}

// Copies the private data associated with the resource to a provided buffer.
HRESULT Direct3DResource8::GetPrivateData(REFGUID refguid, LPVOID pData, DWORD* pSizeOfData)
{
    Direct3DResource8LogMethodValue(TRACE, GetPrivateData, 3, (refguid, pData, pSizeOfData));

    CONST HRESULT result = this->State.Self->GetPrivateData(refguid, pData, pSizeOfData);

    Direct3DResource8LogMethodResultValue(TRACEDEBUGINFO, GetPrivateData, result, 3, (refguid, pData, pSizeOfData));
}

// Frees the specified private data associated with this resource.
HRESULT Direct3DResource8::FreePrivateData(REFGUID refguid)
{
    Direct3DResource8LogMethodValue(TRACE, FreePrivateData, 1, (refguid));

    CONST HRESULT result = this->State.Self->FreePrivateData(refguid);

    Direct3DResource8LogMethodResultValue(TRACEDEBUGINFO, FreePrivateData, result, 1, (refguid));
}

// Assigns the resource-management priority for this resource.
DWORD Direct3DResource8::SetPriority(DWORD PriorityNew)
{
    Direct3DResource8LogMethodValue(TRACE, SetPriority, 1, (PriorityNew));

    CONST HRESULT result = this->State.Self->SetPriority(PriorityNew);

    Direct3DResource8LogMethodCustomResultValue(TRACEDEBUGINFO, SetPriority, result, FALSE, DWORD, 1, (PriorityNew));
}

// Retrieves the priority for this resource. 
DWORD Direct3DResource8::GetPriority()
{
    Direct3DResource8LogMethod(TRACE, GetPriority);

    CONST HRESULT result = this->State.Self->GetPriority();

    Direct3DResource8LogMethodCustomResult(TRACEDEBUGINFO, GetPriority, result, FALSE, DWORD);
}

// Preloads a managed resource.
VOID Direct3DResource8::PreLoad()
{
    Direct3DResource8LogMethod(TRACE, PreLoad);

    this->State.Self->PreLoad();

    Direct3DResource8LogMethodNoResult(TRACEDEBUGINFO, PreLoad);
}

// Returns the type of the resource.
D3DRESOURCETYPE Direct3DResource8::GetType()
{
    Direct3DResource8LogMethod(TRACE, GetType);

    CONST D3DRESOURCETYPE result = this->State.Self->GetType();

    Direct3DResource8LogMethodCustomResult(TRACEDEBUGINFO, GetType, result, FALSE, D3DRESOURCETYPE);
}