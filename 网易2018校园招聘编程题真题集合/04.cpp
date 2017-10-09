#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int height(bool adj[], int node);
int main()
{
	int l; cin >> n >> l;
	bool *adj = new bool[n*n];
	memset(adj, false, sizeof(bool)*n*n);
	int temp;
	for (int i = 1; i < n; i++) {
		cin >> temp;
		adj[temp*n + i] = true;
	}
	int h = height(adj, 0);
	cout << min(min(l + 1, (l + 1 - h) / 2 + h), n);
	return 0;
}
int height(bool adj[], int node)
{
	int maxLen = 0;
	for (int i = 0; i < n; i++) {
		if (adj[node*n + i]) {
			int temp = height(adj, i);
			maxLen = max(maxLen, temp);
		}
	}
	return maxLen + 1;
}