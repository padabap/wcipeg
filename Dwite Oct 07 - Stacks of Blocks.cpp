#include<cstdio>
#include<cstring>
using namespace std;

long long h, s, block[11], num, minnum[101][1024], used[11];

int min(int a, int b)
{
	if (a<b)
		return a;
	else
		return b;
}

long long power(int a, int b)
{
        long long sum=1;
        if (b==0)
                return 1;
        else if (b==1)
                return a;
        else
            for (int i=1; i<=b; i++)
                sum=sum*a;
		return sum;
}

int to_binary(long long dec)
{
	int bin=0;
	
	for (int i=0; i<s; i++)
	{
		bin = bin + (dec%10)*power(2, i);
		dec=dec/10;
	}

	return bin;
}

int go(int total, long long used[11])
{
	int num=99;
	long long num_int=0;

	for (int j=0; j<s; j++)
		num_int = num_int + used[j]* power(10, s-j+1);
	num_int = to_binary(num_int);

	if (minnum[total][num_int] != -1)
		return minnum[total][num_int];

	else
	{
		if (total==0)
			return 0;
		else
		{
			for (int i=0; i<s; i++)
				if (used[i]==0)
					if (total-block[i] >= 0)
					{
						used[i]=1;
						num = min(num, go(total-block[i], used)+1);							
						
						used[i]=0;
					}

			minnum[total][num_int]=num;
			return minnum[total][num_int];
		}
	}

}

int main()
{
	memset(used, 0, sizeof(used));
	memset(minnum, -1, sizeof(minnum));
	scanf("%d%d", &h, &s);
	for (int i=0; i<s; i++)
		scanf("%d", &block[i]);
	
	num=go(h, used);

	if (num==99)
		printf("0\n");
	else
		printf("%d\n", num);
	return 0;
}
