#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str; cin >> str;
	int len = str.size();
	char ch1 = str[0], ch2 = str[0];
	int i;
	for (i = 1; i < len; i++) {
		if (str[i] != ch1) {
			ch2 = str[i];
			break;
		}
	}
	for (; i < len; i++) {
		if (str[i] != ch1 && str[i] != ch2) {
			cout << 0;
			return 0;
		}
	}
	if (ch1 == ch2) cout << 1;
	else cout << 2;
	return 0;
}