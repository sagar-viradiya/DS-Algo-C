#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

using namespace std;

// Inputs 
vector<int> nums {1, 1, 2, 2, 2, 3, 3, 3, 3, 3};
int k = 2;

unordered_map<int, int> freq;
auto compare = [](int a, int b) { return freq[a] < freq[b]; };

int main(int argc, char const *argv[]) {
    
    // PQ with custom comparator for frequency comparison.
    priority_queue<int, vector<int>, decltype(compare)> pq(compare);

    // Calculate the frequency of each number.
    for (int num : nums) {
        if (freq.find(num) == freq.end()) {
            freq[num] = 0;
        }
        freq[num]++;
    }

    // Construct priority queue of number based on frequency calculated above.
    for (unordered_map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
        pq.push(it->first);
        
    }
    
    // Pop K elements from PQ which will return number having highest frequency for each pop.
    for (int i = k - 1; i >= 0; --i) {
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}
