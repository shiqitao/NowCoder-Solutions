#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
	int n; cin >> n;
	unordered_map<int, int> data;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		data[temp]++;
	}
	int m; cin >> m;
	vector<int> result;
	for (int i = 0; i < m; i++) {
		int temp; cin >> temp;
		result.push_back(data[temp]);
	}
	cout << result[0];
	for (int i = 1; i < m; i++) {
		cout << " " << result[i];
	}
	return 0;
}