#include <iostream>
#include <queue>


class Node {
public:
    Node(int data_ = 0) : data(data_),
                          left(nullptr),
                          right(nullptr) {}
    Node* left;
    Node* right;
    int data;
};


class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int data);
    void insertRecursive(int data);

    Node* minNode();
    Node* maxNode();
    
    void BFS();
    void DFSPreorder();
    void DFSInorder();
    void DFSPostorder();


    Node* search(int target);

    int heightOfTree();
    
    Node* getInorderSuccessor(Node* current_node);

    void deleteNodeRecursive(int target);
    
    bool isBST();

    void printLeaves();

private:
    Node* root;

    void DFSPreorderUnwrapped(Node* current);
    void DFSInorderUnwrapped(Node* current);
    void DFSPostorderUnwrapped(Node* current);

    void insertRecursiveUnwrapped(int data, Node** current);
    
    Node* searchUnwrapped(Node* current, int target);

    int heightOfTreeUnwrapped(Node* root);

    Node* deleteNodeRecursiveUnwrapped(Node* node, int target);

    bool isBSTUnwrapped(Node* current);
    // Checking if all values of subtree is lesser than or equal to the node's value 
    bool isSubtreeLesser(Node* current, int subtree_value);
    // Checking if all values of subtree is greater than the node's value 
    bool isSubtreeGreater(Node* current, int subtree_value);

    void printLeavesUnwrapped(Node* current);
};


void BinarySearchTree::insert(int data) {
    Node** current = &root;

    while (*current != nullptr) {
        // If the same number already exists, then go left, and then go to the right-most node. We could do the opposite - Go right and then go to left most node too
        if (data == (*current)->data)
            current = &(*current)->left;
        else if (data > (*current)->data)
            current = &(*current)->right;
        else
            current = &(*current)->left;
    }
    
    *current = new Node(data);    
}

void BinarySearchTree::insertRecursive(int data) {
    insertRecursiveUnwrapped(data, &root);
}
void BinarySearchTree::insertRecursiveUnwrapped(int data, Node** current) {
    if ((*current) != nullptr) {
        if (data == (*current)->data)
            insertRecursiveUnwrapped(data, &(*current)->left);
        else if (data > (*current)->data)
            insertRecursiveUnwrapped(data, &(*current)->right);
        else
            insertRecursiveUnwrapped(data, &(*current)->left);
    }
    else
        (*current) = new Node(data);    
}

void BinarySearchTree::BFS() {
    std::queue<Node*> my_queue;
    my_queue.push(root);

    while (!my_queue.empty()) {
        // After printing the node, pop, and add their children
        for (int size = my_queue.size(); size > 0; size--) {

            std::cout << my_queue.front()->data << ", ";

            if (my_queue.front()->left != nullptr)
                my_queue.push(my_queue.front()->left);
            if (my_queue.front()->right != nullptr)
                my_queue.push(my_queue.front()->right);
            my_queue.pop();            
        }
        std::cout << std::endl;
    }
}

void BinarySearchTree::DFSPreorder() {
    DFSPreorderUnwrapped(root);
    std::cout << std::endl;
}
void BinarySearchTree::DFSPreorderUnwrapped(Node* current) {
    if (current == nullptr)
        return;
    
    std::cout << current->data << ", ";
    DFSPreorderUnwrapped(current->left);
    DFSPreorderUnwrapped(current->right);
}

void BinarySearchTree::DFSInorder() {
    DFSInorderUnwrapped(root);
    std::cout << std::endl;
}
void BinarySearchTree::DFSInorderUnwrapped(Node* current) {
    if (current == nullptr)
        return;
    
    DFSInorderUnwrapped(current->left);
    std::cout << current->data << ", ";
    DFSInorderUnwrapped(current->right);
}

void BinarySearchTree::DFSPostorder() {
    DFSPostorderUnwrapped(root);
    std::cout << std::endl;
}
void BinarySearchTree::DFSPostorderUnwrapped(Node* current) {
    if (current == nullptr)
        return;
    
    DFSPostorderUnwrapped(current->left);
    DFSPostorderUnwrapped(current->right);
    std::cout << current->data << ", ";
}

Node* BinarySearchTree::minNode() {
    Node* current;
    for (current = root; current->left != nullptr; current = current->left);
    return current;
}
Node* BinarySearchTree::maxNode() {
    Node* current;
    for (current = root; current->right != nullptr; current = current->right);
    return current;
}

void BinarySearchTree::deleteNodeRecursive(int target) {
    deleteNodeRecursiveUnwrapped(root, target);
}

