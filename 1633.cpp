#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first > a.second)
	{
		if (b.first > b.second) 
		{
			if (a.first > b.first) return true; 
			else if (a.first == b.first) { if (a.second > b.second) return true; }
		}
		else 
		{ 
			if (a.first > b.second) return true; 
			else if (a.first == b.second) { if (a.second > b.first) return true; }
		}
	}
	else
	{
		if (b.first > b.second) 
		{
			if (a.second > b.first) return true; 
			else if (a.second == b.first) { if (a.first > b.second) return true; }
		}
		else 
		{
			if (a.second > b.second) return true;
			else if (a.second == b.second) { if (a.first > b.first) return true; }
		}
	}
	return false;
}

bool cmp1(pair<int, int> a, pair<int, int> b)
{
	if (a.first > b.first) return true;
	return false;
}

bool cmp2(pair<int, int> a, pair<int, int> b)
{
	if (a.second > b.second) return true;
	return false;
}

int main()
{
	int w, b, nw = 0, nb = 0, sum = 0;
	vector < pair<int, int> > player;
	while (cin >> w >> b) player.push_back(make_pair(w, b));
	stable_sort(player.begin(), player.end(), cmp);
	while (1)
	{
		if (player[0].first > player[0].second) sum += player[0].first, ++nw;
		else sum += player[0].second, ++nb;
		player.erase(player.begin());
		if (nw == 15 || nb == 15) break;
	}
	if (nw != 15)
	{
		stable_sort(player.begin(), player.end(), cmp1);
		while (nw != 15)
		{
			sum += player[0].first, ++nw;
			player.erase(player.begin());
		}
	}
	if (nb != 15)
	{
		stable_sort(player.begin(), player.end(), cmp2);
		while (nb != 15)
		{
			sum += player[0].second, ++nb;
			player.erase(player.begin());
		}
	}
	cout << sum << endl;
	return 0;
}