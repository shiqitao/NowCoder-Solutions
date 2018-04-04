#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string str;
	while (cin >> str) {
		for (int k = 0; k < str.size(); k++) {
			bool stop = true;
			for (int i = str.size() - 1; i > 0; i--) {
				if (str[i - 1] >= 'A'&&str[i - 1] <= 'Z' && (str[i]<'A' || str[i]>'Z')) {
					swap(str[i - 1], str[i]);
					stop = false;
				}
			}
			if (stop) break;
		}
		cout << str << endl;
	}
	return 0;
}