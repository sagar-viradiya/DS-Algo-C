// Leetcode Oct challenge week 4 day 3

#include<iostream>
#include<vector>

using namespace std;

vector<int> tokens {100};
int power = 500;

int main(int argc, char const *argv[]) {
    int score = 0;
    sort(tokens.begin(), tokens.end());
    if (tokens.size() == 0 || tokens[0] > power) {
        cout << score << endl;
        return 0;
    }

    int pointer1 = 0;
    int pointer2 = tokens.size() - 1;

    while(pointer1 <= pointer2) {
        if (score == 0) {
            power -= tokens[pointer1++];
            score++;
            continue;
        }
        if (power < tokens[pointer1]) {
            if (pointer1 == pointer2) {
                break;
            }
            power += tokens[pointer2--];
            score--;
        } else {
            power -= tokens[pointer1++];
            score++;
        }
    }

    cout << score << endl;
    return 0;
}
