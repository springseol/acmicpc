#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct meeting { int start, end; };
bool cmp(const meeting &a, const meeting &b)
{
	if (a.end < b.end)
		return true;
	else if(a.end == b.end)
		if(a.start < b.start)
			return true;
	return false;
}

int main()
{
	int n, max = 0, lend = 0;
	cin >> n;
	vector <meeting> meet(n);
	for (int i = 0; i < n; i++)
		cin >> meet[i].start >> meet[i].end;
	stable_sort(meet.begin(), meet.end(), cmp);
	for (int i = 0; i < n; i++)
		if (lend <= meet[i].start)
		{
			lend = meet[i].end;
			++max;
		}
	cout << max << endl;
	return 0;
}