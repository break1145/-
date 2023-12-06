#include <iostream>

using namespace std;
template<typename T>
struct Node{
    T val;
    Node* next;
    Node* pre;
    Node(T x){
        val = x;
        next = nullptr;
        pre = nullptr;
    };
};

template<typename T>
class myStack{
private:
    int Size;
    Node<T>* _top;
public:
    myStack(){
        this->Size = 0;
        this->_top = nullptr;
    }
    int size()const {
        return this->Size;
    }
    bool empty()const {
        return this->Size == 0;
    }
    void push(const T &x){
        auto new_Node = new Node(x);
        if(this->empty()){
            _top = new_Node;
            Size ++;
        }else{
            new_Node->pre = _top;
            _top->next = new_Node;
            _top = new_Node;
            Size ++;
        }
    }
    auto top() -> T const{
        return this->_top->val;
    }
    bool pop() {
        if (empty()) {
            return false;
        } else {
            if (Size == 1) {
                delete _top;
                _top = nullptr;
            } else {
                auto new_Top = _top->pre;
                delete _top;
                _top = new_Top;
                new_Top->next = nullptr;
            }
            Size--;
            return true;
        }
    }

    ~myStack(){
        while(!this->empty()){
            this->pop();
        }
    };
};
template<typename T>
class myQueue{
private:
    int count;
    Node<T> * head;
    Node<T> * tail;
public:
    myQueue(){
        count = 0;
        head = tail = nullptr;
    }
    [[nodiscard]] int size() const{
        return this->count;
    }
    [[nodiscard]] bool empty() const{
        return this->size() == 0;
    }
    void push(T x){
        auto new_N0de = new Node(x);
        if(this->empty()){
            head = new_N0de;
            tail = new_N0de;
        }
        else{
            tail->next = new_N0de;
            new_N0de->pre = tail;
            new_N0de->next = nullptr;
            tail = new_N0de;
        }
        count ++;
    }
    void pop(){
        if(this->empty()){
            return;
        }
        else{
            if(this->size() == 1){
                delete head;
                head = tail = nullptr;
            }
            else{
                auto tmp = head->next;
                delete head;
                tmp->pre = nullptr;
                head = tmp;
            }
            count--;
        }

    }
    auto front() ->T &{
        return this->head->val;
    }
~myQueue(){
        while(!this->empty()){
        this->pop();
    }
}

};

void judge_Palindromic(const string& str){
    auto q = new myQueue<char>;
    auto s = new myStack<char>;
    for(auto c : str){
        s->push(c);
        q->push(c);
    }
    bool flag = true;
    while(!s->empty() && !q->empty()){
        auto c1 = s->top();
        auto c2 = q->front();
        s->pop();
        q->pop();
        if(c1 != c2){
            flag = false;
            break;
        }
    }
    if(flag){
        cout<<str<<" is a palindromic string" << endl;
    }
    else{
        cout<<str<<" is not a palindromic string" << endl;
    }
    delete s;
    delete q;
}


int main(){
    string str1 = "abcdcba";
    string str2 = "abcdefg";
    judge_Palindromic(str1);
    judge_Palindromic(str2);

}
