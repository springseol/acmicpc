#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 10000;
vector <int> ve[MAX + 1];
bool *vis;

void DFS(int v)
{
	cout << v << " ";
	vis[v] = true;
	for (int i = 0; i < ve[v].size(); i++)
		if (!vis[ve[v][i]])	DFS(ve[v][i]);
}

void BFS(int v)
{
	queue <int> q;
	q.push(v);
	vis[v] = true;
	while (!q.empty())
	{
		int w = q.front();
		q.pop();
		cout << w << " ";
		for (int i = 0; i < ve[w].size(); i++)
			if (!vis[ve[w][i]])
			{
				q.push(ve[w][i]);
				vis[ve[w][i]] = true;
			}
	}
}

int main()
{
	int n, m, v, s, e;
	cin >> n >> m >> v;
	vis = new bool[n + 1];
	fill(vis, vis + n + 1, false);
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		ve[s].push_back(e);
		ve[e].push_back(s);
	}
	for (int i = 1; i < MAX + 1; i++)
		sort(ve[i].begin(), ve[i].end());
	DFS(v);
	cout << endl;
	fill(vis, vis + n + 1, false);
	BFS(v);
	cout << endl;
	return 0;
}