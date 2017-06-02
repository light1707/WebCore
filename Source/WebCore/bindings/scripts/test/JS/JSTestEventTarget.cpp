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
#include "JSTestEventTarget.h"

#include "JSDOMBinding.h"
#include "JSDOMBindingCaller.h"
#include "JSDOMConstructorNotConstructable.h"
#include "JSDOMConvert.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMWrapperCache.h"
#include "JSNode.h"
#include <runtime/Error.h>
#include <runtime/PropertyNameArray.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsTestEventTargetPrototypeFunctionItem(JSC::ExecState*);

// Attributes

JSC::EncodedJSValue jsTestEventTargetConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSTestEventTargetConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::EncodedJSValue);

class JSTestEventTargetPrototype : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestEventTargetPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestEventTargetPrototype* ptr = new (NotNull, JSC::allocateCell<JSTestEventTargetPrototype>(vm.heap)) JSTestEventTargetPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestEventTargetPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};

using JSTestEventTargetConstructor = JSDOMConstructorNotConstructable<JSTestEventTarget>;

template<> JSValue JSTestEventTargetConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    return JSEventTarget::getConstructor(vm, &globalObject);
}

template<> void JSTestEventTargetConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestEventTarget::prototype(vm, globalObject), DontDelete | ReadOnly | DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(&vm, String(ASCIILiteral("TestEventTarget"))), ReadOnly | DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), ReadOnly | DontEnum);
}

template<> const ClassInfo JSTestEventTargetConstructor::s_info = { "TestEventTarget", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestEventTargetConstructor) };

/* Hash table for prototype */

static const HashTableValue JSTestEventTargetPrototypeTableValues[] =
{
    { "constructor", DontEnum, NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestEventTargetConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestEventTargetConstructor) } },
    { "item", JSC::Function, NoIntrinsic, { (intptr_t)static_cast<NativeFunction>(jsTestEventTargetPrototypeFunctionItem), (intptr_t) (1) } },
};

const ClassInfo JSTestEventTargetPrototype::s_info = { "TestEventTargetPrototype", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestEventTargetPrototype) };

void JSTestEventTargetPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestEventTargetPrototypeTableValues, *this);
}

const ClassInfo JSTestEventTarget::s_info = { "TestEventTarget", &Base::s_info, 0, CREATE_METHOD_TABLE(JSTestEventTarget) };

JSTestEventTarget::JSTestEventTarget(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestEventTarget>&& impl)
    : JSEventTarget(structure, globalObject, WTFMove(impl))
{
}

void JSTestEventTarget::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

}

JSObject* JSTestEventTarget::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestEventTargetPrototype::create(vm, &globalObject, JSTestEventTargetPrototype::createStructure(vm, &globalObject, JSEventTarget::prototype(vm, globalObject)));
}

JSObject* JSTestEventTarget::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestEventTarget>(vm, globalObject);
}

bool JSTestEventTarget::getOwnPropertySlot(JSObject* object, ExecState* state, PropertyName propertyName, PropertySlot& slot)
{
    auto* thisObject = jsCast<JSTestEventTarget*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    auto optionalIndex = parseIndex(propertyName);
    if (optionalIndex && optionalIndex.value() < thisObject->wrapped().length()) {
        auto index = optionalIndex.value();
        slot.setValue(thisObject, ReadOnly, toJS<IDLInterface<Node>>(*state, *thisObject->globalObject(), thisObject->wrapped().item(index)));
        return true;
    }
    if (Base::getOwnPropertySlot(thisObject, state, propertyName, slot))
        return true;
    JSValue proto = thisObject->getPrototypeDirect();
    if (proto.isObject() && jsCast<JSObject*>(proto)->hasProperty(state, propertyName))
        return false;

    if (!optionalIndex && thisObject->classInfo() == info() && !propertyName.isSymbol()) {
        auto item = thisObject->wrapped().namedItem(propertyNameToAtomicString(propertyName));
        if (!IDLInterface<Node>::isNullValue(item)) {
            slot.setValue(thisObject, ReadOnly, toJS<IDLInterface<Node>>(*state, *thisObject->globalObject(), item));
            return true;
        }
    }
    return false;
}

bool JSTestEventTarget::getOwnPropertySlotByIndex(JSObject* object, ExecState* state, unsigned index, PropertySlot& slot)
{
    auto* thisObject = jsCast<JSTestEventTarget*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    if (LIKELY(index < thisObject->wrapped().length())) {
        slot.setValue(thisObject, ReadOnly, toJS<IDLInterface<Node>>(*state, *thisObject->globalObject(), thisObject->wrapped().item(index)));
        return true;
    }
    return Base::getOwnPropertySlotByIndex(thisObject, state, index, slot);
}

