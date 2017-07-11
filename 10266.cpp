#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 360000;

int* prefix(int *b)
{
	int *pt = new int[MAX];
	pt[0] = 0;
	int j = 0;
	for (int i = 1; i < MAX; i++)
	{
		pt[i] = 0;
		while (j > 0 && b[i] != b[j])
			j = pt[j-1];
		if (b[i] == b[j])
			pt[i] = ++j;
	}
	return pt;
}

void kmp(int *a, int *b)
{
	int *pt = prefix(b);
	int j = 0;
	bool result = false;
	for (int i = 0; i < 2*MAX; i++)
	{
		while (j > 0 && a[i] != b[j])
			j = pt[j - 1];
		if (a[i] == b[j])
		{
			if (j == MAX - 1)
			{
				result = true;
				break;
			}
			else j++;
		}
	}
	if (result)
		cout << "possible" << endl;
	else
		cout << "impossible" << endl;
}

int main()
{
	int n, ins;
	int *a = new int[2*MAX];
	int *b = new int[MAX];
	for (int i = 0; i < 2 * MAX; i++)
	{
		a[i] = 0;
		if (i < MAX)
			b[i] = 0;
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ins;
		a[ins] = 1;
		a[ins + MAX] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> ins;
		b[ins] = 1;
	}
	kmp(a, b);
	return 0;
}