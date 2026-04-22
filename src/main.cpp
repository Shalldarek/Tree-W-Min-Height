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

    auto parents_from_A = result_A.parents;

    std::vector<int> path;

    int actual_node = node_B;

    while (actual_node != -1) {
        path.push_back(actual_node);
                        
        actual_node = parents_from_A[actual_node];

        for (int i = 0; i < path.size(); i++) {
            std::cout << "-> " << path[i] << std::endl; 
        }
    }

    return 0;
}