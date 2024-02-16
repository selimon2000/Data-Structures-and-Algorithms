#include <stdio.h>
#include <stdlib.h>


struct Node_{
    int data;
    struct Node_* next;
};
typedef struct Node_ Node;


Node* newNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insertAtHead(Node** head, int data) {   
    Node* new_node = newNode(data);
    new_node->next = *head;
    *head = new_node;
}

void insertAtTail(Node** current, int data) {
    // If current is not NULL, we should traverse
    if ((*current) == NULL) {
        insertAtHead(current, data);
        return;
    }

    for (; (*current)->next != NULL; current = &(*current)->next);
    Node* new_node = newNode(data);
    (*current)->next = new_node;
}

void insertAtPos(Node** current, int pos, int data) {
    if ((*current) == NULL || pos == 0) {
        insertAtHead(current, data);
        return;
    }

    int current_pos = 0;
    // Although we want to traverse to the node before the target node, we don't care about (*current)->next->next because that's is what the next if statement checks anyways
    for (; current_pos < pos - 1 && (*current)->next != NULL; current_pos++, current = &(*current)->next);
    if (current_pos != pos - 1) {
        printf("[WARNING]\tIn insertAtPos() ABORTED as pos is out of bounds \n");
        return;
    }
    
    Node* new_node = newNode(data);
    new_node->next = (*current)->next;
    (*current)->next = new_node;
}

void deleteAtHead(Node** head) {
    Node* to_delete = *head;
    *head = (*head)->next;
    free(to_delete);
}

void deleteAtTail(Node* head) {
    // Traverse to the node before tail
    for (; head->next->next != NULL; head = head->next);
    free(head->next);
    head->next = NULL;
}

void deleteAtPos(Node** current, int pos) {
    if (current == NULL)
        return;
    if (pos == 0) {
        deleteAtHead(current);
        return;
    }

    int current_pos = 0;
    for (; ((*current)->next != NULL) && (current_pos < pos - 1); current_pos++, current = &(*current)->next);
    if (current_pos != pos - 1) {
        printf("[WARNING]\tIn deleteAtPos() ABORTED as pos is out of bounds \n");
        return;
    }
    Node* to_delete = (*current)->next;
    (*current)->next = (*current)->next->next;
    free(to_delete);
}

void printList(Node* current) {
    for (; current != NULL; current = current->next)
        printf("%d, ", current->data);   
    printf("\n");
}

void printListRecursive(Node* head) {
    if (head == NULL)
        return;   
    printf("%d, ", head->data);
    printListRecursive(head->next);
}

void printListReverseRecursive(Node* head) {
    if (head == NULL)
        return;   
    printListReverseRecursive(head->next);
    printf("%d, ", head->data);
}

void reverseLinkedListRecursive(Node* current, Node** head) {
    if (current->next == NULL) {
        *head = current;
        current->next == NULL;
        return;
    }
    
    reverseLinkedListRecursive(current->next, head);
    current->next->next = current;
    current->next = NULL;
}

void reverseLinkedList(Node** head) {
    Node* current = *head;
    Node* prev = NULL;
    Node* next;
    for (; current != NULL; prev = current, current = next) {
        next = current->next;
        current->next = prev;
    }

    // Assign head
    *head = prev;
}

/*
int main() {
    Node* head = NULL;

    insertAtHead(&head, 3);
    insertAtHead(&head, 2);
    insertAtHead(&head, 1);
    insertAtTail(&head, 4);
    insertAtPos(&head, 0, 313);
    // printList(head);

    printListRecursive(head);
    printf("\n\n");
    printListReverseRecursive(head);

    // deleteAtHead(&head);
    // deleteAtTail(head);
    // printList(head);

    // deleteAtPos(&head, 2);
    // printList(head);
}
*/

int main() {
    Node* head = NULL;

    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    insertAtTail(&head, 5);
    insertAtTail(&head, 6);

    printList(head);

    reverseLinkedListRecursive(head, &head);
    printList(head);
    
    reverseLinkedList(&head);
    printList(head);
}