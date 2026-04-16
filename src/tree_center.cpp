#include "../include/tree_center.h"
#include <iostream>
#include <vector>
#include <queue>

std::vector<int> bfs_distance(std::vector<std::vector<int>> graph, int start_top) {
    int num_of_tops = graph.size();
    std::vector<int> distances(num_of_tops, -1);

    std::queue<int> q;

    distances[start_top] = 0;

    q.push(start_top);

    while(!q.empty()) {
        int actual = q.front();
        q.pop();
        
        for (int neighbor : graph[actual]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[actual] + 1;
                q.push(neighbor);
            }
        }
    }

    return distances;
}

int get_farthest_node(std::vector<int> distances) {
    int farthert_distance = -1;
    for (int i = 0; i < distances.size(); i++) {
        if (distances[i] > farthert_distance) {
            farthert_distance = i;
        }
    }

    return farthert_distance;
}