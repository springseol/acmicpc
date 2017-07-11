#include <iostream>
using namespace std;

int main()
{
	int sco[10], sum = 0;
	for (int i = 0; i < 10; i++) cin >> sco[i];
	for (int i = 0; i < 10 && sum < 100; i++)
	{
		if (sum + sco[i] > 100 && 100 - sum < (sum + sco[i]) - 100)
			break;
		sum += sco[i];
	}
	cout << sum << endl;
	return 0;
}