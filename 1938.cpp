#include <iostream>
#include <queue>
using namespace std;

struct wood
{
	int x, y, dir, ans;
};

int n, ans = 0, d2[2] = { -1, 1 }, d3[3] = { -1, 0, 1 }, **vis, **vis1;
char **ary;
queue <wood> q;

bool check(wood b, int cn)
{
	int s = 1;
	if (cn == 1 || cn == 3) s = -1;
	for (int i = 0; i < 3; i++)
	{
		if (cn == 0)
		{
			for (int j = 0; j < 2; j++)
			{
				if (b.dir == 0)
				{
					if (vis1[b.x][b.y] == 1 || b.x + d2[j] < 0 || b.x + d2[j] >= n) return false;
					if (ary[b.x + d2[j]][b.y + d3[i]] == '1') return false;
				}
				else
				{
					if (vis[b.x][b.y] == 1 || b.y + d2[j] < 0 || b.y + d2[j] >= n) return false;
					if (ary[b.x + d3[i]][b.y + d2[j]] == '1') return false;
				}
			}
		}
		else if (cn == 1 || cn == 2)	//UP, DOWN
		{
			if (b.dir == 0)
			{
				if (b.x + s < 0 || b.x + s >= n || vis[b.x + s][b.y] == 1) return false;
				if (ary[b.x + s][b.y + d3[i]] == '1') return false;
			}
			else
			{
				if (b.x + (2 * s) < 0 || b.x + (2 * s) >= n || vis1[b.x + s][b.y] == 1) return false;
				if (ary[b.x + (2 * s)][b.y] == '1') return false;
			}
		}
		else	//LEFT, RIGHT
		{
			if (b.dir == 0)
			{
				if (b.y + (2 * s) < 0 || b.y + (2 * s) >= n || vis[b.x][b.y + s] == 1) return false;
				if (ary[b.x][b.y + (2 * s)] == '1') return false;
			}
			else
			{
				if (b.y + s < 0 || b.y + s >= n || vis1[b.x][b.y + s] == 1) return false;
				if (ary[b.x + d3[i]][b.y + s] == '1') return false;
			}
		}
	}
	return true;
}

int main()
{
	wood b, e;
	int c1 = 0, c2 = 0;
	cin >> n;
	ary = new char*[n], vis = new int*[n], vis1 = new int*[n];
	for (int i = 0; i < n; i++)
	{
		ary[i] = new char[n]; vis[i] = new int[n]; vis1[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> ary[i][j];
			vis[i][j] = 0, vis1[i][j] = 0;
			if (ary[i][j] == 'B')
			{
				++c1;
				if (c1 == 2) b.dir = ((i - b.x) == 0) ? 0 : 1;
				if (c1 < 3) b.x = i, b.y = j;
			}
			if (ary[i][j] == 'E')
			{
				++c2;
				if (c2 == 2) e.dir = ((i - e.x) == 0) ? 0 : 1;
				if (c2 < 3) e.x = i, e.y = j;
			}
		}
	}
	b.ans = 0;
	q.push(b);
	while (!q.empty())
	{
		wood s;
		s.x = q.front().x, s.y = q.front().y, s.dir = q.front().dir, s.ans = q.front().ans;
		q.pop();
		if (s.x == e.x && s.y == e.y && s.dir == e.dir)
		{
			cout << s.ans << endl;
			return 0;
		}
		if (s.dir == 0) vis[s.x][s.y] = 1;
		else vis1[s.x][s.y] = 1;
		if (s.dir != e.dir && check(s, 0))
		{
			s.dir ^= 1; ++s.ans; q.push(s); s.dir ^= 1; --s.ans;
		}
		if (check(s, 1))
		{
			--s.x; ++s.ans; q.push(s); ++s.x; --s.ans;
		}
		if (check(s, 2))
		{
			++s.x; ++s.ans; q.push(s); --s.x; --s.ans;
		}
		if (check(s, 3))
		{
			--s.y; ++s.ans; q.push(s); ++s.y; --s.ans;
		}
		if (check(s, 4))
		{
			++s.y; ++s.ans; q.push(s); --s.y; --s.ans;
		}
	}
	cout << "0" << endl;
	return 0;
}