//add 2 fractions and reduce it
#include<cstdio>
using namespace std;

int gcd(int a, int b)
{
	if (a != 0 && b != 0)
	{
		if (a > b)
			return gcd(a % b, b);
		else
			return gcd(a, b % a);
	}
	else
		if (a != 0)
			return a;
		else
			return b;
}

int main()
{
	int n1, n2, d1, d2, sum1, sum2, min, x;
for (int z=0; z<5; z++)
{
	scanf("%d%d%d%d", &n1, &d1, &n2, &d2);

	sum1 = n1 * d2 + n2 * d1;
	sum2 = d1 * d2;

	if (sum1 == 0)
		printf("0 \n");
	else if (sum1 % sum2 == 0)
		printf("%d \n", sum1 / sum2);
	else
	{
		x = gcd(sum1, sum2);
		sum1 = sum1 / x;
		sum2 = sum2 / x;
		printf("%d %d \n", sum1, sum2);
	}
}
	return 0;
}
