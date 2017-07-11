#include <iostream>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int n, *DP, *ans;
	cin >> n;
	DP = new int[n + 1], ans = new int[3];
	DP[0] = 0, DP[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		fill(ans, ans + 3, 1000000);
		if (i % 3 == 0) ans[0] = 1 + DP[i / 3];
		if (i % 2 == 0) ans[1] = 1 + DP[i / 2];
		if (i - 1 != 0) ans[2] = 1 + DP[i - 1];
		DP[i] = min(ans[0], min(ans[1], ans[2]));
	}
	cout << DP[n] << endl;
	return 0;
}