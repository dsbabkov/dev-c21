#pragma once

#include <iosfwd>

class Point;

class IShape
{
public:
    IShape();
    virtual ~IShape();

    virtual IShape *clone() const = 0;
    virtual double square() const = 0;
    virtual bool operator == (const IShape &other) const = 0;
    bool operator != (const IShape &other) const;

    virtual void print(std::ostream &os) const = 0;
    virtual Point center() const = 0;
};

std::ostream &operator << (std::ostream &os, const IShape &shape);
