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
#include "JSTestGenerateIsReachable.h"

#include "JSDOMBinding.h"
#include "JSDOMBindingCaller.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMWrapperCache.h"
#include <runtime/FunctionPrototype.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

// Attributes

JSC::EncodedJSValue jsTestGenerateIsReachableConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSTestGenerateIsReachableConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::EncodedJSValue);

class JSTestGenerateIsReachablePrototype : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestGenerateIsReachablePrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestGenerateIsReachablePrototype* ptr = new (NotNull, JSC::allocateCell<JSTestGenerateIsReachablePrototype>(vm.heap)) JSTestGenerateIsReachablePrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestGenerateIsReachablePrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};

using JSTestGenerateIsReachableConstructor = JSDOMConstructorNotConstructable<JSTestGenerateIsReachable>;

template<> JSValue JSTestGenerateIsReachableConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSTestGenerateIsReachableConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestGenerateIsReachable::prototype(vm, globalObject), DontDelete | ReadOnly | DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(&vm, String(ASCIILiteral("TestGenerateIsReachable"))), ReadOnly | DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), ReadOnly | DontEnum);
}

template<> const ClassInfo JSTestGenerateIsReachableConstructor::s_info = { "TestGenerateIsReachable", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestGenerateIsReachableConstructor) };

/* Hash table for prototype */

static const HashTableValue JSTestGenerateIsReachablePrototypeTableValues[] =
{
    { "constructor", DontEnum, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestGenerateIsReachableConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestGenerateIsReachableConstructor) } },
};

const ClassInfo JSTestGenerateIsReachablePrototype::s_info = { "TestGenerateIsReachablePrototype", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestGenerateIsReachablePrototype) };

void JSTestGenerateIsReachablePrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestGenerateIsReachablePrototypeTableValues, *this);
}

const ClassInfo JSTestGenerateIsReachable::s_info = { "TestGenerateIsReachable", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestGenerateIsReachable) };

JSTestGenerateIsReachable::JSTestGenerateIsReachable(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestGenerateIsReachable>&& impl)
    : JSDOMWrapper<TestGenerateIsReachable>(structure, globalObject, WTFMove(impl))
{
}

void JSTestGenerateIsReachable::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

}

JSObject* JSTestGenerateIsReachable::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestGenerateIsReachablePrototype::create(vm, &globalObject, JSTestGenerateIsReachablePrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSTestGenerateIsReachable::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestGenerateIsReachable>(vm, globalObject);
}

void JSTestGenerateIsReachable::destroy(JSC::JSCell* cell)
{
    JSTestGenerateIsReachable* thisObject = static_cast<JSTestGenerateIsReachable*>(cell);
    thisObject->JSTestGenerateIsReachable::~JSTestGenerateIsReachable();
}

EncodedJSValue jsTestGenerateIsReachableConstructor(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    JSTestGenerateIsReachablePrototype* domObject = jsDynamicDowncast<JSTestGenerateIsReachablePrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!domObject))
        return throwVMTypeError(state, throwScope);
    return JSValue::encode(JSTestGenerateIsReachable::getConstructor(state->vm(), domObject->globalObject()));
}

bool setJSTestGenerateIsReachableConstructor(ExecState* state, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    JSValue value = JSValue::decode(encodedValue);
    JSTestGenerateIsReachablePrototype* domObject = jsDynamicDowncast<JSTestGenerateIsReachablePrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!domObject)) {
        throwVMTypeError(state, throwScope);
        return false;
    }
    // Shadowing a built-in constructor
    return domObject->putDirect(state->vm(), state->propertyNames().constructor, value);
}

JSValue JSTestGenerateIsReachable::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestGenerateIsReachableConstructor>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

bool JSTestGenerateIsReachableOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, SlotVisitor& visitor)
{
    auto* jsTestGenerateIsReachable = jsCast<JSTestGenerateIsReachable*>(handle.slot()->asCell());
    TestGenerateIsReachable* root = &jsTestGenerateIsReachable->wrapped();
    return visitor.containsOpaqueRoot(root);
}

void JSTestGenerateIsReachableOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsTestGenerateIsReachable = static_cast<JSTestGenerateIsReachable*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestGenerateIsReachable->wrapped(), jsTestGenerateIsReachable);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestGenerateIsReachable@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore23TestGenerateIsReachableE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject* globalObject, Ref<TestGenerateIsReachable>&& impl)
{

#if ENABLE(BINDING_INTEGRITY)
    void* actualVTablePointer = *(reinterpret_cast<void**>(impl.ptr()));
#if PLATFORM(WIN)
    void* expectedVTablePointer = reinterpret_cast<void*>(__identifier("??_7TestGenerateIsReachable@WebCore@@6B@"));
#else
    void* expectedVTablePointer = &_ZTVN7WebCore23TestGenerateIsReachableE[2];
#if COMPILER(CLANG)
    // If this fails TestGenerateIsReachable does not have a vtable, so you need to add the
    // ImplementationLacksVTable attribute to the interface definition
    static_assert(__is_polymorphic(TestGenerateIsReachable), "TestGenerateIsReachable is not polymorphic");
#endif
#endif
    // If you hit this assertion you either have a use after free bug, or
    // TestGenerateIsReachable has subclasses. If TestGenerateIsReachable has subclasses that get passed
    // to toJS() we currently require TestGenerateIsReachable you to opt out of binding hardening
    // by adding the SkipVTableValidation attribute to the interface IDL definition
    RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    return createWrapper<TestGenerateIsReachable>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, TestGenerateIsReachable& impl)
{
    return wrap(state, globalObject, impl);
}

TestGenerateIsReachable* JSTestGenerateIsReachable::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicDowncast<JSTestGenerateIsReachable*>(vm, value))
        return &wrapper->wrapped();
    return nullptr;
}

}
