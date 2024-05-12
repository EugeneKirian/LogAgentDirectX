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

#pragma once

#define NOMINMAX
#define STRICT
#define WIN32_MEAN_AND_LEAN

#include <windows.h>
#include <shlwapi.h>

#define DIRECTDRAW_VERSION 0x0700
#include <ddraw.h>
#include <dvp.h>

#define DIRECT3D_VERSION 0x0700
#include <d3d.h>

#define DIRECTRELEASE(x) if (x != NULL) { x->Release(); x = NULL; }

#define IsEqual(a, b) if (a != b) { DebugBreak(); }
#define IsNotEqual(a, b) if (a == b) { DebugBreak(); }

DEFINE_GUID(CLSID_DirectDrawFactory2, 0xb9dc4790, 0x4af1, 0x11d1, 0x8c, 0x4c, 0x00, 0xc0, 0x4f, 0xd9, 0x30, 0xc5);
DEFINE_GUID(IID_IDirectDrawFactory2, 0x89b2c488, 0x4af4, 0x11d1, 0x8c, 0x4c, 0x00, 0xc0, 0x4f, 0xd9, 0x30, 0xc5);

DEFINE_GUID(IID_IDirectDrawPalette2, 0xc03c477e, 0x6519, 0x11d1, 0x8c, 0x52, 0x00, 0xc0, 0x4f, 0xd9, 0x30, 0xc5);

DEFINE_GUID(IID_IDirectDrawKernel, 0x8D56C120, 0x6A08, 0x11D0, 0x9B, 0x06, 0x00, 0xA0, 0xC9, 0x03, 0xA3, 0xB8);

DEFINE_GUID(IID_IDirectDrawOptSurface, 0x51191f1e, 0x4f2b, 0x11d1, 0x8c, 0xc3, 0x0, 0xa0, 0xc9, 0x6, 0x29, 0xa8);

DEFINE_GUID(IID_IDirectDrawSurfaceKernel, 0x60755DA0, 0x6A40, 0x11D0, 0x9B, 0x06, 0x00, 0xA0, 0xC9, 0x03, 0xA3, 0xB8);
DEFINE_GUID(IID_IDirectDrawSurfaceNew, 0x1bab8e96, 0x9cfe, 0x4ce3, 0xbc, 0x72, 0xd7, 0xe9, 0xe9, 0x9a, 0x21, 0x75);