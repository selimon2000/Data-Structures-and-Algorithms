#pragma once

#include <iostream>
#include <stack>

using namespace std;


template <class T>
class linked_list {
private:
    struct node;

    node* head = nullptr;

    // Unwrapped function declarations
    void printListRecursiveUW(node* cur);
    void printReverseListRecursiveUW(node* cur);
    void reverseListRecursiveUW(node* cur);

public:
    void push_back(T val);
    void push_front(T val);
    bool insert(unsigned int pos, T val);
    void printHead();
    void printTail();
    void printList();
    void printReverseList();
    void printListRecursive();
    void printReverseListRecursive();
    int size();
    void popFront();
    void popBack();
    void erase(unsigned int pos);
    void reverseList();
    void reverseListRecursive();
    ~linked_list();
};


#include "linked_list.tpp"