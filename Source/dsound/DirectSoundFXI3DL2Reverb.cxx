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

#include "DirectSoundFXI3DL2Reverb.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundFXI3DL2ReverbLogger.hxx>

#define DirectSoundFXI3DL2ReverbLogMethod(L, M) AgentLogMethod(L, DirectSoundFXI3DL2Reverb, M)
#define DirectSoundFXI3DL2ReverbLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSoundFXI3DL2Reverb, M, C, PARAMS)

#define DirectSoundFXI3DL2ReverbLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSoundFXI3DL2Reverb, AddRef, R)
#define DirectSoundFXI3DL2ReverbLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSoundFXI3DL2Reverb, Release, R)

#define DirectSoundFXI3DL2ReverbLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSoundFXI3DL2Reverb, M, R)
#define DirectSoundFXI3DL2ReverbLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSoundFXI3DL2Reverb, M, R, C, PARAMS)

DirectSoundFXI3DL2Reverb::DirectSoundFXI3DL2Reverb(AgentConstructorParameters(DirectSoundFXI3DL2Reverb))
{
    AgentConstructor();
    AgentLogConstructor(DEBUG, DirectSoundFXI3DL2Reverb);
}

DirectSoundFXI3DL2Reverb::~DirectSoundFXI3DL2Reverb()
{
    AgentDestructor();
    AgentLogDestructor(DEBUG, DirectSoundFXI3DL2Reverb);
}

HRESULT DirectSoundFXI3DL2Reverb::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundFXI3DL2ReverbLogMethodValue(DEBUG, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSoundFXI3DL2Reverb, riid)) { *ppvObj = ActivateAgent(DirectSoundFXI3DL2Reverb, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSoundFXI3DL2ReverbLogMethodResultValue(DEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSoundFXI3DL2Reverb::AddRef()
{
    DirectSoundFXI3DL2ReverbLogMethod(DEBUG, AddRef);
    DirectSoundFXI3DL2ReverbLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectSoundFXI3DL2Reverb::Release()
{
    DirectSoundFXI3DL2ReverbLogMethod(DEBUG, Release);
    DirectSoundFXI3DL2ReverbLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Sets the I3DL2 environmental reverberation parameters of a buffer.
HRESULT DirectSoundFXI3DL2Reverb::SetAllParameters(LPCDSFXI3DL2Reverb pcDsFxI3DL2Reverb)
{
    DirectSoundFXI3DL2ReverbLogMethodValue(DEBUG, SetAllParameters, 1, (pcDsFxI3DL2Reverb));

    CONST HRESULT result = this->State.Self->SetAllParameters(pcDsFxI3DL2Reverb);

    DirectSoundFXI3DL2ReverbLogMethodResultValue(DEBUGINFO, SetAllParameters, result, 1, (pcDsFxI3DL2Reverb));
}

// Retrieves the I3DL2 environmental reverberation parameters of a buffer.
HRESULT DirectSoundFXI3DL2Reverb::GetAllParameters(LPDSFXI3DL2Reverb pDsFxI3DL2Reverb)
{
    DirectSoundFXI3DL2ReverbLogMethodValue(DEBUG, GetAllParameters, 1, (pDsFxI3DL2Reverb));

    CONST HRESULT result = this->State.Self->GetAllParameters(pDsFxI3DL2Reverb);

    DirectSoundFXI3DL2ReverbLogMethodResultValue(DEBUGINFO, GetAllParameters, result, 1, (pDsFxI3DL2Reverb));
}

// Sets standard reverberation parameters of a buffer.
HRESULT DirectSoundFXI3DL2Reverb::SetPreset(DWORD dwPreset)
{
    DirectSoundFXI3DL2ReverbLogMethodValue(DEBUG, SetPreset, 1, (dwPreset));

    CONST HRESULT result = this->State.Self->SetPreset(dwPreset);

    DirectSoundFXI3DL2ReverbLogMethodResultValue(DEBUGINFO, SetPreset, result, 1, (dwPreset));
}

// Retrieves an identifier for standard reverberation parameters of a buffer.
HRESULT DirectSoundFXI3DL2Reverb::GetPreset(LPDWORD pdwPreset)
{
    DirectSoundFXI3DL2ReverbLogMethodValue(DEBUG, GetPreset, 1, (pdwPreset));

    CONST HRESULT result = this->State.Self->GetPreset(pdwPreset);

    DirectSoundFXI3DL2ReverbLogMethodResultValue(DEBUGINFO, GetPreset, result, 1, (pdwPreset));
}

// Sets the quality of the environmental reverberation effect.
// Higher values produce better quality at the expense of processing time. 
HRESULT DirectSoundFXI3DL2Reverb::SetQuality(LONG lQuality)
{
    DirectSoundFXI3DL2ReverbLogMethodValue(DEBUG, SetQuality, 1, (lQuality));

    CONST HRESULT result = this->State.Self->SetQuality(lQuality);

    DirectSoundFXI3DL2ReverbLogMethodResultValue(DEBUGINFO, SetQuality, result, 1, (lQuality));
}

// Retrieves the quality of the environmental reverberation effect.
HRESULT DirectSoundFXI3DL2Reverb::GetQuality(LPLONG plQuality)
{
    DirectSoundFXI3DL2ReverbLogMethodValue(DEBUG, GetQuality, 1, (plQuality));

    CONST HRESULT result = this->State.Self->GetQuality(plQuality);

    DirectSoundFXI3DL2ReverbLogMethodResultValue(DEBUGINFO, GetQuality, result, 1, (plQuality));
}