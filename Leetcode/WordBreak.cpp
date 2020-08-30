// Leetcode July challenge Week 5 Day 2

#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

string s = "catsanddog";
vector<string> wordDic {"cat", "cats", "and", "sand", "dog"};
set<string> wordSet;

// DP top down approach
vector<string> getSetences(string postFix, unordered_map<string, vector<string>>& memo) {
    if (memo.find(postFix) != memo.end()) return memo[postFix];
    vector<string> sentences;
    for (int i = 1; i <= postFix.length(); i++) {
        string prefix = postFix.substr(0, i);
        if (wordSet.find(prefix) != wordSet.end()) {  
            if (i != postFix.length()) {
                for(string sentence : getSetences(postFix.substr(i), memo)) {
                    sentences.push_back(prefix + " " + sentence);
                }
            } else {
                sentences.push_back(prefix);
            }
        }
    }
    memo[postFix] = sentences;
    return memo[postFix];
}

int main(int argc, char const *argv[]) {
    for(string word : wordDic) {
        wordSet.insert(word);
    }
    unordered_map<string, vector<string>> memo;
    for(string sentence : getSetences(s, memo)) {
        cout << sentence << endl;
    }
    return 0;
}
