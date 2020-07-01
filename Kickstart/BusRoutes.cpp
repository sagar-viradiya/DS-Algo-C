// Kickstart 2020 Round B, Problem 2

#include <iostream>
typedef long long ll;

using namespace std;

int n;
ll d;

bool canFinish(ll afterDays, ll routes[]) {
    ll days = afterDays;
    for (int i = 1; i < n; i++) {
        days = ((days + routes[i] - 1) / routes[i]) * routes[i];
        if (days > d) {
            return false;
        }  
    }
    return true;
}

void solve(int t) {
    cin >> n >> d;
    ll routes[n];

    for (int i = 0; i < n; i++) {
        cin >> routes[i];
    }
    
    ll low = 1;
    ll high = d/routes[0];
    ll mid;
    while (low < high) {
        mid = (low + high + 1) / 2;
        if (canFinish(mid * routes[0], routes)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << "Case #" << t << ": " << low * routes[0] << endl;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i+1);
    }
    return 0;
}

