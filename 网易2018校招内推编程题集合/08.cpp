#include <iostream>
#include <cstring>
using namespace std;
#define MOD 1000000007
int main()
{
	int n, k; cin >> n >> k;
	long long *res = new long long[n*k];
	for (int i = 0; i < k; i++) {
		res[i] = 1;
	}
	for (int p = 1; p < n; p++)
	{
		long long sum = 0;
		for (int i = 0; i < k; i++) {
			sum += res[(p - 1)*k + i];
		}
		for (int i = 0; i < k; i++) {
			res[p*k + i] = sum;
			for (int j = 2 * i + 1; j < k; j += i + 1) {
				res[p*k + i] -= res[(p - 1)*k + j];
			}
			res[p*k + i] %= MOD;
		}
	}
	long long sum = 0;
	for (int i = 0; i < k; i++) {
		sum += res[(n - 1)*k + i];
	}
	cout << sum % MOD;
	delete[] res;
	return 0;
}