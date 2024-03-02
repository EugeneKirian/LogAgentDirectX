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

#include "Direct3DTexture.hxx"
#include "Direct3DTexture2.hxx"
#include "DirectDrawColorControl.hxx"
#include "DirectDrawGammaControl.hxx"
#include "DirectDrawSurface.hxx"
#include "DirectDrawSurface2.hxx"
#include "DirectDrawSurface3.hxx"
#include "DirectDrawSurface4.hxx"
#include "DirectDrawSurface7.hxx"

#include <AgentLogger.hxx>
#include <DirectDrawColorControlLogger.hxx>

#define DirectDrawColorControlLogMethod(L, M) AgentLogMethod(L, DirectDrawColorControl, M)
#define DirectDrawColorControlLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectDrawColorControl, M, C, PARAMS)

#define DirectDrawColorControlLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectDrawColorControl, AddRef, R)
#define DirectDrawColorControlLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectDrawColorControl, Release, R)

#define DirectDrawColorControlLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectDrawColorControl, M, R, C, PARAMS)

DirectDrawColorControl::DirectDrawColorControl(AgentConstructorParameters(DirectDrawColorControl))
{
    AgentConstructor();
    AgentLogConstructor(DEBUG, DirectDrawColorControl);
}

DirectDrawColorControl::~DirectDrawColorControl()
{
    AgentDestructor();
    AgentLogDestructor(DEBUG, DirectDrawColorControl);
}

HRESULT DirectDrawColorControl::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectDrawColorControlLogMethodValue(DEBUG, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DTexture, riid)) { *ppvObj = ActivateAgent(Direct3DTexture, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DTexture2, riid)) { *ppvObj = ActivateAgent(Direct3DTexture2, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawColorControl, riid)) { *ppvObj = ActivateAgent(DirectDrawColorControl, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawGammaControl, riid)) { *ppvObj = ActivateAgent(DirectDrawGammaControl, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface2, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface2, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface3, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface3, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface4, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface4, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface7, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface7, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectDrawColorControlLogMethodResultValue(DEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectDrawColorControl::AddRef()
{
    DirectDrawColorControlLogMethod(DEBUG, AddRef);
    DirectDrawColorControlLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectDrawColorControl::Release()
{
    DirectDrawColorControlLogMethod(DEBUG, Release);
    DirectDrawColorControlLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Retrieves the current color-control settings that are associated with an overlay or a primary surface.
HRESULT DirectDrawColorControl::GetColorControls(LPDDCOLORCONTROL lpColorControl)
{
    DirectDrawColorControlLogMethodValue(DEBUG, GetColorControls, 1, (lpColorControl));

    CONST HRESULT result = this->State.Self->GetColorControls(lpColorControl);

    DirectDrawColorControlLogMethodResultValue(DEBUGINFO, GetColorControls, result, 1, (lpColorControl));
}

// Sets the color-control options for an overlay or a primary surface.
HRESULT DirectDrawColorControl::SetColorControls(LPDDCOLORCONTROL lpColorControl)
{
    DirectDrawColorControlLogMethodValue(DEBUG, SetColorControls, 1, (lpColorControl));

    CONST HRESULT result = this->State.Self->SetColorControls(lpColorControl);

    DirectDrawColorControlLogMethodResultValue(DEBUGINFO, SetColorControls, result, 1, (lpColorControl));
}