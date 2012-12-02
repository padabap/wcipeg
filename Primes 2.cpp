#include<cstdio>
#include<cstring>
using namespace std;
//const int N = 1000000000, M = 1000000100;
int main()
{
		int N, M;
        int i, j;
		scanf("%d%d", &N, &M);	
        static bool a[100000000];
        memset(a, 1, sizeof(a));
        a[1]=0;
        for (i=2; i<=M/2; i++)
                if (a[i] == 1)
                        for (j=2; j<=M/i; j++)
                                a[i*j]=0;
        for (i=N; i<=M; i++)
                if (a[i])
                        printf("%d\n", i);
//        printf("\n");
        return 0;
}
