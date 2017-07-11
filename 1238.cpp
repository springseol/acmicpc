#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000;

int main()
{
	int n, m, x, s, e, t, ans = 0;
	cin >> n >> m >> x;
	int **ary = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		ary[i] = new int[n + 1];
		for (int j = 0; j < n + 1; j++)
		{
			if (i == j || i == 0 || j == 0) ary[i][j] = 0;
			else ary[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e >> t;
		ary[s][e] = t;
	}
	for (int k = 1; k < n + 1; k++)
		for (int i = 1; i < n + 1; i++)
			for (int j = 1; j < n + 1; j++)
				ary[i][j] = min(ary[i][j], ary[i][k] + ary[k][j]);
	for (int i = 0; i < n + 1; i++)
		ans = max(ans, ary[i][x] + ary[x][i]);
	cout << ans << endl;
	return 0;
}