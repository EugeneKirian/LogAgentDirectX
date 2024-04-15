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

#include "DirectSoundFXWavesReverb.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundFXWavesReverbLogger.hxx>

#define DirectSoundFXWavesReverbLogMethod(L, M) AgentLogMethod(L, DirectSoundFXWavesReverb, M)
#define DirectSoundFXWavesReverbLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSoundFXWavesReverb, M, C, PARAMS)

#define DirectSoundFXWavesReverbLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSoundFXWavesReverb, AddRef, R)
#define DirectSoundFXWavesReverbLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSoundFXWavesReverb, Release, R)

#define DirectSoundFXWavesReverbLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSoundFXWavesReverb, M, R)
#define DirectSoundFXWavesReverbLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSoundFXWavesReverb, M, R, C, PARAMS)

DirectSoundFXWavesReverb::DirectSoundFXWavesReverb(AgentConstructorParameters(DirectSoundFXWavesReverb))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectSoundFXWavesReverb);
}

DirectSoundFXWavesReverb::~DirectSoundFXWavesReverb()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectSoundFXWavesReverb);
}

HRESULT DirectSoundFXWavesReverb::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundFXWavesReverbLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSoundFXWavesReverb, riid)) { *ppvObj = ActivateAgent(DirectSoundFXWavesReverb, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSoundFXWavesReverbLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSoundFXWavesReverb::AddRef()
{
    DirectSoundFXWavesReverbLogMethod(TRACE, AddRef);
    DirectSoundFXWavesReverbLogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG DirectSoundFXWavesReverb::Release()
{
    DirectSoundFXWavesReverbLogMethod(TRACE, Release);
    DirectSoundFXWavesReverbLogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Sets the music reverberation parameters of a buffer.
HRESULT DirectSoundFXWavesReverb::SetAllParameters(LPCDSFXWavesReverb pcDsFXWavesReverb)
{
    DirectSoundFXWavesReverbLogMethodValue(TRACE, SetAllParameters, 1, (pcDsFXWavesReverb));

    CONST HRESULT result = this->State.Self->SetAllParameters(pcDsFXWavesReverb);

    DirectSoundFXWavesReverbLogMethodResultValue(TRACEDEBUGINFO, SetAllParameters, result, 1, (pcDsFXWavesReverb));
}

// Retrieves the music reverberation parameters of a buffer.
HRESULT DirectSoundFXWavesReverb::GetAllParameters(LPDSFXWavesReverb pDsFXWavesReverb)
{
    DirectSoundFXWavesReverbLogMethodValue(TRACE, GetAllParameters, 1, (pDsFXWavesReverb));

    CONST HRESULT result = this->State.Self->GetAllParameters(pDsFXWavesReverb);

    DirectSoundFXWavesReverbLogMethodResultValue(TRACEDEBUGINFO, GetAllParameters, result, 1, (pDsFXWavesReverb));
}