/*
 * Copyright (C) 2010 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "JSExecState.h"

#include "Microtasks.h"
#include "RejectedPromiseTracker.h"
#include "ScriptExecutionContext.h"
#include "ScriptState.h"
#include "WorkerGlobalScope.h"

namespace WebCore {

void JSExecState::didLeaveScriptContext(JSC::ExecState* exec)
{
    ScriptExecutionContext* context = scriptExecutionContextFromExecState(exec);
    if (!context)
        return;
    MicrotaskQueue::contextQueue(*context).performMicrotaskCheckpoint();
    context->ensureRejectedPromiseTracker().processQueueSoon();
}

JSC::JSValue functionCallHandlerFromAnyThread(JSC::ExecState* exec, JSC::JSValue functionObject, JSC::CallType callType, const JSC::CallData& callData, JSC::JSValue thisValue, const JSC::ArgList& args, NakedPtr<JSC::Exception>& returnedException)
{
    return JSExecState::call(exec, functionObject, callType, callData, thisValue, args, returnedException);
}

JSC::JSValue evaluateHandlerFromAnyThread(JSC::ExecState* exec, const JSC::SourceCode& source, JSC::JSValue thisValue, NakedPtr<JSC::Exception>& returnedException)
{
    return JSExecState::evaluate(exec, source, thisValue, returnedException);
}

} // namespace WebCore
