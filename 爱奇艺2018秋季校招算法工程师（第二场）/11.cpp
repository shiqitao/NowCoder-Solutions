#include <iostream>
using namespace std;
int main()
{
	bool data[10] = { 0, 1, 0, 1, 1, 0, 1, 0, 1, 1 };
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		cout << (data[temp % 10] ? "niu" : "yang") << endl;
	}
	return 0;
}