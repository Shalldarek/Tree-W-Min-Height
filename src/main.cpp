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
    std::cout << "-----------------------------------" << std::endl;

    BFSResult result_start = bfs_distance(graph, 0);

    auto distances_from_start = result_start.distances;
    
    int node_A = get_farthest_node(distances_from_start);
    std::cout << "First explorer found Point A: " << node_A << std::endl;


    BFSResult result_A = bfs_distance(graph, node_A);
 
    auto distances_from_A = result_A.distances;

    int node_B = get_farthest_node(distances_from_A);
    std::cout << "Second explorer found Point B: " << node_B << std::endl;

    std::cout << "The distance of this path is: " << distances_from_A[node_B] << std::endl;
    return 0;
}