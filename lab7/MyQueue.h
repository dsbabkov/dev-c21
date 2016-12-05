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

    MyQueue(const MyQueue &other)
        : values_{new T[other.size()]}
        , capasity_{other.size()}
        , head_{}
        , tail_{}
        , empty_{other.empty_}
    {
        if (empty_){
            return;
        }

        other.copyValues(values_);
    }

    MyQueue(MyQueue &&other)
        : values_{other.values_}
        , capasity_{other.capasity_}
        , head_{other.head_}
        , tail_{other.tail_}
        , empty_{other.empty_}
    {
        other.clearAfterMove();
    }

    MyQueue &operator = (const MyQueue &other){
        if (this == &other){
            return *this;
        }

        size_t size = other.size();
        if (capasity_ < size){
            delete[] values_;
            values_ = new T[size];
            capasity_ = size;
            tail_ = 0;
        }
        else{
            tail_ = capasity_ == size ?
                        0 :
                        size;
        }

        other.copyValues(values_);
        head_ = 0;
        empty_ = other.empty_;
        return *this;
    }

    MyQueue &operator = (MyQueue &&other){
        if (this == &other){
            return *this;
        }

        delete[] values_;
        values_ = other.values_;
        capasity_ = other.capasity_;
        head_ = other.head_;
        tail_ = other.tail_;
        empty_ = other.empty_;

        other.clearAfterMove();
        return *this;
    }

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
        T *newValuesEnd = copyValues(newValues);

        delete[] values_;
        values_ = newValues;
        head_ = 0;
        tail_ = std::distance(newValues, newValuesEnd);
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

    T *copyValues(T *dest) const{
        if (head_ >= tail_ && !empty_){
            dest = std::copy(&values_[head_], &values_[capasity_], dest);
            dest = std::copy(values_, &values_[tail_], dest);
        }
        else{
            dest = std::copy(&values_[head_], &values_[tail_], dest);
        }
        return dest;
    }

    void clearAfterMove(){
        values_ = {};
        capasity_ = 0;
        head_ = tail_ = 0;
        empty_ = true;
    }

private:
    T *values_;
    size_t capasity_;
    size_t head_;
    size_t tail_;
    bool empty_;
};
