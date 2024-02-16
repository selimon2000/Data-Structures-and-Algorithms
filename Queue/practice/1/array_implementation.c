#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 10
int queue_array[ARRAY_SIZE];
int front = -1, rear = -1;


bool isEmpty() {
    return (front == -1 && rear == -1) ? true : false;
}

int size() {
    if (isEmpty())
        return 0;
    
    else if (rear >= front)
        return rear - front + 1;
    
    else
        return  ARRAY_SIZE - front + rear + 1;    
}

bool isFull() {
    return (size() == ARRAY_SIZE) ? true : false;
}

void push(int data) {
    if (isFull()) {
        printf("[WARNING]/t Array is Full so Insert operation cancelled");
        return;
    }
    else if (isEmpty()) {
        front = 0;
        rear = 0;
    }
    else
        rear = (rear + 1) % ARRAY_SIZE;
    

    queue_array[rear] = data;
}

void pop() {
    if (isEmpty()) {
        printf("[WARNING]/t Array is Empty so Pop operation cancelled");
        return;
    }
    else if (size() == 1) {
        front = -1;
        rear = -1;
    }
    
    else
        front = (front + 1) % ARRAY_SIZE;
}

int top() {
    if (isEmpty()) {
        printf("[WARNING]/t Array is Empty so Pop operation cancelled");
        return 0;
    }

    return queue_array[front];
}

void printQueue() {
    int x = front;
    
    for (; x != rear; x = (x + 1) % ARRAY_SIZE)
        printf("%d, ", queue_array[x]);

    printf("%d, ", queue_array[x]);
    printf("\n\n");
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