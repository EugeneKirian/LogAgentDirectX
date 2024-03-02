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
#include "DirectDraw.hxx"
#include "DirectDraw2.hxx"
#include "DirectDraw4.hxx"
#include "DirectDraw7.hxx"
#include "DirectDrawVideoPort.hxx"
#include "DirectDrawVideoPortContainer.hxx"

#include <AgentLogger.hxx>
#include <DirectDrawVideoPortContainerLogger.hxx>

#define DirectDrawVideoPortContainerLogMethod(L, M) AgentLogMethod(L, DirectDrawVideoPortContainer, M)
#define DirectDrawVideoPortContainerLogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, DirectDrawVideoPortContainer, M, C, PARAMS)

#define DirectDrawVideoPortContainerLogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, DirectDrawVideoPortContainer, AddRef, R)
#define DirectDrawVideoPortContainerLogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, DirectDrawVideoPortContainer, Release, R)

#define DirectDrawVideoPortContainerLogMethodResult(L, M, R) AgentLogMethodResult(L, DirectDrawVideoPortContainer, M, R)
#define DirectDrawVideoPortContainerLogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, DirectDrawVideoPortContainer, M, R, C, PARAMS)

#define DirectDrawVideoPortContainerLogMethodCallbackValue(L, M, C, PARAMS) AgentLogMethodCallbackValue(L, DirectDrawVideoPortContainer, M, C, PARAMS)
#define DirectDrawVideoPortContainerLogMethodCallbackResultValue(L, M, R, C, PARAMS) AgentLogMethodCallbackResultValue(L, DirectDrawVideoPortContainer, M, R, C, PARAMS)

typedef struct EnumVideoPortsCallbackContext
{
    DirectDrawVideoPortContainer* Self;
    LPLOGGER Logger;
    LPDDENUMVIDEOCALLBACK lpEnumVideoCallback;
    LPVOID Context;
} ENUMVIDEOPORTSCALLBACKCONTEXT, * LPENUMVIDEOPORTSCALLBACKCONTEXT;

static HRESULT CALLBACK EnumVideoPortsCallback(LPDDVIDEOPORTCAPS lpDDVideoPortCaps, LPVOID lpContext)
{
    LPENUMVIDEOPORTSCALLBACKCONTEXT context = (LPENUMVIDEOPORTSCALLBACKCONTEXT)lpContext;

    DirectDrawVideoPortContainerLogMethodCallbackValue(DEBUG, EnumVideoPorts, 2, (context->Self, lpDDVideoPortCaps));

    CONST HRESULT result = context->lpEnumVideoCallback(lpDDVideoPortCaps, context->Context);

    DirectDrawVideoPortContainerLogMethodCallbackResultValue(DEBUGINFO, EnumVideoPorts, result, 2, (context->Self, lpDDVideoPortCaps));
}

DirectDrawVideoPortContainer::DirectDrawVideoPortContainer(AgentConstructorParameters(DirectDrawVideoPortContainer))
{
    AgentConstructor();
    AgentLogConstructor(DEBUG, DirectDrawVideoPortContainer);
}

DirectDrawVideoPortContainer::~DirectDrawVideoPortContainer()
{
    AgentDestructor();
    AgentLogDestructor(DEBUG, DirectDrawVideoPortContainer);
}

