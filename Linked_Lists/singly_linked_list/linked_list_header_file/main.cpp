#include <iostream>
#include <Node.h>

void printList(Node *node_)
{
    while (node_ != nullptr)
    {
        std::cout << node_->value;
        node_ = node_->next;

        // We want to place a full stop only after the last element, and a comma between the elements
        if (node_ == nullptr)
            std::cout << ".";
        else
            std::cout << ", ";
    }
}

int main()
{
    Node *head = new Node(10);

    Node *second = new Node(20);
    head->next = second;

    Node *tail = new Node(1999);
    second->next = tail;

    printList(head);
    // std::cout<<"Hello World";
}