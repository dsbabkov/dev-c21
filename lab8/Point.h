#pragma once

#include <iosfwd>

class Point
{
public:
    Point();
    Point(double x, double y);

    double x() const;
    void setX(double x);

    double y() const;
    void setY(double y);

    Point &operator -=(const Point &other);
    Point &operator +=(const Point &other);
    Point operator -(const Point &other) const;
    Point operator +(const Point &other) const;

    bool operator == (const Point &other) const;
    bool operator != (const Point &other) const;
    bool operator < (const Point &other) const;

    double vectorLength() const;

private:
    double x_;
    double y_;
};

std::ostream &operator << (std::ostream &os, const Point &point);
