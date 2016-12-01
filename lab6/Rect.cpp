#include "Rect.h"
#include <cmath>
#include <iostream>
#include <typeinfo>

Rect::Rect()
    : topLeft_{}
    , bottomRight_{}
{
}

Rect::Rect(const Point &topLeft, const Point &bottomRight)
    : topLeft_{topLeft}
    , bottomRight_{bottomRight}
{
}

Rect::Rect(double left, double right, double top, double bottom)
    : topLeft_{left, top}
    , bottomRight_{right, bottom}
{
}

Point Rect::topLeft() const
{
    return topLeft_;
}

void Rect::setTopLeft(const Point &topLeft)
{
    topLeft_ = topLeft;
}

Point Rect::bottomRight() const
{
    return bottomRight_;
}

void Rect::setBottomRight(const Point &bottomRight)
{
    bottomRight_ = bottomRight;
}

double Rect::top() const
{
    return topLeft_.y();
}

double Rect::bottom() const
{
    return bottomRight_.y();
}

double Rect::left() const
{
    return topLeft_.x();
}

double Rect::right() const
{
    return bottomRight_.x();
}

Point Rect::center() const
{
    return {right() - left(), bottom() - top()};
}

IShape *Rect::clone() const
{
    return new Rect(*this);
}

bool Rect::operator ==(const IShape &other) const
{
    return typeid(other) == typeid(*this) ?
                *this == static_cast<const Rect &>(other) :
                false;
}

double Rect::square() const
{
    const Point &vector = topLeft_ - bottomRight_;

    return std::abs(vector.x() * vector.y());
}

void Rect::print(std::ostream &os) const
{
    os << "Rect(" << topLeft_ << ", " << bottomRight_ << ')';
}

bool Rect::operator ==(const Rect &other) const
{
    return AbstractColoredShape::operator == (other) &&
            topLeft_ == other.topLeft_ &&
            bottomRight_ == other.bottomRight_;
}

