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
#include "Module.hxx"

VOID DirectDrawClipperCreate(LPMODULE module);
VOID DirectDrawCreateClipper(LPMODULE module);
VOID DirectDraw2CreateClipper(LPMODULE module);
VOID DirectDraw4CreateClipper(LPMODULE module);
VOID DirectDraw7CreateClipper(LPMODULE module);

VOID DirectDrawClipperQueryInterfaceIUnknown(LPMODULE module);
VOID DirectDraw2ClipperQueryInterfaceIUnknown(LPMODULE module);
VOID DirectDraw4ClipperQueryInterfaceIUnknown(LPMODULE module);
VOID DirectDraw7ClipperQueryInterfaceIUnknown(LPMODULE module);

VOID DirectDrawClipperQueryInterfaceClipper(LPMODULE module);
VOID DirectDraw2ClipperQueryInterfaceClipper(LPMODULE module);
VOID DirectDraw4ClipperQueryInterfaceClipper(LPMODULE module);
VOID DirectDraw7ClipperQueryInterfaceClipper(LPMODULE module);

VOID DirectDrawCreateClipperQueryInterfaceAll(LPMODULE module);
VOID DirectDrawClipperQueryInterfaceAll(LPMODULE module);
VOID DirectDraw2ClipperQueryInterfaceAll(LPMODULE module);
VOID DirectDraw4ClipperQueryInterfaceAll(LPMODULE module);
VOID DirectDraw7ClipperQueryInterfaceAll(LPMODULE module);