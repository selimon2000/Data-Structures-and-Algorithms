#include <iostream>

class DoubleNode
{
public:
    DoubleNode() : next(nullptr),
             prev(nullptr),
             data(0){};

    DoubleNode(int data) : next(nullptr),
                     prev(nullptr),
                     data(data){};

    int nodeValue(){
        return data;
    }

    DoubleNode* next;
    DoubleNode* prev;

private:
    int data;
};

void insertAtHead(DoubleNode** head, DoubleNode** tail, int data) {
    DoubleNode* new_node = new DoubleNode(data);

    if (*head == nullptr)
    {
        *head = new_node;
        *tail = *head;
    }
    else
    {
        (*head)->next = new_node;
        new_node->prev = *head;
        *tail = new_node;
    }
}

void printListForward(DoubleNode* head) {
    for (; head!= nullptr; head = head->next)
        std::cout << head->nodeValue() << ", ";   
    std::cout << std::endl;
}

void printListBackward(DoubleNode* current) {
    for (; current != nullptr; current = current->prev)
        std::cout << current->nodeValue() << ", ";  
    std::cout << std::endl;
}


int main() {
    DoubleNode* head = nullptr;
    DoubleNode* tail = nullptr;

    insertAtHead(&head, &tail, 1);
    insertAtHead(&head, &tail, 2);

    printListForward(head);

    printListBackward(tail);
}