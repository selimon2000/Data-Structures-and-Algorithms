#include "trie.h"
#include <iostream>

using namespace std;


int main () {
    Trie my_trie;

    my_trie.insert("hippo"s);
    cout << "Tree contains the word hippo: " << (my_trie.search("hippo"s) ? ("True") : ("False")) << '\n';
}