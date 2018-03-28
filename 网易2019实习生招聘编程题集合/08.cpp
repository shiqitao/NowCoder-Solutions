#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long int w;
void DFS(long long int *data, int n, int index, long long int weight, vector<long long int> &result);
int main()
{
	int n; cin >> n >> w;
	long long int *data = new long long int[n];
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	vector<long long int> part1;
	vector<long long int> part2;
	DFS(data, n / 2, 0, 0, part1);
	DFS(data + n / 2, n - n / 2, 0, 0, part2);
	sort(part1.begin(), part1.end());
	sort(part2.begin(), part2.end());
	int count = 0, j = part2.size() - 1;
	for (int i = 0; i < part1.size(); i++) {
		while (j >= 0) {
			if (part1[i] + part2[j] <= w) {
				count += j + 1;
				break;
			}
			j--;
		}
	}
	cout << count;
	delete[] data;
	return 0;
}
void DFS(long long int *data, int n, int index, long long int weight, vector<long long int> &result)
{
	if (weight > w) {
		return;
	}
	if (index == n) {
		result.push_back(weight);
		return;
	}
	DFS(data, n, index + 1, weight, result);
	DFS(data, n, index + 1, weight + data[index], result);
}