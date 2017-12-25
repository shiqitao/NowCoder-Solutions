#include <iostream>
#include <string>
using namespace std;
int main()
{
	int num[10]; cin >> num[0];
	string str = "";
	for (int i = 1; i < 10; i++) {
		cin >> num[i];
		for (int j = 0; j < num[i]; j++) {
			str += '0' + i;
		}
	}
	cout << str[0];
	for (int i = 0; i < num[0]; i++) {
		cout << 0;
	}
	for (int i = 1; i < str.length(); i++) {
		cout << str[i];
	}
	return 0;
}