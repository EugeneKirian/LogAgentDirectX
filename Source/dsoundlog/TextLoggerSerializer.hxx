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
#include "AgentLogger.hxx"

#define FORMAT(B, X) if(!B->X) { B->Clear(); return FALSE; }
#define FORMATACTION(B, X) if(!X) { B->Clear(); return FALSE; }
#define FORMATVALUE(B, A, X) if(!A(B, X)) { B->Clear(); return FALSE; }

#define FORMATGOTO(B, X, LABEL) if(!B->X) { B->Clear(); goto LABEL; }
#define FORMATACTIONGOTO(B, X, LABEL) if(!X) { B->Clear(); goto LABEL; }

CONST BOOL TextFormatID(LPSTRINGBUILDER builder, CONST GUID value);
CONST BOOL TextFormatID(LPSTRINGBUILDER builder, CONST LPCGUID value);
CONST BOOL TextFormatObject(LPSTRINGBUILDER builder, CONST LPCVOID * value);
CONST BOOL TextFormatObject(LPSTRINGBUILDER builder, CONST LPCVOID value);
CONST BOOL TextFormatString(LPSTRINGBUILDER builder, CONST LPCSTR value);
CONST BOOL TextFormatString(LPSTRINGBUILDER builder, CONST LPCWSTR value);
CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST BOOL value);
CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST D3DVALUE value);
CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST DWORD value);
CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST LONG value);
CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST LPBOOL value);
CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST LPDWORD value);
CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST LPLONG value);
CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST LPQWORD value);
CONST BOOL TextFormatValue(LPSTRINGBUILDER builder, CONST QWORD value);
CONST BOOL TextFormatWindow(LPSTRINGBUILDER builder, CONST HWND* value);
CONST BOOL TextFormatWindow(LPSTRINGBUILDER builder, CONST HWND value);