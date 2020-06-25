#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> dungeon;
int rows, cols;
vector<vector<int>> dp;

int getMinHealth(int currentCell, int nextRow, int nextCol) {
    if (nextRow >= rows || nextCol >= cols) {
        return INT_MAX;
    }

    int nextCell = dp[nextRow][nextCol];

    return max(1, nextCell - currentCell);
}

int main(int argc, char const *argv[])
{
    dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    rows = dungeon.size();
    cols = dungeon[0].size();

    dp = vector(rows, vector<int>(cols, INT_MAX));

    int minHealth = 0;
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            minHealth = min(getMinHealth(dungeon[i][j], i, j + 1), 
            getMinHealth(dungeon[i][j], i + 1, j));
            if (minHealth == INT_MAX) {
                minHealth = dungeon[i][j] >= 0 ? 1 : 1 - dungeon[i][j];
            }
            dp[i][j] = minHealth;
        }
        
    }
    cout << dp[0][0] << endl;
    return 0;
}

