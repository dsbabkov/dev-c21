#pragma once

#include "Node.h"
#include <cstddef>
#include <iosfwd>

class List
{
    friend std::ostream &operator << (std::ostream &os, const List &list);
public:
    List();

    void append(const Shape &shape);
    void prepend(const Shape &shape);
    bool removeFirst(const Shape &shape);

private:
    void glueHeadToTail();

private:
    Node head_;
    Node tail_;
    size_t size_;
};
