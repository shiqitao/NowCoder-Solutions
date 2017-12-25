#include<iostream>
using namespace std;
int main(){
	int num, n = 0;
	char ch;
	cin >> num >> ch;
	int sum = -1;
	while (sum <= num) {
		sum = 2 * (++n)*n - 1;
	}
	for (int i = n - 1; i > 0; i--) {
		for (int j = n - 1 - i; j > 0; j--)
			cout << " ";
		for (int j = 2 * i - 1; j > 0; j--)
			cout << ch;
		cout << endl;
	}
	for (int i = 2; i <= n - 1; i++) {
		for (int j = n - 1 - i; j > 0; j--)
			cout << " ";
		for (int j = 2 * i - 1; j > 0; j--)
			cout << ch;
		cout << endl;
	}
	cout << num - 2 * (n - 1)*(n - 1) + 1 << endl;
	return 0;
}