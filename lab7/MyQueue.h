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
        , empty_{true}
    {}

    ~MyQueue(){
        delete[] values_;
    }

    size_t size() const{
        size_t distance = tail_ - head_;
        if (distance){
            return tail_ >= head_ ?
                        distance :
                        capasity_ + distance;
        }
        else{
            return empty_ ? 0 :capasity_;
        }
    }

    bool isEmpty() const{
        return empty_;
    }

    void reserve(size_t elementCount){
        if (elementCount <= capasity_){
            return;
        }

        T *newValues = new T[elementCount];
        T *p = newValues;
        if (head_ >= tail_ && !empty_){
            p = std::copy(&values_[head_], &values_[capasity_], p);
            p = std::copy(values_, &values_[tail_], p);
        }
        else{
            p = std::copy(&values_[head_], &values_[tail_], p);
        }

        delete[] values_;
        values_ = newValues;
        head_ = 0;
        tail_ = std::distance(newValues, p);
        capasity_ = elementCount;
    }

    void push(const T &value){
        if (!canPush()){
            size_t size = capasity_;
            reserve(size + 1);
            tail_ = size;
        }

        values_[tail_++] = value;
        if (tail_ == capasity_){
            tail_ = 0;
        }
        empty_ = false;
    }

    T pop(){
        if (empty_){
            throw QueueUnderflowException("Queue underflow");
        }

        size_t resultIndex = head_++;
        if (head_ == capasity_){
            head_ = 0;
        }
        empty_ = head_ == tail_;
        return std::move(values_[resultIndex]);
    }

private:
    bool canPush() const{
        return head_ != tail_ ||
                (empty_ && capasity_);
    }

private:
    T *values_;
    size_t capasity_;
    size_t head_;
    size_t tail_;
    bool empty_;
};
