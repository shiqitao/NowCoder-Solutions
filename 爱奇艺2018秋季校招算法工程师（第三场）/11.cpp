#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str; cin >> str;
	int result = 0, num = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') num++;
		else {
			if (num == 0) result++;
			else num--;
		}
	}
	cout << result + num << endl;
	return 0;
}