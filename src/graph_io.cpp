#include "../include/graph_io.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::vector<int>> loadGraph(std::string location) {
    std::fstream file(location);
    std::vector<std::vector<int>> adjList;
    int u, v;

    while (file >> u >> v) {
        int max_node = std::max(u, v);
        if (max_node >= adjList.size()) {
            adjList.resize(max_node + 1); 
        }

        adjList[u].push_back(v); 
        adjList[v].push_back(u); 
    }

    return adjList;
}