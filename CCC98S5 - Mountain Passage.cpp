#include<cstdio>
#include<queue>
using namespace std;

struct triple
{
	int x, y, d;
};

bool operator<(const triple &a, const triple &b)
{
	return (a.d > b.d);
}

int main()
{
	int i, j, trips, n, graph[26][26], x, y, d;
	bool visited[26][26], done;
	triple pos;

//	freopen("test.in", "r", stdin);
	scanf("%d\n", &trips);
	
	while (trips--)
	{
		done = false;
		memset(visited, 0, sizeof(visited));

		priority_queue < triple > Q;
		
		scanf("%d\n", &n);
		for (i=1; i<=n; i++)
			for (j=1; j<=n; j++)
				scanf("%d\n", &graph[i][j]);

		pos.x = 1;
		pos.y = 1;
		pos.d = 0;
		Q.push(pos);
		
		while (!Q.empty())
		{
			d = Q.top().d;
			x = Q.top().x;
			y = Q.top().y;
			Q.pop();

			if ((x==n) && (y==n))
			{
				done = true;
				printf("\n%d\n", d);
				break;
			}

			if (visited[x][y])
				continue;
			visited[x][y] = true;

			if ((x+1 <= n) && (graph[x+1][y] >= graph[x][y]-2) && (graph[x+1][y] <= graph[x][y]+2))
			{
				pos.x = x+1;
				pos.y = y;
				if (graph[x+1][y] > graph[1][1] || graph[x][y] > graph[1][1])				
					pos.d = d+1;
				else				
					pos.d = d;				
				Q.push(pos);
			}

			if ((x-1 >= 1) && (graph[x-1][y] >= graph[x][y]-2) && (graph[x-1][y] <= graph[x][y]+2))
			{
				pos.x = x-1;
				pos.y = y;
				if (graph[x-1][y] > graph[1][1] || graph[x][y] > graph[1][1])
					pos.d = d+1;
				else
					pos.d = d;
				Q.push(pos);
			}

			if ((y+1 <= n) && (graph[x][y+1] >= graph[x][y]-2) && (graph[x][y+1] <= graph[x][y]+2))
			{
				pos.x = x;
				pos.y = y+1;
				if (graph[x][y+1] > graph[1][1] || graph[x][y] > graph[1][1])				
					pos.d = d+1;
				else
					pos.d = d;
				Q.push(pos);
			}

			if ((y-1 >= 1) && (graph[x][y-1] >= graph[x][y]-2) && (graph[x][y-1] <= graph[x][y]+2))
			{
				pos.x = x;
				pos.y = y-1;
				if (graph[x][y-1] > graph[1][1] || graph[x][y] > graph[1][1])
					pos.d = d+1;
				else
					pos.d = d;
				Q.push(pos);
			}
		}

		if (!done)
			printf("\nCANNOT MAKE THE TRIP\n");
	}

	return 0;
}
