#include "trie.h"


// Struct and its methods ////////////////////////////////////
struct Trie::Node {
    char data;
    Node *links[size];
    bool flag = false;

    Node(){
        for (uint8_t i = 0; i < size; i++)    links[i] = nullptr;
    }
    Node(char c) {
        data = c;
        for (uint8_t i = 0; i < size; i++)    links[i] = nullptr;
    }

    bool containsKey(char key) {
        return links[key - 'a'] != nullptr;
    }

    void put (char c) {
        links[c - 'a'] = new Node(c);
    }

    Node* get (char c) {
        return links[c - 'a'];
    }

    void setEnd() {
        flag = true;
    }
};


// Consructor ////////////////////////////////////
Trie::Trie() {
    root = new Node();
}
Trie::~Trie() {
    deleteTrie(root);
}


// Class Methods ////////////////////////////////////
void Trie::insert (const string &word) {
    Node *cur_n = root; // current node

    for (auto l : word) {
        if(!cur_n->containsKey(l)) cur_n->put(l);
        cur_n = cur_n->get(l);
    }

    cur_n->flag = true;
}


bool Trie::search(const string &word) {
    Node *cur_n = root;

    for (auto l : word) {
        if(!cur_n->containsKey(l)) return false;
        cur_n = cur_n->get(l);
    }

    // See if the end flag is set, and return predicament
    return cur_n->flag == true;
}


bool Trie::startsWith(const string &prefix) {
    Node* cur_n = root;

    for (auto l : prefix) {
        if(!cur_n->containsKey(l)) return false;
        cur_n = cur_n->get(l);
    }

    return true;
}


void Trie::deleteTrie(Node* node) {
    if (node == nullptr) return;
    
    // Recursively delete all child nodes
    for (uint8_t i = 0; i < 26; ++i) {
        if (node->links[i] != nullptr) deleteTrie(node->links[i]);
    }
    delete node;
}