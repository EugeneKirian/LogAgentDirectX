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

#include "Direct3D8.hxx"
#include "Direct3DBaseTexture8.hxx"
#include "Direct3DCubeTexture8.hxx"
#include "Direct3DDevice8.hxx"
#include "Direct3DIndexBuffer8.hxx"
#include "Direct3DSurface8.hxx"
#include "Direct3DSwapChain8.hxx"
#include "Direct3DTexture8.hxx"
#include "Direct3DVertexBuffer8.hxx"
#include "Direct3DVolumeTexture8.hxx"

#include <AgentLogger.hxx>
#include <Direct3DDevice8Logger.hxx>

#define Direct3DDevice8LogMethod(L, M) AgentLogMethod(L, Direct3DDevice8, M)
#define Direct3DDevice8LogMethodValue(L, M, C, PARAMS) AgentLogMethodValue(L, Direct3DDevice8, M, C, PARAMS)

#define Direct3DDevice8LogAddRefMethodResult(L, R) AgentLogAddRefMethodResult(L, Direct3DDevice8, AddRef, R)
#define Direct3DDevice8LogReleaseMethodResult(L, R) AgentLogReleaseMethodResult(L, Direct3DDevice8, Release, R, TRUE)

#define Direct3DDevice8LogMethodResult(L, M, R) AgentLogMethodResult(L, Direct3DDevice8, M, R)
#define Direct3DDevice8LogMethodCustomResult(L, M, R, F, T) AgentLogMethodCustomResult(L, Direct3DDevice8, M, R, F, T)

#define Direct3DDevice8LogMethodResultValue(L, M, R, C, PARAMS) AgentLogMethodResultValue(L, Direct3DDevice8, M, R, C, PARAMS)
#define Direct3DDevice8LogMethodCustomResultValue(L, M, R, F, T, C, PARAMS) AgentLogMethodCustomResultValue(L, Direct3DDevice8, M, R, F, T, C, PARAMS)
#define Direct3DDevice8LogMethodNoResultValue(L, M, C, PARAMS) AgentLogMethodNoResultValue(L, Direct3DDevice8, M, C, PARAMS)

Direct3DDevice8::Direct3DDevice8(AgentConstructorParameters(Direct3DDevice8))
{
    AgentConstructor();
    AgentLogConstructor(TRACE, Direct3DDevice8);
}

Direct3DDevice8::~Direct3DDevice8()
{
    AgentDestructor();
    AgentLogDestructor(TRACE, Direct3DDevice8);
}

HRESULT Direct3DDevice8::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
    Direct3DDevice8LogMethodValue(TRACE, QueryInterface, 2, (riid, ppvObj));

    CONST HRESULT result = this->State.Self->QueryInterface(riid, ppvObj);

    if (SUCCEEDED(result))
    {
        if (!AcquireAgent(riid, ppvObj))
        {
            if (IsEqualIID(IID_IDirect3DDevice8, riid) || IsEqualIID(IID_IUnknown, riid)) { *ppvObj = ActivateAgent(Direct3DDevice8, *ppvObj); }
            /* else { HANDLE UNKNOWN IDENTIFIER } */
        }
    }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, QueryInterface, result, 2, (riid, ppvObj));
}

ULONG Direct3DDevice8::AddRef()
{
    Direct3DDevice8LogMethod(TRACE, AddRef);
    Direct3DDevice8LogAddRefMethodResult(TRACE, this->State.Self->AddRef());
}

ULONG Direct3DDevice8::Release()
{
    Direct3DDevice8LogMethod(TRACE, Release);
    Direct3DDevice8LogReleaseMethodResult(TRACE, this->State.Self->Release());
}

// Reports the current cooperative-level status of the Microsoft® Direct3D® device for a windowed or full-screen application.
HRESULT Direct3DDevice8::TestCooperativeLevel()
{
    return this->State.Self->TestCooperativeLevel();
}

// Returns an estimate of the amount of available texture memory.
UINT Direct3DDevice8::GetAvailableTextureMem()
{
    Direct3DDevice8LogMethod(TRACE, GetAvailableTextureMem);

    CONST HRESULT result = this->State.Self->GetAvailableTextureMem();

    Direct3DDevice8LogMethodResult(TRACEDEBUGINFO, GetAvailableTextureMem, result);
}

// Invokes the resource manager to free memory. 
HRESULT Direct3DDevice8::ResourceManagerDiscardBytes(DWORD Bytes)
{
    Direct3DDevice8LogMethodValue(TRACE, ResourceManagerDiscardBytes, 1, (Bytes));

    CONST HRESULT result = this->State.Self->ResourceManagerDiscardBytes(Bytes);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, ResourceManagerDiscardBytes, result, 1, (Bytes));
}

// Returns an interface to the instance of the Microsoft® Direct3D® object that created the device.
HRESULT Direct3DDevice8::GetDirect3D(LPDIRECT3D8* ppD3D8)
{
    Direct3DDevice8LogMethodValue(TRACE, GetDirect3D, 1, (ppD3D8));

    CONST HRESULT result = this->State.Self->GetDirect3D(ppD3D8);

    if (SUCCEEDED(result)) { *ppD3D8 = ActivateAgent(Direct3D8, *ppD3D8); }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetDirect3D, result, 1, (ppD3D8));
}

// Retrieves the capabilities of the rendering device.
HRESULT Direct3DDevice8::GetDeviceCaps(D3DCAPS8* pCaps)
{
    Direct3DDevice8LogMethodValue(TRACE, GetDeviceCaps, 1, (pCaps));

    CONST HRESULT result = this->State.Self->GetDeviceCaps(pCaps);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetDeviceCaps, result, 1, (pCaps));
}

// Retrieves the display mode's spatial resolution, color resolution, and refresh frequency.
HRESULT Direct3DDevice8::GetDisplayMode(D3DDISPLAYMODE* pMode)
{
    Direct3DDevice8LogMethodValue(TRACE, GetDisplayMode, 1, (pMode));

    CONST HRESULT result = this->State.Self->GetDisplayMode(pMode);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetDisplayMode, result, 1, (pMode));
}

// Retrieves the creation parameters of the device.
HRESULT Direct3DDevice8::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS* pParameters)
{
    Direct3DDevice8LogMethodValue(TRACE, GetCreationParameters, 1, (pParameters));

    CONST HRESULT result = this->State.Self->GetCreationParameters(pParameters);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetCreationParameters, result, 1, (pParameters));
}

