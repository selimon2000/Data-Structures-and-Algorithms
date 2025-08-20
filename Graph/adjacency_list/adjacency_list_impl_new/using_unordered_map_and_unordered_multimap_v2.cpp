#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define INF 1000


class WeightedGraph {
private:
    unordered_map<int, unordered_multimap<int, float>> adjacencyList; // multi-map is implemented to represent multi-edges

public:
    void addEdge(int src, int dest, float weight);

    void printGraph() const;

    // Not specifying the start node will allow unconnected nodes to be visited
    void DFSWrapper() const;

    void BFS(int start) const;

    void topSortWrapper() const;

    void kahnTopSortWrapper() const;

    float calculatePathLength(const vector<int>& path) const;

    void dijkstraPriorityQueueSSP(int start, int end) const;

    void dijkstraSetSSP(int start, int end) const;

private:
    void DFS(int v, unordered_set<int> &visited) const;
    void topSort(int node, vector<int> &ts_vec, unordered_set<int> &visited) const;
};


void WeightedGraph::addEdge(int src, int dest, float weight) {
    adjacencyList[src].insert({dest, weight});
}

void WeightedGraph::printGraph() const {
    cout << "Printing Graph" << endl << endl;

    for (auto s : adjacencyList) { // s for source
        cout << s.first << " is connected to: ";
        for (auto n : s.second) {// n for neighbour
            cout << "\v" << n.first << " with weight = "<< n.second << ", ";
        }
        cout << endl << endl;
    }
}


int main() {
    WeightedGraph graph;

    graph.addEdge(0, 1, 2.1);
    graph.addEdge(0, 3, 5.1);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 321.11);
    graph.addEdge(2, 4, 1.4);
    graph.addEdge(3, 4, 1);
    graph.addEdge(4, 11, 99);

    graph.printGraph();

    // graph.DFSWrapper();

    // graph.BFS(0);

    // graph.topSortWrapper();

    // graph.kahnTopSortWrapper();

    // graph.dijkstraPriorityQueueSSP(0,11);

    // graph.dijkstraSetSSP(0, 11);
}