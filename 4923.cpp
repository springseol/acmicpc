#include <iostream>
#include <memory.h>
using namespace std;

int w, h, ary[50][50];
int mox[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }, moy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

void check(int a, int b)
{
	ary[a][b] = 0;
	for (int k = 0; k < 8; k++)
	{
		int c = a + mox[k], d = b + moy[k];
		if (c >= 0 && c < h && d >= 0 && d < w)
			if (ary[c][d] == 1)	check(c, d);
	}
}

int main()
{
	for (cin >> w >> h; w != 0 && h != 0; cin >> w >> h)
	{
		memset(ary, 0, sizeof(ary));
		int num = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) cin >> ary[i][j];
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (ary[i][j] == 1)
				{
					check(i, j);
					++num;
				}
		cout << num << endl;
	}
	return 0;
}