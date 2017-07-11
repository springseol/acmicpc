#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ary[100][100], sum = 0, rec = 0;
int mov[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
vector <int> ans;

void check(int i, int j)
{
	if (ary[i][j] == 0)
	{
		ary[i][j] = 1;
		++sum;
		for (int k = 0; k < 4; k++)
			if (i + mov[k][0] >= 0 && j + mov[k][1] >= 0 && i + mov[k][0] < n && j + mov[k][1] < m)
			{
				++rec;
				check(i + mov[k][0], j + mov[k][1]);
				--rec;
			}
		if (rec == 0)
			ans.push_back(sum), sum = 0;
	}
}

int main()
{
	int k, lx, ly, rx, ry;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> lx >> ly >> rx >> ry;
		for (int x = lx; x < rx; x++)
			for (int y = ly; y < ry; y++)
				ary[x][y] = 1;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			check(i, j);
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}