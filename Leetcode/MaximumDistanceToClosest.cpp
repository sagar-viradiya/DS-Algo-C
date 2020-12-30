// Leetcode Oct challenge Week 5 Day 1

#include<iostream>
#include<vector>

using namespace std;

vector<int> seats {1, 0, 0, 0, 1, 0, 1};

int main(int argc, char const *argv[]) {
    vector<int> occupiedIndex;

    // Record all indicies of occupied seat to calculate distance later.
    for(int i = 0; i < seats.size(); i++) {
        if (seats[i]) {
            occupiedIndex.push_back(i);
        }
    }

    int maxDist = 0;

    // Keep track of max distance that can be achieved between occupied seats.
    for(int i = 0; i < occupiedIndex.size() - 1; i++) {
        maxDist = max(maxDist, (occupiedIndex[i + 1] - occupiedIndex[i]) / 2);
    }

    // If first seat is not occupied then check distance between first seat and next occupied seat.
    if (!seats[0]) {
        maxDist = max(maxDist, occupiedIndex[0]);
    }

    // If last seat is not occupied then check the distance between last seat and previous occupied seat.
    if (!seats[seats.size() - 1]) {
        maxDist = max(maxDist, (int)((seats.size() - 1) - occupiedIndex[occupiedIndex.size() - 1]));
    }
    cout << maxDist << endl;
    return 0;
}
