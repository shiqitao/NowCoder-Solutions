#include <iostream>
using namespace std;
int main()
{
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		int sum = 0,num;
		for (int j = 0; j < n; j++) {
			cin >> num;
			if (num % 4 == 0) sum += 2;
			else if (num % 2 == 0) sum += 1;
		}
		if (sum * 2 >= 2 * n - 2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}