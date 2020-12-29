// Leetcode Oct challenge Week 4 Day 7

#include<iostream>
#include<vector>

using namespace std;

vector<int> nums {0,2,3,4,6,8,9};

int main(int argc, char const *argv[]) {

    vector<string> ans;

    int ptr1, ptr2;
    ptr1 = ptr2 = 0;

    if (nums.size() == 1) {
        ans.push_back(to_string(nums[0]));   
    } else if (!nums.empty()) {
        while(ptr2 < nums.size()) {
            if (ptr2 == nums.size() - 1 || nums[ptr2] != nums[ptr2 + 1] - 1) {
                if (ptr1 == ptr2) {
                    ans.push_back(to_string(nums[ptr1]));
                } else {
                    ans.push_back(to_string(nums[ptr1]) + "->"  + to_string(nums[ptr2]));
                }
                ptr1 = ptr2 + 1;
            }
            ptr2++;
        }
    }

    for(string rang : ans) {
        cout << rang << "\t";
    }

    cout << endl;
    return 0;
}
