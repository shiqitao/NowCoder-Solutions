#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	string str; cin >> str;
	int len = str.size();
	char pre = '0';
	int num = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] != pre) {
			num++;
			pre = str[i];
		}
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << (double)len / num;
	return 0;
}