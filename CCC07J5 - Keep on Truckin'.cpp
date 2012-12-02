#include<cstdio>
#include<cstring>
using namespace std;

int i, min, max, n, m, num=14, count=0, dist;
int motel[7050]={0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
int x[7050];

//recursion
int go(int dist)
{
	int i, count=0;
	if (x[dist] > -1)
		return x[dist];
	else
	{
		if (dist==7000)
		{
			count=1;
			x[dist] = count;
			return x[dist];
		}
		else
		{
			for (i=0; i<num; i++)
				if (motel[i] - dist >= min && motel[i] - dist <= max)
					count=count + go(motel[i]);		
			x[dist] = count;
			return x[dist];
		}
	}
}

int main()
{	
	memset(x, 0, sizeof(x));
	scanf("%d%d%d", &min, &max, &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &m);
		motel[num]=m;
		num++;
	}

	//dp based off of the recursion
	x[7000] = 1;
	for (dist=6999; dist>=0; dist--)
		for (i=0; i<num; i++)
			if (motel[i]-dist >= min && motel[i]-dist <= max)
				x[dist] = x[dist] + x[motel[i]];

	printf("%d\n", x[0]);
	return 0;
}
