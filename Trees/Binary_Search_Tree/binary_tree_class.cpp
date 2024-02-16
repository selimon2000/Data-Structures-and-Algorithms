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


class BinarySearchTree
{
private:
    Node* root;

public:
    BinarySearchTree() : root(nullptr){};

    // Method 1
    void insertOldSchool(int data);
    // Method 2
    void insert(int data);
    // Method 3
    void insertRecursive(int data);
    void insertRecursiveUnwrapped(Node** current, int data);
    // Method 4
    void insertRecursiveWithReturn(int data);
    Node* insertRecursiveUnwrappedWithReturn(Node** current, int data);

    void printTreeRecursive();
    void printTreeRecursiveUnwrapped(Node* current);

    bool search(int target);
    bool searchRecursive(int target);
    bool searchRecursiveUnwrapped(Node* current, int target);
    // This is better because it returns the actual Node, so it can be used in more functions
    Node* searchRecursiveWithReturn(int target);
    Node* searchRecursiveWithReturnUnwrapped(Node* current, int target);
    // Searching for parent of that node - this is better for deletion as we need to change the to_be_deleted upper edges
    Node* searchParentRecursiveWithReturn(int target);
    Node* searchParentRecursiveWithReturnUnwrapped(Node* current, int target);

    Node* minElement();
    Node* maxElement();

    int heightOfTree();
    int heightOfTreeUnwrapped(Node* root);

    void BFS();
    void DFSPreorder();
    void DFSPreorderUnwrapped(Node* current);
    void DFSInorder();
    void DFSInorderUnwrapped(Node* current);
    void DFSPostorder();
    void DFSPostorderUnwrapped(Node* current);

    bool isBST();
    bool isBSTUnwrapped(Node* current);
    // Checking if all values of subtree is lesser than or equal to the node's value 
    bool isSubtreeLesser(Node* current, int subtree_value);
    // Checking if all values of subtree is greater than the node's value 
    bool isSubtreeGreater(Node* current, int subtree_value);

    void deleteNode(int target);

    void deleteNodeRecursive(int target);
    Node* deleteNodeRecursiveUnwrapped(Node* node, int target);

    Node* getSuccessor(Node* node);
};

void BinarySearchTree::insertRecursive(int data) {
    insertRecursiveUnwrapped(&root, data);
}

void BinarySearchTree::insertOldSchool(int data) {
    Node* new_node = new Node(data);

    if (root == nullptr)
        root = new_node;
    
    else {
        Node* current = root;

        while (1) {
            if (data > current->data) {
                if (current->right == nullptr){              
                    current->right = new_node;
                    return;
                }
                current = current->right;
            
            } else {
                if (current->left == nullptr){              
                    current->left = new_node;
                    return;
                }
                current = current->left;  
            }     
        }
    }
}

void BinarySearchTree::insert(int data) {
    Node** current = &root;

    while (*current != nullptr) {
        if (data  > (*current)->data)
            current = &(*current)->right;
        else
            current = &(*current)->left;
    }

    *current = new Node(data);
}

// Double Pointer because IF root is NULL, it needs to be changed
// EXPLANATION FOR DEREFERENCING THE POINTER; WHEN YOU HAVE A NULL VARIABLE, YOU CAN'T SIMPLY GO BACK TO THE PARENT
// HOWEVER, IN THIS CASE WE ARE MERELY POINTING TO NODE LEFT/RIGHT, AND JUST LOOKING AT WHAT THIS POINTS TO
// THE MAGIC HAPPENS HERE: Node** current = &(*current)->left
// A single pointer can only modify the value it points to, not the pointer itself.
// A double pointer allows you to modify the pointer itself, making it possible to change where it points.
void BinarySearchTree::insertRecursiveUnwrapped(Node** current, int data) {

    if (*current == nullptr)
        *current = new Node(data);    
    
    else
        if (data > (*current)->data)
            insertRecursiveUnwrapped(&(*current)->right, data);
        else
            insertRecursiveUnwrapped(&(*current)->left, data);
}

void BinarySearchTree::insertRecursiveWithReturn(int data) {
    insertRecursiveUnwrappedWithReturn(&root, data);
}

