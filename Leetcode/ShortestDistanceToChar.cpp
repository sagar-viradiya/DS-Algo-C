// Leetcode Feb challenge week 1 day 7

#include<iostream>
#include<vector>

using namespace std;

vector<int> clostestDistancesToChar(string str, char ch) {
    vector<int> occurrenceIndex;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ch) {
            occurrenceIndex.push_back(i);
        }
    }

    int pointer1 = -1;
    int pointer2 = 0;

    vector<int> closestDistances;

    for(int i = 0; i < str.length(); i++) {
        if(pointer2 < occurrenceIndex.size() && i > occurrenceIndex[pointer2]) {
            pointer1++;
            pointer2++;
        }
        if(str[i] == ch) {
            closestDistances.push_back(0);
            continue;
        }   

        if(pointer1 == -1) {
            closestDistances.push_back(abs(i - occurrenceIndex[pointer2]));
        } else if (pointer1 < (occurrenceIndex.size() - 1)) {
            closestDistances.push_back(min(abs(i - occurrenceIndex[pointer1]), abs(i - occurrenceIndex[pointer2])));
        } else {
            closestDistances.push_back(abs(i - occurrenceIndex[pointer1]));
        }
    }

    return closestDistances;
}

int main(int argc, char const *argv[]) {
    string str = "abaa";
    char ch = 'b';
    for(int distance : clostestDistancesToChar(str, ch)) {
        cout << distance << "\t";
    }
    cout << endl;
    return 0;
}
