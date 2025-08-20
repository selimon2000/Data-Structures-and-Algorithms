#include <iostream>
#include <map>


class WeightedGraph {
private:
    std::map<int, std::map<int, int>> adjacencyList;

public:
    void addEdge(int src, int dest, int weight) {
        adjacencyList[src][dest] = weight;
    }

    void printGraph() {
        for (const auto &vertex : adjacencyList) {
            std::cout << "Vertex " << vertex.first << " is connected to: ";
            for (const auto &neighbor : vertex.second)
                std::cout << neighbor.first << " (Weight: " << neighbor.second << ") ";
            std::cout << "\n";
        }
    }
};


int main() {
    WeightedGraph graph;

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 1);
    graph.addEdge(2, 4, 4);
    graph.addEdge(3, 4, 6);

    graph.printGraph();
}