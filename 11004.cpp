#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int *ary = new int[n];
	for (int i = 0; i < n; i++) cin >> ary[i];
	nth_element(ary, ary + k, ary + n);
	cout << ary[k - 1] << endl;
	return 0;
}