/*
2293��. ����1

n���� ������ ������ �ִ�. ������ ������ ��Ÿ���� ��ġ�� �ٸ���.
�� �������� ������ ����ؼ�, �� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�. 
�� ����� ���� ���Ͻÿ�. (������ ������ �� ���� ����� �� �ִ�.)
*/

/*
Ǯ�� ��� : ���̳��� ���α׷����� �̿��Ͽ� ����
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