#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int *data = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	cout << data[n - 1];
	for (int i = n - 3; i >= (n + 1) % 2; i -= 2) {
		cout << " " << data[i];
	}
	for (int i = n % 2; i < n; i += 2) {
		cout << " " << data[i];
	}
	delete[] data;
	return 0;
}