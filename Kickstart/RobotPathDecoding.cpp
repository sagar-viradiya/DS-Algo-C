// Kickstart 2020 Round B Problem #3

#include<iostream>
#include<stack>
#include<unordered_map>
typedef long long ll;

using namespace std;

string program;
unordered_map<int, int> closingIndex;
ll limit = 1e9;

void moveRobot(char direction, pair<ll, ll>& subPosition) {
    switch (direction) {
        case 'N':
            subPosition.second = (subPosition.second + limit - 1) % limit;
            break;
        case 'E':
            subPosition.first = (subPosition.first + limit + 1) % limit;
            break;
        case 'W':
            subPosition.first = (subPosition.first + limit - 1) % limit;
            break;
        case 'S':
            subPosition.second = (subPosition.second + limit + 1) % limit;
            break;
    }
}

pair<ll, ll> executeProgram(int low, int high) {
    pair<ll, ll> subProgram = pair(0, 0);
    for (int i = low; i < high; i++) {
        if (program[i] >= '2' && program[i] <= '9') {
            int times = program[i] - '0';
            pair<ll, ll> temp = executeProgram(i + 2, closingIndex[i + 1]);
            i = closingIndex[i + 1];
            subProgram.first = (subProgram.first + (times * temp.first)) % limit;
            subProgram.second = (subProgram.second + (times * temp.second)) % limit;
        } else {
            moveRobot(program[i], subProgram);
        }
    }
    return subProgram;
}

void solve(int t) {
    cin >> program;
    stack<int> openingIndex = stack<int>();
    closingIndex.clear();
    for (int i = 0; i < program.size(); i++) {
        if (program[i] == '(') {
            openingIndex.push(i);
        } else if (program[i] == ')') {
            closingIndex[openingIndex.top()] = i;
            openingIndex.pop();
        }
    }
    pair<ll, ll> ans = executeProgram(0, program.size());
    cout << "Case #" << t << ": " << ans.first + 1 << " " << ans.second + 1 << endl;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }
    return 0;
}
