/*
 * Copyright (C) 2016 Apple Inc. All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef ParsedContentRange_h
#define ParsedContentRange_h

#include <wtf/Forward.h>

namespace WebCore {

class ParsedContentRange {
public:
    WEBCORE_EXPORT explicit ParsedContentRange(const String&);
    ParsedContentRange() { }
    WEBCORE_EXPORT ParsedContentRange(int64_t firstBytePosition, int64_t lastBytePosition, int64_t instanceLength);

    bool isValid() const { return m_isValid; }
    int64_t firstBytePosition() const { return m_firstBytePosition; }
    int64_t lastBytePosition() const { return m_lastBytePosition; }
    int64_t instanceLength() const { return m_instanceLength; }

    WEBCORE_EXPORT String headerValue() const;

    enum { UnknownLength = std::numeric_limits<int64_t>::max() };

private:
    template<typename T> static bool isPositive(T);

    int64_t m_firstBytePosition { 0 };
    int64_t m_lastBytePosition { 0 };
    int64_t m_instanceLength { UnknownLength };
    bool m_isValid { false };
};

}

#endif
