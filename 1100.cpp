#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ins;
	int ans = 0;
	for (int i = 0; i < 8; i++)
	{
		cin >> ins;
		for (int j = 0; j < 8; j++)
			if ((i + j) % 2 == 0 && ins[j] == 'F') ++ans;
	}
	cout << ans << endl;
	return 0;
}