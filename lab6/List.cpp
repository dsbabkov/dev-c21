#include "IShape.h"
#include "List.h"
#include "Point.h"
#include <iostream>

List::List()
    : head_{}
    , tail_{}
    , size_{}
{
    glueHeadToTail();
}

List::List(const List &other)
    : head_{}
    , tail_{}
    , size_{other.size_}
{
    glueHeadToTail();
    for (const Node *p = other.head_.next; p != &other.tail_; p = p->next){
        new Node(&tail_, *p->shapePtr);
    }
}

List::List(List &&other)
    : head_{}
    , tail_{}
    , size_{other.size_}
{
    if (other.head_.next == &other.tail_){
        glueHeadToTail();
        return;
    }

    moveMiddleNodes(other);
}

List::~List()
{
    clear();
}

List &List::operator =(const List &other)
{
    if (this == &other){
        return *this;
    }

    Node *pOther = other.head_.next;
    for (Node *pThis = head_.next; pOther != &other.tail_ && pThis != &tail_; pOther = pOther->next, pThis = pThis->next){
        *pThis = *pOther;
    }

    if (size_ > other.size_){
        for (size_t i = 0, end = size_ - other.size_; i < end; ++i){
            delete tail_.prev;
        }
    }
    else {
        while (pOther != &other.tail_){
            new Node(&tail_, *pOther->shapePtr);
        }
    }

    size_ = other.size_;
    return *this;
}

List &List::operator = (List &&other)
{
    if (this == &other){
        return *this;
    }

    clear();
    if (other.head_.next == &other.tail_){
        return *this;
    }
    size_ = other.size_;
    moveMiddleNodes(other);
    return *this;
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

void List::clear()
{
    while(head_.next != &tail_){
        delete head_.next;
    }
    size_ = 0;
}

void List::sortBySquare()
{
    sort(&List::compareSquare);
    return;
//    sort([](const IShape &left, const IShape &right){
//        return left.square() < right.square();
//    });
}

void List::sortByDistanceFromCenterToNull()
{
    sort(&List::compareDistanceFromCenterToNull);
    return;
//    sort([](const IShape &left, const IShape &right){
//        return left.center().vectorLength() < right.center().vectorLength();
//    });
}

void List::glueHeadToTail()
{
    head_.next = &tail_;
    tail_.prev = &head_;
}

void List::moveMiddleNodes(List &source)
{
    head_.next = source.head_.next;
    head_.next->prev = &head_;

    tail_.prev = source.tail_.prev;
    tail_.prev->next = &tail_;

    source.glueHeadToTail();
    source.size_ = 0;
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

void List::sort(bool (*compare)(const IShape &, const IShape &))
{
    sort([&](const IShape &left, const IShape &right){
        return compare(left, right);
    });
}

bool List::compareSquare(const IShape &left, const IShape &right)
{
    return left.square() < right.square();
}

bool List::compareDistanceFromCenterToNull(const IShape &left, const IShape &right)
{
    return left.center().vectorLength() < right.center().vectorLength();
}


std::ostream &operator <<(std::ostream &os, const List &list)
{
    os << "List size: " << list.size_ << '\n';
    for (Node *p = list.head_.next; p != &list.tail_; p = p->next){
        os << *p->shapePtr
           << " Square:" << p->shapePtr->square()
           << " Center:" << p->shapePtr->center() << '\n';
    }
    return os;
}
