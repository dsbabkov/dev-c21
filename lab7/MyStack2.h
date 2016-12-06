#pragma once

#include "Node.h"
#include "StackUnderflowException.h"
#include <cassert>
#include <cstddef>
#include <utility>

template <class T>
class MyStack2{
public:
    MyStack2()
        : top_{}
        , size_{}
    {}

    MyStack2(const MyStack2 &other)
        : top_{}
        , size_(other.size_)
    {
        if (!size_){
            return;
        }
        top_ = new Node<T>({}, other.top_->value_);
        Node<T> *tail = top_;
        for (Node<T> *p = other.top_->prev_; p; p = p->prev_){
            Node<T> *currentNode = tail;
            tail = new Node<T>({}, p->value_);
            currentNode->prev_ = tail;
        }
    }

    MyStack2(MyStack2 &&other)
        : top_{other.top_}
        , size_{other.size_}
    {
        other.top_ = {};
        other.size_ = 0;
    }

    MyStack2 &operator = (const MyStack2 &other){
        if (this == &other){
            return *this;
        }

        Node<T> *pOther = other.top_;
        Node<T> *pThis = top_;
        Node<T> *pThisEnd = top_;
        while(pThis && pOther){
            pThis->value_ = pOther->value_;
            pThisEnd = pThis;
            pThis = pThis->prev_;
            pOther = pOther->prev_;
        }

        while (pThis){
            Node<T> *p = pThis;
            pThis = pThis->prev_;
            delete p;
        }

        while (pOther){
            pThisEnd->prev_ = new Node<T>({}, pOther->value_);
            pThisEnd = pThisEnd->prev_;
            pOther = pOther->prev_;
        }

        size_ = other.size_;

        return *this;
    }

    MyStack2 &operator = (MyStack2 &&other){
        if (this == &other){
            return *this;
        }
        clear();
        std::swap(top_, other.top_);
        std::swap(size_, other.size_);
        return *this;
    }

    ~MyStack2(){
        clear();
    }

    void clear(){
        while(top_){
            deleteTop();
        }
        size_ = 0;
    }

    size_t size() const{
        return size_;
    }

    void push(const T &value){
        top_ = new Node<T>(top_, value);
        ++size_;
    }

    T pop(){
        if (!size_){
            throw StackUnderflowException("Stack underflow");
        }

        T result = std::move(top_->value_);
        --size_;
        deleteTop();

        return result;
    }

    const T &operator[] (size_t i) const{
        if (i >= size_){
            throw StackOutOfRangeException("Stack index out of range");
        }

        return node(i)->value_;
    }

    T &operator[] (size_t i){
        if (i >= size_){
            throw StackOutOfRangeException("Stack index out of range");
        }

        return node(i)->value_;
    }

    void printElements() const{
        if (top_){
            top_->printPreviousAndThis();
        }
    }

private:
    Node<T> *node(size_t i) const{
        assert(i < size_);

        Node<T> *result = top_;
        for (int j = 0; j < size_ - 1 - i; ++j){
            result = result->prev_;
        }
        return result;
    }

    void deleteTop(){
        Node<T> *currentNode = top_;
        top_ = top_->prev_;
        delete currentNode;

    }

private:
    Node<T> *top_;
    size_t size_;
};
