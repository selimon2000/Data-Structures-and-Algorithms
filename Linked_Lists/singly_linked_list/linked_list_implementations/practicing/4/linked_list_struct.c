#include <stdio.h>
#include <stdlib.h>


struct Node_ {
    int value;
    struct Node_* next;
};
typedef struct Node_ Node;


Node* newNode(int data, Node* next);

void insertAtHead(Node** head, int data);
void insertAtTail(Node** head, int data);
void insertAtPos(Node** head, int data, int pos);

void deleteAtHead(Node** head);
void deleteAtTail(Node* head);
void deleteAtPos(Node** head, int pos);

void printList(Node* head);

// WAS NOT BOTHERED DOING REST OF THE FUNCTIONS: /////////
// void printListRecursive();
// void printListReverseRecursive();

// void reverseLinkedListRecursive();
// void reverseLinkedList();


Node* newNode(int data, Node* next) {
    Node* new_node = (Node*)malloc(sizeof(Node*));
    new_node->value = data;
    new_node->next = next;
    return new_node;
};

void insertAtHead(Node** head, int data) {
    if (*head == NULL)
        *head = newNode(data, NULL);
    else
        *head = newNode(data, *head);
}

void insertAtTail(Node** head, int data) {
    if (*head == NULL) {insertAtHead(head, data); return;}

    Node* current = *head;
    for (; current->next != NULL; current = current->next);
    
    current->next = newNode(data, NULL);
}

void insertAtPos(Node** head, int data, int pos) {
    if (*head == NULL || pos == 0) {insertAtHead(head, data); return;}

    int i = 0;
    Node* current = *head;
    for (; i < pos - 1 && current != NULL; i++, current = current->next);
    if (i != pos -1)
        printf("[WARNING]/tOut of Bounds\n");
    else
        current->next=newNode(data, current->next);
}

void printList(Node* head) {
    printf("Printing List:\n");
    for (; head != NULL; head = head->next)
        printf("%d, ", head->value);
    printf("\n");
}

void deleteAtHead(Node** head) {
    printf("Deleting Head\n");
    Node* to_free = *head;
    *head = (*head)->next;
    free(to_free);
}

void deleteAtTail(Node* head) {
    printf("Deleting Tail\n");
    for (; head->next->next != NULL; head = head->next);

    free(head->next);
    head->next = NULL;
}

void deleteAtPos(Node** head, int pos) {
    printf("Deleting Element at position: %d\n", pos);
    if (pos == 0) { deleteAtHead(head); return; }
    
    int i = 0;
    Node* current = *head;
    for (; i < pos - 1 && current->next->next != NULL; i++, current = current->next);

    if (i != pos - 1)
        printf("[WARNING]\t Out of Bounds\n");
    
    Node* to_delete = current->next;
    current->next = current->next->next;
    free(to_delete);    
}

int main() {
    Node* head = NULL;

    insertAtHead(&head, 3);
    insertAtHead(&head, 2);
    insertAtHead(&head, 1);
    insertAtHead(&head, 0);
    insertAtTail(&head, 9);

    insertAtPos(&head, 313, 2);

    printList(head);

    deleteAtHead(&head);
    printList(head);
    deleteAtTail(head);
    printList(head);

    deleteAtPos(&head, 2);
    printList(head);
}