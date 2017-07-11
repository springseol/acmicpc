#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int n, j = 0;
	cin >> n;
	int *ary = new int[n];
	stack <int> s;
	string ans;
	for (int i = 0; i < n; i++) cin >> ary[i];
	for (int i = 1; i <= n; i++)
	{
		s.push(i);
		ans += "+\n";
		while (!s.empty() && s.top() == ary[j] && j < n)
		{
			ans += "-\n"; ++j;
			s.pop();
		}
	}
	if (s.empty()) cout << ans;
	else cout << "NO" << endl;
	return 0;
}
