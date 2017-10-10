#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n; cin >> n;
	int *data = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	sort(data, data + n);
	int d = data[1] - data[0];
	for (int i = 2; i < n; i++) {
		if (d != data[i] - data[i - 1]) {
			cout << "Impossible";
			delete[] data;
			return 0;
		}
	}
	cout << "Possible";
	delete[] data;
	return 0;
}