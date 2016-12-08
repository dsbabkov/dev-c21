#pragma once
#include <iostream>

template <typename C>
void printAdapter(const C &adapter, typename C::const_reference (C::*topVal)() const){
    C copy(adapter);
    while (!copy.empty()) {
        std::cout << (copy.*topVal)() << ' ';
        copy.pop();
    }
    std::cout << '\n';
}

