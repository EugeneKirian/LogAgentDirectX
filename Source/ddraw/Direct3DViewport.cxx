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
#include <Direct3DViewportLogger.hxx>

#define Direct3DViewportLogMethod(L, M) AgentLogMethod(L, Direct3DViewport, M)
#define Direct3DViewportLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DViewport, M, C, PARAMS)

#define Direct3DViewportLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DViewport, AddRef, R)
#define Direct3DViewportLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DViewport, Release, R)

#define Direct3DViewportLogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DViewport, M, R)
#define Direct3DViewportLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DViewport, M, R, C, PARAMS)

Direct3DViewport::Direct3DViewport(AgentConstructorParameters(Direct3DViewport))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DViewport);
}

Direct3DViewport::~Direct3DViewport()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DViewport);
}

HRESULT Direct3DViewport::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DViewportLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DViewport, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Direct3DViewport, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DViewport2, riid)) { *ppvObj = ActivateAgent(Direct3DViewport2, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DViewport3, riid)) { *ppvObj = ActivateAgent(Direct3DViewport3, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DViewportLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DViewport::AddRef()
{
    Direct3DViewportLogMethod(TRACE, AddRef);
    Direct3DViewportLogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG Direct3DViewport::Release()
{
   Direct3DViewportLogMethod(TRACE, Release);
   Direct3DViewportLogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// This method is not currently implemented.
HRESULT Direct3DViewport::Initialize(LPDIRECT3D lpDirect3D)
{
    Direct3DViewportLogMethodValue(TRACE, Initialize, 1, (lpDirect3D));

    AttemptAccessAgentValue(Direct3D, lpDirect3D);

    CONST HRESULT result = this->State.Self->Initialize(lpDirect3D);

    Direct3DViewportLogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 1, (ActivateAgent(Direct3D, lpDirect3D)));
}

// Retrieves the viewport registers of the viewport.
HRESULT Direct3DViewport::GetViewport(LPD3DVIEWPORT lpData)
{
    Direct3DViewportLogMethodValue(TRACE, GetViewport, 1, (lpData));
    
    CONST HRESULT result = this->State.Self->GetViewport(lpData);

    Direct3DViewportLogMethodResultValue(TRACEDEBUGINFO, GetViewport, result, 1, (lpData));
}

// Sets the viewport registers of the viewport.
HRESULT Direct3DViewport::SetViewport(LPD3DVIEWPORT lpData)
{
    Direct3DViewportLogMethodValue(TRACE, SetViewport, 1, (lpData));

    CONST HRESULT result = this->State.Self->SetViewport(lpData);

    Direct3DViewportLogMethodResultValue(TRACEDEBUGINFO, SetViewport, result, 1, (lpData));
}

// Transforms a set of vertices by the transformation matrix.
HRESULT Direct3DViewport::TransformVertices(DWORD dwVertexCount, LPD3DTRANSFORMDATA lpData, DWORD dwFlags, LPDWORD lpOffscreen)
{
    Direct3DViewportLogMethodValue(TRACE, TransformVertices, 4, (dwVertexCount, lpData, dwFlags, lpOffscreen));

    CONST HRESULT result = this->State.Self->TransformVertices(dwVertexCount, lpData, dwFlags, lpOffscreen);

    Direct3DViewportLogMethodResultValue(TRACEDEBUGINFO, TransformVertices, result, 4, (dwVertexCount, lpData, dwFlags, lpOffscreen));
}

// This method is not currently implemented.
HRESULT Direct3DViewport::LightElements(DWORD dwElementCount, LPD3DLIGHTDATA lpData)
{
    Direct3DViewportLogMethodValue(TRACE, LightElements, 2, (dwElementCount, lpData));

    CONST HRESULT result = this->State.Self->LightElements(dwElementCount, lpData);

    Direct3DViewportLogMethodResultValue(TRACEDEBUGINFO, LightElements, result, 2, (dwElementCount, lpData));
}

// Sets the background material associated with the viewport.
HRESULT Direct3DViewport::SetBackground(D3DMATERIALHANDLE hMat)
{
    Direct3DViewportLogMethodValue(TRACE, SetBackground, 1, (hMat));

    CONST HRESULT result = this->State.Self->SetBackground(hMat);

    Direct3DViewportLogMethodResultValue(TRACEDEBUGINFO, SetBackground, result, 1, (hMat));
}

// Retrieves the handle to a material that represents the current background associated with the viewport.
HRESULT Direct3DViewport::GetBackground(LPD3DMATERIALHANDLE lphMat, LPBOOL lpValid)
{
    Direct3DViewportLogMethodValue(TRACE, GetBackground, 2, (lphMat, lpValid));

    CONST HRESULT result = this->State.Self->GetBackground(lphMat, lpValid);

    Direct3DViewportLogMethodResultValue(TRACEDEBUGINFO, GetBackground, result, 2, (lphMat, lpValid));
}

// Sets the background-depth field for the viewport.
HRESULT Direct3DViewport::SetBackgroundDepth(LPDIRECTDRAWSURFACE lpDDSurface)
{
    Direct3DViewportLogMethodValue(TRACE, SetBackgroundDepth, 1, (lpDDSurface));

    AttemptAccessAgentValue(DirectDrawSurface, lpDDSurface);

    CONST HRESULT result = this->State.Self->SetBackgroundDepth(lpDDSurface);

    Direct3DViewportLogMethodResultValue(TRACEDEBUGINFO, SetBackgroundDepth, result, 1, (ActivateAgent(DirectDrawSurface, lpDDSurface)));
}

// Retrieves a DirectDraw surface that represents the current background-depth field associated with the viewport.
HRESULT Direct3DViewport::GetBackgroundDepth(LPDIRECTDRAWSURFACE* lplpDDSurface, LPBOOL lpValid)
{
    Direct3DViewportLogMethodValue(TRACE, GetBackgroundDepth, 2, (lplpDDSurface, lpValid));

    CONST HRESULT result = this->State.Self->GetBackgroundDepth(lplpDDSurface, lpValid);

    if (SUCCEEDED(result)) { *lplpDDSurface = ActivateAgent(DirectDrawSurface, *lplpDDSurface); }

    Direct3DViewportLogMethodResultValue(TRACEDEBUGINFO, GetBackgroundDepth, result, 2, (lplpDDSurface, lpValid));
}

// Clears the viewport or a set of rectangles in the viewport to the current background material.
HRESULT Direct3DViewport::Clear(DWORD dwCount, LPD3DRECT lpRects, DWORD dwFlags)
{
    Direct3DViewportLogMethodValue(TRACE, Clear, 3, (dwCount, lpRects, dwFlags));

    CONST HRESULT result = this->State.Self->Clear(dwCount, lpRects, dwFlags);

    Direct3DViewportLogMethodResultValue(TRACEDEBUGINFO, Clear, result, 3, (dwCount, lpRects, dwFlags));
}

// Adds the specified light to the list of Direct3DLight objects associated with this viewport
// and increments the reference count of the light object.
HRESULT Direct3DViewport::AddLight(LPDIRECT3DLIGHT lpDirect3DLight)
{
    Direct3DViewportLogMethodValue(TRACE, AddLight, 1, (lpDirect3DLight));

    AttemptAccessAgentValue(Direct3DLight, lpDirect3DLight);

    CONST HRESULT result = this->State.Self->AddLight(lpDirect3DLight);

    Direct3DViewportLogMethodResultValue(TRACEDEBUGINFO, AddLight, result, 1, (ActivateAgent(Direct3DLight, lpDirect3DLight)));
}

// Removes the specified light from the list of Direct3DLight objects associated with this viewport,
// and decrements the reference count for the light object.
HRESULT Direct3DViewport::DeleteLight(LPDIRECT3DLIGHT lpDirect3DLight)
{
    Direct3DViewportLogMethodValue(TRACE, DeleteLight, 1, (lpDirect3DLight));

    AttemptAccessAgentValue(Direct3DLight, lpDirect3DLight);

    CONST HRESULT result = this->State.Self->DeleteLight(lpDirect3DLight);

    Direct3DViewportLogMethodResultValue(TRACEDEBUGINFO, DeleteLight, result, 1, (ActivateAgent(Direct3DLight, lpDirect3DLight)));
}

// Enumerates the Direct3DLight objects associated with the viewport.
HRESULT Direct3DViewport::NextLight(LPDIRECT3DLIGHT lpDirect3DLight, LPDIRECT3DLIGHT* lplpDirect3DLight, DWORD dwFlags)
{
    Direct3DViewportLogMethodValue(TRACE, NextLight, 3, (lpDirect3DLight, lplpDirect3DLight, dwFlags));
    
    AttemptAccessAgentValue(Direct3DLight, lpDirect3DLight);

    CONST HRESULT result = this->State.Self->NextLight(lpDirect3DLight, lplpDirect3DLight, dwFlags);

    if (SUCCEEDED(result)) { *lplpDirect3DLight = ActivateAgent(Direct3DLight, *lplpDirect3DLight); }

    Direct3DViewportLogMethodResultValue(TRACEDEBUGINFO, NextLight, result, 3, (ActivateAgent(Direct3DLight, lpDirect3DLight), lplpDirect3DLight, dwFlags));
}