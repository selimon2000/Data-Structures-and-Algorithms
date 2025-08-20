#include <iostream>
#include <vector>
#include <utility>


class EdgeListGraph {
private:
    std::vector<std::pair<int, int>> edges;

public:
    void addEdge(int from, int to) {
        edges.emplace_back(from, to);
    }

    void removeEdge(int from, int to) {
        for (auto it = edges.begin(); it != edges.end(); ++it) {
            if (it->first == from && it->second == to) {
                edges.erase(it); break;
            }
        }
    }

    bool hasEdge(int from, int to) const {
        for (const auto &edge : edges) {
            if (edge.first == from && edge.second == to) {
                return true;
            }
        }
        return false;
    }

    std::vector<int> getNeighbors(int vertex) const {
        std::vector<int> neighbors;
        for (const auto& edge : edges) {
            if (edge.first == vertex) {
                neighbors.push_back(edge.second);
            }
        }
        return neighbors;
    }

    int getEdgeCount() const {
        return edges.size();
    }

    const std::vector<std::pair<int, int>>& getEdges() const {
        return edges;
    }
};


int main() {
    EdgeListGraph graph;

    // Add some edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Print the number of vertices and edges
    // std::cout << "Number of vertices: " << graph.getVertexCount() << std::endl;
    std::cout << "Number of edges: " << graph.getEdgeCount() << std::endl;

    // Check if an edge exists
    std::cout << "Edge (0,1) exists: " << (graph.hasEdge(0, 1) ? "Yes" : "No") << std::endl;
    std::cout << "Edge (1,3) exists: " << (graph.hasEdge(1, 3) ? "Yes" : "No") << std::endl;

    // Get neighbors of a vertex
    int vertex = 2;
    std::vector<int> neighbors = graph.getNeighbors(vertex);
    std::cout << "Neighbors of vertex " << vertex << ": ";
    for (int neighbor : neighbors)
        std::cout << neighbor << " ";
    std::cout << std::endl;

    // Remove an edge
    graph.removeEdge(1, 2);
    std::cout << "Edge (1,2) removed" << std::endl;

    // Print all edges
    std::cout << "All edges:" << std::endl;
    const std::vector<std::pair<int, int>> &vec = graph.getEdges();

    for (const auto& edge : graph.getEdges())
        std::cout << "(" << edge.first << ", " << edge.second << ")" << std::endl;
}