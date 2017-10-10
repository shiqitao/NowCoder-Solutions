#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string str; cin >> str;
	int len = str.size();
	char ch = str[0];
	int maxLen = 1, tempLen = 1;
	for (int i = 1; i < len; i++) {
		if (str[i] != ch) {
			tempLen++;
			ch = str[i];
		}
		else {
			maxLen = max(maxLen, tempLen);
			tempLen = 1;
		}
	}
	maxLen = max(maxLen, tempLen);
	cout << maxLen;
	return 0;
}