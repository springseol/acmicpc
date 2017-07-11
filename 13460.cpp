#include <iostream>
#include <queue>
using namespace std;

struct point
{
	int x, y;
};

int main()
{
	queue < pair<point, point> > q;
	point r, b, o;
	int n, m, ans = 0, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, -1, 0, 1 };
	cin >> n >> m;
	char **ary = new char*[n]; int ****vis = new int***[n];
	for (int i = 0; i < n; i++)
	{
		ary[i] = new char[m]; vis[i] = new int**[m];
		for (int j = 0; j < m; j++)
		{
			cin >> ary[i][j];
			vis[i][j] = new int*[n];
			for (int k = 0; k < n; k++)
			{
				vis[i][j][k] = new int[m];
				for (int l = 0; l < m; l++) vis[i][j][k][l] = 0;
			}
			if (ary[i][j] == 'R') r.x = i, r.y = j;
			if (ary[i][j] == 'B') b.x = i, b.y = j;
			if (ary[i][j] == 'O') o.x = i, o.y = j;
		}
	}
	vis[r.x][r.y][b.x][b.y] = 1;
	q.push(make_pair(r, b));
	while (!q.empty())
	{
		int size = q.size(); ++ans;
		while (size-- > 0)
		{
			point rc, bc;
			rc.x = q.front().first.x, rc.y = q.front().first.y, bc.x = q.front().second.x, bc.y = q.front().second.y;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				point nrc, nbc;
				nrc.x = rc.x, nrc.y = rc.y, nbc.x = bc.x, nbc.y = bc.y;
				while (ary[nrc.x + dx[i]][nrc.y + dy[i]] != '#' && ary[nrc.x + dx[i]][nrc.y + dy[i]] != 'O')
					nrc.x += dx[i], nrc.y += dy[i];
				while (ary[nbc.x + dx[i]][nbc.y + dy[i]] != '#' && ary[nbc.x + dx[i]][nbc.y + dy[i]] != 'O')
					nbc.x += dx[i], nbc.y += dy[i];
				if (ary[nbc.x + dx[i]][nbc.y + dy[i]] == 'O')
					continue;
				if (nrc.x == nbc.x && nrc.y == nbc.y)
				{
					if (dx[i] > 0)
					{
						if (rc.x < bc.x) nrc.x -= 1; else if (rc.x > bc.x) nbc.x -= 1;
					}
					if (dx[i] < 0)
					{
						if (rc.x < bc.x) nbc.x += 1; else if (rc.x > bc.x) nrc.x += 1;
					}
					if (dy[i] > 0)
					{
						if (rc.y < bc.y) nrc.y -= 1; else if (rc.y > bc.y) nbc.y -= 1;
					}
					if (dy[i] < 0)
					{
						if (rc.y < bc.y) nbc.y += 1; else if (rc.y > bc.y) nrc.y += 1;
					}
				}
				if (ary[nrc.x + dx[i]][nrc.y + dy[i]] == 'O')
				{
					cout << ans << endl;
					return 0;
				}
				if (vis[nrc.x][nrc.y][nbc.x][nbc.y] != 1)
				{
					vis[nrc.x][nrc.y][nbc.x][nbc.y] = 1;
					q.push(make_pair(nrc, nbc));
				}
			}
		}
		if (ans >= 10) break;
	}
	cout << "-1" << endl;
	return 0;
}