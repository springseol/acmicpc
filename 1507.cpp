#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, sum = 0, ans = 0;
	cin >> n;
	int **ary = new int*[n];
	for (int i = 0; i < n; i++)
	{
		ary[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> ary[i][j];
			sum += ary[i][j];
		}
	}
	for (int i = n - 1; i >= 0; i--)
		for (int k = n - 1; k >= 0; k--)
			for (int j = n - 1; j >= 0; j--)
				if (i != k && k != j && ary[i][j] == ary[i][k] + ary[k][j])
					ary[i][j] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			ans += ary[i][j];
	}
	if (sum > ans)
		cout << ans / 2 << endl;
	else
		cout << "-1" << endl;
	return 0;
}