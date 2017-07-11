#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, ans = 0, sum = 0;
	cin >> n;
	int *ins = new int[n];;
	for (int i = 0; i < n; i++)
	{
		cin >> ins[i];
		ans = max(ans, ins[i]), sum += ins[i];
	}
	cin >> m;
	int left = 0, right = ans, mid;
	if (sum <= m)
	{
		cout << ans << endl;
		return 0;
	}
	while (left <= right)
	{
		sum = 0, mid = (left + right) / 2;
		for (int i = 0; i < n; i++)
		{
			if (mid < ins[i]) sum += mid;
			else sum += ins[i];
		}
		if (sum <= m)
		{
			ans = mid;
			left = mid + 1;
			if (sum == m) break;
		}
		else
			right = mid - 1;
	}
	cout << ans << endl;
	return 0;
}