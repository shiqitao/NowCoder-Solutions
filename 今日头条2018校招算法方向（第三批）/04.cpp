#include <iostream>
using namespace std;
int main()
{
	int n, x; cin >> n >> x; x--;
	unsigned long long *data = new unsigned long long[n];
	unsigned long long minnum = -1, minindex;
	for (int i = 0; i < n; i++) {
		cin >> data[i];
		minindex = data[i] < minnum || (data[i] == minnum && i <= x) ? i : minindex;
		minnum = data[i] < minnum || (data[i] == minnum && i <= x) ? data[i] : minnum;
	}
	if (x < minindex) {
		for (int i = 0; i <= x; i++) {
			cout << data[i] - minnum - 1 << " ";
		}
		for (int i = x + 1; i < minindex; i++) {
			cout << data[i] - minnum << " ";
		}
		cout << n*(minnum + 1) - minindex + x;
		for (int i = minindex + 1; i < n; i++) {
			cout << " " << data[i] - minnum - 1;
		}
	}
	else if (x >= minindex) {
		for (int i = 0; i < minindex; i++) {
			cout << data[i] - minnum << " ";
		}
		cout << n*minnum + x - minindex;
		for (int i = minindex + 1; i <= x; i++) {
			cout << " " << data[i] - minnum - 1;
		}
		for (int i = x + 1; i < n; i++) {
			cout << " " << data[i] - minnum;
		}
	}
	delete[] data;
	return 0;
}