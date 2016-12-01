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
    {
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

        Node<T> *currentNode = top_;
        top_ = top_->prev_;
        delete currentNode;

        return result;
    }

    T operator[] (size_t i) const{
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

private:
    Node<T> *node(size_t i) const{
        assert(i < size_);

        Node<T> *result = top_;
        for (int j = 0; j < size_ - 1 - i; ++j){
            result = result->prev_;
        }
        return result;
    }

private:
    Node<T> *top_;
    size_t size_;
};