void JSTestEventTarget::getOwnPropertyNames(JSObject* object, ExecState* state, PropertyNameArray& propertyNames, EnumerationMode mode)
{
    auto* thisObject = jsCast<JSTestEventTarget*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    for (unsigned i = 0, count = thisObject->wrapped().length(); i < count; ++i)
        propertyNames.add(Identifier::from(state, i));
    for (auto& propertyName : thisObject->wrapped().supportedPropertyNames())
        propertyNames.add(Identifier::fromString(state, propertyName));
    Base::getOwnPropertyNames(thisObject, state, propertyNames, mode);
}

template<> inline JSTestEventTarget* BindingCaller<JSTestEventTarget>::castForOperation(ExecState& state)
{
    return jsDynamicDowncast<JSTestEventTarget*>(state.vm(), state.thisValue());
}

EncodedJSValue jsTestEventTargetConstructor(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    JSTestEventTargetPrototype* domObject = jsDynamicDowncast<JSTestEventTargetPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!domObject))
        return throwVMTypeError(state, throwScope);
    return JSValue::encode(JSTestEventTarget::getConstructor(state->vm(), domObject->globalObject()));
}

bool setJSTestEventTargetConstructor(ExecState* state, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    JSValue value = JSValue::decode(encodedValue);
    JSTestEventTargetPrototype* domObject = jsDynamicDowncast<JSTestEventTargetPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!domObject)) {
        throwVMTypeError(state, throwScope);
        return false;
    }
    // Shadowing a built-in constructor
    return domObject->putDirect(state->vm(), state->propertyNames().constructor, value);
}

JSValue JSTestEventTarget::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestEventTargetConstructor>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

static inline JSC::EncodedJSValue jsTestEventTargetPrototypeFunctionItemCaller(JSC::ExecState*, JSTestEventTarget*, JSC::ThrowScope&);

EncodedJSValue JSC_HOST_CALL jsTestEventTargetPrototypeFunctionItem(ExecState* state)
{
    return BindingCaller<JSTestEventTarget>::callOperation<jsTestEventTargetPrototypeFunctionItemCaller>(state, "item");
}

static inline JSC::EncodedJSValue jsTestEventTargetPrototypeFunctionItemCaller(JSC::ExecState* state, JSTestEventTarget* castedThis, JSC::ThrowScope& throwScope)
{
    UNUSED_PARAM(state);
    UNUSED_PARAM(throwScope);
    auto& impl = castedThis->wrapped();
    if (UNLIKELY(state->argumentCount() < 1))
        return throwVMError(state, throwScope, createNotEnoughArgumentsError(state));
    auto index = convert<IDLUnsignedLong>(*state, state->uncheckedArgument(0));
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    return JSValue::encode(toJS<IDLInterface<Node>>(*state, *castedThis->globalObject(), impl.item(WTFMove(index))));
}

void JSTestEventTarget::visitChildren(JSCell* cell, SlotVisitor& visitor)
{
    auto* thisObject = jsCast<JSTestEventTarget*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    Base::visitChildren(thisObject, visitor);
}

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestEventTarget@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore15TestEventTargetE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject* globalObject, Ref<TestEventTarget>&& impl)
{

#if ENABLE(BINDING_INTEGRITY)
    void* actualVTablePointer = *(reinterpret_cast<void**>(impl.ptr()));
#if PLATFORM(WIN)
    void* expectedVTablePointer = reinterpret_cast<void*>(__identifier("??_7TestEventTarget@WebCore@@6B@"));
#else
    void* expectedVTablePointer = &_ZTVN7WebCore15TestEventTargetE[2];
#if COMPILER(CLANG)
    // If this fails TestEventTarget does not have a vtable, so you need to add the
    // ImplementationLacksVTable attribute to the interface definition
    static_assert(__is_polymorphic(TestEventTarget), "TestEventTarget is not polymorphic");
#endif
#endif
    // If you hit this assertion you either have a use after free bug, or
    // TestEventTarget has subclasses. If TestEventTarget has subclasses that get passed
    // to toJS() we currently require TestEventTarget you to opt out of binding hardening
    // by adding the SkipVTableValidation attribute to the interface IDL definition
    RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    return createWrapper<TestEventTarget>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, TestEventTarget& impl)
{
    return wrap(state, globalObject, impl);
}

TestEventTarget* JSTestEventTarget::toWrapped(JSC::VM& vm, JSC::JSValue value)
{
    if (auto* wrapper = jsDynamicDowncast<JSTestEventTarget*>(vm, value))
        return &wrapper->wrapped();
    return nullptr;
}

}
