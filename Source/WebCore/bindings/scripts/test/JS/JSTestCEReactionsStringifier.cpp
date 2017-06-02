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
#include "JSTestCEReactionsStringifier.h"

#include "CustomElementReactionQueue.h"
#include "JSDOMBinding.h"
#include "JSDOMBindingCaller.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMConvert.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMWrapperCache.h"
#include <runtime/Error.h>
#include <runtime/FunctionPrototype.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsTestCEReactionsStringifierPrototypeFunctionToString(JSC::ExecState*);

// Attributes

JSC::EncodedJSValue jsTestCEReactionsStringifierValue(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSTestCEReactionsStringifierValue(JSC::ExecState*, JSC::EncodedJSValue, JSC::EncodedJSValue);
JSC::EncodedJSValue jsTestCEReactionsStringifierConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSTestCEReactionsStringifierConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::EncodedJSValue);

class JSTestCEReactionsStringifierPrototype : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestCEReactionsStringifierPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestCEReactionsStringifierPrototype* ptr = new (NotNull, JSC::allocateCell<JSTestCEReactionsStringifierPrototype>(vm.heap)) JSTestCEReactionsStringifierPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestCEReactionsStringifierPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};

using JSTestCEReactionsStringifierConstructor = JSDOMConstructorNotConstructable<JSTestCEReactionsStringifier>;

template<> JSValue JSTestCEReactionsStringifierConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    UNUSED_PARAM(vm);
    return globalObject.functionPrototype();
}

template<> void JSTestCEReactionsStringifierConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestCEReactionsStringifier::prototype(vm, globalObject), DontDelete | ReadOnly | DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(&vm, String(ASCIILiteral("TestCEReactionsStringifier"))), ReadOnly | DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), ReadOnly | DontEnum);
}

template<> const ClassInfo JSTestCEReactionsStringifierConstructor::s_info = { "TestCEReactionsStringifier", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestCEReactionsStringifierConstructor) };

/* Hash table for prototype */

static const HashTableValue JSTestCEReactionsStringifierPrototypeTableValues[] =
{
    { "constructor", DontEnum, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestCEReactionsStringifierConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestCEReactionsStringifierConstructor) } },
    { "value", CustomAccessor, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestCEReactionsStringifierValue), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestCEReactionsStringifierValue) } },
    { "toString", JSC::Function, NoIntrinsic, { (intptr_t)static_cast<NativeFunction>(jsTestCEReactionsStringifierPrototypeFunctionToString), (intptr_t) (0) } },
};

const ClassInfo JSTestCEReactionsStringifierPrototype::s_info = { "TestCEReactionsStringifierPrototype", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestCEReactionsStringifierPrototype) };

void JSTestCEReactionsStringifierPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestCEReactionsStringifierPrototypeTableValues, *this);
}

const ClassInfo JSTestCEReactionsStringifier::s_info = { "TestCEReactionsStringifier", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestCEReactionsStringifier) };

JSTestCEReactionsStringifier::JSTestCEReactionsStringifier(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestCEReactionsStringifier>&& impl)
    : JSDOMWrapper<TestCEReactionsStringifier>(structure, globalObject, WTFMove(impl))
{
}

void JSTestCEReactionsStringifier::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

}

JSObject* JSTestCEReactionsStringifier::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestCEReactionsStringifierPrototype::create(vm, &globalObject, JSTestCEReactionsStringifierPrototype::createStructure(vm, &globalObject, globalObject.objectPrototype()));
}

JSObject* JSTestCEReactionsStringifier::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestCEReactionsStringifier>(vm, globalObject);
}

void JSTestCEReactionsStringifier::destroy(JSC::JSCell* cell)
{
    JSTestCEReactionsStringifier* thisObject = static_cast<JSTestCEReactionsStringifier*>(cell);
    thisObject->JSTestCEReactionsStringifier::~JSTestCEReactionsStringifier();
}

template<> inline JSTestCEReactionsStringifier* BindingCaller<JSTestCEReactionsStringifier>::castForAttribute(ExecState& state, EncodedJSValue thisValue)
{
    return jsDynamicDowncast<JSTestCEReactionsStringifier*>(state.vm(), JSValue::decode(thisValue));
}

template<> inline JSTestCEReactionsStringifier* BindingCaller<JSTestCEReactionsStringifier>::castForOperation(ExecState& state)
{
    return jsDynamicDowncast<JSTestCEReactionsStringifier*>(state.vm(), state.thisValue());
}

static inline JSValue jsTestCEReactionsStringifierValueGetter(ExecState&, JSTestCEReactionsStringifier&, ThrowScope& throwScope);

EncodedJSValue jsTestCEReactionsStringifierValue(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    return BindingCaller<JSTestCEReactionsStringifier>::attribute<jsTestCEReactionsStringifierValueGetter>(state, thisValue, "value");
}

static inline JSValue jsTestCEReactionsStringifierValueGetter(ExecState& state, JSTestCEReactionsStringifier& thisObject, ThrowScope& throwScope)
{
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(state);
    auto& impl = thisObject.wrapped();
    JSValue result = toJS<IDLDOMString>(state, impl.value());
    return result;
}

