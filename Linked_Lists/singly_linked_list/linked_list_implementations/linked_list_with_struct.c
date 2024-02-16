#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node node;

void printLinkedList(node* head) {
    for (; head != NULL; head = head->next)
        printf("%d, ", head->data);
    printf("\n");
}

void printLinkedListRecursive(node* head) {
    if (head == NULL)
        return;
    printf("%d, ", head->data);
    printLinkedListRecursive(head->next);
}


int main() {
    node head;
    head.data = 11;
    
    node second;
    second.data = 22;
    head.next = &second;

    node third;
    third.data = 33;
    second.next = &third;
    third.next = NULL;

    printLinkedList(&head);

    insertAtBeginning(&head, 99);

    printLinkedListRecursive(&head);
}

    // if (head == NULL)
    // {
    //     printf("Head is null, insertAtBeginning() failed\n");
    //     return;
    // }