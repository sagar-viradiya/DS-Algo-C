// Leetcode October challenge week 3 day 6

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> asteroids {-2,-1,1,2};

int main(int argc, char const *argv[]) {

    stack<int> asteroidStack;
    bool shouldPush;
    for(int asteroid : asteroids) {
        shouldPush = true;
        while (!asteroidStack.empty() && asteroid < 0 && asteroidStack.top() > 0) {
            if (-asteroid == asteroidStack.top()) {
                shouldPush = false;
                asteroidStack.pop();
                break;
            } else if (-asteroid > asteroidStack.top()) {
                shouldPush = true;
                asteroidStack.pop();
            } else {
                shouldPush = false;
                break;
            }
        }
        if(shouldPush) {
            asteroidStack.push(asteroid);
        }
    }

    int survivals[asteroidStack.size()];

    for (int i = asteroidStack.size() - 1 ; i >= 0; i--) {
        survivals[i] = asteroidStack.top();
        asteroidStack.pop();
    }

    for(int s : survivals) {
        cout << s << "\t";
    }
    cout << endl;

    return 0;
}
