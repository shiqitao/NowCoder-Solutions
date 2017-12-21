#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 55;
int getCnt(vector<int> A, int x){
	int n = A.size(), cnt = 0;
	for (int i = x; i < n; i++)
	for (int j = 0; j < i; j++)
	if (A[j] > A[i]) cnt++;
	return cnt;
}
int main(){
	int n, K, dp[maxn][maxn];
	memset(dp, 0, sizeof(int)*maxn*maxn);
	cin >> n >> K;
	vector<int> A(n);
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = n - 1; i >= 0; i--)
	{
		for (int k = 0; k <= K; k++){
			vector<int> tmp1(A.begin(), A.begin() + i + 1);
			dp[i][k] = getCnt(tmp1, i) + dp[i + 1][k];
			if (k >= 1){
				for (int j = i + 1; j < n; j++){
					vector<int> tmp2(A.begin(), A.begin() + j + 1);
					reverse(tmp2.begin() + i, tmp2.begin() + j + 1);
					dp[i][k] = min(dp[i][k], getCnt(tmp2, i) + dp[j + 1][k - 1]);
				}
			}
		}
	}
	cout << dp[0][K] << endl;
}