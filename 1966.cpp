#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int t, n , r;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> r;
		int *ary = new int[n], ans = 1;
		queue < pair<int, int> > q;
		for (int j = 0; j < n; j++)
		{
			cin >> ary[j];
			q.push(make_pair(j, ary[j]));
		}
		sort(ary, ary + n);
		int max = ary[n - ans];
		while(q.front().first != r || q.front().second != max)
		{
			while (q.front().second != max)
			{
				q.push(q.front());
				q.pop();
			} 
			if (q.front().first != r && q.front().second == max)
			{
				q.pop();
				++ans;
				max = ary[n - ans];
			}
		}
		cout << ans << endl;
	}
}