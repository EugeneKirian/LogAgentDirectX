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
#include "DirectDrawSurface4.hxx"

#include <AgentLogger.hxx>
#include <Direct3DViewport3Logger.hxx>

#define Direct3DViewport3LogMethod(L, M) AgentLogMethod(L, Direct3DViewport3, M)
#define Direct3DViewport3LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DViewport3, M, C, PARAMS)

#define Direct3DViewport3LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DViewport3, AddRef, R)
#define Direct3DViewport3LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DViewport3, Release, R)

#define Direct3DViewport3LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DViewport3, M, R)
#define Direct3DViewport3LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DViewport3, M, R, C, PARAMS)

Direct3DViewport3::Direct3DViewport3(AgentConstructorParameters(Direct3DViewport3))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DViewport3);
}

Direct3DViewport3::~Direct3DViewport3()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DViewport3);
}

HRESULT Direct3DViewport3::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DViewport3LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DViewport, riid)) { *ppvObj = ActivateAgent(Direct3DViewport, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DViewport2, riid)) { *ppvObj = ActivateAgent(Direct3DViewport2, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DViewport3, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Direct3DViewport3, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DViewport3::AddRef()
{
    Direct3DViewport3LogMethod(DEBUG, AddRef);
    Direct3DViewport3LogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG Direct3DViewport3::Release()
{
    Direct3DViewport3LogMethod(DEBUG, Release);
    Direct3DViewport3LogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// This method is not currently implemented.
HRESULT Direct3DViewport3::Initialize(LPDIRECT3D lpDirect3D)
{
    Direct3DViewport3LogMethodValue(TRACE, Initialize, 1, (lpDirect3D));

    AttemptAccessAgentValue(Direct3D, lpDirect3D);

    CONST HRESULT result = this->State.Self->Initialize(lpDirect3D);

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 1, (ActivateAgent(Direct3D, lpDirect3D)));
}

// Retrieves the viewport registers of the viewport.
// This method is provided for backward compatibility.
// It has been superseded by the GetViewport2 method.
HRESULT Direct3DViewport3::GetViewport(LPD3DVIEWPORT lpData)
{
    Direct3DViewport3LogMethodValue(TRACE, GetViewport, 1, (lpData));

    CONST HRESULT result = this->State.Self->GetViewport(lpData);

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, GetViewport, result, 1, (lpData));
}

// Sets the viewport registers of the viewport.
// This method is provided for backward compatibility.
// It has been superseded by the SetViewport2 method.
HRESULT Direct3DViewport3::SetViewport(LPD3DVIEWPORT lpData)
{
    Direct3DViewport3LogMethodValue(TRACE, SetViewport, 1, (lpData));

    CONST HRESULT result = this->State.Self->SetViewport(lpData);

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, SetViewport, result, 1, (lpData));
}

// Transforms a set of vertices by the transformation matrix.
HRESULT Direct3DViewport3::TransformVertices(DWORD dwVertexCount, LPD3DTRANSFORMDATA lpData, DWORD dwFlags, LPDWORD lpOffscreen)
{
    Direct3DViewport3LogMethodValue(TRACE, TransformVertices, 4, (dwVertexCount, lpData, dwFlags, lpOffscreen));

    CONST HRESULT result = this->State.Self->TransformVertices(dwVertexCount, lpData, dwFlags, lpOffscreen);

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, TransformVertices, result, 4, (dwVertexCount, lpData, dwFlags, lpOffscreen));
}

// This method is not currently implemented.
HRESULT Direct3DViewport3::LightElements(DWORD dwElementCount, LPD3DLIGHTDATA lpData)
{
    Direct3DViewport3LogMethodValue(TRACE, LightElements, 2, (dwElementCount, lpData));

    CONST HRESULT result = this->State.Self->LightElements(dwElementCount, lpData);

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, LightElements, result, 2, (dwElementCount, lpData));
}

