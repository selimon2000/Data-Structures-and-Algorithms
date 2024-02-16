#include <stdio.h>
#include <stdbool.h>

#define SIZE 10
int queue[SIZE];
int front = -1, rear = -1;


bool isEmpty() {
    return (front == -1 && rear == -1) ? true : false;
}

int queueSize() {
    if (isEmpty())
        return 0;

    return ((rear >= front) ? (rear - front + 1) : (rear + 1 + SIZE - front));
}

bool isFull() {
    if (queueSize() == SIZE)
        return true;

    return false;    
}

void printFirst() {
    printf("%d\n", queue[front]);
}

void printQueue() {
    if (isEmpty())
        printf("Queue is Empty so cannot Print\n");    

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

    printf("\n\n");
}

void pushQueue(int input) {
    // If the queue is full
    if (isFull())
        printf("Queue is Full so cannot Push\n");
    
    // If the queue is empty
    else if (isEmpty())
    {
        front++;
        rear++;
        queue[rear] = input;
    }
    
    // If the queue is else
    else
    {
        rear++;
        rear %= SIZE;
        queue[rear] = input;
    }
}

void popQueue()
{
    if(isEmpty())
        printf("Queue is Empty so can Pop\n");

    // If there is only one remaining
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

int main()
{
    pushQueue(1);
    pushQueue(2);
    pushQueue(3);

    printQueue();

    pushQueue(4);
    printQueue();

    pushQueue(5);

    pushQueue(6);
    printQueue();

    pushQueue(7);
    printQueue();

    pushQueue(8);
    printQueue();

    popQueue();
    printQueue();

    pushQueue(9);
    pushQueue(10);
    pushQueue(11);

    popQueue();
    popQueue();

    pushQueue(12);

    printQueue();
}