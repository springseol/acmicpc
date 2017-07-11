#include <iostream>
using namespace std;

int n;
int **parent, *depth;

int adjust(int a, int b)
{
	while (depth[a] != depth[b])
		a = parent[a][depth[a]];
	return a;
}

int fparent(int a, int b)
{
	for (int i = depth[a]; i >= 0; i--)
		if (parent[a][i] != 0 && parent[a][i] == parent[b][i])
			return parent[a][i];
}

int main()
{
	int n, m, a, b, **find;
	cin >> n;
	parent = new int*[n + 1], depth = new int[n + 1];
	fill(depth, depth + n + 1, 0);
	depth[0] = -1, depth[1] = 0;
	for (int i = 0; i < n + 1; i++)
	{
		parent[i] = new int[10];
		fill(parent[i], parent[i] + 10, 0);
	}
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		if (a < b)
			parent[b][0] = a, depth[b] = depth[a] + 1;
		else
			parent[a][0] = b, depth[a] = depth[b] + 1;
	}
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < 10; j++)
			parent[i][j] = parent[parent[i][j - 1]][j - 1];

	cin >> m;
	find = new int*[m];
	for (int i = 0; i < m; i++)
	{
		find[i] = new int[2];
		fill(find[i], find[i] + 2, 0);
		cin >> a >> b;
		if (depth[a] > depth[b])
		{
			while (depth[a] != depth[b])
				a = parent[a][depth[a]];

		}
		else if (depth[a] < depth[b])
		{
			while (depth[a] != depth[b])
				b = parent[b][depth[b]];
		}
		find[i][0] = a;
		find[i][1] = b;
	}
	for (int i = 0; i < m; i++)
	{
		cout << fparent(find[i][0], find[i][1]) << endl;
	}
	return 0;
}
