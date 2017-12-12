#include <iostream>
#include <string>
using namespace std;
int num[4] = { 1, 27, 703, 18279 };
int pre(string str);
int main()
{
	string str;
	cin >> str;
	cout << pre(str) << endl;
	return 0;
}
int pre(string str)
{
	int index = 0;
	int len = str.size();
	if (len == 1) {
		return str[0] - 'a';
	}
	else {
		cout << (str[0] - 'a')*num[len - 1] << endl;
		return (str[0] - 'a')*num[len - 1] + pre(str.substr(1, len - 1)) + 1;
	}
}