#include <iostream>
using namespace std;

int main()
{
	int T, max = 0;
	cin >> T;
	int *ins = new int[T];
	for (int i = 0; i < T; i++)
	{
		cin >> ins[i];
		if (ins[i] > max) max = ins[i];
	}
	int *DP = new int[max + 1];
	DP[1] = 1, DP[2] = 2, DP[3] = 4;
	for (int i = 4; i <= max; i++)
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
	for (int i = 0; i < T; i++)
		cout << DP[ins[i]] << endl;
	return 0;
}