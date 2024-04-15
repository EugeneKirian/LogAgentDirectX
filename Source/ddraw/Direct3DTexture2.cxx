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

#include "Direct3DDevice2.hxx"
#include "Direct3DTexture.hxx"
#include "Direct3DTexture2.hxx"
#include "DirectDrawGammaControl.hxx"
#include "DirectDrawSurface.hxx"
#include "DirectDrawSurface2.hxx"
#include "DirectDrawSurface3.hxx"
#include "DirectDrawSurface4.hxx"
#include "DirectDrawSurface7.hxx"

#include <AgentLogger.hxx>
#include <Direct3DTexture2Logger.hxx>

#define Direct3DTexture2LogMethod(L, M) AgentLogMethod(L, Direct3DTexture2, M)
#define Direct3DTexture2LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DTexture2, M, C, PARAMS)

#define Direct3DTexture2LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DTexture2, AddRef, R)
#define Direct3DTexture2LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DTexture2, Release, R)

#define Direct3DTexture2LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DTexture2, M, R)
#define Direct3DTexture2LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DTexture2, M, R, C, PARAMS)

Direct3DTexture2::Direct3DTexture2(AgentConstructorParameters(Direct3DTexture2))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DTexture2);
}

Direct3DTexture2::~Direct3DTexture2()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DTexture2);
}

HRESULT Direct3DTexture2::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DTexture2LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DTexture, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Direct3DTexture, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3DTexture2, riid)) { *ppvObj = ActivateAgent(Direct3DTexture2, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawGammaControl, riid)) { *ppvObj = ActivateAgent(DirectDrawGammaControl, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface2, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface2, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface3, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface3, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface4, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface4, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawSurface7, riid)) { *ppvObj = ActivateAgent(DirectDrawSurface7, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DTexture2LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DTexture2::AddRef()
{
    Direct3DTexture2LogMethod(TRACE, AddRef);
    Direct3DTexture2LogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG Direct3DTexture2::Release()
{
    Direct3DTexture2LogMethod(TRACE, Release);
    Direct3DTexture2LogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Obtains the texture handle to be used when rendering with the IDirect3DDevice2 or IDirect3DDevice interfaces.
HRESULT Direct3DTexture2::GetHandle(LPDIRECT3DDEVICE2 lpDirect3DDevice, LPD3DTEXTUREHANDLE lpHandle)
{
    Direct3DTexture2LogMethodValue(TRACE, GetHandle, 2, (lpDirect3DDevice, lpHandle));

    AttemptAccessAgentValue(Direct3DDevice2, lpDirect3DDevice);

    CONST HRESULT result = this->State.Self->GetHandle(lpDirect3DDevice, lpHandle);

    Direct3DTexture2LogMethodResultValue(TRACEDEBUGINFO, GetHandle, result, 2, (ActivateAgent(Direct3DDevice2, lpDirect3DDevice), lpHandle));
}

// Informs the driver that the palette has changed on a texture surface. 
HRESULT Direct3DTexture2::PaletteChanged(DWORD dwStart, DWORD dwCount)
{
    Direct3DTexture2LogMethodValue(TRACE, PaletteChanged, 2, (dwStart, dwCount));

    CONST HRESULT result = this->State.Self->PaletteChanged(dwStart, dwCount);

    Direct3DTexture2LogMethodResultValue(TRACEDEBUGINFO, PaletteChanged, result, 2, (dwStart, dwCount));
}

// loads a texture that was created with the DDSCAPS_ALLOCONLOAD flag,
// which indicates that memory for the DirectDraw surface is not allocated until this method loads the surface.
HRESULT Direct3DTexture2::Load(LPDIRECT3DTEXTURE2 lpD3DTexture)
{
    Direct3DTexture2LogMethodValue(TRACE, Load, 1, (lpD3DTexture));

    AttemptAccessAgentValue(Direct3DTexture2, lpD3DTexture);

    CONST HRESULT result = this->State.Self->Load(lpD3DTexture);

    Direct3DTexture2LogMethodResultValue(TRACEDEBUGINFO, Load, result, 1, (ActivateAgent(Direct3DTexture2, lpD3DTexture)));
}