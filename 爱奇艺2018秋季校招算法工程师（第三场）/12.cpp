#include <iostream>
using namespace std;
long long int csum(long long int num);
int main()
{
	long long int sum; cin >> sum;
	long long int start = 1, end = sum;
	while (start + 1 < end) {
		long long int  mid = start + (end - start) / 2;
		if (csum(mid) == sum) {
			cout << mid << endl;
			return 0;
		}
		else if (csum(mid) > sum) end = mid;
		else start = mid;
	}
	if (csum(start) == sum) cout << start << endl;
	else if (csum(end) == sum) cout << end << endl;
	else cout << -1 << endl;
	return 0;
}
long long int csum(long long int num)
{
	long long int result = 0;
	while (num != 0) {
		result += num;
		num /= 10;
	}
	return result;
}