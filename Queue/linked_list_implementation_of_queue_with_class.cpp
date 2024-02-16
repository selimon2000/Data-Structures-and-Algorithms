#include <iostream>

class Node {
public:
    Node() : data(0),
             next(NULL){};
    Node(int value) : data(value),
                      next(NULL){};
    int data;
    Node* next;
};


class queue {
public:
    queue() : head(NULL){};
    Node *head;

    void push(int value) {
        if (head == NULL)
            head = new Node(value);
        
        // traverse to the end of the queue
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new Node(value);
        }
    }

    void pop() {
        if (head == NULL)
            std::cout << "Pop operation cancelled as list is empty" << std::endl;

        // move then delete the head;
        else {
            Node* old_head = head;
            head = head->next;
            delete old_head;
        }
    }

    void printQueue() {
        Node* current = head;
        for (;current->next != NULL; current = current->next) {
            std::cout << current->data << ", ";
        }
        std::cout << current->data << std::endl << std::endl;
    }
    
};

int main() {
    queue my_queue;

    my_queue.push(1);
    my_queue.push(2);
    my_queue.push(3);

    my_queue.printQueue();

    my_queue.push(4);

    my_queue.printQueue();

    my_queue.push(5);
    my_queue.push(6);

    my_queue.printQueue();

    my_queue.push(7);
    my_queue.printQueue();

    my_queue.push(8);
    my_queue.printQueue();

    my_queue.pop();
    my_queue.printQueue();

    my_queue.push(9);
    my_queue.push(10);
    my_queue.push(11);
    my_queue.pop();
    my_queue.pop();
    my_queue.push(12);
    
    my_queue.printQueue();
}