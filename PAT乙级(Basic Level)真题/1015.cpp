#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int main()
{
	int data[100000];
	int next[100000];
	int i, first, n, k, t, num, j;
	int a[100000];
	cin >> first >> n >> k;
	for (i = 0; i < n; i++)
	{
		cin >> t;
		cin >> data[t] >> next[t];
	}
	num = 0;
	while (first != -1)
	{
		a[num++] = first;
		first = next[first];
	}
	int time = (num) / k;
	j = 0;
	for (i = 0; j < time; i = i + k, j++)
		reverse(a + i, a + i + k);
	for (i = 0; i < num - 1; i++)
	{
		cout << setw(5) << setfill('0') << a[i];
		cout << " " << data[a[i]];
		cout << " " << setw(5) << setfill('0') << a[i + 1] << endl;
	}
	cout << setw(5) << setfill('0') << a[num - 1] << " " << data[a[num - 1]] << " " << "-1" << endl;
	return 0;
}