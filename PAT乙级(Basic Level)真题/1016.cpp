#include <iostream>
using namespace std;
int main()
{
	int c1, c2; cin >> c1 >> c2;
	int second = (c2 - c1 + 50) / 100;
	int minute = second / 60; second %= 60;
	int hour = minute / 60; minute %= 60;
	hour > 9 ? cout << hour << ":" : cout << 0 << hour << ":";
	minute > 9 ? cout << minute << ":" : cout << 0 << minute << ":";
	second > 9 ? cout << second : cout << 0 << second;
	return 0;
}