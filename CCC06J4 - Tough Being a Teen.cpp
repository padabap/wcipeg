#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	vector <int> a[10];
	int before, after, order[10], k=1;
	bool done[10] = {0};
	bool check, output;

	a[1].push_back(2);
	a[4].push_back(1);
	a[4].push_back(3);
	a[5].push_back(3);
	a[7].push_back(1);

	do
	{
		scanf("%d%d", &before, &after);
		a[after].push_back(before);
	}
	while
		(before != 0);

	do
	{
		output = false;
		for (int i=1; i<=7; i++)
		{
			if (done[i] == false)
			{
				if (a[i].size() == 0)
				{
					order[k] = i;
					k++;
					done[i] = true;
					output = true;
					break;
				}
				else
				{
					check = true;
					for (int j=0; j<a[i].size(); j++)
						if (done[a[i][j]] == false)
						{
							check = false;
							break;
						}
					if (check == true)
					{
						order[k] = i;
						k++;
						done[i] = true;
						output = true;
						break;
					}
				}
		
			}
		}
		if (output == false)
		{
			printf("Cannot complete these tasks. Going to bed.");
			break;
		}
	}
	while
		(done[1]==0 || done[2]==0 || done[3]==0 || done[4]==0 || done[5]==0 || done[6]==0 || done[7]==0);

	if (k > 7)
		for (int i=1; i<=7; i++)
			printf("%d ", order[i]);

	return 0;
}
