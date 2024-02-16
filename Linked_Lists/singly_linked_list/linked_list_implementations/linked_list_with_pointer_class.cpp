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

void printLinkedList(Node* head) {
    for (; head != nullptr; head = head->next)
        std::cout << head->nodeValue() << ", ";
    std::cout << std::endl;
}

void printLinkedListRecursive(Node* head) {
    if (head == nullptr)
    {
        std::cout << std::endl;
        return;
    }

    std::cout << head->nodeValue() << ", ";
    printLinkedListRecursive(head->next);        
}

void printLinkedListReverseRecursive(Node *head) {
    if (head == nullptr)
        return;
    
    printLinkedListReverseRecursive(head->next);
    std::cout << head->nodeValue() << ", ";
}

void insertAtBeginning(Node** head, int data) {
    Node* new_node = new Node(data);
    new_node->next = *head;
    *head = new_node; 
}

void insertAtPosition (Node** head, int data, int pos) {
    if (*head == nullptr)
        return;
    
    Node* new_node = new Node(data);
    if (pos == 0)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        Node* current_pos = *head;
        // For loop Explanation: why is it "< pos - 1"
        // The < sign is enough to go to the previous element, and
        // Normally I would think it would be i< pos, since the first element is zero, and we don't have to account for that
        // but if the for loop is not run (when pos == 1), then we have accounted for when it is at the first element.
        // That's why the -1 is necessary
        for (int i = 0; i < pos - 1; i++, current_pos = current_pos->next)
        {
            if (current_pos->next == nullptr)
            {
                printf("Error - linked list is not long enough so insert operation cancelled\n");
                return;
            }
            
        }
        new_node->next = current_pos->next;
        current_pos->next = new_node;
    }
}

void insertAtEnd(Node* current, int value) {
    // go to the last element 
    for (; current->next != nullptr; current = current->next);
    current->next = new Node(value);
}

void deleteNode(Node** head, int pos) {
    if (pos == 0)
    {
        Node* to_delete_node = *head;
        *head = (*head)->next;
        delete to_delete_node;
    }
    else
    {
        Node* current_node = *head;
        for (size_t i = 0; i < pos - 1; i++, current_node = current_node->next);
        if (current_node->next == nullptr)
        {
            printf("out of bounds, deleteNode operation cancelled");
            return;
        }
        Node* to_delete_node = current_node->next;
        current_node->next = to_delete_node->next;
        delete to_delete_node;
    }
}

void reverseLinkedList(Node** head) {
    Node* current = *head;
    if (current == nullptr || current->next == nullptr)
        return;

    Node* next = nullptr;
    Node* prev = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void reverseWithRecursion(Node* current, Node** head) {
    if (current->next == nullptr)
    {
        *head = current;
        return;
    }

    reverseWithRecursion(current->next, head);
    current->next->next = current;
    current->next = nullptr;
}

void searchElement(Node* head, int target) {
    for (; head != nullptr; head = head->next)
    {
        if (head->nodeValue() == target)
        {
            std::cout << "Search Element function: target found" << std::endl;
            return;
        }
    }
    std::cout<< "Search Element function: target does not exist" << std::endl;
}


int main() {
    Node* head = new Node(111);

    Node* second = new Node(222);
    head->next = second;

    Node* third = new Node(333);
    second->next = third;

    printLinkedList(head);

    insertAtBeginning(&head, 313);
    printLinkedListRecursive(head);

    insertAtPosition(&head, 99, 0);
    printLinkedListRecursive(head);

    deleteNode(&head, 4);
    printLinkedListRecursive(head);

    reverseLinkedList(&head);
    printLinkedListRecursive(head);

    printLinkedListReverseRecursive(head);
    std::cout << std::endl;

    reverseWithRecursion(head, &head);
    printLinkedListRecursive(head);

    insertAtEnd(head, 31313);
    printLinkedListRecursive(head);

    searchElement(head, 313513);
}