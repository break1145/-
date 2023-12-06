//
// Created by break on 2023/11/17.
//


#include <iostream>
#include <stdexcept>
#include <vector>
#include "myFind.h"  // 确保包含了相应的头文件
//myFind.tpp
template<typename T>
typename std::vector<T>::iterator myFind<T>::OrderSearch(typename std::vector<T>::iterator begin,
                                                         typename std::vector<T>::iterator end,
                                                         T value) {
    if (begin > end) {
        throw std::invalid_argument("Error: Invalid iterator range specified in OrderSearch. 'begin' iterator should not be greater than 'end'.\n");
    }
    for (auto it = begin; it != end; it++) {
        if (*it == value) {
            return it;
        }
    }
    return end;
}


template<typename T>
typename std::vector<T>::iterator myFind<T>::BinarySearch(typename vector<T>::iterator begin,
                                                          typename vector<T>::iterator end,
                                                          T value) {
    if (begin > end) {
        throw std::invalid_argument("Error: Invalid iterator range specified in OrderSearch. 'begin' iterator should not be greater than 'end'.\n");
    }
    auto l = begin , r = end;
    while(l < r){
        auto mid = l;
        std::advance(mid, std::distance(l, r) / 2);
        if(*mid >= value){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    if (l != end && *l == value) {
        return l;
    } else {
        throw std::invalid_argument("Error: Element not found.\n");
    }


}

