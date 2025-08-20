#include <iostream>
#include <stack>
#include <string>

namespace dsa {
    
template <class T>
class Node {
public:
    Node(T _data = T(), Node *_next = nullptr) :    data(_data),
                                                    next(_next) {}
    T data;
    Node* next;
};


template <class T>
class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        Node<T>* next;
        while (head != nullptr) {
            next = head->next;
            delete head;
            head = next;
        }        
    }

    int size();

    void pushFront(T val);
    void pushBack(T val);
    // First element is pos = 0
    void insert(T val, int pos);

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
    Node<T>* head;

    void printListRecursiveUW(Node<T>* current); // UW stands for Unwrapped
    void printReverseListRecursiveUW(Node<T>* current); // UW stands for Unwrapped

    void reverseListRecursiveUW(Node<T>* current); // UW stands for Unwrapped
};

template <typename T>
int LinkedList<T>::size() {
    int i = 0;
    for(Node<T>* temp_h = head; temp_h != nullptr; temp_h = temp_h->next, i++);
    return i;
}

// INSERT OPERATIONS ///////////////////////////////////////////////////
template <typename T>
void LinkedList<T>::pushFront(T val) {
    head = new Node<T>(val, head);
}
template <typename T>
void LinkedList<T>::pushBack(T val) {
    Node<T>* new_node = new Node<T>(val);

    if(head == nullptr) head = new_node;
    else {
        Node<T>* new_head = head;
        for(; new_head->next != nullptr; new_head = new_head->next);
        new_head->next = new_node;
    }
}
template <typename T>
void LinkedList<T>::insert(T val, int pos) {
    if(pos == 0) {pushFront(val); return;}

    Node<T>* new_head = head;
    unsigned int i = 0;
    for(; i < pos - 1 && new_head->next != nullptr; i++, new_head = new_head->next);
    if(i == pos - 1) new_head->next = new Node<T>(val, new_head->next);
    else std::cout << "[WARNING]\tElement cannot be inserted as pos is out-of-range" << std::endl;
}

// ERASE OPERATIONS /////////////////////////////////////////////////////
template <typename T>
void LinkedList<T>::popFront() {
    if (head == nullptr) return; // Check if it is empty already

    Node<T>* old_head = head;
    head = head->next;
    delete old_head;
}
template <typename T>
void LinkedList<T>::popBack() {
    if (head == nullptr) return; // Check if it is empty already

    Node<T>* temp_head = head;
    for (; temp_head->next->next != nullptr; temp_head = temp_head->next);
    delete(temp_head->next);
    temp_head->next = nullptr;
}
template <typename T>
void LinkedList<T>::posErase(int pos) {
    if (head == nullptr) return; // Check if it is empty already
    if(pos == 0) {popFront(); return;}

    Node<T>* temp_head = head;
    int i = 0;
    for (; i < pos - 1 && temp_head->next != nullptr; i++)
        temp_head = temp_head->next;
    if(i != pos - 1) std::cout << "[WARNING]\tElement cannot be erased as pos is out-of-range" << std::endl;
    Node<T>* to_delete = temp_head->next;
    temp_head->next = temp_head->next->next;
    delete(to_delete);
}

// PRINT OPERATIONS ///////////////////////////////////////////////////
template <typename T>
void LinkedList<T>::printList() {
    for(Node<T>* t_head = head; t_head != nullptr; t_head = t_head->next)
        std::cout << t_head->data << ", ";
    std::cout << std::endl << std::endl;
}
template <typename T>
void LinkedList<T>::printReverseList() {
    std::stack<T> node_stack;
    for(Node<T>* temp_h = head; temp_h != nullptr; temp_h = temp_h->next)
        node_stack.push(temp_h->data);
    
    int stack_size = node_stack.size();
    for(int i = 0; i < stack_size; i++) {
        std::cout << node_stack.top() << ", "; 
        node_stack.pop();
    }
    std::cout << std::endl;
}
template <typename T>
void LinkedList<T>::printListRecursive() {
    printListRecursiveUW(head);
    std::cout << std::endl;
}
template <typename T>
void LinkedList<T>::printListRecursiveUW(Node<T>* current) {
    if(current == nullptr) return;
    std::cout << current->data << ", ";
    printListRecursiveUW(current->next);
}
template <typename T>
void LinkedList<T>::printReverseListRecursive() {
    printReverseListRecursiveUW(head);
    std::cout << std::endl;
}
template <typename T>
void LinkedList<T>::printReverseListRecursiveUW(Node<T>* current) {
    if(current == nullptr) return;
    printReverseListRecursiveUW(current->next);
    std::cout << current->data << ", ";
}

// REVERSE OPERATION /////////////////////////////////////////////////////
template <typename T>
void LinkedList<T>::reverseListRecursive() {
    if (head == nullptr || head->next == nullptr) return;
    reverseListRecursiveUW(head);
}
template <typename T>
void LinkedList<T>::reverseListRecursiveUW(Node<T>* current) {
    if (current->next == nullptr) {
        head = current;
        return;
    }
    reverseListRecursiveUW(current->next);
    (current->next)->next = current;
    current->next = nullptr;
}
template <typename T>
void LinkedList<T>::reverseList() {
    Node<T> *prev = nullptr, *current = head, *next;

    while(current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

}



 int main() {
    dsa::LinkedList<std::string> my_list;  

    my_list.pushBack("My");
    my_list.pushBack("name");
    my_list.pushBack("is");
    my_list.pushBack("Khan");

    my_list.printList();

    my_list.reverseList();

    my_list.printList();
} 

/*
int main() {

    dsa::LinkedList<int> my_list;

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
*/