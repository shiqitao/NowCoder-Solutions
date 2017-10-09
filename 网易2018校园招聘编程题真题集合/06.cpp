#include <iostream>
#include <string>
#include <map>
using namespace std;
int len;
bool ifLegal(string str);
int main()
{
	string s; cin >> s;
	len = s.size();
	map<string, int> hash;
	for (int i = 0; i < len; i++) {
		string temp = s.substr(0, i) + s.substr(i + 1, len - i - 1);
		for (int j = 0; j < len; j++) {
			string t = temp.substr(0, j) + s[i] + temp.substr(j, len - 1 - j);
			if (t != s && ifLegal(t)) hash[t] = 0;
		}
	}
	cout << hash.size();
	return 0;
}
bool ifLegal(string str)
{
	int n = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') n++;
		else n--;
		if (n < 0) return false;
	}
	return true;
}