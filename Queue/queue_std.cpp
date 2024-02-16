#include <iostream>
#include <queue>

int main() {
    std::queue<int> my_queue;
    my_queue.push(1);
    my_queue.push(2);
    my_queue.push(3);

    my_queue.pop();
    std::cout<<my_queue.front() << std::endl;

    std::cout << "Is the queue empty: " << my_queue.empty() << std::endl;

    my_queue.pop();
    my_queue.pop();
    std::cout << "Is the queue empty: " << my_queue.empty() << std::endl;

    my_queue.pop();
    std::cout << "Is the queue empty: " << my_queue.empty() << std::endl;

}