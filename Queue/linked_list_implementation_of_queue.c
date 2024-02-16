#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void push(int x)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->link = NULL;

    if (front == NULL && rear == NULL){
        front = rear = new_node;
        return;
    }
    else{
        rear->link = new_node;
        rear = new_node;
    }
}

void pop()
{
    struct Node* to_delete = front;
    front=front->link;
    free(to_delete);
}

void print_queue()
{
    struct Node* current = front;
    while (current != NULL){
        printf("%d, ", current->data);    
        current = current->link;    
    }
}


int main()
{
    push(1);
    push(2);
    push(3);
    push(4);

    pop();

    push(5);
    push(6);
    push(7);

    print_queue();
}