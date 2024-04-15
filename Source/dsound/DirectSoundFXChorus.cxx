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

#include "DirectSoundFXChorus.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundFXChorusLogger.hxx>

#define DirectSoundFXChorusLogMethod(L, M) AgentLogMethod(L, DirectSoundFXChorus, M)
#define DirectSoundFXChorusLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSoundFXChorus, M, C, PARAMS)

#define DirectSoundFXChorusLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSoundFXChorus, AddRef, R)
#define DirectSoundFXChorusLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSoundFXChorus, Release, R)

#define DirectSoundFXChorusLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSoundFXChorus, M, R)
#define DirectSoundFXChorusLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSoundFXChorus, M, R, C, PARAMS)

DirectSoundFXChorus::DirectSoundFXChorus(AgentConstructorParameters(DirectSoundFXChorus))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectSoundFXChorus);
}

DirectSoundFXChorus::~DirectSoundFXChorus()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectSoundFXChorus);
}

HRESULT DirectSoundFXChorus::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundFXChorusLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSoundFXChorus, riid)) { *ppvObj = ActivateAgent(DirectSoundFXChorus, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSoundFXChorusLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSoundFXChorus::AddRef()
{
    DirectSoundFXChorusLogMethod(TRACE, AddRef);
    DirectSoundFXChorusLogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG DirectSoundFXChorus::Release()
{
    DirectSoundFXChorusLogMethod(TRACE, Release);
    DirectSoundFXChorusLogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Sets the chorus parameters of a buffer.
HRESULT DirectSoundFXChorus::SetAllParameters(LPCDSFXChorus pcDsFxChorus)
{
    DirectSoundFXChorusLogMethodValue(TRACE, SetAllParameters, 1, (pcDsFxChorus));

    CONST HRESULT result = this->State.Self->SetAllParameters(pcDsFxChorus);

    DirectSoundFXChorusLogMethodResultValue(TRACEDEBUGINFO, SetAllParameters, result, 1, (pcDsFxChorus));
}

// Retrieves the chorus parameters of a buffer.
HRESULT DirectSoundFXChorus::GetAllParameters(LPDSFXChorus pDsFxChorus)
{
    DirectSoundFXChorusLogMethodValue(TRACE, GetAllParameters, 1, (pDsFxChorus));

    CONST HRESULT result = this->State.Self->GetAllParameters(pDsFxChorus);

    DirectSoundFXChorusLogMethodResultValue(TRACEDEBUGINFO, GetAllParameters, result, 1, (pDsFxChorus));
}