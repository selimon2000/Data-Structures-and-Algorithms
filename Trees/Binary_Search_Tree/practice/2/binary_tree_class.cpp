#include <iostream>
#include <queue>


class Node {
public:
    Node(int data_ = 0) : data(data_),
                          left(nullptr),
                          right(nullptr) {}
    int data;
    Node* left;
    Node* right;
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
    
    // NOT DONE YET //////////////////////////////////////////////////////////////////
    bool isBST();

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
};

void BinarySearchTree::insert(int data) { 
    Node** current = &root;

    while (*current != nullptr) {
        if (data > (*current)->data)
            current = &(*current)->right;
        else
            current = &(*current)->left;
    }
    (*current) = new Node(data);
}

void BinarySearchTree::insertRecursive(int data) {
    insertRecursiveUnwrapped(data, &root);
}
void BinarySearchTree::insertRecursiveUnwrapped(int data, Node** current) {
    if (*current == nullptr) {
        *current = new Node(data);
        return;
    }
    if (data > (*current)->data)
        insertRecursiveUnwrapped(data, &(*current)->right);
    else
        insertRecursiveUnwrapped(data, &(*current)->left);
}

void BinarySearchTree::BFS() {
    std::queue<Node*> my_queue;
    my_queue.emplace(root);
    int size = 1;

    while (!my_queue.empty()) {
        for (; size > 0; size--) {            
            Node* top = my_queue.front();

            if (top->left != nullptr)
                my_queue.emplace(top->left);
            if (top->right != nullptr)
                my_queue.emplace(top->right);
            
            std::cout << top->data << ", ";
            my_queue.pop();
        }
        std::cout << std::endl;
        size = my_queue.size();
    }
}

void BinarySearchTree::DFSPreorder() {
    DFSPreorderUnwrapped(root);
}
void BinarySearchTree::DFSPreorderUnwrapped(Node* current) {
    if (current == nullptr)
        return;

    DFSPreorderUnwrapped(current->left);
    DFSPreorderUnwrapped(current->right);
    std::cout << current->data << ", ";
}

void BinarySearchTree::DFSInorder() {
    DFSInorderUnwrapped(root);
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
}
void BinarySearchTree::DFSPostorderUnwrapped(Node* current) {
    if (current == nullptr)
        return;

    DFSPostorderUnwrapped(current->left);
    DFSPostorderUnwrapped(current->right);
    std::cout << current->data << ", ";
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

Node* BinarySearchTree::search(int target) {
    return searchUnwrapped(root, target);
}
Node* BinarySearchTree::searchUnwrapped(Node* current, int target) {
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
    return std::max(heightOfTreeUnwrapped(current->left), heightOfTreeUnwrapped(current->right)) + 1;
}

Node* BinarySearchTree::getInorderSuccessor(Node* target_node) {
    Node* current_node = root;
    Node* successor = nullptr;
    // If the node has a right child, then it is easy
    if (target_node->right != nullptr)
        for (successor = target_node->right; successor->left != nullptr; successor = successor->left);
    
    // If not, we have to trace back from the root to get the successor
    else {
        int target = target_node->data;
        
        while (current_node != target_node) {
            if (target > current_node->data)
                current_node = current_node->right;
            
            else {
                successor = current_node;
                current_node = current_node->left;
            }
        }
    }
    return successor;
}

void BinarySearchTree::deleteNodeRecursive(int target) {
    root = deleteNodeRecursiveUnwrapped(root, target);
}
Node* BinarySearchTree::deleteNodeRecursiveUnwrapped(Node* node, int target) {
    
    if (node == nullptr) {
        return nullptr;
    }
    
    else if (target > node->data) {
        node->right = deleteNodeRecursiveUnwrapped(node->right, target);
        return node;
    }
    else if (target < node->data) {
        node->left = deleteNodeRecursiveUnwrapped(node->left, target);
        return node;
    }
    else {
        // If Leaf Node
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        // If Node With Both Children
        else if (node->left != nullptr && node->right != nullptr) {
            // Find Next Biggest Node
            Node* next_biggest = node->right;
            for (; next_biggest->left != nullptr; next_biggest = next_biggest->left);
            // Copy this next biggest node onto the node that we were meant to delete
            node->data = next_biggest->data;
            // Delete the one that was copied
            node->right = deleteNodeRecursiveUnwrapped(node->right, next_biggest->data);

            return node;
        }
        // If Node With Only One Child
        else {
            Node* child = (node->left != nullptr) ? node->left : node->right;
            delete(node);
            return child;
        }
    }
}

bool BinarySearchTree::isBST() {
    return isBSTUnwrapped(root);
}
bool BinarySearchTree::isBSTUnwrapped(Node* current) {
    if (current == nullptr)
        return true;

    return  isBSTUnwrapped(current->left) &&
            isBSTUnwrapped(current->right) &&
            isSubtreeLesser(current->left, current->data) && 
            isSubtreeGreater(current->right, current->data);
}
// Checking if all values of subtree is lesser than or equal to the node's value 
bool BinarySearchTree::isSubtreeLesser(Node* current, int subtree_value) {
    if (current == nullptr)
        return true;
    if (current->data > subtree_value)
        return false;
    
    return isSubtreeLesser(current->left, subtree_value) && isSubtreeLesser(current->right, subtree_value);
        
}
// Checking if all values of subtree is greater than the node's value 
bool BinarySearchTree::isSubtreeGreater(Node* current, int subtree_value) {
    if (current == nullptr)
        return true;
    if (!(current->data > subtree_value))
        return false;

    return isSubtreeGreater(current->left, subtree_value) && isSubtreeGreater(current->right, subtree_value);
}


// int main() {
//     BinarySearchTree BST;
//     BST.insert(9);
//     BST.insert(7);
//     BST.insert(11);
//     BST.insert(4);
//     BST.insert(3);

//     BST.insertRecursive(0);
//     BST.insertRecursive(313);

//     std::cout << "Min Node: " << BST.minNode()->data << std::endl;
//     std::cout << "Max Node: " << BST.maxNode()->data << std::endl;

//     int target = 313;
//     std::cout << "Searching for " << target << ":" << std::endl;
//     std::cout << BST.search(313)->data << std::endl << std::endl << std::endl;

//     BST.deleteNodeRecursive(11);
//     BST.BFS();
// }


// int main() {
//     BinarySearchTree BST;
//     BST.insert(9);
//     // BST.BFS();

//     std::cout << std::endl << std::endl;
//     BST.deleteNodeRecursive(9);
//     BST.insert(1);
//     BST.BFS();
// }