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

#include <Base.hxx>

#include <Assembler.hxx>

#define DIRECTDRAW_VERSION 0x0700
#include <ddraw.h>
#include <dvp.h>

#define DIRECT3D_VERSION 0x0700
#include <d3d.h>

#define DDBLT_PRIVATE_ALIASPATTERN 0x80000000L

#define IDirectDrawVideoPortContainer IDDVideoPortContainer 
#define IID_IDirectDrawVideoPortContainer IID_IDDVideoPortContainer

typedef struct _DDRAWI_DDRAWSURFACE_LCL FAR * LPDDRAWI_DDRAWSURFACE_LCL;
typedef struct _DDRAWI_DIRECTDRAW_LCL FAR * LPDDRAWI_DIRECTDRAW_LCL;