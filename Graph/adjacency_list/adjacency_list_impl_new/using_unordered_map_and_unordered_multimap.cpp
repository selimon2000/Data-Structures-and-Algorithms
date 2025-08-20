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
    // Because it is a directed graph will only be inserting source
    adjacencyList[src].insert({dest, weight});
}

void WeightedGraph::printGraph() const {
    cout << "Printing Graph:" << endl;

    for (const auto &vertex : adjacencyList) {
        cout << "Vertex " << vertex.first << " is connected to: ";

        bool putComma = false;
        for (const auto &neighbor : vertex.second) {
            if(!putComma){putComma=1;} else cout << ",\t";
            cout << neighbor.first << " (Weight: " << neighbor.second << ")";
        }
        cout << "\n";
    }
    
    cout << endl << endl;
}

void WeightedGraph::DFSWrapper() const {
    cout << "Printing DFS:" << endl;
    unordered_set<int> visited;
    for (const auto &node: adjacencyList) {
        if(visited.find(node.first) == visited.end())
            DFS(node.first, visited);
    }
    cout << endl << endl;
}

void WeightedGraph::DFS(int v, unordered_set<int> &visited) const {
    visited.insert(v);
    cout << v << " ";

    if (adjacencyList.find(v) != adjacencyList.end()) {
        for (const auto &nb : adjacencyList.at(v))
            if (visited.find(nb.first) == visited.end())
                DFS(nb.first, visited);
    }
}

void WeightedGraph::BFS(int start) const {
    cout << "Printing BFS\n";

    unordered_set <int> visited;
    queue<int> to_visit;

    to_visit.push(start);
    visited.insert(start);

    while (!to_visit.empty()) {

        int top = to_visit.front();
        cout << top << endl;
        to_visit.pop();

        if (adjacencyList.find(top) != adjacencyList.end()) {        
            for (const auto node_pair : adjacencyList.at(top)) {  
                if(visited.find(node_pair.first) == visited.end()) {
                    to_visit.push(node_pair.first);
                    visited.insert(node_pair.first);
                }
            }
        }
    }        

    cout << endl << endl;
}

void WeightedGraph::topSortWrapper() const {

    cout << "Printing TopSort List" << endl;

    unordered_set<int> visited;
    vector<int> ts_vec;
    ts_vec.reserve(adjacencyList.size());

    for (const auto node : adjacencyList) {
        if (visited.find(node.first) == visited.end())
            topSort(node.first, ts_vec, visited);
    }
    
    for (auto r_it = ts_vec.rbegin(); r_it != ts_vec.rend(); r_it++)
        cout << *r_it << endl;
    cout << endl;
}

void WeightedGraph::topSort(int node, vector<int> &ts_vec, unordered_set<int> &visited) const {
    visited.insert(node);

    if (adjacencyList.find(node) != adjacencyList.end()) {
        for (const auto nb : adjacencyList.at(node)) {
            if(visited.find(nb.first) == visited.end())
                topSort(nb.first, ts_vec, visited);
        }
    }
    
    ts_vec.push_back(node);
}

void WeightedGraph::kahnTopSortWrapper() const {
    cout << "Topological Sort" << endl;

    // Create a map of a node and its in-degrees
    unordered_map<int, int> in_degrees;
    for (const auto& node : adjacencyList) {

        if (in_degrees.find(node.first) == in_degrees.end())
            in_degrees[node.first] = 0;

        for (const auto nb : node.second)
            in_degrees[nb.first]++;
    }        
        
    // Initialise the queue
    queue<int> node_queue;
    for(const auto &node : in_degrees)
        if (node.second == 0)
            node_queue.push(node.first);        

    // Process the queue
    vector<int> top_sort_vec;
    while(!node_queue.empty()) {
        int cur = node_queue.front();
        node_queue.pop();
        top_sort_vec.push_back(cur);

        // Update in_degrees 
        if (adjacencyList.find(cur) != adjacencyList.end()) {
            for(auto node : adjacencyList.at(cur)) {
                in_degrees.at(node.first)--;
                if (in_degrees.at(node.first) == 0)
                    node_queue.push(node.first);
            }
        }
    }
    
    // Check for cycle
    if (top_sort_vec.size() != in_degrees.size())
        cout << "Graph contains a cycle!" << endl;

    // Printing the vector
    for(const auto &node : top_sort_vec)
        cout << node << endl;
    cout << endl;
}

