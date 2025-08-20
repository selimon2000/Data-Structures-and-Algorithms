#include<bits/stdc++.h>
using namespace std;



int spanningTree(const int V, const int E, const vector<vector<int>> &edges) {
    // Create an adjacency list representation of the graph, and fill the adjacency list with edges and their weights
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; ++i) {
        int u = edges[i][0]; int v = edges[i][1]; int wt = edges[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    
    // Create a priority queue to store edges with their weights
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // Create a visited array to keep track of visited vertices.
    vector<bool> visited(V);
    
    // Variable to store the result (sum of edge weights)
    int res = 0;

    // Perform Prim's algorithm to find the Minimum Spanning Tree ////////////////////////////////
    pq.push({0, 0}); // Start with vertex 0, with a weigh of 0
    while (!pq.empty()) {
        auto &[wt, u] = pq.top(); pq.pop();

        if (visited[u]) continue;  // If the vertex is true, skip if the vertex is already visited
        visited[u] = true;  // Mark the vertex as visited

        res += wt;  // Add the edge weight to the result

        // Explore the adjacent vertices
        for (const auto &v : adj[u]) {
            // v[0] represents the vertex and v[1] represents the edge weight
            if(!visited[v.first])
                pq.push({v.second, v.first});  // Add the adjacent edge to the priority queue
        }
    }


    return res;  // Return the sum of edge weights of the Minimum Spanning Tree
}



int main() {
    vector<vector<int>> graph = {{0, 1, 5},
                      			 {1, 2, 3},
                      			 {0, 2, 1}};

    cout << spanningTree(3, 3, graph) << endl;
}