#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
	if (p1.second != p2.second) return p1.second < p2.second;
	return p1.first < p2.first;
}

int main()
{
	int n, val;
	vector< pair<int, int> > ve;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		ve.push_back(make_pair(i, val));
	}
	sort(ve.begin(), ve.end(), cmp);
	for (int i = 0; i < n; i++)
		ve[i].second = ve[i].first, ve[i].first = i;
	sort(ve.begin(), ve.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << ve[i].first << " ";
	return 0;
}