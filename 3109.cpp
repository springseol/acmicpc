#include <iostream>
using namespace std;

int r, c, mov[3] = { -1, 0, 1 }, sum = 0;
char **ins;

int back(int a, int b)
{
	ins[a][b] = 'v';
	for (int i = 0; i < 3; i++)
	{
		int x = a + mov[i], y = b + 1;
		if (x >= 0 && x < r && y < c)
			if (ins[x][y] == '.')
				if (back(x, y)) return 1;
	}
	if (b == c - 1)
		return 1;
	return 0;
}

int main()
{
	cin >> r >> c;
	ins = new char*[r];
	for (int i = 0; i < r; i++)
	{
		ins[i] = new char[c];
		for (int j = 0; j < c; j++)
			cin >> ins[i][j];
	}
	for (int i = 0; i < r; i++)
		sum += back(i, 0);
	cout << sum << endl;
}