EncodedJSValue jsTestCEReactionsStringifierConstructor(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    JSTestCEReactionsStringifierPrototype* domObject = jsDynamicDowncast<JSTestCEReactionsStringifierPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!domObject))
        return throwVMTypeError(state, throwScope);
    return JSValue::encode(JSTestCEReactionsStringifier::getConstructor(state->vm(), domObject->globalObject()));
}

bool setJSTestCEReactionsStringifierConstructor(ExecState* state, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    JSValue value = JSValue::decode(encodedValue);
    JSTestCEReactionsStringifierPrototype* domObject = jsDynamicDowncast<JSTestCEReactionsStringifierPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!domObject)) {
        throwVMTypeError(state, throwScope);
        return false;
    }
    // Shadowing a built-in constructor
    return domObject->putDirect(state->vm(), state->propertyNames().constructor, value);
}

static inline bool setJSTestCEReactionsStringifierValueFunction(ExecState&, JSTestCEReactionsStringifier&, JSValue, ThrowScope&);

bool setJSTestCEReactionsStringifierValue(ExecState* state, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    return BindingCaller<JSTestCEReactionsStringifier>::setAttribute<setJSTestCEReactionsStringifierValueFunction>(state, thisValue, encodedValue, "value");
}

static inline bool setJSTestCEReactionsStringifierValueFunction(ExecState& state, JSTestCEReactionsStringifier& thisObject, JSValue value, ThrowScope& throwScope)
{
    UNUSED_PARAM(state);
    UNUSED_PARAM(throwScope);
    CustomElementReactionStack customElementReactionStack;
    auto& impl = thisObject.wrapped();
    auto nativeValue = convert<IDLDOMString>(state, value);
    RETURN_IF_EXCEPTION(throwScope, false);
    impl.setValue(WTFMove(nativeValue));
    return true;
}


JSValue JSTestCEReactionsStringifier::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestCEReactionsStringifierConstructor>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

static inline JSC::EncodedJSValue jsTestCEReactionsStringifierPrototypeFunctionToStringCaller(JSC::ExecState*, JSTestCEReactionsStringifier*, JSC::ThrowScope&);

EncodedJSValue JSC_HOST_CALL jsTestCEReactionsStringifierPrototypeFunctionToString(ExecState* state)
{
    return BindingCaller<JSTestCEReactionsStringifier>::callOperation<jsTestCEReactionsStringifierPrototypeFunctionToStringCaller>(state, "toString");
}

static inline JSC::EncodedJSValue jsTestCEReactionsStringifierPrototypeFunctionToStringCaller(JSC::ExecState* state, JSTestCEReactionsStringifier* castedThis, JSC::ThrowScope& throwScope)
{
    UNUSED_PARAM(state);
    UNUSED_PARAM(throwScope);
    auto& impl = castedThis->wrapped();
    return JSValue::encode(toJS<IDLDOMString>(*state, impl.value()));
}

bool JSTestCEReactionsStringifierOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, SlotVisitor& visitor)
{
    UNUSED_PARAM(handle);
    UNUSED_PARAM(visitor);
    return false;
}

void JSTestCEReactionsStringifierOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    auto* jsTestCEReactionsStringifier = static_cast<JSTestCEReactionsStringifier*>(handle.slot()->asCell());
    auto& world = *static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, &jsTestCEReactionsStringifier->wrapped(), jsTestCEReactionsStringifier);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestCEReactionsStringifier@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore26TestCEReactionsStringifierE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject* globalObject, Ref<TestCEReactionsStringifier>&& impl)
{

#if ENABLE(BINDING_INTEGRITY)
    void* actualVTablePointer = *(reinterpret_cast<void**>(impl.ptr()));
#if PLATFORM(WIN)
    void* expectedVTablePointer = reinterpret_cast<void*>(__identifier("??_7TestCEReactionsStringifier@WebCore@@6B@"));
#else
    void* expectedVTablePointer = &_ZTVN7WebCore26TestCEReactionsStringifierE[2];
#if COMPILER(CLANG)
    // If this fails TestCEReactionsStringifier does not have a vtable, so you need to add the
    // ImplementationLacksVTable attribute to the interface definition
    static_assert(__is_polymorphic(TestCEReactionsStringifier), "TestCEReactionsStringifier is not polymorphic");
#endif
#endif
    // If you hit this assertion you either have a use after free bug, or
    // TestCEReactionsStringifier has subclasses. If TestCEReactionsStringifier has subclasses that get passed
    // to toJS() we currently require TestCEReactionsStringifier you to opt out of binding hardening
    // by adding the SkipVTableValidation attribute to the interface IDL definition
    RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    return createWrapper<TestCEReactionsStringifier>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, TestCEReactionsStringifier& impl)
{
    return wrap(state, globalObject, impl);
}

TestCEReactionsStringifier* JSTestCEReactionsStringifier::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicDowncast<JSTestCEReactionsStringifier*>(vm, value))
        return &wrapper->wrapped();
    return nullptr;
}

}
