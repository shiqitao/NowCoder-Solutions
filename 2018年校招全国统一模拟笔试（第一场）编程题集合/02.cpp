#include <iostream>
#include <algorithm>
using namespace std;
struct Wood
{
	unsigned short int P, Q, K;
};
bool cmp(Wood wood1, Wood wood2);
int find(int *set, int x);
int main()
{
	int N, M; cin >> N >> M;
	Wood *wood = new Wood[M];
	int maxLen = 0;
	for (int i = 0; i < M; i++) {
		cin >> wood[i].P >> wood[i].Q >> wood[i].K;
		wood[i].P -= 1;
		wood[i].Q -= 1;
	}
	sort(wood, wood + M, cmp);
	int *set = new int[N];
	for (int i = 0; i < N; i++) {
		set[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int fx = find(set, wood[i].P);
		int fy = find(set, wood[i].Q);
		set[fx] = fy;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			cnt += set[i] == i ? 1 : 0;
		}
		if (cnt == 1) {
			cout << wood[i].K;
			delete[] wood;
			return 0;
		}
	}
}
bool cmp(Wood wood1, Wood wood2)
{
	return wood1.K < wood2.K;
}
int find(int *set, int x){
	return x == set[x] ? x : (set[x] = find(set, set[x]));
}