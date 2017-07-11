#include <iostream>
using namespace std;

int **ary, res[3] = { 0 };

void cut(int x, int y, int size)
{
	bool check = true;
	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
			if (ary[x][y] != ary[i][j])
			{
				check = false;
				break;
			}
	if (!check)
	{
		size /= 3;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				cut(x + size*i, y + size*j, size);
	}
	else
	{
		if (ary[x][y] == -1) ++res[0];
		else if (ary[x][y] == 0) ++res[1];
		else ++res[2];
	}
}

int main()
{
	int n;
	cin >> n;
	ary = new int*[n];
	for (int i = 0; i < n; i++)
	{
		ary[i] = new int[n];
		for (int j = 0; j < n; j++) cin >> ary[i][j];
	}
	cut(0, 0, n);

	for (int i = 0; i < 3; i++)
		cout << res[i] << endl;
	return 0;
}