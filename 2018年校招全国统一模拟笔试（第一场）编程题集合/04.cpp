#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int *R = new int[n], temp;
	for (int i = 0; i < n; i++) {
		cin >> temp >> R[i];
		R[i] -= temp;
		m -= temp;
	}
	long long int **DP = new long long int*[n];
	for (int i = 0; i < n; i++) {
		DP[i] = new long long int[m + 1];
		memset(DP[i], 0, sizeof(long long int)*(m + 1));
	}
	for (int i = 0; i <= R[0]; i++) {
		DP[0][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= R[i]; j++) {
			for (int k = 0; k <= m - j; k++) {
				DP[i][k + j] += DP[i - 1][k];
			}
		}
	}
	cout << DP[n - 1][m] << endl;
	delete[] R;
	for (int i = 0; i < n; i++) {
		delete[] DP[i];
	}
	delete[] DP;
	return 0;
}