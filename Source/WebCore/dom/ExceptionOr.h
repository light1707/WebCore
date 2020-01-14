/*

Copyright (C) 2016-2017 Apple Inc. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1.  Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
2.  Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#pragma once

#include "Exception.h"
#include <wtf/CrossThreadCopier.h>
#include <wtf/Expected.h>

namespace WebCore {

template<typename ReturnType> class ExceptionOr {
public:
    ExceptionOr(Exception&&);
    ExceptionOr(ReturnType&&);
    template<typename OtherType> ExceptionOr(const OtherType&, typename std::enable_if<std::is_scalar<OtherType>::value && std::is_convertible<OtherType, ReturnType>::value>::type* = nullptr);

    bool hasException() const;
    const Exception& exception() const;
    Exception&& releaseException();
    const ReturnType& returnValue() const;
    ReturnType&& releaseReturnValue();
    
private:
    Expected<ReturnType, Exception> m_value;
};

template<typename ReturnReferenceType> class ExceptionOr<ReturnReferenceType&> {
public:
    ExceptionOr(Exception&&);
    ExceptionOr(ReturnReferenceType&);

    bool hasException() const;
    const Exception& exception() const;
    Exception&& releaseException();
    const ReturnReferenceType& returnValue() const;
    ReturnReferenceType& releaseReturnValue();
    
private:
    ExceptionOr<ReturnReferenceType*> m_value;
};

template<> class ExceptionOr<void> {
public:
    ExceptionOr(Exception&&);
    ExceptionOr() = default;

    bool hasException() const;
    const Exception& exception() const;
    Exception&& releaseException();

private:
    Expected<void, Exception> m_value;
};

ExceptionOr<void> isolatedCopy(ExceptionOr<void>&&);

template<typename ReturnType> inline ExceptionOr<ReturnType>::ExceptionOr(Exception&& exception)
    : m_value(makeUnexpected(WTFMove(exception)))
{
}

template<typename ReturnType> inline ExceptionOr<ReturnType>::ExceptionOr(ReturnType&& returnValue)
    : m_value(WTFMove(returnValue))
{
}

template<typename ReturnType> template<typename OtherType> inline ExceptionOr<ReturnType>::ExceptionOr(const OtherType& returnValue, typename std::enable_if<std::is_scalar<OtherType>::value && std::is_convertible<OtherType, ReturnType>::value>::type*)
    : m_value(static_cast<ReturnType>(returnValue))
{
}

template<typename ReturnType> inline bool ExceptionOr<ReturnType>::hasException() const
{
    return !m_value.has_value();
}

template<typename ReturnType> inline const Exception& ExceptionOr<ReturnType>::exception() const
{
    return m_value.error();
}

template<typename ReturnType> inline Exception&& ExceptionOr<ReturnType>::releaseException()
{
    return WTFMove(m_value.error());
}

template<typename ReturnType> inline const ReturnType& ExceptionOr<ReturnType>::returnValue() const
{
    return m_value.value();
}

template<typename ReturnType> inline ReturnType&& ExceptionOr<ReturnType>::releaseReturnValue()
{
    return WTFMove(m_value.value());
}

template<typename ReturnReferenceType> inline ExceptionOr<ReturnReferenceType&>::ExceptionOr(Exception&& exception)
    : m_value(WTFMove(exception))
{
}

template<typename ReturnReferenceType> inline ExceptionOr<ReturnReferenceType&>::ExceptionOr(ReturnReferenceType& returnValue)
    : m_value(&returnValue)
{
}

template<typename ReturnReferenceType> inline bool ExceptionOr<ReturnReferenceType&>::hasException() const
{
    return m_value.hasException();
}

template<typename ReturnReferenceType> inline const Exception& ExceptionOr<ReturnReferenceType&>::exception() const
{
    return m_value.exception();
}

template<typename ReturnReferenceType> inline Exception&& ExceptionOr<ReturnReferenceType&>::releaseException()
{
    return m_value.releaseException();
}

template<typename ReturnReferenceType> inline const ReturnReferenceType& ExceptionOr<ReturnReferenceType&>::returnValue() const
{
    return *m_value.returnValue();
}

template<typename ReturnReferenceType> inline ReturnReferenceType& ExceptionOr<ReturnReferenceType&>::releaseReturnValue()
{
    return *m_value.releaseReturnValue();
}

inline ExceptionOr<void>::ExceptionOr(Exception&& exception)
    : m_value(makeUnexpected(WTFMove(exception)))
{
}

inline bool ExceptionOr<void>::hasException() const
{
    return !m_value.has_value();
}

inline const Exception& ExceptionOr<void>::exception() const
{
    return m_value.error();
}

inline Exception&& ExceptionOr<void>::releaseException()
{
    return WTFMove(m_value.error());
}

inline ExceptionOr<void> isolatedCopy(ExceptionOr<void>&& value)
{
    if (value.hasException())
        return isolatedCopy(value.releaseException());
    return { };
}

}

namespace WTF {
template<typename T> struct CrossThreadCopierBase<false, false, WebCore::ExceptionOr<T> > {
    typedef WebCore::ExceptionOr<T> Type;
    static Type copy(const Type& source)
    {
        if (source.hasException())
            return crossThreadCopy(source.exception());
        return crossThreadCopy(source.returnValue());
    }
};
}
