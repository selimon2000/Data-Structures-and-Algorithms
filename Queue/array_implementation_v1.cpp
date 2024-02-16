#include <iostream>

#define size 10

char array_queue[10];
int front = -1;
int rear = -1;


bool isEmpty() {
    return (front == -1 && rear == -1) ? true : false;
}

int queueSize() {
    return (front > rear ? (size - front + rear + 1) : (rear - front + 1));
}

void pushQueue(char value) {
    if (isEmpty())
    {
        front++;
        rear++;
        array_queue[front] = value;
    }

    else if (((rear + 1) % size) == front)
    {
        return;
    }

    else
    {
        rear = (rear + 1) % size;
        array_queue[rear] = value;
    }
}

void popQueue() {
    if (isEmpty())
    {
        return;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}

void printQueue() {
    if (isEmpty())
    {
        std::cout << "Queue is empty." << std::endl;
        return;
    }

    if (front <= rear)
    {
        for (size_t i = front; i <= rear; i++)
            std::cout << array_queue[i] << ", ";
    }
    else
    {
        for (size_t i = front; i < size; i++)
            std::cout << array_queue[i] << ", ";
        for (size_t i = 0; i <= rear; i++)
            std::cout << array_queue[i] << ", ";
    }

    std::cout << std::endl;
}

int main() {
    pushQueue('a');
    pushQueue('b');
    pushQueue('c');
    pushQueue('d');
    pushQueue('e');
    pushQueue('f');
    pushQueue('g');
    pushQueue('h');

    popQueue();

    pushQueue('i');
    pushQueue('j');
    pushQueue('k');

    popQueue();
    popQueue();

    pushQueue('l');

    printQueue();
    std::cout << "front=" << front << std::endl;
    std::cout << "rear=" << rear << std::endl;
    std::cout << queueSize() << std::endl;
}