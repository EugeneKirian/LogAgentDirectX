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

#include "DirectSoundCapture.hxx"
#include "DirectSoundCaptureBuffer8.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <DirectSoundCaptureLogger.hxx>

#define DirectSoundCaptureLogMethod(L, M) AgentLogMethod(L, DirectSoundCapture, M)
#define DirectSoundCaptureLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectSoundCapture, M, C, PARAMS)

#define DirectSoundCaptureLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectSoundCapture, AddRef, R)
#define DirectSoundCaptureLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectSoundCapture, Release, R)

#define DirectSoundCaptureLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectSoundCapture, M, R)
#define DirectSoundCaptureLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectSoundCapture, M, R, C, PARAMS)

DirectSoundCapture::DirectSoundCapture(AgentConstructorParameters(DirectSoundCapture))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, DirectSoundCapture);
}

DirectSoundCapture::~DirectSoundCapture()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, DirectSoundCapture);
}

HRESULT DirectSoundCapture::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectSoundCaptureLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirectSoundCapture, riid)) { *ppvObj = ActivateAgent(DirectSoundCapture, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectSoundCaptureLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectSoundCapture::AddRef()
{
    DirectSoundCaptureLogMethod(TRACE, AddRef);
    DirectSoundCaptureLogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG DirectSoundCapture::Release()
{
    DirectSoundCaptureLogMethod(TRACE, Release);
    DirectSoundCaptureLogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Creates a capture buffer.
HRESULT DirectSoundCapture::CreateCaptureBuffer(LPCDSCBUFFERDESC pcDSCBufferDesc, LPDIRECTSOUNDCAPTUREBUFFER* ppDSCBuffer, LPUNKNOWN pUnkOuter)
{
    DirectSoundCaptureLogMethodValue(TRACE, CreateCaptureBuffer, 3, (pcDSCBufferDesc, ppDSCBuffer, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateCaptureBuffer(pcDSCBufferDesc, ppDSCBuffer, pUnkOuter);

    if (SUCCEEDED(result)) { *ppDSCBuffer = ActivateAgentDelegate(DirectSoundCaptureBuffer8, *ppDSCBuffer); }

    DirectSoundCaptureLogMethodResultValue(TRACEDEBUGINFO, CreateCaptureBuffer, result, 3, (pcDSCBufferDesc, ppDSCBuffer, pUnkOuter));
}

// Retrieves the capabilities of the capture device.
HRESULT DirectSoundCapture::GetCaps(LPDSCCAPS pDSCCaps)
{
    DirectSoundCaptureLogMethodValue(TRACE, GetCaps, 1, (pDSCCaps));

    CONST HRESULT result = this->State.Self->GetCaps(pDSCCaps);

    DirectSoundCaptureLogMethodResultValue(TRACEDEBUGINFO, GetCaps, result, 1, (pDSCCaps));
}

// Initializes a DirectSoundCapture object created by using CoCreateInstance.
// Calling this method is not required when the DirectSoundCaptureCreate8 or DirectSoundFullDuplexCreate8 function is used to create the object. 
HRESULT DirectSoundCapture::Initialize(LPCGUID pcGuidDevice)
{
    DirectSoundCaptureLogMethodValue(TRACE, Initialize, 1, (pcGuidDevice));

    CONST HRESULT result = this->State.Self->Initialize(pcGuidDevice);

    DirectSoundCaptureLogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 1, (pcGuidDevice));
}