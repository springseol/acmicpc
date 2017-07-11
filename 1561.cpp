#include <iostream>
using namespace std;

int main()
{
	long long n;
	int m;
	cin >> n >> m;
	int *ins = new int[m];
	long long left = 0, right = n * 30, mid, lmid = 0, lsum = 0;
	for (int i = 0; i < m; i++)
		cin >> ins[i];

	if (n <= m)
	{
		cout << n << endl;
		return 0;
	}

	while (left <= right)
	{
		mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < m; i++)
			sum += mid / ins[i] + 1;
		if (sum < n)
		{
			left = mid + 1;
			if(mid > lmid)
				lmid = mid, lsum = sum;
		}
		else right = mid - 1;
	}

	for (int i = 0; i < m; ++i)
	{
		if ((lmid + 1) % ins[i] == 0)
			++lsum;
		if (lsum == n)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	return 0;
}