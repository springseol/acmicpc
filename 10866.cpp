#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	int n; string ins;
	deque <int> de;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ins;
		int x;
		if (ins == "push_front")
		{
			cin >> x;
			de.push_front(x);
		}
		else if (ins == "push_back")
		{
			cin >> x;
			de.push_back(x);
		}
		else if (ins == "pop_front")
		{
			if (de.empty()) cout << "-1" << endl;
			else
			{
				cout << de.front() << endl;
				de.pop_front();
			}
		}
		else if (ins == "pop_back")
		{
			if (de.empty()) cout << "-1" << endl;
			else
			{
				cout << de.back() << endl;
				de.pop_back();
			}
		}
		else if (ins == "size")
			cout << de.size() << endl;
		else if (ins == "empty")
		{
			if (de.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else if (ins == "front")
		{
			if (de.empty()) cout << "-1" << endl;
			else cout << de.front() << endl;
		}
		else
		{
			if (de.empty()) cout << "-1" << endl;
			else cout << de.back() << endl;
		}
	}
	return 0;
}