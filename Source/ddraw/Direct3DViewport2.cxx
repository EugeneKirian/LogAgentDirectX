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

#include "Direct3D.hxx"
#include "Direct3DLight.hxx"
#include "Direct3DViewport.hxx"
#include "Direct3DViewport2.hxx"
#include "Direct3DViewport3.hxx"
#include "DirectDrawSurface.hxx"

#include <AgentLogger.hxx>
#include <Direct3DViewport2Logger.hxx>

#define Direct3DViewport2LogMethod(L, M) AgentLogMethod(L, Direct3DViewport2, M)
#define Direct3DViewport2LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DViewport2, M, C, PARAMS)

#define Direct3DViewport2LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DViewport2, AddRef, R)
#define Direct3DViewport2LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DViewport2, Release, R)

#define Direct3DViewport2LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DViewport2, M, R)
#define Direct3DViewport2LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DViewport2, M, R, C, PARAMS)

Direct3DViewport2::Direct3DViewport2(AgentConstructorParameters(Direct3DViewport2))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DViewport2);
}

Direct3DViewport2::~Direct3DViewport2()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DViewport2);
}

HRESULT Direct3DViewport2::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DViewport2LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DViewport, riid)) { *ppvObj = ActivateAgent(Direct3DViewport, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DViewport2, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Direct3DViewport2, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DViewport3, riid)) { *ppvObj = ActivateAgent(Direct3DViewport3, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DViewport2LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DViewport2::AddRef()
{
    Direct3DViewport2LogMethod(DEBUG, AddRef);
    Direct3DViewport2LogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG Direct3DViewport2::Release()
{
    Direct3DViewport2LogMethod(DEBUG, Release);
    Direct3DViewport2LogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// This method is not currently implemented.
HRESULT Direct3DViewport2::Initialize(LPDIRECT3D lpDirect3D)
{
    Direct3DViewport2LogMethodValue(TRACE, Initialize, 1, (lpDirect3D));

    AttemptAccessAgentValue(Direct3D, lpDirect3D);

    CONST HRESULT result = this->State.Self->Initialize(lpDirect3D);

    Direct3DViewport2LogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 1, (ActivateAgent(Direct3D, lpDirect3D)));
}

// Retrieves the viewport registers of the viewport.
// This method is provided for backward compatibility.
// It has been superseded by the GetViewport2 method.
HRESULT Direct3DViewport2::GetViewport(LPD3DVIEWPORT lpData)
{
    Direct3DViewport2LogMethodValue(TRACE, GetViewport, 1, (lpData));

    CONST HRESULT result = this->State.Self->GetViewport(lpData);

    Direct3DViewport2LogMethodResultValue(TRACEDEBUGINFO, GetViewport, result, 1, (lpData));
}

// Sets the viewport registers of the viewport.
// This method is provided for backward compatibility.
// It has been superseded by the SetViewport2 method.
HRESULT Direct3DViewport2::SetViewport(LPD3DVIEWPORT lpData)
{
    Direct3DViewport2LogMethodValue(TRACE, SetViewport, 1, (lpData));

    CONST HRESULT result = this->State.Self->SetViewport(lpData);

    Direct3DViewport2LogMethodResultValue(TRACEDEBUGINFO, SetViewport, result, 1, (lpData));
}

// Transforms a set of vertices by the transformation matrix.
HRESULT Direct3DViewport2::TransformVertices(DWORD dwVertexCount, LPD3DTRANSFORMDATA lpData, DWORD dwFlags, LPDWORD lpOffscreen)
{
    Direct3DViewport2LogMethodValue(TRACE, TransformVertices, 4, (dwVertexCount, lpData, dwFlags, lpOffscreen));

    CONST HRESULT result = this->State.Self->TransformVertices(dwVertexCount, lpData, dwFlags, lpOffscreen);

    Direct3DViewport2LogMethodResultValue(TRACEDEBUGINFO, TransformVertices, result, 4, (dwVertexCount, lpData, dwFlags, lpOffscreen));
}

// This method is not currently implemented.
HRESULT Direct3DViewport2::LightElements(DWORD dwElementCount, LPD3DLIGHTDATA lpData)
{
    Direct3DViewport2LogMethodValue(TRACE, LightElements, 2, (dwElementCount, lpData));

    CONST HRESULT result = this->State.Self->LightElements(dwElementCount, lpData);

    Direct3DViewport2LogMethodResultValue(TRACEDEBUGINFO, LightElements, result, 2, (dwElementCount, lpData));
}

// Sets the background material associated with the viewport.
HRESULT Direct3DViewport2::SetBackground(D3DMATERIALHANDLE hMat)
{
    Direct3DViewport2LogMethodValue(TRACE, SetBackground, 1, (hMat));

    CONST HRESULT result = this->State.Self->SetBackground(hMat);

    Direct3DViewport2LogMethodResultValue(TRACEDEBUGINFO, SetBackground, result, 1, (hMat));
}

// Retrieves the handle to a material that represents the current background associated with the viewport.
HRESULT Direct3DViewport2::GetBackground(LPD3DMATERIALHANDLE lphMat, LPBOOL lpValid)
{
    Direct3DViewport2LogMethodValue(TRACE, GetBackground, 2, (lphMat, lpValid));

    CONST HRESULT result = this->State.Self->GetBackground(lphMat, lpValid);

    Direct3DViewport2LogMethodResultValue(TRACEDEBUGINFO, GetBackground, result, 2, (lphMat, lpValid));
}

// Sets the background-depth field for the viewport.
HRESULT Direct3DViewport2::SetBackgroundDepth(LPDIRECTDRAWSURFACE lpDDSurface)
{
    Direct3DViewport2LogMethodValue(TRACE, SetBackgroundDepth, 1, (lpDDSurface));

    AttemptAccessAgentValue(DirectDrawSurface, lpDDSurface);

    CONST HRESULT result = this->State.Self->SetBackgroundDepth(lpDDSurface);

    Direct3DViewport2LogMethodResultValue(TRACEDEBUGINFO, SetBackgroundDepth, result, 1, (ActivateAgent(DirectDrawSurface, lpDDSurface)));
}

// Retrieves a DirectDraw surface that represents the current background-depth field associated with the viewport.
HRESULT Direct3DViewport2::GetBackgroundDepth(LPDIRECTDRAWSURFACE* lplpDDSurface, LPBOOL lpValid)
{
    Direct3DViewport2LogMethodValue(TRACE, GetBackgroundDepth, 2, (lplpDDSurface, lpValid));

    CONST HRESULT result = this->State.Self->GetBackgroundDepth(lplpDDSurface, lpValid);

    if (SUCCEEDED(result)) { *lplpDDSurface = ActivateAgentDelegate(DirectDrawSurface, *lplpDDSurface); }

    Direct3DViewport2LogMethodResultValue(TRACEDEBUGINFO, GetBackgroundDepth, result, 2, (lplpDDSurface, lpValid));
}

// Clears the viewport or a set of rectangles in the viewport to the current background material.
HRESULT Direct3DViewport2::Clear(DWORD dwCount, LPD3DRECT lpRects, DWORD dwFlags)
{
    Direct3DViewport2LogMethodValue(TRACE, Clear, 3, (dwCount, lpRects, dwFlags));

    CONST HRESULT result = this->State.Self->Clear(dwCount, lpRects, dwFlags);

    Direct3DViewport2LogMethodResultValue(TRACEDEBUGINFO, Clear, result, 3, (dwCount, lpRects, dwFlags));
}

// Adds the specified light to the list of Direct3DLight objects associated with this viewport
// and increments the reference count of the light object.
HRESULT Direct3DViewport2::AddLight(LPDIRECT3DLIGHT lpDirect3DLight)
{
    Direct3DViewport2LogMethodValue(TRACE, AddLight, 1, (lpDirect3DLight));

    AttemptAccessAgentValue(Direct3DLight, lpDirect3DLight);

    CONST HRESULT result = this->State.Self->AddLight(lpDirect3DLight);

    Direct3DViewport2LogMethodResultValue(TRACEDEBUGINFO, AddLight, result, 1, (ActivateAgent(Direct3DLight, lpDirect3DLight)));
}

// Removes the specified light from the list of Direct3DLight objects associated with this viewport,
// and decrements the reference count for the light object.
HRESULT Direct3DViewport2::DeleteLight(LPDIRECT3DLIGHT lpDirect3DLight)
{
    Direct3DViewport2LogMethodValue(TRACE, DeleteLight, 1, (lpDirect3DLight));

    AttemptAccessAgentValue(Direct3DLight, lpDirect3DLight);

    CONST HRESULT result = this->State.Self->DeleteLight(lpDirect3DLight);

    Direct3DViewport2LogMethodResultValue(TRACEDEBUGINFO, DeleteLight, result, 1, (ActivateAgent(Direct3DLight, lpDirect3DLight)));
}

// Enumerates the Direct3DLight objects associated with the viewport.
HRESULT Direct3DViewport2::NextLight(LPDIRECT3DLIGHT lpDirect3DLight, LPDIRECT3DLIGHT* lplpDirect3DLight, DWORD dwFlags)
{
    Direct3DViewport2LogMethodValue(TRACE, NextLight, 3, (lpDirect3DLight, lplpDirect3DLight, dwFlags));

    AttemptAccessAgentValue(Direct3DLight, lpDirect3DLight);

    CONST HRESULT result = this->State.Self->NextLight(lpDirect3DLight, lplpDirect3DLight, dwFlags);

    if (SUCCEEDED(result)) { *lplpDirect3DLight = ActivateAgentDelegate(Direct3DLight, *lplpDirect3DLight); }

    Direct3DViewport2LogMethodResultValue(TRACEDEBUGINFO, NextLight, result, 3, (ActivateAgent(Direct3DLight, lpDirect3DLight), lplpDirect3DLight, dwFlags));
}

// Retrieves the viewport registers of the viewport.
HRESULT Direct3DViewport2::GetViewport2(LPD3DVIEWPORT2 lpData)
{
    Direct3DViewport2LogMethodValue(TRACE, GetViewport2, 1, (lpData));

    CONST HRESULT result = this->State.Self->GetViewport2(lpData);

    Direct3DViewport2LogMethodResultValue(TRACEDEBUGINFO, GetViewport2, result, 1, (lpData));
}

// Sets the viewport registers of the viewport.
HRESULT Direct3DViewport2::SetViewport2(LPD3DVIEWPORT2 lpData)
{
    Direct3DViewport2LogMethodValue(TRACE, SetViewport2, 1, (lpData));

    CONST HRESULT result = this->State.Self->SetViewport2(lpData);

    Direct3DViewport2LogMethodResultValue(TRACEDEBUGINFO, SetViewport2, result, 1, (lpData));
}