/*
2293번. 동전1

n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다.
이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 
그 경우의 수를 구하시오. (각각의 동전은 몇 개라도 사용할 수 있다.)
*/

/*
풀이 방법 : 다이나믹 프로그래밍을 이용하여 구현
*/

#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int *pri = new int[n], *DP = new int[k + 1];
	for (int i = 0; i <= k; i++) DP[i] = 0;
	DP[0] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> pri[i];
		for (int j = pri[i]; j <= k; j++)
			DP[j] += DP[j - pri[i]];
	}
	cout << DP[k] << endl;
	return 0;
}