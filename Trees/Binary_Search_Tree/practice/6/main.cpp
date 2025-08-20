#include <iostream>
#include "binary_search_tree.h"

using namespace std;

#include "binary_search_tree.h"


int main() {
    // Create an instance of the binary_search_tree
    binary_search_tree<float> bst;

    // Test Insert Operations
    cout << "Inserting values into the binary search tree:\n";
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20.231);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Test Traversals
    cout << "\nBreadth-First Search (BFS):\n";
    bst.BFS();

    cout << "\nDepth-First Search (DFS) - Preorder:\n";
    bst.DFSPreorder();

    cout << "\nDepth-First Search (DFS) - Inorder:\n";
    bst.DFSInorder();

    cout << "\nDepth-First Search (DFS) - Postorder:\n";
    bst.DFSPostorder();

    // Test Search Operations
    cout << "\nSearching for value 40:\n";
    auto foundNode = bst.search(40);
    if (foundNode) {
        cout << "Value 40 found in the tree.\n";
    } else {
        cout << "Value 40 not found in the tree.\n";
    }

    cout << "\nSearching for value 100:\n";
    foundNode = bst.search(100);
    if (foundNode) {
        cout << "Value 100 found in the tree.\n";
    } else {
        cout << "Value 100 not found in the tree.\n";
    }

    // Test Delete Operation
    cout << "\nDeleting value 50:\n";
    bst.deleteNodeRecursive(50);

    cout << "\nBreadth-First Search (BFS) after deletion:\n";
    bst.BFS();

    // Test Height of Tree
    cout << "\nHeight of the tree:\n";
    cout << bst.heightOfTree() << endl;

    // Test if Tree is a Valid BST
    cout << "\nIs the tree a valid BST?\n";
    cout << (bst.isBST() ? "Yes" : "No") << endl;

    // Test Min and Max Node
    cout << "\nMinimum value in the tree:\n";
    auto minNode = bst.minNode();
    if (minNode) {
        cout << "Min value: " << minNode->val << endl;
    }

    cout << "\nMaximum value in the tree:\n";
    auto maxNode = bst.maxNode();
    if (maxNode) {
        cout << "Max value: " << maxNode->val << endl;
    }

    // Test Print Leaves
    cout << "\nPrinting leaf nodes:\n";
    bst.printLeaves();
}