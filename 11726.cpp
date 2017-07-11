#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long *DP = new long long[n + 1], res = 0;
	DP[0] = 1, DP[1] = 1;
	for (int i = 2; i <= n; i++)
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
	cout << DP[n] << endl;
	return 0;
}