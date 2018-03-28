#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int max_h = 0, max_m = 0, maxTime = 0;
	int *hour = new int[n];
	int *minute = new int[n];
	int *time = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> hour[i] >> minute[i];
		time[i] = hour[i] * 60 + minute[i];
	}
	int X; cin >> X;
	int reach_h, reach_m; cin >> reach_h >> reach_m;
	int reachTime = reach_h * 60 + reach_m;
	for (int i = 0; i < n; i++) {
		if (time[i]>maxTime && time[i] + X <= reachTime) {
			maxTime = time[i];
			max_h = hour[i];
			max_m = minute[i];
		}
	}
	cout << max_h << " " << max_m;
	delete[] hour;
	delete[] minute;
	delete[] time;
	return 0;
}