#include <iostream>

class Node {
public:
    Node() : value(0),
                next(NULL) {}

    Node(int input) : value(input),
                        next(NULL) {}

    int nodeValue() {
        return value;
    }
            
    Node* next;

private:
    int value;
};

void printLinkedList(Node head) {
    for (; head.next != NULL; head = *head.next)
        std::cout << head.nodeValue() << ", ";
    std::cout << head.nodeValue() << std::endl;        
}

void printLinkedListRecursive(Node head) {
    if (head.next == nullptr)
        return;
    
    else
    {
        std::cout << head.nodeValue() << ", ";
        printLinkedList(*head.next);
    }
}


int main() {
    Node head;
    Node second(11);
    head.next = &second;

    Node third(404);
    second.next = &third;

    printLinkedList(head);
    printLinkedListRecursive(head);
}