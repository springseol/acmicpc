#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m, *ary1, *ary2;

bool binary(int x, int left, int right)
{
	if (left > right)
		return false;
	else
	{
		int mid = (left + right) / 2;
		if (x == ary1[mid])
			return true;
		else if (x < ary1[mid])
			return binary(x, left, mid - 1);
		else
			return binary(x, mid + 1, right);
	}
}

int main()
{
	scanf("%d", &n);
	ary1 = new int[n];
	for (int i = 0; i < n; i++) scanf("%d", &ary1[i]);
	sort(ary1, ary1 + n);
	scanf("%d", &m);
	ary2 = new int[m];
	for (int i = 0; i < m; i++) scanf("%d", &ary2[i]);
	for (int i = 0; i < m; i++)
	{
		if (ary2[i] < ary1[0] || ary2[i] > ary1[n - 1])
			printf("0 ");
		else
		{
			if (binary(ary2[i], 0, n - 1))
				printf("1 ");
			else
				printf("0 ");
		}
	}
	return 0;
}