/*
1922��. ����Ʈ��

��� ������ �����Ͽ� ǥ���ϴ� ������ ������ ���� Ʈ��(Quad Tree)��� ����� �ִ�.
�� ���� ��Ÿ���� 0�� ���� ���� ��Ÿ���� 1�θ� �̷���� ����(2���� �迭)���� ���� ������ ������ �� ���� ���� ����������,
���� Ʈ�������� �̸� �����Ͽ� ������ ǥ���� �� �ִ�.
�־��� ������ ��� 0���θ� �Ǿ� ������ ���� ����� "0"�� �ǰ�, ��� 1�θ� �Ǿ� ������ ���� ����� "1"�� �ȴ�.
���� 0�� 1�� ���� ������ ��ü�� �� ���� ��Ÿ������ ���ϰ�, ���� ��, ������ ��, ���� �Ʒ�, ������ �Ʒ�, 
�̷��� 4���� �������� ������ �����ϰ� �Ǹ�, �� 4���� ������ ������ ����� ���ʴ�� ��ȣ �ȿ� ��� ǥ���Ѵ�
*/

/*
Ǯ�� ��� : ���� �������� �̿��Ͽ� ����
*/

#include <iostream>
#include <string>
using namespace std;

void quad(char **ary, int x, int y, int n)
{
	bool tf = true;
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (ary[x][y] != ary[i][j])
			{
				cout << "(";
				quad(ary, x, y, n / 2);
				quad(ary, x, y + n / 2, n / 2);
				quad(ary, x + n / 2, y, n / 2);
				quad(ary, x + n / 2, y + n / 2, n / 2);
				cout << ")";
				return;
			}
	cout << ary[x][y];
}

int main()
{
	int n;
	cin >> n;
	char **ary = new char*[n];
	string ins;
	for (int i = 0; i < n; i++)
	{
		cin >> ins;
		ary[i] = new char[n];
		for (int j = 0; j < n; j++)
			ary[i][j] = ins[j];
	}
	quad(ary, 0, 0, n);
	return 0;
}