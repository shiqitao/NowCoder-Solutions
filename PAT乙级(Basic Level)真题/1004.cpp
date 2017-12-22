#include <iostream>
#include <string>
using namespace std;
char* week[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
int main()
{
	string str[4];
	for (int i = 0; i < 4; i++) {
		cin >> str[i];
	}
	int k = 0;
	while (true) {
		if (str[0][k] == str[1][k] && str[0][k] >= 'A' && str[0][k] <= 'Z') {
			cout << week[str[0][k] - 'A'] << " ";
			break;
		}
		k++;
	}
	while (k++) {
		if (str[0][k] == str[1][k]) {
			str[0][k] > '9' ? (cout << 10 + str[0][k] - 'A') : (cout << 0 << str[0][k]);
			break;
		}
	}
	k = 0;
	while (true) {
		if (str[2][k] == str[3][k] && ((str[2][k] >= 'a'&& str[2][k] <= 'z') || (str[2][k] >= 'A'&& str[2][k] <= 'Z'))) {
			k > 9 ? cout << ":" << k : cout << ":0" << k;
			break;
		}
		k++;
	}
	return 0;
}