#include<cstdio>
using namespace std;

bool win(int a, int b, int c, int d)
{
	if (a<0 || b<0 || c<0 || d<0) //you couldn't make a reaction, P wins
		return true;
	if (a==2 && b==1 && c==0 && d==2) //i use up all particles, P wins
		return true;
	if (a==1 && b==1 && c==1 && d==1)
		return true;
	if (a==0 && b==0 && c==2 && d==1)
		return true;
	if (a==0 && b==3 && c==0 && d==0)
		return true;
	if (a==1 && b==0 && c==0 && d==1)
		return true;

	if (win(a-2, b-1, c, d-2) == false)
		return true;
	else if (win(a-1, b-1, c-1, d-1) == false)
		return true;
	else if (win(a, b, c-2, d-1) == false)
		return true;
	else if (win(a, b-3, c, d) == false)
		return true;
	else if (win(a-1, b, c, d-1) == false)
		return true;

	return false;
}

int main()
{
	//freopen("test.in", "r", stdin);
	int t, i, a, b, c, d;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (win(a, b, c, d)==true)
			printf("Patrick\n");
		else
			printf("Roland\n");

	}
	return 0;
}
