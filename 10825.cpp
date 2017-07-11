#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
struct grade
{
	char name[10];
	int kor;
	int eng;
	int math;
};

void swap(grade *a, grade *b)
{
	grade *temp; 
	temp = a;
	a = b;
	b = temp;
}

void namesort(grade *c)
{
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n - i; j++)
			if (strcmp(c[j].name, c[j - 1].name) < 0)
				swap(c[j], c[j - 1]);		
}

void mathsort(grade *c)
{
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n - i; j++)
			if (c[j].math > c[j - 1].math)
				swap(c[j], c[j - 1]);
}

void engsort(grade *c)
{
	for (int i = 0; i < n - i; i++)
		for (int j = 1; j < n; j++)
			if (c[j].eng < c[j - 1].eng)
				swap(c[j], c[j - 1]);
}

void korsort(grade *c)
{
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n - i; j++)
			if (c[j].kor > c[j - 1].kor)
				swap(c[j], c[j - 1]);
}

int main()
{
	cin >> n;
	grade *cla = new grade[n];
	for (int i = 0; i < n; i++)
		cin >> cla[i].name >> cla[i].kor >> cla[i].eng >> cla[i].math;
	namesort(cla);
	mathsort(cla);
	engsort(cla);
	korsort(cla);
	for (int i = 0; i < n; i++)
		cout << cla[i].name << endl;

	return 0;
}