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

#include <AgentLogger.hxx>
#include <Direct3DLightLogger.hxx>

#define Direct3DLightLogMethod(L, M) AgentLogMethod(L, Direct3DLight, M)
#define Direct3DLightLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DLight, M, C, PARAMS)

#define Direct3DLightLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DLight, AddRef, R)
#define Direct3DLightLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DLight, Release, R)

#define Direct3DLightLogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DLight, M, R)
#define Direct3DLightLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DLight, M, R, C, PARAMS)

#define Direct3DLightLogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, Direct3DLight, M, C, PARAMS)
#define Direct3DLightLogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, Direct3DLight, M, R, C, PARAMS)

Direct3DLight::Direct3DLight(AgentConstructorParameters(Direct3DLight))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DLight);
}

Direct3DLight::~Direct3DLight()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DLight);
}

HRESULT Direct3DLight::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DLightLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DLight, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Direct3DLight, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DLightLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DLight::AddRef()
{
    Direct3DLightLogMethod(TRACE, AddRef);
    Direct3DLightLogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG Direct3DLight::Release()
{
    Direct3DLightLogMethod(TRACE, Release);
    Direct3DLightLogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// This method is not currently implemented.
HRESULT Direct3DLight::Initialize(LPDIRECT3D lpDirect3D)
{
    Direct3DLightLogMethodValue(TRACE, Initialize, 1, (lpDirect3D));

    AttemptAccessAgentValue(Direct3D, lpDirect3D);

    CONST HRESULT result = this->State.Self->Initialize(lpDirect3D);

    Direct3DLightLogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 1, (ActivateAgent(Direct3D, lpDirect3D)));
}

// Sets the light information for the Direct3DLight object.
HRESULT Direct3DLight::SetLight(LPD3DLIGHT lpLight)
{
    Direct3DLightLogMethodValue(TRACE, SetLight, 1, (lpLight));

    CONST HRESULT result = this->State.Self->SetLight(lpLight);

    Direct3DLightLogMethodResultValue(TRACEDEBUGINFO, SetLight, result, 1, (lpLight));
}

// Retrieves the light information for the Direct3DLight object.
HRESULT Direct3DLight::GetLight(LPD3DLIGHT lpLight)
{
    Direct3DLightLogMethodValue(TRACE, GetLight, 1, (lpLight));

    CONST HRESULT result = this->State.Self->GetLight(lpLight);

    Direct3DLightLogMethodResultValue(TRACEDEBUGINFO, GetLight, result, 1, (lpLight));
}