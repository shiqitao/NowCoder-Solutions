#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	string sequence; cin >> sequence;
	int len = sequence.length();
	int maxlen = 0;
	for (int k = 1; k < len; k++) {
		int **DP = new int*[k];
		for (int i = 0; i < k; i++) {
			DP[i] = new int[len - k];
			memset(DP[i], 0, sizeof(int)*(len - k));
		}
		DP[0][0] = sequence[0] == sequence[k] ? 1 : 0;
		for (int i = 1; i < k; i++) {
			DP[i][0] = sequence[i] == sequence[k] ? 1 : DP[i - 1][0];
		}
		for (int i = 1; i < len - k; i++) {
			DP[0][i] = sequence[0] == sequence[k + i] ? 1 : DP[0][i - 1];
		}
		for (int i = 1; i < k; i++) {
			for (int j = 1; j < len - k; j++) {
				DP[i][j] = sequence[i] == sequence[k + j] ? DP[i - 1][j - 1] + 1 : DP[i - 1][j - 1];
				DP[i][j] = max(DP[i][j], DP[i - 1][j]);
				DP[i][j] = max(DP[i][j], DP[i][j - 1]);
			}
		}
		maxlen = max(maxlen, DP[k - 1][len - k - 1]);
		for (int i = 0; i < k; i++) {
			delete[] DP[i];
		}
		delete[] DP;
	}
	cout << maxlen * 2 << endl;
	return 0;
}