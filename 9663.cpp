#include <iostream>
#include <cstdlib>
using namespace std;

int n, res = 0, *ary;

bool check(int a)
{
	for (int i = 0; i < a; i++)
		if (ary[a] == ary[i] || a - i == abs(ary[a] - ary[i]))
			return false;
	return true;
}

void nqueen(int a)
{
	if (a == n - 1)
	{
		++res;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		ary[a + 1] = i;
		if (check(a + 1)) nqueen(a + 1);
	}
}

int main()
{
	cin >> n;
	ary = new int[n];
	nqueen(-1);
	cout << res << endl;
	return 0;
}