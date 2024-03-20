#include "graph_hashmap_class.h"

void Graph::addEdge(std::string x, std::string y, int wt, bool isBidirect) {
    map[x].push_back({y, wt});

    if (!isBidirect)
        return;

    map[y].push_back({x, wt});
}

void Graph::printEdges() {
        std::cout << "Printing Edges:" << std::endl;

        for (const auto sub_map : map) {
            std::cout << sub_map.first << " ->  ";

            for (const auto node : sub_map.second)
                std::cout << node.first << ": " << node.second << ",  ";
            
            std::cout << std::endl;
        }
}

void Graph::BFS() {
    std::cout << std::endl << "Performing BFS:" << std::endl;
    std::queue<std::string> to_visit;
    // std::vector<std::string> visited;
    std::unordered_set<std::string> visited;

    if (map.empty())
        return;
    
    // Starting with node at map.begin()
    std::string current_node = map.begin()->first;
    to_visit.push(current_node);
    // Add the to_visit nodes to the visited list. This is essential so that we don't even plan on visiting places which we have already visited
    visited.insert(current_node);

    int level_count = 1;

    while (!to_visit.empty()) {
        current_node = to_visit.front();
        to_visit.pop();
        std::cout << current_node << ", ";        

        for (const auto node : map[current_node]) {
            std::string new_node = node.first;

            // Let's search if this node has already been added
            if(visited.find(new_node) != visited.end())
                continue;
            
            to_visit.push(new_node);
            visited.insert(new_node);
        }

        if (--level_count == 0)
            std::cout << std::endl;
        level_count = to_visit.size();
    }

    std::cout << std::endl;
}

void Graph::DFS() {
    std::cout << "Performing DFS" << std::endl;
    std::unordered_map<std::string, bool> visited;
    for (auto p : map)
        visited[p.first] = false;
    
    // Let's start DBS Search with the beginning element of the map
    DFSUnwrapped(map.begin()->first, visited);

    std::cout << std::endl << std::endl;
}

void Graph::DFSUnwrapped(const std::string current_node,
                         std::unordered_map<std::string, bool> &visited) {
    visited[current_node] = true;
    std::cout << current_node << ", ";

    for (auto neighbour_pair : map[current_node]) {
        std::string neighbour = neighbour_pair.first;
        if (!visited[neighbour])
            DFSUnwrapped(neighbour, visited);
    }
}

void Graph::topologicalSort() {
    std::stack<std::string> order;
    std::unordered_set<std::string> visited;

    // Call the recursive helper function for every vertex
    for (const auto pair : map) {
        const std::string vertex = pair.first;
        // If the node hasn't already been searched
        // Rather than just initialising the recursive function with map.begin,
        // using a loop ensures that if there is a part of the graph is unreachable, it can continue
        if (visited.find(vertex) == visited.end())
            topologicalSortUtil(vertex, visited, order);
    }

    // Print the topological order by popping elements from the order
    std::cout << "Topological Sort: ";
    while (!order.empty()) {
        std::cout << order.top() << " ";
        order.pop();
    }

    std::cout << std::endl << std::endl;
}

void Graph::topologicalSortUtil(const std::string &vertex,
                                std::unordered_set<std::string> &visited,
                                std::stack<std::string> &order) {
    visited.insert(vertex);

    // Recur for all adjacent vertices of the current vertex
    for (const auto neighbor : map[vertex]) {
        const std::string &nextVertex = neighbor.first;
        if (visited.find(nextVertex) == visited.end())
            topologicalSortUtil(nextVertex, visited, order);
    }

    // Push the current vertex to the order after visiting all its adjacent vertices
    order.push(vertex);
}


void Graph::SSSP_Distance(std::string s) {
    // Initialize the stack to store the topological order
    std::stack<std::string> Stack;

    // Initialize the distance array
    std::unordered_map<std::string, int> dist;
    for (const auto& pair : map)
        dist[pair.first] = inf;
    
    dist[s] = 0;

    // Initialize visited set
    std::unordered_set<std::string> visited;

    // Call the topological sort utility function for every vertex
    for (const auto& pair : map) {
        const std::string& vertex = pair.first;
        if (visited.find(vertex) == visited.end())
            topologicalSortUtil(vertex, visited, Stack);
    
    }

    // Process vertices in topological order
    while (!Stack.empty()) {
        // Get the next vertex from topological order
        const std::string& u = Stack.top();
        Stack.pop();

        // Update distances of all adjacent vertices
        for (const auto& neighbor : map[u]) {
            const std::string& v = neighbor.first;
            int weight = neighbor.second;
            if (dist[u] != inf) {
                if (dist[v] > dist[u] + weight)
                    dist[v] = dist[u] + weight;
                
            }
        }
    }

    // Print the calculated shortest distances
    std::cout << "Shortest distances from vertex " << s << ":" << std::endl;
    for (const auto& pair : dist) {
        std::cout << "Distance to " << pair.first << ": ";
        if (pair.second == inf)
            std::cout << "INF" << std::endl;
        else
            std::cout << pair.second << std::endl;
    }
    std::cout << std::endl;
}

void Graph::Dijkstra(std::string s) {
    // Initialize the set to store vertices and their distances
    std::set<std::pair<int, std::string>> pq;

    // Initialize the distance map and predecessor map
    std::unordered_map<std::string, int> dist;
    std::unordered_map<std::string, std::string> pred;
    std::unordered_map<std::string, bool> visited;
    for (const auto& pair : map) {
        dist[pair.first] = inf;
        pred[pair.first] = "";
        visited[pair.first] = false;
    }
    dist[s] = 0;

    // Insert the source vertex into the set
    pq.insert({0, s});

    // Process vertices until the set becomes empty
    while (!pq.empty()) {
        // Extract the vertex with the minimum distance from the set
        std::string u = pq.begin()->second;
        int current_dist = pq.begin()->first; // Accessing the minimum distance
        pq.erase(pq.begin());

        // Perform relaxation of adjacent vertices
        for (const auto &neighbor : map[u]) {
            std::string v = neighbor.first;
            int weight = neighbor.second;

            if (dist[v] > current_dist + weight) {
                // Erase the old pair from set
                pq.erase({dist[v], v});
                // Update distance and predecessor of v
                dist[v] = current_dist + weight;
                pred[v] = u;

                // Insert the updated pair into the set only if not visited yet
                if (!visited[v])
                    pq.insert({dist[v], v});
            }
        }
    }

    // Print the calculated shortest distances and paths
    std::cout << "Dijkstra's Search: Shortest Paths From Vertex " << s << ": to All Nodes" << std::endl;
    for (const auto& pair : dist) {
        std::cout << "Distance to " << pair.first << ": ";
        if (pair.second == inf)
            std::cout << "INF" << std::endl;
        else {
            std::cout << pair.second << "\tPath: ";
            std::string current = pair.first;
            while (!pred[current].empty()) {
                std::cout << current << " <- ";
                current = pred[current];
            }
            std::cout << s << std::endl;
        }
    }

    std::cout << std::endl;
}