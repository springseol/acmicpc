#include <iostream>
#include <string>
using namespace std;

int main()
{
	int ary[26];
	fill(ary, ary + 26, -1);
	string ins;
	cin >> ins;
	for (int i = 0; i < ins.length(); i++)
		if (ary[ins[i] - 'a'] == -1) ary[ins[i] - 'a'] = i;
	for (int i = 0; i < 26; i++)
		cout << ary[i] << " ";
	cout << endl;
	return 0;
}