// Sets properties for the cursor.
HRESULT Direct3DDevice8::SetCursorProperties(UINT XHotSpot, UINT YHotSpot, LPDIRECT3DSURFACE8 pCursorBitmap)
{
    Direct3DDevice8LogMethodValue(TRACE, SetCursorProperties, 3, (XHotSpot, YHotSpot, pCursorBitmap));

    AttemptAccessAgentValue(Direct3DSurface8, pCursorBitmap);

    CONST HRESULT result = this->State.Self->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetCursorProperties, result, 3, (XHotSpot, YHotSpot, ActivateAgent(Direct3DSurface8, pCursorBitmap)));
}

// Sets the cursor position and update options.
VOID Direct3DDevice8::SetCursorPosition(UINT XScreenSpace, UINT YScreenSpace, DWORD Flags)
{
    Direct3DDevice8LogMethodValue(TRACE, SetCursorPosition, 3, (XScreenSpace, YScreenSpace, Flags));

    this->State.Self->SetCursorPosition(XScreenSpace, YScreenSpace, Flags);

    Direct3DDevice8LogMethodNoResultValue(TRACEDEBUGINFO, SetCursorPosition, 3, (XScreenSpace, YScreenSpace, Flags));
}

// Displays or hides the cursor.
BOOL Direct3DDevice8::ShowCursor(BOOL bShow)
{
    Direct3DDevice8LogMethodValue(TRACE, ShowCursor, 1, (bShow));

    CONST BOOL result = this->State.Self->ShowCursor(bShow);

    Direct3DDevice8LogMethodCustomResultValue(TRACEDEBUGINFO, ShowCursor, result, !result, BOOL, 1, (bShow));
}

// Creates an additional swap chain for rendering multiple views.
HRESULT Direct3DDevice8::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters, LPDIRECT3DSWAPCHAIN8* pSwapChain)
{
    Direct3DDevice8LogMethodValue(TRACE, CreateAdditionalSwapChain, 2, (pPresentationParameters, pSwapChain));

    CONST HRESULT result = this->State.Self->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain);

    if (SUCCEEDED(result)) { *pSwapChain = ActivateAgentDelegate(Direct3DSwapChain8, *pSwapChain); }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, CreateAdditionalSwapChain, result, 2, (pPresentationParameters, pSwapChain));
}

// Resets the type, size, and format of the swap chain.
HRESULT Direct3DDevice8::Reset(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    Direct3DDevice8LogMethodValue(TRACE, Reset, 1, (pPresentationParameters));

    CONST HRESULT result = this->State.Self->Reset(pPresentationParameters);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, Reset, result, 1, (pPresentationParameters));
}

// Presents the contents of the next in the sequence of back buffers owned by the device. 
HRESULT Direct3DDevice8::Present(CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion)
{
    Direct3DDevice8LogMethodValue(TRACE, Present, 4, (pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion));

    CONST HRESULT result = this->State.Self->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, Present, result, 4, (pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion));
}

// Retrieves a back buffer from the device's swap chain.
HRESULT Direct3DDevice8::GetBackBuffer(UINT BackBuffer, D3DBACKBUFFER_TYPE Type, LPDIRECT3DSURFACE8* ppBackBuffer)
{
    Direct3DDevice8LogMethodValue(TRACE, GetBackBuffer, 3, (BackBuffer, Type, ppBackBuffer));

    CONST HRESULT result = this->State.Self->GetBackBuffer(BackBuffer, Type, ppBackBuffer);

    if (SUCCEEDED(result)) { *ppBackBuffer = ActivateAgent(Direct3DSurface8, *ppBackBuffer); }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetBackBuffer, result, 3, (BackBuffer, Type, ppBackBuffer));
}

// Returns information describing the raster of the monitor on which the swap chain is presented.
HRESULT Direct3DDevice8::GetRasterStatus(D3DRASTER_STATUS* pRasterStatus)
{
    Direct3DDevice8LogMethodValue(TRACE, GetRasterStatus, 1, (pRasterStatus));

    CONST HRESULT result = this->State.Self->GetRasterStatus(pRasterStatus);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetRasterStatus, result, 1, (pRasterStatus));
}

// Sets the gamma correction ramp for the implicit swap chain.
VOID Direct3DDevice8::SetGammaRamp(DWORD Flags, CONST D3DGAMMARAMP* pRamp)
{
    Direct3DDevice8LogMethodValue(TRACE, SetGammaRamp, 2, (Flags, pRamp));

    this->State.Self->SetGammaRamp(Flags, pRamp);

    Direct3DDevice8LogMethodNoResultValue(TRACEDEBUGINFO, SetGammaRamp, 2, (Flags, pRamp));
}

// Retrieves the gamma correction ramp for the swap chain.
VOID Direct3DDevice8::GetGammaRamp(D3DGAMMARAMP* pRamp)
{
    Direct3DDevice8LogMethodValue(TRACE, GetGammaRamp, 1, (pRamp));

    this->State.Self->GetGammaRamp(pRamp);

    Direct3DDevice8LogMethodNoResultValue(TRACEDEBUGINFO, GetGammaRamp, 1, (pRamp));
}

// Creates a texture resource.
HRESULT Direct3DDevice8::CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, LPDIRECT3DTEXTURE8* ppTexture)
{
    Direct3DDevice8LogMethodValue(TRACE, CreateTexture, 7, (Width, Height, Levels, Usage, Format, Pool, ppTexture));

    CONST HRESULT result = this->State.Self->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture);

    if (SUCCEEDED(result)) { *ppTexture = ActivateAgent(Direct3DTexture8, *ppTexture); }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, CreateTexture, result, 7, (Width, Height, Levels, Usage, Format, Pool, ppTexture));
}

// Creates a volume texture resource.
HRESULT Direct3DDevice8::CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, LPDIRECT3DVOLUMETEXTURE8* ppVolumeTexture)
{
    Direct3DDevice8LogMethodValue(TRACE, CreateVolumeTexture, 8, (Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture));

    CONST HRESULT result = this->State.Self->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture);

    if (SUCCEEDED(result)) { *ppVolumeTexture = ActivateAgent(Direct3DVolumeTexture8, *ppVolumeTexture); }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, CreateVolumeTexture, result, 8, (Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture));
}

