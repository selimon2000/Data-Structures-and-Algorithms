#include <iostream>
#include <queue>

#define LOG(x) std::cout << x << std::endl;


class BinarySearchTree {
    
    struct Node {
        int data;
        Node* l;
        Node* r;

        Node(int value) : data(value),
                          l(nullptr),
                          r(nullptr) {}
    };
    Node* root;

    #define LOG_COMMA(x) std::cout << x << ", ";


public:
    BinarySearchTree() : root(nullptr){};
    // ~BinarySearchTree();

    void insert(int data); // DONE
    void insert_v2(int data); // DONE
    void insertRecursive(int data); // DONE
 
    Node* minNode(); // DONE
    Node* maxNode(); // DONE
    Node* search(int target); // DONE
    Node* searchRecursive(int target); // DONE
    
    
    void BFS(); // DONE
    void DFSPreorder(); // DONE
    void DFSInorder(); // DONE
    void DFSPostorder(); // DONE

    int heightOfTree();
    
    Node* getInorderSuccessor(Node* current_node);

    void deleteNodeRecursive(int target); // DONE
    
    bool isBST();

    void printLeaves();


// UW STANDS FOR UNWRAPPED
private:
    void deleteTree(Node* current);

    void DFSPreorderUW(Node* current);  // DONE
    void DFSInorderUW(Node* current);   // DONE
    void DFSPostorderUW(Node* current); // DONE

    void insertRecursiveUW(int data, Node** current); // DONE
    
    Node* searchUW(Node* current, int target); // DONE

    int heightOfTreeUW(Node* root);

    Node* deleteNodeRecursiveUW(Node* node, int target); // DONE

    bool isBSTUW(Node* current);
    // Checking if all values of subtree is lesser than or equal to the node's value 
    bool isSubtreeLesser(Node* current, int subtree_value);
    // Checking if all values of subtree is greater than the node's value 
    bool isSubtreeGreater(Node* current, int subtree_value);

    void printLeavesUW(Node* current);
};


void BinarySearchTree::insert(int data) {
    Node* new_node = new Node(data);

    if (root == nullptr) {root = new_node; return;}
    
    Node* current = root;
    Node* prev;

    while (current != nullptr) {
        prev = current;
        if (data > current->data)   current = current->r;
        else                        current = current->l;
    }

    if (data > prev->data)  prev->r = new_node;
    else                    prev->l = new_node;
}

void BinarySearchTree::insert_v2(int data) {
    Node* new_node = new Node(data);

    if (root == nullptr) {root = new_node; return;}

    Node** current = &root;
    while(*current != nullptr) {
        if (data > (*current)->data)    current = &(*current)->r;
        else                            current = &(*current)->l;
    }
    *current = new Node(data);
}

void BinarySearchTree::insertRecursive(int data) {
    if (root == nullptr) { root = new Node(data); return;}
    insertRecursiveUW(data, &root);
}

void BinarySearchTree::insertRecursiveUW(int data, Node** current) {
    if(*current == nullptr)             *current = new Node(data); 
    
    else if(data > (*current)->data)    return insertRecursiveUW(data, &((*current)->r));
    else if(*current == nullptr)        return insertRecursiveUW(data, &((*current)->l));
}

BinarySearchTree::Node* BinarySearchTree::search(int target) {
    Node* cur = root;
    while (cur->data != target) {
        if (target > cur->data) cur = cur->r;
        else                    cur = cur->l;

        if(cur == nullptr) {LOG("[WARNING] SEARCH TARGET NOT FOUND") return cur;}
    }
    return cur;
}

BinarySearchTree::Node* BinarySearchTree::searchRecursive(int target) {
   return searchUW(root, target);
}
BinarySearchTree::Node* BinarySearchTree::searchUW(Node* current, int target) {
    if(current == nullptr) {std::cout << "[WARNING]\tSearch: element cannot be found" << std::endl; return nullptr;}
    int val = current->data;

    if(target == val) return current;
    if (target > val)   return searchUW(current->r, target);
    else                return searchUW(current->l, target);
}       

BinarySearchTree::Node* BinarySearchTree::minNode() {
    Node* cur = root;
    for (; cur->l != nullptr; cur = cur->l);

    return cur;
}
BinarySearchTree::Node* BinarySearchTree::maxNode() {
    Node* cur = root;
    for (; cur->r != nullptr; cur = cur->r);

    return cur;
}


