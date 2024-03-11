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

#include "DirectSoundCaptureFXNoiseSuppress.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundCaptureFXNoiseSuppressLogger.hxx>

#define DirectSoundCaptureFXNoiseSuppressLogMethod(L, M) AgentLogMethod(L, DirectSoundCaptureFXNoiseSuppress, M)
#define DirectSoundCaptureFXNoiseSuppressLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSoundCaptureFXNoiseSuppress, M, C, PARAMS)

#define DirectSoundCaptureFXNoiseSuppressLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSoundCaptureFXNoiseSuppress, AddRef, R)
#define DirectSoundCaptureFXNoiseSuppressLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSoundCaptureFXNoiseSuppress, Release, R)

#define DirectSoundCaptureFXNoiseSuppressLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSoundCaptureFXNoiseSuppress, M, R)
#define DirectSoundCaptureFXNoiseSuppressLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSoundCaptureFXNoiseSuppress, M, R, C, PARAMS)

DirectSoundCaptureFXNoiseSuppress::DirectSoundCaptureFXNoiseSuppress(AgentConstructorParameters(DirectSoundCaptureFXNoiseSuppress))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectSoundCaptureFXNoiseSuppress);
}

DirectSoundCaptureFXNoiseSuppress::~DirectSoundCaptureFXNoiseSuppress()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectSoundCaptureFXNoiseSuppress);
}

HRESULT DirectSoundCaptureFXNoiseSuppress::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundCaptureFXNoiseSuppressLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSoundCaptureFXNoiseSuppress, riid)) { *ppvObj = ActivateAgent(DirectSoundCaptureFXNoiseSuppress, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSoundCaptureFXNoiseSuppressLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSoundCaptureFXNoiseSuppress::AddRef()
{
    DirectSoundCaptureFXNoiseSuppressLogMethod(DEBUG, AddRef);
    DirectSoundCaptureFXNoiseSuppressLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectSoundCaptureFXNoiseSuppress::Release()
{
    DirectSoundCaptureFXNoiseSuppressLogMethod(DEBUG, Release);
    DirectSoundCaptureFXNoiseSuppressLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Sets the acoustic echo cancellation parameters of a buffer.
// This method requires Microsoft Windows XP Home Edition or Windows XP Professional.
HRESULT DirectSoundCaptureFXNoiseSuppress::SetAllParameters(LPCDSCFXNoiseSuppress pcDscFxNoiseSuppress)
{
    DirectSoundCaptureFXNoiseSuppressLogMethodValue(TRACE, SetAllParameters, 1, (pcDscFxNoiseSuppress));

    CONST HRESULT result = this->State.Self->SetAllParameters(pcDscFxNoiseSuppress);

    DirectSoundCaptureFXNoiseSuppressLogMethodResultValue(TRACEDEBUGINFO, SetAllParameters, result, 1, (pcDscFxNoiseSuppress));
}

// Retrieves the acoustic echo cancellation parameters of a buffer.
// This method requires Microsoft Windows XP Home Edition or Windows XP Professional.
HRESULT DirectSoundCaptureFXNoiseSuppress::GetAllParameters(LPDSCFXNoiseSuppress pDscFxNoiseSuppress)
{
    DirectSoundCaptureFXNoiseSuppressLogMethodValue(TRACE, GetAllParameters, 1, (pDscFxNoiseSuppress));

    CONST HRESULT result = this->State.Self->GetAllParameters(pDscFxNoiseSuppress);

    DirectSoundCaptureFXNoiseSuppressLogMethodResultValue(TRACEDEBUGINFO, GetAllParameters, result, 1, (pDscFxNoiseSuppress));
}

// Resets the effect to its initial state.
HRESULT DirectSoundCaptureFXNoiseSuppress::Reset()
{
    DirectSoundCaptureFXNoiseSuppressLogMethod(DEBUG, Reset);

    CONST HRESULT result = this->State.Self->Reset();

    DirectSoundCaptureFXNoiseSuppressLogMethodResult(DEBUGINFO, Reset, result);
}