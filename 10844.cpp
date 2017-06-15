/*
10844번. 쉬운 계단 수

45656이란 수를 보자.
이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.
세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.
N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)
*/

/*
풀이 방법 : 다이나믹 프로그래밍을 이용하여 구현
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