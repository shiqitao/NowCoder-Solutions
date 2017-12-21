#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
	int n; cin >> n;
	stack<int> data;
	int result = 0;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		while (!data.empty() && temp>data.top()) {
			result = max(result, temp^data.top()), data.pop();
		}
		if (!data.empty()) result = max(result, temp^data.top());
		data.push(temp);
	}
	cout << result << endl;
	return 0;
}