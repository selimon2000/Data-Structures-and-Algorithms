#include <iostream>
#include <stack>


class Node {
public:
    Node(int data_ = 0, Node *next_ = nullptr) : data(data_),
                                                 next(next_) {}
    int data;
    Node* next;
};


class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void insertAtHead(int data);
    void insertAtTail(int data);
    void insertAtPos(int data, int pos);

    void deleteAtHead();
    void deleteAtTail();
    void deleteAtPos(int pos);

    void printLinkedList();
    void printLinkedListReverse();
    void printListRecursive();
    void printListReverseRecursive();

    void reverseList();
    void reverseListRecursive();

    Node* searchLinkedList(int data);

private:
    Node* head;

    void printListRecursiveUnwrapped(Node* current);
    void printListReverseRecursiveUnwrapped(Node* current);

    void reverseListRecursiveUnwrapped(Node* current);
};


void LinkedList::insertAtHead(int data) {
    Node* new_node = new Node(data, head);
    head = new_node;
}

void LinkedList::insertAtTail(int data) {
    if (data == 0 || head == NULL) {
        insertAtHead(data);
        return;
    }

    Node* current = head;
    for (; current->next != nullptr; current = current->next);
    Node* new_node = new Node(data);
    current->next = new_node;
}

void LinkedList::insertAtPos(int data, int pos) {
    if (pos == 0 || head == NULL) {
        insertAtHead(data);
        return;
    }

    Node* current = head;
    int current_pos = 0;
    for (; (current->next->next != nullptr) && (current_pos < pos - 1); current = current->next, current_pos++);
    if (current_pos != pos - 1) {
        printf("[WARNING]\tinsertAtPos ABORTED as pos is OUT OF BOUNDS\n");
        return;
    }
    
    Node* new_node = new Node(data, current->next->next);
    current->next = new_node;
}


void LinkedList::deleteAtHead() {
    if (head == nullptr)
        printf("[WARNING]\tCannot delete as list is already empty\n");
    
    Node* to_delete = head;
    head = head->next;
    free(to_delete);
}

void LinkedList::deleteAtTail() {
    if (head == nullptr)
        printf("[WARNING]\tCannot delete as list is already empty\n");

    Node* current = head;
    for (; current->next->next != nullptr; current = current->next);
    Node* to_delete = current->next;
    current->next = current->next->next;
    free(to_delete);
}

void LinkedList::deleteAtPos(int pos) {
    if (head == nullptr)
        printf("[WARNING]\tCannot delete as list is already empty\n");
    else if (pos == 0)
        deleteAtHead();

    else {
        Node* current = head;
        int current_pos = 0;
        for (; (current->next->next != nullptr) && (current_pos < pos -1); current = current->next, current_pos++);
        if (current_pos != pos - 1) {
            printf("[WARNING]\tdeleteAtPos() ABORTED as pos is OUT OF BOUNDS\n");
            return;
        }
        
        Node* to_delete = current->next;
        current->next = current->next->next;
        free(to_delete);
    }    
}


void LinkedList::printLinkedList() {
    for (Node* current = head; current != nullptr; current = current->next)
        printf("%d, ", current->data);
    printf("\n");
}

void LinkedList::printLinkedListReverse() {
    std::stack<int> my_stack;
    for (Node* current = head; current != nullptr; my_stack.emplace(current->data), current = current->next);
    
    for (; !my_stack.empty(); my_stack.pop())
        printf("%d, ", my_stack.top());
}

void LinkedList::printListRecursiveUnwrapped(Node* current) {
    if (current = nullptr)
        return;

    std::cout << current->data << ", ";
    printListRecursiveUnwrapped(current->next);
}
void LinkedList::printListReverseRecursiveUnwrapped(Node* current) {
    if (current = nullptr)
        return;

    printListReverseRecursiveUnwrapped(current->next);
    std::cout << current->data << ", ";
}

void LinkedList::printListRecursive() {
    printListRecursiveUnwrapped(head);
    std::cout << std::endl;
}

void LinkedList::printListReverseRecursive() {
    printListReverseRecursiveUnwrapped(head);
    std::cout << std::endl;
}


int main() {
    LinkedList my_list;

    my_list.insertAtHead(3);
    my_list.insertAtHead(2);
    my_list.insertAtHead(1);
    my_list.insertAtTail(4);
    my_list.insertAtTail(5);
    my_list.insertAtTail(6);

    my_list.printLinkedList();

    my_list.insertAtPos(313, 6);
    my_list.printLinkedList();

    my_list.deleteAtHead();
    my_list.deleteAtTail();
    my_list.printLinkedList();

    my_list.deleteAtPos(3);
    my_list.printLinkedList();


}