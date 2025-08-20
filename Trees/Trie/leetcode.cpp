#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

#define arr_size 26 // mentioned lowercase english letters


class Trie {
// private:
    struct Node {
        char data;
        bool flag = false;
        Node* links[arr_size];

        Node() {
            for (uint8_t i = 0; i < arr_size; ++i) links[i] = nullptr;
        }
        Node(char c) {
            data = c;
            for (uint8_t i = 0; i < arr_size; ++i) links[i] = nullptr;
        }

        Node* getNext(char c) {
            return links[c - 'a'];
        }

        bool isKey(char c) {
            return (!(links[c - 'a'] == nullptr));
        }

        void put (char c) {
            if (!isKey(c)) links[c - 'a'] = new Node(c);
        }
    };
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    
    void insert(const string &word) {
        Node *cur_n = root; // current_node

        for (auto l : word) {
            cur_n->put(l);
            cur_n = cur_n->getNext(l);
        }

        cur_n->flag = true;
    }
    

    bool search (const string &word) const{
        Node *cur_n = root; // current_node

        for (auto l : word) {
            cur_n = cur_n->getNext(l);
            if(!cur_n) return false;
        }

        return (cur_n->flag == true);
    }
    

    bool startsWith (const string &prefix) const{
        Node *cur_n = root; // current_node

        for (auto l : prefix) {
            cur_n = cur_n->getNext(l);
            if(!cur_n) return false;
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */