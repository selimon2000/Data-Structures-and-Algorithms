#include <iostream>
#include <vector>


class WeightedGraph {
private:
    int numVertices;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;

public:
    WeightedGraph(int vertices) {
        numVertices = vertices;
        adjacencyList.resize(vertices);
    }

    void addEdge(int src, int dest, int weight) {
        adjacencyList[src].emplace_back(dest, weight);
    }

    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertex " << i << " is connected to: ";
            for (const auto &neighbor : adjacencyList[i])
                std::cout << neighbor.first << " (Weight: " << neighbor.second << ") ";
            std::cout << "\n";
        }
    }
};


int main() {
    WeightedGraph graph(5);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 1);
    graph.addEdge(2, 4, 4);
    graph.addEdge(3, 4, 6);
    graph.printGraph();
}