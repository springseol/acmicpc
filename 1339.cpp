#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int square(int a)
{
	if (a > 0) return 10 * square(a - 1);
	else return 1;
}

bool compare(const pair<int, int> &p1, const pair<int, int> &p2)
{
	if (p1.second > p2.second) return true;
	else return false;
}

int main()
{
 	int n, num = 9, sum = 0;
	vector < pair<int, int> > ch;
	cin >> n;
	string st;
	for (int i = 0; i < n; i++)
	{
		cin >> st;
		int len = st.length();
		for (int j = 0; j < len; j++)
		{
			int size = ch.size(), dif = 0;
			for (int k = 0; k < size; k++)
			{
				if (st[j] != ch[k].first) ++dif;
				else ch[k].second += square(len - 1 - j);
			}
			if (dif == size)
				ch.push_back(make_pair(st[j], square(len - 1 - j)));
		}
	}
	sort(ch.begin(), ch.end(), compare);
	for (int i = 0; i < ch.size(); i++)
		sum += ch[i].second * (num--);
	cout << sum << endl;
	return 0;
}