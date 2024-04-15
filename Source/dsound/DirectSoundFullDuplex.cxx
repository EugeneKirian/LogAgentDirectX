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

#include "DirectSound.hxx"
#include "DirectSound8.hxx"
#include "DirectSoundBuffer8.hxx"
#include "DirectSoundCapture.hxx"
#include "DirectSoundCaptureBuffer8.hxx"
#include "DirectSoundFullDuplex.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundFullDuplexLogger.hxx>

#define DirectSoundFullDuplexLogMethod(L, M) AgentLogMethod(L, DirectSoundFullDuplex, M)
#define DirectSoundFullDuplexLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSoundFullDuplex, M, C, PARAMS)

#define DirectSoundFullDuplexLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSoundFullDuplex, AddRef, R)
#define DirectSoundFullDuplexLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSoundFullDuplex, Release, R)

#define DirectSoundFullDuplexLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSoundFullDuplex, M, R)
#define DirectSoundFullDuplexLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSoundFullDuplex, M, R, C, PARAMS)

DirectSoundFullDuplex::DirectSoundFullDuplex(AgentConstructorParameters(DirectSoundFullDuplex))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectSoundFullDuplex);
}

DirectSoundFullDuplex::~DirectSoundFullDuplex()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectSoundFullDuplex);
}

HRESULT DirectSoundFullDuplex::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundFullDuplexLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSound8, riid) || IsEqualIID(IID_IDirectSound, riid)) { *ppvObj = ActivateAgent(DirectSound8, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundCapture, riid)) { *ppvObj = ActivateAgent(DirectSoundCapture, *ppvObj); }
            else if (IsEqualIID(IID_IDirectSoundFullDuplex, riid)) { *ppvObj = ActivateAgent(DirectSoundFullDuplex, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSoundFullDuplexLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSoundFullDuplex::AddRef()
{
    DirectSoundFullDuplexLogMethod(TRACE, AddRef);
    DirectSoundFullDuplexLogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG DirectSoundFullDuplex::Release()
{
    DirectSoundFullDuplexLogMethod(TRACE, Release);
    DirectSoundFullDuplexLogReleaseMethodResult(TRACE, this->State.Self->Release());
}

HRESULT DirectSoundFullDuplex::Initialize(LPCGUID pCaptureGuid, LPCGUID pRenderGuid, LPCDSCBUFFERDESC lpDscBufferDesc, LPCDSBUFFERDESC lpDsBufferDesc, HWND hWnd, DWORD dwLevel, LPLPDIRECTSOUNDCAPTUREBUFFER8 lplpDirectSoundFullDuplexCaptureBuffer8, LPLPDIRECTSOUNDBUFFER8 lplpDirectSoundFullDuplexBuffer8)
{
    DirectSoundFullDuplexLogMethodValue(TRACE, Initialize, 8, (pCaptureGuid, pRenderGuid, lpDscBufferDesc, lpDsBufferDesc, hWnd, dwLevel, lplpDirectSoundFullDuplexCaptureBuffer8, lplpDirectSoundFullDuplexBuffer8));

    CONST HRESULT result = this->State.Self->Initialize(pCaptureGuid, pRenderGuid, lpDscBufferDesc, lpDsBufferDesc, hWnd, dwLevel, lplpDirectSoundFullDuplexCaptureBuffer8, lplpDirectSoundFullDuplexBuffer8);

    if (SUCCEEDED(result))
    {
        *lplpDirectSoundFullDuplexCaptureBuffer8 = ActivateAgentDelegate(DirectSoundCaptureBuffer8, *lplpDirectSoundFullDuplexCaptureBuffer8);
        *lplpDirectSoundFullDuplexBuffer8 = ActivateAgentDelegate(DirectSoundBuffer8, *lplpDirectSoundFullDuplexBuffer8);
    }

    DirectSoundFullDuplexLogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 8, (pCaptureGuid, pRenderGuid, lpDscBufferDesc, lpDsBufferDesc, hWnd, dwLevel, lplpDirectSoundFullDuplexCaptureBuffer8, lplpDirectSoundFullDuplexBuffer8));
}