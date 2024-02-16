#include <iostream>
#include <stack>

class Node {
public:
    Node(int data_ = 0, Node *next_ = nullptr) : data(data_),
                                                 next(next_){};

    int data;
    Node* next;
};


class LinkedList {
public:
    LinkedList() : head(nullptr) {};

    void insertAtHead(int data);
    void insertAtTail(int data);
    void insertAtIndex(int data, int index);

    void deleteAtHead();
    void deleteAtTail();
    void deleteAtIndex(int index);

    void printLinkedList();
    void printLinkedListReverse();

    void printLinkedListRecursive(Node* current_node);
    // Purpose of Wrapper is so that I don't need to enter 'head', especially as it is private
    void printLinkedListRecursiveWrapper();
    void printLinkedListReverseRecursive(Node* current_node);
    void printLinkedListReverseRecursiveWrapper();

    void reverseList();
    void reverseListRecursive(Node* current_node);
    void reverseListRecursiveWrapper();

private:
    Node* head;
};

void LinkedList::insertAtHead(int data) {
    Node *new_node = new Node(data, head);
    head = new_node;
}

void LinkedList::insertAtTail(int data) {
    Node* current_node = head;
    for (; current_node->next != nullptr; current_node = current_node->next);
    Node* new_node = new Node(data);
    new_node->next = current_node->next;
    current_node->next = new_node; 
}

void LinkedList::insertAtIndex(int data, int index) {
    if (index == 0) {
        insertAtHead(data);
        return;
    }
    
    Node* current = head;
    int pos = 0;
    for (; pos < index - 1; pos++, current = current->next) {
        if (current->next->next == NULL)
            std::cout << "[WARNING]/tIndex does not exist in List" << std::endl;
    }
    Node* new_node = new Node(data);
    new_node->next = current->next;
    current->next = new_node;
}

void LinkedList::deleteAtHead() {
    Node* to_delete = head;
    head = head->next;
    delete to_delete;
}

void LinkedList::deleteAtTail() {
    Node* current = head;
    for (; current->next->next != nullptr; current = current->next);

    delete current->next;
    current->next = nullptr;
}

void LinkedList::deleteAtIndex(int index) {
    if (index == 0)
        deleteAtHead();
    
    Node* current = head;
    for (int pos = 0; pos < index - 1; pos++, current = current->next) {
        if (current->next->next == NULL) {
            std::cout << "[WARNING]\tIndex does not fit in list" << std::endl;
            return;
        }
    }
    
    Node* to_delete = current->next;
    current->next = current->next->next;
    delete to_delete;
}

void LinkedList::printLinkedList() {
    for (Node* current = head; current != nullptr; current = current->next) {
        std::cout << current->data << ", ";
    }
    std::cout << std::endl << std::endl;
}

void LinkedList::printLinkedListReverse() {
    std::stack<int> my_stack;
    for (Node* current = head; current != nullptr; current = current->next)
        my_stack.emplace(current->data);
    
    for (; !my_stack.empty(); my_stack.pop())
        std::cout << my_stack.top() << ", ";
    
    std::cout << std::endl << std::endl;
}

void LinkedList::printLinkedListRecursive(Node* current_node) {
    if (current_node == nullptr) {
        return;
    }
    std::cout << current_node->data << ", ";
    printLinkedListRecursive(current_node->next);
}

void LinkedList::printLinkedListRecursiveWrapper() {
    printLinkedListRecursive(head);
}

void LinkedList::printLinkedListReverseRecursive(Node* current_node) {
    if (current_node == nullptr) {
        return;
    }
    printLinkedListReverseRecursive(current_node->next);
    std::cout << current_node->data << ", ";
}

void LinkedList::printLinkedListReverseRecursiveWrapper() {
    printLinkedListReverseRecursive(head);
}

void LinkedList::reverseList() {
    Node* current = head;
    Node* prev = NULL;
    Node* next;

    for (; current != NULL; prev = current, current = next) {
        next = current->next;
        current->next = prev;
    }
    head = prev;
}

void LinkedList::reverseListRecursive(Node* current_node) {
    if (current_node->next == nullptr) {
        head = current_node;
        return;
    }
    reverseListRecursive(current_node->next);
    current_node->next->next = current_node;
    current_node->next = nullptr;
}

void LinkedList::reverseListRecursiveWrapper() {
    reverseListRecursive(head);
}


int main() {
    LinkedList my_list;
    my_list.insertAtHead(4);
    my_list.insertAtHead(3);
    my_list.insertAtHead(2);
    my_list.insertAtHead(1);
    my_list.insertAtHead(0);

    my_list.insertAtTail(5);
    my_list.insertAtTail(6);
    my_list.insertAtTail(7);
    my_list.insertAtTail(8);

    my_list.insertAtIndex(313, 5);

    std::cout << "Printing Linked List:" << std::endl;
    my_list.printLinkedList();

    my_list.deleteAtHead();
    my_list.deleteAtTail();
    my_list.deleteAtIndex(3);
    std::cout << "Printing Linked List after deleting Head and Tail:" << std::endl;
    my_list.printLinkedList();

    std::cout << "Printing Linked List Reverse:" << std::endl;
    my_list.printLinkedListReverse();

    std::cout << "Printing Linked List using Recursion:" << std::endl;
    my_list.printLinkedListRecursiveWrapper();

    std::cout << "\n\nPrinting Linked List reverse using Recursion:" << std::endl;
    my_list.printLinkedListReverseRecursiveWrapper();

    my_list.reverseList();
    std::cout << "\n\nPrinting Linked List after reversing" << std::endl;
    my_list.printLinkedList();

    my_list.reverseListRecursiveWrapper();
    std::cout << "Printing Linked List after reversing again (recursive)" << std::endl;
    my_list.printLinkedList();
}