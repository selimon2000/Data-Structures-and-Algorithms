// By creating a space-optimized adjacency list using an unordered map, 
// the total number of vertices is 10⁶ but there is no edge that is connected
// to most of the vertices so there is no point in reserving space for those
// vertices thus we will only reserve those vertices which are connected to some
// other vertices. Example:- 0,1,2,4,5,7 has an edge thus we store only the mentioned vertices

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int last_node = 0;

// A utility function to add an edge in an undirected graph.
void addEdge(unordered_map<int, vector<int>> &adj, int src, int dest) {
    adj[src].push_back(dest);
    adj[dest].push_back(src);

    // Update last node;
    last_node = (src > last_node) ? src : (dest > last_node) ? dest : last_node;
}

// A utility function to print the adjacency list representation of graph
void printGraph(unordered_map<int, vector<int>> &adj) {
    for (int v = 0; v <= last_node; v++) {

        if (adj.find(v) != adj.end()) {
            cout << endl << "Vertex " << v << ":\t";
            for (auto x : adj[v])
                cout << x << ", ";
        }   
    }
}


int main() {
    unordered_map<int, vector<int>> adj;

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 7);
    addEdge(adj, 1, 8);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 4);
    addEdge(adj, 7, 4);

    printGraph(adj);
}