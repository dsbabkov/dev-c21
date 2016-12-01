#pragma once

#include "StackUnderflowException.h"
#include <cstddef>

template <class T>
class MyStack2{
public:
    MyStack2()
        : values_{}
        , size_{}
    {
    }

    size_t size() const{
        return size_;
    }

    void push(const T &value){
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
    T values_[];
    size_t size_;
};
