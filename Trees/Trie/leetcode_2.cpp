#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

#define arr_size 26 // mentioned lowercase english letters


class WordDictionary {
public:

    struct Node {
        char data;
        bool flag = false;
        Node* links[arr_size];

        Node() {
            data = 0;
            std::fill(std::begin(links), std::end(links), nullptr);
        }
        Node(char c) {
            data = c;
            std::fill(std::begin(links), std::end(links), nullptr);
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

    WordDictionary() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        root = new Node();
    }
    

    void addWord(const string &word) {
        Node *cur_n = root; // current_node

        for (auto l : word) {
            cur_n->put(l);
            cur_n = cur_n->getNext(l);
        }

        cur_n->flag = true;
    }


    bool search(string word) {
        return searchUW(word, 0, root);
    }


    // Unwrapped Function / Helper Function
    bool searchUW(string &word, uint16_t pos, Node *node) {
        if(!node) return false; // if the current node is false return failed
        if (pos == word.size()) return (node->flag == 1);

        char c = word[pos];

        if(c == '.') {
            // Return only if it is correct
            for (uint8_t i = 0; i < arr_size; ++i)
                if (searchUW(word, pos + 1, node->links[i])) return true;
            return false;
        }
        else {
            return searchUW(word, pos + 1, node->getNext(c));
        }
    }
};