#include <iostream>
#include <algorithm>
using namespace std;

template<class T>
class SList {
private:
    int max_Size;
    int count;
    T *elems;

public:
    SList(int maxsize) {
        this->max_Size = maxsize;
        this->count = 0;
        elems = new T[maxsize];
    }

    ~SList() { // 析构函数，释放动态分配的内存
        delete[] elems;
    }

    int Length() {
        return this->count;
    }

    int max_Length() {
        return this->max_Size;
    }

    bool IsEmpty() {
        return this->count == 0;
    }

    bool set_Elem(int position, T a) {
        if (position >= 0 && position < max_Size) {
            elems[position] = a;
            count++;
            return true;
        }
        return false;
    }

    void output_List() const {
        for (int i = 0; i < count; i++) {
            cout << elems[i] << ' ';
        }
    }

    void Swap(int pos1, int pos2) {
        if (pos1 >= 0 && pos1 < count && pos2 >= 0 && pos2 < count) {
            swap(elems[pos1], elems[pos2]);
        }
        else{
            cerr<<"swap error:out of range"<< endl;
        }
    }
    void reverse( T* _begin , T* _end){
        if(_begin == nullptr || _end == nullptr){
            cerr<<"reverse error: pointer out of range"<< endl;
            return;
        }else{
            while(_begin < _end){
                swap(*_begin , *_end);
                _begin ++;
                _end --;
            }
        }
    }
    T* get_Ptr(int position) const {
        if(position < 0 || position > max_Size){
            cerr << "get pointer error:position out of range";
            return nullptr;
        }
        else{
            return & elems[position];
        }
    }

};

int main() {
    auto slist = new SList<int>(20);
    for (int i = 0; i <= 10; i++) {
        slist->set_Elem(i, i);
    }
    slist->output_List();
    cout << endl;
    slist->reverse(slist->get_Ptr(0) , slist->get_Ptr(10));
    slist->output_List();
    delete slist; // 释放动态分配的内存
    return 0;
}
