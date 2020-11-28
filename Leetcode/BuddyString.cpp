// Leetcode Oct challenge week 2 day 6

#include<iostream>
#include<set>

using namespace std;

string A = "abab";
string B = "aabb";

int main(int argc, char const *argv[]) {
    if (A.length() != B.length()) {
        cout << false << endl;
        return 0;
    }

    set<char> chars(A.begin(), A.end());

    if (A == B && chars.size() < A.length()) {
        cout << true << endl;
        return 0;
    }

    string newA, newB;
    for (int i = 0; i < A.length(); i++) {
        if (A.at(i) != B.at(i)) {
            newA += A.at(i);
            newB += B.at(i);
        }
    }

    if (newA.length() == 2 && newA.at(0) == newB.at(1) && newA.at(1) == newB.at(0)) {
        cout << true << endl;
        return 0;
    }
    
    cout << false << endl;
    return 0;
}
