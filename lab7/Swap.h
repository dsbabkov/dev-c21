#pragma once
#include <utility>

template <class T>
void Swap(T &left, T &right){
    T tmp(std::move(left));
    left = std::move(right);
    right = std::move(tmp);
}
