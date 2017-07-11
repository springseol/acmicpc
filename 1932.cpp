#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, ans = 0;
	cin >> n;
	int **tri = new int*[n], **DP = new int*[n];
	for (int i = 0; i < n; i++)
	{
		tri[i] = new int[n], DP[i] = new int[n];
		fill(tri[i], tri[i] + n, 0), fill(DP[i], DP[i] + n, 0);
		for (int j = 0; j <= i; j++)
			cin >> tri[i][j];
	}
	DP[0][0] = tri[0][0];
	for (int i = 1; i < n; i++)
	{
		DP[i][0] = DP[i - 1][0] + tri[i][0];
		for (int j = 1; j < i; j++)
			DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + tri[i][j];
		DP[i][i] = DP[i - 1][i - 1] + tri[i][i];
	}
	for (int i = 0; i < n; i++)
		if (ans < DP[n - 1][i])	ans = DP[n - 1][i];
	cout << ans << endl;
	return 0;
}