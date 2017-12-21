#include <iostream>
using namespace std;
double f[100];
int main()
{
	int boring, unboring;
	cin >> boring >> unboring;
	int all = boring + unboring;
	double pos = (double)all*(all - 1) / 2;
	for (int i = 1; i <= unboring; i++)
	{
		int x = i, y = all - i;
		double c1 = y*(y - 1) / pos / 2;
		double c2 = y*x / pos;
		double c3 = x*(x - 1) / pos / 2;
		f[i] += c2*(f[i - 1] + 1);
		if (i >= 2) f[i] += c3*(f[i - 2] + 1);
		f[i] = (f[i] + c1) / (1 - c1);
	}
	printf("%.1lf", f[unboring]);
	return 0;
}