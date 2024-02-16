#include <iostream>


class Node {
public:
    Node(int data_, Node *next_ = nullptr, Node *prev_ = nullptr) : data(data_),
                                                                    next(next_),
                                                                    prev(prev_){};
    int data;
    Node* next;
    Node* prev;
};


class LinkedList {
public:
    LinkedList() : head(nullptr),
                   tail(nullptr){};

    void insertAtHead(int data);
    void insertAtTail(int data);

    void printLinkedList();
    void printLinkedListReverse();

private:
    Node* head;
    Node* tail;
};

void LinkedList::insertAtHead(int data) {
    Node* new_node = new Node(data);

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    }
    else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void LinkedList::insertAtTail(int data) {
    Node* new_node = new Node(data);

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    }
    else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }

}

void LinkedList::printLinkedList() {
    for (Node* current = head; current != NULL; current = current->next) {
        std::cout << current->data << ", ";
    }
}

void LinkedList::printLinkedListReverse() {
    for (Node* current = tail; current != NULL; current = current->prev)
        std::cout << current->data << ", ";    
}


int main() {
    LinkedList my_list;

    my_list.insertAtHead(3);
    my_list.insertAtHead(2);
    my_list.insertAtHead(1);

    my_list.insertAtTail(4);
    my_list.insertAtTail(5);
    my_list.insertAtTail(6);

    my_list.printLinkedList();
    std::cout << std::endl << std::endl;

    my_list.printLinkedListReverse();
    std::cout << std::endl << std::endl;
}