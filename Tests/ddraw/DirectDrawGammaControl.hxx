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

VOID DirectDrawCreateGammaControl(LPMODULE module);
VOID DirectDraw2CreateGammaControl(LPMODULE module);
VOID DirectDraw4CreateGammaControl(LPMODULE module);
VOID DirectDraw7CreateGammaControl(LPMODULE module);

VOID DirectDrawGammaControlQueryInterfaceIUnknown(LPMODULE module);
VOID DirectDraw2GammaControlQueryInterfaceIUnknown(LPMODULE module);
VOID DirectDraw4GammaControlQueryInterfaceIUnknown(LPMODULE module);
VOID DirectDraw7GammaControlQueryInterfaceIUnknown(LPMODULE module);

VOID DirectDrawGammaControlQueryInterfaceAll(LPMODULE module);
VOID DirectDraw2GammaControlQueryInterfaceAll(LPMODULE module);
VOID DirectDraw4GammaControlQueryInterfaceAll(LPMODULE module);
VOID DirectDraw7GammaControlQueryInterfaceAll(LPMODULE module);