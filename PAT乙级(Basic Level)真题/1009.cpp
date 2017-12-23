#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n; cin >> n;
	for (int i = 0; i < 9; i++) {
		if (double(n) / i == 1111) {
			cout << n << " - " << n << " = 0000";
			return 0;
		}
	}
	int num[4], getMax, getMin;
	do {
		num[0] = n / 1000;
		num[1] = (n %= 1000, n / 100);
		num[2] = (n %= 100, n / 10);
		num[3] = (n %= 10, n);
		sort(num, num + 4);
		getMax = num[3] * 1000 + num[2] * 100 + num[1] * 10 + num[0];
		getMin = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
		n = getMax - getMin;
		cout << num[3] << num[2] << num[1] << num[0] << " - " << num[0] << num[1] << num[2] << num[3] << " = " << n << endl;
	} while (n != 6174);
	return 0;
}