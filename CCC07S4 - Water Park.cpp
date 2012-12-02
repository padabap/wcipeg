#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int n, from, to, dist[10000];
vector <int> path[10000];

int main()
{
	//freopen("test.in", "r", stdin);

	memset(dist, 0, sizeof(dist));

	scanf("%d", &n);
	do
	{
		scanf("%d%d", &from, &to);
		path[from].push_back(to);
	}
	while
		(from != 0);

	dist[n]=1;
	for (int j=n-1; j>0; j--)
		for (int i=0; i<path[j].size(); i++)
		{
			dist[j] = dist[j] + dist[path[j][i]];
		}

	printf("%d\n", dist[1]);

	return 0;
}
