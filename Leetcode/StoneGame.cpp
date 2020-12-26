// Leetcode Oct challenge week 4 problem 4

#include<iostream>
#include<vector>

using namespace std;

int n = 2;

int main(int argc, char const *argv[]) {
    bool dp[n+1];
    fill_n(dp, n+1, false);
    for(int i = 1; i < n + 1; i++) {
        for(int k = 1; k * k <= i; k++) {
            if (!dp[i - (k * k)]) {
                dp[i] = true;
                break;
            }
        }
    }
    cout << dp[n] << endl;
}
