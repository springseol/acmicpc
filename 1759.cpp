#include <iostream>
#include <algorithm>
using namespace std;

int l, c, *pass;

bool check()
{
	int a = 0, b = 0;
	for (int i = 0; i < c; i++)
	{
		if (pass[i] == 'a' || 'e' || 'i' || 'o' || 'u')
			++b;
		else
			++a;
	}
	if (a >= 2 && b >= 1)
		return true;
	return false;
}

void make()
{
	for (int i = 0; i < c; i)
}

int main()
{
	char *ins = new char[c];
	for (int i = 0; i < c; i++)
		cin >> ins[i];
	sort(ins, ins + c);

}