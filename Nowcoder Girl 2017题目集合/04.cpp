#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, m; cin >> n >> m;
	int **r = new int*[n], result = 0;
	int maxr[5] = { 0 };
	for (int i = 0; i < n; i++) {
		r[i] = new int[5];
		for (int j = 0; j < 5; j++) {
			cin >> r[i][j];
			maxr[j] = max(maxr[j], r[i][j]);
		}
	}
	if (m == 1) {
		for (int i = 0; i < n; i++) {
			int temp = 0;
			for (int k = 0; k < 5; k++) {
				temp += r[i][k];
			}
			result = max(result, temp);
		}
	}
	else if (m == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int temp = 0;
				for (int k = 0; k < 5; k++) {
					temp += max(r[i][k], r[j][k]);
				}
				result = max(result, temp);
			}
		}
	}
	else if (m == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int p = 0; p < n; p++) {
					int temp = 0;
					for (int k = 0; k < 5; k++) {
						temp += max(max(r[i][k], r[j][k]), r[p][k]);
					}
					result = max(result, temp);
				}
			}
		}
	}
	else if (m == 4) {
		int maxtemp[5][5] = { 0 };
		for (int p = 0; p < 5; p++) {
			for (int q = p + 1; q < 5; q++) {
				int temp = 0;
				for (int i = 0; i < n; i++) {
					temp = max(temp, r[i][p] + r[i][q]);
				}
				for (int k = 0; k < 5; k++) {
					if (k != p && k != q) {
						temp += maxr[k];
					}
				}
				result = max(result, temp);
			}
		}
	}
	else {
		for (int k = 0; k < 5; k++) {
			result += maxr[k];
		}
	}
	cout << result;
	return 0;
}