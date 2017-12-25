#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	map<char, int> myMap;
	for (int i = 0; i < s2.length(); i++) {
		s2[i] = s2[i] <= 'z'&&s2[i] >= 'a' ? s2[i] - 'a' + 'A' : s2[i];
		myMap[s2[i]] = 1;
	}
	for (int i = 0; i < s1.length(); i++) {
		s1[i] = s1[i] <= 'z'&&s1[i] >= 'a' ? s1[i] - 'a' + 'A' : s1[i];
		if (myMap[s1[i]] == 0) {
			cout << s1[i];
			myMap[s1[i]] = 1;
		}
	}
	return 0;
}