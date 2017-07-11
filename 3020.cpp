#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, h, ins1, ins2;
	cin >> n >> h;
	int ans1 = n / 2, ans2 = 0;
	int *bo = new int[h], *up = new int[h];
	fill(bo, bo + h, 0), fill(up, up + h, 0);
	for (int i = 0; i < n /2; i++)
	{
		cin >> ins1 >> ins2;
		++bo[ins1], ++up[ins2];
	}
	int *tob = new int[h + 1], *tou = new int[h + 1], *ob = new int[h + 1];
	fill(tob, tob + h + 1, 0), fill(tou, tou + h + 1, 0), fill(ob, ob + h + 1, 0);
	tob[1] = n / 2, tou[h] = n / 2;
	for (int i = 1; i < h; i++)
	{
		tob[i + 1] = tob[i] - bo[i];
		tou[h - i] = tou[h - i + 1] - up[i];
	}
	for (int i = 1; i <= h; i++)
	{
		ob[i] = tob[i] + tou[i];
		if (ans1 > ob[i]) ans1 = ob[i];
	}
	for (int i = 1; i <= h; i++)
		if (ans1 == ob[i]) ++ans2;
	cout << ans1 << " " << ans2 << endl;
	return 0;
}