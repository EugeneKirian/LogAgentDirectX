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

#include "Direct3DDevice.hxx"
#include "Direct3DTexture.hxx"
#include "Direct3DTexture2.hxx"
#include "DirectDrawGammaControl.hxx"
#include "DirectDrawSurface.hxx"
#include "DirectDrawSurface2.hxx"
#include "DirectDrawSurface3.hxx"
#include "DirectDrawSurface4.hxx"
#include "DirectDrawSurface7.hxx"

#include <AgentLogger.hxx>
#include <Direct3DTextureLogger.hxx>

#define Direct3DTextureLogMethod(L, M) AgentLogMethod(L, Direct3DTexture, M)
#define Direct3DTextureLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DTexture, M, C, PARAMS)

#define Direct3DTextureLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DTexture, AddRef, R)
#define Direct3DTextureLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DTexture, Release, R)

#define Direct3DTextureLogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DTexture, M, R)
#define Direct3DTextureLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DTexture, M, R, C, PARAMS)

Direct3DTexture::Direct3DTexture(AgentConstructorParameters(Direct3DTexture))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DTexture);
}

Direct3DTexture::~Direct3DTexture()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DTexture);
}

HRESULT Direct3DTexture::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DTextureLogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

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

    Direct3DTextureLogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DTexture::AddRef()
{
    Direct3DTextureLogMethod(DEBUG, AddRef);
    Direct3DTextureLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG Direct3DTexture::Release()
{
    Direct3DTextureLogMethod(DEBUG, Release);
    Direct3DTextureLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

HRESULT Direct3DTexture::Initialize(LPDIRECT3DDEVICE lpDirect3DDevice, LPDIRECTDRAWSURFACE lpDDS)
{
    Direct3DTextureLogMethodValue(TRACE, Initialize, 2, (lpDirect3DDevice, lpDDS));

    AttemptAccessAgentValue(Direct3DDevice, lpDirect3DDevice);
    AttemptAccessAgentValue(DirectDrawSurface, lpDDS);

    CONST HRESULT result = this->State.Self->Initialize(lpDirect3DDevice, lpDDS);

    Direct3DTextureLogMethodResultValue(TRACEDEBUGINFO, Initialize, result, 2, (ActivateAgent(Direct3DDevice, lpDirect3DDevice), ActivateAgent(DirectDrawSurface, lpDDS)));
}

// Obtains the texture handle to be used when rendering with the IDirect3DDevice interface.
HRESULT Direct3DTexture::GetHandle(LPDIRECT3DDEVICE lpDirect3DDevice, LPD3DTEXTUREHANDLE lpHandle)
{
    Direct3DTextureLogMethodValue(TRACE, GetHandle, 2, (lpDirect3DDevice, lpHandle));

    AttemptAccessAgentValue(Direct3DDevice, lpDirect3DDevice);

    CONST HRESULT result = this->State.Self->GetHandle(lpDirect3DDevice, lpHandle);

    Direct3DTextureLogMethodResultValue(TRACEDEBUGINFO, GetHandle, result, 2, (ActivateAgent(Direct3DDevice, lpDirect3DDevice), lpHandle));
}

// Informs the driver that the palette has changed on a texture surface. 
HRESULT Direct3DTexture::PaletteChanged(DWORD dwStart, DWORD dwCount)
{
    Direct3DTextureLogMethodValue(TRACE, PaletteChanged, 2, (dwStart, dwCount));

    CONST HRESULT result = this->State.Self->PaletteChanged(dwStart, dwCount);

    Direct3DTextureLogMethodResultValue(TRACEDEBUGINFO, PaletteChanged, result, 2, (dwStart, dwCount));
}

HRESULT Direct3DTexture::Load(LPDIRECT3DTEXTURE lpD3DTexture)
{
    Direct3DTextureLogMethodValue(TRACE, Load, 1, (lpD3DTexture));

    AttemptAccessAgentValue(Direct3DTexture, lpD3DTexture);

    CONST HRESULT result = this->State.Self->Load(lpD3DTexture);

    Direct3DTextureLogMethodResultValue(TRACEDEBUGINFO, Load, result, 1, (ActivateAgent(Direct3DTexture, lpD3DTexture)));
}

HRESULT Direct3DTexture::Unload()
{
    Direct3DTextureLogMethod(DEBUG, Unload);

    CONST HRESULT result = this->State.Self->Unload();

    Direct3DTextureLogMethodResult(DEBUGINFO, Unload, result);
}