// Sets the background material associated with the viewport.
HRESULT Direct3DViewport3::SetBackground(D3DMATERIALHANDLE hMat)
{
    Direct3DViewport3LogMethodValue(TRACE, SetBackground, 1, (hMat));

    CONST HRESULT result = this->State.Self->SetBackground(hMat);

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, SetBackground, result, 1, (hMat));
}

// Retrieves the handle to a material that represents the current background associated with the viewport.
HRESULT Direct3DViewport3::GetBackground(LPD3DMATERIALHANDLE lphMat, LPBOOL lpValid)
{
    Direct3DViewport3LogMethodValue(TRACE, GetBackground, 2, (lphMat, lpValid));

    CONST HRESULT result = this->State.Self->GetBackground(lphMat, lpValid);

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, GetBackground, result, 2, (lphMat, lpValid));
}

// Sets the background-depth field for the viewport.
HRESULT Direct3DViewport3::SetBackgroundDepth(LPDIRECTDRAWSURFACE lpDDSurface)
{
    Direct3DViewport3LogMethodValue(TRACE, SetBackgroundDepth, 1, (lpDDSurface));

    AttemptAccessAgentValue(DirectDrawSurface, lpDDSurface);

    CONST HRESULT result = this->State.Self->SetBackgroundDepth(lpDDSurface);

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, SetBackgroundDepth, result, 1, (ActivateAgent(DirectDrawSurface, lpDDSurface)));
}


// Retrieves a DirectDraw surface that represents the current background-depth field associated with the viewport.
HRESULT Direct3DViewport3::GetBackgroundDepth(LPDIRECTDRAWSURFACE* lplpDDSurface, LPBOOL lpValid)
{
    Direct3DViewport3LogMethodValue(TRACE, GetBackgroundDepth, 2, (lplpDDSurface, lpValid));

    CONST HRESULT result = this->State.Self->GetBackgroundDepth(lplpDDSurface, lpValid);

    if (SUCCEEDED(result)) { *lplpDDSurface = ActivateAgentDelegate(DirectDrawSurface, *lplpDDSurface); }

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, GetBackgroundDepth, result, 2, (lplpDDSurface, lpValid));
}

// Clears the viewport or a set of rectangles in the viewport to the current background material.
HRESULT Direct3DViewport3::Clear(DWORD dwCount, LPD3DRECT lpRects, DWORD dwFlags)
{
    Direct3DViewport3LogMethodValue(TRACE, Clear, 3, (dwCount, lpRects, dwFlags));

    CONST HRESULT result = this->State.Self->Clear(dwCount, lpRects, dwFlags);

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, Clear, result, 3, (dwCount, lpRects, dwFlags));
}

// Adds the specified light to the list of Direct3DLight objects associated with this viewport
// and increments the reference count of the light object.
HRESULT Direct3DViewport3::AddLight(LPDIRECT3DLIGHT lpDirect3DLight)
{
    Direct3DViewport3LogMethodValue(TRACE, AddLight, 1, (lpDirect3DLight));

    AttemptAccessAgentValue(Direct3DLight, lpDirect3DLight);

    CONST HRESULT result = this->State.Self->AddLight(lpDirect3DLight);

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, AddLight, result, 1, (ActivateAgent(Direct3DLight, lpDirect3DLight)));
}

// Removes the specified light from the list of Direct3DLight objects associated with this viewport,
// and decrements the reference count for the light object.
HRESULT Direct3DViewport3::DeleteLight(LPDIRECT3DLIGHT lpDirect3DLight)
{
    Direct3DViewport3LogMethodValue(TRACE, DeleteLight, 1, (lpDirect3DLight));

    AttemptAccessAgentValue(Direct3DLight, lpDirect3DLight);

    CONST HRESULT result = this->State.Self->DeleteLight(lpDirect3DLight);

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, DeleteLight, result, 1, (ActivateAgent(Direct3DLight, lpDirect3DLight)));
}

