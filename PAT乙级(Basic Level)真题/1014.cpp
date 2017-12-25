#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str; cin >> str;
	int index = 0;
	string num = ""; int E = 0;
	while (str[++index] != 'E') {
		num += str[index];
	}
	bool EPorN = str[(++index)++] == '+';
	for (; index < str.length(); index++) {
		E = E * 10 + str[index] - '0';
	}
	if (str[0] == '-') {
		cout << str[0];
	}
	if (EPorN)
	{
		cout << num[0];
		if (num.length() - 2 <= E) {
			for (int i = 2; i < num.length(); i++) {
				cout << num[i];
			}
			for (int i = 0; i < E - num.length() + 2; i++){
				cout << 0;
			}
		}
		else {
			for (int i = 2; i < E + 2; i++) {
				cout << num[i];
			}
			cout << ".";
			for (int i = E + 2; i < num.length(); i++) {
				cout << num[i];
			}
		}
	}
	else {
		cout << "0.";
		for (int i = 1; i < E; i++) {
			cout << 0;
		}
		cout << num[0];
		for (int i = 2; i < num.length(); i++) {
			cout << num[i];
		}
	}
	return 0;
}