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
#include "JSTestNamedConstructor.h"

#include "JSDOMBinding.h"
#include "JSDOMBindingCaller.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMConvert.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMNamedConstructor.h"
#include "JSDOMWrapperCache.h"
#include <runtime/Error.h>
#include <runtime/FunctionPrototype.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

// Attributes

JSC::EncodedJSValue jsTestNamedConstructorConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSTestNamedConstructorConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::EncodedJSValue);

class JSTestNamedConstructorPrototype : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestNamedConstructorPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestNamedConstructorPrototype* ptr = new (NotNull, JSC::allocateCell<JSTestNamedConstructorPrototype>(vm.heap)) JSTestNamedConstructorPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestNamedConstructorPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};

using JSTestNamedConstructorConstructor = JSDOMConstructorNotConstructable<JSTestNamedConstructor>;
using JSTestNamedConstructorNamedConstructor = JSDOMNamedConstructor<JSTestNamedConstructor>;

template<> JSValue JSTestNamedConstructorConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSTestNamedConstructorConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestNamedConstructor::prototype(vm, globalObject), DontDelete | ReadOnly | DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(&vm, String(ASCIILiteral("TestNamedConstructor"))), ReadOnly | DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), ReadOnly | DontEnum);
}

template<> const ClassInfo JSTestNamedConstructorConstructor::s_info = { "TestNamedConstructor", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestNamedConstructorConstructor) };

template<> EncodedJSValue JSC_HOST_CALL JSTestNamedConstructorNamedConstructor::construct(ExecState* state)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    auto* castedThis = jsCast<JSTestNamedConstructorNamedConstructor*>(state->jsCallee());
    ASSERT(castedThis);
    if (UNLIKELY(state->argumentCount() < 1))
        return throwVMError(state, throwScope, createNotEnoughArgumentsError(state));
    auto str1 = convert<IDLDOMString>(*state, state->uncheckedArgument(0));
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    auto str2 = state->argument(1).isUndefined() ? ASCIILiteral("defaultString") : convert<IDLDOMString>(*state, state->uncheckedArgument(1));
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    auto str3 = state->argument(2).isUndefined() ? String() : convert<IDLDOMString>(*state, state->uncheckedArgument(2));
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    auto object = TestNamedConstructor::createForJSConstructor(WTFMove(str1), WTFMove(str2), WTFMove(str3));
    return JSValue::encode(toJSNewlyCreated<IDLInterface<TestNamedConstructor>>(*state, *castedThis->globalObject(), throwScope, WTFMove(object)));
}

template<> JSValue JSTestNamedConstructorNamedConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSTestNamedConstructorNamedConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestNamedConstructor::prototype(vm, globalObject), DontDelete | ReadOnly | DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(&vm, String(ASCIILiteral("Audio"))), ReadOnly | DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), ReadOnly | DontEnum);
}

template<> const ClassInfo JSTestNamedConstructorNamedConstructor::s_info = { "Audio", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestNamedConstructorNamedConstructor) };

/* Hash table for prototype */

static const HashTableValue JSTestNamedConstructorPrototypeTableValues[] =
{
    { "constructor", DontEnum, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestNamedConstructorConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestNamedConstructorConstructor) } },
};

const ClassInfo JSTestNamedConstructorPrototype::s_info = { "TestNamedConstructorPrototype", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestNamedConstructorPrototype) };

void JSTestNamedConstructorPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestNamedConstructorPrototypeTableValues, *this);
}

const ClassInfo JSTestNamedConstructor::s_info = { "TestNamedConstructor", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestNamedConstructor) };

JSTestNamedConstructor::JSTestNamedConstructor(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestNamedConstructor>&& impl)
    : JSDOMWrapper<TestNamedConstructor>(structure, globalObject, WTFMove(impl))
{
}

void JSTestNamedConstructor::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

}

JSObject* JSTestNamedConstructor::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestNamedConstructorPrototype::create(vm, &globalObject, JSTestNamedConstructorPrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSTestNamedConstructor::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestNamedConstructor>(vm, globalObject);
}

void JSTestNamedConstructor::destroy(JSC::JSCell* cell)
{
    JSTestNamedConstructor* thisObject = static_cast<JSTestNamedConstructor*>(cell);
    thisObject->JSTestNamedConstructor::~JSTestNamedConstructor();
}

EncodedJSValue jsTestNamedConstructorConstructor(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    JSTestNamedConstructorPrototype* domObject = jsDynamicDowncast<JSTestNamedConstructorPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!domObject))
        return throwVMTypeError(state, throwScope);
    return JSValue::encode(JSTestNamedConstructor::getConstructor(state->vm(), domObject->globalObject()));
}

bool setJSTestNamedConstructorConstructor(ExecState* state, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    JSValue value = JSValue::decode(encodedValue);
    JSTestNamedConstructorPrototype* domObject = jsDynamicDowncast<JSTestNamedConstructorPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!domObject)) {
        throwVMTypeError(state, throwScope);
        return false;
    }
    // Shadowing a built-in constructor
    return domObject->putDirect(state->vm(), state->propertyNames().constructor, value);
}

JSValue JSTestNamedConstructor::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestNamedConstructorConstructor>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

JSValue JSTestNamedConstructor::getNamedConstructor(VM& vm, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestNamedConstructorNamedConstructor>(vm, *jsCast<JSDOMGlobalObject*>(globalObject));
}

bool JSTestNamedConstructorOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, SlotVisitor& visitor)
{
    auto* jsTestNamedConstructor = jsCast<JSTestNamedConstructor*>(handle.slot()->asCell());
    if (jsTestNamedConstructor->wrapped().hasPendingActivity())
        return true;
    UNUSED_PARAM(visitor);
    return false;
}

void JSTestNamedConstructorOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsTestNamedConstructor = static_cast<JSTestNamedConstructor*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestNamedConstructor->wrapped(), jsTestNamedConstructor);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestNamedConstructor@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore20TestNamedConstructorE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject* globalObject, Ref<TestNamedConstructor>&& impl)
{

#if ENABLE(BINDING_INTEGRITY)
    void* actualVTablePointer = *(reinterpret_cast<void**>(impl.ptr()));
#if PLATFORM(WIN)
    void* expectedVTablePointer = reinterpret_cast<void*>(__identifier("??_7TestNamedConstructor@WebCore@@6B@"));
#else
    void* expectedVTablePointer = &_ZTVN7WebCore20TestNamedConstructorE[2];
#if COMPILER(CLANG)
    // If this fails TestNamedConstructor does not have a vtable, so you need to add the
    // ImplementationLacksVTable attribute to the interface definition
    static_assert(__is_polymorphic(TestNamedConstructor), "TestNamedConstructor is not polymorphic");
#endif
#endif
    // If you hit this assertion you either have a use after free bug, or
    // TestNamedConstructor has subclasses. If TestNamedConstructor has subclasses that get passed
    // to toJS() we currently require TestNamedConstructor you to opt out of binding hardening
    // by adding the SkipVTableValidation attribute to the interface IDL definition
    RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    return createWrapper<TestNamedConstructor>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, TestNamedConstructor& impl)
{
    return wrap(state, globalObject, impl);
}

TestNamedConstructor* JSTestNamedConstructor::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicDowncast<JSTestNamedConstructor*>(vm, value))
        return &wrapper->wrapped();
    return nullptr;
}

}
