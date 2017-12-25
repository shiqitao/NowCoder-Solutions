#include <iostream>
#include <string>
using namespace std;
int main()
{
	long long int A, B; cin >> A >> B;
	long long int C = A + B;
	int D; cin >> D;
	string str = "";
	while (C != 0) {
		str = char('0' + C%D) + str;
		C /= D;
	}
	cout << str;
	return 0;
}