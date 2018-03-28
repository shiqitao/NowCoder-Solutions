#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstring>
using namespace std;
struct Rectangle
{
	int x1, x2, y1, y2;
};
int main()
{
	int n; cin >> n;
	Rectangle *rect = new Rectangle[n];
	int *x = new int[n * 2];
	int *y = new int[n * 2];
	for (int i = 0; i < n; i++) {
		cin >> rect[i].x1;
		x[i] = rect[i].x1;
	}
	for (int i = 0; i < n; i++) {
		cin >> rect[i].y1;
		y[i] = rect[i].y1;
	}
	for (int i = 0; i < n; i++) {
		cin >> rect[i].x2;
		x[i + n] = rect[i].x2;
	}
	for (int i = 0; i < n; i++) {
		cin >> rect[i].y2;
		y[i + n] = rect[i].y2;
	}
	sort(x, x + 2 * n);
	sort(y, y + 2 * n);
	vector<int> vectorx;
	vector<int> vectory;
	vectorx.push_back(x[0]);
	vectory.push_back(y[0]);
	for (int i = 1; i < 2 * n; i++) {
		if (x[i] != x[i - 1]) {
			vectorx.push_back(x[i]);
		}
		if (y[i] != y[i - 1]) {
			vectory.push_back(y[i]);
		}
	}
	delete[] x;
	delete[] y;
	unordered_map<int, int> myMapx;
	unordered_map<int, int> myMapy;
	for (int i = 0; i < vectorx.size(); i++) {
		myMapx[vectorx[i]] = i;
	}
	for (int i = 0; i < vectory.size(); i++) {
		myMapy[vectory[i]] = i;
	}
	int **map = new int*[vectorx.size()];
	for (int i = 0; i < vectorx.size(); i++) {
		map[i] = new int[vectory.size()];
		memset(map[i], 0, sizeof(int)*vectory.size());
	}
	for (int i = 0; i < n; i++) {
		for (int j = myMapx[rect[i].x1]; j < myMapx[rect[i].x2]; j++) {
			for (int k = myMapy[rect[i].y1]; k < myMapy[rect[i].y2]; k++) {
				map[j][k] += 1;
			}
		}
	}
	int maxNum = 0;
	for (int i = 0; i < vectorx.size(); i++) {
		for (int j = 0; j < vectory.size(); j++) {
			maxNum = max(maxNum, map[i][j]);
		}
	}
	for (int i = 0; i < vectorx.size(); i++) {
		delete[] map[i];
	}
	delete[] map;
	delete[] rect;
	cout << maxNum;
	return 0;
}