#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int pins[30001], sum[30001], p[30001][501], n, b, w, i, j, t;

int go(int start, int balls)
{
    int newp = sum[start], maxp=0, i, j, nextp = 0;

	if (p[start][balls] != 0)
		return p[start][balls];

    if (balls == 0 || start >= n)
        return 0;

    newp += go(start+w, balls-1);

	nextp = go(start+1, balls);

	maxp = max(maxp, newp);
	maxp = max(maxp, nextp);

    if (sum[start] > maxp)
        maxp = sum[start];

    p[start][balls] = maxp;
	return p[start][balls];
}

int main()
{
	freopen("test.in", "r", stdin);

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

		printf("%d\n", go(0, b));
		t--;
	}

	return 0;
}