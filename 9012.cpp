#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int n; bool check = true;
	string ins;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ins;
		stack <int> s; int j = 0;
		for (j = 0; j < ins.length(); j++)
		{
			if (ins[j] == '(')
				s.push(0);
			else if (!s.empty())
				s.pop();
			else
				break;
		}
 		if (s.empty() && j == ins.length())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}