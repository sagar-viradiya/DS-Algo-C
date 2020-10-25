#include<iostream>
#include<vector>
using namespace std;

// Input
vector<vector<int>> intervals {{3, 10}, {4, 10}, {5, 11}};

/* Sort intervals by start point and if start point is same then put one having      larger endpoint first */
bool compareInterval(vector<int> interval1, vector<int> interval2) {
    if(interval1[0] == interval2[0]) {
        return interval1[1] > interval2[1];
    } else {
        return interval1[0] < interval2[0];
    }
}

int main(int argc, char const *argv[])
{
    int numOfIntervals = 1;
    sort(intervals.begin(), intervals.end(), compareInterval);

    int prevEnd = intervals[0][1];

    for(int i = 1; i < intervals.size(); i++) {
        /* If endpoint of prev interval is less than current interval they are not overlapping */
        if(prevEnd < intervals[i][1]) {
            numOfIntervals++;
            prevEnd = intervals[i][1];
        }
    }
    cout << numOfIntervals << endl;
    return 0;
}
