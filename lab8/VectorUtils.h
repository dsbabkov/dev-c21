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

template <class T>
void removePeriodicity(std::vector<T> &vec, size_t i){
    if (i >= vec.size()){
        throw std::out_of_range("Invalid index got to remove periodicity");
    }

    auto first = vec.begin() + i;
    auto last = first + 1;

    for (auto end = vec.end(); last != end && *last == *first; ++last);
    vec.erase(first, last);
}

template <typename T>
size_t detectPeriodicity(const std::vector<T> &vec, size_t hint = 0){
    if (hint >= vec.size() - 1){
        return ~0;
    }

    for (auto it = vec.cbegin() + hint, end = vec.cend() - 1; it != end; ++hint){
        const T &currentValue = *it;
        const T &nextValue = *(++it);
        if (currentValue == nextValue){
            return hint;
        }
    }

    return ~0;
}

template <typename T>
void removePeriodicity(std::vector<T> &vec){
    size_t periodicityIndex = 0;
    while (true){
        periodicityIndex = detectPeriodicity(vec, periodicityIndex);
        if (periodicityIndex >= vec.size()){
            return;
        }
        removePeriodicity(vec, periodicityIndex);
    }

}

template <typename T>
void removeDuplicates(std::vector<T> &vec){
    for (size_t i = 0; i < vec.size() - 1; ++i){
        for (size_t j = i + 1; j < vec.size(); ++j){
            if (vec[i] == vec[j]){
                vec.erase(vec.begin() + j);
                --j;
            }
        }
    }
}
