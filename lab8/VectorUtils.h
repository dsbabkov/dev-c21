#pragma once

#include <iostream>
#include <vector>

template <class T>
std::ostream &operator << (std::ostream &os, const std::vector<T> &vec){
    os << "Size: " << vec.size() << "\n"
          "Capasity: " << vec.capacity() << "\n"
          "Max size: " << vec.max_size() << "\n"
          "Values:";
    for (const T &value: vec){
        os << ' ' << value;
    }
    return os;
}

template <class T>
std::vector<T> &operator << (std::vector<T> & vec, const T &value){
    vec.push_back(value);
    return vec;
}

template <class T>
std::vector<T> &operator << (std::vector<T> & vec, T &&value){
    vec.push_back(value);
    return vec;
}
