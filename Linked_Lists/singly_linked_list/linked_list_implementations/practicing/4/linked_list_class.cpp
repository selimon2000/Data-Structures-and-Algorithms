#include <iostream>
#include <stack>


class Node {
public:
    int data;
    Node* next;

    Node(int data_ = 0, Node *next_ = nullptr) : data(data_),
                                                 next(next_) {}
};

class LinkedList {  
public:
    LinkedList() : head(nullptr) {}

    void insertAtHead(int data);
    void insertAtTail(int data);
    void insertAtPos(int data, int pos);

    void deleteAtHead();
    void deleteAtTail();
    void deleteAtPos(int pos);

    void printLinkedList();
    void printLinkedListReverse();
    void printListRecursive();
    void printListReverseRecursive();

    void reverseList();
    void reverseListRecursive();

    Node* searchLinkedList(int data);

private:
    Node* head;

    void printLinkedListRecursiveUnwrapped(Node* current);
    void printLinkedListReverseUnwrapped(Node* current);

    void reverseListRecursiveUnwrapped(Node* current);
};


void LinkedList::insertAtHead(int data) {
    if (head == nullptr)
        head = new Node(data);
    else 
        head = new Node(data, head);
}

void LinkedList::insertAtTail(int data) {
    if (head == nullptr) {insertAtHead(data); return;}
    
    Node *current = head;
    for (; current->next != nullptr; current = current->next);
    current->next = new Node(data);
}

void LinkedList::insertAtPos(int data, int pos) {
    if (head == nullptr || pos == 0) {insertAtHead(data); return;}

    Node* current = head;
    int i = 0;
    for (; i < pos - 1 && current != nullptr; current = current->next, i++);
    if (i != pos - 1)
        std::cout << "[WARNING]\tOut of range" << std::endl;
    else
        current->next = new Node(data, current->next);
}

void LinkedList::deleteAtHead() {
    if (head==nullptr) return;
    
    Node* to_delete = head;
    head = head->next;

    delete to_delete;
}

void LinkedList::deleteAtTail() {
    if (head == nullptr) return;

    Node* current = head;
    for (; current->next->next != nullptr; current = current->next);
    delete current->next;
    current->next = nullptr;
}

void LinkedList::deleteAtPos(int pos) {
    if (head == nullptr || pos == 0) return;

    Node* current = head;
    int i = 0;
    for (; i < pos - 1 && current->next->next != nullptr; i++, current = current->next);

    if (i != pos - 1) {
        std::cout << "[WARNING]\tOut of Bounds" << std::endl;
        return;
    }

    Node* to_delete = current->next;
    current->next = current->next->next;
    delete to_delete;
}

void LinkedList::printLinkedList() {
    std::cout << "Printing Linked List:" << std::endl;
    for (Node *start = head; start != nullptr; start = start->next)
        std::cout << start->data << ", ";
    std::cout << std::endl;
}

void LinkedList::printLinkedListReverse() {
    std::cout << "Printing Linked List Reverse:" << std::endl;

    std::stack<int> reverse_stack;

    Node* current = head;
    for (; current!= nullptr; reverse_stack.push(current->data), current = current->next);

    for (;!reverse_stack.empty();reverse_stack.pop())
        std::cout << reverse_stack.top() << ", ";
    std::cout << std::endl;            
}

void LinkedList::printListRecursive() {
    std::cout << "Printing Linked List Recursive: " << std::endl;
    if (head == nullptr) return;
    
    printLinkedListRecursiveUnwrapped(head);
    std::cout << std::endl;
}

void LinkedList::printLinkedListRecursiveUnwrapped(Node* current) {
    if (current == nullptr)
        return;

    std::cout << current->data << ", ";
    printLinkedListRecursiveUnwrapped(current->next);
}

void LinkedList::printListReverseRecursive() {
    std::cout << "Printing Linked List in Reverse using Recursion:" << std::endl;
    printLinkedListReverseUnwrapped(head);
    std::cout << std::endl;
}

void LinkedList::printLinkedListReverseUnwrapped(Node* current) {
    if (current == nullptr)
        return;

    printLinkedListReverseUnwrapped(current->next);
    std::cout << current->data << ", ";
}

void LinkedList::reverseListRecursiveUnwrapped(Node* current) {
    if (current->next == nullptr) {
        head = current;
        return;
    }   
    reverseListRecursiveUnwrapped(current->next);
    current->next->next = current;
    current->next = nullptr;
}

void LinkedList::reverseListRecursive() {
    std::cout << "Reversing Linked List:" << std::endl;
    reverseListRecursiveUnwrapped(head);
    std::cout << std::endl;
}

void LinkedList::reverseList() {
    std::cout << "Reversing List:" << std::endl;

    Node *prev = nullptr, *current = head, *next; 

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Node* LinkedList::searchLinkedList(int data) {

// }

int main() {
    LinkedList my_list;

    my_list.insertAtHead(3);
    my_list.insertAtHead(2);
    my_list.insertAtHead(1);
    my_list.insertAtHead(0);
    my_list.insertAtTail(4);
    my_list.insertAtTail(5);
    my_list.insertAtTail(6);
    my_list.printLinkedList();

    my_list.insertAtPos(313, 3);
    my_list.printLinkedList();

    my_list.deleteAtPos(3);
    my_list.printLinkedList();

    my_list.deleteAtHead();
    my_list.deleteAtTail();
    my_list.printLinkedList();

    my_list.printLinkedListReverse();

    my_list.printListRecursive();
    
    my_list.printListReverseRecursive();

    my_list.printLinkedList();
    // my_list.reverseListRecursive();
    my_list.reverseList();
    my_list.printLinkedList();

    std::cout << std::endl << std::endl;

}