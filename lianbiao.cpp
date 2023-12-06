#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
struct Node {
    T value;
    Node* next;
    Node* pre;
    Node(const T& val) {
        value = val;
        next = pre = nullptr;
    }

    bool operator==(const Node<T>& that) const {
        return (this->next == that.next &&
                this->pre == that.pre &&
                this->value == that.value);
    }
};

template<typename T>
class ListTable {
private:
    Node<T>* head;
    Node<T>* tail;
    int count;

public:
    ListTable() {
        head = tail = nullptr;  // 初始化 head 和 tail 为 nullptr
        count = 0;
    }

    void append(const T& value) {
        Node<T>* node = new Node<T>(value);
        if (tail == nullptr) {
            head = tail = node;
        }
        else {
            node->pre = tail;
            tail->next = node;
            tail = node;
        }
        count++;
    }

    void Swap(int pos1, int pos2) {
        if (pos1 == pos2 || pos1 <= 0 || pos1 > count || pos2 <= 0 || pos2 > count) {
            cerr << "swap error: pos out of range" << endl;
            return;
        }

        if (pos1 > pos2) {
            swap(pos1, pos2);
        }

        Node<T>* node1 = nullptr;
        Node<T>* node2 = nullptr;
        Node<T>* prev1 = nullptr;
        Node<T>* prev2 = nullptr;

        Node<T>* current_Node = head;
        Node<T>* prev_Node = nullptr;

        for (int i = 1; i <= count; i++) {
            if (i == pos1) {
                node1 = current_Node;
                prev1 = prev_Node;
            }
            if (i == pos2) {
                node2 = current_Node;
                prev2 = prev_Node;
            }
            prev_Node = current_Node;
            current_Node = current_Node->next;
        }

        if (node1->next == node2) {
            if (prev1) {
                prev1->next = node2;
            } else {
                head = node2;
            }
            node1->next = node2->next;
            node2->next = node1;
            node1->pre = node2;
            node2->pre = prev1;
        } else if (node2->next == node1) {
            if (prev2) {
                prev2->next = node1;
            } else {
                head = node1;
            }
            node2->next = node1->next;
            node1->next = node2;
            node2->pre = node1;
            node1->pre = prev2;
        } else {
            if (prev1) {
                prev1->next = node2;
            } else {
                head = node2;
            }
            if (prev2) {
                prev2->next = node1;
            } else {
                head = node1;
            }
            Node<T>* temp_next = node1->next;
            Node<T>* temp_pre = node1->pre;
            node1->next = node2->next;
            node1->pre = node2->pre;
            node2->next = temp_next;
            node2->pre = temp_pre;
        }
    }


    void output_Table() {
        Node<T>* traverse = head;
        int cnt = 0;
        while (cnt < count) {  // 使用 cnt < count 来判断循环条件
            cout << traverse->value << ' ';
            cnt++;
            traverse = traverse->next;
        }
        cout << endl;
    }

    ~ListTable() {
        Node<T>* current = head;
        while (current) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    auto pTable = new ListTable<int>();
    for (int i = 1; i <= 13; i++) {
        pTable->append(i);
    }
    pTable->output_Table();
    int l = 1, r = 13;
    while (l < r) {
        pTable->Swap(l, r);
        l++;
        r--;
    }
    pTable->output_Table();

    delete pTable;  // 释放内存

    return 0;
}
