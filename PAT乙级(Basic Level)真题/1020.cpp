#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, p; cin >> n >> p;
	int *data = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	sort(data, data + n);
	int maxlen = 0;
	int index = 1;
	for (int i = 0; i < n; i++) {
		if (data[i] * p >= data[n - 1]) {
			maxlen = max(maxlen, n - i);
			break;
		}
		while (data[i] * p >= data[index]) index++;
		maxlen = max(maxlen, index - i);
	}
	cout << maxlen;
	return 0;
}