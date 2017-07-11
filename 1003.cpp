#include <iostream>
using namespace std;

struct DP
{
	int val, zero, one;
};

DP dp[41];

DP fibonacci(int n)
{
	dp[0].val = 0, dp[0].zero = 1, dp[0].one = 0; 
	dp[1].val = 1, dp[1].zero = 0, dp[1].one = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i].val = dp[i - 1].val + dp[i - 2].val;
		dp[i].zero = dp[i - 1].zero + dp[i - 2].zero;
		dp[i].one = dp[i - 1].one + dp[i - 2].one;
	}
	return dp[n];
}

int main()
{
	int T, *ins;
	DP *res;
	cin >> T;
	ins = new int[T], res = new DP[T];
	for (int i = 0; i < T; i++)
	{
		cin >> ins[i];
		res[i] = fibonacci(ins[i]);
	}
	for (int i = 0; i < T; i++)
		cout << res[i].zero << " " << res[i].one << endl;
	return 0;
}