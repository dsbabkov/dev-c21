#pragma once

#include "StackOverflowException.h"
#include "StackUnderflowException.h"
#include <cstddef>

template <class T, size_t capasity = 10>
class MyStack{
public:
    MyStack()
        : values_{}
        , size_{}
    {
    }

    size_t size() const{
        return size_;
    }

    void push(const T &value){
        if (size_ == capasity){
            throw StackOverflowException("Stack overflow");
        }

        values_[size_++] = value;
    }

    T pop(){
        if (!size_){
            throw StackUnderflowException("Stack underflow");
        }

        return values_[--size_];
    }

    T operator[] (size_t i) const{
        if (i >= size_){
            throw StackOutOfRangeException("Stack index out of range");
        }

        return values_[i];
    }

    T &operator[] (size_t i){
        if (i >= size_){
            throw StackOutOfRangeException("Stack index out of range");
        }

        return values_[i];
    }

private:
    T values_[capasity];
    size_t size_;
};
