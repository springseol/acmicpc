#include <iostream>
using namespace std;

int main()
{
	int val, num = 0;
	cin >> val;
	int chval = val;
	do{
		chval = (chval % 10) * 10 + (chval / 10 + chval % 10) % 10;
		num++;
	} while (val != chval);
	cout << num << endl;
	return 0;
}