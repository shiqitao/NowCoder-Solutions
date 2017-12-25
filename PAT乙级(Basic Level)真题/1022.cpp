#include <iostream>
#include <map>
using namespace std;
int main()
{
	int n; cin >> n;
	int maxAll = 0, maxID = 0;
	map<int, int> myMap;
	for (int i = 0; i < n; i++) {
		int id, grade; cin >> id >> grade;
		myMap[id] += grade;
		maxID = myMap[id]>maxAll ? id : maxID;
		maxAll = myMap[id] > maxAll ? myMap[id] : maxAll;
	}
	cout << maxID << " " << maxAll;
	return 0;
}