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
#include "JSTestClassWithJSBuiltinConstructor.h"

#include "JSDOMBinding.h"
#include "JSDOMBindingCaller.h"
#include "JSDOMBuiltinConstructor.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMWrapperCache.h"
#include "TestClassWithJSBuiltinConstructorBuiltins.h"
#include <runtime/FunctionPrototype.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

// Attributes

JSC::EncodedJSValue jsTestClassWithJSBuiltinConstructorConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSTestClassWithJSBuiltinConstructorConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::EncodedJSValue);

class JSTestClassWithJSBuiltinConstructorPrototype : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestClassWithJSBuiltinConstructorPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestClassWithJSBuiltinConstructorPrototype* ptr = new (NotNull, JSC::allocateCell<JSTestClassWithJSBuiltinConstructorPrototype>(vm.heap)) JSTestClassWithJSBuiltinConstructorPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestClassWithJSBuiltinConstructorPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};

using JSTestClassWithJSBuiltinConstructorConstructor = JSDOMBuiltinConstructor<JSTestClassWithJSBuiltinConstructor>;

template<> JSValue JSTestClassWithJSBuiltinConstructorConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSTestClassWithJSBuiltinConstructorConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestClassWithJSBuiltinConstructor::prototype(vm, globalObject), DontDelete | ReadOnly | DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(&vm, String(ASCIILiteral("TestClassWithJSBuiltinConstructor"))), ReadOnly | DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), ReadOnly | DontEnum);
}

template<> FunctionExecutable* JSTestClassWithJSBuiltinConstructorConstructor::initializeExecutable(VM& vm)
{
    return testClassWithJSBuiltinConstructorInitializeTestClassWithJSBuiltinConstructorCodeGenerator(vm);
}

template<> const ClassInfo JSTestClassWithJSBuiltinConstructorConstructor::s_info = { "TestClassWithJSBuiltinConstructor", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestClassWithJSBuiltinConstructorConstructor) };

/* Hash table for prototype */

static const HashTableValue JSTestClassWithJSBuiltinConstructorPrototypeTableValues[] =
{
    { "constructor", DontEnum, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestClassWithJSBuiltinConstructorConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestClassWithJSBuiltinConstructorConstructor) } },
};

const ClassInfo JSTestClassWithJSBuiltinConstructorPrototype::s_info = { "TestClassWithJSBuiltinConstructorPrototype", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestClassWithJSBuiltinConstructorPrototype) };

void JSTestClassWithJSBuiltinConstructorPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestClassWithJSBuiltinConstructorPrototypeTableValues, *this);
}

const ClassInfo JSTestClassWithJSBuiltinConstructor::s_info = { "TestClassWithJSBuiltinConstructor", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestClassWithJSBuiltinConstructor) };

JSTestClassWithJSBuiltinConstructor::JSTestClassWithJSBuiltinConstructor(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestClassWithJSBuiltinConstructor>&& impl)
    : JSDOMWrapper<TestClassWithJSBuiltinConstructor>(structure, globalObject, WTFMove(impl))
{
}

void JSTestClassWithJSBuiltinConstructor::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

}

JSObject* JSTestClassWithJSBuiltinConstructor::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestClassWithJSBuiltinConstructorPrototype::create(vm, &globalObject, JSTestClassWithJSBuiltinConstructorPrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSTestClassWithJSBuiltinConstructor::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestClassWithJSBuiltinConstructor>(vm, globalObject);
}

void JSTestClassWithJSBuiltinConstructor::destroy(JSC::JSCell* cell)
{
    JSTestClassWithJSBuiltinConstructor* thisObject = static_cast<JSTestClassWithJSBuiltinConstructor*>(cell);
    thisObject->JSTestClassWithJSBuiltinConstructor::~JSTestClassWithJSBuiltinConstructor();
}

EncodedJSValue jsTestClassWithJSBuiltinConstructorConstructor(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    JSTestClassWithJSBuiltinConstructorPrototype* domObject = jsDynamicDowncast<JSTestClassWithJSBuiltinConstructorPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!domObject))
        return throwVMTypeError(state, throwScope);
    return JSValue::encode(JSTestClassWithJSBuiltinConstructor::getConstructor(state->vm(), domObject->globalObject()));
}

bool setJSTestClassWithJSBuiltinConstructorConstructor(ExecState* state, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    JSValue value = JSValue::decode(encodedValue);
    JSTestClassWithJSBuiltinConstructorPrototype* domObject = jsDynamicDowncast<JSTestClassWithJSBuiltinConstructorPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!domObject)) {
        throwVMTypeError(state, throwScope);
        return false;
    }
    // Shadowing a built-in constructor
    return domObject->putDirect(state->vm(), state->propertyNames().constructor, value);
}

JSValue JSTestClassWithJSBuiltinConstructor::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestClassWithJSBuiltinConstructorConstructor>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

void JSTestClassWithJSBuiltinConstructor::visitChildren(JSCell* cell, SlotVisitor& visitor)
{
    auto* thisObject = jsCast<JSTestClassWithJSBuiltinConstructor*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    Base::visitChildren(thisObject, visitor);
}

bool JSTestClassWithJSBuiltinConstructorOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, SlotVisitor& visitor)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    return false;
}

void JSTestClassWithJSBuiltinConstructorOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsTestClassWithJSBuiltinConstructor = static_cast<JSTestClassWithJSBuiltinConstructor*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestClassWithJSBuiltinConstructor->wrapped(), jsTestClassWithJSBuiltinConstructor);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestClassWithJSBuiltinConstructor@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore33TestClassWithJSBuiltinConstructorE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject* globalObject, Ref<TestClassWithJSBuiltinConstructor>&& impl)
{

#if ENABLE(BINDING_INTEGRITY)
    void* actualVTablePointer = *(reinterpret_cast<void**>(impl.ptr()));
#if PLATFORM(WIN)
    void* expectedVTablePointer = reinterpret_cast<void*>(__identifier("??_7TestClassWithJSBuiltinConstructor@WebCore@@6B@"));
#else
    void* expectedVTablePointer = &_ZTVN7WebCore33TestClassWithJSBuiltinConstructorE[2];
#if COMPILER(CLANG)
    // If this fails TestClassWithJSBuiltinConstructor does not have a vtable, so you need to add the
    // ImplementationLacksVTable attribute to the interface definition
    static_assert(__is_polymorphic(TestClassWithJSBuiltinConstructor), "TestClassWithJSBuiltinConstructor is not polymorphic");
#endif
#endif
    // If you hit this assertion you either have a use after free bug, or
    // TestClassWithJSBuiltinConstructor has subclasses. If TestClassWithJSBuiltinConstructor has subclasses that get passed
    // to toJS() we currently require TestClassWithJSBuiltinConstructor you to opt out of binding hardening
    // by adding the SkipVTableValidation attribute to the interface IDL definition
    RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    return createWrapper<TestClassWithJSBuiltinConstructor>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, TestClassWithJSBuiltinConstructor& impl)
{
    return wrap(state, globalObject, impl);
}

TestClassWithJSBuiltinConstructor* JSTestClassWithJSBuiltinConstructor::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicDowncast<JSTestClassWithJSBuiltinConstructor*>(vm, value))
        return &wrapper->wrapped();
    return nullptr;
}

}
