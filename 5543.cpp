#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int bur[3], dri[2], bmin = 2001, dmin = 2001;
	for (int i = 0; i < 3; i++)
	{
		cin >> bur[i];
		bmin = min(bmin, bur[i]);
	}
	for (int i = 0; i < 2; i++)
	{
		cin >> dri[i];
		dmin = min(dmin, dri[i]);
	}
	cout << bmin + dmin - 50 << endl;
	return 0;
}