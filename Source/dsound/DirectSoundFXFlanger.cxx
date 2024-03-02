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

#include "DirectSoundFXFlanger.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundFXFlangerLogger.hxx>

#define DirectSoundFXFlangerLogMethod(L, M) AgentLogMethod(L, DirectSoundFXFlanger, M)
#define DirectSoundFXFlangerLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSoundFXFlanger, M, C, PARAMS)

#define DirectSoundFXFlangerLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSoundFXFlanger, AddRef, R)
#define DirectSoundFXFlangerLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSoundFXFlanger, Release, R)

#define DirectSoundFXFlangerLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSoundFXFlanger, M, R)
#define DirectSoundFXFlangerLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSoundFXFlanger, M, R, C, PARAMS)

DirectSoundFXFlanger::DirectSoundFXFlanger(AgentConstructorParameters(DirectSoundFXFlanger))
{
    AgentConstructor();
    AgentLogConstructor(DEBUG, DirectSoundFXFlanger);
}

DirectSoundFXFlanger::~DirectSoundFXFlanger()
{
    AgentDestructor();
    AgentLogDestructor(DEBUG, DirectSoundFXFlanger);
}

HRESULT DirectSoundFXFlanger::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundFXFlangerLogMethodValue(DEBUG, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSoundFXFlanger, riid)) { *ppvObj = ActivateAgent(DirectSoundFXFlanger, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSoundFXFlangerLogMethodResultValue(DEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSoundFXFlanger::AddRef()
{
    DirectSoundFXFlangerLogMethod(DEBUG, AddRef);
    DirectSoundFXFlangerLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectSoundFXFlanger::Release()
{
    DirectSoundFXFlangerLogMethod(DEBUG, Release);
    DirectSoundFXFlangerLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Sets the flange parameters of a buffer.
HRESULT DirectSoundFXFlanger::SetAllParameters(LPCDSFXFlanger pcDsFxFlanger)
{
    DirectSoundFXFlangerLogMethodValue(DEBUG, SetAllParameters, 1, (pcDsFxFlanger));

    CONST HRESULT result = this->State.Self->SetAllParameters(pcDsFxFlanger);

    DirectSoundFXFlangerLogMethodResultValue(DEBUGINFO, SetAllParameters, result, 1, (pcDsFxFlanger));
}

// Retrieves the flange parameters of a buffer.
HRESULT DirectSoundFXFlanger::GetAllParameters(LPDSFXFlanger pDsFxFlanger)
{
    DirectSoundFXFlangerLogMethodValue(DEBUG, GetAllParameters, 1, (pDsFxFlanger));

    CONST HRESULT result = this->State.Self->GetAllParameters(pDsFxFlanger);

    DirectSoundFXFlangerLogMethodResultValue(DEBUGINFO, GetAllParameters, result, 1, (pDsFxFlanger));
}