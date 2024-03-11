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
#include "Direct3DDevice.hxx"
#include "Direct3DMaterial.hxx"
#include "Direct3DMaterial2.hxx"
#include "Direct3DMaterial3.hxx"

#include <AgentLogger.hxx>
#include <Direct3DMaterialLogger.hxx>

#define Direct3DMaterialLogMethod(L, M) AgentLogMethod(L, Direct3DMaterial, M)
#define Direct3DMaterialLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DMaterial, M, C, PARAMS)

#define Direct3DMaterialLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DMaterial, AddRef, R)
#define Direct3DMaterialLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DMaterial, Release, R)

#define Direct3DMaterialLogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DMaterial, M, R)
#define Direct3DMaterialLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DMaterial, M, R, C, PARAMS)

Direct3DMaterial::Direct3DMaterial(AgentConstructorParameters(Direct3DMaterial))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DMaterial);
}

Direct3DMaterial::~Direct3DMaterial()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DMaterial);
}

HRESULT Direct3DMaterial::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DMaterialLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DMaterial, riid)) { *ppvObj = ActivateAgent(Direct3DMaterial, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DMaterial2, riid)) { *ppvObj = ActivateAgent(Direct3DMaterial2, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DMaterial3, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Direct3DMaterial3, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DMaterialLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DMaterial::AddRef()
{
    Direct3DMaterialLogMethod(DEBUG, AddRef);
    Direct3DMaterialLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG Direct3DMaterial::Release()
{
     Direct3DMaterialLogMethod(DEBUG, Release);
     Direct3DMaterialLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// This method is not currently implemented.
HRESULT Direct3DMaterial::Initialize(LPDIRECT3D lpDirect3D)
{
    Direct3DMaterialLogMethodValue(TRACE, Initialize, 1, (lpDirect3D));

    AttemptAccessAgentValue(Direct3D, lpDirect3D);

    CONST HRESULT result = this->State.Self->Initialize(lpDirect3D);

    Direct3DMaterialLogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 1, (ActivateAgent(Direct3D, lpDirect3D)));
}

// Sets the material data for a material object.
HRESULT Direct3DMaterial::SetMaterial(LPD3DMATERIAL lpMat)
{
    Direct3DMaterialLogMethodValue(TRACE, SetMaterial, 1, (lpMat));

    CONST HRESULT result = this->State.Self->SetMaterial(lpMat);

    Direct3DMaterialLogMethodResultValue(TRACEDEBUGINFO, SetMaterial, result, 1, (lpMat));
}

// Retrieves the material data for the Direct3DMaterial object.
HRESULT Direct3DMaterial::GetMaterial(LPD3DMATERIAL lpMat)
{
    Direct3DMaterialLogMethodValue(TRACE, GetMaterial, 1, (lpMat));

    CONST HRESULT result = this->State.Self->GetMaterial(lpMat);

    Direct3DMaterialLogMethodResultValue(TRACEDEBUGINFO, GetMaterial, result, 1, (lpMat));
}

// Binds a material to a device, retrieving a handle that represents the association between the two.
// This handle is used in all Direct3D methods in which a material is to be referenced.
// A material can be used by only one device at a time.
HRESULT Direct3DMaterial::GetHandle(LPDIRECT3DDEVICE lpDirect3DDevice, LPD3DMATERIALHANDLE lpHandle)
{
    Direct3DMaterialLogMethodValue(TRACE, GetHandle, 2, (lpDirect3DDevice, lpHandle));
    AttemptAccessAgentValue(Direct3DDevice, lpDirect3DDevice);

    CONST HRESULT result = this->State.Self->GetHandle(lpDirect3DDevice, lpHandle);

    Direct3DMaterialLogMethodResultValue(TRACEDEBUGINFO, GetHandle, result, 2, (ActivateAgent(Direct3DDevice, lpDirect3DDevice), lpHandle));
}

HRESULT Direct3DMaterial::Reserve()
{
    Direct3DMaterialLogMethod(DEBUG, Reserve);

    CONST HRESULT result = this->State.Self->Reserve();

    Direct3DMaterialLogMethodResult(DEBUGINFO, Reserve, result);
}

HRESULT Direct3DMaterial::Unreserve()
{
    Direct3DMaterialLogMethod(DEBUG, Unreserve);

    CONST HRESULT result = this->State.Self->Unreserve();

    Direct3DMaterialLogMethodResult(DEBUGINFO, Unreserve, result);
}