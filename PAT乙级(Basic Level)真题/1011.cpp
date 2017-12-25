#include <iostream>
#include <string>
using namespace std;
int main()
{
	int num[10] = { 0 };
	string str; cin >> str;
	for (int i = 0; i < str.length(); i++) {
		num[str[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		if (num[i]) {
			cout << i << ":" << num[i] << endl;
		}
	}
	return 0;
}