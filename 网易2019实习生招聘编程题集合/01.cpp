#include <iostream>
#include <algorithm>
using namespace std;
struct Work { int d, p; };
struct People{ int a, index, money; };
bool cmp1(Work a, Work b) {
	return a.d < b.d;
}
bool cmp2(People a, People b) {
	return a.a < b.a;
}
bool cmp3(People a, People b) {
	return a.index < b.index;
}
int main()
{
	int n, m; cin >> n >> m;
	Work *work = new Work[n];
	for (int i = 0; i < n; i++) {
		cin >> work[i].d >> work[i].p;
	}
	People *people = new People[m];
	for (int i = 0; i < m; i++) {
		cin >> people[i].a;
		people[i].index = i;
	}
	sort(work, work + n, cmp1);
	sort(people, people + m, cmp2);
	int j = 0, maxMoney = 0;
	for (int i = 0; i < m; i++) {
		while (j < n) {
			if (work[j].d > people[i].a) {
				break;
			}
			maxMoney = max(maxMoney, work[j].p);
			j++;
		}
		people[i].money = maxMoney;
	}
	sort(people, people + m, cmp3);
	for (int i = 0; i < m; i++) {
		cout << people[i].money << endl;
	}
	delete[] work;
	delete[] people;
	return 0;
}