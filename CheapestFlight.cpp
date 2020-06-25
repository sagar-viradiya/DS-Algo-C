#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

vector<vector<int>> flights {{0,1,100}, {1,2,100}, {0,2,500}};
int src = 0, dst = 2, K = 0;
map<pair<int, int>, int> cachedDistance;

unordered_map<int, vector<pair<int, int>>> constructGraph(
    vector<vector<int>> flights
) {
    unordered_map<int, vector<pair<int, int>>> graph;
    for(vector<int> flight : flights) {
        if (graph.find(flight[0]) == graph.end()) {
            graph[flight[0]] = vector<pair<int, int>>{pair<int, int>(flight[1], flight[2])};
            continue;
        }
        graph[flight[0]].push_back(pair<int, int>(flight[1], flight[2]));
    }
    return graph;
}

int dfs(unordered_map<int, vector<pair<int, int>>> graph, int currentStop, int stops) {
    if(currentStop == dst) return 0;
    if (stops < 0) return INT_MAX;
    if (cachedDistance.find(pair<int, int>(currentStop, stops)) != cachedDistance.end()) {
        return cachedDistance[pair<int, int>(currentStop, stops)];
    }
    int minDistance = INT_MAX;
    int currentDistance = INT_MAX;
    for(pair<int, int> flight : graph[currentStop]) {
        currentDistance = dfs(graph, flight.first, stops - 1);
        if (currentDistance != INT_MAX)
        {
            currentDistance += flight.second;
        }
        
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
        }
    }
    cachedDistance[pair<int, int>(currentStop, stops)] = minDistance;
    return minDistance;
}

int main(int argc, char const *argv[]) {
    unordered_map<int, vector<pair<int, int>>> graph = constructGraph(flights);
    int ans = dfs(graph, src, K);
    cout << ans << endl;
    return 0;
}

