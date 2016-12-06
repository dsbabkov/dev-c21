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
    List(const List &other);
    List(List &&other);
    ~List();

    List &operator = (const List &other);
    List &operator = (List &&other);

    void append(const IShape &shape);
    void prepend(const IShape &shape);
    bool removeFirst(const IShape &shape);

    void clear();

    void sortBySquare();
    void sortByDistanceFromCenterToNull();

private:
    void glueHeadToTail();
    void moveMiddleNodes(List &source);
    void sort(std::function<bool(const IShape &left, const IShape &right)> compareFunction);
    void sort(bool (*compare)(const IShape &left, const IShape &right));

    static bool compareSquare(const IShape &left, const IShape &right);
    static bool compareDistanceFromCenterToNull(const IShape &left, const IShape &right);

private:
    Node head_;
    Node tail_;
    size_t size_;
};
