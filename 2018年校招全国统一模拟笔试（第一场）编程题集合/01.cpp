#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char str[80];
	gets(str);
	for (int i = 0; i < strlen(str); i++) {
		if ((str[i] >= 'a'&&str[i] < 'z') || (str[i] >= 'A'&&str[i] < 'Z')) {
			str[i] += 1;
		}
		else if (str[i] == 'z' || str[i] == 'Z') {
			str[i] -= 25;
		}
	}
	cout << str;
	return 0;
}