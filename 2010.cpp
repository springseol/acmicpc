#include <iostream>
using namespace std;

int main()
{
	int n, ins, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ins;
		if (i != n - 1) sum += ins - 1;
		else sum += ins;
	}
	cout << sum << endl;
	return 0;
}