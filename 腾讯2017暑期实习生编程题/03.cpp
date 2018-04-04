#include <iostream>
#include <limits.h>
#include <map>
using namespace std;
struct Num{ int num, count; };
int main()
{
	int n, temp;
	while (cin >> n) {
		map<int, int> data;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			data[temp]++;
		}
		Num *num = new Num[data.size()];
		int p = 0, numMin = 0;
		for (map<int, int>::iterator it = data.begin(); it != data.end(); ++it, ++p) {
			num[p].num = it->first;
			num[p].count = it->second;
			numMin += num[p].count*(num[p].count - 1) / 2;
		}
		if (numMin == 0) {
			int minNum = INT_MAX;
			for (int i = 0; i < p - 1; i++) {
				if (num[i + 1].num - num[i].num < minNum) {
					minNum = num[i + 1].num - num[i].num;
					numMin = num[i + 1].count*num[i].count;
				}
				else if (num[i + 1].num - num[i].num == minNum) {
					numMin += num[i + 1].count*num[i].count;
				}
			}
		}
		cout << numMin << " " << num[0].count*num[p - 1].count << endl;
		delete[] num;
	}
	return 0;
}