#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 101;

int main()
{
	vector <int> net[MAX];
	queue <int> q;
	int n, m, x, y, ans = 0;
	cin >> n >> m;
	int *com = new int[n + 1];
	fill(com, com + n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		net[x].push_back(y), net[y].push_back(x);
	}
	q.push(1);
	com[1] = 1;
	while (!q.empty())
	{
		int a = q.front(), size = net[a].size();
		q.pop();
		for (int i = 0; i < size; i++)
			if (com[net[a][i]] == 0)
			{
				com[net[a][i]] = 1;
				++ans;
				q.push(net[a][i]);
			}
	}
	cout << ans << endl;
	return 0;
}