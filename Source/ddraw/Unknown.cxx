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

#include "Direct3D.hxx"
#include "Direct3D2.hxx"
#include "Direct3D3.hxx"
#include "Direct3D7.hxx"
#include "Direct3DDevice.hxx"
#include "Direct3DDevice2.hxx"
#include "Direct3DDevice3.hxx"
#include "Direct3DDevice7.hxx"
#include "Direct3DExecuteBuffer.hxx"
#include "Direct3DLight.hxx"
#include "Direct3DMaterial.hxx"
#include "Direct3DMaterial2.hxx"
#include "Direct3DMaterial3.hxx"
#include "Direct3DTexture.hxx"
#include "Direct3DTexture2.hxx"
#include "Direct3DVertexBuffer.hxx"
#include "Direct3DVertexBuffer7.hxx"
#include "Direct3DViewport.hxx"
#include "Direct3DViewport2.hxx"
#include "Direct3DViewport3.hxx"
#include "DirectDraw.hxx"
#include "DirectDraw2.hxx"
#include "DirectDraw4.hxx"
#include "DirectDraw7.hxx"
#include "DirectDrawClipper.hxx"
#include "DirectDrawColorControl.hxx"
#include "DirectDrawGammaControl.hxx"
#include "DirectDrawPalette.hxx"
#include "DirectDrawSurface.hxx"
#include "DirectDrawSurface2.hxx"
#include "DirectDrawSurface3.hxx"
#include "DirectDrawSurface4.hxx"
#include "DirectDrawSurface7.hxx"
#include "DirectDrawVideoPort.hxx"
#include "DirectDrawVideoPortContainer.hxx"
#include "Unknown.hxx"

#include <AgentLogger.hxx>
#include <UnknownLogger.hxx>

#define UnknownLogMethod(L, M) AgentLogMethod(L, Unknown, M)
#define UnknownLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Unknown, M, C, PARAMS)

#define UnknownLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Unknown, AddRef, R)
#define UnknownLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Unknown, Release, R)

#define UnknownLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Unknown, M, R, C, PARAMS)

Unknown::Unknown(AgentConstructorParameters(Unknown))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Unknown);
}

Unknown::~Unknown()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Unknown);
}

HRESULT Unknown::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    UnknownLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3D, riid)) { *ppvObj = ActivateAgent(Direct3D, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3D2, riid)) { *ppvObj = ActivateAgent(Direct3D2, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3D3, riid)) { *ppvObj = ActivateAgent(Direct3D3, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3D7, riid)) { *ppvObj = ActivateAgent(Direct3D7, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DDevice, riid)) { *ppvObj = ActivateAgent(Direct3DDevice, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DDevice2, riid)) { *ppvObj = ActivateAgent(Direct3DDevice2, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DDevice3, riid)) { *ppvObj = ActivateAgent(Direct3DDevice3, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DDevice7, riid)) { *ppvObj = ActivateAgent(Direct3DDevice7, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DExecuteBuffer, riid)) { *ppvObj = ActivateAgent(Direct3DExecuteBuffer, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DLight, riid)) { *ppvObj = ActivateAgent(Direct3DLight, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DMaterial, riid)) { *ppvObj = ActivateAgent(Direct3DMaterial, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DMaterial2, riid)) { *ppvObj = ActivateAgent(Direct3DMaterial2, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DMaterial3, riid)) { *ppvObj = ActivateAgent(Direct3DMaterial3, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DTexture, riid)) { *ppvObj = ActivateAgent(Direct3DTexture, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DTexture2, riid)) { *ppvObj = ActivateAgent(Direct3DTexture2, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DVertexBuffer, riid)) { *ppvObj = ActivateAgent(Direct3DVertexBuffer, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DVertexBuffer7, riid)) { *ppvObj = ActivateAgent(Direct3DVertexBuffer7, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DViewport, riid)) { *ppvObj = ActivateAgent(Direct3DViewport, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DViewport2, riid)) { *ppvObj = ActivateAgent(Direct3DViewport2, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DViewport3, riid)) { *ppvObj = ActivateAgent(Direct3DViewport3, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw, riid)) { *ppvObj = ActivateAgent(DirectDraw, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw2, riid)) { *ppvObj = ActivateAgent(DirectDraw2, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw4, riid)) { *ppvObj = ActivateAgent(DirectDraw4, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw7, riid)) { *ppvObj = ActivateAgent(DirectDraw7, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawClipper, riid)) { *ppvObj = ActivateAgent(DirectDrawClipper, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawColorControl, riid)) { *ppvObj = ActivateAgent(DirectDrawColorControl, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawGammaControl, riid)) { *ppvObj = ActivateAgent(DirectDrawGammaControl, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawPalette, riid)) { *ppvObj = ActivateAgent(DirectDrawPalette, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface2, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface2, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface3, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface3, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface4, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface4, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface7, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface7, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawVideoPort, riid)) { *ppvObj = ActivateAgent(DirectDrawVideoPort, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawVideoPortContainer, riid)) { *ppvObj = ActivateAgent(DirectDrawVideoPortContainer, *ppvObj); }
            else if (IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Unknown, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    UnknownLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Unknown::AddRef()
{
    UnknownLogMethod(DEBUG, AddRef);
    UnknownLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG Unknown::Release()
{
    UnknownLogMethod(DEBUG, Release);
    UnknownLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}