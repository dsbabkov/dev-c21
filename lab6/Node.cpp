#include "Node.h"
#include "Shape.h"

Node::Node()
    : next{}
    , prev{}
    , shapePtr{}
{
}

Node::Node(Node *before, const Shape &shape)
    : next{before}
    , prev{before->prev}
    , shapePtr{shape.clone()}
{
    if (before->prev){
        before->prev->next = this;
    }

    if (before->next){
        before->next->prev = this;
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

