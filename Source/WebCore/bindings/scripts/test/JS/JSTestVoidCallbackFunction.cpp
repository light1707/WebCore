/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"

#if ENABLE(TEST_CONDITIONAL)

#include "JSTestVoidCallbackFunction.h"

#include "JSDOMConvertBoolean.h"
#include "JSDOMConvertBufferSource.h"
#include "JSDOMConvertInterface.h"
#include "JSDOMConvertNumbers.h"
#include "JSDOMConvertSerializedScriptValue.h"
#include "JSDOMConvertStrings.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMGlobalObject.h"
#include "JSTestNode.h"
#include "ScriptExecutionContext.h"
#include "SerializedScriptValue.h"


namespace WebCore {
using namespace JSC;

JSTestVoidCallbackFunction::JSTestVoidCallbackFunction(JSObject* callback, JSDOMGlobalObject* globalObject)
    : TestVoidCallbackFunction(globalObject->scriptExecutionContext())
    , m_data(new JSCallbackDataStrong(callback, globalObject, this))
{
}

JSTestVoidCallbackFunction::~JSTestVoidCallbackFunction()
{
    ScriptExecutionContext* context = scriptExecutionContext();
    // When the context is destroyed, all tasks with a reference to a callback
    // should be deleted. So if the context is 0, we are on the context thread.
    if (!context || context->isContextThread())
        delete m_data;
    else
        context->postTask(DeleteCallbackDataTask(m_data));
#ifndef NDEBUG
    m_data = nullptr;
#endif
}

CallbackResult<typename IDLVoid::ImplementationType> JSTestVoidCallbackFunction::handleEvent(typename IDLFloat32Array::ParameterType arrayParam, typename IDLSerializedScriptValue<SerializedScriptValue>::ParameterType srzParam, typename IDLDOMString::ParameterType strArg, typename IDLBoolean::ParameterType boolParam, typename IDLLong::ParameterType longParam, typename IDLInterface<TestNode>::ParameterType testNodeParam)
{
    if (!canInvokeCallback())
        return CallbackResultType::UnableToExecute;

    Ref<JSTestVoidCallbackFunction> protectedThis(*this);

    auto& globalObject = *m_data->globalObject();
    auto& vm = globalObject.vm();

    JSLockHolder lock(vm);
    auto& state = *globalObject.globalExec();
    JSValue thisValue = jsUndefined();
    MarkedArgumentBuffer args;
    args.append(toJS<IDLFloat32Array>(state, globalObject, arrayParam));
    args.append(toJS<IDLSerializedScriptValue<SerializedScriptValue>>(state, globalObject, srzParam));
    args.append(toJS<IDLDOMString>(state, strArg));
    args.append(toJS<IDLBoolean>(boolParam));
    args.append(toJS<IDLLong>(longParam));
    args.append(toJS<IDLInterface<TestNode>>(state, globalObject, testNodeParam));
    ASSERT(!args.hasOverflowed());

    NakedPtr<JSC::Exception> returnedException;
    m_data->invokeCallback(thisValue, args, JSCallbackData::CallbackType::Function, Identifier(), returnedException);
    if (returnedException) {
        reportException(&state, returnedException);
        return CallbackResultType::ExceptionThrown;
     }

    return { };
}

JSC::JSValue toJS(TestVoidCallbackFunction& impl)
{
    if (!static_cast<JSTestVoidCallbackFunction&>(impl).callbackData())
        return jsNull();

    return static_cast<JSTestVoidCallbackFunction&>(impl).callbackData()->callback();
}

} // namespace WebCore

#endif // ENABLE(TEST_CONDITIONAL)
