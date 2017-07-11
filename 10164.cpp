#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, l, k, ans = 1;
	cin >> n >> m >> k;
	if (k == 0) k = 1;
	l = max(k, n*m - k + 1);
	int *DP = new int[l + 1];
	DP[0] = 1, DP[1] = 1;
	for (int i = 2; i <= l; i++)
	{
		if (i - m <= 0)
			DP[i] = DP[i - 1];
		else if ((i - 1) % m == 0)
			DP[i] = DP[i % m];
		else
			DP[i] = DP[i - 1] + DP[i - m];
	}
	cout << DP[k] * DP[n*m - k + 1] << endl;
	return 0;
}