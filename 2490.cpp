#include <iostream>
using namespace std;

int main()
{
	int ins[3][4], num[3] = { 0, };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			cin >> ins[i][j];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			if (ins[i][j] == 0) ++num[i];
		if (num[i] == 1) cout << "A" << endl;
		else if (num[i] == 2) cout << "B" << endl;
		else if (num[i] == 3) cout << "C" << endl;
		else if (num[i] == 4) cout << "D" << endl;
		else cout << "E" << endl;
	}
	return 0;
}