#include <iostream>


class node {
public:
    node() : data(0),
             next(nullptr){};
    node(int new_data) : data(new_data),
                         next(nullptr){};
    node(int new_data, node* new_next) : data(new_data),
                                         next(new_next){};

    int data;
    node* next;
};


void insertAtHead(node** tail, int data) {
    // If list is empty
    if (*tail == nullptr) {
        *tail = new node(data);
        (*tail)->next = *tail;
    }

    else {
        node* new_node = new node(data, (*tail)->next);
        (*tail)->next = new_node;
    }
}

void insertAtTail(node** tail, int data) {
    // If list is empty
    if (*tail == nullptr) {
        *tail = new node(data);
        (*tail)->next = *tail;
    }
    else {
        node* new_node = new node(data, (*tail)->next);
        (*tail)->next = new_node;
        *tail = new_node;
    }
}

void deletetAtHead(node** tail) {
    // If there is only one node
    if ((*tail)->next == *tail) {
        delete *tail;
        *tail = nullptr;
    }

    else {
    node* old_head = (*tail)->next;
    (*tail)->next = old_head->next;
    delete old_head;
    }
}

void deleteAtTail(node** tail) {
    // If there is only one node
    if ((*tail)->next == *tail) {
        delete *tail;
        *tail = nullptr;
    }

    else {
    // Traverse to node before tail
    node* head = (*tail)->next;
    node* current = (*tail)->next;
    while (current->next != *tail)
        current = current->next;

    delete current->next;
    *tail = current;
    (*tail)->next = head;
    }
}

void printList (node* tail) {
    if (tail == nullptr)
        std::cout << "List is empty so printList cancelled" << std::endl;
    
    else {
        node* current = tail->next;
        for (; current != tail; current = current->next)
            std::cout << current->data << ", ";

        std::cout << current->data << std::endl << std::endl;
    }
}

int size (node* tail) {
    if (tail == nullptr)
        return 0;
    
    int i = 1;
    for (node* current = tail->next; current != tail; current = current->next, i++);
    return i;    
}

int main() {
    node *tail =  nullptr;
    printList(tail);
    std::cout << "Size of list: " << size(tail) << std::endl << std::endl;

    insertAtTail(&tail, 1);
    printList(tail);
    std::cout << "Size of list: " << size(tail) << std::endl << std::endl;

    deletetAtHead(&tail);
    printList(tail);
    std::cout << "Size of list: " << size(tail) << std::endl << std::endl;

    insertAtTail(&tail, 2);
    insertAtTail(&tail, 3);
    insertAtTail(&tail, 4);
    insertAtTail(&tail, 5);

    insertAtHead(&tail, 0);
    insertAtHead(&tail, -1);
    insertAtHead(&tail, -2);

    printList(tail);
    std::cout << "Size of list: " << size(tail) << std::endl << std::endl;

    deletetAtHead(&tail);
    deletetAtHead(&tail);
    printList(tail);
    std::cout << "Size of list: " << size(tail) << std::endl << std::endl;

    deleteAtTail(&tail);
    printList(tail);
    std::cout << "Size of list: " << size(tail) << std::endl << std::endl;
}