// Kickstart 2020 Round D Problem 1
#include<iostream>
#include<vector>

using namespace std;

void solve(int t) {
    int n;
    cin >> n;

    int visitors[n];
    cin >> visitors[0];

    if(n == 1) {
        cout << "Case #" << t << ": " << 1 << endl;
        return;
    }

    int maxVisitors = visitors[0];
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> visitors[i + 1];
        
        if (!i && visitors[i] > visitors[i + 1]) {
            ans++;
            continue;
        }

        if (maxVisitors < visitors[i] && visitors[i] > visitors[i + 1]) {
            ans++;
            maxVisitors = visitors[i];
        }
    }
    
    if (maxVisitors < visitors[n - 1]) {
        ans++;
    }
    
    cout << "Case #" << t << ": " << ans << endl;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    
    return 0;
}
