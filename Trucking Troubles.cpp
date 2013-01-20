#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	//freopen("test.in", "r", stdin);
	int c, r, d, i, from, to, w, dest[10001], min_weight[10001], min;
	vector <int> graph[10001], weight[10001];
	priority_queue < pair<int, int> > Q;

	memset(min_weight, 0, sizeof(min_weight));
	scanf("%d%d%d", &c, &r, &d);
	for (i=0; i<r; i++)
	{
		scanf("%d%d%d", &from, &to, &w);
		graph[from].push_back(to);
		graph[to].push_back(from);
		weight[from].push_back(w);
		weight[to].push_back(w);
	}
	for (i=0; i<d; i++)
		scanf("%d", &dest[i]);

	Q.push(make_pair(0, 1));

	while (!Q.empty())
	{
		w = Q.top().first;
		i = Q.top().second;
		Q.pop();

		if (w <= min_weight[i])
			for (int j=0; j<graph[i].size(); j++)
				if (weight[i][j] > min_weight[graph[i][j]])
				{
					min_weight[graph[i][j]] = weight[i][j];
					Q.push(make_pair(min_weight[graph[i][j]], graph[i][j]));
				}
	}

	min = min_weight[dest[0]];
	for (i=1; i<d; i++)
		if (min_weight[dest[i]] < min)
			min = min_weight[dest[i]];

	printf("%d\n", min);
	return 0;
}