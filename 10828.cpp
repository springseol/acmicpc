#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	int n, p;
	string ins;
	stack <int> s;
	cin >> n;
	while (n-- > 0)
	{
		cin >> ins;
		if (ins == "push")
		{
			cin >> p;
			s.push(p);
		}
		else if (ins == "pop")
		{
			if (s.empty())
				cout << "-1" << endl;
			else
			{
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (ins == "size")
			cout << s.size() << endl;
		else if (ins == "empty")
		{
			if (s.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else
		{
			if (s.empty())
				cout << "-1" << endl;
			else
				cout << s.top() << endl;
		}
	}
	return 0;
}