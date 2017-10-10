#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int *x = new int[n];
	int *y = new int[n];
	int *dx = new int[n*n];
	int *dy = new int[n*n];
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dx[i*n + j] = x[i] - x[j];
			dy[i*n + j] = y[i] - y[j];
		}
	}
	int max = -1, temp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int p = 0; p < n; p++) {
				if (p == i || p == j || dy[i*n + j] * dx[i*n + p] == dy[i*n + p] * dx[i*n + j]) continue;
				temp = 0;
				for (int q = 0; q < n; q++) {
					if (dy[i*n + j] * dx[i*n + q] == dy[i*n + q] * dx[i*n + j] || dy[i*n + j] * dy[p*n + q] == -dx[i*n + j] * dx[p*n + q]) {
						temp++;
					}
				}
				max = max>temp ? max : temp;
			}
		}
	}
	max = max == -1 ? n : max;
	cout << max;
	delete[] x;
	delete[] y;
	delete[] dx;
	delete[] dy;
	return 0;
}