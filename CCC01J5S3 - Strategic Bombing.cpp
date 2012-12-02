#include<iostream>
#include<cstring>
using namespace std;

char from, to, roads[10000];
bool graph[27][27];
int ccount=0;

bool go(int from)
{
	if (from == 1)
		return false;
	else
	{
		for (int i=0; i<27; i++)
			if (graph[from][i] == true)
			{
				graph[from][i] = false;
				graph[i][from] = false;
				if (go(i) == false)
				{
					graph[from][i] = true;
					graph[i][from] = true;
					return false;	
				}
				graph[from][i] = true;
				graph[i][from] = true;
			}
		return true;
	}
}

int main()
{
	//freopen("test.in", "r", stdin);
	memset(roads, false, sizeof(roads));

	do
	{
		scanf("%c%c", &from, &to);
		graph[from - 'A'][to - 'A'] = true;
		graph[to - 'A'][from - 'A'] = true;
		roads[strlen(roads)] = from; roads[strlen(roads)] = to;
		getchar();
	}
	while
		(from != '*');

	for (int i=0; i<(strlen(roads)-2-1); i=i+2)
	{
		graph[roads[i]-'A'][roads[i+1]-'A'] = false;
		graph[roads[i+1]-'A'][roads[i]-'A'] = false;
		if (go(0) == true)
		{
			ccount++;
			printf("%c%c \n", roads[i], roads[i+1]);
		}
		graph[roads[i]-'A'][roads[i+1]-'A'] = true;
		graph[roads[i+1]-'A'][roads[i]-'A'] = true;
	}

	printf("There are %d disconnecting roads.\n", ccount);

	return 0;
}
