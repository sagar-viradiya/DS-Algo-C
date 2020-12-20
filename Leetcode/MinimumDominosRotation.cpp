// Leetcode Oct challenge week 3 day 5

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> A {3,1,3,1,3};
vector<int> B {1,3,1,3,1};

int main(int argc, char const *argv[]) {
    unordered_map<int, int> digitFrq;

    for(int i = 0; i < A.size(); i++) {
        if (digitFrq.find(A[i]) == digitFrq.end()) {
            digitFrq[A[i]] = 0;
        }
        digitFrq[A[i]] += 1;
        if (B[i] != A[i]) {
            if (digitFrq.find(B[i]) == digitFrq.end()) {
                digitFrq[B[i]] = 0;
            }
            digitFrq[B[i]] += 1;
        }
    }

    pair<int, int> maxPair;
    maxPair.first = -1;
    maxPair.second = -1;
    for(auto entry : digitFrq) {
        if (entry.second >= maxPair.second) {
            maxPair.first = entry.first;
            maxPair.second = entry.second;
        }
    }

    if (maxPair.second < A.size()) {
        cout << -1 << endl;
        return 0;
    }


    int rotateA = 0, rotateB = 0;
    for(int i = 0; i < A.size(); i++) {
        if (A[i] != maxPair.first) {
            rotateA++;
        }

        if (B[i] != maxPair.first) {
            rotateB++;
        }
    }
    
    cout << min(rotateA, rotateB) << endl;

    return 0;
}
