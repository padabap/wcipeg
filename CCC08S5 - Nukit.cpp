#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	bool derp[31][31][31][31];
	memset(derp, false, sizeof(derp)); //Roland goes first, no particles = he loses
	//freopen("test.in", "r", stdin);
	int t, i, j, k, l, a, b, c, d;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);

		for (i=0; i<=a; i++)
			for (j=0; j<=b; j++)
				for (k=0; k<=c; k++)
					for (l=0; l<=d; l++)
					{
						if (i>1 && j>0 && l>1 && derp[i-2][j-1][k][l-2]==0)
							derp[i][j][k][l]=1;
						else if (i>0 && j>0 && k>0 && l>0 && derp[i-1][j-1][k-1][l-1]==0)
							derp[i][j][k][l]=1;
						else if (k>1 && l>0 && derp[i][j][k-2][l-1]==0)
							derp[i][j][k][l]=1;
						else if (j>2 && derp[i][j-3][k][l]==0)
							derp[i][j][k][l]=1;
						else if (i>0 && l>0 && derp[i-1][j][k][l-1]==0)
							derp[i][j][k][l]=1;
					}


		if (derp[a][b][c][d]==true)
			printf("Patrick\n");
		else
			printf("Roland\n");

	}
	return 0;
}
