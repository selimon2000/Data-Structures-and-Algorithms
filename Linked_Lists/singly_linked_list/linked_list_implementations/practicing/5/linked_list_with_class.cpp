#include <iostream>
#include <stack>


class Node {
public:
    Node(int _data = 0, Node *_next = nullptr) : data(_data),
                                                 next(_next){};
    int data;
    Node* next;
};


class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        Node* next;
        while (head != nullptr) {
            next = head->next;
            delete head;
            head = next;
        }        
    }

    int size();

    void pushFront(int val);
    void pushBack(int val);
    // First element is pos = 0
    void insert(int val, int pos);

    void popFront();
    void popBack();
    void posErase(int pos);

    void printList();
    void printReverseList();
    void printListRecursive();
    void printReverseListRecursive();

    void reverseList();
    void reverseListRecursive();

private:
    Node* head;

    void printListRecursiveUW(Node* current); // UW stands for Unwrapped
    void printReverseListRecursiveUW(Node* current); // UW stands for Unwrapped

    void reverseListRecursiveUW(Node* current); // UW stands for Unwrapped
};


int LinkedList::size() {
    int i = 0;
    for(Node* temp_h = head; temp_h != nullptr; temp_h = temp_h->next, i++);
    return i;
}

// INSERT OPERATIONS ///////////////////////////////////////////////////
void LinkedList::pushFront(int val) {
    head = new Node(val, head);
}
void LinkedList::pushBack(int val) {
    Node* new_node = new Node(val);

    if(head == nullptr) head = new_node;
    else {
        Node* new_head = head;
        for(; new_head->next != nullptr; new_head = new_head->next);
        new_head->next = new_node;
    }
}
void LinkedList::insert(int val, int pos) {
    if(pos == 0) {pushFront(val); return;}

    Node* new_head = head;
    unsigned int i = 0;
    for(; i < pos - 1 && new_head->next != nullptr; i++, new_head = new_head->next);
    if(i == pos - 1) new_head->next = new Node(val, new_head->next);
    else std::cout << "[WARNING]\tElement cannot be inserted as pos is out-of-range" << std::endl;
}

// ERASE OPERATIONS /////////////////////////////////////////////////////
void LinkedList::popFront() {
    if (head == nullptr) return; // Check if it is empty already

    Node* old_head = head;
    head = head->next;
    delete old_head;
}
void LinkedList::popBack() {
    if (head == nullptr) return; // Check if it is empty already

    Node* temp_head = head;
    for (; temp_head->next->next != nullptr; temp_head = temp_head->next);
    delete(temp_head->next);
    temp_head->next = nullptr;
}
void LinkedList::posErase(int pos) {
    if (head == nullptr) return; // Check if it is empty already
    if(pos == 0) {popFront(); return;}

    Node* temp_head = head;
    int i = 0;
    for (; i < pos - 1 && temp_head->next != nullptr; i++)
        temp_head = temp_head->next;
    if(i != pos - 1) std::cout << "[WARNING]\tElement cannot be erased as pos is out-of-range" << std::endl;
    Node* to_delete = temp_head->next;
    temp_head->next = temp_head->next->next;
    delete(to_delete);
}

// PRINT OPERATIONS ///////////////////////////////////////////////////
void LinkedList::printList() {
    for(Node* t_head = head; t_head != nullptr; t_head = t_head->next)
        std::cout << t_head->data << ", ";
    std::cout << std::endl << std::endl;
}
void LinkedList::printReverseList() {
    std::stack<int> node_stack;
    for(Node* temp_h = head; temp_h != NULL; temp_h = temp_h->next)
        node_stack.push(temp_h->data);
    
    int stack_size = node_stack.size();
    for(int i = 0; i < stack_size; i++) {
        std::cout << node_stack.top() << ", "; 
        node_stack.pop();
    }
    std::cout << std::endl;
}
void LinkedList::printListRecursive() {
    printListRecursiveUW(head);
    std::cout << std::endl;
}
void LinkedList::printListRecursiveUW(Node* current) {
    if(current == nullptr) return;
    std::cout << current->data << ", ";
    printListRecursiveUW(current->next);
}
void LinkedList::printReverseListRecursive() {
    printReverseListRecursiveUW(head);
    std::cout << std::endl;
}
void LinkedList::printReverseListRecursiveUW(Node* current) {
    if(current == nullptr) return;
    printReverseListRecursiveUW(current->next);
    std::cout << current->data << ", ";
}

// REVERSE OPERATION /////////////////////////////////////////////////////
void LinkedList::reverseListRecursive() {
    if (head == nullptr || head->next == nullptr) return;
    reverseListRecursiveUW(head);
}
void LinkedList::reverseListRecursiveUW(Node* current) {
    if (current->next == nullptr) {
        head = current;
        return;
    }
    reverseListRecursiveUW(current->next);
    (current->next)->next = current;
    current->next = nullptr;
}

void LinkedList::reverseList() {
    Node *prev = nullptr, *current = head, *next;

    while(current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}


int main() {

    LinkedList my_list;

    my_list.pushFront(3);

    my_list.pushBack(4);
    my_list.pushBack(5);
    my_list.pushBack(6);

    my_list.pushFront(2);
    my_list.pushFront(1);

    my_list.printList();

    my_list.insert(99, 6);
    my_list.popFront();
    my_list.popBack();
    my_list.printList();

    my_list.posErase(4);
    my_list.printList();

    std::cout << "Size of List is: " << my_list.size() << std::endl;
    my_list.printReverseList();

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Printing List Normal:" << std::endl;
    my_list.printList();

    std::cout << "Printing List Normal (Recursive):" << std::endl;
    my_list.printListRecursive();
    std::cout << "Printing List Reverse: (Recursive)" << std::endl;
    my_list.printReverseListRecursive();

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Printing List Normal:" << std::endl;
    my_list.printList();

    my_list.reverseListRecursive();
    std::cout << "Printing List Normal (after it has been reverse):" << std::endl;
    my_list.printList();

    my_list.reverseList();
    std::cout << "Printing List Normal (after it has been reversed again so back to normal):" << std::endl;
    my_list.printList();

}