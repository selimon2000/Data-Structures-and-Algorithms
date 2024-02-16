#include <iostream>
#include <stack>

class Node {
public:
    Node(int data_ = 0) : data(data_),
                          next(nullptr) {}

    int data;
    Node* next;
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

    void printLinkedListUnwrapped(Node* current);
    void printLinkedListReverseUnwrapped(Node* current);

    void reverseListRecursiveUnwrapped(Node* current);
};

void LinkedList::insertAtHead(int data) {
    if (head == nullptr) {
        head = new Node(data);
        return;
    }
    
    Node* new_node = new Node(data);
    new_node->next = head;
    head = new_node;
}

void LinkedList::insertAtTail(int data) {
    Node* current = head;

    for (; current->next != nullptr; current = current->next);
        current->next = new Node(data);
}

void LinkedList::insertAtPos(int data, int pos) {
    if (pos == 0) {
        insertAtHead(data);
        return;
    }
    
    int current_pos = 0;
    Node* current = head;
    for (; current_pos < pos - 1 && current != nullptr; current_pos++, current = current->next);

    if (pos - current_pos != 1)
        std::cout << "[WARNING]\tinsertAtPos(): pos is out of bounds" << std::endl;
    else {
        Node* new_node = new Node(data);
        new_node->next = current->next;
        current->next = new_node;
    }
}

void LinkedList::deleteAtHead() {
    Node* old_head = head;
    head = head->next;
    delete(old_head);
}

void LinkedList::deleteAtTail() {
    Node* current = head;

    for (; current->next->next != nullptr; current = current->next);
    free(current->next);
    current->next = nullptr;
}

void LinkedList::deleteAtPos(int pos) {
    if (pos == 0){
        deleteAtHead();
        return;
    }
    
    Node* current = head;
    int current_pos = 0;
    for (; (current->next != nullptr) && (current_pos < pos - 1); current_pos++, current = current->next);

    if ((pos - current_pos) != 1)
        std::cout << "[WARNING]\tdeleteAtPos(): position is out of bounds" << std::endl;
    else {
        Node* to_delete = current->next;
        current->next = to_delete->next;
        free(to_delete);
    }
}

void LinkedList::printLinkedList() {
    for (Node* current = head; current != nullptr; current = current->next)
        std::cout << current->data << ", ";
    
    std::cout << std::endl;
}

void LinkedList::printLinkedListReverse() {
    std::stack<int> my_stack;

    for (Node* current = head; current != nullptr;
        my_stack.push(current->data), current = current->next);
    
    for (; !my_stack.empty(); my_stack.pop())
        std::cout << my_stack.top() << ", ";

    std::cout << std::endl;
}

void LinkedList::printListRecursive() {
    printLinkedListUnwrapped(head);
    std::cout << std::endl;
}
void LinkedList::printLinkedListUnwrapped(Node* current) {
    if (current == nullptr)
        return;
    
    std::cout << current->data << ", ";
    printLinkedListUnwrapped(current->next);
}

void LinkedList::printListReverseRecursive() {
    printLinkedListReverseUnwrapped(head);
    std::cout << std::endl;
} 
void LinkedList::printLinkedListReverseUnwrapped(Node* current) {
    if (current == nullptr)
        return;
    
    printLinkedListReverseUnwrapped(current->next);
    std::cout << current->data << ", ";
}

Node* LinkedList::searchLinkedList(int data) {
    Node* current = head;
    for (; current != nullptr; current = current->next) {
        if (current->data == data)
            return current;
    }
    return nullptr;
}

void LinkedList::reverseList() {

    Node* current = head;
    Node* prev = nullptr;
    Node* next;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

void LinkedList::reverseListRecursive() {
    reverseListRecursiveUnwrapped(head);
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


int main() {
    LinkedList my_tree;

    my_tree.insertAtHead(3);
    my_tree.insertAtHead(2);
    my_tree.insertAtHead(1);
    my_tree.insertAtTail(4);
    my_tree.insertAtTail(5);
    my_tree.insertAtTail(6);
    my_tree.printLinkedList();

    my_tree.insertAtPos(313, 3);
    my_tree.printLinkedList();

    my_tree.deleteAtHead();
    my_tree.deleteAtTail();
    my_tree.deleteAtPos(2);
    my_tree.printLinkedList();
    
    int target = 9;
    std::cout << "Searching For Target: " << target << std::endl;
    if (my_tree.searchLinkedList(target) == nullptr)
        std::cout << "Target DOES NOT EXIST in LinkedList" << std::endl;
    else
        std::cout << "Target EXISTS in LinkedList" << std::endl;  

    std::cout << "Printing LinkedList in Reverse:" << std::endl;
    my_tree.printLinkedListReverse(); 

    std::cout << "Printing LinkedList in order using recursion:" << std::endl;
    my_tree.printListRecursive();

    std::cout << "Printing LinkedList in Reverse using recursion:" << std::endl;
    my_tree.printListReverseRecursive();

    std::cout << "Reversing LinkedList in Reverse using recursion:" << std::endl;
    my_tree.reverseListRecursive();
    my_tree.printListRecursive();
    std::cout << "Reversing LinkedList in Reverse again using recursion so back to normal:" << std::endl;
    my_tree.reverseListRecursive();
    my_tree.printListRecursive();

    std::cout << "\n\n\nReversing LinkedList in Reverse one more time:" << std::endl;
    my_tree.reverseList();
    my_tree.printListRecursive();
    std::cout << "Reversing LinkedList in Reverse again using recursion so back to normal:" << std::endl;
    my_tree.reverseList();
    my_tree.printListRecursive();
}