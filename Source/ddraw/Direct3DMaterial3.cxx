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
#include "Direct3DDevice3.hxx"
#include "Direct3DMaterial.hxx"
#include "Direct3DMaterial2.hxx"
#include "Direct3DMaterial3.hxx"

#include <AgentLogger.hxx>
#include <Direct3DMaterial3Logger.hxx>

#define Direct3DMaterial3LogMethod(L, M) AgentLogMethod(L, Direct3DMaterial3, M)
#define Direct3DMaterial3LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DMaterial3, M, C, PARAMS)

#define Direct3DMaterial3LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DMaterial3, AddRef, R)
#define Direct3DMaterial3LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DMaterial3, Release, R)

#define Direct3DMaterial3LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DMaterial3, M, R)
#define Direct3DMaterial3LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DMaterial3, M, R, C, PARAMS)

Direct3DMaterial3::Direct3DMaterial3(AgentConstructorParameters(Direct3DMaterial3))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DMaterial3);
}

Direct3DMaterial3::~Direct3DMaterial3()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DMaterial3);
}

HRESULT Direct3DMaterial3::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DMaterial3LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

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

    Direct3DMaterial3LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DMaterial3::AddRef()
{
    Direct3DMaterial3LogMethod(DEBUG, AddRef);
    Direct3DMaterial3LogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG Direct3DMaterial3::Release()
{
    Direct3DMaterial3LogMethod(DEBUG, Release);
    Direct3DMaterial3LogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Sets the material data for a material object.
HRESULT Direct3DMaterial3::SetMaterial(LPD3DMATERIAL lpMat)
{
    Direct3DMaterial3LogMethodValue(TRACE, SetMaterial, 1, (lpMat));

    CONST HRESULT result = this->State.Self->SetMaterial(lpMat);

    Direct3DMaterial3LogMethodResultValue(TRACEDEBUGINFO, SetMaterial, result, 1, (lpMat));
}

// Retrieves the material data for the Direct3DMaterial object.
HRESULT Direct3DMaterial3::GetMaterial(LPD3DMATERIAL lpMat)
{
    Direct3DMaterial3LogMethodValue(TRACE, GetMaterial, 1, (lpMat));

    CONST HRESULT result = this->State.Self->GetMaterial(lpMat);

    Direct3DMaterial3LogMethodResultValue(TRACEDEBUGINFO, GetMaterial, result, 1, (lpMat));
}

// Binds a material to a device, retrieving a handle that represents the association between the two.
// This handle is used in all Direct3D methods in which a material is to be referenced.
// A material can be used by only one device at a time.
HRESULT Direct3DMaterial3::GetHandle(LPDIRECT3DDEVICE3 lpDirect3DDevice, LPD3DMATERIALHANDLE lpHandle)
{
    Direct3DMaterial3LogMethodValue(TRACE, GetHandle, 2, (lpDirect3DDevice, lpHandle));
    AttemptAccessAgentValue(Direct3DDevice3, lpDirect3DDevice);

    CONST HRESULT result = this->State.Self->GetHandle(lpDirect3DDevice, lpHandle);

    Direct3DMaterial3LogMethodResultValue(TRACEDEBUGINFO, GetHandle, result, 2, (ActivateAgent(Direct3DDevice3, lpDirect3DDevice), lpHandle));
}