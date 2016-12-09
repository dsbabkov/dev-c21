#pragma once

#include <algorithm>
#include <iostream>

template <typename C>
void printWithForEach(const C &container){
    std::for_each(container.cbegin(), container.cend(), [&](typename C::const_reference &value){std::cout << value << " ";});
    std::cout << '\n';
}
