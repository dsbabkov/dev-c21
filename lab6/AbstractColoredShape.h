#pragma once

#include "IShape.h"

class AbstractColoredShape: public IShape
{
    enum Color{
        Black,
        Red
    };

public:
    AbstractColoredShape();

    Color color() const;
    void setColor(const Color &color);

    bool operator == (const AbstractColoredShape &other) const;

private:
    Color color_;    
};
