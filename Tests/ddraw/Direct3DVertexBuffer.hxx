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

VOID DirectDrawVertexBuffer(LPMODULE module);
VOID DirectDraw2VertexBuffer(LPMODULE module);
VOID DirectDraw4VertexBuffer(LPMODULE module);
VOID DirectDraw7VertexBuffer(LPMODULE module);

VOID DirectDrawVertexBufferQueryInterfaceIUnknown(LPMODULE module);
VOID DirectDraw2VertexBufferQueryInterfaceIUnknown(LPMODULE module);
VOID DirectDraw4VertexBufferQueryInterfaceIUnknown(LPMODULE module);
VOID DirectDraw7VertexBufferQueryInterfaceIUnknown(LPMODULE module);

VOID DirectDrawVertexBufferQueryInterfaceAll(LPMODULE module);
VOID DirectDraw2VertexBufferQueryInterfaceAll(LPMODULE module);
VOID DirectDraw4VertexBufferQueryInterfaceAll(LPMODULE module);
VOID DirectDraw7VertexBufferQueryInterfaceAll(LPMODULE module);