#include <iostream>
#include <vector>
using namespace std;


// Add edge
void addEdge(vector<int> adj[], int s, int d) {
    adj[s].push_back(d);
    adj[d].push_back(s);
}

// Print the graph
void printGraph(vector<int> adj[], int V) {
    for (int d = 0; d < V; ++d) {
        cout << "\n Vertex " << d << ":\t";
        for (auto x : adj[d])
            cout << x << ", ";
        printf("\n");
    }
}


int main() {
    // Number of Vertices
    int V = 4;
    // Create a graph - an Array of Vectors in this case
    vector<int> adj[V];

    // Add edges
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    printGraph(adj, V);
}