#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, xy[8][2] = { { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 } };
	int same = 0;
	string *ary, cary;
	cin >> n;
	ary = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ary[i];
		if (i == 0)
			cary = ary[i];
	}
	int len = ary[0].length(), ans = len;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < len; j++)
		{
			same = 0;
			for (int k = 0; k < 8; k++)
			{
				if (i + xy[k][0] >= 0 && i + xy[k][0] < n
					&& j + xy[k][1] >= 0 && j + xy[k][1] < len)
					if (ary[i][j] == ary[i + xy[k][0]][j + xy[k][1]])
						k = 8, same = 1;
			}
			if (same == 0)
			{
				for (int a = 0; a < len; a++)
					if (ary[i][j] == cary[a])
						--ans;
			}
		}
	cout << ans << endl;
	return 0;
}