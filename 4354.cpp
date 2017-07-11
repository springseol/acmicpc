#include <iostream>
#include <string>
using namespace std;

int main()
{
	string P;
	while (cin >> P)
	{
		if (P[0] == '.') break;
		int m = P.length(), *pt = new int[m], j = 0;
		fill(pt, pt + m, 0);
		for (int i = 1; i < m; i++)
		{
			while (j > 0 && P[i] != P[j])
				j = pt[j - 1];
			if (P[i] == P[j])
				pt[i] = ++j;
		}
		int la = pt[m - 1], fi = m - la;
		if (pt[m - 1] == 0) cout << "1" << endl;
		else cout << la / fi + 1 << endl;
	}
	return 0;
}