#include <iostream>
#include <stack>


void printStackFromTop(std::stack<int> my_stack) {
    int size = my_stack.size();

    for (int i = 0; i < size; i++, my_stack.pop())
        std::cout << my_stack.top() << ", ";
        
    std::cout << std::endl << std::endl;
}

void printStackFromBottom(std::stack<int> my_stack) {
    if (my_stack.empty())
        return;

    int top = my_stack.top();
    my_stack.pop();
    printStackFromBottom(my_stack);
    std::cout << top << ", ";    
}


int main() {
    std::stack<int> my_stack;

    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);
    my_stack.pop();
    my_stack.push(4);
    my_stack.push(5);
    my_stack.push(6);
    
    printStackFromBottom(my_stack);
    std::cout << std::endl << std::endl;

    printStackFromTop(my_stack);
}