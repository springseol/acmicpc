#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50;
vector <int> chi[MAX];
int  del, ans = 0;

void BFS(int n)
{
	int size = chi[n].size();
	if (size == 0) ++ans;
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (chi[n][i] != del) BFS(chi[n][i]);
			else if (size - 1 == 0) ++ans;
		}
	}
}

int main()
{
	int n, par, root;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> par;
		if(par != -1) chi[par].push_back(i);
		else root = i;
	}
	cin >> del;
	if(del != root) BFS(root);
	cout << ans << endl;
	return 0;
}