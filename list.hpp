#ifndef LIST_H
#define LIST_H


#include <iostream>
#include <fstream> 
#include <stdexcept>

class Node {
public:
    Node(int _data) : data(_data), next_(nullptr) {}
    int data;
    Node* next_;
};

class List {
public:
    void print() {
        if (is_empty()) {
            std::cout << "elements do not exist!\n";
            return;
        }
        Node* ptr = begin;
        while (ptr != nullptr) {
            std::cout << ptr->data << (ptr->next_ ? " " : "\n");
            ptr = ptr->next_;
        }
    }

    int len() const {
        int length = 0;
        Node* ptr = begin;
        while (ptr != nullptr) {
            ++length;
            ptr = ptr->next_;
        }
        return length;
    }

    Node* get_node(int index) const {
        if (!(0 < index <= len())) {return nullptr;}
        Node* ptr = begin;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->next_;
        }
        return ptr;
    }

    Node* search(int value) {
        for (int i{}; i < len(); i++) {
            Node* node = get_node(i);
            if (value == node->data) {return node;}
        }
        return new Node(-1);
    }

    void append(int data) {
        Node* new_node = new Node(data);
        if (is_empty()) {
            begin = end = new_node;
        } else {
            end->next_ = new_node;
            end = new_node;
        }   
    }

    int insert(int _data, int index = 0) {
        if (!(0 < index <= len())) {return -1;}
        Node* obj = new Node(_data);
        if (is_empty()) {
            begin = end = obj;
        } else if (index == 0){
            obj->next_ = begin;
            begin = obj;
        } else {
            Node* ptr = get_node(index - 1);
            obj->next_ = ptr->next_;
            ptr->next_ = obj;
        }
        return 0;
    }

    int cut() {
        if (!is_empty()) {
            Node* buffer = begin;
            begin = begin->next_;
            delete buffer;
            if (begin == nullptr) {
                end = nullptr;
            }
            return 0;
        } else {
            return -1;
        }
    }

    int pop_end(int index) {
        if (index < 0 || index >= len()) {return -1;} 
        else {
            Node* ptr = get_node(index - 1);
            Node* ptr_next = get_node(index);
            ptr->next_ = ptr_next->next_;
            delete ptr_next;
            return 0;
        }
    }
     
    List() : begin(nullptr), end(nullptr) {}
    ~List() {
        while (begin != nullptr) {
            Node* temp = begin;
            begin = begin->next_;
            delete temp;
        }
        end = nullptr;
    }
private:
    bool is_empty() {
        if (len() == 0) {return true;} else {return false;}
    }

    Node* begin;
    Node* end;
};


#endif

