#include <iostream>
#include <cstring>
using namespace std;
void DFS(int k, int n, bool data[9], int num, int index);
bool ifNone = true;
int main()
{
	int k, n; cin >> k >> n;
	bool data[9] = { 0 };
	DFS(k, n, data, 0, 0);
	if (ifNone) {
		cout << "None";
	}
	return 0;
}
void DFS(int k, int n, bool data[9], int num, int index)
{
	if (num == k) {
		int sum = 0;
		for (int i = 0; i < 9; i++) {
			sum += data[i] * (i + 1);
		}
		if (sum == n) {
			ifNone = false;
			for (int i = 0; i < 9; i++) {
				if (data[i]) {
					cout << i + 1 << " ";
				}
			}
			cout << endl;
		}
		return;
	}
	if (index >= 9 || num > k) {
		return;
	}
	bool temp[9];
	memcpy(temp, data, sizeof(bool)* 9);
	temp[index] = true;
	DFS(k, n, temp, num + 1, index + 1);
	memcpy(temp, data, sizeof(bool)* 9);
	temp[index] = false;
	DFS(k, n, temp, num, index + 1);
}