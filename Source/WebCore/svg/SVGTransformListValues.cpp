/*
 * Copyright (C) 2004, 2005, 2008 Nikolas Zimmermann <zimmermann@kde.org>
 * Copyright (C) 2004, 2005 Rob Buis <buis@kde.org>
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
#include "SVGTransformListValues.h"

#include "AffineTransform.h"
#include "SVGSVGElement.h"
#include "SVGTransformable.h"
#include <wtf/text/StringBuilder.h>

namespace WebCore {

Ref<SVGTransform> SVGTransformListValues::createSVGTransformFromMatrix(SVGMatrix& matrix) const
{
    return SVGSVGElement::createSVGTransformFromMatrix(matrix);
}

Ref<SVGTransform> SVGTransformListValues::consolidate()
{
    AffineTransform matrix;
    if (!concatenate(matrix))
        return SVGTransform::create();

    SVGTransformValue transform(matrix);
    clear();
    append(transform);
    return SVGTransform::create(transform);
}

bool SVGTransformListValues::concatenate(AffineTransform& result) const
{
    unsigned size = this->size();
    if (!size)
        return false;

    for (unsigned i = 0; i < size; ++i)
        result *= at(i).matrix();

    return true;
}

String SVGTransformListValues::valueAsString() const
{
    StringBuilder builder;
    unsigned size = this->size();
    for (unsigned i = 0; i < size; ++i) {
        if (i > 0)
            builder.append(' ');

        builder.append(at(i).valueAsString());
    }

    return builder.toString();
}

void SVGTransformListValues::parse(const String& transform)
{
    auto upconvertedCharacters = StringView(transform).upconvertedCharacters();
    const UChar* start = upconvertedCharacters;
    if (!SVGTransformable::parseTransformAttribute(*this, start, start + transform.length()))
        clear();
}

} // namespace WebCore
