#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, sum = 0;
	cin >> n;
	int *A = new int[n], *B = new int[n];
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];
	sort(A, A + n), sort(B, B + n);
	for (int i = 0; i < n; i++)
		sum += A[i] * B[n - 1 - i];
	cout << sum << endl;
	return 0;
}