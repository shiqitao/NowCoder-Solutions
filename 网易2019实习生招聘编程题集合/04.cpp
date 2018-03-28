#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	char director[5] = "NESW";
	int now = 0;
	for (int i = 0; i < n; i++) {
		char next; cin >> next;
		if (next == 'L') {
			now = (now + 4 - 1) % 4;
		}
		else {
			now = (now + 1) % 4;
		}
	}
	cout << director[now];
	return 0;
}