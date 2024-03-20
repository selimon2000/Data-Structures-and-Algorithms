#include <iostream>
#include <list>


class Graph{
    int v_n;
    std::list<int> *l;

public:
    Graph(int v_n_) : v_n(v_n_){
        l = new std::list<int>[v_n];
    };

    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printEdges() {
        for (int i = 0; i < v_n; i++) {
            std::cout << "Vertex " << i << ":" << "\t";
            for (int edge : l[i])
                std::cout << edge << ", ";
            std::cout << std::endl;
        }        
    }
};


int main() {
    Graph g(4);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);

    g.printEdges();
}