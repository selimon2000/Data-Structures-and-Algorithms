#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct LL_Node {
    int data;
    struct LL_Node* next;
};
typedef struct LL_Node Node;


void insertAtBeginning(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    
    if (*head == NULL)
        new_node->next = NULL;
    else 
        new_node->next = *head;
    
    *head = new_node;
}

void printLinkedList(Node* current_node) {
    for (; current_node != NULL; current_node = current_node->next) {
        printf("%d, ", current_node->data);
    }
}

void printLinkedListRecursive(Node* head) {
    if (head == NULL)
        return;
    
    printf("%d, ", head->data);
    printLinkedListRecursive(head->next);
}

void printLinkedListReverseRecursive(Node* head) {
    if (head == NULL)
        return;
    
    printLinkedListReverseRecursive(head->next);
    printf("%d, ", head->data);
}

void insertAtBack(Node** head, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    Node* current_node = *head;
    
    if (current_node == NULL)
        current_node = new_node;
    
    else {
        for (; current_node->next != NULL; current_node = current_node->next);
        current_node->next = new_node;
    }
}

void reverseLinkedList(Node** head) {
    if (head == NULL)
        return;
    
    Node* current_node = *head;
    Node* prev_node = NULL;
    Node* next_node;
    
    for (; current_node != NULL; prev_node = current_node, current_node = next_node) {
        next_node = current_node->next;
        current_node->next = prev_node;
    }
    *head = prev_node;
}

void reverseLinkedListRecursive(Node** head, Node* current) {
    if (current->next == NULL) {
        *head = current;
        return;
    }

    reverseLinkedListRecursive(head, current->next);
    current->next->next = current;
    current->next = NULL;
}

void deleteHeadNode(Node** head) {
    Node* to_delete = *head;
    *head = (*head)->next;
    free(to_delete);
}

void deleteRearNode(Node** head) {
    Node* current = *head;
    for (; current->next->next != NULL; current = current->next);
    
    free(current->next->next);
    current->next = NULL;
}

void deleteNodeWithIndex(Node** head, int position) {
    if (position == 0) {
        deleteHeadNode(head);
        return;
    }
    
    Node* current = *head;
    Node* previous = NULL;
    int pos = 0;

    // Traverse to the index that is to be deleted
    for (; current != NULL && pos < position; previous = current, current = current->next, pos++);
    if (pos != position) {
        printf("[WARNING]\tLinked List is shorter than index\n");
        return;
    }
    else {
        previous->next = current->next;
        free(current);
    }
}

// NOTE: THERE ARE TWO insertNodeAtIndex FUNCTIONS - THE LATTER IS MORE MEMORY EFFICIENT AS IT DOES NOT REQUIRE PREV_NODE
// bool insertNodeAtIndex(Node** head, int data, int position) {
//     if (position == 0) {
//         insertAtBeginning(head, data);
//         return true;
//     }

//     Node* current_node = *head;
//     Node* prev_node;
//     int pos = 0;
//     for (; current_node != NULL && pos < position; prev_node = current_node, current_node = current_node->next, pos++);
//     if (pos != position) {
//         printf("[WARNING]\tLinked List is shorter than index\n");
//         return false;
//     }
    
//     Node* new_node = (Node*)malloc(sizeof(Node));
//     new_node->data = data;
//     prev_node->next = new_node;
//     new_node->next = current_node;

//     return true;
// }

bool insertNodeAtIndex(Node** head, int data, int position) {
    if (position == 0) {
        insertAtBeginning(head, data);
        return true;
    }

    Node* current_node = *head;
    int pos = 0;
    for (; current_node->next != NULL && pos < position - 1; current_node = current_node->next, pos++);
    if (pos != position -1) {
        printf("[WARNING]\tLinked List is shorter than index\n");
        return false;
    }
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = current_node->next;
    current_node->next = new_node;

    return true;
}

bool searchNode(Node* current_node, int position) {
    int pos = 0;
    for (; current_node != NULL && pos < position; current_node = current_node->next, pos++);
    if (pos != position) {
        printf("[WARNING]\tLinked List is shorter than index\n");
        return false;
    }
    printf("Element at position %d has the value %d", position, current_node->data);
    return true;
}

bool searchForValue(Node* current_node, int value) {
    for (int pos = 0; current_node != NULL; current_node = current_node->next, pos++){
        if (current_node->data == value) {
            printf("Value: %d Found at index: %d\n", value, pos);
            return true;
        }
    }
    printf("[WARNING]\tValue Not Found\n");
    return false;
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 3;
    head->next = NULL;

    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    insertAtBack(&head, 4);
    insertAtBack(&head, 5);
    insertAtBack(&head, 6);
    insertAtBack(&head, 7);
    insertAtBack(&head, 8);
    insertAtBack(&head, 9);

    printLinkedListRecursive(head);
    printf("\n\n");

    printLinkedListReverseRecursive(head);
    printf("\n\n");

    printLinkedList(head);
    printf("\n\n");

    printf("Reversed Linked List:\n");
    reverseLinkedList(&head);
    printLinkedList(head);
    printf("\n\n");

    printf("Unreversed Linked List:\n");
    reverseLinkedListRecursive(&head, head);
    printLinkedList(head);
    printf("\n\n");

    printf("Deleting Head node\n");
    deleteHeadNode(&head);
    printLinkedList(head);
    printf("\n\n");

    printf("Deleting Rear node twice\n");
    deleteRearNode(&head);
    deleteRearNode(&head);
    printLinkedList(head);
    printf("\n\n");

    printf("Deleting the second element (where first element is the zeroth)\n");
    deleteNodeWithIndex(&head, 2);
    printLinkedList(head);
    printf("\n\n");

    printf("Searching Node\n");
    searchNode(head, 2);
    printf("\n\n");

    printf("Searching to see if value '6' exists in List\n");
    searchForValue(head, 6);
    printf("\n\n");

    printf("Inserting at specific index - index 0\n");
    insertNodeAtIndex(&head, 21, 4);
    printLinkedList(head);
    printf("\n\n");
}