// Leetcode July challenge week 3, Problem 7.

#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> directions {pair(1, 0), pair(0, 1), pair(-1, 0), pair(0, -1)};
vector<vector<char>> board {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
string word = "SEE";
int ROW = board.size();
int COL = board[0].size();

bool search(int index, int row, int col) {
    if (index >= word.size()) return true;
    if (row >= ROW || row < 0 || col >= COL || col < 0 || board[row][col] != word[index]) {
        return false;
    }
    board[row][col] = '#';
    for (pair<int, int> direction : directions) {
        if (search(index + 1, row + direction.first, col + direction.second)) {
            return true;
        }
    }
    board[row][col] = word[index];
    return false;
}

int main(int argc, char const *argv[]) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (search(0, i ,j)) {
                cout << true << endl;
                return 0;
            }
        }
    }
    cout << false << endl;
    return 0;
}
