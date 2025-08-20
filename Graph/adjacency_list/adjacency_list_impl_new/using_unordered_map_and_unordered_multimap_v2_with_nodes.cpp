#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

#define INF 1000


class WeightedGraph {
private:
    unordered_map<int, unordered_multimap<int, float>> adjacencyList;
    unordered_map<int, pair<float, float>> coordinates; // Map of node to (x, y) coordinates

public:
    void addEdge(int src, int dest, float weight);
    void addNode(int node, float x, float y); // Add coordinates for a node
    void printGraph() const;
    void aStar(int start, int end) const;

private:
    float heuristic(int node, int end) const; // Heuristic function
};


void WeightedGraph::addEdge(int src, int dest, float weight) {
    adjacencyList[src].insert({dest, weight});
}

void WeightedGraph::addNode(int node, float x, float y) {
    coordinates[node] = {x, y};
}

void WeightedGraph::printGraph() const {
    cout << "Printing Graph:" << endl;
    for (const auto &vertex : adjacencyList) {
        cout << "Vertex " << vertex.first << " is connected to: ";
        bool putComma = false;
        for (const auto &neighbor : vertex.second) {
            if (!putComma) { putComma = 1; } else cout << ",\t";
            cout << neighbor.first << " (Weight: " << neighbor.second << ")";
        }
        cout << "\n";
    }
    cout << endl << endl;
}

float WeightedGraph::heuristic(int node, int end) const {
    auto [x1, y1] = coordinates.at(node);
    auto [x2, y2] = coordinates.at(end);
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); // Euclidean distance
}

void WeightedGraph::aStar(int start, int end) const {
    unordered_map<int, pair<float, int>> node_dist_prev; // Stores (cost, predecessor)
    node_dist_prev[start] = {0, -1};

    priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> node_order;
    node_order.push({heuristic(start, end), start}); // Initial priority based on heuristic

    while (!node_order.empty()) {
        auto [current_cost, current_node] = node_order.top();
        node_order.pop();

        if (current_node == end) break;

        if (current_cost > node_dist_prev[current_node].first) continue;

        if (adjacencyList.find(current_node) != adjacencyList.end()) {
            for (const auto& [neighbor, weight] : adjacencyList.at(current_node)) {
                float new_dist = node_dist_prev[current_node].first + weight;
                float estimated_total_cost = new_dist + heuristic(neighbor, end);

                if (node_dist_prev.find(neighbor) == node_dist_prev.end() || new_dist < node_dist_prev[neighbor].first) {
                    node_dist_prev[neighbor] = {new_dist, current_node};
                    node_order.push({estimated_total_cost, neighbor});
                }
            }
        }
    }

    // Print path
    if (node_dist_prev.find(end) == node_dist_prev.end()) {
        cout << "No path exists between node " << start << " and node " << end << endl;
        return;
    }

    cout << "Shortest path from " << start << " to " << end << " is: ";
    vector<int> path;
    for (int i = end; i != -1; i = node_dist_prev[i].second) {
        path.push_back(i);
    }
    for (auto it = path.rbegin(); it != path.rend(); ++it) {
        cout << *it;
        if (next(it) != path.rend()) cout << " -> ";
    }
    cout << endl;
    cout << "With cost: " << node_dist_prev[end].first << endl;
}


int main() {
    WeightedGraph graph;

    graph.addNode(0, 0.0, 0.0);
    graph.addNode(1, 1.0, 1.0);
    graph.addNode(2, 2.0, 2.0);
    graph.addNode(3, 3.0, 3.0);
    graph.addNode(4, 4.0, 4.0);
    graph.addNode(11, 5.0, 5.0);

    graph.addEdge(0, 1, 2.1);
    graph.addEdge(0, 3, 5.1);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 321.11);
    graph.addEdge(2, 4, 1.4);
    graph.addEdge(3, 4, 1);
    graph.addEdge(4, 11, 99);

    graph.printGraph();

    graph.aStar(0, 11);
}