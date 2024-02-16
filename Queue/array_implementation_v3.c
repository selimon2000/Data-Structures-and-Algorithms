#include <stdio.h>
#include <stdbool.h>

#define SIZE 10
int queue[SIZE];
int front = -1, rear = -1;

bool isEmpty() {
    return ((front == -1 && rear == -1) ? true : false);
}

int queueSize() {
    if (isEmpty())
        return 0;

    if (rear >= front)
        return rear - front + 1;
    else
        return SIZE - front + rear + 1;
}

bool isFull() {
    return (queueSize() == SIZE) ? true : false;
}

void pop() {
    if (isEmpty())
        printf("Queue is Empty so it cannot be Popped\n");
    
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {    
        front++;
        front %= SIZE;
    }
}

void push(int value) {
    if (isFull())
    {
        printf("Cannot Push as Queue is at max capacity\n");
        return;
    }
    else if (isEmpty())
    {
        front++;
        rear++;
    }
    else
    {
        rear++;
        rear %= SIZE;
    }

    queue[rear] = value;
}

int returnFront() {
    if (isEmpty())
        printf("Queue is Empty therefore Front cannot be printed\n");
    else
        return queue[front];
}

int returnRear() {
    if (isEmpty())
        printf("Queue is Empty therefore Rear cannot be printed\n");
    else
        return queue[rear];
}

void printQueue() {
    if (isEmpty())
        printf("Queue is Empty so cannnot be printed\n");

    else if (rear >= front)
    {
        for (size_t i = front; i <= rear; i++)
            printf("%d, ", queue[i]);
    }
    else
    {
        for (size_t i = front; i < SIZE; i++)
            printf("%d, ", queue[i]);
        for (size_t i = 0; i <= rear; i++)
            printf("%d, ", queue[i]);
    }

    printf("\n");
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