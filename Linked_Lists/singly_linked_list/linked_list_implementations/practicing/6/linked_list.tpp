template <typename T>
struct linked_list<T>::node {
    node() : next(nullptr) {}
    node(T val) : val(val), next(nullptr) {}
    node(T val, node *next) : val(val), next(next) {}

    T val;
    node *next;
};

template <typename T>
void linked_list<T>::push_back(T val) {
    if(head == nullptr) head = new node(val);
    else {
        node* cur = head;
        for( ; cur->next != nullptr; cur = cur->next);
        cur->next = new node(val);
    }
}

template <typename T>
void linked_list<T>::push_front(T val) {
    if(head == nullptr) head = new node(val);
    else {
        node* new_node = new node(val);
        new_node->next = head;
        head = new_node;
    }
}

template <typename T>
bool linked_list<T>::insert(unsigned int pos, T val) {
    if (pos == 0) push_front(val);
    else {
        node* cur = head;
        for (unsigned int i = 0; i < (pos - 1); ++i) {
            if(cur->next == nullptr) {
                cout << "ERROR\tFailed Insert Operation\n";
                return false;
            }
            cur = cur->next;
        }
        cur->next = new node(val, cur->next);
    }
    return true;
}

template <typename T>
void linked_list<T>::printHead() {
    if (head) cout << "Value of Head: " << head->val << '\n';
}

template <typename T>
void linked_list<T>::printTail() {
    if (!head) return;
    node* cur = head;
    for (; cur->next != nullptr; cur = cur->next);
    cout << "Value at tail: " << cur->val << '\n';
}

template <typename T>
void linked_list<T>::printList() {
    if (!head) return;
    cout << "Printing List:\t";
    node* cur = head;
    for (; cur->next != nullptr; cur = cur->next) cout << cur->val << ", ";
    cout << cur->val << ".\n\n";
}

template <typename T>
void linked_list<T>::printReverseList() {
    cout << "Printing Reverse List\n";
    stack<T> my_stack;
    node* cur = head;
    for (; cur != nullptr; cur = cur->next) my_stack.push(cur->val);
    
    for (; !my_stack.empty(); my_stack.pop()) cout << my_stack.top() << ", ";
    cout << '\n';
}

template <typename T>
void linked_list<T>::printListRecursive() {
    printListRecursiveUW(head);
}

template <typename T>
void linked_list<T>::printListRecursiveUW(node* cur) {
    if (cur == nullptr) return;
    cout << cur->val << ", ";
    printListRecursiveUW(cur->next);
}

template <typename T>
void linked_list<T>::printReverseListRecursive() {
    printReverseListRecursiveUW(head);
}

template <typename T>
void linked_list<T>::printReverseListRecursiveUW(node* cur) {
    if (cur == nullptr) return;
    printReverseListRecursiveUW(cur->next);
    cout << cur->val << ", ";
}

template <typename T>
int linked_list<T>::size() {
    int count{0};
    for (node* cur = head; cur != nullptr; ++count, cur = cur->next);
    return count;    
}

template <typename T>
void linked_list<T>::popFront() {
    if (!head) return;
    node* to_delete = head;
    head = head->next;
    delete to_delete;
}

template <typename T>
void linked_list<T>::popBack() {
    if (!head) return;
    if (head->next == nullptr) {
        popFront();
        return;
    } 
    node* cur = head;
    while (cur->next->next != nullptr) cur = cur->next;
    delete cur->next;
    cur->next = nullptr;
}

template <typename T>
void linked_list<T>::erase(unsigned int pos) {
    if (head == nullptr) {
        cout << "WARNING\tpopErase() - there are no nodes\n";
        return;
    }
    if (pos == 0) {
        popFront();
        return;
    } 

    node* cur = head;
    for (unsigned int i = 0; i < (pos - 1); ++i, cur = cur->next) {
        if (!cur || !cur->next) {
            cout << "WARNING\tpopErase() - there are not enough nodes\n";
            return;
        }
    }
    if (!cur->next) return;
    node* temp = cur->next->next;
    delete cur->next;
    cur->next = temp;
}

template <typename T>
void linked_list<T>::reverseList() {
    if (head == nullptr || head->next == nullptr) return;

    node* new_next = nullptr;
    node* next;
    node* cur = head;

    while (cur != nullptr) {
        next = cur->next;
        cur->next = new_next;
        new_next = cur;
        cur = next;
    }
    head = new_next;
}

template <typename T>
void linked_list<T>::reverseListRecursive() {
    if (!head || !head->next) return;
    node* old_head = head; 
    reverseListRecursiveUW(head);
    old_head->next = nullptr;
}

template <typename T>
void linked_list<T>::reverseListRecursiveUW(node* cur) {
    if (cur->next == nullptr) {
        head = cur;
        return;
    }
    reverseListRecursiveUW(cur->next);
    cur->next->next = cur;
}

template <typename T>
linked_list<T>::~linked_list() {
    while (head) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
}