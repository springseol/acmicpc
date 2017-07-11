#include <iostream>
using namespace std;

struct shark
{
	int size, speed, IQ;
};

int main()
{
	int n;
	cin >> n;
	shark *s = new shark[n];
	for (int i = 0; i < n; i++)
		cin >> s[i].size >> s[i].speed >> s[i].IQ;
	return 0;
}