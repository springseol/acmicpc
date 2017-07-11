#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *sco = new int[n], **DP = new int*[n];
	for (int i = 0; i < n; i++)
	{
		cin >> sco[i];
		DP[i] = new int[2];
	}
	DP[0][0] = sco[0], DP[0][1] = sco[0];
	DP[1][0] = sco[0] + sco[1], DP[1][1] = sco[1];
	for (int i = 2; i < n; i++)
	{
		DP[i][0] = DP[i - 1][1] + sco[i];
		DP[i][1] = max(DP[i - 2][0], DP[i - 2][1]) + sco[i];
	}
	cout << max(DP[n - 1][0], DP[n - 1][1]) << endl;
	return 0;
}