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

#include "DirectSoundFXParamEq.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundFXParamEqLogger.hxx>

#define DirectSoundFXParamEqLogMethod(L, M) AgentLogMethod(L, DirectSoundFXParamEq, M)
#define DirectSoundFXParamEqLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSoundFXParamEq, M, C, PARAMS)

#define DirectSoundFXParamEqLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSoundFXParamEq, AddRef, R)
#define DirectSoundFXParamEqLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSoundFXParamEq, Release, R)

#define DirectSoundFXParamEqLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSoundFXParamEq, M, R)
#define DirectSoundFXParamEqLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSoundFXParamEq, M, R, C, PARAMS)

DirectSoundFXParamEq::DirectSoundFXParamEq(AgentConstructorParameters(DirectSoundFXParamEq))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectSoundFXParamEq);
}

DirectSoundFXParamEq::~DirectSoundFXParamEq()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectSoundFXParamEq);
}

HRESULT DirectSoundFXParamEq::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundFXParamEqLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSoundFXParamEq, riid)) { *ppvObj = ActivateAgent(DirectSoundFXParamEq, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSoundFXParamEqLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSoundFXParamEq::AddRef()
{
    DirectSoundFXParamEqLogMethod(DEBUG, AddRef);
    DirectSoundFXParamEqLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectSoundFXParamEq::Release()
{
    DirectSoundFXParamEqLogMethod(DEBUG, Release);
    DirectSoundFXParamEqLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Sets the parametric equalizer parameters of a buffer.
HRESULT DirectSoundFXParamEq::SetAllParameters(LPCDSFXParamEq pcDsFxParamEq)
{
    DirectSoundFXParamEqLogMethodValue(TRACE, SetAllParameters, 1, (pcDsFxParamEq));

    CONST HRESULT result = this->State.Self->SetAllParameters(pcDsFxParamEq);

    DirectSoundFXParamEqLogMethodResultValue(TRACEDEBUGINFO, SetAllParameters, result, 1, (pcDsFxParamEq));
}

// Retrieves the parametric equalizer parameters of a buffer.
HRESULT DirectSoundFXParamEq::GetAllParameters(LPDSFXParamEq pDsFxParamEq)
{
    DirectSoundFXParamEqLogMethodValue(TRACE, GetAllParameters, 1, (pDsFxParamEq));

    CONST HRESULT result = this->State.Self->GetAllParameters(pDsFxParamEq);

    DirectSoundFXParamEqLogMethodResultValue(TRACEDEBUGINFO, GetAllParameters, result, 1, (pDsFxParamEq));
}