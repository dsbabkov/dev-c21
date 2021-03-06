#include "Point.h"
#include <cmath>
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

bool Point::operator <(const Point &other) const
{
    return vectorLength() < other.vectorLength();
}

double Point::vectorLength() const
{
    return std::sqrt(pow(x_, 2) + pow(y_, 2));
}


std::ostream &operator <<(std::ostream &os, const Point &point)
{
    os << '{' << point.x() << "; " << point.y() << '}';
    return os;
}
