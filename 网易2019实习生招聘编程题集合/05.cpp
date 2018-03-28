#include <iostream>
using namespace std;
int main()
{
	int n, k; cin >> n >> k;
	long long int count = 0;
	if (k == 0) {
		count = n;
		count = count*count;
	}
	else {
		for (int y = k + 1; y <= n; y++) {
			count += n / y*(y - k) + (n % y >= k ? n % y - k + 1 : 0);
		}
	}
	cout << count;
	return 0;
}