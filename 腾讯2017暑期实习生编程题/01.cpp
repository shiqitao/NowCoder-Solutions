#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	string str;
	while (cin >> str) {
		int len = str.size() + 1;
		int **DP = new int*[len];
		for (int i = 0; i < len; i++) {
			DP[i] = new int[len];
			memset(DP[i], 0, sizeof(int)*len);
		}
		for (int i = 1; i < len; i++) {
			for (int j = i - 1; j >= 0; j--) {
				DP[j][i] = max(DP[j][i - 1], 1);
				for (int k = j; k < i - 1; k++) {
					if (str[i - 1] == str[k]) {
						DP[j][i] = max(DP[j][i], DP[k + 1][i - 1] + 2);
						break;
					}
					else {
						DP[j][i] = max(DP[j][i], DP[k + 1][i - 1]);
					}
				}
			}
		}
		cout << len - 1 - DP[0][len - 1] << endl;
		for (int i = 0; i < len; i++) {
			delete[] DP[i];
		}
		delete[] DP;
	}
	return 0;
}