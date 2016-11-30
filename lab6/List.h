#pragma once

#include "Node.h"
#include <cstddef>
#include <iosfwd>

class List
{
    friend std::ostream &operator << (std::ostream &os, const List &list);
public:
    List();

    void append(const IShape &shape);
    void prepend(const IShape &shape);
    bool removeFirst(const IShape &shape);

private:
    void glueHeadToTail();

private:
    Node head_;
    Node tail_;
    size_t size_;
};
