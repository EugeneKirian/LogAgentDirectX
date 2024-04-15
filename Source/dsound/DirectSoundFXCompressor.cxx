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

#include "DirectSoundFXCompressor.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundFXCompressorLogger.hxx>

#define DirectSoundFXCompressorLogMethod(L, M) AgentLogMethod(L, DirectSoundFXCompressor, M)
#define DirectSoundFXCompressorLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSoundFXCompressor, M, C, PARAMS)

#define DirectSoundFXCompressorLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSoundFXCompressor, AddRef, R)
#define DirectSoundFXCompressorLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSoundFXCompressor, Release, R)

#define DirectSoundFXCompressorLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSoundFXCompressor, M, R)
#define DirectSoundFXCompressorLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSoundFXCompressor, M, R, C, PARAMS)

DirectSoundFXCompressor::DirectSoundFXCompressor(AgentConstructorParameters(DirectSoundFXCompressor))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectSoundFXCompressor);
}

DirectSoundFXCompressor::~DirectSoundFXCompressor()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectSoundFXCompressor);
}

HRESULT DirectSoundFXCompressor::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundFXCompressorLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSoundFXCompressor, riid)) { *ppvObj = ActivateAgent(DirectSoundFXCompressor, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSoundFXCompressorLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSoundFXCompressor::AddRef()
{
    DirectSoundFXCompressorLogMethod(TRACE, AddRef);
    DirectSoundFXCompressorLogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG DirectSoundFXCompressor::Release()
{
    DirectSoundFXCompressorLogMethod(TRACE, Release);
    DirectSoundFXCompressorLogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Sets the compression parameters of a buffer.
HRESULT DirectSoundFXCompressor::SetAllParameters(LPCDSFXCompressor pcDsFxCompressor)
{
    DirectSoundFXCompressorLogMethodValue(TRACE, SetAllParameters, 1, (pcDsFxCompressor));

    CONST HRESULT result = this->State.Self->SetAllParameters(pcDsFxCompressor);

    DirectSoundFXCompressorLogMethodResultValue(TRACEDEBUGINFO, SetAllParameters, result, 1, (pcDsFxCompressor));
}

// Retrieves the compression parameters of a buffer.
HRESULT DirectSoundFXCompressor::GetAllParameters(LPDSFXCompressor pDsFxCompressor)
{
    DirectSoundFXCompressorLogMethodValue(TRACE, GetAllParameters, 1, (pDsFxCompressor));

    CONST HRESULT result = this->State.Self->GetAllParameters(pDsFxCompressor);

    DirectSoundFXCompressorLogMethodResultValue(TRACEDEBUGINFO, GetAllParameters, result, 1, (pDsFxCompressor));
}