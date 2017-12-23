#include <iostream>
using namespace std;
int main()
{
	int grade[3] = { 0 };
	int win[3] = { 0 };
	int lose[3] = { 0 };
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		char temp1, temp2; cin >> temp1 >> temp2;
		if (temp1 == temp2) grade[1]++;
		else if (temp1 == 'C' && temp2 == 'J') { grade[0]++; win[0]++; }
		else if (temp1 == 'C' && temp2 == 'B') { grade[2]++; lose[2]++; }
		else if (temp1 == 'J' && temp2 == 'C') { grade[2]++; lose[0]++; }
		else if (temp1 == 'J' && temp2 == 'B') { grade[0]++; win[1]++; }
		else if (temp1 == 'B' && temp2 == 'C') { grade[0]++; win[2]++; }
		else { grade[2]++; lose[1]++; }
	}
	cout << grade[0] << " " << grade[1] << " " << grade[2] << endl
		<< grade[2] << " " << grade[1] << " " << grade[0] << endl;
	if (win[2] >= win[0] && win[2] >= win[1]) cout << "B ";
	else if (win[0] >= win[1]) cout << "C ";
	else cout << "J ";
	if (lose[2] >= lose[0] && lose[2] >= lose[1]) cout << "B";
	else if (lose[0] >= lose[1]) cout << "C";
	else cout << "J";
	return 0;
}