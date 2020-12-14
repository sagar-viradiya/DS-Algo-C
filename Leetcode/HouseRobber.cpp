// Leetcode Oct challenge Week 2 day 7

#include<iostream>
#include<vector>

using namespace std;

vector<int> nums {1, 2, 3, 1};

int main(int argc, char const *argv[]) {
    vector<int> rob1;
    vector<int> rob2;

    rob1.push_back(0);
    rob2.push_back(0);

    // Check house 0 to n-1
    for(int i = 0; i < nums.size() - 1; i++) {
        if (i == 0) {
            rob1.push_back(nums[i]);
            continue;
        }
        rob1.push_back(max(rob1[i], nums[i] + rob1[i - 1]));
    }

    // Check house 1 to n
    for (int i = 1; i < nums.size(); i++) {
        if (i == 1) {
            rob2.push_back(nums[i]);
            continue;
        }
        rob2.push_back(max(rob2[i - 1], nums[i] + rob2[i - 2])); 
    }
    
    // Take max of house 0 to n-1 robbery and house 1 to n robbery
    cout << max(rob1[nums.size() - 1], rob2[nums.size()- 1]) << endl;
    return 0;
}

