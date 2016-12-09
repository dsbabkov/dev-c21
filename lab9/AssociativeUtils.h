#pragma once
#include <iostream>

template <typename C>
void printAssociative(const C &container){
    for (const auto &pair: container){
        std::cout << pair.first << ": " << pair.second << "\n";
    }
}