HRESULT DirectDrawVideoPortContainer::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    DirectDrawVideoPortContainerLogMethodValue(DEBUG, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3D, riid)) { *ppvObj = ActivateAgent(Direct3D, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3D2, riid)) { *ppvObj = ActivateAgent(Direct3D2, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3D3, riid)) { *ppvObj = ActivateAgent(Direct3D3, *ppvObj); }
            else if (IsEqualIID(IID_IDirect3D7, riid)) { *ppvObj = ActivateAgent(Direct3D7, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(DirectDraw, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw2, riid)) { *ppvObj = ActivateAgent(DirectDraw2, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw4, riid)) { *ppvObj = ActivateAgent(DirectDraw4, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDraw7, riid)) { *ppvObj = ActivateAgent(DirectDraw7, *ppvObj); }
            else if (IsEqualIID(IID_IDirectDrawVideoPortContainer, riid)) { *ppvObj = ActivateAgent(DirectDrawVideoPortContainer, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    DirectDrawVideoPortContainerLogMethodResultValue(DEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG DirectDrawVideoPortContainer::AddRef()
{
    DirectDrawVideoPortContainerLogMethod(DEBUG, AddRef);
    DirectDrawVideoPortContainerLogAddRefMethodResult(DEBUG, this->State.Self->AddRef());
}

ULONG DirectDrawVideoPortContainer::Release()
{
    DirectDrawVideoPortContainerLogMethod(DEBUG, Release);
    DirectDrawVideoPortContainerLogReleaseMethodResult(DEBUG, this->State.Self->Release());
}

// Creates a DirectDrawVideoPort object.
HRESULT DirectDrawVideoPortContainer::CreateVideoPort(DWORD dwFlags, LPDDVIDEOPORTDESC lpDDVideoPortDesc, LPDIRECTDRAWVIDEOPORT FAR* lplpDDVideoPort, IUnknown FAR* pUnkOuter)
{
    DirectDrawVideoPortContainerLogMethodValue(DEBUG, CreateVideoPort, 4, (dwFlags, lpDDVideoPortDesc, lplpDDVideoPort, pUnkOuter));

    CONST HRESULT result = this->State.Self->CreateVideoPort(dwFlags, lpDDVideoPortDesc, lplpDDVideoPort, pUnkOuter);

    if (SUCCEEDED(result)) { *lplpDDVideoPort = ActivateAgentDelegate(DirectDrawVideoPort, *lplpDDVideoPort); }

    DirectDrawVideoPortContainerLogMethodResultValue(DEBUGINFO, CreateVideoPort, result, 4, (dwFlags, lpDDVideoPortDesc, lplpDDVideoPort, pUnkOuter));
}

// Enumerates all the video ports that the hardware exposes that are compatible with a provided video-port description.
HRESULT DirectDrawVideoPortContainer::EnumVideoPorts(DWORD dwFlags, LPDDVIDEOPORTCAPS lpDDVideoPortCaps, LPVOID lpContext, LPDDENUMVIDEOCALLBACK lpEnumVideoCallback)
{
    DirectDrawVideoPortContainerLogMethodValue(DEBUGINFO, EnumVideoPorts, 4, (dwFlags, lpDDVideoPortCaps, lpContext, lpEnumVideoCallback));

    if (lpEnumVideoCallback == NULL) { DirectDrawVideoPortContainerLogMethodResultValue(DEBUGINFO, EnumVideoPorts, DDERR_INVALIDPARAMS, 4, (dwFlags, lpDDVideoPortCaps, lpContext, lpEnumVideoCallback)); }

    ENUMVIDEOPORTSCALLBACKCONTEXT context;

    context.Self = this;
    context.lpEnumVideoCallback = lpEnumVideoCallback;
    context.Context = lpContext;
    context.Logger = this->State.Logger;

    CONST HRESULT result = this->State.Self->EnumVideoPorts(dwFlags, lpDDVideoPortCaps, &context, EnumVideoPortsCallback);
    
    DirectDrawVideoPortContainerLogMethodResultValue(DEBUGINFO, EnumVideoPorts, result, 4, (dwFlags, lpDDVideoPortCaps, lpContext, lpEnumVideoCallback));
}

// Retrieves the connection information supported by all video ports.
HRESULT DirectDrawVideoPortContainer::GetVideoPortConnectInfo(DWORD dwPortId, LPDWORD lpNumEntries, LPDDVIDEOPORTCONNECT lpConnectInfo)
{
    DirectDrawVideoPortContainerLogMethodValue(DEBUG, GetVideoPortConnectInfo, 3, (dwPortId, lpNumEntries, lpConnectInfo));

    CONST HRESULT result = this->State.Self->GetVideoPortConnectInfo(dwPortId, lpNumEntries, lpConnectInfo);

    DirectDrawVideoPortContainerLogMethodResultValue(DEBUGINFO, GetVideoPortConnectInfo, result, 3, (dwPortId, lpNumEntries, lpConnectInfo));
}

HRESULT DirectDrawVideoPortContainer::QueryVideoPortStatus(DWORD dwPortId, LPDDVIDEOPORTSTATUS lpVPStatus)
{
    DirectDrawVideoPortContainerLogMethodValue(DEBUG, QueryVideoPortStatus, 2, (dwPortId, lpVPStatus));

    CONST HRESULT result = this->State.Self->QueryVideoPortStatus(dwPortId, lpVPStatus);

    DirectDrawVideoPortContainerLogMethodResultValue(DEBUGINFO, QueryVideoPortStatus, result, 2, (dwPortId, lpVPStatus));
}