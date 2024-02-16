#include <iostream>
#include <vector>

// Edges is what we input, which gets processed by the Graph class, so that it only stored edges
class Edge
{
public:
    int src, dest, weight;
    Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight) {}
};


class Node
{
public:
    int value, weight;

    Node(int value, int weight) : value(value), weight(weight) {}
};


class Graph
{
public:
    // A vector of vectors to represent adjacency list
    std::vector<std::vector<Node>> adj;

    Graph(std::vector<Edge> edges) {
        adj.resize(edges.size());

        // add edges to the undirected graph
        for (Edge &e : edges)
            adj[e.src].emplace_back(e.dest, e.weight);
    }


    void printGraph(Graph graph) {
        int n = graph.adj.size();

        for (int node = 0; node < n; node++) {   
            std::cout << node << ":\t";

            for (Node edge : graph.adj[node])
                std::cout << edge.value << "(" << edge.weight << "),  ";

            std::cout << std::endl;
        }
        
    }
};


int main() {
    std::vector<Edge> edges = {
        {0, 1, 6},
        {1, 2, 7},
        {2, 0, 5},
        {2, 1, 4},
        {3, 2, 10},
        {4, 5, 1},
        {5, 4, 3}};

    Graph graph(edges);

    graph.printGraph(graph);
}