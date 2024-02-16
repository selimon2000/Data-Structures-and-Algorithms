#include <iostream>


class Node {
public:
    Node(int data_ = 0) : data(data_){}

    int data;
    Node* left;
    Node* right;
};


class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr){}
    
    void insert(int data);
    void insertRecursive(int data);

    Node* minNode();
    Node* maxNode();

    void printInOrder();
    
private:
    Node* root;

    // Recursive Methods which require wrapper:
    Node* insertRecursiveUnwrapped(int data, Node** current);
    void printInOrderUnwrapped(Node* current);
};

void BinarySearchTree::insert(int data) {
    Node** current = &root;
    
    while ((*current) != nullptr) {
        if (data > (*current)->data)
            current = &(*current)->right;
        else
            current = &(*current)->left;
    }

    (*current) = new Node(data);
}

Node* BinarySearchTree::insertRecursiveUnwrapped(int data, Node** current) {
    if (*current == nullptr)
        *current = new Node(data);

    else {
        if (data > (*current)->data)
            (*current)->right = insertRecursiveUnwrapped(data, &(*current)->right);
        else
            (*current)->left = insertRecursiveUnwrapped(data, &(*current)->left);
    }
    
    return *current;
}

void BinarySearchTree::insertRecursive(int data) {
    insertRecursiveUnwrapped(data, &root);
}

Node* BinarySearchTree::minNode() {
    Node* current = root;
    for (; current->left != nullptr; current = current->left);
    return current;
}

Node* BinarySearchTree::maxNode() {
    Node* current = root;
    for (; current->right != nullptr; current = current->right);
    return current;
}

void BinarySearchTree::printInOrderUnwrapped(Node* current) {
    if (current == nullptr)
        return;
    
    printInOrderUnwrapped(current->left);
    std::cout << current->data << ", ";
    printInOrderUnwrapped(current->right);
}

void BinarySearchTree::printInOrder() {
    printInOrderUnwrapped(root);
    std::cout << std::endl;
}


int main() {
    BinarySearchTree my_tree;
    my_tree.printInOrder();

    my_tree.insertRecursive(80);
    my_tree.insertRecursive(30);
    my_tree.insertRecursive(70);
    my_tree.insertRecursive(20);
    my_tree.insertRecursive(40);
    my_tree.insertRecursive(60);
    my_tree.insertRecursive(50);

    my_tree.printInOrder();

    std::cout << "Min Node: " << my_tree.minNode()->data << std::endl;
    std::cout << "Max Node: " << my_tree.maxNode()->data << std::endl;
}