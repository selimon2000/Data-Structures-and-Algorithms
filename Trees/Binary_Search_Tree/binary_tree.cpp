#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <queue>


struct bst_node {
    int data;
    struct bst_node* left;
    struct bst_node* right;
};


int max(int a, int b){
    return a > b ? a : b;
}


struct bst_node* newNode(int data) {
    struct bst_node* ptr = (struct bst_node*)malloc(sizeof(struct bst_node));
    
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}

void insert(struct bst_node** root, int data) {
    if ((*root) == NULL) {
            *root = newNode(data);
            return;
        }
    
    else if (data <= (*root)->data)
        insert(&((*root)->left), data);
    
    else
        insert(&(*root)->right, data);
}

void printInOrder(struct bst_node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

bool search(struct bst_node* root, int data) {
    if (root == NULL) return false;
    else if (root->data == data) return true;
    else if (root->data > data) return search(root->right, data);
    else return search(root->left, data); 
}

void minElement(struct bst_node* root) {
    if (root == NULL) {
        printf("Tree is empty");
        return;
    }
    else if (root->left == NULL) {
        printf("\n\nLowest element is: %d", root->data);
        return;
    }

    return minElement(root->left);
}

void maxElement(struct bst_node* root) {
    if (root == NULL) {
        printf("Tree is empty");
        return;
    }
    if (root->right == NULL) {
        printf("\n\nHighest element is: %d", root->data);
        return;
    }

    return maxElement(root->right);
}

int heightOfTree(struct bst_node *root) {
    // THE LINE BELOW IS NOT RUN WHEN WE ARE AT THE LEAF OF THE NODE, BUT RATHER WHEN WE AT THE
    // LEFT AND RIGHT CHILD OF THE LEAF, WHICH IS EQUAL TO NULL; THAT'S WHY WE ADD '-1'
    if (root == NULL)
        return -1;
    // NOTE: THIS ELSE IF STATEMENT IS ONLY FOR OPTIMISATION, TO CHECK IF WE ARE ALREADY AT A LEAF;
    // WORKS THE SAME WITHOUT IT
    else if (root->left == NULL && root->right == NULL)
        return 0;

    return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
}

void breadthFirstSearch(struct bst_node* root) {
    if (root == NULL)
        return;

    std::queue<struct bst_node*> breadth_queue;
    breadth_queue.push(root);

    while (!breadth_queue.empty()) {
        struct bst_node* current = breadth_queue.front();
        breadth_queue.pop();

        if (current != NULL) {
            printf("%d, ", current->data);
            breadth_queue.push(current->left);
            breadth_queue.push(current->right);
        }
    }
}

bool isBST(struct bst_node* root, int min, int max) {
    if (root == NULL)
        return true;

    if (root->data <= min || root->data > max)
        return false;

    return isBST(root->left, min, root->data) &&
           isBST(root->right, root->data, max);
}

struct bst_node* deleteNode(struct bst_node* root, int data) {
    // If the tree is empty
    if (root == NULL);

    // Let's find the node
    else if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    // When we have found the node
    else {
        // Case 1: leaf child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
            return root; 
        }
        // Case 2: one child
        else if (root->left == NULL) {
            struct bst_node* to_delete = root;
            root = root->right;
            free(to_delete);
        }
        else if (root->right == NULL) {
            struct bst_node* to_delete = root;
            root = root->left;
            free(to_delete);
        }
        // Case 3: 2 children
        else {
            // First find the smallest number in the after starting in the right child
            struct bst_node* temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;    
}

struct bst_node* minValue(struct bst_node* node) {
    while (node->left!=NULL)
        node = node->left;
    
    return node;
}

struct bst_node* getSuccessor(struct bst_node* root, struct bst_node* node){

    if (node->right != NULL)
        return minValue(node->right);

    else {
        int next_data = node->data;
        struct bst_node* successor = NULL;

        while (root != NULL) {
            // As we traverse we record successor, which for most cases is the parent of the child as we traverse
            if (next_data < root->data) {
                successor = root;
                root = root->left;
            }
            
            // We don't care if from the root we go right, because if the node is the right child it means it has already gone to that parent node
            else if (next_data > root->data)
                root = root->right;
            
            // When root equals to targeted node
            else
                break;
        }
        return successor;
    }
}

int main() {

    struct bst_node* root = NULL;

    // Example usage: inserting nodes into the BST
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 3);
    insert(&root, 5);

    // Print the BST in order
    printf("In-order traversal: ");
    printInOrder(root);
    printf("\n");

    // Print the binary tree with Breadth First Search (when searching by level)
    printf("\nBreadth First Search:\n");
    breadthFirstSearch(root);

    // Example: Searching for 5
    printf("\n\nSearching for 5: %d", search(root, 5));

    // // Example: Searching for 99
    printf("\n\nSearching for 99: %d", search(root, 99));

    minElement(root);    
    maxElement(root);

    printf("\nHeight of the tree is: %d\n", heightOfTree(root));

    printf("\n Checking if binary tree is BST: %d", int(isBST(root, -1000, 1000)));

    printf("\nDeleting Node");
    deleteNode(root, 7);

    // Print the BST in order
    printf("In-order traversal: ");
    printInOrder(root);
    printf("\n");

    printf("Successor: %d", getSuccessor(root, root->left->right)->data);

    return 0;
}