Node* BinarySearchTree::insertRecursiveUnwrappedWithReturn(Node** root, int data) {
    if ((*root) == nullptr)
        *root = new Node(data);

    else
        if (data > (*root)->data)
            (*root)->right = insertRecursiveUnwrappedWithReturn(&(*root)->right, data);
        else
            (*root)->right = insertRecursiveUnwrappedWithReturn(&(*root)->right, data);
    
    return *root;
}

void BinarySearchTree::printTreeRecursive() {
    printTreeRecursiveUnwrapped(root);
    std::cout << std::endl << std::endl;
}

void BinarySearchTree::printTreeRecursiveUnwrapped(Node* current) {
    if (current == nullptr)
        return;
    
    printTreeRecursiveUnwrapped(current->left);
    std::cout << current->data << ", ";
    printTreeRecursiveUnwrapped(current->right);
}

bool BinarySearchTree::search(int target) {
    Node* current = root;
    while (current != nullptr) {

        if (current->data == target)
            return true;
        else if (target > current->data)
            current = current->right;
        else
            current = current->left;
    }

    return false;    
}

bool BinarySearchTree::searchRecursive(int target) {
    return searchRecursiveUnwrapped(root, target);
}

bool BinarySearchTree::searchRecursiveUnwrapped(Node* current, int target) {
    if (current == nullptr)
        return false;
    else if (current->data == target)
        return true;
    else if (target > current->data)
        return searchRecursiveUnwrapped(current->right, target);
    else
        return searchRecursiveUnwrapped(current->left, target);
}       

Node* BinarySearchTree::searchRecursiveWithReturn(int target) {
    return searchRecursiveWithReturnUnwrapped(root, target);
}

Node* BinarySearchTree::searchRecursiveWithReturnUnwrapped(Node* current, int target) {
    if (current == nullptr)
        return nullptr;

    else if (target == current->data)
        return current;
    
    else if (target > current->data)
        return searchRecursiveWithReturnUnwrapped(current->right, target);
    else
        return searchRecursiveWithReturnUnwrapped(current->left, target);
}

Node* BinarySearchTree::searchParentRecursiveWithReturn(int target) {
    return searchParentRecursiveWithReturnUnwrapped(root, target);
}

Node* BinarySearchTree::searchParentRecursiveWithReturnUnwrapped(Node* current, int target) {
    if (current == nullptr)
        return nullptr;

    // else if (current->data == target       || // Incase we are already there as it could be the head
    //          current->left->data == target ||
    //          current->right->data == target)
    //     return current;

    // else if (current->left->data == target ||
    //          current->right->data == target)
    //     return current;
    else if ((current->left != nullptr && current->left->data == target) ||
         (current->right != nullptr && current->right->data == target))
        return current;

    else if (target > current->data)
        return searchParentRecursiveWithReturnUnwrapped(current->right, target);
    else
        return searchParentRecursiveWithReturnUnwrapped(current->left, target);
}

Node* BinarySearchTree::minElement() {
    Node* current = root;
    for (; current->left != nullptr; current = current->left);
    return current;
}

Node* BinarySearchTree::maxElement() {
    Node* current = root;
    for (; current->right != nullptr; current = current->right);
    return current;
}

int BinarySearchTree::heightOfTree() {
    return heightOfTreeUnwrapped(root);
}

int BinarySearchTree::heightOfTreeUnwrapped(Node* root) {
    if (root == nullptr)
        return -1;

    return std::max(heightOfTreeUnwrapped(root->left), heightOfTreeUnwrapped(root->right)) + 1;
}

