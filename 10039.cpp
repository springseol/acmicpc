#include <iostream>
using namespace std;

int main()
{
	int sco[5], sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> sco[i];
		if (sco[i] > 40) sum += sco[i];
		else sum += 40;
	}
	cout << sum / 5 << endl;
	return 0;
}