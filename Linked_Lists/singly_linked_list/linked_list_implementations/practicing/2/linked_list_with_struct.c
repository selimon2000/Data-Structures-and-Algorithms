#include <stdio.h>
#include <stdlib.h>


struct Node_ {
    int data;
    struct Node_* next;
};
typedef struct Node_ Node;


Node* newNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
}

void insertAtFront(int data, Node** current) {
    if (*current == NULL)
        *current = newNode(data);

    else {
        Node* new_node = newNode(data);
        (new_node)->next = *current;

        *current = new_node;
    }
}

void insertAtBack(int data, Node* current) {
    if (current == NULL)
        current = newNode(data);

    else {
        for (; current->next != NULL; current = current->next);
        current->next = newNode(data);
    }
}

void insertAtPos(int data, int pos, Node** current) {
    // IF inserting at head
    if (pos == 0) {
        insertAtFront(data, current);
        return;
    }

    // Traverse to node before the new_node
    int current_pos = 0;
    for (; (current_pos < pos - 1) && ( (*current) != NULL); current_pos++, current = &(*current)->next);
    // Check if we are at the node before the new_node - otherwise we are at an invalid position
    if (pos - current_pos != 1) {
        printf("[WARNING]\tIn insertAtPos(), inputted pos is out of bounds\n");
        return;
    }

    // The new_node will be inserted after the the node before the actual node
    Node* new_node = newNode(data);
    new_node->next = (*current)->next;
    (*current)->next = new_node;
}

void deleteAtFront(Node** head) {

    if (*head == NULL)
        printf("[WARNING]\tdeleteatFront(): head is invalid\n");
    
    else {
        Node* to_delete = *head;
        *head = (*head)->next;
        free(to_delete);
    }
}

void deleteAtBack(Node** head) {
    if (*head == NULL)
        printf("[WARNING]\tdeleteatFront(): head is invalid\n");
    
    else {
        // Traverse to the second last node
        for (; (*head)->next->next != NULL; head = &(*head)->next);
        free((*head)->next);
        (*head)->next = NULL;
    }
}

void deleteAtPos(int pos, Node** head) {
    if (pos == 0) {
        deleteAtFront(head);
        return;
    }
  
    int current_pos = 0;
    for (; ((*head) != NULL) && current_pos < pos - 1; current_pos++, head = &(*head)->next);
    if (pos - current_pos != 1) {
        printf("[WARNING]\tIn deleteAtPos(), inputted pos is out of bounds\n");
        return;
    }
    
    Node* to_delete = (*head)->next;
    (*head)->next = to_delete->next;
    free(to_delete);
}

void printLinkedList(Node* current) {
    for (; current != NULL; current = current->next)
        printf("%d, ", current->data);
    printf("\n");
}

void printLinkedListRecursive(Node* current) {
    if (current == NULL)
        return;
    
    printf("%d, ", current->data);
    printLinkedListRecursive(current->next);
}

void printLinkedListReverseRecursive(Node* current) {
    if (current == NULL)
        return;
    
    printLinkedListReverseRecursive(current->next);
    printf("%d, ", current->data);    
}

void reverseLinkedList(Node** head) {

    Node* prev = NULL;
    Node* current = *head;
    Node* next;

    for (; current != NULL;) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void reverseLinkedListRecursive(Node* current, Node** head) {
    if (current->next == NULL) {
        *head = current;
        return;
    }

    reverseLinkedListRecursive(current->next, head);
    current->next->next = current;
    current->next = NULL;   
}

Node* findNodeWithValue(int data, Node* current) {
    for (; current != NULL; current = current->next) {
        if (current->data == data)
            return current;
    }
    return NULL;
}


// int main() {
//     Node* head = NULL;

//     insertAtFront(3, &head);
//     insertAtFront(2, &head);
//     insertAtFront(1, &head);
//     insertAtBack(4, head);
//     insertAtBack(5, head);
//     insertAtBack(6, head);
//     printLinkedList(head);

//     insertAtPos(313, 6, &head);
//     printLinkedList(head);

//     deleteAtFront(&head);
//     deleteAtBack(&head);
//     deleteAtFront(&head);
//     printLinkedList(head);

//     deleteAtPos(2, &head);
//     printLinkedList(head);

//     printLinkedListRecursive(head);
//     printf("\n\n");

//     printLinkedListReverseRecursive(head);
//     printf("\n\n");

//     reverseLinkedListRecursive(head, &head);
//     printLinkedList(head);

//     printf("HERE:\n");
//     reverseLinkedList(&head);
//     printLinkedList(head);

//     int target = 4;
//     printf("Looking for %d:\n", target);
//     if (findNodeWithValue(target, head) == NULL)
//         printf("Number DOES NOT EXIST in Linked List");
//     else
//         printf("Number EXISTS in Linked List");
// }

int main() {
    Node* head = NULL;

    insertAtBack(3, head);
    printLinkedList(head);
}