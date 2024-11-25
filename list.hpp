#ifndef LIST_H
#define LIST_H



#include <iostream>
#include <fstream> 
#include <stdexcept>

/*
 * класс Node - это элемент линейного списка
 * он хранит данные и указатель на следующий Node
 */
class Node {
public:
    Node(int _data) : data(_data), next_(nullptr) {}
    int data;
    Node* next_;
};

/*
 * класс List - это линейный список
 */
class List {
public:
    /*
     * функция print - выводит все элементы списка
     */
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

    /*
     * функция len - возвращает количество элементов списка
     */
    int len() const {
        int length = 0;
        Node* ptr = begin;
        while (ptr != nullptr) {
            ++length;
            ptr = ptr->next_;
        }
        return length;
    }

    /*
     * функция get_node - возвращает указатель на node по индексу
     */
    Node* get_node(int index) const {
        if (!(0 < index <= len())) {return nullptr;}
        Node* ptr = begin;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->next_;
        }
        return ptr;
    }

    /*
     * функция append - добавляет новый Node в конец списка
     */
    int append(int _data) {
        Node* obj = new Node(_data);
        if (is_empty()) {
            begin = end = obj;
        } else {
            end->next_ = obj;
            end = obj;
            return 0;
        }   
    }

    /*
     * функция insert - добавляет новый Node в список
     */
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

    /*
     * функция cut - удаляет Node из начала списка
     */
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
    /*
     * функция pop - удаляет Node по индексу
     */
    int pop(int x) {
        if (x < 0 || x >= len()) {return -1;} 
        else {
            Node* ptr = get_node(x - 1);
            Node* ptr_next = get_node(x);
            ptr->next_ = ptr_next->next_;
            delete ptr_next;
            return 0;
        }
    }

    /*
     * функция search - ищет Node по значению
     */
    Node* search(int value) {
        for (int i{}; i < len(); i++) {
            Node* node = get_node(i);
            if (value == node->data) {return node;}
        }
        return new Node(-1);
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
