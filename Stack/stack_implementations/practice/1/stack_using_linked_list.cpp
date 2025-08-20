#include <iostream>
#include <forward_list>


class Stack {
public:
    Stack(){};

    int top();
    void pop();
    void push(int data);
    void printStackFromTop();

private:
    std::forward_list<int> stack_list;
};

int Stack::top() {
    return stack_list.front();
}

void Stack::pop() {
    stack_list.pop_front();
}

void Stack::push(int data) {
    stack_list.push_front(data);
}

void Stack::printStackFromTop() {
    for (auto it = stack_list.begin(); it != stack_list.end(); it++)
        std::cout << *it << ", ";
    
    std::cout << std::endl;
}


int main() {
    Stack my_stack;

    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);
    my_stack.printStackFromTop();

    my_stack.push(1);
    my_stack.push(2);
    my_stack.pop();
    my_stack.push(3);
    my_stack.printStackFromTop();
}