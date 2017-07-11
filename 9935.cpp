#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string a, b;
	vector <char> ans;
	cin >> a >> b;
	int size1 = a.size(), size2 = b.size();
	for (int i = 0; i < size1; i++)
	{
		ans.push_back(a[i]);
		int che = 0, size3 = ans.size();
		if (ans[size3 - 1] == b[size2 - 1])
		{
			++che;
			for (int j = 1; j < size2; j++)
				if (ans[size3 - 1 - j] == b[size2 - 1 - j]) ++che;
			if (che == size2)
				for (int j = 0; j < size2; j++)
					ans.pop_back();
		}
	}
	if (ans.size() <= 0)
		cout << "FRULA" << endl;
	else
	{
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i];
		cout << endl;
	}
	return 0;
}