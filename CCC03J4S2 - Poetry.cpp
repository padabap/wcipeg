#include<iostream>
#include<cctype>
#include<string>
using namespace std;

int main()
{
	int i, j, z;
	string a[5];

	cin >> z;
	getline(cin, a[0]);
	do
	{
		for (i=1; i<=4; i++)
		{
			getline(cin, a[i]);
			for (j=0; j<a[i].length(); j++)
				a[i][j] = toupper(a[i][j]);

			for (j=a[i].length()-1; j>=0; j--)
				if (a[i][j]=='A' || a[i][j]=='E' || a[i][j]=='I' || a[i][j]=='O' || a[i][j]=='U' || a[i][j-1]==' ')
					break;
			if (j == -1)
				j = 0;

			a[i] = a[i].substr(j); //now each string = last "syllable"				
		}

		if (a[1] == a[2] && a[2] == a[3] && a[3] == a[4])
			cout << "perfect" << endl;
		else if (a[1] == a[2] && a[3] == a[4])
			cout << "even" << endl;
		else if (a[1] == a[3] && a[2] == a[4])
			cout << "cross" << endl;
		else if (a[1] == a[4] && a[2] == a[3])
			cout << "shell" << endl;
		else cout << "free" << endl;

		z=z-1;
	}
	while (z>0);
	return 0;
}
