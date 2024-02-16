#include <iostream>
#include <vector>


class Graph {
private:
    std::vector<std::vector<bool>> adjMatrix;
    int numVertices;

public:
    Graph(int numVertices_) : numVertices(numVertices_) {
        adjMatrix.resize(numVertices, std::vector<bool>(numVertices, false));
    }

    void addEdge(int i, int j) {
        // If the graph is undirected we do it for both
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true;
    }

    void removeEdge(int i, int j) {
        // If the graph is undirected we do it for both
        adjMatrix[i][j] = false;
        adjMatrix[j][i] = false;
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            std::cout << i << ": ";
            for (bool j : adjMatrix[i])
                std::cout << (j ? 1 : 0) << " ";
            std::cout << "\n";
        }
    }
};


int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);

    g.printGraph();
}