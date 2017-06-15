/*
1076��. ����

���� ��ǰ���� ������ ����. ������ �� 3���� �̿��ؼ� �� ������ �� ������ ��Ÿ����.
ó�� �� 2���� ������ ���̰�, ������ ���� ���ؾ� �ϴ� ���̴�.
������ ���� ���� ǥ�� �̿��ؼ� ���Ѵ�.

��		��	��
black	0	1
brown	1	10
red	2	100
orange	3	1000
yellow	4	10000
green	5	100000
blue	6	1000000
violet	7	10000000
grey	8	100000000
white	9	1000000000
���� ���, ���׿� ���� yellow, violet, red���ٸ� ������ ���� 4,700�� �ȴ�.
*/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

const string color[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };

int main()
{
	long long ans = 0;
	string ins;
	for (int i = 0; i < 3; i++)
	{
		cin >> ins;
		for (int j = 0; j < 10; j++)
			if (!ins.compare(color[j]))
			{
				if (i == 0) ans += 10 * j;
				else if (i == 1) ans += j;
				else ans *= pow(10, j);
			}
	}
	cout << ans << endl;
	return 0;
}