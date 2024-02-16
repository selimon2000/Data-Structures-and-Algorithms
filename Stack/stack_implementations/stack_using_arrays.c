#include <stdio.h>

#define MAX_SIZE 100


int A[MAX_SIZE];
int top = -1;

void push(int x) {
    if (top == MAX_SIZE - 1)
    {
        printf("Error: stack overflow\n");
        return;
    }

    A[++top] = x;
    return;
}

int pop() {
    if (top == -1) {
        printf("Error: No element to pop as stack is empty\n");
        return -1;
    }

    return A[top--];
}

int Top() {
    return A[top];
}

void printStack() {
    for (size_t i = 0; i <= top; i++)
        printf("%d, ", A[i]);
    
    printf("\n\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    printStack();

    pop();
    push(12);
    printStack();
}