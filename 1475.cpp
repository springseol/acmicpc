/*
1475��. �� ��ȣ

�ټ��̴� �������� ������ ���� �̻�Դ�. 
�ټ��̴� �ڱ� �� ��ȣ�� ���� �ö�ƽ ���ڷ� ���� ���̷��� �Ѵ�.
�ټ����� ���������� �ö�ƽ ���ڸ� �� ��Ʈ�� �Ǵ�. �� ��Ʈ���� 0������ 9������ ���ڰ� �ϳ��� ����ִ�.
�ټ����� �� ��ȣ�� �־����� ��, �ʿ��� ��Ʈ�� ������ �ּҰ��� ����Ͻÿ�. (6�� 9�� ����� �̿��� �� �ְ�, 9�� 6�� ����� �̿��� �� �ִ�.)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, num[10] = { 0, }, rest, ans = 0;
	cin >> n;
	while (n > 0)
	{
		rest = n % 10;
		if (rest == 6 || rest == 9)
		{
			if (num[6] > num[9]) ++num[9];
			else ++num[6];
		}
		else
			++num[rest];
		n /= 10;
	}
	for (int i = 0; i < 10; i++)
		ans = max(ans, num[i]);
	cout << ans << endl;
	return 0;
}