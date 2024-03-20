// #include <iostream>
#include <unordered_map>
#include <list>
#include <string>

class Graph {
    std::unordered_map<std::string, std::list<std::pair<std::string, int>>> map;

public:
    void addEdge(std::string x, std::string y, int wt, bool isBidirect = false) {
        // If the node doesn not already exist
        // auto i = map.find(x);
        // if(i == map.end())
        //     map[x] = std::list<std::pair<std::string, int>>();
        map[x].push_back({y, wt});

        if(!isBidirect)
            return;

        // i = map.find(y);
        // if(i == map.end())
        //     map[y] = std::list<std::pair<std::string, int>>();
        map[y].push_back({x, wt});
    }

    void printEdges() {
        std::cout << "Printing Edges:" << std::endl;

        for (const auto sub_map : map) {
            std::cout << sub_map.first << " ->  ";

            for (const auto node : sub_map.second) {
                std::cout << node.first << "-" << node.second << ",  ";
            }

            std::cout << std::endl;
        }
        
    }
};


// int main() {
//     Graph g;

//     g.addEdge("A", "B", 313, true);
//     g.addEdge("B", "C", 20, true);

//     g.printEdges();
// }