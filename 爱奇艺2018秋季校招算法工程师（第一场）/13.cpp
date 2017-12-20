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
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (sequence[i] == sequence[j]) {
				int nowlen = 1;
				int x = j - i - 1;
				int y = len - j - 1;
				if (x != 0 && y != 0) {
					int start1 = i + 1, start2 = j + 1;
					int **DP = new int*[x];
					for (int k = 0; k < x; k++) {
						DP[k] = new int[y];
						memset(DP[k], 0, sizeof(int)*y);
					}
					for (int k = 0; k < y; k++) {
						if (sequence[start1] == sequence[start2 + k]) {
							DP[0][k] = 1;
						}
					}
					for (int k = 0; k < x; k++) {
						if (sequence[start1 + k] == sequence[start2]) {
							DP[k][0] = 1;
						}
					}


					for (int k = 0; k < x; k++) {
						delete[] DP[k];
					}
					delete[] DP;
				}
			}
		}
	}

	return 0;
}