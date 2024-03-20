#pragma once

#include <list>
#include <string>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>

class Graph {
    std::unordered_map<std::string, std::list<std::pair<std::string, int>>> map;
    int inf = std::numeric_limits<int>::max();
    // Recursive Function within DFS()
    void DFSUnwrapped(const std::string current_node,
                      std::unordered_map<std::string, bool> &visited);

    void topologicalSortUtil(const std::string& vertex, std::unordered_set<std::string>& visited, std::stack<std::string>& stack);

public:
    void addEdge(std::string x, std::string y, int wt, bool isBidirect = false);

    void printEdges();

    void BFS();

    void DFS();

    void topologicalSort();

    // Single Source Shortest Path Problem - For DAG. Calculates the distance
    void SSSP_Distance(std::string s);

    void Dijkstra(std::string s);
};