#pragma once

#include "Point.h"
#include "Shape.h"

class Circle: public Shape
{
public:
    Circle();
    Circle(const Point &center, double radius);

    Point center() const;
    void setCenter(const Point &center);
    double radius() const;
    void setRadius(double radius);

    virtual Shape *clone() const override;
    virtual double square() const override;
    virtual bool operator ==(const Shape &other) const override;
    virtual void print(std::ostream &os) const override;
    bool operator ==(const Circle &other) const;

private:
    Point center_;
    double radius_;
};
