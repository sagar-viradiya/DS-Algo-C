// Leetcode Oct challenge Week 2 Day 4
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> points {{10, 16}, {10, 16}};

bool compareInterval(vector<int> interval1, vector<int> interval2) {
    return interval1[1] < interval2[1];
}

int main(int argc, char const *argv[]) {
    int numberOfBalloons = 1;
    sort(points.begin(), points.end(), compareInterval);
    int point = points[0][1];
    for(int i = 1; i < points.size(); i++) {
        if (point >= points[i][0]) {
            continue;
        }
        numberOfBalloons++;
        point = points[i][1];
    }
    cout << numberOfBalloons << endl;
    return 0;
}
