#include <iostream>
using namespace std;

int main()
{
	int n, ins, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ins;
		for (int i = 2; i <= ins; ++i)
		{
			if (i == ins) ++res;
			if (ins % i == 0) break;
		}
	}
	cout << res << endl;
	return 0;
}