/*
1065��. �Ѽ�

� ���� ���� X�� �ڸ����� ���������� �̷�ٸ�, �� ���� �Ѽ���� �Ѵ�. 
���������� ���ӵ� �� ���� ���� ���̰� ������ ������ ���Ѵ�. 
N�� �־����� ��, 1���� ũ�ų� ����, N���� �۰ų� ���� �Ѽ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
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