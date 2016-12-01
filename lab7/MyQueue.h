#pragma once

#include "QueueUnderflowException.h"

template <class T>
class MyQueue
{
public:
    MyQueue();
    ~MyQueue();

private:
    T *values_;
};
