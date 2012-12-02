#include<cstdio>
using namespace std;

char grid[51][51], update[51][51];

int count(int x, int y) //returns num of live neighbours
{
	int num = 0;
	int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dy[8] = {-1, 1, 0, -1, 1, -1, 1, 0};

	for (int i=0; i<8; i++)
		if (grid[x+dx[i]][y+dy[i]] == 'X')
			num++;
	return num;
}

int main()
{
	int r, c, i, j, num=0, gen;
	scanf("%d%d", &r, &c);
	for (i=1; i<=r; i++)
	{
		scanf("\n");
		for (j=1; j<=c; j++)
			scanf("%c", &grid[i][j]);
	}

for (gen=1; gen<=100; gen++)
{
	for (i=1; i<=r; i++)
		for (j=1; j<=c; j++)
		{
			if (grid[i][j] == '.')
			{
				if (count(i, j) == 3)
					update[i][j] = 'X';
				else
					update[i][j] = '.';
			}
			else
			{
				if (count(i, j) == 2 || count(i, j) == 3)
					update[i][j] = 'X';
				else
					update[i][j] = '.';
			}
		}

	num=0;
	for (i=1; i<=r; i++)
		for (j=1; j<=c; j++)
		{
			grid[i][j] = update[i][j];
			if (update[i][j] == 'X')
				num++;
		}

	if (gen == 1 || gen == 5 || gen == 10 || gen == 50 || gen == 100)
		printf("%d\n", num);
	
}
	return 0;
}
