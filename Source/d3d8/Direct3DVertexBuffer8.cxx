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

#include "Direct3DDevice8.hxx"
#include "Direct3DResource8.hxx"
#include "Direct3DVertexBuffer8.hxx"

#include <AgentLogger.hxx>
#include <Direct3DVertexBuffer8Logger.hxx>

#define Direct3DVertexBuffer8LogMethod(L, M) AgentLogMethod(L, Direct3DVertexBuffer8, M)
#define Direct3DVertexBuffer8LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DVertexBuffer8, M, C, PARAMS)

#define Direct3DVertexBuffer8LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DVertexBuffer8, AddRef, R)
#define Direct3DVertexBuffer8LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DVertexBuffer8, Release, R, FALSE)

#define Direct3DVertexBuffer8LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DVertexBuffer8, M, R)
#define Direct3DVertexBuffer8LogMethodCustomResult(L, M, R, F, T) AgentLogMethodCustomResult(L, Direct3DVertexBuffer8, M, R, F, T)
#define Direct3DVertexBuffer8LogMethodNoResult(L, M) AgentLogMethodNoResult(L, Direct3DVertexBuffer8, M)

#define Direct3DVertexBuffer8LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DVertexBuffer8, M, R, C, PARAMS)
#define Direct3DVertexBuffer8LogMethodCustomResultValue(L, M, R, F, T, C, PARAMS) AgentLogMethodCustomResultValue(L, Direct3DVertexBuffer8, M, R, F, T, C, PARAMS)

Direct3DVertexBuffer8::Direct3DVertexBuffer8(AgentConstructorParameters(Direct3DVertexBuffer8))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DVertexBuffer8);
}

Direct3DVertexBuffer8::~Direct3DVertexBuffer8()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DVertexBuffer8);
}

