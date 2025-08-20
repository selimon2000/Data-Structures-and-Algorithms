#include <iostream>
#include <queue>


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data_) : data(data_),
                      left(nullptr),
                      right(nullptr) {}
};


class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() {
        deleteTree(root);
    }

    void insert(int data); // Done
    void insertRecursive(int data); // Done
 
    Node* minNode(); // Done
    Node* maxNode(); // Done
    Node* search(int target); // Done
    Node* searchRecursive(int target); // Done
    
    void BFS(); // Done
    void DFSPreorder(); // Done
    void DFSInorder(); // Done
    void DFSPostorder(); // Done

    int heightOfTree(); // Done
    
    Node* getInorderSuccessor(Node* current_node); // Done

    void deleteNodeRecursive(int target); // Done
    
    bool isBST(); // Done

    void printLeaves(); // Done


private:
    Node* root;
    void deleteTree(Node* current); // Done

    void DFSPreorderUnwrapped(Node* current); // Done
    void DFSInorderUnwrapped(Node* current); // Done
    void DFSPostorderUnwrapped(Node* current); // Done

    void insertRecursiveUnwrapped(int data, Node** current);
    
    Node* searchUnwrapped(Node* current, int target); // Done

    int heightOfTreeUnwrapped(Node* root); // Done

    Node* deleteNodeRecursiveUnwrapped(Node* node, int target); // Done

    bool isBSTUnwrapped(Node* current); // Done
    // Checking if all values of subtree is lesser than or equal to the node's value 
    bool isSubtreeLesser(Node* current, int subtree_value); // Done
    // Checking if all values of subtree is greater than the node's value 
    bool isSubtreeGreater(Node* current, int subtree_value); // Done

    void printLeavesUnwrapped(Node* current); // Done
};


void BinarySearchTree::deleteTree(Node* current) {
    if (current == nullptr)
        return;
    
    deleteTree(current->left);
    deleteTree(current->right);
    delete current;
}

// void BinarySearchTree::insert(int data) {
//     Node* new_node = new Node(data);
//     Node* current = root;
//     if (current == nullptr) {
//         root = new_node;
//         return;
//     }
    
//     while (current != nullptr) {
//         // If we need to go left
//         if (current->data <= data) {
//             // Let's check if we can plant it
//             if (current->left == nullptr)
//                 current->left = new_node;
            
//             current = current->left;
//         }
//         // Going Right
//         else {
//             // Let's check if we can plant it
//             if (current->right == nullptr)
//                 current->right = new_node;
            
//             current = current->right;
//         }
//     }
// }

