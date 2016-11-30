#pragma once

#include "Point.h"
#include "Shape.h"

class Rect: public Shape
{
public:
    Rect();
    Rect(const Point &topLeft, const Point &bottomRight);
    Rect(double left, double right, double top, double bottom);

    Point topLeft() const;
    void setTopLeft(const Point &topLeft);

    Point bottomRight() const;
    void setBottomRight(const Point &bottomRight);

    double top() const;
    double bottom() const;
    double left() const;
    double right() const;

    virtual Shape *clone() const override;
    virtual bool operator ==(const Shape &other) const override;
    virtual double square() const override;
    virtual void print(std::ostream &os) const override;

    bool operator == (const Rect &other) const;

private:
    Point topLeft_;
    Point bottomRight_;
};
