#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
	int x;
	int y;
	int *dis;
};
int main()
{
	int n; cin >> n;
	int *x = new int[n];
	int *y = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	Node *node = new Node[n*n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			node[i*n + j].x = x[i];
			node[i*n + j].y = y[j];
			node[i*n + j].dis = new int[n];
			for (int k = 0; k < n; k++) {
				node[i*n + j].dis[k] = abs(node[i*n + j].x - x[k]) + abs(node[i*n + j].y - y[k]);
			}
			sort(node[i*n + j].dis, node[i*n + j].dis + n);
			for (int k = 1; k < n; k++) {
				node[i*n + j].dis[k] += node[i*n + j].dis[k - 1];
			}
		}
	}
	delete[] x;
	delete[] y;
	cout << 0;
	for (int i = 1; i < n; i++) {
		int minDis = node[0].dis[i];
		for (int j = 1; j < n*n; j++) {
			minDis = min(minDis, node[j].dis[i]);
		}
		cout << " " << minDis;
	}
	return 0;
}