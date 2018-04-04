#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
	string str1, str2; cin >> str1 >> str2;
	unordered_map<char, int> data;
	for (int i = 0; i < str1.size(); i++) {
		data[str1[i]]++;
	}
	bool buy = true;
	int count = 0;
	for (int i = 0; i < str2.size(); i++) {
		if (data[str2[i]] <= 0) {
			buy = false;
			count++;
		}
		data[str2[i]]--;
	}
	if (buy) {
		cout << "Yes " << str1.size() - str2.size();
	}
	else {
		cout << "No " << count;
	}
	return 0;
}