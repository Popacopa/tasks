#include <iostream>
#include <fstream> 

class Node {
public:
    Node(int _data) : data(_data), next(nullptr) {}
    int data;
    Node* next;
};

class List {
public:
    List() : begin(nullptr), end(nullptr) {}
    ~List() {
        while (!is_empty()) {
            pop();
        }
    }

    void print() const {
        if (is_empty()) {
            std::cout << "elements do not exist!\n";
            return;
        }
        Node* ptr = begin;
        while (ptr != nullptr) {
            std::cout << ptr->data << (ptr->next ? " " : "\n");
            ptr = ptr->next;
        }
    }

    int len() const {
        int length = 0;
        Node* ptr = begin;
        while (ptr != nullptr) {
            ++length;
            ptr = ptr->next;
        }
        return length;
    }

    Node* get_node(int index) const {
        if (index < 0) {
            return begin;
        } else if (index > len()) {
            return end;
        }
        Node* ptr = begin;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->next;
        }
        return ptr;
    }

    Node* append(int _data) {
        Node* obj = new Node(_data);
        if (is_empty()) {
            begin = end = obj;
        } else {
            end->next = obj;
            end = obj;
        }
        return obj;
    }

    Node* insert(int _data) {
        Node* obj = new Node(_data);
        if (is_empty()) {
            begin = end = obj;
        } else {
            obj->next = begin;
            begin = obj;
        }
        return obj;
    }

    void pop() {
        if (!is_empty()) {
            Node* buffer = begin->next;
            delete begin;
            begin = buffer;
            if (begin == nullptr) {
                end = nullptr;
            }
        }
    }

private:
    bool is_empty() const {
        return begin == nullptr;
    }

    Node* begin;
    Node* end;
};

