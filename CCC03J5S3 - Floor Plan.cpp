#include<iostream>
#include<algorithm>
using namespace std;

int go(char board[26][26], int x, int y);

int main()
{
	char a[26][26];
	int room[100];
	int tiles, r, c, i, j, num=0, filled=0;
	cin >> tiles >> r >> c;
	for (i=0; i<r; i++)
	{
		for (j=0; j<c; j++)
			cin >> a[i][j];	
	}

	for (i=0; i<r; i++)
		for (j=0; j<c; j++)
			if (a[i][j] == '.')
			{
				room[num] = go(a, i, j);
				num++;
			}

	sort(room, room+num);

	//for (i=num-1; i>=0; i--)
		//cout << room[i] << endl;
	
	for (i=num-1; i>=0; i--)
		if (tiles >= room[i])
		{
			tiles = tiles - room[i];
			filled++;
		}
		else
			break;

	cout << filled << " room";
	if (filled != 1)
		cout << 's';
	cout << ", " << tiles << " square metre(s) left over";
	
	return 0;
}

int go(char a[26][26], int x, int y)
{
	int count=0;
	count = count + 1;
	a[x][y]='I';
	if (a[x+1][y]=='.')
		count = count + go(a, x+1, y);
	if (a[x-1][y]=='.')
		count = count + go(a, x-1, y);
	if (a[x][y+1]=='.')
		count = count + go(a, x, y+1);
	if (a[x][y-1]=='.')
		count = count + go(a, x, y-1);
	return count;
}
