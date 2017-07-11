#include <iostream>
using namespace std;
int main()
{
	int a, b, res = 0, max = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> a >> b;
		res = res - a + b;
		max = max > res ? max : res;
	}
	cout << max << endl;
}