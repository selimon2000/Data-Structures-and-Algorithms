#include <iostream>

#define size 10


class Queue {
private:
    int queue_array[size];
    int front;
    int rear;

public:
    Queue() : front(-1),
              rear(-1) {}
    
    bool isEmpty();
    int queueSize();
    bool isFull();
    int* frontRef();
    int* backRef();
    void push(int data);
    void pop();
    void print();
};

bool Queue::isEmpty() {
    return (front == -1 && rear == -1) ? true : false;
}

int Queue::queueSize() {
    if (this->isEmpty())
        return 0;
    else if (rear >= front)
        return rear - front + 1;
    else
        return size - front + rear + 1;
}

bool Queue::isFull() {
    if (this->queueSize() == size)
        return true;
    return false;
}

int* Queue::frontRef() {
    return &queue_array[front];
}

int* Queue::backRef() {
    return &queue_array[rear];
}

void Queue::push(int data) {
    if (this->isFull())
        std::cout << "[WARNING]\t Stack is Full" << std::endl;
    else if (this->isEmpty()) {
        rear++;
        front++;
        queue_array[rear] = data;
    }
    else {
        rear++;
        rear %= size;
        queue_array[rear] = data;
    }
}

void Queue::pop() {
    if (this->isEmpty())
        std::cout << "[WARNING]\t Stack is Empty" << std::endl;
    else if (rear == front) {
        front = -1;
        rear = -1;
    }
    else {
        front++;
        front %= size;
    }
}

void Queue::print() {
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            std::cout << queue_array[i] << ", ";
    }
    else {
        for (int i = front; i < size; i++)
            std::cout << queue_array[i] << ", ";
        for (int i = 0; i <= rear; i++)
            std::cout << queue_array[i] << ", ";
    }
    std::cout << std::endl << std::endl;
}

int main() {
    Queue my_queue;

    my_queue.push(1);
    my_queue.push(2);
    my_queue.push(3);

    my_queue.print();

    my_queue.push(4);

    my_queue.print();

    my_queue.push(5);
    my_queue.push(6);

    my_queue.print();

    my_queue.push(7);
    my_queue.print();

    my_queue.push(8);
    my_queue.print();

    my_queue.pop();
    my_queue.print();

    my_queue.push(9);
    my_queue.push(10);
    my_queue.push(11);
    my_queue.pop();
    my_queue.pop();
    my_queue.push(12);
    
    my_queue.print();

    std::cout << *(my_queue.frontRef());
}