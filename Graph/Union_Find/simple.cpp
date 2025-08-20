#include <iostream>
#include <numeric>
#include <vector>
using namespace std;



class UnionFind {
public:
    vector<int> parent;
    UnionFind(int size) {
        parent.resize(size);
        // Initialize the parent array with each element as its own representative
        iota(parent.begin(), parent.end(), 0);
    }

    // Find the representative (root) of the set that includes element i
    int find(int i) {
      
        // If i itself is root or representative
        if (parent[i] == i) return i;

        // Else recursively find the representative of the parent
        return find(parent[i]);
    }

    // Unite (merge) the set that includes element i and the set that includes element j
    void unite(int i, int j) {
      
        // Representative of set containing i
        int irep = find(i);
      
        // Representative of set containing j
        int jrep = find(j);
       
        // Make the representative of i's set be the representative of j's set
        parent[irep] = jrep;
    }
};



int main() {
    int size = 5;
    UnionFind uf(size);
    uf.unite(1, 2);
    uf.unite(3, 4);
    bool inSameSet = (uf.find(1) == uf.find(2));
    cout << inSameSet << endl;
}