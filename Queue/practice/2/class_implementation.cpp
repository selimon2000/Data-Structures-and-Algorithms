#include <iostream>
#include <list>


class Queue {
public:
    Queue(){}

    int front();
    void pop();
    void insert(int data);
    bool isEmpty();
    int size();
    void printQueue();
    
private:
    std::list<int> queue_list;
};

int Queue::front() {
    return queue_list.front();
}

void Queue::pop() {
    queue_list.pop_front();
}

void Queue::insert(int data) {
    queue_list.push_back(data);
}

bool Queue::isEmpty() {
    return queue_list.empty();
}

int Queue::size() {
    return queue_list.size();
}

void Queue::printQueue() {
    for (auto it = queue_list.begin(); it != queue_list.end(); it++)
        std::cout << *it << ", ";
    std::cout << std::endl << std::endl;
}


int main() {
    Queue MyQueue;

    MyQueue.insert(1);
    MyQueue.insert(2);
    MyQueue.insert(3);

    MyQueue.printQueue();

    MyQueue.insert(4);

    MyQueue.printQueue();

    MyQueue.insert(5);
    MyQueue.insert(6);

    MyQueue.printQueue();

    MyQueue.insert(7);
    MyQueue.printQueue();

    MyQueue.insert(8);
    MyQueue.printQueue();

    MyQueue.pop();
    MyQueue.printQueue();

    MyQueue.insert(9);
    MyQueue.insert(10);
    MyQueue.insert(11);
    MyQueue.pop();
    MyQueue.pop();
    MyQueue.insert(12);
    
    MyQueue.printQueue();
}