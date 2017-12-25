#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	string str, temp; cin >> temp >> str;
	map<char, int> myMap;
	for (int i = 0; i < temp.length(); i++) {
		if (temp[i] >= 'A' && temp[i] <= 'Z') {
			myMap[temp[i]] = 1;
			myMap[temp[i] - 'A' + 'a'] = 1;
		}
		else if (temp[i] == '+') {
			for (char ch = 'A'; ch <= 'Z'; ch++) {
				myMap[ch] = 1;
			}
		}
		else {
			myMap[temp[i]] = 1;
		}
	}
	for (int i = 0; i < str.length(); i++) {
		if (!myMap[str[i]]) {
			cout << str[i];
		}
	}
	return 0;
}