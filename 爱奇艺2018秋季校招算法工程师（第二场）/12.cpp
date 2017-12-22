#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int all = n + m;
	double *E = new double[m + 1];
	double pos = all*(all - 1) / 2.0;
	for (int i = 1; i <= m; i++)
	{
		int x = i, y = all - i;
		double e1 = y*(y - 1) / pos / 2;
		double e2 = y*x / pos;
		double e3 = x*(x - 1) / pos / 2;
		E[i] += e2*(E[i - 1] + 1);
		if (i >= 2) E[i] += e3*(E[i - 2] + 1);
		E[i] = (E[i] + e1) / (1 - e1);
	}
	cout << setiosflags(ios::fixed) << setprecision(1) << E[m] << endl;
	return 0;
}