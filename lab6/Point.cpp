#include "Point.h"
#include <iostream>

Point::Point()
    : x_{}
    , y_{}
{
}

Point::Point(double x, double y)
    : x_{x}
    , y_{y}
{
}

double Point::x() const
{
    return x_;
}

void Point::setX(double x)
{
    x_ = x;
}

double Point::y() const
{
    return y_;
}

void Point::setY(double y)
{
    y_ = y;
}

Point &Point::operator -=(const Point &other)
{
    x_ -= other.x_;
    y_ -= other.y_;

    return *this;
}

Point &Point::operator +=(const Point &other)
{
    x_ += other.x_;
    y_ += other.y_;

    return *this;
}

Point Point::operator -(const Point &other) const
{
    return {x_ - other.x_,
                y_ - other.y_};
}

Point Point::operator +(const Point &other) const
{
        return {x_ + other.x_,
                    y_ + other.y_};
}

bool Point::operator ==(const Point &other) const
{
    return x_ == other.x_ &&
            y_ == other.y_;
}


std::ostream &operator <<(std::ostream &os, const Point &point)
{
    os << '{' << point.x() << "; " << point.y() << '}';
    return os;
}
