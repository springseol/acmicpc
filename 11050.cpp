#include <iostream>
using namespace std;

int main()
{
	int n, k, ans = 1;
	cin >> n >> k;
	for (int i = n; i > n - k; i--)
		ans *= i;
	for (int i = 1; i <= k; i++)
		ans /= i;
	cout << ans << endl;
	return 0;
}