Node* BinarySearchTree::deleteNodeRecursiveUnwrapped(Node* node, int target) {
    if (node == nullptr)
        return nullptr;
    
    if (node->data != target) {
        if (target > node->data)
            node->right = deleteNodeRecursiveUnwrapped(node->right, target);
        else
            node->left = deleteNodeRecursiveUnwrapped(node->left, target);

        return node;
    }
    else {
        // If leaf node free leaf, and ensure that it's parent points to NULL
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        // If it has both children, find the next biggest number, and swap the numbers. Then delete the swapped number
        else if (node->left != nullptr && node->right != nullptr) {
            // Find next biggest number
            Node* next_biggest;
            for (next_biggest = node->right; next_biggest->left != nullptr; next_biggest = next_biggest->left);
            // Swap the number
            node->data = next_biggest->data;
            node->right = deleteNodeRecursiveUnwrapped(node->right, next_biggest->data);
            return node;
        }
        // If it only has one child
        else {
            Node* return_node = (node->left != nullptr)?(node->left):(node->right);
            delete node;
            return return_node;            
        }
    }
}

Node* BinarySearchTree::search(int target) {
    return searchUnwrapped(root, target);
}
Node* BinarySearchTree::searchUnwrapped(Node* current, int target) {
    if (current == nullptr)
        return nullptr;
    
    if (current->data == target)
        return current;
    
    if (target > current->data)
        return searchUnwrapped(current->right, target);
    else
        return searchUnwrapped(current->left, target);
}

int BinarySearchTree::heightOfTree() {
    return heightOfTreeUnwrapped(root);
}
int BinarySearchTree::heightOfTreeUnwrapped(Node* current) {
    if (current == nullptr)
        return -1;
    
    return std::max(heightOfTreeUnwrapped(current->left), heightOfTreeUnwrapped(current->right)) + 1;
}

Node* BinarySearchTree::getInorderSuccessor(Node* target_node) {
    if (target_node->right != nullptr) {
        Node* successor;
        for (successor = target_node->right; successor->left != nullptr; successor = successor->left);
        return successor;
    }
    
    int target = target_node->data;
    Node* current = root;
    Node* successor = current;

    while (current != nullptr && current->data != target) {
        if (target > current->data)
            current = current->right;
        
        else {
            successor = current;
            current = current->left;
        }
    }
    return successor;
}


bool BinarySearchTree::isBST() {
    return isBSTUnwrapped(root);
}

bool BinarySearchTree::isBSTUnwrapped(Node* current) {
    if (current == nullptr)
        return true;
    
    return (isBSTUnwrapped(current->left) && isBSTUnwrapped(current->left) &&
            isSubtreeLesser(current->left, current->data) && isSubtreeGreater(current->right, current->data));
}
// Checking if all values of subtree is lesser than or equal to the node's value
bool BinarySearchTree::isSubtreeLesser(Node* current, int subtree_value) {
    if (current->data > subtree_value)
        return false;

    return isSubtreeLesser(current->left, subtree_value) && isSubtreeGreater(current->right, subtree_value);
}
// Checking if all values of subtree is greater than the node's value 
bool BinarySearchTree::isSubtreeGreater(Node* current, int subtree_value) {
    if (!(current->data > subtree_value))
        return false;

    return isSubtreeLesser(current->left, subtree_value) && isSubtreeGreater(current->right, subtree_value);
}

void BinarySearchTree::printLeaves() {
    printLeavesUnwrapped(root);
}
void BinarySearchTree::printLeavesUnwrapped(Node* current) {   
    if (current == nullptr)
        return;

    if (current->left == nullptr && current->right == nullptr) {
        std::cout << current->data << ", ";
        return;
    }
    
    printLeavesUnwrapped(current->left);
    printLeavesUnwrapped(current->right); 
}


// int main() {

//     BinarySearchTree my_tree;

//     my_tree.insert(5);
//     my_tree.insert(3);
//     my_tree.insert(1);
//     my_tree.insert(9);
//     my_tree.insert(8);
//     my_tree.insert(8);
//     my_tree.insert(8);
//     my_tree.insertRecursive(313);
//     my_tree.DFSInorder();

//     // my_tree.DFSPreorder();

//     my_tree.deleteNodeRecursive(5);
//     my_tree.DFSInorder();
//     // my_tree.DFSPostorder();
//     // my_tree.BFS();

//     std::cout << std::endl << "Height of binary tree: "<< my_tree.heightOfTree() << std::endl;
// }


int main() {

    BinarySearchTree my_tree;

    my_tree.insert(5);
    my_tree.insert(3);
    my_tree.insert(1);
    my_tree.insert(9);
    my_tree.insert(8);
    my_tree.insert(8);
    my_tree.insert(8);

    my_tree.printLeaves();
}