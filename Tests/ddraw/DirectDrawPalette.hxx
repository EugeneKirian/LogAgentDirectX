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

VOID DirectDrawCreatePalette(LPMODULE module);
VOID DirectDraw2CreatePalette(LPMODULE module);
VOID DirectDraw4CreatePalette(LPMODULE module);
VOID DirectDraw7CreatePalette(LPMODULE module);

VOID DirectDrawPaletteQueryInterfaceIUnknown(LPMODULE module);
VOID DirectDraw2PaletteQueryInterfaceIUnknown(LPMODULE module);
VOID DirectDraw4PaletteQueryInterfaceIUnknown(LPMODULE module);
VOID DirectDraw7PaletteQueryInterfaceIUnknown(LPMODULE module);

VOID DirectDrawPaletteQueryInterfacePalette(LPMODULE module);
VOID DirectDraw2PaletteQueryInterfacePalette(LPMODULE module);
VOID DirectDraw4PaletteQueryInterfacePalette(LPMODULE module);
VOID DirectDraw7PaletteQueryInterfacePalette(LPMODULE module);

VOID DirectDrawPaletteQueryInterfaceAll(LPMODULE module);
VOID DirectDraw2PaletteQueryInterfaceAll(LPMODULE module);
VOID DirectDraw4PaletteQueryInterfaceAll(LPMODULE module);
VOID DirectDraw7PaletteQueryInterfaceAll(LPMODULE module);