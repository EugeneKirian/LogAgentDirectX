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

#include "DirectSoundCaptureFXAec.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundCaptureFXAecLogger.hxx>

#define DirectSoundCaptureFXAecLogMethod(L, M) AgentLogMethod(L, DirectSoundCaptureFXAec, M)
#define DirectSoundCaptureFXAecLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSoundCaptureFXAec, M, C, PARAMS)

#define DirectSoundCaptureFXAecLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSoundCaptureFXAec, AddRef, R)
#define DirectSoundCaptureFXAecLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSoundCaptureFXAec, Release, R)

#define DirectSoundCaptureFXAecLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSoundCaptureFXAec, M, R)
#define DirectSoundCaptureFXAecLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSoundCaptureFXAec, M, R, C, PARAMS)

DirectSoundCaptureFXAec::DirectSoundCaptureFXAec(AgentConstructorParameters(DirectSoundCaptureFXAec))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectSoundCaptureFXAec);
}

DirectSoundCaptureFXAec::~DirectSoundCaptureFXAec()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectSoundCaptureFXAec);
}

HRESULT DirectSoundCaptureFXAec::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundCaptureFXAecLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSoundCaptureFXAec, riid)) { *ppvObj = ActivateAgent(DirectSoundCaptureFXAec, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSoundCaptureFXAecLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSoundCaptureFXAec::AddRef()
{
    DirectSoundCaptureFXAecLogMethod(DEBUG, AddRef);
    DirectSoundCaptureFXAecLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectSoundCaptureFXAec::Release()
{
    DirectSoundCaptureFXAecLogMethod(DEBUG, Release);
    DirectSoundCaptureFXAecLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Sets the acoustic echo cancellation parameters of a buffer.
// This method requires Microsoft Windows XP Home Edition or Windows XP Professional.
HRESULT DirectSoundCaptureFXAec::SetAllParameters(LPCDSCFXAec pDscFxAec)
{
    DirectSoundCaptureFXAecLogMethodValue(TRACE, SetAllParameters, 1, (pDscFxAec));

    CONST HRESULT result = this->State.Self->SetAllParameters(pDscFxAec);

    DirectSoundCaptureFXAecLogMethodResultValue(TRACEDEBUGINFO, SetAllParameters, result, 1, (pDscFxAec));
}

// Retrieves the acoustic echo cancellation parameters of a buffer.
// This method requires Microsoft Windows XP Home Edition or Windows XP Professional.
HRESULT DirectSoundCaptureFXAec::GetAllParameters(LPDSCFXAec pDscFxAec)
{
    DirectSoundCaptureFXAecLogMethodValue(TRACE, GetAllParameters, 1, (pDscFxAec));

    CONST HRESULT result = this->State.Self->GetAllParameters(pDscFxAec);

    DirectSoundCaptureFXAecLogMethodResultValue(TRACEDEBUGINFO, GetAllParameters, result, 1, (pDscFxAec));
}

// Retrieves the status of the effect.
HRESULT DirectSoundCaptureFXAec::GetStatus(LPDWORD pdwStatus)
{
    DirectSoundCaptureFXAecLogMethodValue(TRACE, GetStatus, 1, (pdwStatus));

    CONST HRESULT result = this->State.Self->GetStatus(pdwStatus);

    DirectSoundCaptureFXAecLogMethodResultValue(TRACEDEBUGINFO, GetStatus, result, 1, (pdwStatus));
}

// Resets the effect to its initial state.
HRESULT DirectSoundCaptureFXAec::Reset()
{
    DirectSoundCaptureFXAecLogMethod(DEBUG, Reset);

    CONST HRESULT result = this->State.Self->Reset();

    DirectSoundCaptureFXAecLogMethodResult(DEBUGINFO, Reset, result);
}