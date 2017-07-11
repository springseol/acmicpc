#include <iostream>
#include <algorithm>
using namespace std;

int n, res = 0, **a, **c, **c1, **c2, **c3, **c4;

void move1()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int k = j + 1;
			while (k < n && a[i][k] == 0) ++k;
			if (k >= n) continue;
			if (a[i][j] == 0) a[i][j] = a[i][k], a[i][k] = 0, --j;
			else
			{
				if (a[i][j] == a[i][k]) a[i][j] *= 2, a[i][k] = 0;
				else
				{
					int l = j + 1;
					while (a[i][l] != 0 && l < k) ++l;
					if (l >= k) continue;
					a[i][l] = a[i][k], a[i][k] = 0;
				}
			}

		}
}

void move2()
{
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j >= 0; j--)
		{
			int k = j - 1;
			while (k >= 0 && a[i][k] == 0) --k;
			if (k < 0) continue;
			if (a[i][j] == 0) a[i][j] = a[i][k], a[i][k] = 0, ++j;
			else
			{
				if (a[i][j] == a[i][k]) a[i][j] *= 2, a[i][k] = 0;
				else
				{
					int l = j - 1;
					while (a[i][l] != 0 && l < k) --l;
					if (l <= k) continue;
					a[i][l] = a[i][k], a[i][k] = 0;
				}
			}

		}
}

void move3()
{
	for (int j = 0; j < n; j++)
		for (int i = 0; i < n; i++)
		{
			int k = i + 1;
			while (k < n && a[k][j] == 0) ++k;
			if (k >= n) continue;
			if (a[i][j] == 0) a[i][j] = a[k][j], a[k][j] = 0, --i;
			else
			{
				if (a[i][j] == a[k][j]) a[i][j] *= 2, a[k][j] = 0;
				else
				{
					int l = i + 1;
					while (a[l][j] != 0 && l < k) ++l;
					if (l >= k) continue;
					a[l][j] = a[k][j], a[k][j] = 0;
				}
			}

		}
}

void move4()
{
	for (int j = 0; j < n; j++)
		for (int i = n - 1; i >= 0; i--)
		{
			int k = i - 1;
			while (k >= 0 && a[k][j] == 0) --k;
			if (k < 0) continue;
			if (a[i][j] == 0) a[i][j] = a[k][j], a[k][j] = 0, ++i;
			else
			{
				if (a[i][j] == a[k][j]) a[i][j] *= 2, a[k][j] = 0;
				else
				{
					int l = i - 1;
					while (a[l][j] != 0 && l < k) --l;
					if (l <= k) continue;
					a[l][j] = a[k][j], a[k][j] = 0;
				}
			}

		}
}
void copy(int count)
{
	switch (count)
	{
	case 0:
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				c[i][j] = a[i][j];
		break;
	case 1:
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				c1[i][j] = a[i][j];
		break;
	case 2:
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				c2[i][j] = a[i][j];
		break;
	case 3:
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				c3[i][j] = a[i][j];
		break;
	case 4:
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				c4[i][j] = a[i][j];
		break;
	}
}

void paste(int count)
{
	switch (count)
	{
	case 0:
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = c[i][j];
		break;
	case 1:
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = c1[i][j];
		break;
	case 2:
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = c2[i][j];
		break;
	case 3:
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = c3[i][j];
		break;
	case 4:
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = c4[i][j];
		break;
	}

}

int rec(int count)
{
	if (count == 5)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				res = max(res, a[i][j]);
		return res;
	}
	paste(count);
	move1();
	copy(count + 1);
	rec(count + 1);

	paste(count);
	move2();
	copy(count + 1);
	rec(count + 1);

	paste(count);
	move3();
	copy(count + 1);
	rec(count + 1);

	paste(count);
	move4();
	copy(count + 1);
	rec(count + 1);

	return res;
}

int main()
{
	cin >> n;
	a = new int*[n], c = new int*[n], c1 = new int*[n], c2 = new int*[n], c3 = new int*[n], c4 = new int*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n], c[i] = new int[n], c1[i] = new int[n], c2[i] = new int[n], c3[i] = new int[n], c4[i] = new int[n];
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}
	copy(0);
	rec(0);
	cout << res << endl;
	return 0;
}