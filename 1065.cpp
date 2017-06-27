/*
1065번. 한수

어떤 양의 정수 X의 자리수가 등차수열을 이룬다면, 그 수를 한수라고 한다. 
등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. 
N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i < 100) ++ans;
		else
		{
			vector <int> ve;
			int a = i, dif = 0; 
			while (a > 0)
			{
				ve.push_back(a % 10);
				a /= 10;
			}
			dif = ve[1] - ve[0];
			for (int j = 2; j < ve.size(); j++)
			{
				if (ve[j] - ve[j - 1] != dif) break;
				else if (j == ve.size() - 1) ++ans;
			}
			ve.clear();
		}
	}
	cout << ans << endl;
	return 0;
}