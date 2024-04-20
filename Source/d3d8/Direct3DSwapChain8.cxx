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

#include "Direct3DSurface8.hxx"
#include "Direct3DSwapChain8.hxx"

#include <AgentLogger.hxx>
#include <Direct3DSwapChain8Logger.hxx>

#define Direct3DSwapChain8LogMethod(L, M) AgentLogMethod(L, Direct3DSwapChain8, M)
#define Direct3DSwapChain8LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DSwapChain8, M, C, PARAMS)

#define Direct3DSwapChain8LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DSwapChain8, AddRef, R)
#define Direct3DSwapChain8LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DSwapChain8, Release, R, FALSE)

#define Direct3DSwapChain8LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DSwapChain8, M, R)
#define Direct3DSwapChain8LogMethodCustomResult(L, M, R, F, T) AgentLogMethodCustomResult(L, Direct3DSwapChain8, M, R, F, T)

#define Direct3DSwapChain8LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DSwapChain8, M, R, C, PARAMS)
#define Direct3DSwapChain8LogMethodCustomResultValue(L, M, R, F, T, C, PARAMS) AgentLogMethodCustomResultValue(L, Direct3DSwapChain8, M, R, F, T, C, PARAMS)

Direct3DSwapChain8::Direct3DSwapChain8(AgentConstructorParameters(Direct3DSwapChain8))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DSwapChain8);
}

Direct3DSwapChain8::~Direct3DSwapChain8()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DSwapChain8);
}

HRESULT Direct3DSwapChain8::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DSwapChain8LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DSwapChain8, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Direct3DSwapChain8, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DSwapChain8LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DSwapChain8::AddRef()
{
    Direct3DSwapChain8LogMethod(TRACE, AddRef);
    Direct3DSwapChain8LogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG Direct3DSwapChain8::Release()
{
    Direct3DSwapChain8LogMethod(TRACE, Release);
    Direct3DSwapChain8LogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Presents the contents of the next in the sequence of back buffers owned by the swap chain. 
HRESULT Direct3DSwapChain8::Present(CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion)
{
    Direct3DSwapChain8LogMethodValue(TRACE, Present, 4, (pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion));

    CONST HRESULT result = this->State.Self->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);

    Direct3DSwapChain8LogMethodResultValue(TRACEDEBUGINFO, Present, result, 4, (pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion));
}

// Retrieves a back buffer from the swap chain of the device.
HRESULT Direct3DSwapChain8::GetBackBuffer(UINT BackBuffer, D3DBACKBUFFER_TYPE Type, LPDIRECT3DSURFACE8* ppBackBuffer)
{
    Direct3DSwapChain8LogMethodValue(TRACE, GetBackBuffer, 3, (BackBuffer, Type, ppBackBuffer));

    CONST HRESULT result = this->State.Self->GetBackBuffer(BackBuffer, Type, ppBackBuffer);

    if (SUCCEEDED(result)) { *ppBackBuffer = ActivateAgent(Direct3DSurface8, *ppBackBuffer); }

    Direct3DSwapChain8LogMethodResultValue(TRACEDEBUGINFO, GetBackBuffer, result, 3, (BackBuffer, Type, ppBackBuffer));
}