#include "List.h"
#include "IShape.h"
#include <iostream>

List::List()
    : head_{}
    , tail_{}
    , size_{}
{
    glueHeadToTail();
}

List::~List()
{
    while(head_.next != &tail_){
        delete head_.next;
    }
}

void List::append(const IShape &shape)
{
    new Node(&tail_, shape);
    ++size_;
}

void List::prepend(const IShape &shape)
{
    new Node(head_.next, shape);
    ++size_;
}

bool List::removeFirst(const IShape &shape)
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

void List::sort(std::function<bool (const IShape &, const IShape &)> compareFunction)
{
    for (Node *p1 = head_.next; p1 != &tail_; p1 = p1->next){
        for (Node *p2 = p1->next; p2 != &tail_; p2 = p2->next){
            if (compareFunction(*p2->shapePtr, *p1->shapePtr)){
                std::swap(p1->shapePtr, p2->shapePtr);
            }
        }
    }
}


std::ostream &operator <<(std::ostream &os, const List &list)
{
    for (Node *p = list.head_.next; p != &list.tail_; p = p->next){
        os << *p->shapePtr << '\n';
    }
    return os;
}