#include "Node.h"
#include "IShape.h"

Node::Node()
    : next{}
    , prev{}
    , shapePtr{}
{
}

Node::Node(Node *before, const IShape &shape)
    : next{before}
    , prev{before->prev}
    , shapePtr{shape.clone()}
{
    next->prev = this;

    if (prev){
        prev->next = this;
    }
}

Node::~Node()
{
    if (prev){
        prev->next = next;
    }

    if (next){
        next->prev = prev;
    }
}

void Node::swapNeighbours(Node &other)
{
    std::swap(prev, other.prev);
    std::swap(next, other.next);
}

