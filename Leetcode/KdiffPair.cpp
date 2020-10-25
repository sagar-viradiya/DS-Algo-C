#include<iostream>
#include<vector>
#include<map>

using namespace std;

// inputs
vector<int> nums {1,2,3,4,5};
int k = 1;

int main(int argc, char const *argv[])
{
    int numOfPairs = 0;
    map<int, int> numFreq;

    // Count num frequency
    for(int num : nums) {
        if(numFreq.find(num) == numFreq.end()) {
            numFreq[num] = 0;
        }
        numFreq[num] += 1;
    }
    int key, val;

    // If k = 0 and if frequency of key is > 1 then increment numOfPairs
    // If k > 0 and if k + key exist in the map then increment numOfPairs
    for(map<int, int>::iterator itr = numFreq.begin(); itr != numFreq.end(); itr++) {
        key = itr->first;
        val = itr-> second;
        if(k > 0 && numFreq.find(key + k) != numFreq.end()) {
            numOfPairs++;
        } else if (k == 0 && val > 1) {
            numOfPairs++;
        }
    }
    cout << numOfPairs << endl;
    return 0;
}