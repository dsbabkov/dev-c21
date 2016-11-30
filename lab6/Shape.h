#pragma once

#include <iosfwd>

class Shape
{
public:
    enum Color{
        Black,
        Red
    };

public:
    Shape();
    virtual ~Shape();

    Color color() const;
    void setColor(const Color &color);

    virtual Shape *clone() const = 0;
    virtual double square() const = 0;
    virtual bool operator == (const Shape &other) const = 0;
    bool operator != (const Shape &other) const;

    virtual void print(std::ostream &os) const = 0;

private:
    Color color_;
};

std::ostream &operator << (std::ostream &os, const Shape &shape);
