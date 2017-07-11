#include <iostream>
using namespace std;

int n, m, x, y, k, **ary, *ord, dice[6] = { 0 }; 

void move(int c)
{
	int cdice[6];
	for (int i = 0; i < 6; i++) cdice[i] = dice[i];
	if (c == 1)
		dice[0] = cdice[4], dice[2] = cdice[0], dice[4] = cdice[5], dice[5] = cdice[2];
	else if (c == 2)
		dice[0] = cdice[2], dice[2] = cdice[5], dice[4] = cdice[0], dice[5] = cdice[4];
	else if (c == 3)
		dice[0] = cdice[3], dice[1] = cdice[0], dice[3] = cdice[5], dice[5] = cdice[1];
	else
		dice[0] = cdice[1], dice[1] = cdice[5], dice[3] = cdice[0], dice[5] = cdice[3];
}

int main()
{
	cin >> n >> m >> x >> y >> k;
	ary = new int*[n], ord = new int[k];
	for (int i = 0; i < n; i++)
	{
		ary[i] = new int[m];
		for (int j = 0; j < m; j++)
			cin >> ary[i][j];
	}
	for (int i = 0; i < k; i++)	cin >> ord[i];
	for (int i = 0; i < k; i++)
	{
		int s = 1; bool check = true;
		if (ord[i] == 2 || ord[i] == 3) s = -1;
		if (ord[i] == 1 || ord[i] == 2)
		{
			y += s;
			if (y < 0 || y >= m) y -= s, check = false;
		}
		if (ord[i] == 3 || ord[i] == 4)
		{
			x += s;
			if (x < 0 || x >= n) x -= s, check = false;
		}
		if (check)
		{
			move(ord[i]);
			if (ary[x][y] == 0) ary[x][y] = dice[5];
			else dice[5] = ary[x][y], ary[x][y] = 0;
			cout << dice[0] << endl;
		}
	}
	return 0;
}