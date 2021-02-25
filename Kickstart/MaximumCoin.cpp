// Kickstart 2020 Round G Problem 2

#include<iostream>
#define ll long long

using namespace std;

void solve(int t) {
    int n;
    cin >> n;
    ll coinMatrix[n][n];
    ll mainDiagonalSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> coinMatrix[i][j];
            if (i == j) {
                mainDiagonalSum += coinMatrix[i][i];
            }
        }
    }

    ll diagonalMax = 0;
    ll diagonal1Max;
    ll diagonal2Max;
    for (int i = 1; i < n; i++) {
        diagonal1Max = 0;
        diagonal2Max = 0;
        for(int j = 0; j < n - i; j++) {
            diagonal1Max += coinMatrix[i + j][j];
            diagonal2Max += coinMatrix[j][i + j];
        }
        diagonalMax = max(diagonalMax, max(diagonal1Max, diagonal2Max));
    }
    
    cout << "Case #" << t << ": " << max(mainDiagonalSum, diagonalMax) << endl;
    
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        solve(i);
    }
    
    return 0;
}
