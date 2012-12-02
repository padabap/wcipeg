#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

int n, mini=2000, size[26];

int f(int space, int pos)
{
	int i;

	for (i=pos; i<n; i++)
			if (space + size[i] <= 1440)
			{
				if (1440 - space - size[i] < mini)
					mini = 1440 - space - size[i];
				f(space + size[i], i+1);				
			}
	return mini;
}

int main()
{
	int i, z;
	ifstream fin ("test.in");

for (z=0; z<5; z++)
{
	mini=2000;
	cin >> n;
	for (i=0; i<n; i++)
		cin >> size[i];

	for (i=0; i<n; i++)
	{
		f(size[i], i+1);
	}

	cout << mini << endl;
}
	return 0;

}
