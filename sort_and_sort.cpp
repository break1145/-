//
// Created by break on 2023/11/30.
//
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

//希尔排序
vector<int> shell_Sort(vector<int>& a) {
    for(int gap = a.size() / 2; gap > 0; gap /= 2) {
        for(int i = gap; i < a.size(); ++i) {
            int tmp = a[i];
            int j;
            for(j = i; j >= gap && a[j - gap] > tmp; j -= gap) {
                a[j] = a[j - gap];
            }
            a[j] = tmp;
        }
    }
    return a;
}
//快速排序
int part(vector<int>& arr , int low , int high) {
    int target = arr[high];
    int i = low - 1;
    for(int j = low;j < high;j ++) {
        if(arr[j] <= target) {
            i ++;
            swap(arr[i] , arr[j]);
        }
    }
    swap(arr[i+1] , arr[high]);
    return i + 1;
}
void q_Sort(vector<int>& a , int low , int high) {
    if(low < high) {
        int p = part(a , low , high);
        q_Sort(a , low , p - 1);
        q_Sort(a , p + 1 , high);
    }
}
//选择排序
void selectSort(vector<int>& arr) {
    for(int i = 0;i < arr.size() - 1 ; i ++) {
        int min_IDX = i;
        for(int j = i + 1 ; j < arr.size();j ++) {
            if(arr[j] < arr[min_IDX]) {
                min_IDX = j;
            }
        }
        swap(arr[i] , arr[min_IDX]);
    }
}
//堆排序
void heapi(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapi(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapi(arr, n, i);
    }

    for (int i = n - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);

        heapi(arr, i, 0);
    }
}

