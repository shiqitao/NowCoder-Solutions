#include <iostream>
#include <cstring>
using namespace std;
bool data[21];
void play(int n);
int main()
{
	memset(data, false, sizeof(bool)* 21);
	for (int i = 1; i < 21; i++) {
		play(i);
	}
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		cout << (data[temp % 20] ? "niu" : "yang") << endl;
	}
	return 0;
}
void play(int n)
{
	int power = 1;
	while (power <= n) {
		if (!data[n - power]) {
			data[n] = true;
			return;
		}
		power *= 4;
	}
}