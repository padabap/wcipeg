#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct state
	{
		int x, y, dist;
	};

int main()
{
	int r, c, x, y, dist, t;
	char grid[25][25];
	bool vis[25][25], done;
	state pos;
	queue <state> Q;

scanf("%d", &t);
for (int z=0; z<t; z++)
{
	done = false;
	memset(grid, 0, sizeof(grid));
	memset(vis, 0, sizeof(vis));

	scanf("%d%d", &r, &c);

	for (int i=1; i<=r; i++)
	{
		scanf("\n");
		for (int j=1; j<=c; j++)
			scanf("%c", &grid[i][j]);		
	}

	pos.x = 1;
	pos.y = 1;
	pos.dist = 0;
	Q.push(pos);
	vis[pos.x][pos.y] = true;

	while (!Q.empty())
	{
		x = Q.front().x;
		y = Q.front().y;
		dist = Q.front().dist;
		Q.pop();

		if (x==r && y==c && grid[x][y]!='*')
		{
			printf("%d\n", dist+1);
			done = true;
			break;
		}
		else
		{
			if (grid[x][y] == '|')
			{
				if (vis[x+1][y] == false)
				{
					pos.x = x+1;
					pos.y = y;
					pos.dist = dist+1;
					Q.push(pos);
					vis[x+1][y] = true;
				}

				if (vis[x-1][y] == false)
				{
					pos.x = x-1;
					pos.y = y;
					pos.dist = dist+1;
					Q.push(pos);
					vis[x-1][y] = true;
				}
			}
			else if (grid[x][y] == '-')
			{
				if (vis[x][y+1] == false)
				{
					pos.x = x;
					pos.y = y+1;
					pos.dist = dist+1;
					Q.push(pos);
					vis[x][y+1] = true;
				}

				if (vis[x][y-1] == false)
				{
					pos.x = x;
					pos.y = y-1;
					pos.dist = dist+1;
					Q.push(pos);
					vis[x][y-1] = true;
				}
			}
			else if (grid[x][y] == '+')
			{
				if (vis[x+1][y] == false)
				{
					pos.x = x+1;
					pos.y = y;
					pos.dist = dist+1;
					Q.push(pos);
					vis[x+1][y] = true;
				}

				if (vis[x-1][y] == false)
				{
					pos.x = x-1;
					pos.y = y;
					pos.dist = dist+1;
					Q.push(pos);
					vis[x-1][y] = true;
				}

				if (vis[x][y+1] == false)
				{
					pos.x = x;
					pos.y = y+1;
					pos.dist = dist+1;
					Q.push(pos);
					vis[x][y+1] = true;
				}

				if (vis[x][y-1] == false)
				{
					pos.x = x;
					pos.y = y-1;
					pos.dist = dist+1;
					Q.push(pos);
					vis[x][y-1] = true;
				}
			}
		}
	}

	if (done == false)
		printf("-1\n");

}

	return 0;
}
