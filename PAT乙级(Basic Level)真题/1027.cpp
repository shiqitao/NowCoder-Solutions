#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	getline(cin, str, '.'); int pGalleon = atoi(str.c_str());
	getline(cin, str, '.'); int pSickle = atoi(str.c_str());
	getline(cin, str, ' '); int pKnut = atoi(str.c_str());
	getline(cin, str, '.'); int aGalleon = atoi(str.c_str());
	getline(cin, str, '.'); int aSickle = atoi(str.c_str());
	getline(cin, str); int aKnut = atoi(str.c_str());
	int pMoney = pGalleon * 17 * 29 + pSickle * 29 + pKnut;
	int aMoney = aGalleon * 17 * 29 + aSickle * 29 + aKnut;
	if (aMoney >= pMoney) {
		int galleon = (aMoney - pMoney) / (17 * 29);
		int sickle = (aMoney - pMoney - galleon * 17 * 29) / 29;
		int knut = (aMoney - pMoney) % 29;
		cout << galleon << "." << sickle << "." << knut;
	}
	else {
		int galleon = (pMoney - aMoney) / (17 * 29);
		int sickle = (pMoney - aMoney - galleon * 17 * 29) / 29;
		int knut = (pMoney - aMoney) % 29;
		cout << "-" << galleon << "." << sickle << "." << knut;
	}
	return 0;
}