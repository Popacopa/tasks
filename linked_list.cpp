#include <iostream>
#include <fstream> 

class Node {
public:
    int data;
    Node* next;
    Node(int _data) : data(_data), next(nullptr){}

};
struct List {
    Node *begin, *end;
    List() : begin(nullptr), end(nullptr){}
    ~List() {
        while (!is_empty()) {this->pop();}
    }
bool is_empty() {
    return begin == nullptr;
}
void print() {
    if (is_empty()) {std::cout << "elements is not exist!";}
    Node* ptr = begin;
    while (ptr != nullptr) {
        if (ptr->next == nullptr) {std::cout << ptr->data << "\n";} else {std::cout << ptr->data << " ";}
        ptr = ptr->next;
    }
}
int len() {
    int lenght{};
    Node* ptr = begin;
    while (ptr != nullptr) {
        lenght++;
        ptr = ptr->next;
    }
    return lenght;
}
Node* get_node(int index) {
    if (index > len() || index < 0) {return nullptr;}
    Node* ptr = begin;
    for (int i{}; i < len(); i++) {
        if (i == index) {return ptr;}
        ptr = ptr->next;
    } 
    return nullptr;  
}
Node* append(int _data) {
    Node* obj = new Node(_data);
    is_empty() ? (begin = end = obj) : (end->next = obj, end = obj);
    return obj;
}
Node* insert(int _data) {
    Node* obj = new Node(_data);
    is_empty() ? (begin = end = obj) : (obj->next = begin, begin = obj);
    return obj;
    }

void pop() {
    Node* buffer = begin->next;
    delete begin;
    begin = buffer;
};
};
int main() {
    List arr;
    Node* b = arr.append(3);
    arr.append(4);
    arr.append(5);
    arr.print();
    std::cout << arr.begin->data << " " << arr.begin->next->data << std::endl;
    arr.insert(2);
    std::cout << arr.begin->data << " " << arr.begin->next->data << std::endl;
    std::cout << arr.len() << "\n";
    std::cout << arr.get_node(3)->data;
    return 0;
}
 