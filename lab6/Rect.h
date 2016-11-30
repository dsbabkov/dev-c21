#pragma once

#include "Point.h"
#include "AbstractColoredShape.h"

class Rect: public AbstractColoredShape
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

    virtual IShape *clone() const override;
    virtual bool operator ==(const IShape &other) const override;
    virtual double square() const override;
    virtual void print(std::ostream &os) const override;

    bool operator == (const Rect &other) const;

private:
    Point topLeft_;
    Point bottomRight_;
};
