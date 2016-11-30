#include "AbstractColoredShape.h"

AbstractColoredShape::AbstractColoredShape()
    : color_{}
{
}

AbstractColoredShape::Color AbstractColoredShape::color() const
{
    return color_;
}

void AbstractColoredShape::setColor(const Color &color)
{
    color_ = color;
}
