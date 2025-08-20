#include "binary_search_tree.h"

template <typename T>
struct binary_search_tree<T>::node {
    node() : l(nullptr), r(nullptr) {}
    node(T val) : val(val), l(nullptr), r(nullptr) {}

    T val;
    node *l;
    node *r;
};

template <typename T>
binary_search_tree<T>::~binary_search_tree() {
    deleteTree(root);
}

// DELETE OPERATION -----------------------------------------------------------

// Uses Post-Order Traversal
template <typename T>
void binary_search_tree<T>::deleteTree(node* cur) {
    if(cur == nullptr) return;

    if(cur->l) deleteTree(cur->l);
    if(cur->r) deleteTree(cur->r);
    delete cur;
}


// INSERT OPERATIONS -----------------------------------------------------------

// Using pointer
template <typename T>
void binary_search_tree<T>::insert(T data) {
    if(root == nullptr) {root = new node(data); return;}

    node *prev;
    node *cur = root;

    while (cur != nullptr) {
        prev = cur;
        cur = (data > cur->val) ? (cur->r) : (cur->l);
    }

    if (data > prev->val)   prev->r = new node(data);
    else                    prev->l = new node(data);
}

// Using double pointer
template <typename T>
void binary_search_tree<T>::insert_v2(T data) {
    if(root == nullptr) {root = new node(data); return;}

    node **cur = &root;

    while (*cur != nullptr) {
        if (data > (*cur)->val) cur = &((*cur)->r);
        else                    cur = &((*cur)->l);
    }
    *cur = new node(data);
}

template <typename T>
void binary_search_tree<T>::insertRecursive(T data) {
    insertRecursiveUW(data, &root);
}

template <typename T>
void binary_search_tree<T>::insertRecursiveUW(T data, node **current) {
    if (*current == nullptr) {*current = new node(data); return;}
    
    insertRecursiveUW(data, (data > (*current)->val) ? &((*current)->r) : &((*current)->l));
}


// DELETE OPERATIONS -----------------------------------------------------------
template <typename T>
void binary_search_tree<T>::deleteNodeRecursive(T target) {
    deleteNodeRecursiveUW(root, target);
}
template <typename T>
typename binary_search_tree<T>::node* binary_search_tree<T>::deleteNodeRecursiveUW(node* cur, T target) {
    if (cur == nullptr) return nullptr;

    // Traverse to target
    if(cur->val != target) {
        if (target > cur->val)  cur->r = deleteNodeRecursiveUW(cur->r, target);
        else                    cur->l = deleteNodeRecursiveUW(cur->l, target);
    }
    else {
        // Case: Leaf Node
        if(cur->l == nullptr && cur->r == nullptr) {
            delete cur;
            return nullptr;
        }

        // Case: 2 Children - Replace with next biggest - go right then all the way left
        else if(cur->l != nullptr && cur->r != nullptr) {
            node* n_n = cur->r; // new_node
            while(n_n->l != nullptr) n_n = n_n->l;
            cur->val = n_n->val;

            // delete n_n
            cur->r = deleteNodeRecursiveUW(cur->r, n_n->val);

            return cur;
        }

        // Case: 1 Child // parent of to_delete_node will have its child pointing to child of to_delete_node
        else {
            node *child_node = (cur->l == nullptr) ? (cur->r) : (cur->l);
            delete cur;
            return child_node;
        }
    }

    return cur;
}


// SEARCH OPERATIONS -----------------------------------------------------------
template <typename T>
typename binary_search_tree<T>::node* binary_search_tree<T>::minNode() const {
    node *cur = root;
    for(; cur->l != nullptr; cur = cur->l);
    return cur;
}

template <typename T>
typename binary_search_tree<T>::node* binary_search_tree<T>::maxNode() const {
    node *cur = root;
    for(; cur->r != nullptr; cur = cur->r);
    return cur;
}

template <typename T>
typename binary_search_tree<T>::node* binary_search_tree<T>::search(T target) const {
    node* cur = root;
    while(cur != nullptr) {
        if(cur->val == target) return cur;
        cur = (target > cur->val) ? (cur->r) : (cur->l);
    }
    
    return cur;
}

template <typename T>
typename binary_search_tree<T>::node* binary_search_tree<T>::searchRecursive(T target) const {
    return searchUW(root, target);
}

template <typename T>
typename binary_search_tree<T>::node* binary_search_tree<T>::searchUW(node* cur, T target) const {
    if(cur->val == target) return cur;
    return searchUW((target > cur->val) ? (cur->r) : (cur->l), target);
}


// PRINT OPERATIONS -----------------------------------------------------------
template <typename T>
void binary_search_tree<T>::printLeaves() const {
    printLeavesUW(root);
    cout << "\n";
}

template <typename T>
void binary_search_tree<T>::printLeavesUW(node* cur) const {
    if (cur->l == nullptr && cur->r == nullptr) {cout << cur->val << ", "; return;};
    if (cur->l) printLeavesUW(cur->l);
    if (cur->r) printLeavesUW(cur->r);
}

