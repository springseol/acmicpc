/*
10844��. ���� ��� ��

45656�̶� ���� ����.
�� ���� ������ ��� �ڸ����� ���̰� 1�� ����. �̷� ���� ��� ����� �Ѵ�.
�����̴� ���� ���̰� N�� ��� ���� �� �� �ִ��� �ñ�������.
N�� �־��� ��, ���̰� N�� ��� ���� �� �� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. (0���� �����ϴ� ���� ����.)
*/

/*
Ǯ�� ��� : ���̳��� ���α׷����� �̿��Ͽ� ����
*/

#include <iostream>
using namespace std;

const long long mod = 1000000000;

int main()
{
	int n;
	cin >> n;
	long long **DP = new long long*[n], ans = 0;
	for (int i = 0; i < n; i++)
	{
		DP[i] = new long long[10];
		for (int j = 0; j < 10; j++)
		{
			DP[i][j] = 0;
			if (i == 0 && j > 0) DP[i][j] = 1;
			else if (i != 0)
			{
				if (j - 1 >= 0) DP[i][j] += DP[i - 1][j - 1];
				if (j + 1 < 10) DP[i][j] += DP[i - 1][j + 1];
				DP[i][j] %= mod;
			}
		}
	}
	for (int i = 0; i < 10; i++) ans += DP[n - 1][i];
	cout << ans % mod << endl;
	return 0;
}