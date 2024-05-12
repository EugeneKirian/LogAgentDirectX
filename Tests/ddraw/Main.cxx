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
#include "Direct3DTexture.hxx"
#include "Direct3DVertexBuffer.hxx"
#include "Direct3DViewport.hxx"
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

#include "DllGetClassObject.hxx"

#include "Window.hxx"

#include <stdio.h>

#define Invoke(X)                 \
    printf(#X ## "\r\n");         \
    X(module)

VOID ExecuteDirect3D(LPMODULE module)
{
    Invoke(DirectDrawDirect3D);
    Invoke(DirectDraw2Direct3D);
    Invoke(DirectDraw4Direct3D);
    Invoke(DirectDraw7Direct3D);

    Invoke(DirectDrawDirect3DQueryInterfaceIUnknown);
    Invoke(DirectDraw2Direct3DQueryInterfaceIUnknown);
    Invoke(DirectDraw4Direct3DQueryInterfaceIUnknown);
    Invoke(DirectDraw7Direct3DQueryInterfaceIUnknown);
    Invoke(DirectDraw7Direct3DQueryInterfaceIUnknown);

    Invoke(DirectDrawDirect3DQueryInterfaceAll);
    Invoke(DirectDraw2Direct3DQueryInterfaceAll);
    Invoke(DirectDraw4Direct3DQueryInterfaceAll);
    Invoke(DirectDraw7Direct3DQueryInterfaceAll);
}

VOID ExecuteDirect3D2(LPMODULE module)
{
    Invoke(DirectDrawDirect3D2QueryInterfaceAll);
    Invoke(DirectDraw2Direct3D2QueryInterfaceAll);
    Invoke(DirectDraw4Direct3D2QueryInterfaceAll);
    Invoke(DirectDraw7Direct3D2QueryInterfaceAll);
}

VOID ExecuteDirect3D3(LPMODULE module)
{
    Invoke(DirectDrawDirect3D3QueryInterfaceAll);
    Invoke(DirectDraw2Direct3D3QueryInterfaceAll);
    Invoke(DirectDraw4Direct3D3QueryInterfaceAll);
    Invoke(DirectDraw7Direct3D3QueryInterfaceAll);
}

VOID ExecuteDirect3D7(LPMODULE module)
{
    Invoke(DirectDrawDirect3D7QueryInterfaceAll);
    Invoke(DirectDraw2Direct3D7QueryInterfaceAll);
    Invoke(DirectDraw4Direct3D7QueryInterfaceAll);
    Invoke(DirectDraw7Direct3D7QueryInterfaceAll);
}

VOID ExecuteDirect3DDevice(LPMODULE module)
{
    Invoke(DirectDrawCreateDirect3DDevice);
    Invoke(DirectDraw2CreateDirect3DDevice);
    Invoke(DirectDraw4CreateDirect3DDevice);
    Invoke(DirectDraw7CreateDirect3DDevice);

    Invoke(DirectDrawDirect3DDeviceQueryInterfaceIUnknown);
    Invoke(DirectDraw2Direct3DDeviceQueryInterfaceIUnknown);
    Invoke(DirectDraw4Direct3DDeviceQueryInterfaceIUnknown);

    Invoke(DirectDrawDirect3DDeviceQueryInterfaceAll);
    Invoke(DirectDraw2Direct3DDeviceQueryInterfaceAll);
    Invoke(DirectDraw4Direct3DDeviceQueryInterfaceAll);

    Invoke(DirectDrawDirect3DDeviceUnknownQueryAll);
}

VOID ExecuteDirect3DDevice2(LPMODULE module)
{
    Invoke(DirectDrawCreateDirect3DDevice2);
    Invoke(DirectDraw2CreateDirect3DDevice2);
    Invoke(DirectDraw4CreateDirect3DDevice2);
    Invoke(DirectDraw7CreateDirect3DDevice2);

    Invoke(DirectDrawCreateDirect3DDevice2QueryInterfaceIUnknown);
    Invoke(DirectDraw2CreateDirect3DDevice2QueryInterfaceIUnknown);
    Invoke(DirectDraw4CreateDirect3DDevice2QueryInterfaceIUnknown);

    Invoke(DirectDrawCreateDirect3DDevice2QueryInterfaceAll);
    Invoke(DirectDraw2CreateDirect3DDevice2QueryInterfaceAll);
    Invoke(DirectDraw4CreateDirect3DDevice2QueryInterfaceAll);

    Invoke(DirectDrawDirect3DDevice2UnknownQueryAll);
}

VOID ExecuteDirect3DDevice3(LPMODULE module)
{
    Invoke(DirectDrawCreateDirect3DDevice3);
    Invoke(DirectDraw2CreateDirect3DDevice3);
    Invoke(DirectDraw4CreateDirect3DDevice3);
    Invoke(DirectDraw7CreateDirect3DDevice3);

    Invoke(DirectDrawCreateDirect3DDevice3QueryInterfaceIUnknown);
    Invoke(DirectDraw2CreateDirect3DDevice3QueryInterfaceIUnknown);
    Invoke(DirectDraw4CreateDirect3DDevice3QueryInterfaceIUnknown);

    Invoke(DirectDrawCreateDirect3DDevice3QueryInterfaceAll);
    Invoke(DirectDraw2CreateDirect3DDevice3QueryInterfaceAll);
    Invoke(DirectDraw4CreateDirect3DDevice3QueryInterfaceAll);

    Invoke(DirectDrawDirect3DDevice3UnknownQueryAll);
    Invoke(DirectDraw2Direct3DDevice3UnknownQueryAll);
    Invoke(DirectDraw4Direct3DDevice3UnknownQueryAll);
}

VOID ExecuteDirect3DDevice7(LPMODULE module)
{
    Invoke(DirectDrawCreateDirect3DDevice7);
    Invoke(DirectDraw2CreateDirect3DDevice7);
    Invoke(DirectDraw4CreateDirect3DDevice7);
    Invoke(DirectDraw7CreateDirect3DDevice7);

    Invoke(DirectDraw7CreateDirect3DDevice7QueryInterfaceIUnknown);

    Invoke(DirectDraw7CreateDirect3DDevice7QueryInterfaceAll);

    Invoke(DirectDraw7Direct3DDevice7UnknownQueryAll);
}

VOID ExecuteDirect3DExecuteBuffer(LPMODULE module)
{
    Invoke(DirectDrawCreateDirect3DExecuteBuffer);

    Invoke(DirectDrawDirect3DExecuteBufferQueryInterfaceIUnknown);

    Invoke(DirectDrawDirect3DExecuteBufferQueryInterfaceAll);
}

VOID ExecuteDirect3DLight(LPMODULE module)
{
    Invoke(DirectDrawDirect3DCreateLight);
    Invoke(DirectDraw2Direct3DCreateLight);
    Invoke(DirectDraw4Direct3DCreateLight);
    Invoke(DirectDraw7Direct3DCreateLight);
    Invoke(DirectDrawDirect3DLightQueryInterfaceIUnknown);
    Invoke(DirectDraw2Direct3DLightQueryInterfaceIUnknown);
    Invoke(DirectDraw4Direct3DLightQueryInterfaceIUnknown);
    Invoke(DirectDrawDirect3DLightQueryInterfaceAll);
    Invoke(DirectDraw2Direct3DLightQueryInterfaceAll);
    Invoke(DirectDraw4Direct3DLightQueryInterfaceAll);
}

VOID ExecuteDirect3DMaterial(LPMODULE module)
{
    Invoke(DirectDrawCreateMaterial);
    Invoke(DirectDraw2CreateMaterial);
    Invoke(DirectDraw4CreateMaterial);
    Invoke(DirectDraw7CreateMaterial);
    Invoke(DirectDrawCreateMaterialQueryInterfaceIUnknown);
    Invoke(DirectDraw2CreateMaterialQueryInterfaceIUnknown);
    Invoke(DirectDraw4CreateMaterialQueryInterfaceIUnknown);
    Invoke(DirectDrawCreateMaterialQueryInterfaceAll);
    Invoke(DirectDraw2CreateMaterialQueryInterfaceAll);
    Invoke(DirectDraw4CreateMaterialQueryInterfaceAll);
}

VOID ExecuteDirect3DTexture(LPMODULE module)
{
    Invoke(DirectDrawCreateSurfaceTexture);
    Invoke(DirectDraw2CreateSurfaceTexture);
    Invoke(DirectDraw4CreateSurfaceTexture);
    Invoke(DirectDraw7CreateSurfaceTexture);
    Invoke(DirectDrawSurfaceTextureQueryInterfaceIUnknown);
    Invoke(DirectDraw2SurfaceTextureQueryInterfaceIUnknown);
    Invoke(DirectDraw4SurfaceTextureQueryInterfaceIUnknown);
    Invoke(DirectDrawSurfaceTextureQueryInterfaceAll);
    Invoke(DirectDraw2SurfaceTextureQueryInterfaceAll);
    Invoke(DirectDraw4SurfaceTextureQueryInterfaceAll);
}

VOID ExecuteDirect3DVertexBuffer(LPMODULE module)
{
    Invoke(DirectDrawVertexBuffer);
    Invoke(DirectDraw2VertexBuffer);
    Invoke(DirectDraw4VertexBuffer);
    Invoke(DirectDraw7VertexBuffer);
    Invoke(DirectDrawVertexBufferQueryInterfaceIUnknown);
    Invoke(DirectDraw2VertexBufferQueryInterfaceIUnknown);
    Invoke(DirectDraw4VertexBufferQueryInterfaceIUnknown);
    Invoke(DirectDraw7VertexBufferQueryInterfaceIUnknown);
    Invoke(DirectDrawVertexBufferQueryInterfaceAll);
    Invoke(DirectDraw2VertexBufferQueryInterfaceAll);
    Invoke(DirectDraw4VertexBufferQueryInterfaceAll);
    Invoke(DirectDraw7VertexBufferQueryInterfaceAll);
}

VOID ExecuteDirect3DViewport(LPMODULE module)
{
    Invoke(DirectDrawCreateViewport);
    Invoke(DirectDraw2CreateViewport);
    Invoke(DirectDraw4CreateViewport);
    Invoke(DirectDraw7CreateViewport);
    Invoke(DirectDrawCreateViewportQueryInterfaceIUnknown);
    Invoke(DirectDraw2CreateViewportQueryInterfaceIUnknown);
    Invoke(DirectDraw4CreateViewportQueryInterfaceIUnknown);
    Invoke(DirectDrawCreateViewportQueryInterfaceAll);
    Invoke(DirectDraw2CreateViewportQueryInterfaceAll);
    Invoke(DirectDraw4CreateViewportQueryInterfaceAll);
}

VOID ExecuteDirectDraw(LPMODULE module)
{
    Invoke(DirectDrawCreate);
    Invoke(DirectDrawQueryInterfaceIUnknown);
    Invoke(DirectDrawQueryInterfaceIUnknownIDirectDraw);
    Invoke(DirectDrawQueryInterfaceIDirectDraw);
    Invoke(DirectDrawQueryInterfaceIDirectDraw2);
    Invoke(DirectDrawQueryInterfaceIDirectDraw4);
    Invoke(DirectDrawQueryInterfaceIDirectDraw7);
    Invoke(DirectDrawQueryInterfaceAll);
}

VOID ExecuteDirectDraw2(LPMODULE module)
{
    Invoke(DirectDraw2Create);
    Invoke(DirectDraw2QueryInterfaceIUnknown);
    Invoke(DirectDraw2QueryInterfaceIUnknownIDirectDraw);
    Invoke(DirectDraw2QueryInterfaceIDirectDraw);
    Invoke(DirectDraw2QueryInterfaceIDirectDraw2);
    Invoke(DirectDraw2QueryInterfaceIDirectDraw4);
    Invoke(DirectDraw2QueryInterfaceIDirectDraw7);
    Invoke(DirectDraw2QueryInterfaceAll);
    Invoke(DirectDraw2QueryInterfaceIUnknownIDirectDraw2);
}

VOID ExecuteDirectDraw4(LPMODULE module)
{
    Invoke(DirectDraw4Create);
    Invoke(DirectDraw4QueryInterfaceIUnknown);
    Invoke(DirectDraw4QueryInterfaceIUnknownIDirectDraw);
    Invoke(DirectDraw4QueryInterfaceIDirectDraw);
    Invoke(DirectDraw4QueryInterfaceIDirectDraw2);
    Invoke(DirectDraw4QueryInterfaceIDirectDraw4);
    Invoke(DirectDraw4QueryInterfaceIDirectDraw7);
    Invoke(DirectDraw4QueryInterfaceAll);
    Invoke(DirectDraw4QueryInterfaceIUnknownIDirectDraw4);
}

VOID ExecuteDirectDraw7(LPMODULE module)
{
    Invoke(DirectDraw7Create);
    Invoke(DirectDraw7QueryInterfaceIUnknown);
    Invoke(DirectDraw7QueryInterfaceIUnknownIDirectDraw);
    Invoke(DirectDraw7QueryInterfaceIDirectDraw);
    Invoke(DirectDraw7QueryInterfaceIDirectDraw2);
    Invoke(DirectDraw7QueryInterfaceIDirectDraw4);
    Invoke(DirectDraw7QueryInterfaceIDirectDraw7);
    Invoke(DirectDraw7QueryInterfaceAll);
    Invoke(DirectDraw7QueryInterfaceIUnknownIDirectDraw7);
}

VOID ExecuteDirectDrawClipper(LPMODULE module)
{
    Invoke(DirectDrawClipperCreate);
    Invoke(DirectDrawCreateClipper);
    Invoke(DirectDraw2CreateClipper);
    Invoke(DirectDraw4CreateClipper);
    Invoke(DirectDraw7CreateClipper);
    Invoke(DirectDrawClipperQueryInterfaceIUnknown);
    Invoke(DirectDraw2ClipperQueryInterfaceIUnknown);
    Invoke(DirectDraw4ClipperQueryInterfaceIUnknown);
    Invoke(DirectDraw7ClipperQueryInterfaceIUnknown);
    Invoke(DirectDrawClipperQueryInterfaceClipper);
    Invoke(DirectDraw2ClipperQueryInterfaceClipper);
    Invoke(DirectDraw4ClipperQueryInterfaceClipper);
    Invoke(DirectDraw7ClipperQueryInterfaceClipper);
    Invoke(DirectDrawCreateClipperQueryInterfaceAll);
    Invoke(DirectDrawClipperQueryInterfaceAll);
    Invoke(DirectDraw2ClipperQueryInterfaceAll);
    Invoke(DirectDraw4ClipperQueryInterfaceAll);
    Invoke(DirectDraw7ClipperQueryInterfaceAll);
}

VOID ExecuteDirectDrawColorControl(LPMODULE module)
{
    Invoke(DirectDrawColorControl);
}

VOID ExecuteDirectDrawGammaControl(LPMODULE module)
{
    Invoke(DirectDrawCreateGammaControl);
    Invoke(DirectDraw2CreateGammaControl);
    Invoke(DirectDraw4CreateGammaControl);
    Invoke(DirectDraw7CreateGammaControl);
    Invoke(DirectDrawGammaControlQueryInterfaceIUnknown);
    Invoke(DirectDraw2GammaControlQueryInterfaceIUnknown);
    Invoke(DirectDraw4GammaControlQueryInterfaceIUnknown);
    Invoke(DirectDraw7GammaControlQueryInterfaceIUnknown);
    Invoke(DirectDrawGammaControlQueryInterfaceAll);
    Invoke(DirectDraw2GammaControlQueryInterfaceAll);
    Invoke(DirectDraw4GammaControlQueryInterfaceAll);
    Invoke(DirectDraw7GammaControlQueryInterfaceAll);
}

VOID ExecuteDirectDrawPalette(LPMODULE module)
{
    Invoke(DirectDrawCreatePalette);
    Invoke(DirectDraw2CreatePalette);
    Invoke(DirectDraw4CreatePalette);
    Invoke(DirectDraw7CreatePalette);
    Invoke(DirectDrawPaletteQueryInterfaceIUnknown);
    Invoke(DirectDraw2PaletteQueryInterfaceIUnknown);
    Invoke(DirectDraw4PaletteQueryInterfaceIUnknown);
    Invoke(DirectDraw7PaletteQueryInterfaceIUnknown);
    Invoke(DirectDrawPaletteQueryInterfacePalette);
    Invoke(DirectDraw2PaletteQueryInterfacePalette);
    Invoke(DirectDraw4PaletteQueryInterfacePalette);
    Invoke(DirectDraw7PaletteQueryInterfacePalette);
    Invoke(DirectDrawPaletteQueryInterfaceAll);
    Invoke(DirectDraw2PaletteQueryInterfaceAll);
    Invoke(DirectDraw4PaletteQueryInterfaceAll);
    Invoke(DirectDraw7PaletteQueryInterfaceAll);
}

VOID ExecuteDirectDrawSurface(LPMODULE module)
{
    Invoke(DirectDrawCreateSurface);
    Invoke(DirectDraw2CreateSurface);
    Invoke(DirectDraw4CreateSurface);
    Invoke(DirectDraw7CreateSurface);
    Invoke(DirectDrawSurfaceQueryInterfaceIUnknown);
    Invoke(DirectDraw2SurfaceQueryInterfaceIUnknown);
    Invoke(DirectDraw4SurfaceQueryInterfaceIUnknown);
    Invoke(DirectDraw7SurfaceQueryInterfaceIUnknown);
    Invoke(DirectDrawSurfaceQueryInterfaceAll);
    Invoke(DirectDraw2SurfaceQueryInterfaceAll);
    Invoke(DirectDraw4SurfaceQueryInterfaceAll);
    Invoke(DirectDraw7SurfaceQueryInterfaceAll);
}

VOID ExecuteDirectDrawSurface2(LPMODULE module)
{
    Invoke(DirectDrawCreateSurface2);
    Invoke(DirectDraw2CreateSurface2);
    Invoke(DirectDraw4CreateSurface2);
    Invoke(DirectDraw7CreateSurface2);
    Invoke(DirectDrawSurface2QueryInterfaceIUnknown);
    Invoke(DirectDraw2Surface2QueryInterfaceIUnknown);
    Invoke(DirectDraw4Surface2QueryInterfaceIUnknown);
    Invoke(DirectDraw7Surface2QueryInterfaceIUnknown);
    Invoke(DirectDrawSurface2QueryInterfaceAll);
    Invoke(DirectDraw2Surface2QueryInterfaceAll);
    Invoke(DirectDraw4Surface2QueryInterfaceAll);
    Invoke(DirectDraw7Surface2QueryInterfaceAll);
}

VOID ExecuteDirectDrawSurface3(LPMODULE module)
{
    Invoke(DirectDrawCreateSurface3);
    Invoke(DirectDraw2CreateSurface3);
    Invoke(DirectDraw4CreateSurface3);
    Invoke(DirectDraw7CreateSurface3);
    Invoke(DirectDrawSurface3QueryInterfaceIUnknown);
    Invoke(DirectDraw2Surface3QueryInterfaceIUnknown);
    Invoke(DirectDraw4Surface3QueryInterfaceIUnknown);
    Invoke(DirectDraw7Surface3QueryInterfaceIUnknown);
    Invoke(DirectDrawSurface3QueryInterfaceAll);
    Invoke(DirectDraw2Surface3QueryInterfaceAll);
    Invoke(DirectDraw4Surface3QueryInterfaceAll);
    Invoke(DirectDraw7Surface3QueryInterfaceAll);
}

VOID ExecuteDirectDrawSurface4(LPMODULE module)
{
    Invoke(DirectDrawCreateSurface4);
    Invoke(DirectDraw2CreateSurface4);
    Invoke(DirectDraw4CreateSurface4);
    Invoke(DirectDraw7CreateSurface4);
    Invoke(DirectDrawSurface4QueryInterfaceIUnknown);
    Invoke(DirectDraw2Surface4QueryInterfaceIUnknown);
    Invoke(DirectDraw4Surface4QueryInterfaceIUnknown);
    Invoke(DirectDraw7Surface4QueryInterfaceIUnknown);
    Invoke(DirectDrawSurface4QueryInterfaceAll);
    Invoke(DirectDraw2Surface4QueryInterfaceAll);
    Invoke(DirectDraw4Surface4QueryInterfaceAll);
    Invoke(DirectDraw7Surface4QueryInterfaceAll);
}

VOID ExecuteDirectDrawSurface7(LPMODULE module)
{
    Invoke(DirectDrawCreateSurface7);
    Invoke(DirectDraw2CreateSurface7);
    Invoke(DirectDraw4CreateSurface7);
    Invoke(DirectDraw7CreateSurface7);
    Invoke(DirectDrawSurface7QueryInterfaceIUnknown);
    Invoke(DirectDraw2Surface7QueryInterfaceIUnknown);
    Invoke(DirectDraw4Surface7QueryInterfaceIUnknown);
    Invoke(DirectDraw7Surface7QueryInterfaceIUnknown);
    Invoke(DirectDrawSurface7QueryInterfaceAll);
    Invoke(DirectDraw2Surface7QueryInterfaceAll);
    Invoke(DirectDraw4Surface7QueryInterfaceAll);
    Invoke(DirectDraw7Surface7QueryInterfaceAll);
}

VOID ExecuteDirectDrawVideoPort(LPMODULE module)
{
    Invoke(DirectDrawCreateVideoPort);
    Invoke(DirectDraw2CreateVideoPort);
    Invoke(DirectDraw4CreateVideoPort);
    Invoke(DirectDraw7CreateVideoPort);
}

VOID ExecuteDirectDrawVideoPortContainer(LPMODULE module)
{
    Invoke(DirectDrawCreateVideoPortContainer);
    Invoke(DirectDraw2CreateVideoPortContainer);
    Invoke(DirectDraw4CreateVideoPortContainer);
    Invoke(DirectDraw7CreateVideoPortContainer);
    Invoke(DirectDrawVideoPortContainerQueryInterfaceIUnknown);
    Invoke(DirectDraw2VideoPortContainerQueryInterfaceIUnknown);
    Invoke(DirectDraw4VideoPortContainerQueryInterfaceIUnknown);
    Invoke(DirectDraw7VideoPortContainerQueryInterfaceIUnknown);
    Invoke(DirectDrawVideoPortContainerQueryInterfaceVideoPortContainer);
    Invoke(DirectDraw2VideoPortContainerQueryInterfaceVideoPortContainer);
    Invoke(DirectDraw4VideoPortContainerQueryInterfaceVideoPortContainer);
    Invoke(DirectDraw7VideoPortContainerQueryInterfaceVideoPortContainer);
    Invoke(DirectDrawVideoPortContainerQueryInterfaceAll);
    Invoke(DirectDraw2VideoPortContainerQueryInterfaceAll);
    Invoke(DirectDraw4VideoPortContainerQueryInterfaceAll);
    Invoke(DirectDraw7VideoPortContainerQueryInterfaceAll);
}

VOID ExecuteDllGetClassObject(LPMODULE module)
{
    Invoke(DllGetClassObject);
}

VOID Execute(LPMODULE module)
{
    Invoke(ExecuteDirect3D);
    Invoke(ExecuteDirect3D2);
    Invoke(ExecuteDirect3D3);
    Invoke(ExecuteDirect3D7);
    Invoke(ExecuteDirect3DDevice);
    Invoke(ExecuteDirect3DDevice2);
    Invoke(ExecuteDirect3DDevice3);
    Invoke(ExecuteDirect3DDevice7);
    Invoke(ExecuteDirect3DExecuteBuffer);
    Invoke(ExecuteDirect3DLight);
    Invoke(ExecuteDirect3DMaterial);
    Invoke(ExecuteDirect3DTexture);
    Invoke(ExecuteDirect3DVertexBuffer);
    Invoke(ExecuteDirect3DViewport);
    Invoke(ExecuteDirectDraw);
    Invoke(ExecuteDirectDraw2);
    Invoke(ExecuteDirectDraw4);
    Invoke(ExecuteDirectDraw7);
    Invoke(ExecuteDirectDrawClipper);
    Invoke(ExecuteDirectDrawColorControl);
    Invoke(ExecuteDirectDrawGammaControl);
    Invoke(ExecuteDirectDrawPalette);
    Invoke(ExecuteDirectDrawSurface);
    Invoke(ExecuteDirectDrawSurface2);
    Invoke(ExecuteDirectDrawSurface3);
    Invoke(ExecuteDirectDrawSurface4);
    Invoke(ExecuteDirectDrawSurface7);
    Invoke(ExecuteDirectDrawVideoPort);
    Invoke(ExecuteDirectDrawVideoPortContainer);

    Invoke(ExecuteDllGetClassObject);
}

BOOL AcquirePath(LPSTR lpBuffer, LPCSTR lpPath, const UINT uSize)
{
    CHAR path[MAX_PATH];
    ZeroMemory(path, MAX_PATH);

    if (PathCombineA(path, lpPath, DIRECT_DRAW_LIBRARY_NAME) == NULL) { return FALSE; }

    return strncpy_s(lpBuffer, uSize, path, MAX_PATH) == 0;
}

BOOL AcquireOriginalPath(LPSTR lpBuffer, const UINT uSize)
{
    if (lpBuffer == NULL) { return FALSE; }

    CHAR path[MAX_PATH];
    ZeroMemory(path, MAX_PATH);

    if (GetSystemDirectoryA(path, MAX_PATH) == 0) { return FALSE; }

    return AcquirePath(lpBuffer, path, uSize);
}

BOOL AcquireAgentPath(LPSTR lpBuffer, const UINT uSize)
{
    if (lpBuffer == NULL) { return FALSE; }

    CHAR path[MAX_PATH];
    ZeroMemory(path, MAX_PATH);

    if (GetCurrentDirectoryA(MAX_PATH, path) == 0) { return FALSE; }

    return AcquirePath(lpBuffer, path, uSize);
}

int main()
{
    if (!RegisterWindowClass()) { printf("Unable to register window class.\r\n."); return EXIT_FAILURE; }

    // Original
    {
        CHAR path[MAX_PATH];
        ZeroMemory(path, MAX_PATH);

        if (AcquireOriginalPath(path, MAX_PATH))
        {
            LPMODULE module = InitializeModule(path);

            if (module == NULL) { printf("Unable to load the original module %s.\r\n", path); return EXIT_FAILURE; }

            printf("Executing tests on %s ...\r\n", path);

            Execute(module);
            ReleaseModule(module);
        }
        else { printf("Unable to load the original module %s.\r\n", path); return EXIT_FAILURE; }
    }

    // Agent
    {
        CHAR path[MAX_PATH];
        ZeroMemory(path, MAX_PATH);

        if (AcquireAgentPath(path, MAX_PATH))
        {
            LPMODULE module = InitializeModule(path);

            if (module == NULL) { printf("Unable to load the agent module %s.\r\n", path); return EXIT_FAILURE; }

            printf("Executing tests on %s ...\r\n", path);

            Execute(module);
            ReleaseModule(module);
        }
        else { printf("Unable to load the agent module %s.\r\n", path); return EXIT_FAILURE; }
    }

    ReleaseWindowClass();

    return EXIT_SUCCESS;
}