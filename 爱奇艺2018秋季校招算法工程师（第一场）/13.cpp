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
		

		for (int i = 0; i < k; i++) {
			delete[] DP[i];
		}
		delete[] DP;
	}
	return 0;
}