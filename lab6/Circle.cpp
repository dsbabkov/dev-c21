#include "Circle.h"
#include <cmath>
#include <iostream>
#include <typeinfo>

static const double pi = acos(-1);

Circle::Circle()
{

}

Circle::Circle(const Point &center, double radius)
    : center_{center}
    , radius_{radius}
{
}

double Circle::radius() const
{
    return radius_;
}

void Circle::setRadius(double radius)
{
    radius_ = radius;
}

IShape &Circle::operator =(const IShape &other)
{
    IShape::operator =(other);
    Circle::operator =(static_cast<const Circle &>(other));
    return *this;
}

IShape *Circle::clone() const
{
    return new Circle(*this);
}

double Circle::square() const
{
    return pi * pow(radius_, 2);
}

bool Circle::operator ==(const IShape &other) const
{
    return typeid(other) == typeid(*this) ?
                this->Circle::operator ==(static_cast<const Circle &>(other)) :
                false;
}

void Circle::print(std::ostream &os) const
{
    os << "Circle(" << center_ << " R =" << radius_ << ')';
}

bool Circle::operator ==(const Circle &other) const
{
    return AbstractColoredShape::operator == (other) &&
            center_ == other.center_ &&
            radius_ == other.radius_;
}

Point Circle::center() const
{
    return center_;
}

void Circle::setCenter(const Point &center)
{
    center_ = center;
}

