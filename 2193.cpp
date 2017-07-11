#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long **DP = new long long*[n];
	for (int i = 0; i < n; i++)
		DP[i] = new long long[2];
	DP[0][0] = 0, DP[0][1] = 1;
	for (int i = 1; i < n; i++)
	{
		DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
		DP[i][1] = DP[i - 1][0];
	}
	cout << DP[n - 1][0] + DP[n - 1][1] << endl;
	return 0;
}