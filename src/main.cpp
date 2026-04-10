#include <iostream>
#include "../include/graph_io.h"
#include "../include/tree_center.h"

int main() {
    std::string data = "../data/data.txt";
    
    auto graph = loadGraph(data);

    for (int i = 0; i < graph.size(); i++) {
        std::cout << "The top " << i << " is connected with: ";
        for (int neighbor : graph[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }

    auto distances = bfs_distance(graph, 0);

    for (int d : distances) {
        std::cout << d << " ";
    }
    std::cout << std::endl;

    return 0;
}