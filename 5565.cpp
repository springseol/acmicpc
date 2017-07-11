#include <iostream>
using namespace std;

int main()
{
	int sum, pri;
	cin >> sum;
	for (int i = 0; i < 9; i++)
	{
		cin >> pri;
		sum -= pri;
	}
	cout << sum << endl;
	return 0;

}