// Creates a cube texture resource.
HRESULT Direct3DDevice8::CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, LPDIRECT3DCUBETEXTURE8* ppCubeTexture)
{
    Direct3DDevice8LogMethodValue(TRACE, CreateCubeTexture, 6, (EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture));

    CONST HRESULT result = this->State.Self->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture);

    if (SUCCEEDED(result)) { *ppCubeTexture = ActivateAgent(Direct3DCubeTexture8, *ppCubeTexture); }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, CreateCubeTexture, result, 6, (EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture));
}

// Creates a vertex buffer.
HRESULT Direct3DDevice8::CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, LPDIRECT3DVERTEXBUFFER8* ppVertexBuffer)
{
    Direct3DDevice8LogMethodValue(TRACE, CreateVertexBuffer, 5, (Length, Usage, FVF, Pool, ppVertexBuffer));

    CONST HRESULT result = this->State.Self->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer);

    if (SUCCEEDED(result)) { *ppVertexBuffer = ActivateAgentDelegate(Direct3DVertexBuffer8, *ppVertexBuffer); }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, CreateVertexBuffer, result, 5, (Length, Usage, FVF, Pool, ppVertexBuffer));
}

// Creates an index buffer.
HRESULT Direct3DDevice8::CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, LPDIRECT3DINDEXBUFFER8* ppIndexBuffer)
{
    Direct3DDevice8LogMethodValue(TRACE, CreateIndexBuffer, 5, (Length, Usage, Format, Pool, ppIndexBuffer));

    CONST HRESULT result = this->State.Self->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer);

    if (SUCCEEDED(result)) { *ppIndexBuffer = ActivateAgentDelegate(Direct3DIndexBuffer8, *ppIndexBuffer); }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, CreateIndexBuffer, result, 5, (Length, Usage, Format, Pool, ppIndexBuffer));
}

// Creates a render target surface.
HRESULT Direct3DDevice8::CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, BOOL Lockable, LPDIRECT3DSURFACE8* ppSurface)
{
    Direct3DDevice8LogMethodValue(TRACE, CreateRenderTarget, 6, (Width, Height, Format, MultiSample, Lockable, ppSurface));

    CONST HRESULT result = this->State.Self->CreateRenderTarget(Width, Height, Format, MultiSample, Lockable, ppSurface);

    if (SUCCEEDED(result)) { *ppSurface = ActivateAgentDelegate(Direct3DSurface8, *ppSurface); }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, CreateRenderTarget, result, 6, (Width, Height, Format, MultiSample, Lockable, ppSurface));
}

// Creates a depth-stencil resource.
HRESULT Direct3DDevice8::CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, LPDIRECT3DSURFACE8* ppSurface)
{
    Direct3DDevice8LogMethodValue(TRACE, CreateDepthStencilSurface, 5, (Width, Height, Format, MultiSample, ppSurface));

    CONST HRESULT result = this->State.Self->CreateDepthStencilSurface(Width, Height, Format, MultiSample, ppSurface);

    if (SUCCEEDED(result)) { *ppSurface = ActivateAgentDelegate(Direct3DSurface8, *ppSurface); }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, CreateDepthStencilSurface, result, 5, (Width, Height, Format, MultiSample, ppSurface));
}

// Creates an image surface.
HRESULT Direct3DDevice8::CreateImageSurface(UINT Width, UINT Height, D3DFORMAT Format, LPDIRECT3DSURFACE8* ppSurface)
{
    Direct3DDevice8LogMethodValue(TRACE, CreateImageSurface, 4, (Width, Height, Format, ppSurface));

    CONST HRESULT result = this->State.Self->CreateImageSurface(Width, Height, Format, ppSurface);

    if (SUCCEEDED(result)) { *ppSurface = ActivateAgentDelegate(Direct3DSurface8, *ppSurface); }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, CreateImageSurface, result, 4, (Width, Height, Format, ppSurface));
}

// Copies rectangular subsets of pixels from one surface to another.
HRESULT Direct3DDevice8::CopyRects(LPDIRECT3DSURFACE8 pSourceSurface, CONST RECT* pSourceRectsArray, UINT cRects, LPDIRECT3DSURFACE8 pDestinationSurface, CONST POINT* pDestPointsArray)
{
    Direct3DDevice8LogMethodValue(TRACE, CopyRects, 5, (pSourceSurface, pSourceRectsArray, cRects, pDestinationSurface, pDestPointsArray));

    AttemptAccessAgentValue(Direct3DSurface8, pSourceSurface);
    AttemptAccessAgentValue(Direct3DSurface8, pDestinationSurface);

    CONST HRESULT result = this->State.Self->CopyRects(pSourceSurface, pSourceRectsArray, cRects, pDestinationSurface, pDestPointsArray);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, CopyRects, result, 5, (ActivateAgent(Direct3DSurface8, pSourceSurface), pSourceRectsArray, cRects, ActivateAgent(Direct3DSurface8, pDestinationSurface), pDestPointsArray));
}

// Updates the dirty portions of a texture.
HRESULT Direct3DDevice8::UpdateTexture(LPDIRECT3DBASETEXTURE8 pSourceTexture, LPDIRECT3DBASETEXTURE8 pDestinationTexture)
{
    Direct3DDevice8LogMethodValue(TRACE, UpdateTexture, 2, (pSourceTexture, pDestinationTexture));

    AttemptAccessAgentValue(Direct3DBaseTexture8, pSourceTexture);
    AttemptAccessAgentValue(Direct3DBaseTexture8, pDestinationTexture);

    CONST HRESULT result = this->State.Self->UpdateTexture(pSourceTexture, pDestinationTexture);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, UpdateTexture, result, 2, (ActivateAgent(Direct3DBaseTexture8, pSourceTexture), ActivateAgent(Direct3DBaseTexture8, pDestinationTexture)));
}

// Generates a copy of the device's front buffer and places that copy in a system memory buffer provided by the application. 
HRESULT Direct3DDevice8::GetFrontBuffer(LPDIRECT3DSURFACE8 pDestSurface)
{
    Direct3DDevice8LogMethodValue(TRACE, GetFrontBuffer, 1, (pDestSurface));

    AttemptAccessAgentValue(Direct3DSurface8, pDestSurface);

    CONST HRESULT result = this->State.Self->GetFrontBuffer(pDestSurface);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetFrontBuffer, result, 1, (ActivateAgent(Direct3DSurface8, pDestSurface)));
}

