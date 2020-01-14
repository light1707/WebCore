/*
 * Copyright (C) 2004, 2005, 2006 Nikolas Zimmermann <zimmermann@kde.org>
 * Copyright (C) 2004, 2005, 2006, 2007 Rob Buis <buis@kde.org>
 * Copyright (C) 2007-2019 Apple Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "config.h"
#include "SVGLengthValue.h"

#include "AnimationUtilities.h"
#include "CSSPrimitiveValue.h"
#include "SVGParserUtilities.h"
#include <wtf/text/StringConcatenateNumbers.h>
#include <wtf/text/TextStream.h>

namespace WebCore {

static inline const char* lengthTypeToString(SVGLengthType lengthType)
{
    switch (lengthType) {
    case SVGLengthType::Unknown:
    case SVGLengthType::Number:
        return "";    
    case SVGLengthType::Percentage:
        return "%";
    case SVGLengthType::Ems:
        return "em";
    case SVGLengthType::Exs:
        return "ex";
    case SVGLengthType::Pixels:
        return "px";
    case SVGLengthType::Centimeters:
        return "cm";
    case SVGLengthType::Millimeters:
        return "mm";
    case SVGLengthType::Inches:
        return "in";
    case SVGLengthType::Points:
        return "pt";
    case SVGLengthType::Picas:
        return "pc";
    }

    ASSERT_NOT_REACHED();
    return "";
}

static inline SVGLengthType parseLengthType(const UChar* ptr, const UChar* end)
{
    if (ptr == end)
        return SVGLengthType::Number;

    const UChar firstChar = *ptr;

    if (++ptr == end)
        return firstChar == '%' ? SVGLengthType::Percentage : SVGLengthType::Unknown;

    const UChar secondChar = *ptr;

    if (++ptr != end)
        return SVGLengthType::Unknown;

    if (firstChar == 'e' && secondChar == 'm')
        return SVGLengthType::Ems;
    if (firstChar == 'e' && secondChar == 'x')
        return SVGLengthType::Exs;
    if (firstChar == 'p' && secondChar == 'x')
        return SVGLengthType::Pixels;
    if (firstChar == 'c' && secondChar == 'm')
        return SVGLengthType::Centimeters;
    if (firstChar == 'm' && secondChar == 'm')
        return SVGLengthType::Millimeters;
    if (firstChar == 'i' && secondChar == 'n')
        return SVGLengthType::Inches;
    if (firstChar == 'p' && secondChar == 't')
        return SVGLengthType::Points;
    if (firstChar == 'p' && secondChar == 'c')
        return SVGLengthType::Picas;

    return SVGLengthType::Unknown;
}

static inline SVGLengthType primitiveTypeToLengthType(unsigned short primitiveType)
{
    switch (primitiveType) {
    case CSSPrimitiveValue::CSS_UNKNOWN:
        return SVGLengthType::Unknown;
    case CSSPrimitiveValue::CSS_NUMBER:
        return SVGLengthType::Number;
    case CSSPrimitiveValue::CSS_PERCENTAGE:
        return SVGLengthType::Percentage;
    case CSSPrimitiveValue::CSS_EMS:
        return SVGLengthType::Ems;
    case CSSPrimitiveValue::CSS_EXS:
        return SVGLengthType::Exs;
    case CSSPrimitiveValue::CSS_PX:
        return SVGLengthType::Pixels;
    case CSSPrimitiveValue::CSS_CM:
        return SVGLengthType::Centimeters;
    case CSSPrimitiveValue::CSS_MM:
        return SVGLengthType::Millimeters;
    case CSSPrimitiveValue::CSS_IN:
        return SVGLengthType::Inches;
    case CSSPrimitiveValue::CSS_PT:
        return SVGLengthType::Points;
    case CSSPrimitiveValue::CSS_PC:
        return SVGLengthType::Picas;
    }

    return SVGLengthType::Unknown;
}

static inline CSSPrimitiveValue::UnitType lengthTypeToPrimitiveType(SVGLengthType lengthType)
{
    switch (lengthType) {
    case SVGLengthType::Unknown:
        return CSSPrimitiveValue::CSS_UNKNOWN;
    case SVGLengthType::Number:
        return CSSPrimitiveValue::CSS_NUMBER;
    case SVGLengthType::Percentage:
        return CSSPrimitiveValue::CSS_PERCENTAGE;
    case SVGLengthType::Ems:
        return CSSPrimitiveValue::CSS_EMS;
    case SVGLengthType::Exs:
        return CSSPrimitiveValue::CSS_EXS;
    case SVGLengthType::Pixels:
        return CSSPrimitiveValue::CSS_PX;
    case SVGLengthType::Centimeters:
        return CSSPrimitiveValue::CSS_CM;
    case SVGLengthType::Millimeters:
        return CSSPrimitiveValue::CSS_MM;
    case SVGLengthType::Inches:
        return CSSPrimitiveValue::CSS_IN;
    case SVGLengthType::Points:
        return CSSPrimitiveValue::CSS_PT;
    case SVGLengthType::Picas:
        return CSSPrimitiveValue::CSS_PC;
    }

    ASSERT_NOT_REACHED();
    return CSSPrimitiveValue::CSS_UNKNOWN;
}

SVGLengthValue::SVGLengthValue(SVGLengthMode lengthMode, const String& valueAsString)
    : m_lengthMode(lengthMode)
{
    setValueAsString(valueAsString);
}

SVGLengthValue::SVGLengthValue(float valueInSpecifiedUnits, SVGLengthType lengthType, SVGLengthMode lengthMode)
    : m_valueInSpecifiedUnits(valueInSpecifiedUnits)
    , m_lengthType(lengthType)
    , m_lengthMode(lengthMode)
{
    ASSERT(m_lengthType != SVGLengthType::Unknown);
}

SVGLengthValue::SVGLengthValue(const SVGLengthContext& context, float value, SVGLengthType lengthType, SVGLengthMode lengthMode)
    : m_lengthType(lengthType)
    , m_lengthMode(lengthMode)
{
    setValue(context, value);
}

SVGLengthValue SVGLengthValue::construct(SVGLengthMode lengthMode, const String& valueAsString, SVGParsingError& parseError, SVGLengthNegativeValuesMode negativeValuesMode)
{
    SVGLengthValue length(lengthMode);

    if (length.setValueAsString(valueAsString).hasException())
        parseError = ParsingAttributeFailedError;
    else if (negativeValuesMode == SVGLengthNegativeValuesMode::Forbid && length.valueInSpecifiedUnits() < 0)
        parseError = NegativeValueForbiddenError;

    return length;
}

SVGLengthValue SVGLengthValue::blend(const SVGLengthValue& from, const SVGLengthValue& to, float progress)
{
    if ((from.isZero() && to.isZero())
        || from.lengthType() == SVGLengthType::Unknown
        || to.lengthType() == SVGLengthType::Unknown
        || (!from.isZero() && from.lengthType() != SVGLengthType::Percentage && to.lengthType() == SVGLengthType::Percentage)
        || (!to.isZero() && from.lengthType() == SVGLengthType::Percentage && to.lengthType() != SVGLengthType::Percentage)
        || (!from.isZero() && !to.isZero() && (from.lengthType() == SVGLengthType::Ems || from.lengthType() == SVGLengthType::Exs) && from.lengthType() != to.lengthType()))
        return to;

    if (from.lengthType() == SVGLengthType::Percentage || to.lengthType() == SVGLengthType::Percentage) {
        auto fromPercent = from.valueAsPercentage() * 100;
        auto toPercent = to.valueAsPercentage() * 100;
        return { WebCore::blend(fromPercent, toPercent, progress), SVGLengthType::Percentage };
    }

    if (from.lengthType() == to.lengthType() || from.isZero() || to.isZero() || from.isRelative()) {
        auto fromValue = from.valueInSpecifiedUnits();
        auto toValue = to.valueInSpecifiedUnits();
        return { WebCore::blend(fromValue, toValue, progress), to.isZero() ? from.lengthType() : to.lengthType() };
    }

    SVGLengthContext nonRelativeLengthContext(nullptr);
    auto fromValueInUserUnits = nonRelativeLengthContext.convertValueToUserUnits(from.valueInSpecifiedUnits(), from.lengthType(), from.lengthMode());
    if (fromValueInUserUnits.hasException())
        return { };

    auto fromValue = nonRelativeLengthContext.convertValueFromUserUnits(fromValueInUserUnits.releaseReturnValue(), to.lengthType(), to.lengthMode());
    if (fromValue.hasException())
        return { };

    float toValue = to.valueInSpecifiedUnits();
    return { WebCore::blend(fromValue.releaseReturnValue(), toValue, progress), to.lengthType() };
}

SVGLengthValue SVGLengthValue::fromCSSPrimitiveValue(const CSSPrimitiveValue& value)
{
    SVGLengthType lengthType = primitiveTypeToLengthType(value.primitiveType());
    return lengthType == SVGLengthType::Unknown ? SVGLengthValue() : SVGLengthValue(value.floatValue(), lengthType);
}

Ref<CSSPrimitiveValue> SVGLengthValue::toCSSPrimitiveValue(const SVGLengthValue& length)
{
    return CSSPrimitiveValue::create(length.valueInSpecifiedUnits(), lengthTypeToPrimitiveType(length.lengthType()));
}

ExceptionOr<void> SVGLengthValue::setValueAsString(const String& valueAsString, SVGLengthMode lengthMode)
{
    m_valueInSpecifiedUnits = 0;
    m_lengthMode = lengthMode;
    m_lengthType = SVGLengthType::Number;
    return setValueAsString(valueAsString);
}

float SVGLengthValue::value(const SVGLengthContext& context) const
{
    auto result = valueForBindings(context);
    if (result.hasException())
        return 0;
    return result.releaseReturnValue();
}

String SVGLengthValue::valueAsString() const
{
    return makeString(FormattedNumber::fixedPrecision(m_valueInSpecifiedUnits), lengthTypeToString(m_lengthType));
}

ExceptionOr<float> SVGLengthValue::valueForBindings(const SVGLengthContext& context) const
{
    return context.convertValueToUserUnits(m_valueInSpecifiedUnits, m_lengthType, m_lengthMode);
}

ExceptionOr<void> SVGLengthValue::setValue(const SVGLengthContext& context, float value)
{
    // 100% = 100.0 instead of 1.0 for historical reasons, this could eventually be changed
    if (m_lengthType == SVGLengthType::Percentage)
        value = value / 100;

    auto convertedValue = context.convertValueFromUserUnits(value, m_lengthType, m_lengthMode);
    if (convertedValue.hasException())
        return convertedValue.releaseException();
    m_valueInSpecifiedUnits = convertedValue.releaseReturnValue();
    return { };
}

ExceptionOr<void> SVGLengthValue::setValue(const SVGLengthContext& context, float value, SVGLengthType lengthType, SVGLengthMode lengthMode)
{
    // FIXME: Seems like a bug that we change the value of m_unit even if setValue throws an exception.
    m_lengthMode = lengthMode;
    m_lengthType = lengthType;
    return setValue(context, value);
}

ExceptionOr<void> SVGLengthValue::setValueAsString(const String& string)
{
    if (string.isEmpty())
        return { };

    float convertedNumber = 0;
    auto upconvertedCharacters = StringView(string).upconvertedCharacters();
    const UChar* ptr = upconvertedCharacters;
    const UChar* end = ptr + string.length();

    if (!parseNumber(ptr, end, convertedNumber, false))
        return Exception { SyntaxError };

    auto lengthType = parseLengthType(ptr, end);
    if (lengthType == SVGLengthType::Unknown)
        return Exception { SyntaxError };

    m_lengthType = lengthType;
    m_valueInSpecifiedUnits = convertedNumber;
    return { };
}

ExceptionOr<void> SVGLengthValue::convertToSpecifiedUnits(const SVGLengthContext& context, SVGLengthType lengthType)
{
    auto valueInUserUnits = valueForBindings(context);
    if (valueInUserUnits.hasException())
        return valueInUserUnits.releaseException();

    auto originalLengthType = m_lengthType;
    m_lengthType = lengthType;
    auto result = setValue(context, valueInUserUnits.releaseReturnValue());
    if (!result.hasException())
        return { };

    m_lengthType = originalLengthType;
    return result.releaseException();
}

TextStream& operator<<(TextStream& ts, const SVGLengthValue& length)
{
    ts << length.valueAsString();
    return ts;
}

}