// Simple Version, without new lines to represent levels
// void binary_search_tree::BFS() const {
//     queue<node*> node_queue; node_queue.push(root);

//     while(!node_queue.empty()) {
//         node* cur = node_queue.front();
//         node_queue.pop();

//         cout << cur->val << ", ";

//         if(cur->l) node_queue.push(cur->l);
//         if(cur->r) node_queue.push(cur->r);
//     }

//     cout << '\n';
// }

// Representing levels by injecting nullptr as a key in the queue, to indicate a new level
// void binary_search_tree::BFS() const {
//     if (root == nullptr) return; // Handle empty tree case

//     queue<node*> node_queue;
//     node_queue.push(root); node_queue.push(nullptr); // Level delimiter

//     while (!node_queue.empty()) {
//         node* cur = node_queue.front();
//         node_queue.pop();

//         if (cur == nullptr) {
//             // End of the current level
//             cout << '\n';
//             if (!node_queue.empty()) node_queue.push(nullptr); // Add delimiter for the next level
//         } else {
//             // Process the current node
//             cout << cur->val << " ";
//             if (cur->l) node_queue.push(cur->l);
//             if (cur->r) node_queue.push(cur->r);
//         }
//     }
// }

// Representing levels by counting - everytime we finish the count we are at a new level
template <typename T>
void binary_search_tree<T>::BFS() const {
    if (root == nullptr) return; // Handle empty tree case

    queue<node*> n_q; // node_queue
    n_q.push(root);
    int count = 1;

    while (!n_q.empty()) {
        node* cur = n_q.front();
        n_q.pop();

        // End of the current level
        if (count-- == 0) {cout << '\n'; count = n_q.size();}

        // Process the current node
        cout << cur->val << " ";
        if (cur->l) n_q.push(cur->l);
        if (cur->r) n_q.push(cur->r);
    }
}

template <typename T>
void binary_search_tree<T>::DFSPreorder() const {DFSPreorderUW(root);}
template <typename T>
void binary_search_tree<T>::DFSInorder() const {DFSInorderUW(root);}
template <typename T>
void binary_search_tree<T>::DFSPostorder() const {DFSPostorderUW(root);}

template <typename T>
void binary_search_tree<T>::DFSPreorderUW(node* cur) const {
    if(cur == nullptr) return;
    
    cout << cur->val << ", ";
    if(cur->l) DFSPreorderUW(cur->l);
    if(cur->r) DFSPreorderUW(cur->r);
}

template <typename T>
void binary_search_tree<T>::DFSInorderUW(node* cur) const {
    if(cur == nullptr) return;
    
    if(cur->l) DFSInorderUW(cur->l);
    cout << cur->val << ", ";
    if(cur->r) DFSInorderUW(cur->r);
}
template <typename T>
void binary_search_tree<T>::DFSPostorderUW(node* cur) const {
    if(cur == nullptr) return;
    
    if(cur->l) DFSPostorderUW(cur->l);
    if(cur->r) DFSPostorderUW(cur->r);
    cout << cur->val << ", ";   
}


// OTHER OPERATIONS 
template <typename T>
int binary_search_tree<T>::heightOfTree() const {
    return heightOfTreeUW(root);
}
template <typename T>
int binary_search_tree<T>::heightOfTreeUW(node* cur) const {
    if(cur == nullptr) return -1;
    return max(heightOfTreeUW(cur->l), heightOfTreeUW(cur->r)) + 1;
}
template <typename T>
typename binary_search_tree<T>::node* binary_search_tree<T>::getInorderSuccessor(node *cur) const {
    if (cur->r != nullptr) {
        for (cur = cur->r; cur->l != nullptr; cur = cur->l);
        return cur;
    }

    // Analogy: descending a giant root
        // When we traverse right, we just jump down.
        // When we traverse left, we need to place the hook on the current platform before jumping again
    node *hook = root , *trav; // traversal node
    while(trav != cur) {
        if(trav->val > cur->val)
            trav = trav->r;
        else {
            hook = cur;
            trav = trav->l;
        }
    }
    return hook;
}

template <typename T>
bool binary_search_tree<T>::isBST() const {
    return isBSTUW(root);
}
template <typename T>
bool binary_search_tree<T>::isBSTUW(node* cur) const {
    if(cur == nullptr) return true;
    return isBSTUW(cur->l) & isBSTUW(cur->r) &
           isSubtreeLesser(cur->l, cur->val) & isSubtreeGreater(cur->r, cur->val);
}
template <typename T>
bool binary_search_tree<T>::isSubtreeLesser(node* cur, T subtree_value) const {
    if(cur == nullptr) return true;
    if (! (cur->val <= subtree_value)) return false;
    return isSubtreeLesser(cur->l, subtree_value) & isSubtreeLesser(cur->r, subtree_value);
}
template <typename T>
bool binary_search_tree<T>::isSubtreeGreater(node* cur, T subtree_value) const {
    if(cur == nullptr) return true;
    if (! (cur->val > subtree_value)) return false;
    return isSubtreeGreater(cur->l, subtree_value) & isSubtreeGreater(cur->r, subtree_value);
}