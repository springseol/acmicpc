#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, c, ans;
	cin >> n >> c;
	int *x = new int[n];
	for (int i = 0; i < n; i++) cin >> x[i];
	sort(x, x + n);
	int left = 1, right = x[n - 1] - x[0];
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int check = 1, put = x[0];
		for (int i = 0; i < n; i++)
			if (x[i] - put >= mid)
			{
				++check;
				put = x[i];
			}
		if (check >= c)
			ans = mid, left = mid + 1;
		else right = mid - 1;
	}
	cout << ans << endl;
	return 0;
}