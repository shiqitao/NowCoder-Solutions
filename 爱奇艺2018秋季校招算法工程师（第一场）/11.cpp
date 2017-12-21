#include <iostream>
#include <algorithm>
#define mod 1000000007
using namespace std;
int main()
{
	int n; cin >> n;
	int *num = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	long long int result = 1;
	for (int i = 0; i < n; i++) {
		if (num[i] <= i) {
			cout << 0 << endl;
			return 0;
		}
		result = result*(num[i] - i) % mod;
	}
	cout << result << endl;
	delete[] num;
	return 0;
}