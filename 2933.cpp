#include <iostream>
using namespace std;

int R, C, N, *SH, cmove[4][2] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
char **ary;

void DFS(int a, int b)
{
	bool **visited = new bool*[R];
	for (int i = 0; i < R; i++)
	{
		visited[i] = new bool[C];
		for (int j = 0; j < C; j++)
			visited[i][j] = false;
	}
	visited[a][b] = true;
	for (int i = 0; i < 4; i++)
	{
		int x = a + cmove[i][0], y = b + cmove[i][1];
		if (x >= 0 && x < R && y >= 0 && y < C)
			if (ary[x][y] == 'x' && !visited[x][y])
			{
				int j;
				for (j = y; j >= 0; j--)
					if (ary[x][j] == 'x')
						break;
				cout << x << " " << j << endl;
				ary[x][y] = '.', ary[x][j + 1] = 'x';
				visited[x][y] = true;
				DFS(x, y);
			}
	}
}

int main()
{
	cin >> R >> C;
	ary = new char*[R];
	for (int i = 0; i < R; i++)
	{
		ary[i] = new char[C];
		for (int j = 0; j < C; j++)
			cin >> ary[i][j];
	}
	cin >> N; 
	SH = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> SH[i];
		int j;
		if (i % 2 == 0)
			for (j = 0; ary[8-SH[i]][j] != 'x'; j++);
		else
			for (j = C - 1; ary[8-SH[i]][j] != 'x'; j--);
		DFS(8-SH[i], j);
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << ary[i][j] << " ";
		cout << endl;
	}
	return 0;
}