void BinarySearchTree::BFS() {
    if (root == nullptr) return;
    
    Node* cur = root;
    std::queue<Node*> n_q; // n_q means node_queue
    n_q.push(cur);

    while (!n_q.empty()) {
        int size = n_q.size();

        for (unsigned int i = 0; i < size; i++) {        
            Node* cur = n_q.front(); n_q.pop();
            LOG_COMMA(cur->data);
            if(cur->l != nullptr) n_q.push(cur->l);
            if(cur->r != nullptr) n_q.push(cur->r);
        }
        std::cout << std::endl;
    }
}

void BinarySearchTree::DFSPreorder() {
    DFSPreorderUW(root);
    std::cout << std::endl;
}
void BinarySearchTree::DFSPreorderUW(Node* current) {
    if (current == nullptr) return;
    
    LOG_COMMA(current->data);
    DFSInorderUW(current->l);
    DFSInorderUW(current->r);
}
void BinarySearchTree::DFSInorder() {
    DFSInorderUW(root);
    std::cout << std::endl;
}
void BinarySearchTree::DFSInorderUW(Node* current) {
    if (current == nullptr) return;
    
    DFSInorderUW(current->l);
    LOG_COMMA(current->data);
    DFSInorderUW(current->r);
}

void BinarySearchTree::DFSPostorder() {
    DFSPostorderUW(root);
    std::cout << std::endl;
}
void BinarySearchTree::DFSPostorderUW(Node* current) {
    if (current == nullptr) return;
    
    DFSInorderUW(current->l);
    DFSInorderUW(current->r);
    LOG_COMMA(current->data);
}

void BinarySearchTree::deleteNodeRecursive(int target) {
    if (root == nullptr) return;
    deleteNodeRecursiveUW(root, target);
}
BinarySearchTree::Node* BinarySearchTree::deleteNodeRecursiveUW(Node* node, int target) {
    
    // Traverse To Target
    int val = node->data;
    if (val != target) {
        if (target > val)   node->r = deleteNodeRecursiveUW(node->r, target);
        else                node->l = deleteNodeRecursiveUW(node->l, target);
    }
    else {
        // If it is a leaf node
        if (node->l == nullptr && node->r == nullptr) {
            delete node;
            return nullptr;
        }

        // If it is has both children (replace with next biggest element)
        else if (node->l != nullptr && node->r != nullptr) {
            // Find Next Biggest
            Node* n_b; // Next Biggest
            for (n_b = node->r; n_b->l != nullptr; n_b = n_b->l);

            // Make current node's value equal to next_biggest
            node->data = n_b->data;
            
            // Delete the n_b node
            node->r = deleteNodeRecursiveUW(node->r, n_b->data);
            return node;
        }
        
        // If it has one child
        else {
            Node* child = (node->l == nullptr) ? (node->r) : (node->l);
            delete node;
            return child;
        }
    }
    return node;
}


int BinarySearchTree::heightOfTree() {
    return heightOfTreeUW(root);
}
int BinarySearchTree::heightOfTreeUW(Node* root) {
    if (root == nullptr) return -1;
    
    return std::max(heightOfTreeUW(root->l), heightOfTreeUW(root->l)) + 1;
}

bool BinarySearchTree::isBST() {
    return isBSTUW(root);
}
bool BinarySearchTree::isBSTUW(Node* current) {
    if (current == nullptr) return true;
    
    return isBSTUW(current->l) &
           isBSTUW(current->r) &
           isSubtreeLesser(current->l, current->data) &
           isSubtreeGreater(current->r, current->data);
}
// Checking if all values of subtree is lesser than or equal to the node's value 
bool BinarySearchTree::isSubtreeLesser(Node* current, int subtree_value) {
    if (current == nullptr) return true;
    if (! (current->data <= subtree_value)) return false;
    
    return  isSubtreeLesser(current->l, subtree_value) &
            isSubtreeLesser(current->r, subtree_value);
}
// Checking if all values of subtree is greater than the node's value 
bool BinarySearchTree::isSubtreeGreater(Node* current, int subtree_value) {
    if (current == nullptr) return true;
    if (! (current->data > subtree_value)) return false;
    
    return  isSubtreeGreater(current->l, subtree_value) &
            isSubtreeGreater(current->r, subtree_value);
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

    std::cout << BST.minNode()->data << std::endl;
    std::cout << BST.maxNode()->data << std::endl;

    LOG(BST.searchRecursive(5)->data)
    LOG(BST.search(12)->data)

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
    BST.DFSInorder();

    std::cout << "After deletion:" << std::endl;
    BST.BFS();


    // Check if it's still a BST
    std::cout << "Is it still a BST? " << (BST.isBST() ? "Yes" : "No") << std::endl;


    // Height of Tree
    std::cout << "Height of Tree: " << BST.heightOfTree() << std::endl;
}