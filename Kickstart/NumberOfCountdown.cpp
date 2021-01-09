// Kickstart 2020 Round C Problem 1

#include<iostream>

using namespace std;

void solve(int t) {
    int ans = 0;
    int n, k;
    cin >> n >> k;
    int current;
    cin >> current;
    int prev = current;
    int counter = 0;
    for (int i = 1; i < n; i++) {
        cin >> current;
        if (prev == current + 1) {
            counter++;
        } else {
            counter = 0;
        }
        if (current == 1 && counter >= k - 1) {
            ans++;
        }
        prev = current;
    }
    
    cout << "Case #" << t << ": " << ans << endl;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i+1);
    }
    return 0;
}
