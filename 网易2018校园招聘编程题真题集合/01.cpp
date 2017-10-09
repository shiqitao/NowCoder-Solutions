#include <iostream>
using namespace std;
void recursion(int n);
int main()
{
	int n; cin >> n;
	recursion(n);
	return 0;
}
void recursion(int n)
{
	if (n != 0) {
		if (n % 2) {
			recursion((n - 1) / 2);
			cout << "1";
		}
		else {
			recursion((n - 2) / 2);
			cout << "2";
		}
	}
}