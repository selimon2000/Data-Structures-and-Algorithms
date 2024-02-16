#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *link;
};


struct Node* top = NULL; // this will always point to the head of the node

void push(int x) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->link = top;

    top = new_node;
}

int returnTop() {
    return top->data;
}

void pop() {
    if (top == NULL)
        return;
    
    struct Node* to_be_deleted = top;
    top = top->link;
    free(to_be_deleted);
}

void printStackFromTop() {
    struct Node* current = top;
    while (current != NULL) {
        printf("%d, ", current->data);
        current = current->link;
    }
    printf("\n\n");
}


int main() {
    push(1);
    push(2);
    push(3);
    printStack();
    
    pop();
    push(4);
    printStack();

    printf("Printing top: %d", returnTop()); 
}