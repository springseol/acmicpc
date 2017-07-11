#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, ans;
	cin >> n;
	int *ins = new int[n], *DP = new int[n];
	for (int i = 0; i < n; i++) cin >> ins[i];
	DP[0] = ins[0], ans = ins[0];
	for (int i = 1; i < n; i++)
	{
		DP[i] = max(DP[i - 1] + ins[i], ins[i]);
		ans = max(DP[i], ans);
	}
	cout << ans << endl;
	return 0;
}