#include<iostream>
using namespace std;

int main()
{
	int i, j, k, t, s, h;
	cin >> t >> s >> h;
	
	for (i=1; i<=t; i++)
	{
		for (j=1; j<=3; j++)
		{
			cout << '*';
			for (k=1; k<=s; k++)
				cout << ' ';
		}
		cout << endl;
	}
	

	for (i=1; i<=3 + s*2; i++)
		cout << '*';
	cout << endl;

	for (i=1; i<=h; i++)
	{
		for  (j=1; j<=s+1; j++)
			cout << ' ';
		cout << '*' << endl;
	}

	return 0;
}
