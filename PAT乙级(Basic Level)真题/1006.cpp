#include <iostream>
using namespace std;
int main()
{
	int A, DA, B, DB; cin >> A >> DA >> B >> DB;
	int AA = 0, BB = 0;
	while (A != 0) {
		if (DA == A % 10) {
			AA = AA * 10 + DA;
		}
		A /= 10;
	}
	while (B != 0) {
		if (DB == B % 10) {
			BB = BB * 10 + DB;
		}
		B /= 10;
	}
	cout << AA + BB;
	return 0;
}