// With Double Pointer
void BinarySearchTree::insert(int data) {
    if (root == nullptr) {root = new Node(data); return;}
    Node** current = &root;

    while (*current != nullptr) {
        if (data > (*current)->data)
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
    if (*current == nullptr) {
        *current = new Node(data);
        return;
    }
    if (data > (*current)->data)
        insertRecursiveUnwrapped(data, &(*current)->right);
    else
        insertRecursiveUnwrapped(data, &(*current)->left);
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
    Node* current = root;
    while (current != nullptr && current->data != target) {
        if (target < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return current;
}

Node* BinarySearchTree::searchRecursive(int target) {
   return searchUnwrapped(root, target);
}

Node* BinarySearchTree::searchUnwrapped(Node* current, int target) {
    if (current == nullptr) {
        std::cout << "[WARNING]\tNot Found" << std::endl;
        return nullptr;
    }

    if (target == current->data)
        return current;    
    else if (target > current->data)
        return searchUnwrapped(current->right, target);
    else
        return searchUnwrapped(current->left, target);
}

void BinarySearchTree::BFS() {
    if (root == nullptr) return;
    std::queue<Node *> bfs_queue;
    bfs_queue.push(root);

    while (!bfs_queue.empty()) {
        int size = bfs_queue.size();

        for (int i = 0; i < size; i++) {
            Node* current = bfs_queue.front();
            std::cout << current->data << ", ";

            if (current->left != nullptr)
                bfs_queue.push(current->left);
            if (current->right != nullptr)
                bfs_queue.push(current->right);
            
            bfs_queue.pop();
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void BinarySearchTree::DFSPreorder() {
    DFSPreorderUnwrapped(root);
    std::cout << std::endl;
}

void BinarySearchTree::DFSInorder() {
    DFSInorderUnwrapped(root);
    std::cout << std::endl;
}

void BinarySearchTree::DFSPostorder() {
    DFSPostorderUnwrapped(root);
    std::cout << std::endl;
}

void BinarySearchTree::DFSPreorderUnwrapped(Node* current) {
    if (current == nullptr)
        return;
    
    std::cout << current->data << ", ";
    DFSPreorderUnwrapped(current->left);
    DFSPreorderUnwrapped(current->right);
}

void BinarySearchTree::DFSInorderUnwrapped(Node* current) {
    if (current == nullptr)
        return;
    
    DFSInorderUnwrapped(current->left);
    std::cout << current->data << ", ";
    DFSInorderUnwrapped(current->right);
}

void BinarySearchTree::DFSPostorderUnwrapped(Node* current) {
    if (current == nullptr)
        return;

    DFSPostorderUnwrapped(current->left);
    DFSPostorderUnwrapped(current->right);
    std::cout << current->data << ", ";
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

int BinarySearchTree::heightOfTree() {
    return heightOfTreeUnwrapped(root);
}

int BinarySearchTree::heightOfTreeUnwrapped(Node *current) {
    if (current == nullptr)
        return -1;

    return std::max(heightOfTreeUnwrapped(current->left), heightOfTreeUnwrapped(current->right)) + 1;
}


// isBST ////////////////////////////////////////////////////////////////////////
bool BinarySearchTree::isBST() {
    return isBSTUnwrapped(root);
}

bool BinarySearchTree::isBSTUnwrapped(Node* current) {
    if (current == nullptr)
        return true;

    return isBSTUnwrapped(current->left) &&
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

    return isSubtreeLesser(current->left, subtree_value) &&
           isSubtreeLesser(current->right, subtree_value);
}
// Checking if all values of subtree is greater than the node's value 
bool BinarySearchTree::isSubtreeGreater(Node* current, int subtree_value) {
    if (current == nullptr)
        return true;
    if (!(current->data > subtree_value))
        return false;

    return isSubtreeGreater(current->left, subtree_value) &&
           isSubtreeGreater(current->right, subtree_value);
}
///////////////////////////////////////////////////////////////////////////////


Node* BinarySearchTree::getInorderSuccessor(Node* current_node) {
    Node* return_node;
    // If there is a right child then easy:
    if (current_node->right != nullptr) {   
        for (return_node = current_node->right; current_node->right != nullptr; current_node = current_node->right);
        return current_node;
    }
    
    // Else
    // Analogy - we are decending a giant root.
    // When we traverse right, we just jump down.
    // When we traverse left, we need to place the hook on the current platform before jumping again
    Node* successor = root;
    Node* traverse = root;
    int target = current_node->data;

    while (traverse != nullptr && traverse != current_node) {
        if (target > traverse->data)
            traverse = traverse->right;
        else {
            successor = traverse;
            traverse = traverse->right;
        }
    }
    return successor;
}


void BinarySearchTree::deleteNodeRecursive(int target) {
    deleteNodeRecursiveUnwrapped(root, target);
}

Node* BinarySearchTree::deleteNodeRecursiveUnwrapped(Node* node, int target) {
    // Traverse to target
    if (node->data != target) {
        if (target > node->data)
            node->right = deleteNodeRecursiveUnwrapped(node->right, target);
        else
            node->left = deleteNodeRecursiveUnwrapped(node->left, target);
    }

    else {
        // If it is a leaf node
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        // If it has 2 children
        // Replace with next biggest element, by going right, and then as left as possible
        else if (node->left != nullptr && node->right != nullptr) {
            Node* n_b_node = node->right;
            while (n_b_node->left != nullptr)
                n_b_node = n_b_node->left;
            
            node = n_b_node;
            return deleteNodeRecursiveUnwrapped(n_b_node, n_b_node->data);
        }
        // If it has one child
        else {
            Node* return_node;

            // If left child exists
            if (node->left != nullptr)
                return_node = node->left;
            // If right child exists
            else
                return_node = node->right;

            delete node;
            return return_node;
        }
    }

    return nullptr;
}

int main() {
    BinarySearchTree BST;

    // Insertion
    BST.insert(10);
    BST.insert(5);
    BST.insert(15);
    BST.insert(3);
    BST.insert(7);
    BST.insert(12);
    BST.insert(17);

    // Traversal
    std::cout << "Breadth-first Traversal:" << std::endl;
    BST.BFS();
    
    std::cout << "Depth-first Pre-order Traversal:" << std::endl;
    BST.DFSPreorder();

    std::cout << "Depth-first In-order Traversal:" << std::endl;
    BST.DFSInorder();

    std::cout << "Depth-first Post-order Traversal:" << std::endl;
    BST.DFSPostorder();

    // Search
    std::cout << "Searching for values:" << std::endl;
    std::cout << "Search for 7: " << (BST.search(7) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 20: " << (BST.search(20) ? "Found" : "Not Found") << std::endl;

    // Deletion
    std::cout << "Deleting node 15:" << std::endl;
    BST.deleteNodeRecursive(15);
    std::cout << "After deletion:" << std::endl;
    BST.BFS();

    // Check if it's still a BST
    std::cout << "Is it still a BST? " << (BST.isBST() ? "Yes" : "No") << std::endl;

    // Height of Tree
    std::cout << "Height of Tree: " << BST.heightOfTree() << std::endl;

    // return 0;
}