// Sets a new color buffer, depth buffer, or both for the device.
HRESULT Direct3DDevice8::SetRenderTarget(LPDIRECT3DSURFACE8 pRenderTarget, LPDIRECT3DSURFACE8 pNewZStencil)
{
    Direct3DDevice8LogMethodValue(TRACE, SetRenderTarget, 2, (pRenderTarget, pNewZStencil));

    AttemptAccessAgentValue(Direct3DSurface8, pRenderTarget);
    AttemptAccessAgentValue(Direct3DSurface8, pNewZStencil);

    CONST HRESULT result = this->State.Self->SetRenderTarget(pRenderTarget, pNewZStencil);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetRenderTarget, result, 2, (ActivateAgent(Direct3DSurface8, pRenderTarget), ActivateAgent(Direct3DSurface8, pNewZStencil)));
}

// Retrieves a pointer to the Microsoft® Direct3D® surface that is being used as a render target.
HRESULT Direct3DDevice8::GetRenderTarget(LPDIRECT3DSURFACE8* ppRenderTarget)
{
    Direct3DDevice8LogMethodValue(TRACE, GetRenderTarget, 1, (ppRenderTarget));

    CONST HRESULT result = this->State.Self->GetRenderTarget(ppRenderTarget);

    if (SUCCEEDED(result)) { *ppRenderTarget = ActivateAgent(Direct3DSurface8, *ppRenderTarget); }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetRenderTarget, result, 1, (ppRenderTarget));
}

// Retrieves the depth-stencil surface owned by the Direct3DDevice object.
HRESULT Direct3DDevice8::GetDepthStencilSurface(LPDIRECT3DSURFACE8* ppZStencilSurface)
{
    Direct3DDevice8LogMethodValue(TRACE, GetDepthStencilSurface, 1, (ppZStencilSurface));

    CONST HRESULT result = this->State.Self->GetDepthStencilSurface(ppZStencilSurface);

    if (SUCCEEDED(result)) { *ppZStencilSurface = ActivateAgent(Direct3DSurface8, *ppZStencilSurface); }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetDepthStencilSurface, result, 1, (ppZStencilSurface));
}

// Begins a scene. 
HRESULT Direct3DDevice8::BeginScene()
{
    Direct3DDevice8LogMethod(TRACE, BeginScene);

    CONST HRESULT result = this->State.Self->BeginScene();

    Direct3DDevice8LogMethodResult(TRACEDEBUGINFO, BeginScene, result);
}

// Ends a scene that was begun by calling the IDirect3DDevice8::BeginScene method.
HRESULT Direct3DDevice8::EndScene()
{
    Direct3DDevice8LogMethod(TRACE, EndScene);

    CONST HRESULT result = this->State.Self->EndScene();

    Direct3DDevice8LogMethodResult(TRACEDEBUGINFO, EndScene, result);
}

// Clears the viewport, or a set of rectangles in the viewport, to a specified RGBA color, clears the depth buffer, and erases the stencil buffer.
HRESULT Direct3DDevice8::Clear(DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, FLOAT Z, DWORD Stencil)
{
    Direct3DDevice8LogMethodValue(TRACE, Clear, 6, (Count, pRects, Flags, Color, Z, Stencil));

    CONST HRESULT result = this->State.Self->Clear(Count, pRects, Flags, Color, Z, Stencil);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, Clear, result, 6, (Count, pRects, Flags, Color, Z, Stencil));
}

// Sets a single device transformation-related state.
HRESULT Direct3DDevice8::SetTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix)
{
    Direct3DDevice8LogMethodValue(TRACE, SetTransform, 2, (State, pMatrix));

    CONST HRESULT result = this->State.Self->SetTransform(State, pMatrix);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetTransform, result, 2, (State, pMatrix));
}

// Retrieves a matrix describing a transformation state.
HRESULT Direct3DDevice8::GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix)
{
    Direct3DDevice8LogMethodValue(TRACE, GetTransform, 2, (State, pMatrix));

    CONST HRESULT result = this->State.Self->GetTransform(State, pMatrix);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetTransform, result, 2, (State, pMatrix));
}

// Multiplies a device's world, view, or projection matrices by a specified matrix.
HRESULT Direct3DDevice8::MultiplyTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix)
{
    Direct3DDevice8LogMethodValue(TRACE, MultiplyTransform, 2, (State, pMatrix));

    CONST HRESULT result = this->State.Self->MultiplyTransform(State, pMatrix);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, MultiplyTransform, result, 2, (State, pMatrix));
}

// Sets the viewport parameters for the device.
HRESULT Direct3DDevice8::SetViewport(CONST D3DVIEWPORT8* pViewport)
{
    Direct3DDevice8LogMethodValue(TRACE, SetViewport, 1, (pViewport));

    CONST HRESULT result = this->State.Self->SetViewport(pViewport);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetViewport, result, 1, (pViewport));
}

// Retrieves the viewport parameters currently set for the device.
HRESULT Direct3DDevice8::GetViewport(D3DVIEWPORT8* pViewport)
{
    Direct3DDevice8LogMethodValue(TRACE, GetViewport, 1, (pViewport));

    CONST HRESULT result = this->State.Self->GetViewport(pViewport);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetViewport, result, 1, (pViewport));
}

// Sets the material properties for the device.
HRESULT Direct3DDevice8::SetMaterial(CONST D3DMATERIAL8* pMaterial)
{
    Direct3DDevice8LogMethodValue(TRACE, SetMaterial, 1, (pMaterial));

    CONST HRESULT result = this->State.Self->SetMaterial(pMaterial);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetMaterial, result, 1, (pMaterial));
}

// Retrieves the current material properties for the device.
HRESULT Direct3DDevice8::GetMaterial(D3DMATERIAL8* pMaterial)
{
    Direct3DDevice8LogMethodValue(TRACE, GetMaterial, 1, (pMaterial));

    CONST HRESULT result = this->State.Self->GetMaterial(pMaterial);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetMaterial, result, 1, (pMaterial));
}

