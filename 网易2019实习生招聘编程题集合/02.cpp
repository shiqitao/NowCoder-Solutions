#include <iostream>
using namespace std;
int main()
{
	int l, r; cin >> l >> r;
	int count = (r - l + 1) / 3 * 2;
	int num = r - l + 1 - (r - l + 1) / 3 * 3;
	if (num == 1 && (l % 3 == 0 || l % 3 == 2)) {
		count += 1;
	}
	else if (num == 2 && (l % 3 == 0 || l % 3 == 1)) {
		count += 1;
	}
	else if (num == 2 && l % 3 == 2) {
		count += 2;
	}
	cout << count;
	return 0;
}