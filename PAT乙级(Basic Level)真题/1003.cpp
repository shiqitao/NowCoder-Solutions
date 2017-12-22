#include <iostream>
#include <math.h>
using namespace std;
bool ifPrime(int k);
int main()
{
	int n, m; cin >> n >> m;
	int num = 1;
	int count = 0;
	while (num++, count < n) {
		if (ifPrime(num)) {
			count++;
		}
	}
	cout << num - 1;
	while (num++, count < m) {
		if (ifPrime(num)) {
			count++;
			if ((count - n) % 10) {
				cout << " " << num;
			}
			else {
				cout << endl << num;
			}
		}
	}
	return 0;
}
bool ifPrime(int k)
{
	if (k % 2 == 0 && k != 2) return false;
	int stop = sqrt(k);
	for (int i = 3; i <= stop; i += 2) {
		if (k%i == 0) {
			return false;
		}
	}
	return true;
}