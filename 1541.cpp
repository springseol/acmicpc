#include <iostream>
#include <string>
using namespace std;

int calculate(char *str)
{
	int sum = 0;
	char *ptr2, *p;
	ptr2 = strtok_s(str, "+-", &p);
	sum += atoi(ptr2);
	while (ptr2 = strtok_s(NULL, "+-", &p))
		sum += atoi(ptr2);
	return sum;
}

int main()
{
	int sum = 0;
	char ins[51], fir[51], *ptr, *p;
	cin >> ins;

	ptr = strtok_s(ins, "-", &p);
	strcpy_s(fir, sizeof(fir), ptr);
	ptr = strtok_s(NULL, "", &p);
	sum = calculate(fir);

	if (ptr != NULL)
		sum -= calculate(ptr);
	
	cout << sum << endl;
	return 0;
}