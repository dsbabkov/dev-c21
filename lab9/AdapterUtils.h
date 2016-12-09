#pragma once
#include <iostream>
#include <queue>

template <typename C>
void printAdapter(const C &adapter, typename C::const_reference (C::*topVal)() const){
    C copy(adapter);
    while (!copy.empty()) {
        std::cout << (copy.*topVal)() << ' ';
        copy.pop();
    }
    std::cout << '\n';
}

template <typename C>
typename C::const_reference adapterTop(const C &adapter){
    return adapter.top();
}

template <typename T,typename C>
const T &adapterTop(const std::queue<T,C> &adapter){
    return adapter.front();
}


template <typename C>
void printAdapter( C adapter){

    while (!adapter.empty()) {
        std::cout << adapterTop(adapter) << ' ';
        adapter.pop();
    }
    std::cout << '\n';
}
