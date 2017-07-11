#include <iostream>
#include <algorithm>
using namespace std;

int n, m, num = 0, ar = 0, ma = 0;
int **ary, mo[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

int check(int a, int b)
{
	++ar, ary[a][b] = 0;
	for (int i = 0; i < 4; i++)
	{
		int x = a + mo[i][0], y = b + mo[i][1];
		if (x >= 0 && x < n && y >= 0 && y < m)
			if (ary[x][y] == 1) check(x, y);
	}
	return ar;
}

int main()
{
	cin >> n >> m;
	ary = new int*[n];
	for (int i = 0; i < n; i++)
	{
		ary[i] = new int[m];
		for (int j = 0; j < m; j++) cin >> ary[i][j];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (ary[i][j] == 1)
			{
				++num;
				ma = max(ma, check(i, j));
				ar = 0;
			}
		}
	cout << num << endl << ma << endl;
	return 0;
}