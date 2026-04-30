#include "../include/tree_center.h"
#include <iostream>
#include <vector>
#include <queue>

BFSResult bfs_distance(std::vector<std::vector<int>> graph, int start_top) {
    int num_of_tops = graph.size();

    //-1 means ,,not visited yet''
    std::vector<int> distances(num_of_tops, -1);

    //where did we come from to reach this node
    std::vector<int> parents(num_of_tops, -1);

    std::queue<int> q;

    //start node is 0
    distances[start_top] = 0;

    q.push(start_top);

    while(!q.empty()) {
        int actual = q.front();
        q.pop();
        
        for (int neighbor : graph[actual]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[actual] + 1;
                parents[neighbor] = actual;
                q.push(neighbor);
            }
        }
    }

    return {distances, parents};
}

// Function that returns the ID of the node that is the furthest away.
int get_farthest_node(std::vector<int> distances) {
    int max_distance = -1;    
    int farthest_node = -1;   

    for (int i = 0; i < distances.size(); i++) {
        if (distances[i] > max_distance) {
            max_distance = distances[i]; 
            farthest_node = i;        
        }
    }

    return farthest_node; 
}