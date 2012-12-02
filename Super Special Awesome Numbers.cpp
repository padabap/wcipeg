#include<cstdio>
using namespace std;
bool super(int x); //if sum of digits is even
bool special(int x); //if digits are in increasing order
bool awesome(int x); //not divisible by any perfect sq other than 1
int main()
{
	int l, u, count;
for (int z=0; z<5; z++)
{
	count=0;
	scanf("%d%d", &l, &u);

	for (int i=l; i<=u; i++)
		if (super(i) == true && special(i) == true && awesome(i) == true)
			count++;

	printf("%d \n", count);
}	
	return 0;
}

bool super(int x)
{
	int sum=0;
	
	while (x > 9)
	{
		sum = sum + x % 10;
		x = x / 10;
	}
	sum = sum + x;

	if (sum % 2 == 0)
		return true;
	else
		return false;
}

bool special(int x)
{
	if (x < 10)
		return true;
	else
	{
		while (x > 9)
		{
			if (x % 10 <= (x % 100 / 10))
				return false;
			x = x / 10;
		}
		return true;
	}
}

bool awesome(int x)
{
	int sq=2;
	while (sq * sq <= x)
	{
		if (x % (sq * sq) == 0)
			return false;
		sq++;
	}
	return true;
}
