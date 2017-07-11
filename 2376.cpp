#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1001;

int main()
{
	queue <int> q;
	vector <int> parent[MAX];
	int n, par, *ins, *depth, start, end;
	cin >> n;
	par = n, ins = new int[n], depth = new int[n + 1];
	fill(depth, depth + n + 1, 0);
	for (int i = 1; i < n; i++)
	{
		cin >> ins[i];
		if ((ins[i] - depth[i] - depth[i + 1]) == 2)
			q.push(i), ins[i] = 0;
	}
	cin >> start >> end;
	while (!q.empty())
	{
		++par;
		int a = q.front();
		q.pop();
		for (int i = 0; i < 2; i++)
		{
			int size = parent[a + i].size();
			if (size > 0)
			{
				int node = parent[a + i][size - 1];
				for (int j = 1; j <= n; j++)
					for (int k = 0; k < parent[j].size(); k++)
						if (parent[j][k] == node && j != a + i)
						{
							parent[j].push_back(par);
							++depth[j];
						}
			}
			parent[a + i].push_back(par);
			++depth[a + i];
		}
		for (int i = 1; i <= n; i++)
			if ((ins[i] - depth[i] - depth[i + 1]) == 2)
				q.push(i), ins[i] = 0;
	}
	for (int i = 0; i < parent[start].size(); i++)
		for (int j = 0; j < parent[end].size(); j++)
			if (parent[start][i] == parent[end][j])
			{
				cout << i + j + 2 << endl;
				return 0;
			}
	return 0;
}