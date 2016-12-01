#pragma once

#include "Point.h"
#include "AbstractColoredShape.h"

class Circle: public AbstractColoredShape
{
public:
    Circle();
    Circle(const Point &center, double radius);

    Point center() const;
    void setCenter(const Point &center);
    double radius() const;
    void setRadius(double radius);

    virtual IShape *clone() const override;
    virtual double square() const override;
    virtual bool operator ==(const IShape &other) const override;
    virtual void print(std::ostream &os) const override;
    virtual double distanceFromCenterToNull() const override;
    bool operator ==(const Circle &other) const;

private:
    Point center_;
    double radius_;
};
