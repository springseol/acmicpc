#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	a = "0" + a, b = "0" + b;
	int an = a.length(), bn = b.length();
	int **lca = new int*[an];
	lca[0] = new int[bn];
	fill(lca[0], lca[0] + bn, 0);
	for (int i = 1; i < an; i++)
	{
		lca[i] = new int[bn];
		lca[i][0] = 0;
		for (int j = 1; j < bn; j++)
		{
			if (a[i] == b[j])
				lca[i][j] = lca[i - 1][j - 1] + 1;
			else
				lca[i][j] =lca[i - 1][j] > lca[i][j - 1] ? lca[i - 1][j] : lca[i][j - 1];
		}
	}
	cout << lca[an - 1][bn - 1] << endl;
	return 0;
}