#include "List.h"
#include "Shape.h"

List::List()
    : head_{}
    , tail_{}
    , size_{}
{
    glueHeadToTail();
}

void List::append(const Shape &shape)
{
    new Node(&tail_, shape);
    ++size_;
}

void List::prepend(const Shape &shape)
{
    new Node(head_.next, shape);
    ++size_;
}

bool List::removeFirst(const Shape &shape)
{
    for (Node *p = head_.next; p != &tail_; p = p->next){
        if (*p->shapePtr == shape){
            delete p;
            --size_;
            return true;
        }
    }

    return false;
}

void List::glueHeadToTail()
{
    head_.next = &tail_;
    tail_.prev = &head_;
}


std::ostream &operator <<(std::ostream &os, const List &list)
{
    for (Node *p = list.head_.next; p != &list.tail_; p = p->next){
        os << *p->shapePtr;
    }
    return os;
}
