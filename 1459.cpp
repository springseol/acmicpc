#include <iostream>
using namespace std;

int main()
{
	long long x, y, sum = 0;
	int w, s;
	cin >> x >> y >> w >> s;
	if (w * 2 <= s)
		sum = (x + y) * w;
	else
	{
		if (x < y) { long long temp = x; x = y; y = temp; }

		if (w < s)
			sum = y * s + (x - y) * w;
		else
		{
			if ((x - y) % 2 != 0)
				sum = (x - 1) * s + w;
			else
				sum = x * s;
		}
	}
	cout << sum << endl;
	return 0;
}