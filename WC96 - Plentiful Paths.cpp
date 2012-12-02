#include<cstdio>
#include<cstring>
using namespace std;
int a[101][101];
//go from 1, 1 to m, n

int maxi(int x, int y)
{
	if (x>y)
		return x;
	else 
		return y;
}

int main()
{
	int m, n, x, y, i, j;
	bool a[101][101];
	int dist[101][101];
	memset(a, false, sizeof(a));
	memset(dist, 0, sizeof(dist));
	//freopen("test.in", "r", stdin);
	scanf("%d%d\n", &m, &n);
	while (1)
	{
		scanf("%d%d\n", &x, &y);
		if (x==0 && y==0)
			break;
		else
			a[x][y]=true;
	}

	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
		{
			dist[i][j]=maxi(dist[i-1][j], dist[i][j-1]);
			if (a[i][j]==true)
				dist[i][j]+=1;
		}
		
	printf("%d\n", dist[m][n]);
	return 0;
}
