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

#include <Logger.hxx>

#include "Agent.hxx"
#include "StringBuilder.hxx"

class BinaryLoggerSerializer : public LoggerSerializer
{
public:
    BinaryLoggerSerializer(LPLOGGERSETTINGS settings, LPLOGGERWRITER writer);
    virtual ~BinaryLoggerSerializer();

    virtual CONST BOOL Serialize(CONST LOGGERLEVEL level, CONST LPLOGGERACTION action) override;
};

typedef BinaryLoggerSerializer* LPBINARYLOGGERSERIALIZER;

class TextLoggerSerializer : public LoggerSerializer
{
public:
    TextLoggerSerializer(LPLOGGERSETTINGS settings, LPLOGGERWRITER writer);
    virtual ~TextLoggerSerializer();

    virtual CONST BOOL Serialize(CONST LOGGERLEVEL level, CONST LPLOGGERACTION action) override;

protected:
    LPSTRINGBUILDER Builder;
};

typedef TextLoggerSerializer* LPTEXTLOGGERSERIALIZER;

#define AgentLogConstructor(LEVEL, O) LogConstructorMacro(this->State.Logger, LEVEL, O, this)

#define AgentLogDestructor(LEVEL, O) LogDestructorMacro(this->State.Logger, LEVEL, O, this)

#define AgentLogMethod(LEVEL, O, M) LogMethodMacro(this->State.Logger, LEVEL, O, M, this)

#define AgentLogMethodValue(LEVEL, O, M, C, PARAMS) LogMethodValueMacro(this->State.Logger, LEVEL, O, M, this, C, PARAMS)

#define AgentLogAddRefMethodResult(LEVEL, O, M, R) LogMethodResultMacro(this->State.Logger, LEVEL, O, M, this, FALSE, ULONG, R)

#define AgentLogReleaseMethodResult(LEVEL, O, M, R)                                                                                         \
    CONST ULONG __result__ = R;                                                                                                             \
    if (this->State.Logger->IsAcceptable(LOGGER_LEVEL_##LEVEL))                                                                             \
    {                                                                                                                                       \
        LogMethodResult(this->State.Logger, LOGGER_LEVEL_##LEVEL, OBJECT_ID_##O, this, METHOD_ID_##O##_##M, (DWORD)__result__, NULL);       \
    }                                                                                                                                       \
    if (__result__ == 0) { delete this; }                                                                                                   \
    return __result__;

#define AgentLogMethodResult(LEVEL, O, M, R) LogMethodResultMacro(this->State.Logger, LEVEL, O, M, this, FAILED(R), HRESULT, R)

#define AgentLogMethodResultValue(LEVEL, O, M, R, C, PARAMS) LogMethodResultValueMacro(this->State.Logger, LEVEL, O, M, this, FAILED(R), HRESULT, R, C, PARAMS)

#define AgentLogMethodCallbackValue(LEVEL, O, M, C, PARAMS) LogMethodCallbackValueMacro(context->Logger, LEVEL, O, M, M, context->Self, C, PARAMS)

#define AgentLogMethodCallbackResultValue(LEVEL, O, M, R, C, PARAMS) LogMethodCallbackResultValueMacro(context->Logger, LEVEL, O, M, M, context->Self, HRESULT, R, C, PARAMS)