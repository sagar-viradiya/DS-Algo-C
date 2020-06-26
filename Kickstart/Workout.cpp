// Kickstart 2020 Round A Problem 3

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<int> sessions;
int n, k;

void solve(int t) {
    cin >> n >> k;
    sessions.clear();
    sessions = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> sessions[i];
    }

    int low = 1;
    int high = sessions[n - 1] - sessions[0];
    int mid, _k;

    while (low < high) {
        _k = 0;
        mid = (low + high) / 2;
        for (int i = 1; i < sessions.size(); i++) {
            _k += ((sessions[i] - sessions[i - 1]) + mid - 1)  / mid - 1;
        }
        if (_k > k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    cout << "Case #" << t << ": " << low << endl;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
