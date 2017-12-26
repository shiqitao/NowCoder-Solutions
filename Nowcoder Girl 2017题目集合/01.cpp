#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n; cin >> n;
	string result = "";
	while (n != 0) {
		result = (n % 2 ? "N" : "G") + result;
		n = (n - 1) / 2;
	}
	cout << result;
	return 0;
}