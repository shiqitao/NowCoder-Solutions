#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n, s; cin >> n >> s;
	int data[10] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	int result = 0;
	for (int i = 0; i < pow(2, n); i++) {
		int mincoin = 10000, sum = 0, sumcoin = 0;
		int temp = i;
		for (int j = 0; j < n; j++) {
			if (temp % 2) {
				sum += data[j];
				mincoin = mincoin < data[j] ? mincoin : data[j];
				sumcoin++;
			}
			temp >>= 1;
		}
		result = sum >= s && sum - mincoin < s ? result>sumcoin ? result : sumcoin : result;
	}
	cout << result;
	return 0;
}