void BinarySearchTree::BFS() {

    if (root == nullptr) {
        std::cout << "[WARNING]\tTree is empty." << std::endl;
        return;
    }

    std::queue<Node*> my_queue;
    my_queue.push(root);

    while (!my_queue.empty()) {

        for (int size = my_queue.size(); size > 0; size--) {

            Node* current = my_queue.front();        
            std::cout << current->data << ", ";
            
            if (current->left != nullptr)
                my_queue.push(current->left);
            if (current->right != nullptr)
                my_queue.push(current->right);
            
            my_queue.pop();
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void BinarySearchTree::DFSPreorder() {
    DFSPreorderUnwrapped(root);
    std::cout << std::endl << std::endl;
}

void BinarySearchTree::DFSPreorderUnwrapped (Node* current) {
    if (current == nullptr)
        return;

    std::cout << current->data << ", ";
    DFSPreorderUnwrapped(current->left);
    DFSPreorderUnwrapped(current->right);  
}

void BinarySearchTree::DFSInorder() {
    DFSInorderUnwrapped(root);
    std::cout << std::endl << std::endl;
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
    std::cout << std::endl << std::endl;
}

void BinarySearchTree::DFSPostorderUnwrapped(Node* current) {
    if (current == nullptr)
        return;

    DFSPostorderUnwrapped(current->left);
    DFSPostorderUnwrapped(current->right);  
    std::cout << current->data << ", ";
}

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

bool BinarySearchTree::isSubtreeLesser(Node* current, int subtree_value) {
    if (current == nullptr)
        return true;
    
    if(current->data > subtree_value)
        return false;

    return isSubtreeLesser(current->left, subtree_value) && isSubtreeLesser(current->right, subtree_value);
}

bool BinarySearchTree::isSubtreeGreater(Node* current, int subtree_value) {
    if (current == nullptr)
        return true;
    
    if(!(current->data > subtree_value))
        return false;

    return isSubtreeGreater(current->left, subtree_value) && isSubtreeGreater(current->right, subtree_value);
}

void BinarySearchTree::deleteNode(int target) {
    Node* parent = searchParentRecursiveWithReturn(target);
    Node* delete_node;
    bool isLeft;

    if (parent == nullptr) {
        std::cout << "[WARNING]\tdeleteNode() failed as target was not found" << std::endl;
        return;
        }
    if (target == parent->left->data) {
        isLeft = true;
        delete_node = parent->left;
        }
    else {
        isLeft = false;
        delete_node = parent->right;
        }

    // Case: leaf node
    if (delete_node->left == nullptr &&
        delete_node->right == nullptr) {
        free(delete_node);
        if (isLeft)
            parent->left = nullptr;
        else
            parent->right = nullptr;
    }

    // Case: node with both children
    else if (delete_node->left != nullptr &&
             delete_node->right != nullptr) {

        // Go to the next biggest node
        Node* temp = delete_node->right;
        while (temp->left != NULL)
            temp = temp->left;

        // Swapping the values
        int to_swap = delete_node->data;
        delete_node->data = temp->data;
        temp->data = to_swap;
        deleteNode(to_swap);
    }

    // Case: node with only 1 child
    else {
        // First we have to see which side the child is
        if (delete_node->right == nullptr) {
            if (isLeft)
                parent->left = delete_node->left;
            else
                parent->left = delete_node->right;
        }
        else {
            if (isLeft)
                parent->right = delete_node->left;
            else
                parent->right = delete_node->right;
        }
        free(delete_node);
    }
}

void BinarySearchTree::deleteNodeRecursive(int target) {
    deleteNodeRecursiveUnwrapped(root, target);
}

Node* BinarySearchTree::deleteNodeRecursiveUnwrapped(Node* node, int target) {
    // Find the node //////////////////////
    if (node == nullptr) {
        std::cout << "[WARNING]\tdeleteNodeRecursiveUnwrapped(): node is null so target does not exist" << std::endl;
        return node;
    }
    
    else if (node->data != target) {
        if (target > node->data)
            node->right = deleteNodeRecursiveUnwrapped(node->right, target);
        else
            node->left = deleteNodeRecursiveUnwrapped(node->left, target);
        
        return node;
    }
    ///////////////////////////////////////

    else {
        // Scenario 1 - deleting leaf node
        if (node->left == nullptr && node->right == nullptr) {
            free(node);
            return nullptr;
        }

        // Scenario 2 - deleting node with both children
        else if (node->left != nullptr && node->right != nullptr) {
            // Find next biggest node
            Node* next_biggest = node->left;
            while (next_biggest->right != nullptr)
                next_biggest = next_biggest->right;
            
            node->data = next_biggest->data;
            deleteNodeRecursiveUnwrapped(next_biggest, target);
            return node;
        }

        // Scenario 3 - deleting node with only one child
        else {
            Node* child_of_node;
            if (node->left == nullptr)
                child_of_node = node->right;
            else
                child_of_node = node->left;
                        
            free(node);
            return child_of_node;
        }
    }
}

Node* BinarySearchTree::getSuccessor(Node* node) {
    Node* successor = nullptr;

    if (node->right != nullptr)
        for (successor = node->right; successor->left != nullptr; successor = successor->left);

    // The successor is above
    else {
        successor = root;
        Node* current = root;
        int target = node->data;

        while (current != node) {
            
            // If target <= current->data
            if (!(target > current->data)) {
                successor = current;
                current = current->left;
            }
            // If the node is the right child of a parent node, then the successor would be the parent 
            else
                current = current->right;
        }
    }

    return successor;
}


/*
int main() {
    BinarySearchTree my_tree;

    my_tree.insertRecursive(1);
    my_tree.printTreeRecursive();

    my_tree.insertRecursive(2);
    my_tree.insertOldSchool(66);
    my_tree.insertRecursive(4);
    my_tree.insertRecursive(3);
    my_tree.insertRecursive(6);

    my_tree.insertRecursiveWithReturn(313);

    my_tree.insert(99);
    my_tree.printTreeRecursive();

    std::cout << "Searching if element exists:\t" << my_tree.search(66) << std::endl;
    std::cout << "Searching if element exists:\t" << my_tree.searchRecursive(313) << std::endl << std::endl;

    std::cout << "Min number is: " << my_tree.minElement()->data << std::endl;
    std::cout << "Max number is: " << my_tree.maxElement()->data << std::endl << std::endl;


    std::cout << "Height of the tree is: " << my_tree.heightOfTree() << std::endl;

    std::cout << "BFS Search:" << std::endl;
    my_tree.BFS();

    std::cout << "DFS Preorder Search:" << std::endl;
    my_tree.DFSPreorder();

    std::cout << "DFS Inorder Search:" << std::endl;
    my_tree.DFSInorder();

    std::cout << "DFS Postorder Search:" << std::endl;
    my_tree.DFSPostorder();

    std::cout << "Checking if tree is Binary Search Tree: " << my_tree.isBST() << std::endl;

    int target = 313;
    std::cout << "Searching for target: " << target << std::endl;
    Node* search_node = my_tree.searchRecursiveWithReturn(target);
    if (search_node == nullptr)
        std::cout << "[WARNING]\t Search Failed" << std::endl;
    else    
        std::cout << "Value is: " << search_node->data << std::endl;

    // my_tree.deleteNode(313);
    // my_tree.printTreeRecursive();

    // std::cout << "DFS Inorder Search:" << std::endl;
    // my_tree.BFS();

    my_tree.printTreeRecursive();

    my_tree.deleteNodeRecursive(313);
    my_tree.printTreeRecursive();


    std::cout << "BFS Search:" << std::endl;
    my_tree.BFS();

    std::cout << my_tree.getSuccessor(my_tree.searchRecursiveWithReturn(66))->data << std::endl;
    std::cout << my_tree.getSuccessor(my_tree.searchRecursiveWithReturn(6))->data << std::endl;
}
*/

// int main() {
//     BinarySearchTree my_tree;

//     my_tree.insertRecursive(1);
//     my_tree.printTreeRecursive();

//     my_tree.insertRecursive(2);
//     my_tree.insertOldSchool(66);
//     my_tree.insertRecursive(4);
//     my_tree.insertRecursive(3);
//     my_tree.insertRecursive(6);

//     my_tree.insertRecursiveWithReturn(313);

//     my_tree.insert(99);
//     my_tree.printTreeRecursive();
// }

int main() {
    BinarySearchTree my_tree;

    my_tree.insert(1);
    my_tree.insert(2);
    my_tree.insert(66);
    my_tree.insert(4);
    my_tree.insert(3);
    my_tree.insert(6);
    my_tree.insert(313);
    my_tree.insert(99);

    my_tree.printTreeRecursive();
}