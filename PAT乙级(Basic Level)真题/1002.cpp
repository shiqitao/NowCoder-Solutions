#include <iostream>
#include <iomanip>
#define MAX(x,y) ((x)>(y)?(x):(y))
using namespace std;
int main()
{
	int A[5] = { 0 };
	bool B1 = false; int B3 = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		A[0] += temp % 10 ? 0 : temp;
		A[1] += temp % 5 == 1 ? ((B1 = !B1) ? temp : -temp) : 0;
		A[2] += temp % 5 == 2 ? 1 : 0;
		A[3] += temp % 5 == 3 ? B3++, temp : 0;
		A[4] = temp % 5 == 4 ? MAX(A[4], temp) : A[4];
	}
	for (int i = 0; i < 5; i++) {
		if (A[i] == 0) cout << "N";
		else if (i == 3) cout << setiosflags(ios::fixed) << setprecision(1) << (double)A[i] / B3;
		else cout << A[i];
		if (i != 5) cout << " ";
	}
	return 0;
}