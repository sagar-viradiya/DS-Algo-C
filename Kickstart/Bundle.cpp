// Kickstart 2020 Round A Problem 4

#include <iostream>
#include <unordered_map>
typedef long long ll;

using namespace std;

ll n, k;

struct Node {

	public:
		ll freq = 0;
		unordered_map<char, Node*> charMap;
};

class Trie {

	public: Node* rootPtr = new Node;

	public: void insert(string word) {
		Node* temp = rootPtr;
		for (int i = 0; i < word.size(); i++) {
			if (temp->charMap.find(word[i]) == temp->charMap.end()) {
				temp->charMap[word[i]] = new Node;
			}
			temp = temp->charMap[word[i]];
			temp->freq++;
		}
	}
};

ll dfs(Node* root) {
	if (root == nullptr) {
		return 0;
	}

	ll ans = root->freq / k;
	for (pair<char, Node*> entry : root->charMap) {
		ans += dfs(entry.second);
	}
	
	return ans;
}

void solve(int t) {
	cin >> n >> k;
	Trie trie;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		trie.insert(word);
	}
	cout << "Case #" << t << ": " << dfs(trie.rootPtr) << endl;
}
	

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		solve(i+1);
	}
	
	return 0;
}