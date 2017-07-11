#include <iostream>
using namespace std;

int main()
{
	int day, cnum[5], ans = 0;
	cin >> day;
	for (int i = 0; i < 5; i++)
	{
		cin >> cnum[i];
		if (cnum[i] == day) ++ans;
	}
	cout << ans << endl;
	return 0;
}