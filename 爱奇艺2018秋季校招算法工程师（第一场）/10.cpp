#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string sequence; cin >> sequence;
	int depth = 0, maxDepth = 0;
	for (int i = 0; i < sequence.length(); i++) {
		if (sequence[i] == '(') {
			depth++;
			maxDepth = max(maxDepth, depth);
		}
		else depth--;
	}
	cout << maxDepth << endl;
	return 0;
}