#pragma once

#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

#define size 26

class Trie {
    struct Node;

    Node *root;

public:
    Trie();
    ~Trie();

    void insert (const string &word);

    bool search(const string &word);

    // Return if there is any word in the trie which starts with the string prefix
    bool startsWith(const string &prefix);

private:
    void deleteTrie(Node* node);
};


#include "trie.tpp"