#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector <int> mins, plus;
	int n, ins, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ins;
		if (ins > 0) plus.push_back(ins);
		else mins.push_back(ins);
	}
	sort(mins.begin(), mins.end()), sort(plus.begin(), plus.end());
	int size1 = mins.size(), size2 = plus.size();
	for (int i = 0; i < size1; i++)
		if (i < size1 - 1) ans += mins[i] * mins[i + 1], i += 1;
		else ans += mins[i];
	for (int i = size2 - 1; i >= 0; i--)
		if (i > 0) ans += max(plus[i] * plus[i - 1], plus[i] + plus[i - 1]), i -= 1;
		else ans += plus[i];
	cout << ans << endl;
	return 0;
}