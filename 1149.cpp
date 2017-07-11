#include <iostream>
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int n, **ins, **DP;
	cin >> n;
	ins = new int*[n], DP = new int*[n];
	for (int i = 0; i < n; i++)
	{
		ins[i] = new int[3], DP[i] = new int[3];
		for (int j = 0; j < 3; j++)
		{
			cin >> ins[i][j];
			if (i == 0)
				DP[i][j] = ins[i][j];
		}
	}
	for (int i = 1; i < n; i++)
	{
		DP[i][0] = ins[i][0] + min(DP[i - 1][1], DP[i - 1][2]);
		DP[i][1] = ins[i][1] + min(DP[i - 1][0], DP[i - 1][2]);
		DP[i][2] = ins[i][2] + min(DP[i - 1][0], DP[i - 1][1]);
	}
	cout << min(DP[n - 1][0], min(DP[n - 1][1], DP[n - 1][2])) << endl;
	return 0;
}