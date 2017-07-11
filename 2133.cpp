#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *DP = new int[n + 1];
	DP[0] = 1, DP[2] = 3;
	for (int i = 4; i <= n; i += 2)
		DP[i] = DP[2] * DP[i - 2] + 2 * DP[i - 4];
	cout << DP[n] << endl;
	return 0;
}