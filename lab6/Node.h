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
    Node(Node *prev, Node *next, IShape *shapePtr = {});
    ~Node();

    void swapNeighbours(Node &other);


private:
    Node *next;
    Node *prev;
    std::unique_ptr<IShape> shapePtr;
};
