// Kickstart 2020 Round B Problem 1

#include<iostream>
#include<vector>

using namespace std;

void solve(int t) {
    int n;
    cin >> n;
    int previous;
    cin >> previous;
    int current, next, ans = 0;
    cin >> current;
    for (int i = 1; i < n - 1; i++) {
        cin >> next;
        if (current > previous && current > next) {
            ans++;
        }
        previous = current;
        current = next;
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