// Assigns a set of lighting properties for this device.
HRESULT Direct3DDevice8::SetLight(DWORD Index, CONST D3DLIGHT8* pLight)
{
    Direct3DDevice8LogMethodValue(TRACE, SetLight, 2, (Index, pLight));

    CONST HRESULT result = this->State.Self->SetLight(Index, pLight);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetLight, result, 2, (Index, pLight));
}

// Retrieves a set of lighting properties that this device uses.
HRESULT Direct3DDevice8::GetLight(DWORD Index, D3DLIGHT8* pLight)
{
    Direct3DDevice8LogMethodValue(TRACE, GetLight, 2, (Index, pLight));

    CONST HRESULT result = this->State.Self->GetLight(Index, pLight);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetLight, result, 2, (Index, pLight));
}

// Enables or disables a set of lighting parameters within a device.
HRESULT Direct3DDevice8::LightEnable(DWORD Index, BOOL bEnable)
{
    Direct3DDevice8LogMethodValue(TRACE, LightEnable, 2, (Index, bEnable));

    CONST HRESULT result = this->State.Self->LightEnable(Index, bEnable);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, LightEnable, result, 2, (Index, bEnable));
}

// Retrieves the activity status—enabled or disabled—for a set of lighting parameters within a device.
HRESULT Direct3DDevice8::GetLightEnable(DWORD Index, BOOL* pEnable)
{
    Direct3DDevice8LogMethodValue(TRACE, GetLightEnable, 2, (Index, pEnable));

    CONST HRESULT result = this->State.Self->GetLightEnable(Index, pEnable);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetLightEnable, result, 2, (Index, pEnable));
}

// Sets the coefficients of a user-defined clipping plane for the device.
HRESULT Direct3DDevice8::SetClipPlane(DWORD Index, CONST FLOAT* pPlane)
{
    Direct3DDevice8LogMethodValue(TRACE, SetClipPlane, 2, (Index, pPlane));

    CONST HRESULT result = this->State.Self->SetClipPlane(Index, pPlane);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetClipPlane, result, 2, (Index, pPlane));
}

// Retrieves the coefficients of a user-defined clipping plane for the device.
HRESULT Direct3DDevice8::GetClipPlane(DWORD Index, FLOAT* pPlane)
{
    Direct3DDevice8LogMethodValue(TRACE, GetClipPlane, 2, (Index, pPlane));

    CONST HRESULT result = this->State.Self->GetClipPlane(Index, pPlane);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetClipPlane, result, 2, (Index, pPlane));
}

// Sets a single device render-state parameter.
HRESULT Direct3DDevice8::SetRenderState(D3DRENDERSTATETYPE State, DWORD Value)
{
    Direct3DDevice8LogMethodValue(TRACE, SetRenderState, 2, (State, Value));

    CONST HRESULT result = this->State.Self->SetRenderState(State, Value);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetRenderState, result, 2, (State, Value));
}

// Retrieves a render-state value for a device.
HRESULT Direct3DDevice8::GetRenderState(D3DRENDERSTATETYPE State, DWORD* pValue)
{
    Direct3DDevice8LogMethodValue(TRACE, GetRenderState, 2, (State, pValue));

    CONST HRESULT result = this->State.Self->GetRenderState(State, pValue);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetRenderState, result, 2, (State, pValue));
}

// Signals Microsoft® Direct3D® to begin recording a device-state block.
HRESULT Direct3DDevice8::BeginStateBlock()
{
    Direct3DDevice8LogMethod(TRACE, BeginStateBlock);

    CONST HRESULT result = this->State.Self->BeginStateBlock();

    Direct3DDevice8LogMethodResult(TRACEDEBUGINFO, BeginStateBlock, result);
}

// Signals Microsoft® Direct3D® to stop recording a device-state block and retrieve a handle to the state block.
HRESULT Direct3DDevice8::EndStateBlock(DWORD* pToken)
{
    Direct3DDevice8LogMethodValue(TRACE, EndStateBlock, 1, (pToken));

    CONST HRESULT result = this->State.Self->EndStateBlock(pToken);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, EndStateBlock, result, 1, (pToken));
}

// Applies an existing device-state block to the rendering device.
HRESULT Direct3DDevice8::ApplyStateBlock(DWORD Token)
{
    Direct3DDevice8LogMethodValue(TRACE, ApplyStateBlock, 1, (Token));

    CONST HRESULT result = this->State.Self->ApplyStateBlock(Token);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, ApplyStateBlock, result, 1, (Token));
}

// Updates the values within an existing state block to the values set for the device.
HRESULT Direct3DDevice8::CaptureStateBlock(DWORD Token)
{
    Direct3DDevice8LogMethodValue(TRACE, CaptureStateBlock, 1, (Token));

    CONST HRESULT result = this->State.Self->CaptureStateBlock(Token);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, CaptureStateBlock, result, 1, (Token));
}

// Deletes a previously recorded device-state block.
HRESULT Direct3DDevice8::DeleteStateBlock(DWORD Token)
{
    Direct3DDevice8LogMethodValue(TRACE, DeleteStateBlock, 1, (Token));

    CONST HRESULT result = this->State.Self->DeleteStateBlock(Token);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, DeleteStateBlock, result, 1, (Token));
}

// Creates a new state block that contains the values for all device states, vertex-related states, or pixel-related states.
HRESULT Direct3DDevice8::CreateStateBlock(D3DSTATEBLOCKTYPE Type, DWORD* pToken)
{
    Direct3DDevice8LogMethodValue(TRACE, CreateStateBlock, 2, (Type, pToken));

    CONST HRESULT result = this->State.Self->CreateStateBlock(Type, pToken);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, CreateStateBlock, result, 2, (Type, pToken));
}

// Sets the clip status.
HRESULT Direct3DDevice8::SetClipStatus(CONST D3DCLIPSTATUS8* pClipStatus)
{
    Direct3DDevice8LogMethodValue(TRACE, SetClipStatus, 1, (pClipStatus));

    CONST HRESULT result = this->State.Self->SetClipStatus(pClipStatus);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetClipStatus, result, 1, (pClipStatus));
}

// Retrieves the clip status.
HRESULT Direct3DDevice8::GetClipStatus(D3DCLIPSTATUS8* pClipStatus)
{
    Direct3DDevice8LogMethodValue(TRACE, GetClipStatus, 1, (pClipStatus));

    CONST HRESULT result = this->State.Self->GetClipStatus(pClipStatus);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetClipStatus, result, 1, (pClipStatus));
}

