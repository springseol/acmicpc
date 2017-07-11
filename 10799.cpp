#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack <char> s;
	string ch;
	int sum = 0;
	cin >> ch;
	for (int i = 0; i < ch.length(); i++)
	{
		if (ch[i] == '(')
			s.push('(');
		else
		{
			s.pop();
			if (ch[i - 1] == '(')
				sum += s.size();
			else
				++sum;
		}
	}
	cout << sum << endl;
	return 0;
}