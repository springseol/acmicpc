#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, ans = 0;
	cin >> n;
	int *rope = new int[n];
	for (int i = 0; i < n; i++) cin >> rope[i];
	sort(rope, rope + n);
	for (int i = 0; i < n; i++)
		ans = max(ans, rope[i] * (n - i));
	cout << ans << endl;
	return 0;
}