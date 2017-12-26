#include <iostream>
#include <algorithm>
using namespace std;
class Cube
{
	friend istream& operator>>(istream &in, Cube &obj);
private:
	int _up[4];
	int _down[4];
	int _left[4];
	int _right[4];
	int _front[4];
	int _back[4];
	int calnow() const;
	void upp();		// 上层顺时针旋转90度
	void upn();		// 上层逆时针旋转90度
	void rightp();	// 右层顺时针旋转90度
	void rightn();	// 右层逆时针旋转90度
	void frontp();	// 前层顺时针旋转90度
	void frontn();	// 前层逆时针旋转90度
public:
	int rotate(int) const;
};
istream& operator>>(istream &in, Cube &obj)
{
	in >> obj._up[0] >> obj._up[1] >> obj._up[2] >> obj._up[3];
	in >> obj._left[0] >> obj._left[1] >> obj._front[0] >> obj._front[1];
	in >> obj._right[0] >> obj._right[1] >> obj._left[2] >> obj._left[3];
	in >> obj._front[2] >> obj._front[3] >> obj._right[2] >> obj._right[3];
	in >> obj._down[0] >> obj._down[1] >> obj._down[2] >> obj._down[3];
	in >> obj._back[0] >> obj._back[1] >> obj._back[2] >> obj._back[3];
	return in;
}
int Cube::calnow() const
{
	int now[6] = { 1, 1, 1, 1, 1, 1 }, result = 0;
	for (int i = 0; i < 4; i++) {
		now[0] *= _up[i]; now[1] *= _down[i];
		now[2] *= _left[i]; now[3] *= _right[i];
		now[4] *= _front[i]; now[5] *= _back[i];
	}
	for (int i = 0; i < 6; i++) {
		result += now[i];
	}
	return result;
}
void Cube::upp()
{
	swap(_up[0], _up[1]);
	swap(_up[0], _up[3]);
	swap(_up[0], _up[2]);
	swap(_front[0], _left[0]); swap(_front[1], _left[1]);
	swap(_front[0], _back[3]); swap(_front[1], _back[2]);
	swap(_front[0], _right[0]); swap(_front[1], _right[1]);
}
void Cube::upn()
{
	swap(_up[0], _up[2]);
	swap(_up[0], _up[3]);
	swap(_up[0], _up[1]);
	swap(_front[0], _right[0]); swap(_front[1], _right[1]);
	swap(_front[0], _back[3]); swap(_front[1], _back[2]);
	swap(_front[0], _left[0]); swap(_front[1], _left[1]);
}
void Cube::rightp()
{
	swap(_right[0], _right[1]);
	swap(_right[0], _right[3]);
	swap(_right[0], _right[2]);
	swap(_front[1], _up[1]); swap(_front[3], _up[3]);
	swap(_front[1], _back[1]); swap(_front[3], _back[3]);
	swap(_front[1], _down[1]); swap(_front[3], _down[3]);
}
void Cube::rightn()
{
	swap(_right[0], _right[2]);
	swap(_right[0], _right[3]);
	swap(_right[0], _right[1]);
	swap(_front[1], _down[1]); swap(_front[3], _down[3]);
	swap(_front[1], _back[1]); swap(_front[3], _back[3]);
	swap(_front[1], _up[1]); swap(_front[3], _up[3]);
}
void Cube::frontp()
{
	swap(_front[0], _front[1]);
	swap(_front[0], _front[3]);
	swap(_front[0], _front[2]);
	swap(_up[2], _right[0]); swap(_up[3], _right[2]);
	swap(_up[2], _down[1]); swap(_up[3], _down[0]);
	swap(_up[2], _left[3]); swap(_up[3], _left[1]);
}
void Cube::frontn()
{
	swap(_front[0], _front[2]);
	swap(_front[0], _front[3]);
	swap(_front[0], _front[1]);
	swap(_up[2], _left[3]); swap(_up[3], _left[1]);
	swap(_up[2], _down[1]); swap(_up[3], _down[0]);
	swap(_up[2], _right[0]); swap(_up[3], _right[2]);
}
int Cube::rotate(int n) const
{
	Cube temp = *this;
	while (n != 0) {
		switch (n % 6)
		{
		case 1:temp.upp(); break;
		case 2:temp.upn(); break;
		case 3:temp.rightp(); break;
		case 4:temp.rightn(); break;
		case 5:temp.frontp(); break;
		default:temp.frontn(); break;
		}
		n /= 6;
	}
	return temp.calnow();
}

int main()
{
	Cube cube; cin >> cube;
	int result = 0;
	for (int i = 1; i < 7776; i++) {
		result = max(result, cube.rotate(i));
	}
	cout << result;
	return 0;
}