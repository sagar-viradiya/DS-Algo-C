// Leetcode Nov Challenge Week 1 Day 4 

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

int n = 3;
vector<vector<int>> edges {{0, 1}, {0, 2}};

int main(int argc, char const *argv[]) {
    unordered_map<int, unordered_set<int>> graph;
    queue<int> nodes;

    // Construct graph
    for(vector<int> edge : edges) {
        if (graph.find(edge[0]) == graph.end()) {
            graph[edge[0]] = unordered_set<int>();
        }
        graph[edge[0]].insert(edge[1]);
        if (graph.find(edge[1]) == graph.end()) {
            graph[edge[1]] = unordered_set<int>();
        }
        graph[edge[1]].insert(edge[0]);
    }

    // Add all leaf nodes
    for(const auto &entry : graph) {
        if (entry.second.size() == 1) {
            nodes.push(entry.first);
        }
    }

    // Trim all leaf nodes until we reach centroids.
    int remainingNodes = n;
    while(remainingNodes > 2) {
        remainingNodes -= nodes.size();
        int numOfNodes = nodes.size();
        for(int i = 0; i < numOfNodes; i++) {
            int temp = nodes.front();
            nodes.pop();
            graph[*graph[temp].begin()].erase(temp);
            // Add leaf node for next iteration
            if(graph[*graph[temp].begin()].size() == 1) {
                nodes.push(*graph[temp].begin());
            }
        }
    }

    while(!nodes.empty()) {
        cout << nodes.front() << "\t";
        nodes.pop();
    }
    cout << endl;
    return 0;
}
