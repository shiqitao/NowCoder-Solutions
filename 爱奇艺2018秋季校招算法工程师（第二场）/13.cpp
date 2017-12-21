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
	int i = 0, j = 1;
	while (data[j] == data[i]) j++;
	int max1 = max(data[i], data[j]);
	int max2 = min(data[i], data[j]);
	int index1 = data[i] > data[j] ? i : j;
	int index2 = data[i] > data[j] ? j : i;
	int maxor = max1^max2;
	while (true) {
		if (j == n) {
			i++; j = i + 1;
			while (j != n && data[j] == data[i]) j++;
			if (j == n) break;
			max1 = max(data[i], data[j]);
			max2 = min(data[i], data[j]);
			index1 = data[i] > data[j] ? i : j;
			index2 = data[i] > data[j] ? j : i;
			maxor = max(max1^max2, maxor);
		}
		if (data[j] <= max2 || data[j] == max1) {
			j++;
		}
		else if (i == index1 && data[j] > max1) {
			index1 = j; max1 = data[j];
			index2 = i; max2 = data[i];
			maxor = max(max1^max2, maxor);
		}
		else if (i == index1) {
			index2 = j; max2 = data[j];
			maxor = max(max1^max2, maxor);
		}
		else {
			i++; j = i + 1;
			while (j != n && data[j] == data[i]) j++;
			if (j == n) break;
			max1 = max(data[i], data[j]);
			max2 = min(data[i], data[j]);
			index1 = data[i] > data[j] ? i : j;
			index2 = data[i] > data[j] ? j : i;
			maxor = max(max1^max2, maxor);
		}
	}
	cout << maxor << endl;
	delete[] data;
	return 0;
}