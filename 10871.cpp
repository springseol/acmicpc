#include <iostream>
using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;
	int *ins = new int[n];
	for (int i = 0; i < n; i++)
		cin >> ins[i];
	for (int i = 0; i < n; i++)
		if (ins[i] < x) cout << ins[i] << " ";
	cout << endl;
	return 0;
}