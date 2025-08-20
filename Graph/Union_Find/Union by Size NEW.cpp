// C++ program for Union by Size with Path Compression
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;



class UnionFind {
    vector<int> parent;
    vector<int> Size; // In constructor size array is initialised as '1' as that indicates how many components are in that group
    const int _size;
    int n_components;

public:
    UnionFind(int n) : parent(n), _size(n), n_components(n), Size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    // Function to find the representative (or the root node) for the set that includes i
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
        // Elements are in the same set, no need to unite anything.
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

        --n_components;
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

    int size() {
        return _size;
    }

    int num_components() {
        return n_components;
    }
};



// Cycle detection in graph pseudo code /////////////////
// bool has_cycle(vectoredges, n) {
//     uf = UnionFind(n);
//     for u, v in edges:
//         if not uf.union(u, v):
//             return True  # cycle found
//     return false;
// }



int main() {
    const int n = 8;
    UnionFind unionFind(n);
    unionFind.unionBySize(0, 1);
    unionFind.unionBySize(2, 3);
    unionFind.unionBySize(0, 4);
    for (int i = 0; i < n; i++)
        cout << "Element " << i << ": Representative = " << unionFind.find(i) << endl;

    unionFind.printParent();

    // How many different groups
    cout << "Number of groups: " << unionFind.countGroups() << endl;
    cout << "Number of groups: " << unionFind.countGroupsAlternative() << endl;
    cout << "Number of groups: " << unionFind.num_components() << endl;

    // cout << "original size: " << unionFind.size() << endl;
}