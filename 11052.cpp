#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *ary = new int[n], *DP = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ary[i];
		DP[i] = ary[i];
	}
	for (int i = 1; i < n; i++)
		for (int j = 0; j <= i/2; j++)
		{
			int sum = DP[j] + DP[i-j-1];
			if (DP[i] < sum) DP[i] = sum;
		}
	cout << DP[n-1] << endl;;
	return 0;
}