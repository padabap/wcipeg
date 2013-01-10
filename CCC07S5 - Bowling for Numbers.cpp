#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int pins[30001], sum[30001], p[30001][501], n, b, w, i, j, t;

int main()
{
	//freopen("test.in", "r", stdin);

	scanf("%d", &t);
	while (t>0)
	{
		memset(pins, 0, sizeof(pins));
		memset(sum, 0, sizeof(sum));
		memset(p, 0, sizeof(p));
		scanf("%d%d%d", &n, &b, &w);
		for (i=0; i<n; i++)
			scanf("%d", &pins[i]);

		for (j=0; j<n; j++)
			for (i=j; i<min(j+w, n); i++)
				sum[j] += pins[i];

		for (int start=n-1; start>=0; start--)
			for (int balls=1; balls<=b; balls++)
			{				
				int newp = sum[start], maxp=0, nextp = 0;

				newp += p[min(start+w, n)][balls-1];
				nextp = p[min(start+1, n)][balls];

				maxp = max(maxp, newp);
				maxp = max(maxp, nextp);

				p[start][balls] = maxp;
			}

		printf("%d\n", p[0][b]);
		t--;
	}

	return 0;
}