// Enumerates the Direct3DLight objects associated with the viewport.
HRESULT Direct3DViewport3::NextLight(LPDIRECT3DLIGHT lpDirect3DLight, LPDIRECT3DLIGHT* lplpDirect3DLight, DWORD dwFlags)
{
    Direct3DViewport3LogMethodValue(TRACE, NextLight, 3, (lpDirect3DLight, lplpDirect3DLight, dwFlags));

    AttemptAccessAgentValue(Direct3DLight, lpDirect3DLight);

    CONST HRESULT result = this->State.Self->NextLight(lpDirect3DLight, lplpDirect3DLight, dwFlags);

    if (SUCCEEDED(result)) { *lplpDirect3DLight = ActivateAgentDelegate(Direct3DLight, *lplpDirect3DLight); }

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, NextLight, result, 3, (ActivateAgent(Direct3DLight, lpDirect3DLight), lplpDirect3DLight, dwFlags));
}

// Retrieves the viewport registers of the viewport.
HRESULT Direct3DViewport3::GetViewport2(LPD3DVIEWPORT2 lpData)
{
    Direct3DViewport3LogMethodValue(TRACE, GetViewport2, 1, (lpData));

    CONST HRESULT result = this->State.Self->GetViewport2(lpData);

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, GetViewport2, result, 1, (lpData));
}

// Sets the viewport registers of the viewport.
HRESULT Direct3DViewport3::SetViewport2(LPD3DVIEWPORT2 lpData)
{
    Direct3DViewport3LogMethodValue(TRACE, SetViewport2, 1, (lpData));

    CONST HRESULT result = this->State.Self->SetViewport2(lpData);

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, SetViewport2, result, 1, (lpData));
}

// Sets the background-depth field for the viewport.
HRESULT Direct3DViewport3::SetBackgroundDepth2(LPDIRECTDRAWSURFACE4 lpDDSurface)
{
    Direct3DViewport3LogMethodValue(TRACE, SetBackgroundDepth2, 1, (lpDDSurface));

    AttemptAccessAgentValue(DirectDrawSurface4, lpDDSurface);

    CONST HRESULT result = this->State.Self->SetBackgroundDepth2(lpDDSurface);

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, SetBackgroundDepth2, result, 1, (ActivateAgent(DirectDrawSurface4, lpDDSurface)));
}

// Retrieves a DirectDraw surface that represents the current background-depth field associated with the viewport.
HRESULT Direct3DViewport3::GetBackgroundDepth2(LPDIRECTDRAWSURFACE4* lplpDDS, LPBOOL lpValid)
{
    Direct3DViewport3LogMethodValue(TRACE, GetBackgroundDepth2, 2, (lplpDDS, lpValid));

    CONST HRESULT result = this->State.Self->GetBackgroundDepth2(lplpDDS, lpValid);

    if (SUCCEEDED(result)) { *lplpDDS = ActivateAgentDelegate(DirectDrawSurface4, *lplpDDS); }

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, GetBackgroundDepth2, result, 2, (lplpDDS, lpValid));
}

// Clears the viewport (or a set of rectangles in the viewport) to a specified RGBA color,
// clears the depth-buffer, and erases the stencil buffer.
HRESULT Direct3DViewport3::Clear2(DWORD dwCount, LPD3DRECT lpRects, DWORD dwFlags, DWORD dwColor, D3DVALUE dvZ, DWORD dwStencil)
{
    Direct3DViewport3LogMethodValue(TRACE, Clear2, 6, (dwCount, lpRects, dwFlags, dwColor, dvZ, dwStencil));

    CONST HRESULT result = this->State.Self->Clear2(dwCount, lpRects, dwFlags, dwColor, dvZ, dwStencil);

    Direct3DViewport3LogMethodResultValue(TRACEDEBUGINFO, Clear2, result, 6, (dwCount, lpRects, dwFlags, dwColor, dvZ, dwStencil));
}