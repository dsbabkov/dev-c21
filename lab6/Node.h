#pragma once

#include <iosfwd>
#include <memory>

class IShape;
class List;

class Node
{
    friend class List;
    friend std::ostream &operator <<(std::ostream &os, const List &list);
public:
    Node();
    Node(Node *before, const IShape &shape);
    ~Node();

private:
    Node *next;
    Node *prev;
    std::unique_ptr<IShape> shapePtr;
};
