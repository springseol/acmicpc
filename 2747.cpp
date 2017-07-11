#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *DP = new int[n + 1];
	fill(DP, DP + n + 1, 0);
	DP[0] = 0, DP[1] = 1;
	for (int i = 2; i <= n; i++)
		DP[i] = DP[i - 1] + DP[i - 2];
	cout << DP[n] << endl;
	return 0;
}