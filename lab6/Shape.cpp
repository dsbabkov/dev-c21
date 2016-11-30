#include "Shape.h"

Shape::Shape()
    : color_{}
{

}

Shape::~Shape()
{
}

Shape::Color Shape::color() const
{
    return color_;
}

void Shape::setColor(const Color &color)
{
    color_ = color;
}

bool Shape::operator !=(const Shape &other) const
{
    return !(*this == other);
}

std::ostream &operator <<(std::ostream &os, const Shape &shape)
{
    shape.print(os);
    return os;
}
