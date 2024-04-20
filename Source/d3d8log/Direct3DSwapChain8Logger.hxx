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

#include "Base.hxx"

typedef struct Direct3DSwapChain8QueryInterfaceMethodValue
{
    GUID ID;
    LPVOID* Object;
} DIRECT3DSWAPCHAIN8QUERYINTERFACEMETHODVALUE, * LPDIRECT3DSWAPCHAIN8QUERYINTERFACEMETHODVALUE;

typedef struct Direct3DSwapChain8AddRefMethodValue
{

} DIRECT3DSWAPCHAIN8ADDREFMETHODVALUE, * LPDIRECT3DSWAPCHAIN8ADDREFMETHODVALUE;

typedef struct Direct3DSwapChain8ReleaseMethodValue
{

} DIRECT3DSWAPCHAIN8RELEASEMETHODVALUE, * LPDIRECT3DSWAPCHAIN8RELEASEMETHODVALUE;

typedef struct Direct3DSwapChain8PresentMethodValue
{
    CONST RECT* SourceRect;
    CONST RECT* DestRect;
    HWND Window;
    CONST RGNDATA* Region;
} DIRECT3DSWAPCHAIN8PRESENTMETHODVALUE, * LPDIRECT3DSWAPCHAIN8PRESENTMETHODVALUE;

typedef struct Direct3DSwapChain8GetBackBufferMethodValue
{
    UINT Index;
    D3DBACKBUFFER_TYPE Type;
    LPDIRECT3DSURFACE8* BackBuffer;
} DIRECT3DSWAPCHAIN8GETBACKBUFFERMETHODVALUE, * LPDIRECT3DSWAPCHAIN8GETBACKBUFFERMETHODVALUE;