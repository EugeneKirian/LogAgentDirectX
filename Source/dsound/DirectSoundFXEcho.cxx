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

#include "DirectSoundFXEcho.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundFXEchoLogger.hxx>

#define DirectSoundFXEchoLogMethod(L, M) AgentLogMethod(L, DirectSoundFXEcho, M)
#define DirectSoundFXEchoLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSoundFXEcho, M, C, PARAMS)

#define DirectSoundFXEchoLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSoundFXEcho, AddRef, R)
#define DirectSoundFXEchoLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSoundFXEcho, Release, R)

#define DirectSoundFXEchoLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSoundFXEcho, M, R)
#define DirectSoundFXEchoLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSoundFXEcho, M, R, C, PARAMS)

DirectSoundFXEcho::DirectSoundFXEcho(AgentConstructorParameters(DirectSoundFXEcho))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectSoundFXEcho);
}

DirectSoundFXEcho::~DirectSoundFXEcho()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectSoundFXEcho);
}

HRESULT DirectSoundFXEcho::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundFXEchoLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSoundFXEcho, riid)) { *ppvObj = ActivateAgent(DirectSoundFXEcho, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSoundFXEchoLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSoundFXEcho::AddRef()
{
    DirectSoundFXEchoLogMethod(TRACE, AddRef);
    DirectSoundFXEchoLogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG DirectSoundFXEcho::Release()
{
    DirectSoundFXEchoLogMethod(TRACE, Release);
    DirectSoundFXEchoLogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Sets the echo parameters of a buffer.
HRESULT DirectSoundFXEcho::SetAllParameters(LPCDSFXEcho pcDsFxEcho)
{
    DirectSoundFXEchoLogMethodValue(TRACE, SetAllParameters, 1, (pcDsFxEcho));

    CONST HRESULT result = this->State.Self->SetAllParameters(pcDsFxEcho);

    DirectSoundFXEchoLogMethodResultValue(TRACEDEBUGINFO, SetAllParameters, result, 1, (pcDsFxEcho));
}

// Retrieves the echo parameters of a buffer.
HRESULT DirectSoundFXEcho::GetAllParameters(LPDSFXEcho pDsFxEcho)
{
    DirectSoundFXEchoLogMethodValue(TRACE, GetAllParameters, 1, (pDsFxEcho));

    CONST HRESULT result = this->State.Self->GetAllParameters(pDsFxEcho);

    DirectSoundFXEchoLogMethodResultValue(TRACEDEBUGINFO, GetAllParameters, result, 1, (pDsFxEcho));
}