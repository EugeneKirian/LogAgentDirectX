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

#include "Direct3DDevice3.hxx"
#include "Direct3DVertexBuffer.hxx"
#include "Direct3DVertexBuffer7.hxx"

#include <AgentLogger.hxx>
#include <Direct3DVertexBufferLogger.hxx>

#define Direct3DVertexBufferLogMethod(L, M) AgentLogMethod(L, Direct3DVertexBuffer, M)
#define Direct3DVertexBufferLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DVertexBuffer, M, C, PARAMS)

#define Direct3DVertexBufferLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DVertexBuffer, AddRef, R)
#define Direct3DVertexBufferLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DVertexBuffer, Release, R)

#define Direct3DVertexBufferLogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DVertexBuffer, M, R)
#define Direct3DVertexBufferLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DVertexBuffer, M, R, C, PARAMS)

Direct3DVertexBuffer::Direct3DVertexBuffer(AgentConstructorParameters(Direct3DVertexBuffer))
{
    AgentConstructor();
    AgentLogConstructor(DEBUG, Direct3DVertexBuffer);
}

Direct3DVertexBuffer::~Direct3DVertexBuffer()
{
    AgentDestructor();
    AgentLogDestructor(DEBUG, Direct3DVertexBuffer);
}

HRESULT Direct3DVertexBuffer::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DVertexBufferLogMethodValue(DEBUG, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DVertexBuffer, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Direct3DVertexBuffer, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DVertexBufferLogMethodResultValue(DEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DVertexBuffer::AddRef()
{
    Direct3DVertexBufferLogMethod(DEBUG, AddRef);
    Direct3DVertexBufferLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG Direct3DVertexBuffer::Release()
{
    Direct3DVertexBufferLogMethod(DEBUG, Release);
    Direct3DVertexBufferLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Locks a vertex buffer and obtains a pointer to the vertex buffer memory.
HRESULT Direct3DVertexBuffer::Lock(DWORD dwFlags, LPVOID* lplpData, LPDWORD lpdwSize)
{
    Direct3DVertexBufferLogMethodValue(DEBUG, Lock, 3, (dwFlags, lplpData, lpdwSize));

    CONST HRESULT result = this->State.Self->Lock(dwFlags, lplpData, lpdwSize);

    Direct3DVertexBufferLogMethodResultValue(DEBUGINFO, Lock, result, 3, (dwFlags, lplpData, lpdwSize));
}

// Unlocks a previously locked vertex buffer.
HRESULT Direct3DVertexBuffer::Unlock()
{
    Direct3DVertexBufferLogMethod(DEBUG, Unlock);

    CONST HRESULT result = this->State.Self->Unlock();

    Direct3DVertexBufferLogMethodResult(DEBUGINFO, Unlock, result);
}

// Processes untransformed vertices into a transformed or optimized vertex buffer.
HRESULT Direct3DVertexBuffer::ProcessVertices(DWORD dwVertexOp, DWORD dwDestIndex, DWORD dwCount, LPDIRECT3DVERTEXBUFFER lpSrcBuffer, DWORD dwSrcIndex, LPDIRECT3DDEVICE3 lpD3DDevice, DWORD dwFlags)
{
    Direct3DVertexBufferLogMethodValue(DEBUG, ProcessVertices, 7, (dwVertexOp, dwDestIndex, dwCount, lpSrcBuffer, dwSrcIndex, lpD3DDevice, dwFlags));

    AttemptAccessAgentValue(Direct3DVertexBuffer, lpSrcBuffer);
    AttemptAccessAgentValue(Direct3DDevice3, lpD3DDevice);

    CONST HRESULT result = this->State.Self->ProcessVertices(dwVertexOp, dwDestIndex, dwCount, lpSrcBuffer, dwSrcIndex, lpD3DDevice, dwFlags);

    Direct3DVertexBufferLogMethodResultValue(DEBUGINFO, ProcessVertices, result, 7, (dwVertexOp, dwDestIndex, dwCount, ActivateAgent(Direct3DVertexBuffer, lpSrcBuffer), dwSrcIndex, ActivateAgent(Direct3DDevice3, lpD3DDevice), dwFlags));
}

// Retrieves a description of the vertex buffer.
HRESULT Direct3DVertexBuffer::GetVertexBufferDesc(LPD3DVERTEXBUFFERDESC lpVBDesc)
{
    Direct3DVertexBufferLogMethodValue(DEBUG, GetVertexBufferDesc, 1, (lpVBDesc));

    CONST HRESULT result = this->State.Self->GetVertexBufferDesc(lpVBDesc);

    Direct3DVertexBufferLogMethodResultValue(DEBUGINFO, GetVertexBufferDesc, result, 1, (lpVBDesc));
}

// Converts an unoptimized vertex buffer into an optimized vertex buffer.
HRESULT Direct3DVertexBuffer::Optimize(LPDIRECT3DDEVICE3 lpD3DDevice, DWORD dwFlags)
{
    Direct3DVertexBufferLogMethodValue(DEBUG, Optimize, 2, (lpD3DDevice, dwFlags));

    AttemptAccessAgentValue(Direct3DDevice3, lpD3DDevice);

    CONST HRESULT result = this->State.Self->Optimize(lpD3DDevice, dwFlags);

    Direct3DVertexBufferLogMethodResultValue(DEBUGINFO, Optimize, result, 2, (ActivateAgent(Direct3DDevice3, lpD3DDevice), dwFlags));
}