#pragma once

#include "Node.h"
#include <cstddef>
#include <iosfwd>
#include <functional>

class IShape;

class List
{
    friend std::ostream &operator << (std::ostream &os, const List &list);
public:
    List();
    ~List();

    void append(const IShape &shape);
    void prepend(const IShape &shape);
    bool removeFirst(const IShape &shape);

private:
    void glueHeadToTail();
    void sort(std::function<bool(const IShape &left, const IShape &right)> compareFunction);

private:
    Node head_;
    Node tail_;
    size_t size_;
};
