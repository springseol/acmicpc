/*
1076번. 저항

전자 제품에는 저항이 들어간다. 저항은 색 3개를 이용해서 그 저항이 몇 옴인지 나타낸다.
처음 색 2개는 저항의 값이고, 마지막 색은 곱해야 하는 값이다.
저항의 값은 다음 표를 이용해서 구한다.

색		값	곱
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
예를 들어, 저항에 색이 yellow, violet, red였다면 저항의 값은 4,700이 된다.
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