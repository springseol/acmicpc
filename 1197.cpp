#include <iostream>
#include <vector>
#include <queue>
#include <functional> 
using namespace std;

const int MAX = 10001;

int main()
{
	int v, e, a, b, c, ans = 0;
	vector < pair<int, int> > ve[MAX];
	priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
	cin >> v >> e;
	int *vis = new int[v + 1];
	fill(vis, vis + v + 1, 0), vis[1] = 1;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		ve[a].push_back(make_pair(b, c)), ve[b].push_back(make_pair(a, c));
		if (a == 1 || b == 1)
		{
			if (a == 1) q.push(make_pair(c, b));
			else q.push(make_pair(c, a));
		}
	}
	while (!q.empty())
	{
		pair<int, int> p = q.top();
		q.pop();
		if (vis[p.second] == 0)
		{
			vis[p.second] = 1;
			ans += p.first;
			for (int i = 0; i < ve[p.second].size(); i++)
				q.push(make_pair(ve[p.second][i].second, ve[p.second][i].first));
		}
	}
	cout << ans << endl;
	return 0;
}