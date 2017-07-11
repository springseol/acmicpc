#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int *n = new int[t], *m = new int[t], **pri = new int*[t];
	for (int i = 0; i < t; i++)
	{
		cin >> n[i];
		pri[i] = new int[n[i]];
		for (int j = 0; j < n[i]; j++) cin >> pri[i][j];
		cin >> m[i];
	}
	for (int i = 0; i < t; i++)
	{
		int *DP = new int[m[i] + 1];
		fill(DP, DP + m[i] + 1, 0), DP[0] = 1;
		for (int j = 0; j < n[i]; j++)
			for (int k = pri[i][j]; k < m[i] + 1; k++)
				DP[k] += DP[k - pri[i][j]];
		cout << DP[m[i]] << endl;
		delete[]DP;
	}
	return 0;
}