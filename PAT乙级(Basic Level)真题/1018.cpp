#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n; cin >> n;
	string name, str;
	string minStr = "z", minName = "";
	string maxStr = "", maxName = "";
	string start = "1814/09/06";
	string end = "2014/09/06";
	int counts = 0;
	for (int i = 0; i < n; i++) {
		cin >> name >> str;
		if (str >= start && str <= end) {
			counts++;
			if (minStr > str) {
				minStr = str;
				minName = name;
			}
			if (maxStr < str) {
				maxStr = str;
				maxName = name;
			}
		}
	}
	cout << counts << " " << minName << " " << maxName << endl;
	return 0;
}