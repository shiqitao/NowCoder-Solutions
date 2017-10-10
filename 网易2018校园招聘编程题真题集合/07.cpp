#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n; cin >> n;
	int *data = new int[n];
	cin >> data[0];
	int *DP = new int[n*n];
	int sum = 0;
	for (int i = 1; i < n; i++) {
		cin >> data[i];
		DP[i*n + i - 1] = sum;
		sum += abs(data[i] - data[i - 1]);
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i - 1; j++) {
			DP[i*n + j] = DP[(i - 1)*n + j] + abs(data[i] - data[i - 1]);
		}
		for (int k = 0; k < i - 1; k++) {
			DP[i*n + i - 1] = min(DP[i*n + i - 1], DP[(i - 1)*n + k] + abs(data[i] - data[k]));
		}
	}
	int result = DP[(n - 1)*n];
	for (int i = 1; i < n - 1; i++) {
		result = min(result, DP[(n - 1)*n + i]);
	}
	cout << result;
	delete[] data;
	delete[] DP;
	return 0;
}