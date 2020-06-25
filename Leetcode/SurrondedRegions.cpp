#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> directions {pair(0, -1), pair(-1, 0), pair(1, 0), pair(0, 1)};

void dfs(vector<vector<char>>& board, int x, int y) {
    board[x][y] = 'E';
    int newX, newY;
    for(int i = 0; i < directions.size(); i++) {
        newX = x + directions[i].first;
        newY = y + directions[i].second;
        if (newX > -1 && 
            newX < board[0].size() && 
            newY > -1 && 
            newY < board.size() &&
            board[newX][newY] == 'O'
        ) {
            dfs(board, newX, newY);
        }
    }
}

int main(int argc, char const *argv[]) {

    vector<vector<char>> board {{'X', 'X', 'X', 'X'}, 
                                {'X', 'O', 'O', 'X'}, 
                                {'X', 'X', 'O', 'X'}, 
                                {'X', 'O', 'X', 'X'}};

    if (board.size() == 0) {
        return 0;
    }

    for (int i = 0; i < board[0].size(); i++) {
        if (board[0][i] == 'O') {
            dfs(board, 0, i);
        }
        if (board[board.size() - 1][i] == 'O') {
            dfs(board, board.size() - 1, i);
        }
    }

    for (int i = 0; i < board.size(); i++) {
        if (board[i][0] == 'O') {
            dfs(board, i, 0);
        }
        if (board[i][board[0].size() - 1] == 'O') {
            dfs(board, i, board[0].size() - 1);
        }
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == 'E') {
                board[i][j] = 'O';
            }
        }
    }
    
    return 0;
}

