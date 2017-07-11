#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x, y, w, h, res;
	cin >> x >> y >> w >> h;
	res = min(min(x, y), min(w - x, h - y));
	cout << res << endl;
	return 0;
}