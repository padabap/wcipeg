#include<iostream>
#include<string>
using namespace std;

int main()
{
	int odd, even, i, z;
	string x;

for (z=0; z<5; z++)
{
	odd=0; even=0;
	cin >> x;

	for (i=0; i<12; i=i+2)
	{
		odd = odd + int(x[i]) - 48;
		even = even + int(x[i+1]) - 48;
	}
	even = even - (int(x[11]) - 48);
	
	for (i=0; i<=9; i++)
	{
		if (( even+i + 3*odd) % 10 == 0)
		{
			x[11]=(i+48);
			break;
		}
	}

	cout << x << endl;
}
	return 0;
}
