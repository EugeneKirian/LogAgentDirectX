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
#include "Direct3DResource8.hxx"
#include "Direct3DSurface8.hxx"
#include "Direct3DSwapChain8.hxx"
#include "Direct3DTexture8.hxx"
#include "Direct3DVertexBuffer8.hxx"
#include "Direct3DVolume8.hxx"
#include "Direct3DVolumeTexture8.hxx"

#include "Window.hxx"

#include <stdio.h>

#define Invoke(X)                 \
    printf(#X ## "\r\n");         \
    X(module)

VOID ExecuteDirect3D8(LPMODULE module)
{
    Invoke(Direct3D8Create);
    Invoke(Direct3D8Release);
    Invoke(Direct3D8QueryInterfaceIUnknown);
    Invoke(Direct3D8QueryInterfaceAll);
}

VOID ExecuteDirect3DBaseTexture8(LPMODULE module)
{
    Invoke(Direct3DBaseTexture8Create);
    Invoke(Direct3DBaseTexture8Release);
    Invoke(Direct3DBaseTexture8QueryInterfaceIUnknown);
    Invoke(Direct3DBaseTexture8QueryInterfaceAll);
    Invoke(Direct3DBaseTexture8UnknownQueryInterfaceAll);
}

VOID ExecuteDirect3DCubeTexture8(LPMODULE module)
{
    Invoke(Direct3DCubeTexture8Create);
    Invoke(Direct3DCubeTexture8Release);
    Invoke(Direct3DCubeTexture8QueryInterfaceIUnknown);
    Invoke(Direct3DCubeTexture8QueryInterfaceAll);
    Invoke(Direct3DCubeTexture8UnknownQueryInterfaceAll);
}

VOID ExecuteDirect3DDevice8(LPMODULE module)
{
    Invoke(Direct3DDevice8Create);
    Invoke(Direct3DDevice8Release);
    Invoke(Direct3DDevice8QueryInterfaceIUnknown);
    Invoke(Direct3DDevice8QueryInterfaceAll);
    Invoke(Direct3DDevice8UnknownQueryInterfaceAll);
    Invoke(Direct3DDevice8SetRenderTarget);
}

VOID ExecuteDirect3DIndexBuffer8(LPMODULE module)
{
    Invoke(Direct3DIndexBuffer8Create);
    Invoke(Direct3DIndexBuffer8Release);
    Invoke(Direct3DIndexBuffer8QueryInterfaceIUnknown);
    Invoke(Direct3DIndexBuffer8QueryInterfaceAll);
    Invoke(Direct3DIndexBuffer8UnknownQueryInterfaceAll);
}

VOID ExecuteDirect3DResource8(LPMODULE module)
{
    Invoke(Direct3DResource8Create);
    Invoke(Direct3DResource8Release);
    Invoke(Direct3DResource8QueryInterfaceIUnknown);
    Invoke(Direct3DResource8QueryInterfaceAll);
}

VOID ExecuteDirect3DSurface8(LPMODULE module)
{
    Invoke(Direct3DSurface8Create);
    Invoke(Direct3DSurface8Release);
    Invoke(Direct3DSurface8QueryInterfaceIUnknown);
    Invoke(Direct3DSurface8QueryInterfaceAll);
    Invoke(Direct3DSurface8UnknownQueryInterfaceAll);
}

VOID ExecuteDirect3DSwapChain8(LPMODULE module)
{
    Invoke(Direct3DSwapChain8Create);
    Invoke(Direct3DSwapChain8Release);
    Invoke(Direct3DSwapChain8QueryInterfaceIUnknown);
    Invoke(Direct3DSwapChain8QueryInterfaceAll);
    Invoke(Direct3DSwapChain8UnknownQueryInterfaceAll);
}

VOID ExecuteDirect3DTexture8(LPMODULE module)
{
    Invoke(Direct3DTexture8Create);
    Invoke(Direct3DTexture8Release);
    Invoke(Direct3DTexture8QueryInterfaceIUnknown);
    Invoke(Direct3DTexture8QueryInterfaceAll);
    Invoke(Direct3DTexture8UnknownQueryInterfaceAll);
}

VOID ExecuteDirect3DVertexBuffer8(LPMODULE module)
{
    Invoke(Direct3DVertexBuffer8Create);
    Invoke(Direct3DVertexBuffer8Release);
    Invoke(Direct3DVertexBuffer8QueryInterfaceIUnknown);
    Invoke(Direct3DVertexBuffer8QueryInterfaceAll);
    Invoke(Direct3DVertexBuffer8UnknownQueryInterfaceAll);
}

VOID ExecuteDirect3DVolume8(LPMODULE module)
{
    Invoke(Direct3DVolume8Create);
    Invoke(Direct3DVolume8Release);
    Invoke(Direct3DVolume8QueryInterfaceIUnknown);
    Invoke(Direct3DVolume8QueryInterfaceAll);
    Invoke(Direct3DVolume8UnknownQueryInterfaceAll);
}

VOID ExecuteDirect3DVolumeTexture8(LPMODULE module)
{
    Invoke(Direct3DVolumeTexture8Create);
    Invoke(Direct3DVolumeTexture8Release);
    Invoke(Direct3DVolumeTexture8QueryInterfaceIUnknown);
    Invoke(Direct3DVolumeTexture8QueryInterfaceAll);
    Invoke(Direct3DVolumeTexture8UnknownQueryInterfaceAll);
}

VOID Execute(LPMODULE module)
{
    Invoke(ExecuteDirect3D8);
    Invoke(ExecuteDirect3DBaseTexture8);
    Invoke(ExecuteDirect3DCubeTexture8);
    Invoke(ExecuteDirect3DDevice8);
    Invoke(ExecuteDirect3DIndexBuffer8);
    Invoke(ExecuteDirect3DResource8);
    Invoke(ExecuteDirect3DSurface8);
    Invoke(ExecuteDirect3DSwapChain8);
    Invoke(ExecuteDirect3DTexture8);
    Invoke(ExecuteDirect3DVertexBuffer8);
    Invoke(ExecuteDirect3DVolume8);
    Invoke(ExecuteDirect3DVolumeTexture8);
}

BOOL AcquirePath(LPSTR lpBuffer, LPCSTR lpPath, const UINT uSize)
{
    CHAR path[MAX_PATH];
    ZeroMemory(path, MAX_PATH);

    if (PathCombineA(path, lpPath, DIRECT_3D_LIBRARY_NAME) == NULL) { return FALSE; }

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