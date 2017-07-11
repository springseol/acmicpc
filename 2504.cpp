#include <iostream>
#include <stack>
#include <string>
using namespace std;

string ins;
stack <char> s;

int cal(int i, int val)
{
	if (ins[i] == '(' || ins[i] == '[')
	{
		s.push(ins[i]);
		if (ins[i + 1] == '(')
			return 2 * cal(i + 1, val);
		else
			return 3 * cal(i + 1, val);
	}
	else
	{
		if (ins[i] == ')')
			return 2;
		else
			return 3;
	}
	if (i < ins.length())
		cal(i++, val);
	return val;
}

int main()
{
	int ans = 0, i = 0;

	cin >> ins;
	for (i = 0; i < ins.length(); i++)
	{
		if (ins[i] == '(' || ins[i] == '[')
			s.push(ins[i]);
		else if (!s.empty())
		{
			

		}
		else
		{
			ans = 0;
			break;
		}
	}
	cout << ans << endl;
}