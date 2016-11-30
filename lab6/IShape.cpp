#include "IShape.h"

IShape::IShape()
{
}

IShape::~IShape()
{
}

bool IShape::operator !=(const IShape &other) const
{
    return !(*this == other);
}

std::ostream &operator <<(std::ostream &os, const IShape &shape)
{
    shape.print(os);
    return os;
}
