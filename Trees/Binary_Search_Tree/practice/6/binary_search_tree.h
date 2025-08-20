#pragma once

#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class binary_search_tree {
private:
    struct node;                                                    
    node *root = nullptr;           
public:         
    ~binary_search_tree();                                          
        
    // INSERT OPERATIONS            
    void insert(T data);                                          
    void insert_v2(T data);                                       
    void insertRecursive(T data);                                 
            
    // DELETE OPERATION         
    void deleteNodeRecursive(T target);                           

    // SEARCH OPERATIONS    
    node* minNode() const;                
    node* maxNode() const;                                    
    node* search(T target) const;                           
    node* searchRecursive(T target) const;                  

    // PRINT OPERATIONS
    void printLeaves() const;                                 
    void BFS() const;                                         
    void DFSPreorder() const;                                 
    void DFSInorder() const;                                  
    void DFSPostorder() const;                                

    // OTHER OPERATIONS 
    int heightOfTree() const;                                 
    node* getInorderSuccessor(node* cur) const;
    bool isBST() const;                                       

private:
    void deleteTree(node* cur);                         

    void DFSPreorderUW(node* cur) const;                      
    void DFSInorderUW(node* cur) const;                       
    void DFSPostorderUW(node* cur) const;                     

    void insertRecursiveUW(T data, node** cur);       
    
    node* searchUW(node* cur, T target) const;              

    int heightOfTreeUW(node* cur) const;

    node* deleteNodeRecursiveUW(node* node, T target);

    bool isBSTUW(node* cur) const;                            
    // Checking if all values of subtree is lesser than or equal
    // to the node's value 
    bool isSubtreeLesser(node* cur, T subtree_value) const;
    // Checking if all values of subtree is greater than the node's value 
    bool isSubtreeGreater(node* cur, T subtree_value) const;

    void printLeavesUW (node* cur) const;                      
};


#include "binary_search_tree.tpp"