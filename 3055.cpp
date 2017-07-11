#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 2501;
queue < pair<int, int> > q;
char **map; int r, c, **ary, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 }, res = INF;

struct hedgehog
{ int x, y, time; }h; 

void water()
{
	int num = 0;
	while (!q.empty())
	{
		int size = q.size(); ++num;
		while (size > 0)
		{
			int x = q.front().first, y = q.front().second;
			q.pop(); --size;
			for (int i = 0; i < 4; i++)
			{
				int x2 = x + dx[i], y2 = y + dy[i];
				if (x2 >= 0 && x2 < r && y2 >= 0 && y2 < c)
					if (map[x2][y2] == '.' && ary[x2][y2] == INF)
					{ ary[x2][y2] = num; q.push(make_pair(x2, y2));	}
			}
		}
	}
}

int move(hedgehog h)
{
	for (int i = 0; i < 4; i++)
	{
		int x = h.x, y = h.y, x2 = x + dx[i], y2 = y + dy[i];
		if (x2 >= 0 && x2 < r && y2 >= 0 && y2 < c)
		{
			if (map[x2][y2] == 'D') res = min(res, ++h.time);
			else if (map[x2][y2] == '.' && ary[x2][y2] > h.time + 1)
			{
				ary[x2][y2] = ++h.time;
				h = { x2, y2, h.time };
				move(h);
				h = { x, y, --h.time };
			}
		}
	}
	return res;
}

int main()
{
	cin >> r >> c;
	ary = new int*[r]; map = new char*[r];
	for (int i = 0; i < r; i++)
	{
		ary[i] = new int[c], map[i] = new char[c];
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			ary[i][j] = INF;
			if (map[i][j] == '*')
			{
				q.push(make_pair(i, j));
				ary[i][j] = 0;
			}
			if (map[i][j] == 'S') h = { i, j, 0 };
		}
	}
	water();
	move(h);
	if (res != INF) cout << res << endl;
	else cout << "KAKTUS" << endl;
	return 0;
}