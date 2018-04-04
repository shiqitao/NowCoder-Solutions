#include <iostream>
#include <string>
#define MOD 1000000007
using namespace std;
int main()
{
	string str; cin >> str;
	int numP = 0, numPA = 0, numPAT = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i]=='P') {
			numP++;
			numP %= MOD;
		}
		else if (str[i] == 'A') {
			numPA += numP;
			numPA %= MOD;
		}
		else {
			numPAT += numPA;
			numPAT %= MOD;
		}
	}
	cout << numPAT;
	return 0;
}