void WeightedGraph::dijkstraPriorityQueueSSP(int start, int end) const {
    unordered_map<int, pair<float, int>> node_dist_prev;
    node_dist_prev[start] = {0, -1};  // Start node has a distance of 0 and no predecessor, '-1' is a useful breadcrumb, particularly when printing the path

    priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> node_order;
    node_order.push({0, start});

    while (!node_order.empty()) {
        pair<float, int> current_pair = node_order.top();
        node_order.pop();

        // Whilst this was waiting in the priority queue, it may have already been further optimised. If so, just skip
        if (current_pair.first > node_dist_prev[current_pair.second].first) continue;
        // Don't relax the current node; rather break as it's enough
        if (current_pair.second == end) break;

        for (auto node : adjacencyList.at(current_pair.second)) {
            float new_dist = current_pair.first + node.second;

            // If the node hasn't been initialised yet or if the path (AKA weight) is lower than the current path
            if (node_dist_prev.find(node.first) == node_dist_prev.end() || node_dist_prev[node.first].first > new_dist) {
                node_dist_prev[node.first] = {new_dist, current_pair.second};  // Update distance and predecessor
                node_order.push({new_dist, node.first});
            }
        }
    }

    // PRINT PATH
    if (node_dist_prev.find(end) == node_dist_prev.end()) {cout << "No path exists between node " << start << " and node " << end << endl; return;}

    cout << "Shortest path from " << start << " to " << end << " is: ";
    int i = end; // Keeps track of current node
    // Push path onto vector
    vector<int> path;
    while (i != -1) {
        path.push_back(i);
        i = node_dist_prev[i].second;
    }
    for (vector<int>::const_reverse_iterator it = path.rbegin(); it != path.rend(); it++)   
        cout << *it << ", ";
    cout << endl;
    cout << "With cost: " << node_dist_prev[end].first << endl;
}


void WeightedGraph::dijkstraSetSSP(int start, int end) const {
    unordered_map<int, pair<float, int>> node_dist_prev;
    node_dist_prev[start] = {0, -1};

    set<pair<float, int>> node_set;
    node_set.insert({0, start});

    while (!node_set.empty()) {
        auto current_pair = *node_set.begin();
        node_set.erase(node_set.begin());

        int current_node = current_pair.second;
        float current_dist = current_pair.first;

        if (current_node == end) break;

        if (current_dist > node_dist_prev[current_node].first) continue;

        if (adjacencyList.find(current_node) != adjacencyList.end()) {
            for (const auto& [neighbor, weight] : adjacencyList.at(current_node)) {
                float new_dist = current_dist + weight;

                if (node_dist_prev.find(neighbor) == node_dist_prev.end() ||  new_dist < node_dist_prev[neighbor].first) {        
                    node_set.erase({node_dist_prev[neighbor].first, neighbor});
                    node_dist_prev[neighbor] = {new_dist, current_node};
                    node_set.insert({new_dist, neighbor});
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

    graph.addEdge(0, 1, 2.1);
    graph.addEdge(0, 3, 5.1);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 321.11);
    graph.addEdge(2, 4, 1.4);
    graph.addEdge(3, 4, 1);
    graph.addEdge(4, 11, 99);

    graph.printGraph();

    graph.DFSWrapper();

    graph.BFS(0);

    graph.topSortWrapper();

    graph.kahnTopSortWrapper();

    graph.dijkstraPriorityQueueSSP(0,11);

    graph.dijkstraSetSSP(0, 11);
}