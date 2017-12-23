#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
struct Mooncake
{
	double num;
	double allprize;
	double prize;
};
bool cmp(Mooncake mooncake1, Mooncake mooncake2);
int main()
{
	int n, need; cin >> n >> need;
	Mooncake*mooncake = new Mooncake[n];
	for (int i = 0; i < n; i++) {
		cin >> mooncake[i].num;
	}
	for (int i = 0; i < n; i++) {
		cin >> mooncake[i].allprize;
		mooncake[i].prize = mooncake[i].allprize / mooncake[i].num;
	}
	sort(mooncake, mooncake + n, cmp);
	double result = 0;
	int i = 0;
	do {
		if (mooncake[i].num < need) {
			result += mooncake[i].allprize;
			need -= mooncake[i].num;
		}
		else {
			result += need*mooncake[i].prize;
			break;
		}
	} while (++i < n);
	cout << setiosflags(ios::fixed) << setprecision(2) << result;
	delete[] mooncake;
	return 0;
}
bool cmp(Mooncake mooncake1, Mooncake mooncake2) { return mooncake1.prize > mooncake2.prize; }