// Retrieves a texture assigned to a stage for a device.
HRESULT Direct3DDevice8::GetTexture(DWORD Stage, LPDIRECT3DBASETEXTURE8* ppTexture)
{
    Direct3DDevice8LogMethodValue(TRACE, GetTexture, 2, (Stage, ppTexture));

    CONST HRESULT result = this->State.Self->GetTexture(Stage, ppTexture);

    if (SUCCEEDED(result)) { *ppTexture = ActivateAgentBase(Direct3DBaseTexture8, *ppTexture); }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetTexture, result, 2, (Stage, ppTexture));
}

// Assigns a texture to a stage for a device.
HRESULT Direct3DDevice8::SetTexture(DWORD Stage, LPDIRECT3DBASETEXTURE8 pTexture)
{
    Direct3DDevice8LogMethodValue(TRACE, SetTexture, 2, (Stage, pTexture));

    AttemptAccessAgentBaseValue(Direct3DBaseTexture8, pTexture);

    CONST HRESULT result = this->State.Self->SetTexture(Stage, pTexture);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetTexture, result, 2, (Stage, ActivateAgent(Direct3DBaseTexture8, pTexture)));
}

// Retrieves a state value for an assigned texture.
HRESULT Direct3DDevice8::GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue)
{
    Direct3DDevice8LogMethodValue(TRACE, GetTextureStageState, 3, (Stage, Type, pValue));

    CONST HRESULT result = this->State.Self->GetTextureStageState(Stage, Type, pValue);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetTextureStageState, result, 3, (Stage, Type, pValue));
}

// Sets the state value for the currently assigned texture.
HRESULT Direct3DDevice8::SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
    Direct3DDevice8LogMethodValue(TRACE, SetTextureStageState, 3, (Stage, Type, Value));

    CONST HRESULT result = this->State.Self->SetTextureStageState(Stage, Type, Value);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetTextureStageState, result, 3, (Stage, Type, Value));
}

// Reports the device's ability to render the current texture-blending operations and arguments in a single pass.
HRESULT Direct3DDevice8::ValidateDevice(DWORD* pNumPasses)
{
    Direct3DDevice8LogMethodValue(TRACE, ValidateDevice, 1, (pNumPasses));

    CONST HRESULT result = this->State.Self->ValidateDevice(pNumPasses);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, ValidateDevice, result, 1, (pNumPasses));
}

// Retrieves information about the rendering device.
HRESULT Direct3DDevice8::GetInfo(DWORD DevInfoID, LPVOID pDevInfoStruct, DWORD DevInfoStructSize)
{
    Direct3DDevice8LogMethodValue(TRACE, GetInfo, 3, (DevInfoID, pDevInfoStruct, DevInfoStructSize));

    CONST HRESULT result = this->State.Self->GetInfo(DevInfoID, pDevInfoStruct, DevInfoStructSize);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetInfo, result, 3, (DevInfoID, pDevInfoStruct, DevInfoStructSize));
}

// Sets palette entries.
HRESULT Direct3DDevice8::SetPaletteEntries(UINT PaletteNumber, CONST PALETTEENTRY* pEntries)
{
    Direct3DDevice8LogMethodValue(TRACE, SetPaletteEntries, 2, (PaletteNumber, pEntries));

    CONST HRESULT result = this->State.Self->SetPaletteEntries(PaletteNumber, pEntries);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetPaletteEntries, result, 2, (PaletteNumber, pEntries));
}

// Retrieves palette entries.
HRESULT Direct3DDevice8::GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY* pEntries)
{
    Direct3DDevice8LogMethodValue(TRACE, GetPaletteEntries, 2, (PaletteNumber, pEntries));

    CONST HRESULT result = this->State.Self->GetPaletteEntries(PaletteNumber, pEntries);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetPaletteEntries, result, 2, (PaletteNumber, pEntries));
}

// Sets the current texture palette.
HRESULT Direct3DDevice8::SetCurrentTexturePalette(UINT PaletteNumber)
{
    Direct3DDevice8LogMethodValue(TRACE, SetCurrentTexturePalette, 1, (PaletteNumber));

    CONST HRESULT result = this->State.Self->SetCurrentTexturePalette(PaletteNumber);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetCurrentTexturePalette, result, 1, (PaletteNumber));
}

// Retrieves the current texture palette.
HRESULT Direct3DDevice8::GetCurrentTexturePalette(UINT* PaletteNumber)
{
    Direct3DDevice8LogMethodValue(TRACE, GetCurrentTexturePalette, 1, (PaletteNumber));

    CONST HRESULT result = this->State.Self->GetCurrentTexturePalette(PaletteNumber);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetCurrentTexturePalette, result, 1, (PaletteNumber));
}

// Renders a sequence of nonindexed, geometric primitives of the specified type from the current set of data input streams.
HRESULT Direct3DDevice8::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
    Direct3DDevice8LogMethodValue(TRACE, DrawPrimitive, 3, (PrimitiveType, StartVertex, PrimitiveCount));

    CONST HRESULT result = this->State.Self->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, DrawPrimitive, result, 3, (PrimitiveType, StartVertex, PrimitiveCount));
}

// Renders the indexed geometric primitive into an array of vertices.
HRESULT Direct3DDevice8::DrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT MinIndex, UINT NumVertices, UINT StartIndex, UINT PrimitiveCount)
{
    Direct3DDevice8LogMethodValue(TRACE, DrawIndexedPrimitive, 5, (PrimitiveType, MinIndex, NumVertices, StartIndex, PrimitiveCount));

    CONST HRESULT result = this->State.Self->DrawIndexedPrimitive(PrimitiveType, MinIndex, NumVertices, StartIndex, PrimitiveCount);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, DrawIndexedPrimitive, result, 5, (PrimitiveType, MinIndex, NumVertices, StartIndex, PrimitiveCount));
}

// Renders data specified by a user memory pointer as a sequence of geometric primitives of the specified type.
HRESULT Direct3DDevice8::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, LPCVOID pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    Direct3DDevice8LogMethodValue(TRACE, DrawPrimitiveUP, 4, (PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride));

    CONST HRESULT result = this->State.Self->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, DrawPrimitiveUP, result, 4, (PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride));
}

