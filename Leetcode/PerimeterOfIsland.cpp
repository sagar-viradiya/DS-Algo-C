// Leetcode July challenge week 1, Day 7.

#include<iostream>
#include<vector>

using namespace std;

int perimeter;
vector<pair<int, int>> directions {pair(-1, 0), pair(1, 0), pair(0, -1), pair(0, 1)};
vector<vector<int>> grid {{0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}};

void updateParimeter(int i, int j) {
    int newI, newJ;

    if (grid[i][j] == 0) return;

    for(pair<int, int> direction : directions) {
        newI = i + direction.first;
        newJ = j + direction.second;
        if (newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size()) {
            if (grid[newI][newJ] == 0) {
                perimeter++;
            }
        } else {
            perimeter++;
        }
    }
}

int main(int argc, char const *argv[]) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            updateParimeter(i, j);
        }
    }
    cout<< perimeter << endl;
    return 0;
}
