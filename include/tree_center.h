#pragma once
#include "vector"

std::vector<int> bfs_distance(std::vector<std::vector<int>> graph, int start_top);

int get_farthest_node(std::vector<int> distances);