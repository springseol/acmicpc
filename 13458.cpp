#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int *a = new int[n], b, c;
	long long ans = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> b >> c;
	for (int i = 0; i < n; i++)
	{
		if(a[i] - b > 0)
			ans += (a[i] - b) / c + ((a[i] - b) % c == 0 ? 0 : 1);
		++ans;
	}
	cout << ans << endl;
	return 0;
}