#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct line
{
	int sx, sy, ex, ey;
	int num;
};

int main()
{
	vector <line> row, col;
	int l, n, head = 0, s, ln = 0; long long len = 1;  bool check = true;
	cin >> l >> n;
	int *t = new int[n + 1], x = l, y = l, x2 = l, y2 = l; char *dir = new char[n + 1];
	for (int i = 0; i < n; i++) cin >> t[i] >> dir[i];
	t[n] = 2 * l + 1, dir[n] = dir[n - 1];
	for (int i = 0; i <= n; i++)
	{
		if (head == 0 || head == 2) s = 1; else s = -1;
		int size1 = row.size(), size2 = col.size(), last = 2 * l;
		if (head <= 1)
		{
			x2 = x + (s * t[i]), y2 = y;
			if (x > x2) swap(x, x2);
			for (int j = 0; j < size2; j++)
			{
				if (col[j].num + 1 != ln && x <= col[j].sx && x2 >= col[j].sx && col[j].sy <= y && col[j].ey >= y)
				{
					if (s == 1) last = min(last, col[j].sx - x); else last = min(last, x2 - col[j].sx);
					check = false;
				}
			}
			for (int j = 0; j < size1; j++)
				if (row[j].sy == y)
				{
					if (row[j].sx > x2 || row[j].ex < x) continue;
					else
					{
						if (s == 1) last = min(last, row[j].sx - x); else last = min(last, x2 - row[j].ex);
						check = false;
						break;
					}
				}
			if (!check)
			{
				len += last - 1;
				cout << len << endl;
				return 0;
			}
			else
			{
				if (x < 0 || x2 > 2 * l)
				{
					if (s == 1) len += 2 * l - x;
					else len += x2;
					cout << len << endl;
					return 0;
				}
				line a = { x, y, x2, y2, ln++ };
				row.push_back(a);
				len += t[i];
				if (s == 1) x = x2;
				if (head == 0) { if (dir[i] == 'L') head = 3; else head = 2; }
				else { if (dir[i] == 'L') head = 2; else head = 3; }
			}
		}
		else
		{
			x2 = x, y2 = y + (s * t[i]);
			if (y > y2) swap(y, y2);
			for (int j = 0; j < size1; j++)
			{
				if (row[j].num + 1 != ln && y <= row[j].sy && y2 >= row[j].sy && row[j].sx <= x && row[j].ex >= x)
				{
					if (s == 1) last = min(last, row[j].sy - y); else last = min(last, y2 - row[j].sy);
					check = false;
				}
			}
			for (int j = 0; j < size2; j++)
				if (col[j].sx == x)
				{
					if (col[j].sy > y2 || col[j].ey < y) continue;
					else
					{
						if (s == 1) last = min(last, col[j].sy - y); else last = min(last, y2 - col[j].ey);
						check = false;
						break;
					}
				}
			if (!check)
			{
				len += last - 1;
				cout << len << endl;
				return 0;
			}
			else
			{
				if (y < 0 || y2 > 2 * l)
				{
					if (s == 1) len += 2 * l - y;
					else len += y2;
					cout << len << endl;
					return 0;
				}
				line a = { x, y, x2, y2, ln++ };
				col.push_back(a);
				len += t[i];
				if (s == 1) y = y2;
				if (head == 2) { if (dir[i] == 'L') head = 0; else head = 1; }
				else { if (dir[i] == 'L') head = 1; else head = 0; }
			}
		}
	}
	cout << len << endl;
	return 0;
}