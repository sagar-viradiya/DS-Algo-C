// Kickstart 2020 Round H Problem 1

#include<iostream>
#define ll long long

using namespace std;

void minTimeToFinish(int t) {
    ll n, k, s;

    cin >> n >> k >> s;
    
    if((k - s) * 2 > k) {
        cout << "Case #" << t << ": " << n + k << endl;
    } else {
        cout << "Case #" << t << ": " << (2* k) - (2*s) + n << endl;
    }
}

int main(int argc, char const *argv[]) {

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        minTimeToFinish(i);
    }
    
    return 0;
}
