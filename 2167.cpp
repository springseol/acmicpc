#include <iostream>
using namespace std;

int main()
{
	int n, m, k, **ary, **inary;
	cin >> n >> m;
	ary = new int*[n];
	for (int i = 0; i < n; i++)
	{
		ary[i] = new int[m];
		for (int j = 0; j < m; j++)
			cin >> ary[i][j];
	}
	cin >> k;
	inary = new int*[k];
	for (int i = 0; i < k; i++)
	{
		inary[i] = new int[4];
		for (int j = 0; j < 4; j++)
			cin >> inary[i][j];
	}

	for (int i = 0; i < k; i++)
	{
		int sum = 0;
		for (int a = inary[i][0] - 1; a <= inary[i][2] - 1; a++)
			for (int b = inary[i][1] - 1; b <= inary[i][3] - 1; b++)
				sum += ary[a][b];
		cout << sum << endl;
	}
	return 0;
}