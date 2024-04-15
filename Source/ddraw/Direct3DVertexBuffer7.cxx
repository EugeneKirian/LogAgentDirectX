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

#include "Direct3DDevice7.hxx"
#include "Direct3DVertexBuffer.hxx"
#include "Direct3DVertexBuffer7.hxx"

#include <AgentLogger.hxx>
#include <Direct3DVertexBuffer7Logger.hxx>

#define Direct3DVertexBuffer7LogMethod(L, M) AgentLogMethod(L, Direct3DVertexBuffer7, M)
#define Direct3DVertexBuffer7LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DVertexBuffer7, M, C, PARAMS)

#define Direct3DVertexBuffer7LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DVertexBuffer7, AddRef, R)
#define Direct3DVertexBuffer7LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DVertexBuffer7, Release, R)

#define Direct3DVertexBuffer7LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DVertexBuffer7, M, R)
#define Direct3DVertexBuffer7LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DVertexBuffer7, M, R, C, PARAMS)

Direct3DVertexBuffer7::Direct3DVertexBuffer7(AgentConstructorParameters(Direct3DVertexBuffer7))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DVertexBuffer7);
}

Direct3DVertexBuffer7::~Direct3DVertexBuffer7()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DVertexBuffer7);
}

HRESULT Direct3DVertexBuffer7::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DVertexBuffer7LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DVertexBuffer7, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Direct3DVertexBuffer7, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }


    Direct3DVertexBuffer7LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DVertexBuffer7::AddRef()
{
    Direct3DVertexBuffer7LogMethod(TRACE, AddRef);
    Direct3DVertexBuffer7LogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG Direct3DVertexBuffer7::Release()
{
    Direct3DVertexBuffer7LogMethod(TRACE, Release);
    Direct3DVertexBuffer7LogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Locks a vertex buffer and obtains a pointer to the vertex buffer memory.
HRESULT Direct3DVertexBuffer7::Lock(DWORD dwFlags, LPVOID* lplpData, LPDWORD lpdwSize)
{
    Direct3DVertexBuffer7LogMethodValue(TRACE, Lock, 3, (dwFlags, lplpData, lpdwSize));

    CONST HRESULT result = this->State.Self->Lock(dwFlags, lplpData, lpdwSize);

    Direct3DVertexBuffer7LogMethodResultValue(TRACEDEBUGINFO, Lock, result, 3, (dwFlags, lplpData, lpdwSize));
}

// Unlocks a previously locked vertex buffer.
HRESULT Direct3DVertexBuffer7::Unlock()
{
    Direct3DVertexBuffer7LogMethod(TRACE, Unlock);

    CONST HRESULT result = this->State.Self->Unlock();

    Direct3DVertexBuffer7LogMethodResult(TRACEDEBUGINFO, Unlock, result);
}

// Processes untransformed vertices into a transformed or optimized vertex buffer.
HRESULT Direct3DVertexBuffer7::ProcessVertices(DWORD dwVertexOp, DWORD dwDestIndex, DWORD dwCount, LPDIRECT3DVERTEXBUFFER7 lpSrcBuffer, DWORD dwSrcIndex, LPDIRECT3DDEVICE7 lpD3DDevice, DWORD dwFlags)
{
    Direct3DVertexBuffer7LogMethodValue(TRACE, ProcessVertices, 7, (dwVertexOp, dwDestIndex, dwCount, lpSrcBuffer, dwSrcIndex, lpD3DDevice, dwFlags));

    AttemptAccessAgentValue(Direct3DVertexBuffer7, lpSrcBuffer);
    AttemptAccessAgentValue(Direct3DDevice7, lpD3DDevice);

    CONST HRESULT result = this->State.Self->ProcessVertices(dwVertexOp, dwDestIndex, dwCount, lpSrcBuffer, dwSrcIndex, lpD3DDevice, dwFlags);

    Direct3DVertexBuffer7LogMethodResultValue(TRACEDEBUGINFO, ProcessVertices, result, 7, (dwVertexOp, dwDestIndex, dwCount, ActivateAgent(Direct3DVertexBuffer7, lpSrcBuffer), dwSrcIndex, ActivateAgent(Direct3DDevice7, lpD3DDevice), dwFlags));
}

// Retrieves a description of the vertex buffer.
HRESULT Direct3DVertexBuffer7::GetVertexBufferDesc(LPD3DVERTEXBUFFERDESC lpVBDesc)
{
    Direct3DVertexBuffer7LogMethodValue(TRACE, GetVertexBufferDesc, 1, (lpVBDesc));

    CONST HRESULT result = this->State.Self->GetVertexBufferDesc(lpVBDesc);

    Direct3DVertexBuffer7LogMethodResultValue(TRACEDEBUGINFO, GetVertexBufferDesc, result, 1, (lpVBDesc));
}

// Converts an unoptimized vertex buffer into an optimized vertex buffer.
HRESULT Direct3DVertexBuffer7::Optimize(LPDIRECT3DDEVICE7 lpD3DDevice, DWORD dwFlags)
{
    Direct3DVertexBuffer7LogMethodValue(TRACE, Optimize, 2, (lpD3DDevice, dwFlags));

    AttemptAccessAgentValue(Direct3DDevice7, lpD3DDevice);

    CONST HRESULT result = this->State.Self->Optimize(lpD3DDevice, dwFlags);

    Direct3DVertexBuffer7LogMethodResultValue(TRACEDEBUGINFO, Optimize, result, 2, (ActivateAgent(Direct3DDevice7, lpD3DDevice), dwFlags));
}

// Processes untransformed strided vertices into a transformed or optimized vertex buffer.
HRESULT Direct3DVertexBuffer7::ProcessVerticesStrided(DWORD dwVertexOp, DWORD dwDestIndex, DWORD dwCount, LPD3DDRAWPRIMITIVESTRIDEDDATA lpVertexArray, DWORD dwSrcIndex, LPDIRECT3DDEVICE7 lpD3DDevice, DWORD dwFlags)
{
    Direct3DVertexBuffer7LogMethodValue(TRACE, ProcessVerticesStrided, 7, (dwVertexOp, dwDestIndex, dwCount, lpVertexArray, dwSrcIndex, lpD3DDevice, dwFlags));

    AttemptAccessAgentValue(Direct3DDevice7, lpD3DDevice);

    CONST HRESULT result = this->State.Self->ProcessVerticesStrided(dwVertexOp, dwDestIndex, dwCount, lpVertexArray, dwSrcIndex, lpD3DDevice, dwFlags);

    Direct3DVertexBuffer7LogMethodResultValue(TRACEDEBUGINFO, ProcessVerticesStrided, result, 7, (dwVertexOp, dwDestIndex, dwCount, lpVertexArray, dwSrcIndex, ActivateAgent(Direct3DDevice7, lpD3DDevice), dwFlags));
}