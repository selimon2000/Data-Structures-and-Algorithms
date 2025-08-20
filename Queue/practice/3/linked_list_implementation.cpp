#include <iostream>
#include <list>


class Queue {
private:
    std::list<int> queue_list;

public:
    int front();
    int back();
    int size();

    void push(int data);
    void pop();
    void print();
};

int Queue::front() {
    return queue_list.front();
}

int Queue::back() {
    return queue_list.back();
}

int Queue::size() {
    return queue_list.size();
}

void Queue::push(int data) {
    queue_list.push_back(data);
}

void Queue::pop() {
    if (queue_list.empty())
        std::cout << "[WARNING]\tQueue is empty";
    queue_list.pop_front();
}

void Queue::print() {
    for (auto node : queue_list)
        std::cout << node << ", ";
    
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

    std::cout << my_queue.front();
}