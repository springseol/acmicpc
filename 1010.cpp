#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int **ins = new int*[T];
	for (int i = 0; i < T; i++)
	{
		ins[i] = new int[2];
		cin >> ins[i][0] >> ins[i][1];
	}
	for (int i = 0; i < T; i++)
	{
		long long ans = 1;
		for (int j = 1; j <= ins[i][0]; j++)
			ans = ans * (ins[i][1] - j + 1) / j;
		cout << ans << endl;
	}
}