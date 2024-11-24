#include <iostream>
#include <fstream> 
#include <stdexcept>
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
        while (begin != nullptr) {
            Node* temp = begin;
            begin = begin->next;
            delete temp;
        }
        end = nullptr;
    }

    void print() {
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
            //throw std::out_of_range("Index out of range");
            return begin;
        } else if (index > len()) {
            //throw std::out_of_range("Index out of range");
            return end;
        }
        Node* ptr = begin;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->next;
        }
        return ptr;
    }

    int append(int _data) {
        try {
            Node* obj = new Node(_data);
        if (is_empty()) {
            begin = end = obj;
        } else {
            end->next = obj;
            end = obj;
        } 
        } catch (const std::exception& e) {std::cerr << e.what();}
        return 0;
    }

    Node* insert(int _data, int index) {
        Node* obj = new Node(_data);
        if (is_empty()) {
            begin = end = obj;
        } else {
            Node* ptr = get_node(index - 1);
            obj->next = ptr->next;
            ptr->next = obj;
            /* obj->next = begin;
            begin = obj; */ 
        }
        return obj;
    }

    void cut() {
        if (!is_empty()) {
            Node* buffer = begin;
            begin = begin->next;
            delete buffer;
            if (begin == nullptr) {
                end = nullptr;
            }
        }
    }
    int pop(int x) {
        if (x < 0 || x >= len()) {return -1;} 
        else {
            Node* ptr = get_node(x - 1);
            Node* ptr_next = get_node(x);
            ptr->next = ptr_next->next;
            delete ptr_next;
            return 0;
        }
    }
    Node* search(int value) {
        for (int i{}; i < len(); i++) {
            Node* node = get_node(i);
            if (value == node->data) {return node;}
        }
        return new Node(-1);
    }
private:
    bool is_empty() {
        if (len() == 0) {return true;} else {return false;}
    }

    Node* begin;
    Node* end;
};

