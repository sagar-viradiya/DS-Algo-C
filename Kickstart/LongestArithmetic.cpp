// Kickstart 2020 Round E Problem 1

#include<iostream>
#define ll long long

using namespace std;

void solve(int t) {
    int n;
    cin >> n;

    ll nums[n];
    cin >> nums[0];
    cin >> nums[1];

    ll diff = nums[0] - nums[1];
    int maxLength = 2;
    int tempLength = maxLength;

    for (int i = 2; i < n; i++) {
        cin >> nums[i];
        if (nums[i - 1] - nums[i] == diff) {
            tempLength++;
        } else {
            diff = nums[i - 1] - nums[i]; 
            maxLength = max(maxLength, tempLength);
            tempLength = 2;
        }
    }

    maxLength = max(maxLength, tempLength);
    cout << "Case #" << t + 1 << ": " << maxLength << endl;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i);
    }
    return 0;
}
