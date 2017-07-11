#include <iostream>
using namespace std;

int main()
{
	int a, b, c, mul, num[10] = { 0, };
	cin >> a >> b >> c;
	mul = a * b * c;
	while (mul > 0)
	{
		++num[mul % 10];
		mul /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << num[i] << endl;
	return 0;	
}