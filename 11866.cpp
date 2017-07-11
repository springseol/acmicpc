#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	queue <int> q;
	for (int i = 1; i <= n; i++) q.push(i);
	cout << "<";
	while (!q.empty())
	{
		int a = 1;
		while (a++ < m)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		q.pop();
		if (q.size() > 0) cout << ", ";
	}
	cout << ">" << endl;
	return 0;
}