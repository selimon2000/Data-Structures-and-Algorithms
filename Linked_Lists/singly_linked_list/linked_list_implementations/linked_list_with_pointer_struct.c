#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node node;

void printLinkedList(node* head){
    for (; head != NULL; head = head->next)  
        printf("%d, ", head->data);
    printf("\n");
}

void printLinkedListRecursive(node* head) {
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d, ", head->data);
    printLinkedListRecursive(head->next);    
}

void printLinkedListReverseRecursive(node* head) {
    if (head == NULL)
        return;
    
    printLinkedListReverseRecursive(head->next);
    printf("%d, ", head->data);    
}

void insertAtBack(node* head, int data) {
    // For loop to traverse to the last element of the linked list
    for (; head->next != NULL; head = head->next);  
    
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    
    head->next = new_node;
}

void insertAtBeginning(node** head, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;

    *head = new_node;
}


void insertAtPosition(node** head, int data, int pos) { // to insert at first element pos is 0, not 1
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;

    if (pos == 0)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        node* current = *head;
        for (size_t i = 0; i < pos - 1; i++, current = current->next);
        new_node->next = current->next;
        current->next = new_node;
    }
}

void deleteNode(node** head, int pos) {
    if (pos == 0)
    {
        node* to_delete = *head;
        *head = (*head)->next;
        free(to_delete);
    }
    else
    {
        node* current = *head;
        for (size_t i = 0; i < pos - 1; i++, current = current->next);
        node* to_delete = current->next;
        current->next = to_delete->next;
        free(to_delete);
    }
}

void reverseLinkedList(node** head)
{
    node* current = *head;

    node* prev = NULL;
    node* next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    *head = prev;
}


int main() {
    node* head = (node*)malloc(sizeof(node));
    head->data = 1;

    node* second = (node*)malloc(sizeof(node));
    second->data = 2;
    head->next = second;

    node* third = (node*)malloc(sizeof(node));
    third->data = 3;
    second->next = third;

    insertAtBack(head, 99);
    printLinkedList(head);

    insertAtBeginning(&head, 10101);
    printLinkedListRecursive(head);

    insertAtPosition(&head, 808, 3);
    printLinkedListRecursive(head);

    deleteNode(&head, 5);
    printLinkedListRecursive(head);

    reverseLinkedList(&head);
    printLinkedListRecursive(head);

    printLinkedListReverseRecursive(head);
}