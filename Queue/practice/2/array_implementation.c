#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 10

int queue[ARRAY_SIZE];
int front = -1;
int rear = -1;


int size() {
    if (rear > front)
        return rear - front + 1;
    else
        return ARRAY_SIZE - front + rear + 1;
}

bool isEmpty() {
    if (front == -1 && rear == -1)
        return true;
    return false;
}

void pop() {
    if (isEmpty()) {
        printf("[WARNING]\tpop(): Queue is empty\n");
    }
    else if (size() == 1) {
        front = -1;
        rear = -1;
    }
    else {
        front++;
        front %= ARRAY_SIZE;
    }
}

void push(int data) {

    if (size() == ARRAY_SIZE) {
        printf("[WARNING]\tpush(): Queue is full\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
        rear = 0;
    }
    else {
        rear++;
        rear %= ARRAY_SIZE;
    }
    queue[rear] = data;
}

void printQueue() {
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d, ", queue[i]);
    }
    else {
        for (int i = front; i < ARRAY_SIZE; i++)
            printf("%d, ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d, ", queue[i]);
    }
    printf("\n\n");
}

int top() {
    if (!isEmpty())
        return queue[front];
    else {
        printf("[WARNING]\ttop(): Queue is empty\n");
        return 0;
    }
}


int main() {
    push(1);
    push(2);
    push(3);

    printQueue();

    push(4);

    printQueue();

    push(5);
    push(6);

    printQueue();

    push(7);
    printQueue();

    push(8);
    printQueue();

    pop();
    printQueue();

    push(9);
    push(10);
    push(11);
    pop();
    pop();
    push(12);
    
    printQueue();
}