#pragma once

#include <iostream>

template <typename T>
void printContainer(const T &container){
    std::cout << '{';
    for (auto it = container.cbegin(), end = container.cend(); it != end; ++it){
        std::cout << *it << ", ";
    }
    if (!container.empty()){
        std::cout << "\b\b";
    }
    std::cout << '}';
}

template <typename T>
void reverse(T &container){
    for (auto it = container.begin(), end = container.end(); it != end && ++it != end; --end){
        std::swap(*it, *end);
    }
}

template <typename T>
T reversedContainer(const T &container){
    return T(container.crbegin(), container.crend());
}