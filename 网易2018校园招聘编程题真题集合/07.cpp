#include <iostream>
#include <limits.h>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n; cin >> n;
	int *data = new int[n];
	cin >> data[0] >> data[1];
	int *DP = new int[n*n];
	int sum = 0;
	DP[0] = DP[1] = DP[n] = 0;
	for (int i = 2; i < n; i++) {
		cin >> data[i];
		sum += abs(data[i] - data[i - 1]);
		DP[i] = sum;
		DP[i*n] = sum;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (i - 1 > j) DP[i*n + j] = DP[(i - 1)*n + j] + abs(data[i] - data[i - 1]);
			else if (j - 1 > i) DP[i*n + j] = DP[i*n + j - 1] + abs(data[i] - data[i - 1]);
			else if (i - 1 == j) {
				DP[i*n + j] = INT_MAX;
				for (int k = 0; k < j; k++) {
					DP[i*n + j] = min(DP[i*n + j], DP[k*n + j] + abs(data[i] - data[k]));
				}
			}
			else if (j - 1 == i) {
				DP[i*n + j] = INT_MAX;
				for (int k = 0; k < i; k++) {
					DP[i*n + j] = min(DP[i*n + j], DP[i*n + k] + abs(data[j] - data[k]));
				}
			}
			else DP[i*n + j] = INT_MAX;
		}
	}
	int result = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		result = min(result, DP[i*n + n - 1]);
		result = min(result, DP[(n - 1)*n + i]);
	}
	cout << result;
	delete[] DP;
	return 0;
}