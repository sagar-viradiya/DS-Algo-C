#include <iostream>
#include <vector>

using namespace std;

/*
    Given an array with n objects colored red, white or blue, 
    sort them in-place so that objects of the same color are adjacent, 
    with the colors in the order red, white and blue.

    Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

    Note: You are not suppose to use the library's sort function for this problem.

    Example:

    Input: [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

    Follow up:
    
        - A rather straight forward solution is a two-pass algorithm using counting sort.
          First, iterate the array counting number of 0's, 1's, and 2's, 
          then overwrite array with total number of 0's, then 1's and followed by 2's.
        - Could you come up with a one-pass algorithm using only constant space?
*/
int main(int argc, char const *argv[]) {
    vector<int> nums{2,0,2,1,1,0};
    int low, mid = 0;
    int high = nums.size() - 1;

    while(mid <= high) {
        if (nums[mid] == 2) {
            int temp = nums[high];
            nums[high] = nums[mid];
            nums[mid] = temp;
            high--;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            int temp = nums[mid];
            nums[mid] = nums[low];
            nums[low] = temp;
            mid++;
            low++;
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
}