// Renders the specified geometric primitive with data specified by a user memory pointer.
HRESULT Direct3DDevice8::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertexIndices, UINT PrimitiveCount, LPCVOID pIndexData, D3DFORMAT IndexDataFormat, LPCVOID pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    Direct3DDevice8LogMethodValue(TRACE, DrawIndexedPrimitiveUP, 8, (PrimitiveType, MinVertexIndex, NumVertexIndices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride));

    CONST HRESULT result = this->State.Self->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertexIndices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, DrawIndexedPrimitiveUP, result, 8, (PrimitiveType, MinVertexIndex, NumVertexIndices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride));
}

// Applies the vertex processing defined by the vertex shader to the set of input data streams, generating a single stream of interleaved vertex data to the destination vertex buffer. 
HRESULT Direct3DDevice8::ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, LPDIRECT3DVERTEXBUFFER8 pDestBuffer, DWORD Flags)
{
    Direct3DDevice8LogMethodValue(TRACE, ProcessVertices, 5, (SrcStartIndex, DestIndex, VertexCount, pDestBuffer, Flags));

    AttemptAccessAgentValue(Direct3DVertexBuffer8, pDestBuffer);

    CONST HRESULT result = this->State.Self->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, Flags);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, ProcessVertices, result, 5, (SrcStartIndex, DestIndex, VertexCount, ActivateAgent(Direct3DVertexBuffer8, pDestBuffer), Flags));
}

// Creates a vertex shader.
HRESULT Direct3DDevice8::CreateVertexShader(CONST DWORD* pDeclaration, CONST DWORD* pFunction, DWORD* pHandle, DWORD Usage)
{
    Direct3DDevice8LogMethodValue(TRACE, CreateVertexShader, 4, (pDeclaration, pFunction, pHandle, Usage));

    CONST HRESULT result = this->State.Self->CreateVertexShader(pDeclaration, pFunction, pHandle, Usage);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, CreateVertexShader, result, 4, (pDeclaration, pFunction, pHandle, Usage));
}

// Sets the current vertex shader to a previously created vertex shader or to a flexible vertex format (FVF) fixed function shader.
HRESULT Direct3DDevice8::SetVertexShader(DWORD Handle)
{
    Direct3DDevice8LogMethodValue(TRACE, SetVertexShader, 1, (Handle));

    CONST HRESULT result = this->State.Self->SetVertexShader(Handle);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetVertexShader, result, 1, (Handle));
}

// Retrieves the currently set vertex shader.
HRESULT Direct3DDevice8::GetVertexShader(DWORD* pHandle)
{
    Direct3DDevice8LogMethodValue(TRACE, GetVertexShader, 1, (pHandle));

    CONST HRESULT result = this->State.Self->GetVertexShader(pHandle);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetVertexShader, result, 1, (pHandle));
}

// Deletes the vertex shader referred to by the specified handle and frees up the associated resources.
HRESULT Direct3DDevice8::DeleteVertexShader(DWORD Handle)
{
    Direct3DDevice8LogMethodValue(TRACE, DeleteVertexShader, 1, (Handle));

    CONST HRESULT result = this->State.Self->DeleteVertexShader(Handle);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, DeleteVertexShader, result, 1, (Handle));
}

// Sets values in the vertex constant array.
HRESULT Direct3DDevice8::SetVertexShaderConstant(DWORD Register, LPCVOID pConstantData, DWORD ConstantCount)
{
    Direct3DDevice8LogMethodValue(TRACE, SetVertexShaderConstant, 3, (Register, pConstantData, ConstantCount));

    CONST HRESULT result = this->State.Self->SetVertexShaderConstant(Register, pConstantData, ConstantCount);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetVertexShaderConstant, result, 3, (Register, pConstantData, ConstantCount));
}

// Retrieves the values in the vertex constant array.
HRESULT Direct3DDevice8::GetVertexShaderConstant(DWORD Register, LPVOID pConstantData, DWORD ConstantCount)
{
    Direct3DDevice8LogMethodValue(TRACE, GetVertexShaderConstant, 3, (Register, pConstantData, ConstantCount));

    CONST HRESULT result = this->State.Self->GetVertexShaderConstant(Register, pConstantData, ConstantCount);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetVertexShaderConstant, result, 3, (Register, pConstantData, ConstantCount));
}

// Retrieves the vertex shader declaration token array.
HRESULT Direct3DDevice8::GetVertexShaderDeclaration(DWORD Handle, LPVOID pData, DWORD* pSizeOfData)
{
    Direct3DDevice8LogMethodValue(TRACE, GetVertexShaderDeclaration, 3, (Handle, pData, pSizeOfData));

    CONST HRESULT result = this->State.Self->GetVertexShaderDeclaration(Handle, pData, pSizeOfData);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetVertexShaderDeclaration, result, 3, (Handle, pData, pSizeOfData));
}

// Retrieves the vertex shader function.
HRESULT Direct3DDevice8::GetVertexShaderFunction(DWORD Handle, LPVOID pData, DWORD* pSizeOfData)
{
    Direct3DDevice8LogMethodValue(TRACE, GetVertexShaderFunction, 3, (Handle, pData, pSizeOfData));

    CONST HRESULT result = this->State.Self->GetVertexShaderFunction(Handle, pData, pSizeOfData);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetVertexShaderFunction, result, 3, (Handle, pData, pSizeOfData));
}

// Binds a vertex buffer to a device data stream.
HRESULT Direct3DDevice8::SetStreamSource(UINT StreamNumber, LPDIRECT3DVERTEXBUFFER8 pStreamData, UINT Stride)
{
    Direct3DDevice8LogMethodValue(TRACE, SetStreamSource, 3, (StreamNumber, pStreamData, Stride));

    AttemptAccessAgentValue(Direct3DVertexBuffer8, pStreamData);

    CONST HRESULT result = this->State.Self->SetStreamSource(StreamNumber, pStreamData, Stride);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetStreamSource, result, 3, (StreamNumber, ActivateAgent(Direct3DVertexBuffer8, pStreamData), Stride));
}

