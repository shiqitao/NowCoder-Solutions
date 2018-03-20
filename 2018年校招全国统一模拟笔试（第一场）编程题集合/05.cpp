#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int equal = 0, count = 0, data;
	while (count < n) {
		cin >> data;
		if (data == ++count) {
			if (count != n) cin >> data;
			count++; equal++;
		}
	}
	cout << equal;
	return 0;
}