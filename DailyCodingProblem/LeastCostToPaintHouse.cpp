/*
    A builder is looking to build a row of N houses that can be of K different colors. He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.

    Given an N by K matrix where the nth row and kth column represents the cost to build the nth house with kth color, return the minimum cost which achieves this goal.
*/

#include<iostream>
#include<vector>

using namespace std;

// DP, Time complexity O(NK), Constant space complexity
int minCost(vector<vector<int>> costs) {
    if (costs.size() == 0) {
        return 0; 
    }
    
    int min1 = 0;
    int min2 = 0;
    int prevMinIndex = 0;
    int tempMin1;
    int tempMin2;
    int tempPrevMinIndex;
    int cost;
    for (int i = 0; i < costs.size(); i++) {
        tempMin1 = INT16_MAX;
        tempMin2 = INT16_MAX;
        tempPrevMinIndex = -1;
        for (int j = 0; j < costs[i].size(); j++) {            
            cost = costs[i][j] + (j == prevMinIndex ? min2 : min1);
            if (tempMin1 > cost) {
                tempMin2 = tempMin1;
                tempMin1 = cost;
                tempPrevMinIndex = j;
            } else if (tempMin2 > cost) {
                tempMin2 = cost;
            }
        }
        min1 = tempMin1;
        min2 = tempMin2;
        prevMinIndex = tempPrevMinIndex;
    }
    return min1;
}

int main(int argc, char const *argv[]) {
    cout << minCost(vector<vector<int>> {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}) << endl;
    return 0;
}