// Retrieves a vertex buffer bound to the specified data stream.
HRESULT Direct3DDevice8::GetStreamSource(UINT StreamNumber, LPDIRECT3DVERTEXBUFFER8* ppStreamData, UINT* pStride)
{
    Direct3DDevice8LogMethodValue(TRACE, GetStreamSource, 3, (StreamNumber, ppStreamData, pStride));

    CONST HRESULT result = this->State.Self->GetStreamSource(StreamNumber, ppStreamData, pStride);

    if (SUCCEEDED(result)) { *ppStreamData = ActivateAgent(Direct3DVertexBuffer8, *ppStreamData); }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetStreamSource, result, 3, (StreamNumber, ppStreamData, pStride));
}

// Sets index data.
HRESULT Direct3DDevice8::SetIndices(LPDIRECT3DINDEXBUFFER8 pIndexData, UINT BaseVertexIndex)
{
    Direct3DDevice8LogMethodValue(TRACE, SetIndices, 2, (pIndexData, BaseVertexIndex));

    AttemptAccessAgentValue(Direct3DIndexBuffer8, pIndexData);

    CONST HRESULT result = this->State.Self->SetIndices(pIndexData, BaseVertexIndex);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetIndices, result, 2, (ActivateAgent(Direct3DIndexBuffer8, pIndexData), BaseVertexIndex));
}

// Retrieves index data.
HRESULT Direct3DDevice8::GetIndices(LPDIRECT3DINDEXBUFFER8* ppIndexData, UINT* pBaseVertexIndex)
{
    Direct3DDevice8LogMethodValue(TRACE, GetIndices, 2, (ppIndexData, pBaseVertexIndex));

    CONST HRESULT result = this->State.Self->GetIndices(ppIndexData, pBaseVertexIndex);

    if (SUCCEEDED(result)) { *ppIndexData = ActivateAgent(Direct3DIndexBuffer8, *ppIndexData); }

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetIndices, result, 2, (ppIndexData, pBaseVertexIndex));
}

// Creates a pixel shader.
HRESULT Direct3DDevice8::CreatePixelShader(CONST DWORD* pFunction, DWORD* pHandle)
{
    Direct3DDevice8LogMethodValue(TRACE, CreatePixelShader, 2, (pFunction, pHandle));

    CONST HRESULT result = this->State.Self->CreatePixelShader(pFunction, pHandle);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, CreatePixelShader, result, 2, (pFunction, pHandle));
}

// Sets the current pixel shader to a previously created pixel shader.
HRESULT Direct3DDevice8::SetPixelShader(DWORD Handle)
{
    Direct3DDevice8LogMethodValue(TRACE, SetPixelShader, 1, (Handle));

    CONST HRESULT result = this->State.Self->SetPixelShader(Handle);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetPixelShader, result, 1, (Handle));
}

// Retrieves the currently set pixel shader.
HRESULT Direct3DDevice8::GetPixelShader(DWORD* pHandle)
{
    Direct3DDevice8LogMethodValue(TRACE, GetPixelShader, 1, (pHandle));

    CONST HRESULT result = this->State.Self->GetPixelShader(pHandle);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetPixelShader, result, 1, (pHandle));
}

// Deletes the pixel shader referred to by the specified handle.
HRESULT Direct3DDevice8::DeletePixelShader(DWORD Handle)
{
    Direct3DDevice8LogMethodValue(TRACE, DeletePixelShader, 1, (Handle));

    CONST HRESULT result = this->State.Self->DeletePixelShader(Handle);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, DeletePixelShader, result, 1, (Handle));
}

// Sets the values in the pixel constant array.
HRESULT Direct3DDevice8::SetPixelShaderConstant(DWORD Register, LPCVOID pConstantData, DWORD ConstantCount)
{
    Direct3DDevice8LogMethodValue(TRACE, SetPixelShaderConstant, 3, (Register, pConstantData, ConstantCount));

    CONST HRESULT result = this->State.Self->SetPixelShaderConstant(Register, pConstantData, ConstantCount);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, SetPixelShaderConstant, result, 3, (Register, pConstantData, ConstantCount));
}

// Retrieves the values in the pixel constant array.
HRESULT Direct3DDevice8::GetPixelShaderConstant(DWORD Register, LPVOID pConstantData, DWORD ConstantCount)
{
    Direct3DDevice8LogMethodValue(TRACE, GetPixelShaderConstant, 3, (Register, pConstantData, ConstantCount));

    CONST HRESULT result = this->State.Self->GetPixelShaderConstant(Register, pConstantData, ConstantCount);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetPixelShaderConstant, result, 3, (Register, pConstantData, ConstantCount));
}

// Retrieves the pixel shader function.
HRESULT Direct3DDevice8::GetPixelShaderFunction(DWORD Handle, LPVOID pData, DWORD* pSizeOfData)
{
    Direct3DDevice8LogMethodValue(TRACE, GetPixelShaderFunction, 3, (Handle, pData, pSizeOfData));

    CONST HRESULT result = this->State.Self->GetPixelShaderFunction(Handle, pData, pSizeOfData);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, GetPixelShaderFunction, result, 3, (Handle, pData, pSizeOfData));
}

// Draws a rectangular high-order patch using the currently set streams.
HRESULT Direct3DDevice8::DrawRectPatch(UINT Handle, CONST FLOAT* pNumSegs, CONST D3DRECTPATCH_INFO* pRectPatchInfo)
{
    Direct3DDevice8LogMethodValue(TRACE, DrawRectPatch, 3, (Handle, pNumSegs, pRectPatchInfo));

    CONST HRESULT result = this->State.Self->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, DrawRectPatch, result, 3, (Handle, pNumSegs, pRectPatchInfo));
}

// Draws a triangular high-order patch using the currently set streams.
HRESULT Direct3DDevice8::DrawTriPatch(UINT Handle, CONST FLOAT* pNumSegs, CONST D3DTRIPATCH_INFO* pTriPatchInfo)
{
    Direct3DDevice8LogMethodValue(TRACE, DrawTriPatch, 3, (Handle, pNumSegs, pTriPatchInfo));

    CONST HRESULT result = this->State.Self->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, DrawTriPatch, result, 3, (Handle, pNumSegs, pTriPatchInfo));
}

// Frees a cached high-order patch.
HRESULT Direct3DDevice8::DeletePatch(UINT Handle)
{
    Direct3DDevice8LogMethodValue(TRACE, DeletePatch, 1, (Handle));

    CONST HRESULT result = this->State.Self->DeletePatch(Handle);

    Direct3DDevice8LogMethodResultValue(TRACEDEBUGINFO, DeletePatch, result, 1, (Handle));
}