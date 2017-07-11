#include <iostream>
using namespace std;
const int INF = 100000;

void prim(int n, int **W)
{
	int i, vnear, min, *near = new int[n + 1], *dis = new int[n + 1], sum = 0;
	for (i = 1; i <= n; i++)
	{
		near[i] = 1;
		dis[i] = W[1][i];
	}
	for (int j = 0; j <= n - 2; j++)
	{
		min = INF;
		for (i = 2; i <= n; i++)
			if (0 <= dis[i] && dis[i] < min)
			{
				min = dis[i];
				vnear = i;
			}
		sum += min;
		dis[vnear] = -1;

		for (i = 2; i <= n; i++)
			if (W[i][vnear] < dis[i])
			{
				dis[i] = W[i][vnear];
				near[i] = vnear;
			}
	}
	cout << sum << endl;
}

int main()
{
	int n, m, **ary, a, b, c;
	cin >> n >> m;
	ary = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		ary[i] = new int[n + 1];
		fill(ary[i], ary[i] + n + 1, INF);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		ary[a][b] = c, ary[b][a] = c;
	}
	prim(n, ary);
	return 0;
}