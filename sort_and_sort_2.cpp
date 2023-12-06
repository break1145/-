//
// Created by break on 2023/11/30.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void countSort(std::vector<int>& arr, int exp) {
    const int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(std::vector<int>& array) {
    int max = *std::max_element(array.begin(), array.end());

    // 从最低位开始，对每一位进行计数排序
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(array, exp);
    }
}



