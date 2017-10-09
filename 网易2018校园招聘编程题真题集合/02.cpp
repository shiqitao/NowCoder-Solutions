#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string n; cin >> n;
	string temp = n;
	reverse(n.begin(), n.end());
	cout << atoi(n.c_str()) + atoi(temp.c_str());
	return 0;
}