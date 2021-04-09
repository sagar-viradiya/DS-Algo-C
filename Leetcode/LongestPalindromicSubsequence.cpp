// Longest palindromic subsequence

#include<iostream>
#include<vector>

using namespace std;

string s = "cdabbad";

// Dynamic programming approach O(n^2)
int main(int argc, char const *argv[]) {
    vector<vector<bool>> dp = vector<vector<bool>>(
        s.length(), vector<bool>(s.length(), false)
    );

    int start = 0;
    int end = 0;

    // Mark all individual characters as palindrom
    for(int i = 0; i < s.length(); i++) {
        dp[i][i] = true;
    }

    // Mark all palendrom string of length 2
    for(int i = 0; i < s.length() - 1; i++) {
        if(s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            end = i + 1;
        } 
    }

    // DP approach
    for(int i = s.length() - 3; i >= 0; i--) {
        for(int j = i + 2; j < s.length(); j++) {
            if (s[i] == s[j] && dp[i + 1][j - 1]){
                dp[i][j] = true;
                if(j - i > end - start) {
                    start = i;
                    end = j;
                }
            } 
        }
    }

    // Start and end would point to longest palindromic substring in the input string
    cout << s.substr(start, end - start + 1) << endl;
    return 0;
}
