#include "IShape.h"
#include "BadShapeType.h"
#include <typeinfo>

IShape::IShape()
{
}

IShape::~IShape()
{
}

IShape &IShape::operator =(const IShape &other)
{
    if (typeid(*this) != typeid(other)){
        throw BadShapeType();
    }
    return *this;
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
