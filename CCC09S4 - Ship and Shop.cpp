#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	int i, cities, routes, from, to, stores, cost, dest, dist[5001] = {0}, d, j;
	vector <int> graph[5001], weight[5001];
	priority_queue < pair<int, int> > Q;

	scanf("%d\n%d\n", &cities, &routes);
	for (i=0; i<routes; i++)
	{
		scanf("%d%d%d", &from, &to, &d);
		graph[from].push_back(to);
		graph[to].push_back(from);
		weight[from].push_back(d);
		weight[to].push_back(d);
	}
	scanf("%d", &stores);
	for (i=0; i<stores; i++)
	{
		scanf("%d%d", &to, &cost);
		graph[0].push_back(to);
		weight[0].push_back(cost);
	}
	scanf("%d", &dest);

	for (i=1; i<=cities; i++)
		dist[i] = 999999999;
	Q.push(make_pair(0, 0));

	while (!Q.empty())
	{
		d = Q.top().first * -1;
		i = Q.top().second;
		Q.pop();

		if (d<=dist[i])
			for (j=0; j<graph[i].size(); j++)
				if (d + weight[i][j] < dist[graph[i][j]])
				{
					dist[graph[i][j]] = d + weight[i][j];
					Q.push( make_pair(dist[graph[i][j]] * -1, graph[i][j]) );
				}
	}
	printf("%d\n", dist[dest]);

	return 0;
	
}
