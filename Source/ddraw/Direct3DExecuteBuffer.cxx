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

#include "Direct3DDevice.hxx"
#include "Direct3DExecuteBuffer.hxx"

#include <AgentLogger.hxx>
#include <Direct3DExecuteBufferLogger.hxx>

#define Direct3DExecuteBufferLogMethod(L, M) AgentLogMethod(L, Direct3DExecuteBuffer, M)
#define Direct3DExecuteBufferLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DExecuteBuffer, M, C, PARAMS)

#define Direct3DExecuteBufferLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DExecuteBuffer, AddRef, R)
#define Direct3DExecuteBufferLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DExecuteBuffer, Release, R)

#define Direct3DExecuteBufferLogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DExecuteBuffer, M, R)
#define Direct3DExecuteBufferLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DExecuteBuffer, M, R, C, PARAMS)

#define Direct3DExecuteBufferLogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, Direct3DExecuteBuffer, M, C, PARAMS)
#define Direct3DExecuteBufferLogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, Direct3DExecuteBuffer, M, R, C, PARAMS)

typedef struct ValidateCallbackContext
{
    Direct3DExecuteBuffer* Self;
    LPLOGGER Logger;
    LPD3DVALIDATECALLBACK Func;
    LPVOID Context;
} VALIDATECALLBACKCONTEXT, * LPVALIDATECALLBACKCONTEXT;

static HRESULT CALLBACK ValidateCallback(LPVOID lpContext, DWORD dwOffset)
{
    LPVALIDATECALLBACKCONTEXT context = (LPVALIDATECALLBACKCONTEXT)lpContext;

    Direct3DExecuteBufferLogMethodCallbackValue(TRACEDEBUG, Validate, 2, (context->Self, dwOffset));

    CONST HRESULT result = context->Func(context->Context, dwOffset);

    Direct3DExecuteBufferLogMethodCallbackResultValue(TRACEDEBUGINFO, Validate, result, 2, (context->Self, dwOffset));
}

Direct3DExecuteBuffer::Direct3DExecuteBuffer(AgentConstructorParameters(Direct3DExecuteBuffer))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DExecuteBuffer);
}

Direct3DExecuteBuffer::~Direct3DExecuteBuffer()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DExecuteBuffer);
}

HRESULT Direct3DExecuteBuffer::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DExecuteBufferLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DExecuteBuffer, riid)) { *ppvObj = ActivateAgent(Direct3DExecuteBuffer, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DExecuteBufferLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DExecuteBuffer::AddRef()
{
     Direct3DExecuteBufferLogMethod(TRACE, AddRef);
     Direct3DExecuteBufferLogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG Direct3DExecuteBuffer::Release()
{
     Direct3DExecuteBufferLogMethod(TRACE, Release);
     Direct3DExecuteBufferLogReleaseMethodResult(TRACE, this->State.Self->Release());
}

HRESULT Direct3DExecuteBuffer::Initialize(LPDIRECT3DDEVICE lpDirect3DDevice, LPD3DEXECUTEBUFFERDESC lpDesc)
{
    Direct3DExecuteBufferLogMethodValue(TRACE, Initialize, 2, (lpDirect3DDevice, lpDesc));

    AttemptAccessAgentValue(Direct3DDevice, lpDirect3DDevice);

    CONST HRESULT result = this->State.Self->Initialize(lpDirect3DDevice, lpDesc);

    Direct3DExecuteBufferLogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 2, (ActivateAgent(Direct3DDevice, lpDirect3DDevice), lpDesc));
}

// Obtains a direct pointer to the commands in the execute buffer.
HRESULT Direct3DExecuteBuffer::Lock(LPD3DEXECUTEBUFFERDESC lpDesc)
{
    Direct3DExecuteBufferLogMethodValue(TRACE, Lock, 1, (lpDesc));

    CONST HRESULT result = this->State.Self->Lock(lpDesc);

    Direct3DExecuteBufferLogMethodResultValue(TRACEDEBUGINFO, Lock, result, 1, (lpDesc));
}

// Releases the direct pointer to the commands in the execute buffer.
HRESULT Direct3DExecuteBuffer::Unlock()
{
    Direct3DExecuteBufferLogMethod(TRACE, Lock);

    CONST HRESULT result = this->State.Self->Unlock();

    Direct3DExecuteBufferLogMethodResult(TRACEDEBUGINFO, Unlock, result);
}

// Sets the execute data state of the Direct3DExecuteBuffer object.
// The execute data is used to describe the contents of the Direct3DExecuteBuffer object.
HRESULT Direct3DExecuteBuffer::SetExecuteData(LPD3DEXECUTEDATA lpData)
{
    Direct3DExecuteBufferLogMethodValue(TRACE, SetExecuteData, 1, (lpData));

    CONST HRESULT result = this->State.Self->SetExecuteData(lpData);

    Direct3DExecuteBufferLogMethodResultValue(TRACEDEBUGINFO, SetExecuteData, result, 1, (lpData));
}

// Retrieves the execute data state of the Direct3DExecuteBuffer object.
// The execute data is used to describe the contents of the Direct3DExecuteBuffer object.
HRESULT Direct3DExecuteBuffer::GetExecuteData(LPD3DEXECUTEDATA lpData)
{
    Direct3DExecuteBufferLogMethodValue(TRACE, GetExecuteData, 1, (lpData));

    CONST HRESULT result = this->State.Self->GetExecuteData(lpData);

    Direct3DExecuteBufferLogMethodResultValue(TRACEDEBUGINFO, GetExecuteData, result, 1, (lpData));
}

// This method is not currently implemented.
HRESULT Direct3DExecuteBuffer::Validate(LPDWORD lpdwOffset, LPD3DVALIDATECALLBACK lpFunc, LPVOID lpContext, DWORD dwReserved)
{
    Direct3DExecuteBufferLogMethodValue(TRACEDEBUG, Validate, 4, (lpdwOffset, lpFunc, lpContext, dwReserved));

    if (lpContext == NULL) { Direct3DExecuteBufferLogMethodResultValue(TRACEDEBUGINFO, Validate, DDERR_INVALIDPARAMS, 4, (lpdwOffset, lpFunc, lpContext, dwReserved)); }

    VALIDATECALLBACKCONTEXT context;

    context.Self = this;
    context.Func = lpFunc;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->Validate(lpdwOffset, ValidateCallback, &context, dwReserved);

    Direct3DExecuteBufferLogMethodResultValue(TRACEDEBUGINFO, Validate, result, 4, (lpdwOffset, lpFunc, lpContext, dwReserved));
}

// This method is not currently supported.
HRESULT Direct3DExecuteBuffer::Optimize(DWORD dwFlags)
{
    Direct3DExecuteBufferLogMethodValue(TRACE, Optimize, 1, (dwFlags));

    CONST HRESULT result = this->State.Self->Optimize(dwFlags);

    Direct3DExecuteBufferLogMethodResultValue(TRACEDEBUGINFO, Optimize, result, 1, (dwFlags));
}