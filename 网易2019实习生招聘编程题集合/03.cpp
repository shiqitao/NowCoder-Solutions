#include <iostream>
using namespace std;
int main()
{
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		int j = 0, count = 0;
		while (j++ < n) {
			char ch; cin >> ch;
			if (ch == '.') {
				count++;
				if (j++ < n) cin >> ch;
				if (j++ < n) cin >> ch;
			}
		}
		cout << count << endl;
	}
	return 0;
}