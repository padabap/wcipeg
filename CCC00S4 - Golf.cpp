#include<cstdio>
#include<cstring>
using namespace std;

int total, clubs, i, length[33], min=99999, a[5281], j;
int main()
{
	//freopen("test.in", "r", stdin);
	scanf("%d%d", &total, &clubs);
	for (i=0; i<clubs; i++)
		scanf("%d", &length[i]);

	for (i=1; i<=total; i++)
		a[i]=99999;
	a[0] = 0;

	for (j=1; j<=total; j++)
		for (i=0; i<clubs; i++)
			if (j-length[i] >= 0)
				if (a[j-length[i]]+1 < a[j] )
					a[j] = a[j-length[i]]+1;

	if (a[total]==99999)
		printf("Roberta acknowledges defeat.");
	else
		printf("Roberta wins in %d strokes.\n", a[total]);

	return 0;
}
