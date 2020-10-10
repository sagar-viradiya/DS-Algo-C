// Leetcode 624 Maximum distance in arrays

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> arrays {{1,4}, {0, 5}};

int main(int argc, char const *argv[])
{
    int maxVal = arrays[0][arrays[0].size() - 1];
    int minVal = arrays[0][0];
    int distance = INT_MIN;

    for (int i = 1;i<arrays.size(); i++) {
        distance = max(distance, max(maxVal - arrays[i][0], arrays[i][arrays[i].size() - 1] - minVal));
        maxVal = max(maxVal, arrays[i][arrays[i].size() - 1]);
        minVal = min(minVal, arrays[i][0]);
    }
    cout << distance << endl; 
    return 0;
}
