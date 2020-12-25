// Leetcode Oct challenge week 4 day 2

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> nums {1,2,3,4};

int main(int argc, char const *argv[]) {
    if (nums.size() < 3) {
        cout << false << endl;
        return 0;
    }

    vector<int> mins;
    mins.push_back(nums[0]);

   for(int i = 1; i < nums.size(); i++) {
       mins.push_back(min(nums[i], mins[i - 1]));
   }

    stack<int> numsK;

    for (int j = nums.size() - 1; j >= 0;  j--) {
        if(mins[j] < nums[j]) {
            while (!numsK.empty() && numsK.top() <= mins[j]) {
                numsK.pop();
            }
            if (!numsK.empty() && nums[j] > numsK.top()) {
                cout << true << endl;
                return 0;
            }
            numsK.push(nums[j]);
        }
    }
    cout << false << endl;
    return 0;
}
