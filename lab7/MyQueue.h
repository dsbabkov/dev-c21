#pragma once

#include "QueueUnderflowException.h"

template <class T>
class MyQueue
{
public:
    MyQueue()
        : values_{}
        , capasity_{}
        , head_{}
        , tail_{}
    {}

    ~MyQueue(){
        delete[] values_;
    }

    size_t size() const{
        return tail_ >= head_ ?
                    tail_ - head_ :
                    capasity_ - head_ + tail_;
    }

    void reserve(size_t elementCount){
        if (elementCount <= capasity_){
            return;
        }

        size_t newTail = size();
        T *newValues = new T[elementCount];

        T *p = newValues;

        while (head_ != tail_ && head_ != capasity_){
            *p++ = values_[head_++];
        }

        if (head_ != tail_){
            for (size_t i = 0; i < tail_; ++i){
                *p++ = values_[i];
            }
        }

        delete[] values_;
        values_ = newValues;
        head_ = 0;
        tail_ = newTail;
        capasity_ = elementCount;
    }

    void push(const T &value){
        size_t size = this->size();
        if (size == capasity_){
            reserve(size + 1);
        }

        if (tail_ == capasity_){
            tail_ = 0;
        }
        values_[tail_++] = value;
    }

    T pop(){
        if (head_ == tail_){
            throw QueueUnderflowException("Queue underflow");
        }

        size_t resultIndex = head_++;
        if (head_ == capasity_){
            head_ = 0;
        }
        return std::move(values_[resultIndex]);
    }


private:
    T *values_;
    size_t capasity_;
    size_t head_;
    size_t tail_;
};
