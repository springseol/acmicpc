#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *num = new int[n];
	for (int i = 0; i < n; i++)
		cin >> num[i];
	sort(num, num + n);
	cout << num[n - 1] * num[0] << endl;
	return 0;
}