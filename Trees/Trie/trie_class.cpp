#include <iostream>
#include <string>
#include <cstdint>

using namespace std;


class Trie {
// private:
    struct Node {
        char data;
        Node *links[26];
        bool flag = false;

        Node(){}
        Node(char c) {
            data = c;
        }

        bool containsKey(char key) {
            return links[key - 'a'] != nullptr;
        }

        void put (char c, Node* node) {
            links[c - 'a'] = node;
        }

        Node* get (char c) {
            return links[c - 'a'];
        }

        void setEnd() {
            flag = true;
        }
    };

    Node *root;

public:
    Trie() {
        root = new Node();
    }
    ~Trie() {
        deleteTrie(root);
    }


    void insert (const string &word) {
        Node *cur_n = root; // current node

        for (auto l : word) {
            if(!cur_n->containsKey(l)) cur_n->put(l, new Node(l));
            cur_n = cur_n->get(l);
        }

        cur_n->flag = true;
    }

    bool search(const string &word) {
        Node *cur_n = root;

        for (auto l : word) {
            if(!cur_n->containsKey(l)) return false;
            cur_n = cur_n->get(l);
        }

        // See if the end flag is set, and return predicament
        return cur_n->flag == true;
    }

    // Return if there is any word in the trie which starts with the string prefix
    bool startsWith(const string &prefix) {
        Node* cur_n = root;

        for (auto l : prefix) {
            if(!cur_n->containsKey(l)) return false;
            cur_n = cur_n->get(l);
        }

        return true;
    }

private:
    void deleteTrie(Node* node) {
        if (node == nullptr) return;
        
        // Recursively delete all child nodes
        for (uint8_t i = 0; i < 26; ++i) {
            if (node->links[i] != nullptr) deleteTrie(node->links[i]);
        }
        delete node;
    }

};

int main () {
    Trie my_trie;

    my_trie.insert("hippo"s);
    cout << "Tree contains the word hippo: " << (my_trie.search("hippo"s) ? ("True") : ("False")) << '\n';
}