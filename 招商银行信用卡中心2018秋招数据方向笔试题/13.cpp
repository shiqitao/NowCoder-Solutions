#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
int main()
{
	int m, n; cin >> m >> n;
	bool adj[26][26] = { 0 };
	unordered_set<char> mySet;
	for (int i = 0; i < m; i++) {
		char ch[3];
		cin >> ch[0] >> ch[1] >> ch[2];
		mySet.insert(ch[0]);
		mySet.insert(ch[1]);
		adj[ch[0] - 'A'][ch[1] - 'A'] = true;
		if (ch[2] != '*') {
			adj[ch[0] - 'A'][ch[2] - 'A'] = true;
			mySet.insert(ch[2]);
		}
	}
	if (n == 0) {
		int count = 0;
		for (unordered_set<char>::iterator it = mySet.begin(); it != mySet.end(); it++) {
			cout << *it << " ";
			count++;
		}
		if (count == 0) {
			cout << "None";
		}
		return 0;
	}
	int result[26] = { 0 };
	for (int i = 0; i < 26; i++) {
		bool reach[26] = { 0 };
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int start = q.front();
			q.pop();
			for (int j = 0; j < 26; j++) {
				if (adj[start][j] && !reach[j]) {
					result[i]++;
					reach[j] = true;
					q.push(j);
				}
			}
		}
	}
	int count = 0;
	for (int i = 0; i < 26; i++) {
		if (result[i] >= n) {
			cout << char('A' + i) << " ";
			count++;
		}
	}
	if (count == 0) {
		cout << "None";
	}
	return 0;
}