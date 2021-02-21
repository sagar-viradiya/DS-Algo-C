/*
    This problem was asked by Google.

    Given a set of closed intervals, find the smallest set of numbers that covers all the intervals. If there are multiple smallest sets, return any of them.

    For example, given the intervals [0, 3], [2, 6], [3, 4], [6, 9], one set of numbers that covers all these intervals is {3, 6}.
*/

#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

// Driver function to sort the vector elements by second element of pairs 
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) { 
    return (a.second < b.second); 
}

unordered_set<int> smallestSet(vector<pair<int, int>> intervals) {
    // Sort the intervals by second element of a interval in ascending order
    sort(intervals.begin(), intervals.end(), sortbysec);
    unordered_set<int> numbers;
    int lastMax;

    /* Greedy approach where we take last number of the sorted interval and ignore all intervals having last number */
    for(int i = 0; i < intervals.size(); i++) {
        if(numbers.empty()) {
            numbers.insert(intervals[i].second);
            lastMax = intervals[i].second;
            continue;
        }
        if (intervals[i].first <= lastMax) {
            continue;
        } else {
            numbers.insert(intervals[i].second);
            lastMax = intervals[i].second;
        }
    }
    return numbers;
} 


int main(int argc, char const *argv[]) {
    unordered_set<int> numbers = smallestSet(
        vector<pair<int, int>> { 
            pair(1, 2), pair(0, 4), pair(5, 7), pair(6, 7), pair(8, 10), pair(6, 9)
        }
    );
    for(int num : numbers) {
        cout << num << "\t";
    }
    cout << endl;
    return 0;
}