HRESULT Direct3DVertexBuffer8::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DVertexBuffer8LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DVertexBuffer8, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Direct3DVertexBuffer8, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DResource8, riid)) { *ppvObj = ActivateAgent(Direct3DResource8, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DVertexBuffer8LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DVertexBuffer8::AddRef()
{
    Direct3DVertexBuffer8LogMethod(TRACE, AddRef);
    Direct3DVertexBuffer8LogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG Direct3DVertexBuffer8::Release()
{
    Direct3DVertexBuffer8LogMethod(TRACE, Release);
    Direct3DVertexBuffer8LogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Retrieves the device associated with a resource.
HRESULT Direct3DVertexBuffer8::GetDevice(LPDIRECT3DDEVICE8* ppDevice)
{
    Direct3DVertexBuffer8LogMethodValue(TRACE, GetDevice, 1, (ppDevice));

    CONST HRESULT result = this->State.Self->GetDevice(ppDevice);

    if (SUCCEEDED(result)) { *ppDevice = ActivateAgent(Direct3DDevice8, *ppDevice); }

    Direct3DVertexBuffer8LogMethodResultValue(TRACEDEBUGINFO, GetDevice, result, 1, (ppDevice));
}

// Associates data with the resource that is intended for use by the application, not by Microsoft® Direct3D®.
// Data is passed by value, and multiple sets of data can be associated with a single resource.
HRESULT Direct3DVertexBuffer8::SetPrivateData(REFGUID refguid, LPCVOID pData, DWORD SizeOfData, DWORD Flags)
{
    Direct3DVertexBuffer8LogMethodValue(TRACE, SetPrivateData, 4, (refguid, pData, SizeOfData, Flags));

    CONST HRESULT result = this->State.Self->SetPrivateData(refguid, pData, SizeOfData, Flags);

    Direct3DVertexBuffer8LogMethodResultValue(TRACEDEBUGINFO, SetPrivateData, result, 4, (refguid, pData, SizeOfData, Flags));
}

// Copies the private data associated with the resource to a provided buffer.
HRESULT Direct3DVertexBuffer8::GetPrivateData(REFGUID refguid, LPVOID pData, DWORD* pSizeOfData)
{
    Direct3DVertexBuffer8LogMethodValue(TRACE, GetPrivateData, 3, (refguid, pData, pSizeOfData));

    CONST HRESULT result = this->State.Self->GetPrivateData(refguid, pData, pSizeOfData);

    Direct3DVertexBuffer8LogMethodResultValue(TRACEDEBUGINFO, GetPrivateData, result, 3, (refguid, pData, pSizeOfData));
}

// Frees the specified private data associated with this resource.
HRESULT Direct3DVertexBuffer8::FreePrivateData(REFGUID refguid)
{
    Direct3DVertexBuffer8LogMethodValue(TRACE, FreePrivateData, 1, (refguid));

    CONST HRESULT result = this->State.Self->FreePrivateData(refguid);

    Direct3DVertexBuffer8LogMethodResultValue(TRACEDEBUGINFO, FreePrivateData, result, 1, (refguid));
}

// Assigns the resource-management priority for this resource.
DWORD Direct3DVertexBuffer8::SetPriority(DWORD PriorityNew)
{
    Direct3DVertexBuffer8LogMethodValue(TRACE, SetPriority, 1, (PriorityNew));

    CONST HRESULT result = this->State.Self->SetPriority(PriorityNew);

    Direct3DVertexBuffer8LogMethodCustomResultValue(TRACEDEBUGINFO, SetPriority, result, FALSE, DWORD, 1, (PriorityNew));
}

// Retrieves the priority for this resource. 
DWORD Direct3DVertexBuffer8::GetPriority()
{
    Direct3DVertexBuffer8LogMethod(TRACE, GetPriority);

    CONST HRESULT result = this->State.Self->GetPriority();

    Direct3DVertexBuffer8LogMethodCustomResult(TRACEDEBUGINFO, GetPriority, result, FALSE, DWORD);
}

// Preloads a managed resource.
VOID Direct3DVertexBuffer8::PreLoad()
{
    Direct3DVertexBuffer8LogMethod(TRACE, PreLoad);

    this->State.Self->PreLoad();

    Direct3DVertexBuffer8LogMethodNoResult(TRACEDEBUGINFO, PreLoad);
}

// Returns the type of the resource.
D3DRESOURCETYPE Direct3DVertexBuffer8::GetType()
{
    Direct3DVertexBuffer8LogMethod(TRACE, GetType);

    CONST D3DRESOURCETYPE result = this->State.Self->GetType();

    Direct3DVertexBuffer8LogMethodCustomResult(TRACEDEBUGINFO, GetType, result, FALSE, D3DRESOURCETYPE);
}

// Locks a range of vertex data and obtains a pointer to the vertex buffer memory.
HRESULT Direct3DVertexBuffer8::Lock(UINT OffsetToLock, UINT SizeToLock, BYTE** ppbData, DWORD Flags)
{
    Direct3DVertexBuffer8LogMethodValue(TRACE, Lock, 4, (OffsetToLock, SizeToLock, ppbData, Flags));

    CONST HRESULT result = this->State.Self->Lock(OffsetToLock, SizeToLock, ppbData, Flags);

    Direct3DVertexBuffer8LogMethodResultValue(TRACEDEBUGINFO, Lock, result, 4, (OffsetToLock, SizeToLock, ppbData, Flags));
}

// Unlocks index data.
HRESULT Direct3DVertexBuffer8::Unlock()
{
    Direct3DVertexBuffer8LogMethod(TRACE, Unlock);

    CONST HRESULT result = this->State.Self->Unlock();

    Direct3DVertexBuffer8LogMethodResult(TRACEDEBUGINFO, Unlock, result);
}

// Retrieves a description of the vertex buffer resource.
HRESULT Direct3DVertexBuffer8::GetDesc(D3DVERTEXBUFFER_DESC* pDesc)
{
    Direct3DVertexBuffer8LogMethodValue(TRACE, GetDesc, 1, (pDesc));

    CONST HRESULT result = this->State.Self->GetDesc(pDesc);

    Direct3DVertexBuffer8LogMethodResultValue(TRACEDEBUGINFO, GetDesc, result, 1, (pDesc));
}