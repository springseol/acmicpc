#include <iostream>
#include <deque>
using namespace std;

int main()
{
	int n, m, o, ans = 0;
	cin >> n >> m;
	deque <int> dq;
	for (int i = 1; i <= n; i++) dq.push_back(i);
	for (int i = 0; i < m; i++)
	{
		cin >> o;
		deque <int> lq = dq, rq = dq;
		int l = 0, r = 0;
		while (lq.front() != o)
		{
			lq.push_back(lq.front());
			lq.pop_front();
			++l;
		}
		while (rq.front() != o)
		{
			rq.push_front(rq.back());
			rq.pop_back();
			++r;
		}
		if (l > r)
			ans += r, dq = rq;
		else
			ans += l, dq = lq;
		dq.pop_front();
	}
	cout << ans << endl;
	return 0;
}