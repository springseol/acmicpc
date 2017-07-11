#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string ins;
	queue <int> q;
	for (int i = 0; i < n; i++)
	{
		cin >> ins;
		if (ins == "push")
		{
			int x;
			cin >> x;
			q.push(x);
		}
		else if (ins == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << endl;
				q.pop();
			}
			else cout << "-1" << endl;
		}
		else if (ins == "size")
			cout << q.size() << endl;
		else if (ins == "empty")
		{
			if (q.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else if (ins == "front")
		{
			if (!q.empty()) cout << q.front() << endl;
			else cout << "-1" << endl;
		}
		else
		{
			if (!q.empty()) cout << q.back() << endl;
			else cout << "-1" << endl;
		}
	}
	return 0;
}