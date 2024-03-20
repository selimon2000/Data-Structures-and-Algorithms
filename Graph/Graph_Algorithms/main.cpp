#include "graph_hashmap_class.h"
#include <iostream>


// DAG
int main() {
    Graph g;

    g.addEdge("A", "B", 313, true);
    g.addEdge("B", "C", 20, true);
    g.addEdge("A", "C", 313, true);
    g.addEdge("B", "D", 20, true);
    g.addEdge("E", "D", 20, true);

    // // Add edges to create a directed acyclic graph
    // g.addEdge("A", "B", 313, false);
    // g.addEdge("B", "C", 20, false);
    // g.addEdge("A", "C", 313, false);
    // g.addEdge("D", "B", 20, false); // Ensure no cycle is formed
    // g.addEdge("E", "D", 20, false);
    // g.addEdge("F", "E", 20, false); // Ensure no cycle is formed

    g.printEdges();

    g.BFS();

    g.DFS();

    g.topologicalSort();

    g.SSSP_Distance("B");

    g.Dijkstra("C");
}