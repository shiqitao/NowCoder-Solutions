#include <iostream>
using namespace std;
int main()
{
	int x, f, d, p; cin >> x >> f >> d >> p;
	if (x*f >= d) cout << d / x;
	else cout << f + (d - x*f) / (x + p);
	return 0;
}