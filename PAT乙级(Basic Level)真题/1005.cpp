#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Stu
{
	int ID;
	int integrity;
	int ability;
	int all;
};
bool cmp(Stu stu1, Stu stu2);
void print(vector<Stu> &v);
int main()
{
	vector<Stu> v1, v2, v3,v4;
	int n, H, L; cin >> n >> L >> H;
	for (int i = 0; i < n; i++) {
		int ID, integrity, ability;
		cin >> ID >> integrity >> ability;
		Stu stu{ ID, integrity, ability, integrity + ability };
		if (integrity >= H && ability >= H) v1.push_back(stu);
		else if (integrity >= H && ability >= L) v2.push_back(stu);
		else if (integrity >= L && ability >= L && integrity >= ability) v3.push_back(stu);
		else if (integrity >= L && ability >= L) v4.push_back(stu);
	}
	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);
	sort(v3.begin(), v3.end(), cmp);
	sort(v4.begin(), v4.end(), cmp);
	cout << v1.size() + v2.size() + v3.size() + v4.size() << endl;
	print(v1); print(v2); print(v3); print(v4);
	return 0;
}
bool cmp(Stu stu1, Stu stu2)
{
	if (stu1.all != stu2.all) return stu1.all > stu2.all ? true : false;
	if (stu1.integrity != stu2.integrity) return stu1.integrity > stu2.integrity ? true : false;
	return stu1.ID < stu2.ID ? true : false;
}
void print(vector<Stu> &v)
{
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].ID << " " << v[i].integrity << " " << v[i].ability << endl;
	}
}