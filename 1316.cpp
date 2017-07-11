#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, ans = 0, ary[26] = { 0, };
	string ins;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ins;
		bool check = true;
		++ary[ins[0] - 'a'];
		for (int j = 1; j < ins.length(); j++)
		{
			if (ary[ins[j] - 'a'] > 0 && ins[j - 1] != ins[j])
				check = false;
			else ++ary[ins[j] - 'a'];
		}
		if (check) ++ans;
		for (int j = 0; j < 26; j++) ary[j] = 0;
	}
	cout << ans << endl;
	return 0;
}