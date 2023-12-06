//
// Created by break on 2023/11/17.
//

#ifndef UNTITLED1_MYFIND_H
#define UNTITLED1_MYFIND_H

#include <vector>
using std::vector;

template<typename T>
class myFind {


public:
    static typename vector<T>::iterator OrderSearch(vector<T>::iterator begin ,
                                    vector<T>::iterator end ,
                                    T value);
    static typename vector<T>::iterator BinarySearch(vector<T>::iterator begin ,
                                            vector<T>::iterator end ,
                                            T value);

};

#include "myFind.tpp"
#endif //UNTITLED1_MYFIND_H
