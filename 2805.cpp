#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long n, m, ans;
	cin >> n >> m;
	long long *h = new long long[n];
	for (int i = 0; i < n; i++) cin >> h[i];
	sort(h, h + n);
	long long left = 0, right = h[n - 1];
	while (left <= right)
	{
		long long mid = (left + right) / 2, sum = 0;
		for (int i = 0; i < n; i++)
			if (h[i] - mid > 0) sum += h[i] - mid;
		if (sum == m)
		{
			ans = mid;
			break;
		}
		else if (sum > m)
			left = mid + 1, ans = mid;
		else right = mid - 1;
	}
	cout << ans << endl;
	return 0;
}