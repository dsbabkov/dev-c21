#include "Node.h"
#include "IShape.h"
#include "BadShapeType.h"

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

Node::Node(Node *prev, Node *next, IShape *shapePtr)
    : next{next}
    , prev{prev}
    , shapePtr{shapePtr}
{
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

Node &Node::operator =(const Node &other)
{
    try {
        *shapePtr = *other.shapePtr;
    }
    catch (BadShapeType &){
        shapePtr.reset(other.shapePtr->clone());
    }
    return *this;
}

void Node::swapNeighbours(Node &other)
{
    std::swap(prev, other.prev);
    std::swap(next, other.next);
}

