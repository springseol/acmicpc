#include <iostream>
using namespace std;

int main()
{
	int n, ans = 0;
	cin >> n;
	for (int i = n / 5; i >= 0; i--)
	{
		ans = i;
		if ((n - 5 * i) % 3 == 0)
		{
			ans += (n - 5 * i) / 3;
			break;
		}
		else if (i == 0) ans = -1;
	}
	cout << ans << endl;
	return 0;
}