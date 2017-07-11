#include <iostream>
using namespace std;

const int E = 0, N = 1, W = 2, S = 3;

struct robot
{
	int rx, ry, head;
};

int main()
{
	int a, b, n, m, x, y, mr, mn; char dir;
	cin >> a >> b >> n >> m;
	robot *r = new robot[n];
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> dir;
		r[i].rx = x, r[i].ry = y;
		switch (dir)
		{
		case 'E': r[i].head = E; break;
		case 'W': r[i].head = W; break;
		case 'S': r[i].head = S; break;
		case 'N': r[i].head = N; break; 
		}
	}
	for (int i = 0; i < m; i++) 
	{
		cin >> mr >> dir >> mn;
		int lx = r[mr - 1].rx, ly = r[mr - 1].ry, lh = r[mr - 1].head, px, py;
		if (dir == 'L' || dir == 'R')
			r[mr - 1].head = (dir == 'L') ? (lh + (1 * mn)) % 4 : (lh + (3 * mn)) % 4;
		else
		{
			for (int j = 1; j <= mn; j++)
			{
				if (lh == E) px = j, py = 0;
				else if (lh == W) px = -j, py = 0;
				else if (lh == S) px = 0, py = -j;
				else px = 0, py = j;
				if (lx + px > a || lx + px < 1 || ly + py> b || ly + py < 1)
				{
					cout << "Robot " << mr << " crashes into the wall" << endl;
					return 0;
				}
				for (int k = 0; k < n; k++)
					if (r[k].rx == lx + px && r[k].ry == ly + py)
					{
						cout << "Robot " << mr << " crashes into robot " << k + 1 << endl;
						return 0;
					}
				if (j == mn) r[mr - 1].rx += px, r[mr - 1].ry += py;
			}
		}
	}
	cout << "OK" << endl;
	return 0;
}