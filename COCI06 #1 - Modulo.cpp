#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int x, a[11], pos=0;
	bool check;
	memset(a, -1, sizeof(a));

	for (int i=1; i<=10; i++)
	{
		scanf("%d", &x);
		x = x % 42;

		check=false;
		for (int j=0; j<=pos; j++)
			if (x == a[j])
				check = true;

		if (check == false)
		{
			a[++pos]=x;
		}
	}

	printf("%d \n", pos);
	return 0;
}
