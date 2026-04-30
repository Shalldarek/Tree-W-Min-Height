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

    // Drop the explorer at node 0 to find one extreme edge of the graph
    BFSResult result_start = bfs_distance(graph, 0);

    auto distances_from_start = result_start.distances;
    
    //Find the node that is furthest away from 0 - Point A.
    int node_A = get_farthest_node(distances_from_start);
    std::cout << "First explorer found Point A: " << node_A << std::endl;

    //Drop the explorer exactly at Point A to find the opposite extreme edge
    BFSResult result_A = bfs_distance(graph, node_A);
 
    auto distances_from_A = result_A.distances;

    //The node furthest from Point A is Point B - the longest possible path in the tree
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

    int path_distance = path.size();
    int path_center_idex = path_distance / 2;

    if (path_distance % 2 != 0) {
        std::cout << "The center was found!" << std::endl;
        std::cout << "The edge from the vector 'path' is on the index: " << path[path_center_idex] << std::endl;
    } else {
        std::cout << "Two centers were found!" << std::endl;
        std::cout << "I. The edge from the vector 'path' is on the index: " << path[path_center_idex - 1] << std::endl;
        std::cout << "II. The edge from the vector 'path' is on the index: " << path[path_center_idex] << std::endl;
    }

    return 0;
}