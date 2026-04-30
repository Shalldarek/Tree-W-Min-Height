#pragma once
#include <vector>

struct BFSResult {
    std::vector<int> distances;
    std::vector<int> parents;
};

//Breadth-First Search - Function returns a custom struct containing both distances and the path history (parents)
BFSResult bfs_distance(std::vector<std::vector<int>> graph, int start_top);

int get_farthest_node(std::vector<int> distances);