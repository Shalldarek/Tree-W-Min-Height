#pragma once
#include <vector>

struct BFSResult {
    std::vector<int> distances;
    std::vector<int> parents;
};

BFSResult bfs_distance(std::vector<std::vector<int>> graph, int start_top);

int get_farthest_node(std::vector<int> distances);