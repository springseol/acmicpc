#include <iostream>
using namespace std;

int main()
{
	int n, k, ans = 0;
	cin >> n >> k;
	int *A = new int[n];
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = n - 1; i >= 0; i--) ans += k / A[i], k %= A[i];
	cout << ans << endl;
	return 0;
}