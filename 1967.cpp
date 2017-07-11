#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;
vector < pair<int, int> > tree[MAX + 1];
int result = 0;

int DFS(int a)
{
	int max = 0, max2 = 0;
	for (int i = 0; i < tree[a].size(); i++)
	{
		int weight = DFS(tree[a][i].first) + tree[a][i].second;
		if (weight > max)
			max2 = max, max = weight;
		else if (weight > max2)
			max2 = weight;
	}
	if (result < max + max2)
		result = max + max2;
	return max;
}

int main()
{
	int n, p, c, w;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> p >> c >> w;
		tree[p].push_back(make_pair(c, w));
	}
	DFS(1);
	cout << result << endl;
	return 0;
}