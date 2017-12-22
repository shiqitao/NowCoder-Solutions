#include <iostream>
#include <string>
using namespace std;
int main()
{
	string A; cin >> A;
	int B; cin >> B;
	int temp = A[0] - '0';
	if (temp >= B) {
		cout << temp / B;
		temp %= B;
	}
	for (int i = 1; i < A.size(); i++) {
		temp = temp * 10 + A[i] - '0';
		temp >= B ? cout << temp / B : cout << 0;
		temp %= B;
	}
	cout << " " << temp;
	return 0;
}