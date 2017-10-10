#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n; cin >> n;
	int *height = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}
	sort(height, height + n);
	int sum;
	if (n % 2) {
		sum = max(height[n / 2 + 1] + height[n / 2] - height[n / 2 - 1] * 2, height[n / 2 + 1] * 2 - height[n / 2] - height[n / 2 - 1]);
		for (int i = 0; i < n / 2 - 1; i++) {
			sum += height[n - 1 - i] * 2 - height[i] * 2;
		}
	}
	else {
		sum = height[n / 2] - height[n / 2 - 1];
		for (int i = 0; i < n / 2 - 1; i++) {
			sum += height[n - 1 - i] * 2 - height[i] * 2;
		}
	}
	cout << sum;
	delete[] height;
	return 0;
}