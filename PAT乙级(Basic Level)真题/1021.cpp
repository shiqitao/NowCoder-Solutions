#include <iostream>
#include <string>
using namespace std;
int main()
{
	int weight[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	char ch[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
	int n; cin >> n;
	bool allpassed = true;
	for (int k = 0; k < n; k++) {
		string str; cin >> str;
		int num = 0, i = 0;
		for (; i < 17; i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				num += (str[i] - '0')*weight[i];
			}
			else break;
		}
		if (i != 17 || str[i] != ch[num % 11]) {
			cout << str << endl;
			allpassed = false;
		}
	}
	if (allpassed) {
		cout << "All passed";
	}
	return 0;
}