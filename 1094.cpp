#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, sum = 64;
	cin >> n;
	vector <int> ans;
	ans.push_back(64);
	int size = ans.size();
	while (sum != n)
	{
		size = ans.size();
		int mid = ans[size - 1] / 2;
		sum -= mid;
		ans[size - 1] = mid;
		if (sum < n) sum += mid, ans.push_back(mid);
	}
	cout << size << endl;
	return 0;
}