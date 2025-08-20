// C++ program for Union by Size with Path Compression
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;



class UnionFind {
    vector<int> parent;
    vector<int> Size;

public:
    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        Size.resize(n, 1);
    }

    // Function to find the representative (or the root
    // node) for the set that includes i
    int find(int i) {
        int root = parent[i];
        if (parent[root] != root)
            return parent[i] = find(root); // Perform path compression

        return root;
    }

    // Unites the set that includes i and the set that includes j by size
    void unionBySize(int i, int j) {
        // Find the representatives (or the root nodes) for the set that includes i
        int irep = find(i);
        // And do the same for the set that includes j
        int jrep = find(j);
        // Elements are in the same set, no need to unite  anything.
        if (irep == jrep) return;

        // Get the size of i’s tree
        int isize = Size[irep];
        // Get the size of j’s tree
        int jsize = Size[jrep];

        // If i’s size is less than j’s size
        if (isize < jsize) {
            // Then move i under j
            parent[irep] = jrep;
            // Increment j's size by i's size
            Size[jrep] += Size[irep];
        }
        // Else if j’s size is less than i’s size
        else {
            // Then move j under i
            parent[jrep] = irep;
            // Increment i's size by j's size
            Size[irep] += Size[jrep];
        }
    }

    int countGroups() {
        int cnt = 0;
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] == i) ++cnt;
        }

        return cnt;
    }

    int countGroupsAlternative() {
        int count = 0;
        for (int i = 0; i < parent.size(); i++) {
            if (find(i) == i) {
                count++;
            }
        }
        return count;
    }

    void printParent() {
        for (int i = 0; i < parent.size(); ++i) {
            cout << parent[i] << " ";
        }
        cout << endl;
    }
};



int main() {
    const int n = 8;
    UnionFind unionFind(n);
    unionFind.unionBySize(0, 1);
    unionFind.unionBySize(2, 3);
    unionFind.unionBySize(0, 4);
    for (int i = 0; i < n; i++) cout << "Element " << i << ": Representative = " << unionFind.find(i) << endl;

    unionFind.printParent();

    // How many different groups
    cout << "Number of groups: " << unionFind.countGroups() << endl;
    cout << "Number of groups: " << unionFind.countGroupsAlternative() << endl;
}