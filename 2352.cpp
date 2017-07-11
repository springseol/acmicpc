#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, size = 1, lb, ans = 0;
	cin >> n;
	int *ins = new int[n + 1], *DP = new int[n + 1];
	for (int i = 1; i <= n; i++) cin >> ins[i];
	DP[1] = ins[1];
	for (int i = 2; i <= n; i++)
	{
		if (DP[size] < ins[i])
		{
			size++;
			DP[size] = ins[i];
		}
		lb = lower_bound(DP + 1, DP + size + 1, ins[i]) - DP;
		
		DP[lb] = ins[i];
		cout << lb << " " << DP[lb] << endl;

	}
	cout << size << endl;
	return 0;
}