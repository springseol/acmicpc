#include <iostream>
using namespace std;

int n, m;
char **ary, che[2][2] = { { 'B', 'W' }, { 'W', 'B' } };

int check(int a, int b)
{
	int res[2] = { 0, 0 };
	for (int i = a; i < a + 8; i++)
		for (int j = b; j < b + 8; j++)
			for (int k = 0; k < 2; k++)
			{
				if (i % 2 == j % 2 && ary[i][j] != che[k][0]) ++res[k];
				else if (i % 2 != j % 2 && ary[i][j] != che[k][1]) ++res[k];
			}
	return res[0] < res[1] ? res[0] : res[1];
}

int main()
{
	int min = 1000, ans;
	cin >> n >> m;
	ary = new char*[n];
	for (int i = 0; i < n; i++)
	{
		ary[i] = new char[m];
		for (int j = 0; j < m; j++)
			cin >> ary[i][j];
	}
	for (int i = 0; i < n - 8 + 1; i++)
		for (int j = 0; j < m - 8 + 1; j++)
		{
			ans = check(i, j);
			if (min > ans) min = ans;
		}
	cout << min << endl;
	return 0;
}