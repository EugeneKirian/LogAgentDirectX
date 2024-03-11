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

#include "DirectSoundFXDistortion.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundFXDistortionLogger.hxx>

#define DirectSoundFXDistortionLogMethod(L, M) AgentLogMethod(L, DirectSoundFXDistortion, M)
#define DirectSoundFXDistortionLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSoundFXDistortion, M, C, PARAMS)

#define DirectSoundFXDistortionLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSoundFXDistortion, AddRef, R)
#define DirectSoundFXDistortionLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSoundFXDistortion, Release, R)

#define DirectSoundFXDistortionLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSoundFXDistortion, M, R)
#define DirectSoundFXDistortionLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSoundFXDistortion, M, R, C, PARAMS)

DirectSoundFXDistortion::DirectSoundFXDistortion(AgentConstructorParameters(DirectSoundFXDistortion))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectSoundFXDistortion);
}

DirectSoundFXDistortion::~DirectSoundFXDistortion()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectSoundFXDistortion);
}

HRESULT DirectSoundFXDistortion::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundFXDistortionLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSoundFXDistortion, riid)) { *ppvObj = ActivateAgent(DirectSoundFXDistortion, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSoundFXDistortionLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSoundFXDistortion::AddRef()
{
    DirectSoundFXDistortionLogMethod(DEBUG, AddRef);
    DirectSoundFXDistortionLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectSoundFXDistortion::Release()
{
    DirectSoundFXDistortionLogMethod(DEBUG, Release);
    DirectSoundFXDistortionLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Sets the distortion parameters of a buffer.
HRESULT DirectSoundFXDistortion::SetAllParameters(LPCDSFXDistortion pcDsFxDistortion)
{
    DirectSoundFXDistortionLogMethodValue(TRACE, SetAllParameters, 1, (pcDsFxDistortion));

    CONST HRESULT result = this->State.Self->SetAllParameters(pcDsFxDistortion);

    DirectSoundFXDistortionLogMethodResultValue(TRACEDEBUGINFO, SetAllParameters, result, 1, (pcDsFxDistortion));
}

// Retrieves the distortion parameters of a buffer.
HRESULT DirectSoundFXDistortion::GetAllParameters(LPDSFXDistortion pDsFxDistortion)
{
    DirectSoundFXDistortionLogMethodValue(TRACE, GetAllParameters, 1, (pDsFxDistortion));

    CONST HRESULT result = this->State.Self->GetAllParameters(pDsFxDistortion);

    DirectSoundFXDistortionLogMethodResultValue(TRACEDEBUGINFO, GetAllParameters, result, 1, (pDsFxDistortion));
}