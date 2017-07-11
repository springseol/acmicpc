#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 100000000;

int main()
{
	int n, **ary, m, x, y, z, *len, vnear;
	bool *visited;
	cin >> n >> m;
	ary = new int*[n + 1], len = new int[n + 1], visited = new bool[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		ary[i] = new int[n + 1];
		fill(ary[i], ary[i] + n + 1, INF);
		ary[i][i] = 0;
		fill(visited, visited + n + 1, false);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> z;
		if (ary[x][y] > z)
			ary[x][y] = z;
	}
	cin >> x >> y;
	for (int i = 1; i < n + 1; i++)
		len[i] = ary[x][i];
	visited[x] = true;

	for (int k = 1; k < n; k++)
	{
		int min = INF;
		for (int j = 1; j < n + 1; j++)
			if (visited[j] == false && min > len[j])
			{
				min = len[j];
				vnear = j;
			}
		visited[vnear] = true;
		for (int j = 1; j < n + 1; j++)
			if (ary[vnear][j] != INF)
				len[j] = (len[j] < len[vnear] + ary[vnear][j]) ? len[j] : len[vnear] + ary[vnear][j];
	}

	cout << len[y] << endl;
	return 0;
}